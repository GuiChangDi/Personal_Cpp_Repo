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
	fgets(str, sizeof(str), stdin);
	int len  = strlen(str);
	str[len-1] = '\0';//Remove the end '\n' due to fgets() will add '\n' on the end of str
    // gets_s(str);//use this if compile with visual stdio
	bool flag = judge(str);
	if (flag)	printf("是回文串\n");
	else printf("不是回文串\n");
	return 0;
}