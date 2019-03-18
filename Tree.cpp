#include <iostream>
#include "Tree.h"
struct TreeNode
{
	int Element;
	SearchTree left;
	SearchTree right;
};

SearchTree
MakeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		free(T);
	}
	return NULL;
}

Position
Find(int X, SearchTree T)
{
	if (T == NULL)
		return NULL;
	if (X < T->Element)
		Find(X, T->left);
	if (X > T->Element)
		Find(X, T->right);
	else
		return T;
}

Position
FindMin(SearchTree T)
{
	if (T == NULL)
		return NULL;
	if (T->left != NULL)
		FindMin(T->left);
	else
		return T;
}

Position
FindMax(SearchTree T)
{
	if (T == NULL)
		return NULL;
	while (T->right != NULL)
		T = T->right;
	return T;
}

SearchTree
Insert(int X, SearchTree T)
{
	if (T == NULL)
	{
		T = new TreeNode;
		if (T == NULL)
			std::cout << "Out of resources" << std::endl;
		T->Element = X;
		T->left = T->right = NULL;
	}
	if (X < T->Element)
		Insert(X, T->left);
	if (X > T->Element)
		Insert(X, T->right);
	return T;
}
SearchTree
Delete(int X, SearchTree T)
{
	Position TmpCell;

	if (T == NULL)
		std::cout << "Element not found" << std::endl;
	else
		if (X < T->Element)		//Go left
			T->left = Delete(X, T->left);
		else if (X > T->Element)  //Go right
			T->right = Delete(X, T->left);
		else
			if (T->left && T->right)  //have two children
			{
				TmpCell = FindMin(T->right);
				T->Element = TmpCell->Element;
				T->right = Delete(T->Element, T->right);
			}
			else  //just have one or zero children
			{
				TmpCell = T;
				if (T->left == NULL)
					T = T->right;
				else if (T->right == NULL)
					T = T->left;
				free(TmpCell);
			}
	return T;
}

