#include <cstdio>

int main()
{
    int a,b,c;
    int num[10];
    int n, i;
    scanf("%d %d %d", &a, &b, &n);
    c = a + b;
    i = 0;
    do{
        num[i++] = c % n;
        c = c / n;
    } while(c != 0);

    for (int j=i - 1; j >= 0; j--)
        printf("%d", num[j]);
    return 0;

}