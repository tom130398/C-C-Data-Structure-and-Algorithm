#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

class Stack
{
private:
	Node *top;
public:
	Stack()
	{
		top = NULL;
	}
	void push(int x);
	int pop();
	void display();
};

//function to add value to the top of the stack
void Stack::push(int x)
{
	Node *t = new Node;
	if(t == NULL)
		cout << "Stack is full" << endl;
	else
	{
		t->data = x;
		t->next = top;
		top = t;
	}
}

//funtion to remove a value from the top of the stack
int Stack::pop()
{
	int x = -1;
	if(top == NULL)
		cout << "Stack is empty" << endl;
	else
	{
		x = top->data;
		Node *t = top;
		top = top->next;
		delete t;
	}
	return x;
}

//function to display the stack
void Stack::display()
{
	Node *p = top;
	while(p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	Stack stk;
	stk.push(10);
	stk.push(11);
	stk.push(12);
	stk.display();
	cout << stk.pop() << endl;
	return 0;
}
