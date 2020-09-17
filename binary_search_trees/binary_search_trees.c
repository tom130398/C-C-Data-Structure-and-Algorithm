#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node* lchild;
	int data;
	struct Node* rchild;
}*root = NULL;

void insert(int key)
{
	struct Node *t = root;
	struct Node *r, *p;

	if(root == NULL)
	{
		p = (struct Node *)malloc(sizeof(struct Node));
		p->data = key;
		p->lchild = p->rchild = NULL;
		root = p;
		return;
	}
	while(t != NULL)
	{
		r = t;
		if(key < t->data)
			t = t->lchild;
		else if(key > t->data)
			t = t->rchild;
		else
			return;
	}
	p = (struct Node *)malloc(sizeof(struct Node));
	p->data = key;
	p->lchild = p->rchild = NULL;
	if(key < r->data)
		r->lchild = p;
	else
		r->rchild = p;
}

struct Node *rInsert(struct Node *p, int key)
{
	struct Node *t = NULL;
	if(p == NULL)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = key;
		t->lchild = t->rchild = NULL;
		return t;
	}
	if(key < p->data)
		p->lchild = rInsert(p->lchild, key);
	else if(key > p->data)
		p->rchild = rInsert(p->rchild, key);
	return p;
}

void inorder(struct Node *p)
{
	if(p)
	{
		inorder(p->lchild);
		printf("%d ", p->data);
		inorder(p->rchild);
	}
}

struct Node *search(int key)
{
	struct Node *t = root;
	while(t != NULL)
	{
		if(key == t->data)
			return t;
		else if(key < t->data)
			return t->lchild;
		else
			return t->rchild;
	}
	return NULL;
}

int main()
{
	root = rInsert(root,10);
	insert(5);
	insert(20);
	insert(8);
	insert(30);
	inorder(root);
	printf("\n");
	struct Node *temp = search(20);
	if(temp != NULL)
		printf("%d is found\n", temp->data);
	else
		printf("Cannot find given key\n");
}
