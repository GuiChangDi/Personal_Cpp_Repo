#include "../Header/Order.h"
#include <iostream>

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
	int flag = 0;//indicate whether there is match on table.
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