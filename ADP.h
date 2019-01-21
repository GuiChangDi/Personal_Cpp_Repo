#pragma once
#define True 1
#define False 0

typedef unsigned int uint;
//List ADP
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node
{
	int Element;
	Position Next;
};

typedef struct
{
	int CoeffArray[MaxDegree + 1];
	int HighPower;
} *Polynomial;