#define _CRT_SECURE_NO_WARNINGS//use this define to avoid warning on vs compile or use scanf_s instead of scanf
#include <cstdio>

const int MAXSIZE = 10;

int main()
{
    int sum[MAXSIZE] = {0};
    int k,j, MAX, n;
    printf("Input n:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        printf("Input the %d number and score:", i);
        scanf("%d%d", &k, &j);
        sum[k] += j;
    }
    MAX = 0;
    for (int i = 1; i <= n; i++){
        if (sum[MAX] <= sum[i])
            MAX = i;
    }
    printf("Max score is: %d %d\n", MAX, sum[MAX]);
    return 0;
}