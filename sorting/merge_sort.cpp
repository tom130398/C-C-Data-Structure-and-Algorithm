#include <iostream>
using namespace std;

template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

void merge(int a[], int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = low;
	int b[high+1];
	while(i <= mid && j <= high)
	{
		if(a[i] < a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while(i <= mid)
		b[k++] = a[i++];
	while(j <= high)
		b[k++] = a[j++];
	for(int i = low; i <= high; i++)
		a[i] = b[i];
}

void iterativeMergeSort(int a[], int n)
{
	int p;
	for(p = 2; p <= n; p=p*2)
	{
		for(int i = 0; i+p-1 < n; i+=p)
		{
			int low = i;
			int high = i + p - 1;
			int mid = (low + high)/2;
			merge(a, low, mid, high);
		}
	}
	if(p/2 < n)
		merge(a, 0, p/2 - 1, n - 1);
}

int main()
{
	int a[] = {2,5,1,6,4,9,7,3,8,0};
	int n = sizeof(a)/sizeof(a[0]);
	Print(a, n, "\t\tA");
	iterativeMergeSort(a, n);
	Print(a, n, "Sorted");
}