#include <cstdio>
#include <algorithm>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

struct student {
    char id[13];
    int score;
    int final_rank;
    int local_rank;
    int location_number;
} a[100];

bool cmp(student a, student b){
    if ( a.score != b.score ) return a.score > b.score;
    else return strcmp(a.id, b.id) < 0;
}

int main()
{
    int N = 0;
    int K = 0;
    int num = 0;    //考生总数
    scanf("%d", &N); //考场数

    for (int i = 0; i < N ; i++){
        scanf("%d", &K);        //考场内人数
        for (int j = 0; j < K ; j++){
            scanf("%s %d", a[j].id, &a[j].score);
            num++;
            a[j].location_number = j;   //考场号
        }
        //根据分数进行排序
        sort(a + num - K, a + num, cmp);
        a[num - K].local_rank = 1;
        for(int j = num - K + 1; j < num; j++){
            if (a[j].score == a[j-1].score){
                a[j].local_rank = a[j-1].local_rank;
            } else {
                a[j].local_rank = j + 1 - (num - K);
            }
        }
    }
    printf("%d\n", num);
    sort(a, a + num, cmp);  //将所有考生排序
    int r = 1;    //当前考生的姓名
    for(int i = 0; i < num; i++) {
        if(i > 0 && a[i].score != a[i-1].score){
            r = i + 1;  //当前考生与上一个考生分数不同时，让r更新人数+1
        }
        printf("%s ", a[i].id);
        printf("%d %d %d\n", r, a[i].location_number, a[i].local_rank);
    }
    return 0;
}