/*
  Using cpp class to implement List relate API
*/
#pragma once
typedef int Rank;//index
#define ListNodePosi(T) ListNode<T>*//list node position

template <typename T>
struct ListNode{
  T data;//list value
  ListNodePosi(T) pred;//precursor。front node
  ListNodePosi(T) succ;//succursor. next node
  //constructor
  ListNode() {}
  ListNode( T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL)
    : data(e), pred(p), succ(s) {}
  //api
  ListNodePosi(T) insertAsPred(T const& e);
  ListNodePosi(T) insertAsSucc(T const& e);
};

template <typename T>
class List{
private:
  int _size;
  ListNodePosi(T) header;
  ListNodePosi(T) trailer;

protected:
  void init();//List initialize
  int clear();//clear all node
  void copyNodes(ListNodePosi(T) p, int n);//copy p number node from position p
  void merge(ListNodePosi(T)&, int, List<T>&, ListNodePosi(T), int);
  void mergeSort(ListNodePosi(T)& P, int n);//mergesort from position p
};