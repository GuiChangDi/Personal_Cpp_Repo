#include <iostream>
using namespace std;


struct TreeNode{
  int data;
  char s;
  TreeNode *parent;
  TreeNode *lChild;
  TreeNode *rChild;
  TreeNode(int a=0 , char r='\0',TreeNode *p = NULL, TreeNode *lC = NULL, TreeNode *rC = NULL)
          : data(a), s(r), parent(p), lChild(lC), rChild(rC) {}
};

struct Treeheap{
  int size;
  TreeNode **root;
};

void
TreeNodeCompare( TreeNode a, TreeNode b)
{

}

TreeNode*
CreateTreeNode(int a, char b)
{
  TreeNode *t = new TreeNode(a, b, NULL, NULL , NULL);
  return t;
}

Treeheap*
creatheap(char a[], int w[],int size)
{
  Treeheap *minHeap = new Treeheap;
  for (int i = 0; i < size; i++)
    minHeap->root[i] = CreateTreeNode(w[i], a[i]);
  minHeap->size = size;

  return minHeap;
}

TreeNode*
BuildMinTree( TreeNode *a, TreeNode *b)
{
  TreeNode *t = new TreeNode;
  if( a->data > b->data){
    t->lChild = b;
    t->rChild = a;
  } else {
    t->lChild = a;
    t->rChild = b;
  }
  a->parent = t;
  b->parent = t;
  t->data = a->data + b->data;
  
  return t;
}

void
Build_Huffman_Tree(char a[], int w[], int size)
{

}

void
Huffman_Encode(char a[], int w[], int size)
{
  // Step 1: Create a Huffman Tree 
  Build_Huffman_Tree( a, w, size);
}

int main()
{
  char a[] = {'a', 'b', 'c', 'd', 'e', 'f'};
  int weight[] = {2,5,15,9,23,17};
  int size = sizeof(a)/sizeof(a[0]);

  Huffman_Encode(a, weight, size);

  return 0;
}