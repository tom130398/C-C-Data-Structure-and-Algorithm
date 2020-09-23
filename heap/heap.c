#include <stdio.h>

void insert(int a[], int n)
{
	int i = n;
	int temp = a[n];
	while (i > 0 && temp > a[i % 2 == 0 ? (i/2)-1 : i/2])
	{
		a[i] = a[i % 2 == 0 ? (i/2)-1 : i/2];
		i = i % 2 == 0 ? (i/2)-1 : i/2;
	}
	a[i] = temp;
}

void print(int a[], int n)
{
	printf("Max Heap: [");
	for(int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if(i < n - 1)
			printf(", ");
	}
	printf("]\n");
}

void createHeap(int a[], int n)
{
	for(int i = 0; i < n; i++)
		insert(a, i);
}

int main()
{
	int a[] = {10, 20, 30, 25, 5, 40, 35};
	createHeap(a, sizeof(a)/sizeof(a[0]));
	print(a, sizeof(a)/sizeof(a[0]));
	printf("\n");	
	return 0;
}