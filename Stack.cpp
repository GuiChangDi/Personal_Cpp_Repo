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
		std::cout << "Header can't be NULL" << std:endl;
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
