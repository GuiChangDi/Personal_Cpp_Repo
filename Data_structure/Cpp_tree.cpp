#include "Header/Cpp_tree.h"
#include "Header/Cpp_stack.h"
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
    default: travIn_R(this, visit); break;//recursive version
  }
}

template <typename T>
int
BinTree<T>::updateHeight(BinNodePosi(T) x)//update node x height
{ return x=->height = 1 + max(stature(x->lChild), stature(x->rChild)); }

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

template <typename T> //二叉树子树接入算法：将S当作节点x癿左子树接入， S本身置空
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>* &S) { //x->lChild == NULL
  if (x->lChild = S->_root) x->lChild->parent = x; //接入
  _size += S->_size;
  updateHeightAbove(x); //更新全规模与x所有祖先的高度
  S->_root = NULL;
  S->_size = 0;
  release(S); 
  S = NULL; 
  return x; //释放原树， 迒回接入位置
}

template <typename T> //二叉树子树接入算法：将S当作节点x癿右子树接入， S本身置空
BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>* &S) { //x->rChild == NULL
  if (x->rChild = S->_root) x->rChild->parent = x; //接入
  _size += S->_size; 
  updateHeightAbove(x); //更新全树规模与x所有祖先癿高度
  S->_root = NULL; 
  S->_size = 0; 
  release(S); 
  S = NULL; 
  return x; //释放原树，返回接入位置
}

template <typename T> //初除二叉树中位置x处癿节点及其后代，迒回被初除节点癿数值
int BinTree<T>::remove(BinNodePosi(T) x) { //assert: x为二叉树中癿合法位置
  FromParentTo(*x) = NULL; //切断来自父节点癿指针
  updateHeightAbove(x->parent); //更新祖先高度
  int n = removeAt(x); _size -= n; return n; //初除子树x，更新觃模，迒回初除节点总数
}

template <typename T> //初除二叉树中位置x处癿节点及其后代，迒回被删除节点癿数值
static int removeAt(BinNodePosi(T) x) { //assert: x为二叉树中癿合法位置
  if (!x) return 0; //递归基：空树
  int n = 1 + removeAt(x->lChild) + removeAt(x->rChild); //递归释放左、右子树
  release(x->data); release(x); return n; //释放被摘除节点，幵迒回初除节点总数
}

template <typename T> //二叉树子树分离算法：将子树x从当前树中摘除，将其封装为一棵独立子树迒回
BinTree<T>* BinTree<T>::secede(BinNodePosi(T) x) { //assert: x为二叉树中癿合法位置
  FromParentTo(*x) = NULL; //切断来自父节点的指针
  updateHeightAbove(x->parent); //更新原树中所有祖先的高度
  BinTree<T>* S = new BinTree<T>; S->_root = x; x->parent = NULL; //新树以x为根
  S->_size = x->size(); _size -= S->_size; return S; //更新规模，返回分离出来癿子树
}

//Traverse
//Recursive version
template <typename T, typename VST>
void
travPre_R(BinNodePosi(T) x, VST &visit){
  if (x == NULL) return;
  visit(x->data);
  travPre_R(x->lChild,visit);
  travPre_R(x->rChild,visit);
}

template <typename T, typename VST>
void
travPost_R(BinNodePosi(T) x, VST &visit){
  if (x == NULL) return;
  travPre_R(x->lChild,visit);
  travPre_R(x->rChild,visit);
  visit(x->data);
}

template <typename T, typename VST>
void
travIn_R(BinNodePosi(T) x, VST &visit){
  if (x == NULL) return;
  travPre_R(x->lChild,visit);
  visit(x->data);
  travPre_R(x->rChild,visit);
}

//No-Recursive version
template <typename T, typename VST>
void
travPre(BinNodePosi(T) x, VST &visit){
  Stack<BinNodePosi(T)> S;
  if (x) S.push(x);//root node in stack
  while (!S.empty()){
    x = S.pop();//out stack
    visit(x->data);
    if (HasRChild(*x)) 
      S.push(S->rChild);
    if (HasLChild(*x))
      S.push(x->lChild);
  }
}

template <typename T>
static
void
goAlongLeftBranch(BinNodePosi(T) x, Stack<BinNodePosi(T)> &S){
  while(x) { S.push(x); x = x->lChild; }
}

//中序遍历
template <typename T, typename VST>
void
travIn(BinNodePosi(T) x, VST &visit){
  Stack<BinNodePosi(T)> S;
  while (true){
    goAlongLeftBranch(x, S);
    if (S.empty()) break;
    x = S.pop();
    visit(x->data);
    x = x->rChild;
  }
}

 //定位节点v在中序遍历中的直接后继
template <typename T>
BinNodePosi(T)
BinNode<T>::succ() {
  BinNodePosi(T) s = this; //记录后继的临时发量
  if (rChild) { //若有右孩子，则直接后继必在右子树中，具体地就是
    s = rChild; //右子树中
  while (HasLChild(*s)) s = s->lChild; //最靠左（最小）的节点
  } else { //否则，直接后继应是“将当前节点包含于其左子树中癿最低祖先”，具体地就是
    while (IsRChild(*s)) s = s->parent; //逆向地沿右向分支，不断朝左上斱移动
    s = s->parent; //最后再朝右上方移动一步，即抵达直接后继（如果存在）
  }
  return s;
}

//在以S为栈顶节点为根的子树中，找到最高左侧可见叶节点
template <typename T>
static
void
gotoHLVFL(Stack<BinNodePosi(T)> &S){//沿途所遇节点一次入栈
  while (BinNodePosi(T) x = S.top())//自上而下，反复检查当前节点（栈顶）
    if (HasLChild(*x)) {//尽可能向左
      if (HasRChild(*x)) S.push(x->rChild);//若有右孩子，优先入栈
      S.push(x->lChild);//然后转至左孩子
    } else//实不得已
      S.push(x->rChild);//才向右
  S.pop();//返回之前，弹空栈顶的空节点
}

//后序遍历
template <typename T, typename VST>
void travPost_I(BinNodePosi(T) x, VST& visit) { //二叉树癿后序遍历（迭代版）
  Stack<BinNodePosi(T)> S; //辅助栈
  if (x) S.push(x); //根节点入栈
  while (!S.empty()) {
    if (S.top() != x->parent) //若栈顶非当前节点之父（则必为其右兄），此时需
      gotoHLVFL(S); //在以其右兄为根之子树中，找到HLVFL（相当与递归深入其中）
    x = S.pop(); visit(x->data); //弹出栈顶（即前一节点之后继），并访问
  }
}