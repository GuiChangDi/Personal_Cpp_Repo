#define _CRT_SECURE_NO_WARNINGS//use this define to avoid warning on vs compile or use scanf_s instead of scanf
#include <cstdio>

int main()
{
    int n, l;
    char s;
    printf("Input n and character:");
    scanf("%d %c", &n,&s);
    if ((n%2) == 0) l = n/2;
    else l = n/2 + 1;

    for (int i = 0; i < n; i++)
        printf("%c", s);
    printf("\n");
    for (int i = 0;i < l - 2; i++){
        printf("%c", s);
        for (int j = 0;j < n - 2; j++)
            printf(" ");
        printf("%c\n", s);
    }
    for (int i = 0; i < n; i++)
        printf("%c", s);
    return 0;
}