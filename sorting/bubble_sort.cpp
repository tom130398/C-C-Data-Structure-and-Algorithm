#include <iostream>
using namespace std;

template <class T>
void print(T& v, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << v[i] << flush;
	}
	cout << endl;
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int a[], int n)
{
	for(int i = 0; i < n-1; i++)
	{
		for(int j = 0; j < n-i-1; j++)
		{
			if(a[j] > a [j+1])
				swap(a[j], a[j+1]);
		}
	}
}

int main()
{
	int a[] = {3,5,1,7,4,8,2,9};
	bubbleSort(a, sizeof(a)/sizeof(a[0]));
	print(a, sizeof(a)/sizeof(a[0]));
}