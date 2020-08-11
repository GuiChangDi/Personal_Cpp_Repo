#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

int main()
{
	char str[90];
	char s[90][90];
    memset(str,0,sizeof(str));
    memset(s,0,sizeof(s));
	fgets(str, sizeof(str), stdin);
    //gets_s(str);//use gets_s on visual studio
	int len = strlen(str);
	str[len-1] = '\0';//Remove the end '\n' due to fgets() will add '\n' on the end of str
	int l = 0, h = 0;
	for (int i = 0; i < len; i++) {
		if ((str[i] != ' ') && (str[i] != '\n')) {
			s[l][h] = str[i];
			h++;
		}
		else {
			s[l][h] = '\0';
			l++;
			h = 0;
		}
	}
	for (int i = l; i >= 0; i--) {
		printf("%s", s[i]);
		if(i > 0) printf(" ");
	}
	return 0;
}