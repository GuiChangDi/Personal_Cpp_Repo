#include <cstdio>
#include <cstring>
using namespace std;

int hashFunc(char S[], int n){
    int id = 0;
    for (int i=0 ; i < n ; i++){
        id = id * 26 + (S[i] - 'A');
    }
    return id;
}

int main(){
    char a[] = 'ABC';
    int b = hashFunc(a, 3);
    printf("%d\n", b);
    return 0;
}