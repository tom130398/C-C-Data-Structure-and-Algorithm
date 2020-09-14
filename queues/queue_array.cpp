#include <iostream>
using namespace std;

class Queue
{
private:
	int front;
	int back;
	int size;
	int *a;
public:
	Queue(int size);
	~Queue();
	bool isFull();
	bool isEmpty();
	void enqueue(int x);
	int dequeue();
	void display();
};

Queue::Queue(int size)
{
        front = back = 0;
        this->size = size;
        a = new int[this->size];
}

Queue::~Queue()
{
	delete [] a;
}

bool Queue::isEmpty() {
	if(front == back)
		return true;
	return false;
}

bool Queue::isFull() {
	if ((back + 1) % size == front)
        	return true;
	return false;
}

void Queue::enqueue(int x)
{
	if(isFull())
		cout << "Queue is full" << endl;
	else
	{
		back = (back + 1) % size;
		a[back] = x;
	}
}

int Queue::dequeue()
{
	int x = -1;
	if(isEmpty())
		cout << "Queue is empty" << endl;
	else
	{
		front = (front + 1) % size;
		x = a[front];
	}
	return x;
}

void Queue::display()
{
	int i = front + 1;
	do
	{
		cout << a[i] << flush;
		if(i < back)
			cout << "<-" << flush;
		i = (i + 1) % size;
	}while(i != (back + 1) % size);
	cout << endl;
}

int main()
{
	Queue q(5);
	q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40);
        q.enqueue(50);
        q.enqueue(60);
	q.display();
	cout << q.dequeue() << endl;
	q.display();
}
