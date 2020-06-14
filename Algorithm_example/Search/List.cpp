#include <iostream>
using namespace std;
/*
List.cpp
线性表有关小算法题解
*/
const int MaxSize = 100;

struct SqList{
    int length;
    int *data;
};

/*
对长度为N的顺序表L， 编写一个时间复杂度为O(N),空间复杂度为(1)的算法，删除线性表中所有值为x的元素
*/
void remove_x( SqList &L , int x)
{
    int k = 0;
    for(int i = 0; i < L.length ; i++){
        if (L.data[i] != x){
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
}

int main(){
    int a[] = {1,2,3,4,3,5};
    struct SqList b;
    b.length = 6;
    b.data = a;
    remove_x(b, 3);
    for(int i = 0; i< b.length ; i++)
        cout<<b.data[i];
    return 0;
}