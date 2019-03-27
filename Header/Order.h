#pragma once

struct queue
{
	int data[100];
	int head;
	int tail;
};

struct stack
{
	int data[100];
	int top;
};

struct node
{
	int data;
	struct node *next;
};

int bucket(int a[], int n);
int bubble(int a[], int n);
int rapidorder(int a[], int left, int right);//Make order
int removemutli(int a[], int n);
void Judgepalindrome();//Judge whether string is palindrome
void Catfish(int n);//Use 2 queue and 1 stack to determing which person will win
static int fun(int x);//caculate how many sticks x need. 
int enumMath(int n);//A+B = C.Enumerate all possible results.n is stick number.+,= needs 4 stick
void Permutation(int num,int n);//Full Permutation