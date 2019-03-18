#include "Order.h"
#include <iostream>
int bucket(int a[], int n) {
	int i, t;
	for (i = 0; i < n; i++)
	{
		a[i] = 0;
	}

	for (i = 1; i <= n; i++)
	{
		std::cin >> t;
		a[t]++;
	}

	std::cout << "Outcome:" << std::endl;
	for (i = 0; i < n; i++)
	{
		for (int j = 1; j <= a[i]; j++)
			std::cout << i ;
	}
	return 1;
}