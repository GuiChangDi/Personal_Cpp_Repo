#define _CRT_SECURE_NO_WARNINGS//use this define to avoid warning on vs compile or use scanf_s instead of scanf
#include <cstdio>

//Callatz猜想实现 c version

void Callatz(){
    int step = 0, n;
    scanf("%d", &n);
    while( n != 1){
        if (n%2 == 0) {n /= 2; printf(" %d ",n);}
        else if (n%2 == 1)
            {n = (3*n+1) / 2; printf(" %d ",n);}
        step ++;
    }
    printf("Step: %d\n", step);
}

int main(){
    Callatz();
    return 0;
}