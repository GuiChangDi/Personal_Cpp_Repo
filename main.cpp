#include <iostream>
#include "Header/Order.h"
#include "Header/Queue.h"
using namespace std;

static int printarray(int a[], int n)
{
	std::cout << "The outcome array is: ";
	if (n < 0)
		return 0;
	for (int i = 0; i < n; i++)
		std::cout << a[i] << " ";
	return 1;
}

int main()
{
	int a[100];
	
	std::cin.get();
	std::cin.get();
    return 0;
}