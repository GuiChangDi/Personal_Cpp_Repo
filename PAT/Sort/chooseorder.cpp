#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

//选择排序
void ChooseOrder(int a[],int n) {
	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (a[j] < a[i]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	return;
}

int main()
{
	int b[] = { 4,6,1,2,4,8,9,3,5 };
	int n = sizeof(b) / sizeof(b[0]);
	ChooseOrder(b, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", b[i]);
	}
	return 0;
}