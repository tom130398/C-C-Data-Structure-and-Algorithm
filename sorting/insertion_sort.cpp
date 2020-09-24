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

void insertionSort(int a[], int n)
{
	for(int i = 1; i < n; i++)
	{
		int j = i - 1;
		int x = a[i];
		while(j >= 0 && a[j] > x)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = x;
	}
}

int main()
{
	int a[] = {2,3,5,4,1,7,6,9,0};
	print(a, sizeof(a)/sizeof(a[0]));
	insertionSort(a, sizeof(a)/sizeof(a[0]));
	print(a, sizeof(a)/sizeof(a[0]));
}