#include "ADP.h"
#include "Function_Protocol.h"
#include <iostream>

struct Node
{
	int Element;
	Position Next;
};

int
BinarySearch(const int A[],int X,int N)
{
    int low,mid,high;
    low = 0,high = N-1;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(mid == X)
            return True;
        else if(A[mid] <= X)
            low = mid + 1;
        else if(A[mid] > X)
            high = mid-1;
    }
    return False;
}

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