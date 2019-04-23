#include "../Header/Order.h"
#include <iostream>
#include <string.h>

//Time complexity = O(N)  
int bucket(int a[], int n) {
	int i, t;
	for (i = 0; i < n; i++)
	{
		a[i] = 0;
	}

	for (i = 1; i <= n; i++)
	{
		std::cout << "Input the " << i << " number:";
		std::cin >> t;
		a[t]++;
	}

	std::cout << std::endl<< "Outcome:" << std::endl;
	for (i = 0; i < n; i++)
	{
		for (int j = 1; j <= a[i]; j++)
			std::cout << i ;
	}

	std::cout<<std::endl;
	return 1;
}

//BinarySearch no recursive, Time complexity = O(logN)
int
BinarySearch(const int A[],int X,int N)
{
    int low,mid,high;
    low = 0,high = N-1;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(mid == X)
            return true;
        else if(A[mid] <= X)
            low = mid + 1;
        else if(A[mid] > X)
            high = mid-1;
    }
    return false;
}

//Time complexity = O(N^2)     if a[i] > a[i+1], switch up 
int bubble(int a[], int n)
{
	int t,temp;
	for (int i = 0; i < n; i++)
	{
		std::cout << "Input the " << i+1 << " number:";
		std::cin >> t;
		a[i] = t;
	}

	std::cout << "The array is: ";
	for (int i = 0; i < n; i++)
		std::cout << a[i]<<" ";

	for (int i = n-1;i>=0;i--)
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}

	std::cout << std::endl<<"After bubble order,array is: ";
	for (int i = 0; i < n; i++)
		std::cout << a[i]<<" ";
	return 1;
}

//Rapid order Time complexity: MAX O(N^2), Average O(NlogN)
int rapidorder(int a[],int left, int right)
{
	int temp, i, j, refer;
	if (left >= right)
		return 0;

	i = left;
	j = right;
	refer = a[left];

	while (i != j)
	{
		while (a[j] >= refer && i<j)
			j--;
		while (a[i] <= refer && i<j)
			i++;
		if (i < j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	a[left] = a[i];
	a[i] = refer;

	//recursion
	rapidorder(a, left, i - 1);
	rapidorder(a, i + 1, right);
	return 1;
}

//Remove repeat elem in array and sort
int removemutli(int a[], int n)
{
	int p,num;
	num = 0;
	for (int i = 0; i < 100; i++)
		a[i] = 0;

	for (int i = 0; i < n; i++)
	{
		std::cout << "Input the " << i + 1 << " number:";
		std::cin >> p;
		a[p] = 1;
	}

	std::cout << "The outcome is :" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (a[i] > 0)
		{
			num++;
			std::cout << i << " ";
		}
	}
	std::cout << "Total count number: " << num << std::endl;
	return 1;
}

//Use stack to judge string whether is palindrome
void Judgepalindrome()
{
	int a[100];
	char b[10];
	int i;
	int mid, next, top = -1;
	std::cin >> b;
	int len = strlen(b);
	if (len % 2 == 0)
	{
		mid = len / 2;
		next = mid + 1;
	}
	else
	{
		mid = len / 2 + 1;
		next = mid;
	}

	for (i = 0; i < mid; i++)
		a[++top] = b[i];
	for (i = next - 1; i < len; i++)
	{
		if (b[i] != a[top])
			break;
		top--;
	}
	if (top != -1)
		std::cout << "Not" << std::endl;
	else
		std::cout << "Yes" << std::endl;
}

//Use 2 queue and 1 stack to determing which person will win
void Catfish(int n)
{
	//initilize queue and stack
	struct queue qu1, qu2;
	struct stack s;
	int mark[10];//array indicate current number we have
	qu1.head = qu2.head = 1;
	qu1.tail = qu2.tail = 1;
	s.top = 0;
	
	static int count = 0;
	for (int i = 1; i < 9; i++)
		mark[i] = 0;
	std::cout << "Input Person A's Cards: \n";
	for (int i = 1; i <= n; i++)
	{
		std::cout << "Input the " << i << " Number:";
		std::cin >> qu1.data[qu1.tail];
		qu1.tail++;
	}

	std::cout << "Input Person B's Cards: \n";
	for (int i = 1; i <= n; i++)
	{
		std::cout << "Input the " << i << " Number:";
		std::cin >> qu2.data[qu2.tail];
		qu2.tail++;
	}


 	while ((qu1.head != qu1.tail) && (qu2.head != qu2.tail) && count <=100)//Set boundary conditions: Person A or Person B have no cards,or Round num up to 100.
	{
		//Person A put out card.
		int t1 = qu1.data[qu1.head];//person A put a card
		//Judge if there is the same card number on the table
		if(mark[t1] == 0)//there is no same card on the table
		{
			//make t1 out queue,and push to stack
			qu1.head++;
			s.data[++s.top] = t1;
			mark[t1] = 1;//mark there is already have card value as t1
		}
		else//there already have the same card on the table
		{
			//make t1 out queue
			qu1.head++;
			qu1.data[qu1.tail++] = t1;//push to end of queue
			while (s.data[s.top] != t1)//Place the card number on table to queue one by one until to the same card number.
			{
				mark[s.data[s.top]] = 0;//unmark
				qu1.data[qu1.tail++] = s.data[s.top];
				s.top--;
			}
		}

		//Person B put out card.
		int t2 = qu2.data[qu2.head];//person B put a card
		//Judge if there is the same card number on the table
		if (mark[t2] == 0)//there is no same card on the table
		{
			qu2.head++;//card out of queue
			s.data[++s.top] = t2;//card put in to stack
			mark[t2] = 1;//mark card on the table
		}
		else//there already have the same card on the table
		{
			qu2.head++;//card t2 out queue
			qu2.data[qu2.tail++] = t2;//push t2 to end of queue
			while (s.data[s.top] != t2)//Place the card number on table to queue one by one until to the same card number.
			{
				mark[s.data[s.top]] = 0;//unmark
				qu2.data[qu2.tail++] = s.data[s.top];
				s.top--;
			}
		}
		count++;//round num 
	}

	//Judge who win the game
	if (qu2.head == qu2.tail)//Person A win this game
	{
		std::cout << "Game round: " << count << std::endl;
		std::cout << "Person A win! \nHis cards number is: ";
		for (int i = qu1.head; i < qu1.tail; i++)//show Person A card number
			std::cout << qu1.data[i] << " ";
		if (s.top > 0)
		{
			std::cout << "\nThe table cards: ";
			for (int i = 1; i <= s.top; i++)
				std::cout << s.data[i] << " ";
		}
		else
			std::cout << "\nThere is no card on the table!";
	}
	else//Person B win this game
	{
		std::cout << "Game round: " << count << std::endl;
		std::cout << "Person B win! \nHis cards number is: ";
		for (int i = qu2.head; i < qu2.tail; i++)//show Person B card number
			std::cout << qu2.data[i] << " ";
		if (s.top > 0)
		{
			std::cout << "\nThe table cards: ";
			for (int i = 1; i <= s.top; i++)
				std::cout << s.data[i] << " ";
		}
		else
			std::cout << "\nThere is no card on the table!";
	}
}

static int fun(int x)//caculate how many sticks x need. 
{
	int num = 0;
	int a[10] = { 4,2,5,5,4,5,6,3,7,6 };
	while (x / 10 != 0)
	{
		num += a[x % 10];
		x /= 10;
	}
		num += a[x];
	return num;
}

int enumMath(int n)//A+B = C.Enumerate all possible results.n is stick number.+,= needs 4 stick
{
	int num_max = 1111;
	int A, B,C,sum = 0;
	for (A = 0; A <= num_max; A++)
	{
		for (B = 0; B <= num_max; B++)
		{
			C = A + B;
			if (fun(A) + fun(B) + fun(C) == n - 4)
			{
				std::cout << A << " + " << B << " = " << C<<std::endl;
				sum++;
			}
		}
	}
	std::cout << "Total results number: " << sum;
	return sum;
}

//Full Permutation
int Per1[10], Per2[10];
void Permutation(int num,int n)//n: the permutation range,num: the location so far program has been.
{
	int i;
	static int count = 0;

	//Up to max num
	if (num == n)
	{
		count++;
		for (i = 0; i < n; i++)
			std::cout << Per1[i] << " ";
		std::cout << std::endl;
		std::cout << "The " << count << " Result" << std::endl;
		std::cout << std::endl;
		return;
	}

	for (i = 0; i < n; i++)
	{
		if (Per2[i] == 0)//if i wasn't in Per2[]
		{
			Per1[num] = i;//Put i into the num'st position
			Per2[i] = 1;//mark i has been used

			//Now through recursive
			Permutation(num + 1,n);
			Per2[i] = 0;//try to retrive the i number
		}
	}
	return;
}

//Found the short path to target,DFS
void CurrentStatus_DFS(int x, int y, int step)//step means so far steps we have go  
{
	int n, m, p, q, min = 99999999;
	int map[51][51], book[51][51];  //a[] record whether this point is obstacle, book[51] record whether this point has been in the path.
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} }; //four direction to go,Right Down,Left,Right
	int tx, ty, k;
	std::cin>>p>>q;
	std::cin>>n>>m;
	if (x == p && x == q)
	{
		if(step < min);
			min = step;
		return;//Important,otherwise will loop forever
	}

	//enmurate four direction
	for (k = 0; k < 4; k++)
	{
		//caculate the next coordinate
		tx = x + next[k][0];
		ty = y + next[k][1];
		if (tx < 1 || tx > n || ty < 1 || ty > m)//Judge whether out of range
			continue;
		if(map[tx][ty] == 0 && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;//Mark this point has been in path
			CurrentStatus_DFS(tx, ty, step + 1);//Try the next point
			book[tx][ty] = 0;//Done try,unmark this point;Important!!!!!!!!!!!!!!!!!!!!!
		}
	}
	return;
}

//Found the shortest way to target,using Breadth First Search,no recursive
/**
----------------->Y
|
|
|
|
|
|X
**/

void CurrentStatus_BFS()
{
	struct note
	{
		int x;//X-axis
		int y;//Y-axis
		int s;//step count
		int f;//the last position
	};
	struct note que[2501];//set map size = 50*50
	int head, tail;
	int a[51][51] = { 0 };//store map
	int book[51][51] = { 0 };//record which point has been in queque,prevent a point being visited repeatly.
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };//right,down,left,up
	int k, n, m, startx, starty, p, q, tx, ty, flag;

	std::cout << "Input m,n:\n";//Input the map range
	std::cin >> m >> n;

	std::cout << "Input start position:";
	std::cin >> startx >> starty;

	std::cout << "Input the destination";
	std::cin >> p >> q;

	//Initiate queque
	head = 1;
	tail = 1;
	//Add (starts=x,starty) to queque,and mark it.
	que[tail].x = startx;
	que[tail].y = starty;
	que[tail].s = 0;
	que[tail].f = 0;
	tail++;
	book[startx][starty] = 1;//Mark
	flag = 0;//Indicate whether reach the desitination,0 not reach,1 reach
	
	//while que is not empty loop
	while (head < tail)
	{
		//enum the 4 direction
		for (k = 0; k < 4; k++)
		{
			//the next point
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];
			//Judge whether out of space
			if (tx < 1 || tx > n || ty < 1 || ty > m)
				continue;
			//Judge whether this point is obstacle or already on the path
			if (a[tx][ty] == 0 && book[tx][ty] == 0)
			{
				//Mark this point 
				//BFS every point only in que for once,no need to restore book[][]
				book[tx][ty] = 1;
				//Insert to que
				que[tail].x = tx;
				que[tail].y = ty;
				que[tail].f = head;
				que[tail].s = que[head].s + 1;
				tail++;
			}
			//If reach the destination,return
			if (tx == p && ty == q)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
		head++;//Out que
	}
	std::cout << "Total step : " << que[tail - 1].s << std::endl;
}

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