#include "Header/Cpp_tree.h"
#include <iostream>
using namespace std;

template <typename T>
BinNodePosi(T)
BinNode<T>::insertAsLC(T const &t) { return lChild = new BinNode(t, this); }

template <typename T>
BinNodePosi(T)
BinNode<T>::insertAsRC(T const &t) { return rChild = new BinNode(t,this); }

template <typename T>
template <typename VST>
void
BinNode<T>::travIn(VST &visit) {
  switch (rand() % 5) {
    case 1: travIn(this, visit); break;//iteration version
    default: travIn(this, visit); break;//recursive version
  }
}

template <typename T>
int
BinTree<T>::updateHeight(BinNodePosi(T) x)//update node x height
{ return x0=->height = 1 + max(stature(x->lChild), stature(x->rChild)); }

template <typename T>
void
BinTree<T>::updateHeightAbove(BinNodePosi(T) x)
{ while (x) { updateHeight(x); x = ->parent; }}

template <typename T>
BinNodePosi(T)
BinTree<T>::insertAsRoot(T const &e)
{ _size = 1; return _root = new BinNode<T>(e); }

template <typename T>
BinNodePosi(T)
BinTree<T>::insertAsLC(BinNodePosi(T) x, T const &e)
{ _size++; x->insertAsLC(e); updateHeightAbove(x); return x->lChild; }

template <typename T>
BinNodePosi(T)
BinTree<T>::insertAsRC(BinNodePosi(T) x, T const &e)
{ _size++; x->insertAsRC(e); updateHeightAbove(x); return x->rChild; }