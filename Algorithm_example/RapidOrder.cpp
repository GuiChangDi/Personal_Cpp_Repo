#include <iostream>
#include <stack>

//Recursive version,Adverage Time Complexity O(nLogn),Max Time Complexity O(N^2)
void
RapidOrder(
	int a[],
	int low,
	int high
)
{
	int i, j, temp,p;
	if (low >= high)
		return;

	i = low;
	j = high;
	p = a[low];

	while (i < j)
	{
		while (p <= a[j] && i<j)
			j--;
		while (p >= a[i] && i<j)
			i++;
		if (i < j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	a[low] = a[i];
	a[i] = p;
	RapidOrder(a, low, i - 1);
	RapidOrder(a, i + 1, high);
}

//RapidOrder No-recursive version.Using stack to simulate the recursive.
static
int
RapidOrder_OneRound(
	int a[],
	int low,
	int high
)
{
	int i = low;
	int j = high;
	int p = a[low];
	int temp;
	if (low >= high)
		return low;

	while (i != j)
	{
		while (a[j] >= p && i < j)
			j--;
		while (a[i] <= p && i < j)
			i++;
		if (i < j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	a[low] = a[i];
	a[i] = p;
	return i;
}

void RapidOrder_NoRecursive(int a[], int left, int right)
{
	std::stack<int> st;
	if (left < right)
	{
		int mid = RapidOrder_OneRound(a, left, right);
		if (left < mid - 1)
		{
			st.push(left);
			st.push(mid - 1);
		}
		if (right > mid + 1)
		{
			st.push(mid + 1);
			st.push(right);
		}
		while (!st.empty()) {
			int q = st.top();
			st.pop();
			int p = st.top();
			st.pop();
			mid = RapidOrder_OneRound(a, p, q);
			if (p<mid - 1)
			{
				st.push(p);
				st.push(mid - 1);
			}
			if (q>mid + 1)
			{
				st.push(q);
				st.push(mid + 1);
			}
		}
	}
}

int main(
	int     argc,
	char    *argv[]
)
{
	int a[10] = { 2,1,0,5,7,4,23,54,34,19 };
	RapidOrder_NoRecursive(a, 0, 9);
	for (int i = 0; i < 10; i++)
		std::cout << a[i] << " ";
	std::cin.get();
	std::cin.get();
	return 0;
}