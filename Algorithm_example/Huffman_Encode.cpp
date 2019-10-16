#include <iostream>
using namespace std;

#define TreeNode(T) TreeNode<T>*

template <typename T>
struct TreeNode{
  T data;
  TreeNode(T) parent;
  TreeNode(T) lChild;
  TreeNode(T) rChild;
  int height;
  TreeNode(T a , TreeNode(T) p = NULL, TreeNode(T) lC = NULL, TreeNode(T) rC = NULL, int h = 0;)
          : data(a), parent(p), lC(lChild), rC(rChild), h(height) {}
};

