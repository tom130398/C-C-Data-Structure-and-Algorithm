#include <stdio.h>

void print(int a[], int n)
{
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int a[], int n)
{
	int i, j, k;
	for(i = 0; i < n-1; i++)
	{
		for(j = k = i; j < n; j++)
		{
			if(a[j] < a[k])
				k = j;
		}
	swap(&a[i], &a[k]);
	}
}

int main()
{
	int a[] = {2,3,5,4,1,7,6,9,0};
	print(a, sizeof(a)/sizeof(a[0]));
	selectionSort(a, sizeof(a)/sizeof(a[0]));
	print(a, sizeof(a)/sizeof(a[0]));
}
