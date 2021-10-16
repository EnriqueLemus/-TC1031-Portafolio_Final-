#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_

  #include <climits>
  #include "Node.h"
  #include "Stack.h"
  using namespace std;

  template <class T>
  class DoubleLinkedList {
    private:
      Node<T>* head;
      Node<T>* tail;
      int numElements;

    public:
      DoubleLinkedList();
      ~DoubleLinkedList();
      int getNumElements();
      Node<T>* getHead();
      Node<T>* getNode(int pos);
      T getData(int position);
      T getHeadData();
      T getTailData();
      int findData(T value);
      void printList();
      void addFirst(T value);
      void addLast(T value);
      bool deleteData(T value);
      bool deleteAt(int position);
      void clear();
      Node<T>* merge(Node<T>* head1, Node<T>* head2);
      Node<T>* getMiddle(Node<T>* head);
      Node<T>* sort(Node<T>* head);
      void addAt(int pos, T newData);
      Node<T>* partition(Node<T> *l, Node<T> *h);
      void _quickSort(Node<T>* l, Node<T> *h);
      void quickSort(Node<T> *head);
      void ordenaQuickiterativo(vector<T>);
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
  void DoubleLinkedList<T>::printList() {
    Node<T> *ptr = head;
    while (ptr != NULL){
      cout << ptr->data << " ";
      ptr = ptr->next;
    }
    cout << endl;
  }

  template<class T> // Complejidad: O(1)
  Node<T>* DoubleLinkedList<T>::getHead(){
    return this->head;
  }

  template<class T> // Complejidad: O(n)
  Node<T>* DoubleLinkedList<T>::getNode(int pos){
    Node<T>* result = head;
    for(int i = 0; result != NULL; i++){
      if(i == pos)
        break;
      result = result->next;
    }
    return result;
  }

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

  template<class T> // Complejidad: O(1)
  T DoubleLinkedList<T>::getHeadData(){
    return this->head->data;
  }

  template<class T> // Complejidad: O(1)
  T DoubleLinkedList<T>::getTailData(){
    return this->tail->data;
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
    cout << ". . Lista eliminada . ." << endl;
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
  Node<T>* DoubleLinkedList<T>::merge(Node<T>* head1, Node<T>* head2){
    Node<T>* newHead = NULL;
    Node<T> *tail = NULL;

    if (head1->data <= head2->data){
      newHead = head1;
      head1 = head1->next;
    }
    else{
      newHead = head2;
      head2 = head2->next;
    }
    tail = newHead;
   
    while(head1 != NULL && head2 != NULL){
      if (head1->data <= head2->data){
        tail->next = head1;
        head1 = head1->next;
      }
      else{
        tail->next = head2;
        head2 = head2->next;
      } 
      tail = tail->next;
    }
    if(head1 != NULL)
      tail->next = head1;
    if(head2 != NULL)
      tail->next = head2;

    return newHead;
}

template<class T> // Complejidad: O(n)
Node<T>* DoubleLinkedList<T>::getMiddle(Node<T> *head){
  Node<T> *middle = head;
  Node<T> *tail = head->next;
   
  while(middle->next != NULL && tail != NULL && tail->next != NULL){
    middle = middle->next;
    tail = tail->next->next;
  }
  return middle;
}

template<class T> // Complejidad: O(nlogn)
Node<T>* DoubleLinkedList<T>::sort(Node<T>* head){
  if(head == NULL){
    cout << "La lista se encuentra vacía." << endl;
    return head;
  }
  // Si tiene 1 elemento
  if(head->next == NULL){
    this->head = head;
    return head;
  }
  Node<T> *newHead;
  Node<T>* middle = getMiddle(head);
  Node<T>* head2 = middle->next;

  middle->next = NULL;
  newHead = merge(sort(head), sort(head2));
  this->head = newHead;
  
  return newHead;
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


template<class T>
Node<T>* partition(Node<T> *l, Node<T> *h){
    // set pivot as h element
    int x = h->data;
    // similar to i = l-1 for array implementation
    Node<T> *i = l->prev;
    // Similar to "for (int j = l; j <= h- 1; j++)"
    for (Node<T> *j = l; j != h; j = j->next)
    {
        if (j->data <= x)
        {
            // Similar to i++ for array
            i = (i == NULL)? l : i->next;
 
            swap(&(i->data), &(j->data));
        }
    }
    i = (i == NULL)? l : i->next; // Similar to i++
    swap(&(i->data), &(h->data));
    return i;}

/*template<class T>
void _quickSort(Node<T>* l, Node<T> *h){
    if (h != NULL && l != h && l != h->next){
        Node<T> *p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}
 

template<class T>
void quickSort(Node<T> *head)
{
    // Find last node
    Node<T> *h = lastNode(head);
 
    // Call the recursive QuickSort
    _quickSort(head, h);
}   
*/

/*
template <class T>
void DoubleLinkedList<T>::ordenaQuickiterativo(vector<T> bitacora){
    Stack<T> stack = new Stack<T>();
    stack.push(0);
    stack.push(bitacora.length);
    while (!stack.isEmpty()) {
        int end = stack.pop();
        int start = stack.pop();
        if (end - start < 2) continue;
        int p = start + ((end-start)/2);
        p = partition(bitacora,p,start,end);

        stack.push(p+1);
        stack.push(end);

        stack.push(start);
        stack.push(p);

    }
} */

#endif // _DOUBLELINKEDLIST_H_