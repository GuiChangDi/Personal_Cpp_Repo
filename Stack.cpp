#include "Stack.h"
#include <iostream>

int
IsEmpty(Stack S)
{
	return S->Next == NULL;
}

void
MakeEmpty(Stack S)
{
	if (S == NULL)
		std::cout << "Header can't be NULL" << std::endl;
	else
		while (!IsEmpty(S))
			Pop(S);
}

Stack
CreateStack(void)
{
	Stack S;
	S = (Stack)malloc(sizeof(Node));
	if (S == NULL)
		std::cout << "Out of space" << std::endl;
	S->Next = NULL;
	MakeEmpty(S);
	return S;
}

void Pop(Stack S)
{
	while (S->Next != NULL)
	{
		Stack P;
		P = S->Next;
		S->Next = S->Next->Next;
		free(P);
	}
}

void
Push(int X, Stack S)
{
	Stack P;
	P = (Stack)malloc(sizeof(Stack));
	if (P == NULL)
		std::cout << "Out of space" << std::endl;
	else {
		P->Element = X;
		P->Next = S;
		S->Next = P;
	}
}

int
Top(Stack S)
{
	if (IsEmpty(S))
		std::cout << "Stack is Empty" << std::endl;
	else
		return S->Next->Element;
}

