#include <iostream>

//BinarySearch no recursive, Time complexity = O(logN)
//return the index of element
int
BinarySearch(
	int a[],
	int x,
	int n
)
{
	int low = 0;
	int high = n;
	int mid;
	while (low < high)
	{
		mid = (high - low) / 2;
		if (a[mid] <= x)
			low = mid + 1;
		if (a[mid] > x)
			high = mid;
		if (a[mid] == x)
			return mid;
	}
	return 0;
}

int main(
	int     argc,
	char    *argv[]
)
{
	int a[10] = { 1,3,5,7,9,11,13,15,17,19 };
	int b = BinarySearch(a, 11, 10);
	std::cout << b << std::endl;
	std::cin.get();
	std::cin.get();
	return 0;
}