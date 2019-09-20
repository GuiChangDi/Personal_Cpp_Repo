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

/*
  List structure:
    header-> first------------>last->trailer
          <-      <-----------<-    <-
*/
template <typename T>
class List{
private:
  int _size;
  ListNodePosi(T) header;
  ListNodePosi(T) trailer;

protected:
  void init();//List initialize
  int clear();//clear all node
  void copyNodes(ListNodePosi(T) p, int n);//copy n number node from position p
  void merge(ListNodePosi(T)&, int, List<T>&, ListNodePosi(T), int);
  void mergeSort(ListNodePosi(T)& P, int n);//mergesort n node from position p
  void selectionSort(ListNodePosi(T) p, int n);//perform selectionSort on n nodes from position p
  void insertionSort(ListNodePosi(T) p, int n);//perform insertionSort on n nodes from position p

public:
  //Constructor
  List() { init(); }//default
  List(List<T> const& L);//copu List L entirely
  List(List<T> const& L, Rank r, int n);//copy n nodes start from r in List L
  List(ListNodePosi(T) p, int n);//copy n nodes from position p
  //destructor
  ~List();
  //Read-only api
  Rank size() const { return _size; }
  bool empty() const { return _size <= 0; }
  T& operator[](Rank r) const;//overload, support traverse from Rank (low effciency)
  ListNodePosi(T) first() const { return header->succ; }//first node position
  ListNodePosi(T) last() const { return trailer->pred; }//last node position
  bool valid(ListNodePosi(T) p);//position p whether valid
  { return p && (trailer != p) && (header != p); }
  int disordered() const; //judge whether list have ordered
  ListNodePosi(T) find(T const &e) const//List find NO-order
  { return find(e, _size, trailer); }
  ListNodePosi(T) find(T const &e, int n, ListNodePosi(T) p) const;//List find No-order in section
  ListNodePosi(T) search(T const &e) const//List search in order
  { return search(e, _size, trailer); }
  ListNodePosi(T) search(T const &e, int n, ListNodePosi(T) p) const;//Find q <= e in Node p's n number predNode
  ListNodePosi(T) selectMax(ListNodePosi(T) p, int n);//find Max in p and next n-1 node
  ListNodePosi(T) selectMax() { return selectMax(header->succ, _size); }//find max in whole List
  //Write api
  ListNodePosi(T) insertAsFirst(T const &e);//insert e as first node
  ListNodePosi(T) insertAsLast(T const &e);//insert e as last node
  ListNodePosi(T) insertBefore(ListNodePosi(T) p, T const &e);//insert e to the precursor of p
  ListNodePosi(T) insertAfter(ListNodePosi(T) p, T const &e);//insert e to the rear of p
  T remove(ListNodePosi(T) p);//delete Node in position p
  void merge(List<T> &L) { merge(first(), _size, L, L.first(), L._size); }//merge two list
  void sort(ListNodePosi(T) p, int n);//List sort in section
  void sort() { sort(first(), _size); }//List sort
  int deduplicate();
  int uniquify();
  void reverse();
  //traverse
  void traverse(void (*visit)(T&));//performance visit function
  template <typename P>
  void traverse(P & visit);//use visit function referrence.
};