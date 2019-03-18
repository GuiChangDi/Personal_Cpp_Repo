#include "../Header/Order.h"
#include <iostream>

//Time complexity = O(N)  
int bucket(int a[], int n) {
	int i, t;
	for (i = 0; i < n; i++)
	{
		a[i] = 0;
	}

	for (i = 1; i <= n; i++)
	{
		std::cout << "Input the " << i << " number:";
		std::cin >> t;
		a[t]++;
	}

	std::cout << std::endl<< "Outcome:" << std::endl;
	for (i = 0; i < n; i++)
	{
		for (int j = 1; j <= a[i]; j++)
			std::cout << i ;
	}

	std::cout<<std::endl;
	return 1;
}

//Time complexity = O(N^2)     if a[i] > a[i+1], switch up 
int bubble(int a[], int n)
{
	int t,temp;
	for (int i = 0; i < n; i++)
	{
		std::cout << "Input the " << i+1 << " number:";
		std::cin >> t;
		a[i] = t;
	}

	std::cout << "The array is: ";
	for (int i = 0; i < n; i++)
		std::cout << a[i]<<" ";

	for (int i = n-1;i>=0;i--)
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}

	std::cout << std::endl<<"After bubble order,array is: ";
	for (int i = 0; i < n; i++)
		std::cout << a[i]<<" ";
	return 1;
}

//Rapid order Time complexity: MAX O(N^2), Average O(NlogN)
int rapidorder(int a[],int left, int right)
{
	int temp, i, j, refer;
	if (left >= right)
		return 0;

	i = left;
	j = right;
	refer = a[left];

	while (i != j)
	{
		while (a[j] >= refer && i<j)
			j--;
		while (a[i] <= refer && i<j)
			i++;
		if (i < j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	a[left] = a[i];
	a[i] = refer;

	//recursion
	rapidorder(a, left, i - 1);
	rapidorder(a, i + 1, right);
}

//Remove repeat elem in array and sort
int removemutli(int a[], int n)
{
	int p,num;
	num = 0;
	for (int i = 0; i < 100; i++)
		a[i] = 0;

	for (int i = 0; i < n; i++)
	{
		std::cout << "Input the " << i + 1 << " number:";
		std::cin >> p;
		a[p] = 1;
	}

	std::cout << "The outcome is :" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (a[i] > 0)
		{
			num++;
			std::cout << i << " ";
		}
	}
	std::cout << "Total count number: " << num << std::endl;
	return 1;
}