#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
const int MAX = 256;

bool judge(char a[])
{
	int len = strlen(a);
	for (int i = 0; i < len / 2; i++) {
		if (a[i] != a[len - 1 - i]) {
			return false;
		}
	}
	return true;
}

int main()
{
	char str[MAX];
	gets(str);
    gets_s(str);//use this if compile with visual stdio
	bool flag = judge(str);
	if (flag)	printf("是回文串\n");
	else printf("不是回文串\n");
	return 0;
}