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

template <typename T>
Rank
Vector<T>::
find(T const &e, Rank lo, Rank hi) const{
  while((lo < hi--) && (e != _elem[hi]))
  return hi;
}

template <typename T>
Rank
Vector<T>::
insert(Rank r, T const &e){
  expand();
  for(int i= _size ;i > r; i--)
    _elem[i] = _elem[i - 1];
  _elem[r] = e;
  return r;
}

template <typename T>
int
Vector<T>::
remove(Rank lo, Rank hi){
  if (lo == hi) return 0;
  while(hi < _size) _elem[lo++] = _elem[hi++];
  _size = lo;
  shrink();
  return hi - lo;
}

template <typename T>
T
Vector<T>::
remove(Rank r){
  T e = _elem[r];
  remove(r, r+1);
  return e;
}

template <typename T>
int
Vector<T>::
deduplicate(){
  int oldSize = _size;
  Rank i = 1;
  while (i < _size)
    find(_elem[i], 0 ,i) < 0 ? i++ : remove(i);
  return oldSize - _size;
}

template <typename T>
void
Vector<T>::
traverse(void (*visit)(T)){
  for(int i=0;i< _size;i++)
    visit(_elem[i]);
}

template <typename T>
template <typename P>
void
Vector<T>::
traverse(P& visit){
  for(int i=0;i< _size;i++)
    visit(_elem[i]);
}

template <typename T>
struct Increase
{ virtual void operator()(T& e) { e++; } };

//increase allvector array elem
template <typename T>
void
increase(Vector<T> &V)
{ V.traverse(Increase<T>()); };

//Return the number of disorder elem, return 0 - all elem are order list
template <typename T>
int
Vector<T>::
disordered() const {
  int n = 0;
  for (int i=1; i < _size ;i++)
    if ( _elem[i] > _elem[i+1]) n++;
  return n;
}

template <typename T>
int
Vector<T>::
uniquify(){
  Rank i = 0, j = 0;
  while (++j < _size)
    if (_elem[i] != _elem[j])
      _elem[++i] = _elem[j];
  _size = ++i;
  shrink();
  return j - i;
}

template <typename T>
static
Rank binSearch(T* A, T const& e, Rank lo, Rank hi){
  while(lo < hi){
    Rank mid = (hi-lo)/2;
    if (A[mid] == e)
      return mid;
    if (A[mid] > e)
      hi = mid;//find in [lo,mid]
    if (A[mid] < e)
      lo = mid + 1;//find in (mid,hi)
  }
  return -1;//if not found ,return -1
}

template <typename T>
Rank
Vector<T>::
search(T const& e, Rank lo, Rank hi) const {
  return (rand() % 2) ? //50% to use
    binSearch(_elem, e, lo, hi) : fibSearch(_elem, e, lo, hi);//use binary search or Fibonacci search
}



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