#include <iostream>

//Time complexity = O(N)  
//just support 0-9
void
bucket(
	void
)
{
	int i, temp;
	int *a = new int[10]();

	for (i = 0; i < 10; i++)
	{
		std::cout << "Input the " << i << " number:(0-9): ";
		std::cin >> temp;
		a[temp]++;
	}
	std::cout << "After bucket order,outcome is:" << std::endl;

	for (i = 0; i < 10; i++)
	{
		for (int j = 1; j <= a[temp]; j++)
			std::cout << i << " ";
	}
	delete[] a;
	return;
}

int main(
  int   argc,
  char* argv[]
)
{
  bucket();
  std::cin.get();
  std::cin.get();
  return 0;
}