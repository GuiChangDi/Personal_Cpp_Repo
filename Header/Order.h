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

int bucket(int a[], int n);
int bubble(int a[], int n);
int rapidorder(int a[], int left, int right);
int removemutli(int a[], int n);
void Judgepalindrome();
void Catfish(int n);