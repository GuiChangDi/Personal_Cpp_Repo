#include "../Header/Order.h"
#include <iostream>
#include <string.h>
#include <vector>
#include <stack>

//Use BFS to count area
void countarea()
{
	struct note
	{
		int x;
		int y;
	};

	struct note que[2501];//   50*50
	int head, tail;
	int a[51][51] = { 0 };
	int book[51][51] = { 0 };
	int i, j, k, sum, n, m, startx, starty, tx, ty;
	//Direct Array
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

	//Read n row,m line and start position (startx,starty)
	std::cout << "Input n :";
	std::cin >> n;
	std::cout << "Input m :";
	std::cin >> m;
	std::cout << "Input (startx,starty):";
	std::cin >> startx >> starty;

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			std::cin >> a[i][j];

	//Init que
	head = 1;
	tail = 1;
	//Insert the Initiate start
	que[tail].x = startx;
	que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;
	sum = 1;

	//Loop while que not empty
	while (head < tail)
	{
		//4 direction
		for (k = 0; k < 4; k++)
		{
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];

			//Judge whether out of space
			if (tx < 1 || tx > n || ty < 1 || ty > m)
				continue;
			//Judge whether in the path or not accessible
			if (book[tx][ty] == 0 && a[tx][ty] > 0)
			{
				book[tx][ty] = 1;//Mark in path
				sum++;
				que[tail].x = tx;
				que[tail].y = ty;
				tail++;
			}
		}
		head++;//After 1 point ,out que
	}
	std::cout << "Total area = " << sum;
}

 struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int m,i,j;
    struct ListNode *p1,*p2;
    p1 = l1;
    p2 = l2;
    int temp1 = 0, temp2 = 0;
    i = j = 0;
    while(p1 != NULL)
    {
        m = p1->val * (10^i);
        temp1 += m;
        i++;
        p1 = p1->next;
    }
    
    while(p2 != NULL)
    {
        m = p2->val * (10^j);
        temp2 += m;
        j++;
        p2 = p2->next;
    }
    
    int out = temp1+temp2;
    int temp;
    struct ListNode* result;
    while(out != 0)
    {
        temp =  out%10;
        out /= 10;
        result->val = temp;
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        result->next = node;
        result = result->next;
    }
    return result;
}