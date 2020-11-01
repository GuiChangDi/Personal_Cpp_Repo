#include <cstdio>

int binary_search(
	int a[],
	int n,
	int low,
	int high
) {
	int temp = 0;
	int mid = 0;
	while (low <= high) {
		mid = (high - low)/2 + low;
		if (a[mid] > n)
			high = mid - 1;
		if (a[mid] < n)
			low = mid + 1;
		if (a[mid] == n)
			return mid;
	}
	return -1;
}

int main() {
	int a[] = { 1,5,7,9,13,16,22,33,65 };
	int b = binary_search(a, 16, 0, sizeof(a)/sizeof(a[0])-1);
	printf("%d", b);
	return 0;
}