#include <iostream>
#include "Header/Cpp_list.h"
using namespace std;

template <typename T>
void
List<T>::init(){
  header = new ListNode<T>;
  trailer = new ListNode<T>;
  header->succ = trailer;
  header->pred = NULL;

  trailer->pred = header;
  trailer->succ = NULL;
  _size = 0;
}

//Make List can be use like List[0]
template <typename T>
T&
List<T>::operator[](Rank r) const{//assert: 0 <= r < size
  ListNodePosi p = first();
  while(r-- > 0) p = p->succ;
  return p->data;
}

template <typename T>
ListNodePosi(T)
List<T>::find(T const &e, int n, ListNodePosi(T) p) const{
  while(0 < n--){
    if( p->data == e)
      return p;
    p = p->pred;
  }
  return NULL;
}

template <typename T>
ListNodePosi(T)
List<T>::insertAsFirst(T const &e){
  _size++;
  return header->insertAsSucc(e);
}

template <typename T>
ListNodePosi(T)
List<T>::insertAsLast(T const &e){
  _size++;
  return trailer->insertAsPred(e);
}

template <typename T>
ListNodePosi(T)
List<T>::insertBefore(ListNodePosi(T) p, T const &e){
  _size++;
  return p->insertAsPred(e);
}

template <typename T>
ListNodePosi(T)
List<T>::insertAfter(ListNodePosi(T) p, T const &e){
  _size++;
  return p->insertAsSucc(e);
}

template <typename T>
ListNodePosi(T)
ListNode<T>::insertAsPred(T const &e){
  ListNodePosi(T) x = new ListNode(e, pred, this);
  pred->succ = x;
  pred = x;
  return x;
}

template <typename T>
ListNodePosi(T)
ListNode<T>::insertAsSucc(T const &e){
  ListNodePosi(T) x = new ListNode(e, this, succ);
  succ->pred = x;
  succ = x;
  return x;
}

template <typename T>
void
List<T>::copyNodes(ListNodePosi(T) p, int n){
  init();
  while(n--)  { insertAsLast(p->data); p = p->succ; }//Insert to the end
}

template <typename T>
List<T>::List(ListNodePosi(T) p, int n)
{ copyNodes(p, n); }

template <typename T>
List<T>::List(List<T> const &L)
{ copyNodes( L.first(), L._size); }

template <typename T>
List<T>::List(List<T> const &L, Rank r, int n)
{ copyNodes(L[r], n); }

template <typename T>
T
List<T>::remove(ListNodePosi(T) p){
  T e = p->data;
  p->pred->succ = p->succ;
  p->succ->pred = p->pred;
  delete p;
  _size--;
  return e;
}

template <typename T>
List<T>::~List()
{ clear(); delete header; delete trailer;}

template <typename T>
int
List<T>::clear(){
  int oldSize = _size;
  while (0 < _size) remove(header->succ);
  return oldSize;
}

template <typename T>
int
List<T>::deduplicate(){
  if (_size < 2) reuturn 0;
  int oldSize = _size;
  ListNodePosi(T) p = header;
  Rank r = 0;
  while (trailer != (p = p->succ)){
    ListNodePosi(T) q = find(p->data, r, p);
    q ? remove(q) : r++;
  }
  return oldSize - _size;
}

template <typename T>
void
List<T>::traverse(void (*visit)(T&))
{ for (ListNodePosi(T) p = header->succ; p!= trailer; p = p->succ) visit(p->data); }

template <typename T>
template <typename P>
void
List<T>::traverse(P & visit)
{ for (ListNodePosi(T) p = header->succ; p!= trailer; p = p->succ) visit(p->data); }

template <typename T>
int
List<T>::uniquify(){
  if (_size < 2) return 0;
  int oldSize = _size;
  ListNodePosi(T) p,q;
  for (p = header, q = p->succ; trailer != q; p = q, q = q->succ)
    if (p->data == q->data) { remove(q); q = p; }
  return oldSize - _size;
}

template <typename T>
ListNodePosi(T)
List<T>::search(T const &e,int n, ListNodePosi(T) p) const{
  while (0 <= n--)
    if (((p = p->pred) ->data) <= e) break;
  return p;
}

template <typename T>
void
List<T>::sort(ListNodePosi(T) p, int n){
  switch (rand() %3) {
    case 1: insertionSort(p, n); break;
    case 2; selectionSort(p, n); break;
    default:  mergeSort(p, n); break;
  }
}