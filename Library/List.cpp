#include "../Header/List.h"
#include <iostream>

uint
Gcd(uint M, uint N)
{
	uint Rem;

	while (N > 0)
	{
		Rem = M % N;
		M = N;
		N = Rem;
	}
	return M;
}

/*
int 
IsEmpty(List L)
{
	return L->Next == NULL;
}
*/

int
IsLast(Position P, List L)
{
	return P->Next == NULL;
}

Position
Find(int X, List L)
{
	Position P;
	P = L->Next;
	while (P != NULL && P->Element != X)
		P = P->Next;
	return P;
}

Position
FindPrevious(int X, List L)
{
	Position P;
	P = L->Next;
	while (P->Next != NULL && P->Next->Element != X)
		P = P->Next;
	return P;
}

void Delete(int X, List L)
{
	Position P,TmpCell;

	P = FindPrevious(X, L);

	if (!IsLast(P, L))
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}

void
Insert(int X, List L, Position P)
{
	Position TmpCell;
	TmpCell = (Position)malloc(sizeof(struct Node));
	if (TmpCell == NULL)
		printf("Out of Memory!");

	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

void DeleteList(List L)
{
	Position P,Tmp;
	P = L->Next;
	L->Next = NULL;
	while (P != NULL)
	{
		Tmp = P->Next;
		free(P);
		P = Tmp;
	}
}

void
ZeroPolynomial(Polynomial Poly)
{
	int i;

	for( i = 0 ; i<= MaxDegree; i++)
		Poly->CoeffArray[i] = 0;
	Poly->HighPower = 0;
}

Node *
search_list(Node *node, void const *value, int(*compare)(void const *, void const *))
{
	while (node != NULL)
	{
		if (compare(&node->Element, value) == 0)
			break;
		node = node->Next;
	}
	return node;
}

