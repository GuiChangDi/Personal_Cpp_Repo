#include "../Header/Queue.h"
#include <iostream>

#define MALLOC(S) (S)malloc(sizeof(S))
int
IsEmpty(Queue Q)
{
	return Q->Size == 0;
}

int
IsFull(Queue Q)
{
	return Q->Size == MaxQueueSize;
}

Queue CreateQueue(int num)
{
	Queue S;
	if (num<MinQueueSize || num>MaxQueueSize)
		std::cout << "Queue size is illegal" << std::endl;
	S = MALLOC(Queue);
	S->Array = (int*)malloc(sizeof(Queue)*num);
	if (S->Array == NULL)
		std::cout << "Out of space" << std::endl;
	S->Capacity = num;
	return S;
}