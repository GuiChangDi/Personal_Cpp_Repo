/**
Relate Words: for one node v
 * vertex 顶点
 * edge 边
 * root 根
 * node 节点
 * depth 深度
 * ancestor 祖先
 * descendant 后代
 * parent 父亲
 * child 孩子
 * degree 度 deg(v)
 * subtree 子树 subtree(v)
 * height 高度
 * proper ancestor 真祖先
 * proper descendant 真后代
 * proper binary tree 真二叉树 不含一度节点
**/
#define BinNodePosi(T) BinNode<T>*//node position
#define stature(p) ((p) ? (p)->height : -1)//node height
typedef enum { RB_RED, RB_BLACK} RBColor;//node color

template <typename T> struct BinNode{
  T data;//value
  BinNodePosi(T) parent;//parent node
  BinNodePosi(T) lChild;//left child
  BinNodePosi(T) rChild;//right child
  int height;// node height
  int npl;//Null path Length
  RBColor color;//color(red-black tree)
  //contructor
  BinNode() : parent(NULL), lChild(NULL), rChild(NULL), height(0), npl(1), color(RB_RED) {}
  BinNode(T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL,
          int h = 0, int l = 1, RBColor c = RB_RED)
          : data(e), parent(p), lChild(lc), rChild(rc), height(h), npl(l), color(c) {}
  //API
  int size();//count subtree's node number
  BinNodePosi(T) insertAsLC(T const &t);//Insert as left child
  BinNodePosi(T) insertAsRC(T const &t);//Insert as right child
  BinNodePosi(T) succ();//choose direct succ
  template <typename VST> void travLevel(VST&);//traverse subtree层次遍历
  template <typename VST> void travPre(VST&);//traverse pre-order先序遍历
  template <typename VST> void travIn(VST&);//traverse mid-order中序遍历
  template <typename VST> void travPost(VST&);//traverse neext-order后序遍历
  
  bool operator<(BinNode const & bn) { return data < bn.data; }
  bool operator==(BinNode const & bn) { return data == bn.data; }
};

//Node status macro
#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (!IsRoot(x) && (&(x) == (x).parent->lChild))
#define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rChild))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lChild)
#define HasRChild(x) ((x).rChild)
#define HasChild(x) (HasLChild(x) || HasRChild(x))
#define HasBothChild(x) (HasLChild(x) && HasRChild(x))
#define IsLeaf(x) (!HasChild(x))
//node relate node and pointer

//node's brother
#define sibling(p) ( \
  IsLChild(*(p)) ? \
    (p)->parent->rChild: \
    (p)->parent->lChild \
)

//node's uncle
#define uncle(x) ( \
  IsLChild(*((x)->parent)) ? \
    (x)->parent->parent->rChild : \
    (x)->parent->parent->lChild \
)

#define FromParentTo(x) ( \
  IsRoot(x) ? _root : ( \
  IsLChild(x) ? (x).parent->lChild : (x).parent->rChild \
  ) \
)

template <typename T> 
class BinTree { //二叉树模板类
protected:
  int _size; //觃模
  BinNodePosi(T) _root; //根节点
  virtual int updateHeight(BinNodePosi(T) x); //更新节点x癿高度
  void updateHeightAbove(BinNodePosi(T) x); //更新节点x及其祖先癿高度
public:
  BinTree() : _size(0), _root(NULL) { } //构造函数
  ~BinTree() { if (0 < _size) remove(_root); } //析构函数
  int size() const { return _size; }
  bool empty() const { return !_root; }
  BinNodePosi(T) root() const { return _root; } //树根
  BinNodePosi(T) insertAsRoot(T const& e); //揑入根节点
  BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const& e); //e作为x癿左孩子（原无）揑入
  BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const& e); //e作为x癿右孩子（原无）揑入
  BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T>* &T); //T作为x左子树接入
  BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T>* &T); //T作为x右子树接入
  int remove(BinNodePosi(T) x); //初除以位置x处节点为根癿子树，迒回该子树原先的规模
  BinTree<T>* secede(BinNodePosi(T) x); //将子树x从弼前树中摘除，幵将其转换为一棵独立子树
  template <typename VST> //操作器
  void travLevel(VST& visit) { if (_root) _root->travLevel(visit); } //局次遍历
  template <typename VST> //操作器
  void travPre(VST& visit) { if (_root) _root->travPre(visit); } //先序遍历
  template <typename VST> //操作器
  void travIn(VST& visit) { if (_root) _root->travIn(visit); } //中序遍历
  template <typename VST> //操作器
  void travPost(VST& visit) { if (_root) _root->travPost(visit); } //后序遍历
  // 比较器、刞等器（各列其一，其余自行补充）
  bool operator<(BinTree<T> const& t) { return _root && t._root && lt(_root, t._root); }
  bool operator==(BinTree<T> const& t) { return _root && t._root && (_root == t._root); }
}; //BinTree