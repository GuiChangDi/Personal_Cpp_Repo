#pragma once

struct queue
{
	int data[100];
	int head;
	int tail;
};

struct stack_internal
{
	int data[100];
	int top;
};

struct node
{
	int data;
	struct node *next;
};


static int fun(int x);//caculate how many sticks x need. 
int enumMath(int n);//A+B = C.Enumerate all possible results.n is stick number.+,= needs 4 stick
void Permutation(int num,int n);//Full Permutation
void CurrentStatus_DFS(int x, int y, int step);//DFS to find the shortest way to target.Use recursive.
void CurrentStatus_BFS();//BFS to find the shortest way ,no recursive.
void countarea();//BFS to caculate total area
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);