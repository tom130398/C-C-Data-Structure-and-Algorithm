#include <stdio.h>
#include <stdlib.h>

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

int partition(int a[], int l, int h)
{
	int pivot = a[l];
	int i = l;
	int j = h;
	do
	{
		do{i++;}	while(a[i] <= pivot);
		do{j--;}	while(a[j] > pivot);
		if(i < j)
			swap(&a[i], &a[j]);
	}
	while(i < j);
	swap(&a[l], &a[j]);
	return  j;
}

void quicksort(int a[], int l, int h)
{
	int j;
	if(l < h)
	{
		j = partition(a, l, h);
		quicksort(a, l, j);
		quicksort(a, j+1, h);
	}
}

int main()
{
	int a[] = {9,3,5,1,6,8,0,4,7,2};
	int n= sizeof(a)/sizeof(a[0]);
	quicksort(a, 0, n);
	print(a, n);
}