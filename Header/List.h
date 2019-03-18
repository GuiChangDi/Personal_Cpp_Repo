#pragma once
#define True 1
#define False 0
#define MaxDegree 100
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

//Search Function
int BinarySearch(const int A[], int X, int N);
uint Gcd(uint M, uint N);
//List function declare
List ListMakeEmpty(List L);
//int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(int X, List L);
void Delete(int X, List L);
Position FindPrevious(int X, List L);
void Insert(int X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
int Retrieve(Position P);