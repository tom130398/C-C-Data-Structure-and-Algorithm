#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int>& v, int key)
{
	//insert key at the end
	auto i = v.size();
	v.emplace_back(key);

	//rearrange elements
	while(i > 0 && key > v[i % 2 == 0 ? (i/2)-1 : i/2])
	{
		v[i] = v[i % 2 == 0 ? (i/2)-1 : i/2];
		i = i % 2 == 0 ? (i/2)-1 : i/2;
	}
	v[i] = key;
}

template <class T>
void print(T& v, int n)
{
	cout << "Max Heap: [" << flush;
	for(int i = 0; i < n; i++)
	{
		cout << v[i] << flush;
		if(i < n - 1)
			cout << ", " << flush;
	}
	cout << "]" << endl;
}

int main()
{
	vector<int> v = {45, 35, 15, 30, 10, 12, 6, 5, 20};
	print(v, v.size());
	v.reserve(15);	//reserve space for 15 elements
	insert(v, 50);
	print(v, v.size());
	return 0;
}