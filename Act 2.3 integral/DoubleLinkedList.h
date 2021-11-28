#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_

  #include <climits>
  #include "Node.h"
  #include "Stack.h"
  #include "dateTime.h"
  #include "Data.h"
  using namespace std;

  template <class T>
  class DoubleLinkedList{
    private:
      Node<T>* head;
      Node<T>* tail;
      int numElements;

    public:
      DoubleLinkedList();
      ~DoubleLinkedList();
      int getNumElements();
      T getData(int position);
      int findData(T value);
      void printList();
      void addFirst(T value);
      void addLast(T value);
      bool deleteData(T value);
      bool deleteAt(int position);
      void clear();
      void addAt(int pos, T newData);
      void swap ( T* a, T* b );
      Node<T>* partition(Node<T> *l, Node<T> *h);
      void quick_Sort(Node<T>* l, Node<T> *h);
      void quickSort();
      void ordenaQuickiterativo(Node<T>);
  };

  template<class T> // Complejidad: O(1)
  DoubleLinkedList<T>::DoubleLinkedList(){
    head = NULL;
    tail = NULL;
    numElements = 0;
  }
  
  template<class T> // Complejidad: O(n)
  DoubleLinkedList<T>::~DoubleLinkedList(){
    Node<T> *p, *q;
    p = head;
    while (p != NULL){
      q = p->next;
      delete p;
      p = q;
    }
    head = NULL;
    tail = NULL;
    numElements = 0;
  }
 
  template<class T> // Complejidad: O(1)
  int DoubleLinkedList<T>::getNumElements(){
    return numElements;
  }

  template<class T> // Complejidad: O(n)
  void DoubleLinkedList<T>::printList(){
    Node<T> *ptr = head;
    while (ptr!=NULL){
      std::cout<<ptr->data.getAll()<<std::endl;
      ptr = ptr->next;
    }
    std::cout<<std::endl;
  }//O(n)



  template<class T>
  T DoubleLinkedList<T>::getData(int position) {
    if (position == 0) {
      return head->data;
    }
    Node<T> *p = head;
    int index = 0;
    while (p != NULL) {
      if (index == position)
      return p->data;
      index++;
      p = p->next;
    }
    return p->data;
  }

  
  template<class T> // Complejidad: O(n)
  int DoubleLinkedList<T>::findData(T value){
    Node<T>* ptr = head;
    if(ptr == NULL)
      return -1;
    else{
      for(int index = 0; ptr != NULL; index++){
        if(ptr->data == value)
          return index;
        ptr = ptr->next;
      }
    }
    return -1;
  }

  template<class T> // Complejidad: O(1)
  void DoubleLinkedList<T>::addFirst(T value){
    Node<T> *newNode = new Node<T>(value);
    if (head == NULL){
      head = newNode;
      tail = newNode;
    }
    else{
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
    numElements++;
  }
  
  template<class T> // Complejidad: O(1)
  void DoubleLinkedList<T>::addLast(T value){
    if (head == NULL){
      addFirst(value);
    }
    else {
      Node<T> *newNode = new Node<T>(value);
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
      numElements++;
    }    
  }
  
  template<class T> // Complejidad: O(n)
  bool DoubleLinkedList<T>::deleteData(T value){
    Node<T> *p, *q;
    p = head;
    q = NULL;
    // Si la lista esta vacia 
    if (p == NULL)
      return false;
    else {
      // buscar value en la lista
      while (p != NULL && p->data != value){
        q = p;
        p = p->next;
      }
      // Si no existe value en la lista
      if (p == NULL)
        return false;
      // Si debe borrarse el primer elemento
      if (p->prev == NULL){
        head = p->next;
        if (head != NULL)
          head->prev = NULL;
      }
      else if (p->next == NULL){ 
        // Si debe borrarse el último elemento
        q->next = NULL;
        tail = q;
      }
      else{
        // Cualquier otro elemento entre la lista 
        q->next = p->next;
        p->next->prev = q;
      }
      delete p;
      numElements--;
      return true;
    }
  }

  template<class T> // Complejidad: O(n)
  bool DoubleLinkedList<T>::deleteAt(int position){
    if (position < 0 || position >= numElements){
      cout << "Indice fuera de rango" << endl;
      return false;
    }
    else if (position == 0){ // Si debe borrarse el primer elemento
      Node<T> *p = head;
      // Si la lista contiene solo un nodo
      if (head != NULL && head->next == NULL){
        head = NULL;
        tail = NULL;  
      }
      else{
        head = p->next;
        head->prev = NULL;
      }
      delete p;
      numElements--;
      return true; 
    }
    else{ 
      Node<T> *p = head, *q = NULL;
      int index = 0;
      while (index != position){
        q = p;
        p = p->next;
        index++;
      }
      // Si debe borrarse el último elemento
      if (p->next == NULL){
        q->next = NULL;
        tail = q;
      }
      else{ // Cualquier otro elemento entre la lista 
        q->next = p->next;
        p->next->prev = q;
      }
      delete p;
      numElements--;
      return true;
    }
  }

  template<class T> // Complejidad: O(n)
  void DoubleLinkedList<T>::clear(){
    cout << ". . Lista anterior eliminada . ." << endl;
    Node<T> *p, *q;
    p = head;
    while (p != NULL){
      q = p->next;
      delete p;
      p = q;
    }
    head = NULL;
    tail = NULL;
    numElements = 0;
  }
 

template<class T> // Complejidad: O(n)
void DoubleLinkedList<T>::addAt(int pos, T newData){
  Node<T>* result = head;
  for(int i = 0; result != NULL; i++) {
    if(i == pos)
      break;
      result = result->next;
    }
    result->data = newData;
  }

 
//-GeeksforGeeks QuickSort on Doubly Linked List.
template<class T>  /* A utility function to swap two elements */
void DoubleLinkedList<T>::swap ( T* a, T* b ){   // Complejidad: O(1)
  T t = *a; *a = *b; *b = t; 
}
//-GeeksforGeeks QuickSort on Doubly Linked List.
template<class T>
 Node<T>* DoubleLinkedList<T>::partition(Node<T> *l, Node<T> *h){  // Complejidad: O(n)
    // set pivot as h element
    dateTime x = h->data.getFecha();
    // similar to i = l-1 for array implementation
    Node<T> *i = l->prev;
    // Similar to "for (int j = l; j <= h- 1; j++)"
    for (Node<T> *j = l; j != h; j = j->next){
      if (j->data.getFecha() < x){
        // Similar to i++ for array
        i = (i == NULL)? l : i->next;
        swap(&(i->data), &(j->data));
      }
    }
    i = (i == NULL)? l : i->next; // Similar to i++
    swap(&(i->data), &(h->data));
    return i;
  }

//-GeeksforGeeks QuickSort on Doubly Linked List.
template <class T> 
void DoubleLinkedList<T>::quick_Sort(Node<T>* l, Node<T> *h){   //Complejidad: O(n log n)
  if (h != NULL && l != h && l != h->next)
  {
      Node<T> *p = partition(l, h);
      quick_Sort(l, p->prev);
      quick_Sort(p->next, h);
  }
}//O(n log n)



//-GeeksforGeeks QuickSort on Doubly Linked List.
template <class T>
void DoubleLinkedList<T>::quickSort(){
  Node<T> *p = head;
  // Find last node
  Node<T> *t = tail;
  // Call the recursive QuickSort
  quick_Sort(p, t);
}//O(1)



/*
template <class T>
void DoubleLinkedList<T>::ordenaQuickiterativo(int array){
    Stack<T> stack = new Stack<T>();
    stack.push(0);
    stack.push(array.length);
    while (!stack.isEmpty()) {
        int end = stack.pop();
        int start = stack.pop();
        if (end - start < 2) continue;
        int p = start + ((end-start)/2);
        p = partition(array,p,start,end);

        stack.push(p+1);
        stack.push(end);

        stack.push(start);
        stack.push(p);

    }
} 
*/
#endif // _DOUBLELINKEDLIST_H_