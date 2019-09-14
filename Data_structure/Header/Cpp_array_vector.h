/*
  The Vector treat as array.
  Use Cpp class to pacakge as Vector
*/
typedef int Rank;//Can be treat as index of array
#define DEFAULT_CAPACITY 3 //default size

template <typename T>
class Vector{
protected:
  Rank _size;//A[] valid size
  int _capacity;//total size
  T* _elem;//A[i] value

  void copyFrom(T const *A, Rank lo,Rank hi); //Copy function A[lo,hi)
  void expand(); //If space is not enough,expand.
  void shrink(); //shrink capacity
  bool bubble(Rank lo, Rank hi);//bubble function swap one round
  bool bubbleSort(Rank lo, Rank hi);//bubble function sort algorithm
  Rank max(Rank lo,Rank hi);//Find the max elem in [lo,hi)
  void selectionSort(Rank lo,Rank hi);//Selection sort algorithm
  void merge(Rank lo,Rank mi, Rank hi);//merge algorithm
  void mergeSort(Rank lo, Rank hi);
  Rank partition(Rank lo,Rank hi);
  void quickSort(Rank lo,Rank hi);//quick sort algorithm
  void heapSort(Rank lo,Rank hi);

public:
  //Constructor
  Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)//capacity is c,array size is s,all elem is 0
  {_elem = new T[_capacity = c]; for(_size = 0;_size < s; _elem[_size++] = v);}
  Vector(T const* A, Rank lo, Rank hi) {copyFrom(A,lo,hi);}//array copy [lo,hi)
  Vector(T const* A, Rank n) {copyFrom(A,0,n);}//array copy [0,n)
  Vector(Vector<T> const& V,Rank lo,hi) {copyFrom(V._elem,lo,hi);}
  Vector(Vector<T> const& V) {copyFrom(V._elem,0,V._size);}
  //Destructor
  ~Vector() { delete [] _elem;}
  //Read-only api
  Rank size() const {return _size}//Display size
  bool empty() const {return !_size}//Display whether empty
  int disordered() const;//Judge vector whether sorted
  Rank find(T const& e) const { return find(e,0, _size);}//No-order find in [0,_size]
  Rank find(T const& e, Rank lo, Rank hi) const;//No-order find in [lo,hi]
  Rank search(T const& e) const//Order find in [0,_size]
  { return (0 >= _size) ? -1: search(e,0,_size);}
  Rank search(T const& e, Rank lo, Rank hi) const;//Order find in [lo,hi]
  //Writeable api
  T& operator[](Rank r) const;//overload [],make Vector can use like Vector[]
  Vector<T> & operator=(Vector<T> const&);//overload =
  T remove(Rank r);//delete a[r] value
  int remove(Rank lo, Rank hi);//delete elem in [lo, hi)
  Rank insert(Rank r, T const& e);//Insert elem. a[r] = e.
  Rank insert(T const& e) {return insert(_size,e);}//Insert to the end
  void sort(Rank lo, Rank hi);//sort elem in [lo,hi)
  void sort() {sort(0,_size);}
  void unsort(Rank lo, Rank hi);//make array disorder
  void unsort() {unsort(0,_size);}
  int deduplicate();//remove the duplicate elem in No-order
  int uniquify();//remove the duplicate elem in order
  //travel array
  void traverse(void (*)(T));//Traverse,use function pointer
  template <typename P> void traverse(P&);//Traverse,use function reference
};