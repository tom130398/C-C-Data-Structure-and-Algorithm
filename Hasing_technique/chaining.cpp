#include <iostream>
using namespace std;

//linked list node
class Node{
public:
	int data;
	Node* next;
};

//hash table
class HashTable{
public:
	Node** HT;
	HashTable();
	int hash(int key);
	void insert(int key);
	int search(int key);
	~HashTable();
};

HashTable::HashTable()
{
	HT = new Node* [10];
	for(int i = 0; i < 10; i++)
		HT[i] = nullptr;
}

int HashTable::hash(int key)
{
	return key % 10;
}

void HashTable::insert(int key)
{
	int i = hash(key);
	Node *t = new Node;
	t->data = key;
	t->next = nullptr;

	//Case: no node in the linked list
	if(HT[i] == nullptr)
		HT[i] = t;
	else
	{
		Node *p = HT[i];
		Node *q = HT[i];
		while(p && p->data < key)
		{
			q = p;
			p = p->next;
		}
		//Case: insert position first
		if(q == HT[i])
		{
			t->next = HT[i];
			HT[i] = t;
		}
		else
		{
			t->next = q->next;
			q->next = t;
		}
	}
}

int HashTable::search(int key)
{
	int i = hash(key);
	Node *p = HT[i];
	while(p)
	{
		if(p->data == key)
			return p->data;
		p = p->next;
	}
	return -1;
}

HashTable::~HashTable()
{
	for(int i = 0; i < 10; i++)
	{
		Node* p = HT[i];
		while(HT[i])
		{
			HT[i] = HT[i]->next;
			delete p;
			p = HT[i];
		}
	}
	delete [] HT;
}

int main()
{
	int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
	int n = sizeof(A)/sizeof(A[0]);
	HashTable H;
	for (int i=0; i<n; i++){
		H.insert(A[i]);
	}
	cout << "Successful Search" << endl;
	int key = 6;
	int value = H.search(key);
	cout << "Key: " << key << ", Value: " << value << endl;
	cout << "Unsuccessful Search" << endl;
	key = 95;
	value = H.search(key);
	cout << "Key: " << key << ", Value: " << value << endl;

	return 0;
}