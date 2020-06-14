#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

void InsertSort(int a[], int n) {
	int temp = 0,j = 0;
	for (int i = 1; i < n; i++) {
		temp = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > temp) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}

int main()
{
	int b[] = { 4,6,1,2,4,8,9,3,5 };
	int n = sizeof(b) / sizeof(b[0]);
	InsertSort(b, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", b[i]);
	}
	return 0;
}