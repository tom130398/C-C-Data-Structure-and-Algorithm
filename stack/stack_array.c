#include <stdio.h>
#include <stdlib.h>

struct Stack
{
	int size;
	int top;
	int *s;
};

//function to initialize the stack
void create(struct Stack *st)
{
	printf("Enter size: ");
	scanf("%d", &st->size);
	st->top = -1;
	st->s = (int*)malloc(st->size*sizeof(int));
}

//function to display the stack
void display(struct Stack st)
{
	for(int i = st.top; i >= 0; i--)
		printf("%d ", st.s[i]);
	printf("\n");
}

//function to add a value to the top of the stack
void push(struct Stack *st, int x)
{
	if(st->top == st->size-1)
		printf("Stack Overflow\n");
	else
	{
		st->top++;
		st->s[st->top] = x;
	}
}

//function to remove a value from the top of the stack
int pop(struct Stack *st)
{
	int x = -1;
	if(st->top == -1)
		printf("Stack Underflow\n");
	else
	{
		x = st->s[st->top];
		st->top--;
	}
	return x;
}

//function to find a element with given position in stack
int peek(struct Stack st, int pos)
{
	int x = -1;
	if(st.top - pos < 0)
		printf("Invalid Position\n");
	else
		x = st.s[st.top - pos + 1];
	return x;
}

int main()
{
	struct Stack st;
	create(&st);
	push(&st,10);
        push(&st,20);
        push(&st,30);
        push(&st,40);
        push(&st,50);
	printf("%d\n", peek(st, 1));
	display(st);
	return 0;
}
