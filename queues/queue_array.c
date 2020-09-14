#include <stdio.h>
#include <stdlib.h>

struct Queue
{
	int size;
	int front;
	int back;
	int *a;
};

//function to initialize a queue
void create(struct Queue *q, int size)
{
	q->size = size;
	q->front = q->back = -1;
	q->a = (int *)malloc(q->size * sizeof(int));
}

//function to add a value in the queue
void enqueue(struct Queue *q, int x)
{
	if(q->back == q->size - 1)
		printf("Queue is full\n");
	else
	{
		q->back++;
		q->a[q->back] = x;
	}
}

//function to remove a value from the queue
int dequeue(struct Queue *q)
{
	int x = -1;
	if(q->front == q->back)
		printf("Queue is empty\n");
	else
	{
		q->front++;
		x = q->a[q->front];
	}
	return x;
}

//function to diplay the queue
void display(struct Queue q)
{
	for(int i = q.front+1; i <= q.back; i++)
		printf("%d ", q.a[i]);
	printf("\n");
}

int main()
{
	struct Queue q;
	create(&q, 5);
	enqueue(&q, 1);
        enqueue(&q, 2);
        enqueue(&q, 3);
        enqueue(&q, 4);
        enqueue(&q, 5);
        dequeue(&q);
	display(q);
}
