#include <iostream>
#include <stdio.h>

int plus(int x)
{
	x++;
	return x;
}

void printarray(int a[], int i)
{
	int j ;
	for (j = 0;j < i; j++)
	{
		std::cout << a[j] << std::endl;
	}
}

/*
int main()
{
	int *psome = new int[10];
	for (int i = 0; i < 10; i++)
	{
		psome[i] = 1;
	}
	printarray(psome, 10);
	delete [] psome;
	std::cout << psome[0] << std::endl;
	std::cin.get();
	return 0;
}
*/

int main(int arg, char *arv[])
{
	int exit_status = EXIT_SUCCESS;
	FILE *input;

	while (*++arv != NULL) {
		fopen_s(&input, "Shadowsocks.md","r");
		if (input == NULL)
		{
			perror(*arv);
			exit_status = EXIT_FAILURE;
			continue;
		}
		else
			printf("Open Success!\n");

		if (fclose(input) != 0)
		{
			perror("fclose");
			exit(EXIT_FAILURE);
		}
	}
	
	system("pause");
	return exit_status;
}