#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int a[], int n)
{
	int i, j;
	for(i = 0; i < n-1; i++)
	{
		for(j = 0; j < n-i-1; j++)
		{
			if(a[j] < a[j+1])
				swap(&a[j], &a[j+1]);
		}
	}
}

int main()
{
	int a[] = {3, 4, 7, 2, 8, 1, 9};
	bubbleSort(a, sizeof(a)/sizeof(a[0]));
	for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
		printf("%d, ", a[i]);
	printf("\n");
}