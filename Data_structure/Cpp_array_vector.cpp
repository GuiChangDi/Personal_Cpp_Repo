#include <iostream>
#include "Header/Cpp_array_vector.h"
using namespace std;

template <typename T>
void
Vector<T>::
copyFrom(T const *A, Rank lo, Rank hi){
  _elem = new T[_capacity = 2*(hi-lo)];
  _size = 0;
  while(lo < hi)
    _elem[_size++] = A[_size++];
}

template <typename T>
Vector<T>&
Vector<T>::
operator=(Vector<T> const &V){
  if (_elem) delete [] _elem;
  copyFrom(V._elem,0,V.size());
  return *this;
}

template <typename T>
void
Vector<T>::
expand(){
  if (_size < _capacity) return;//No need to expand
  if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
  T* oldElem = _elem;
  _elem = new T[_capacity <<=1];//double the capacity
  for (int i = 0; i< _size; i++)
    _elem = oldElem[i];//copy old elem to new expanded array
  delete [] oldElem;//Free origin space
}

template <typename T>
void
Vector<T>::
shrink(){
  if (_capacity < DEFAULT_CAPACITY << 1) return;
  if (_size << 2 > _capacity) return;
  T* oldElem = _elem;
  _elem = new T[_capacity >> 1];//shrink to 1/2
  for(int i = 0;i < _size;i++)
    _elem[i] = oldElem[i];//copy orgin content
  delete [] oldElem;
}

template <typename T>
T&
Vector<T>::
operator[](Rank r) const{
  return _elem[];
}

template <typename T>
void
Vector<T>::
unsort(Rank lo,Rank hi){
  T* V = _elem + low;
  for (Rank i = hi - low; i > 0;i--)
    swap(V[i - 1], V[rand() % i]);//swap V[i - 1] to V[0,i)
}

template <typename T>
static bool lt(T* a, T* b) {return lt(*a,*b);}

template <typename T>
static bool lt(T& a,T& b) {return a<b;}

template <typename T>
static bool eq(T* a, T* b) {return eq(*a,*b);}

template <typename T>
static bool eq(T& a,T& b) { return a == b;}

int
main(
  int argc,
  char* argv[]
)
{
  cin.get();
  cin.get();
  return 0;
}