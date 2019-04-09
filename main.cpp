#include <iostream>
#include "Header/Order.h"
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
	int a[] = {2,3,4,2,5,6,4,7,34,23,43,54};
	rapidorder(a,0,11);
	printarray(a,12);
	std::cin.get();
	std::cin.get();
    return 0;
}