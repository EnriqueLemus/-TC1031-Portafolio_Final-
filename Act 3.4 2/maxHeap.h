#ifndef _MAXHEAP_H_
#define _MAXHEAP_H_

#include<vector>
#include<iostream>
using namespace std;

template<class T>
class MaxHeap{
  private:
  std::vector<T> datos; 
  int maxSize; 
  int size;   

  int parent(int i);
  int left(int i);
  int right(int i);

  public:
    MaxHeap(int capacity);
    ~MaxHeap();
    void clear();
    bool isEmpty();
    int getSize();
    int getCapacity();
    void printMaxHeap();
    void push(T key);
    T top();
    T getData(int k);
};

  template <class T> 
  MaxHeap<T>::MaxHeap(int capacity) {
    size = 0;
    maxSize = capacity;
    datos.resize(maxSize);
    T getData(int posicion);
  }

  template <class T> 
  MaxHeap<T>::~MaxHeap() {
      datos.clear();
  }

  template <class T> 
  void MaxHeap<T>::clear() {
      datos.clear();
  }
  
  template <class T> 
  bool MaxHeap<T>::isEmpty() {
    return (size <= 0);
  }

  template <class T> 
  int MaxHeap<T>::getSize() {
    return size;
  }

  template <class T> 
  int MaxHeap<T>::getCapacity() {
    return maxSize;
  }

  template <class T> 
  void MaxHeap<T>::printMaxHeap() {
    for (int i=0; i < size; i++)
      cout << datos[i] << " ";
    cout <<endl;
  }

  template <class T> 
  T MaxHeap<T>::getData(int k) {
    return datos[k];
  }

  template <class T> 
  int MaxHeap<T>::parent(int i) {
    return (i-1)/2; 
  }
  
  template <class T> 
  int MaxHeap<T>::left(int i) {
    return (2*i + 1); 
  }

  template <class T> 
  int MaxHeap<T>::right(int i) {
    return (2*i + 2);
  }

  template <class T> 
  void MaxHeap<T>::push(T key) {
    if (size == maxSize) {
        cout << "Overflow: no se puede insertar la llave: "<< key<<endl;
        return;
    }
    int i = size;
    datos[i] = key;
    size++;
    while (i != 0 && datos[parent(i)] < datos[i]) {
       swap(datos[i], datos[parent(i)]);
       i = parent(i);
    }
  }

  template <class T> 
  T MaxHeap<T>::top() {
    T result = -1;
    if (isEmpty()) {
        cout << "El MaxHeap está vacio" <<endl;
        return result;
    }
    return datos[0];
  }


#endif // _MAXHEAP_H_