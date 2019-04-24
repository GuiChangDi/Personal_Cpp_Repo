#include <iostream>
#include "Header/Stack_class.h"
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
	Stack a;
	a.push(20);
	a.push(30);
	unsigned long b,c;
	a.pop(b);
	a.pop(c);
	std::cout<<b<<c<<std::endl;
	std::cin.get();
	std::cin.get();
    return 0;
}