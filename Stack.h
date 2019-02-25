#pragma once
typedef struct Node {
	int Element;
	PtrToNode Next;
};
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(int X, Stack S);
int Top(Stack S);
void Pop(Stack S);

struct creature {
	char has_backbone;
	short has_4_leg;
	union secondary_characteristics form;
};

union secondary_characteristics {
	char has_fur;
	short more_than_4_leg;
};