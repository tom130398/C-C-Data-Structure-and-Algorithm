#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node *lchild;
	int data; 
	int height;
	struct Node *rchild;
}*root = NULL;

int nodeheight(struct Node *p)
{
	int hl, hr;

	hl = p && p->lchild ? p->lchild->height : 0;
	hr = p && p->rchild ? p->rchild->height : 0;

	return hl > hr ? hl + 1 : hr + 1;
}

int balanceFactor(struct Node *p)
{
	int hl, hr;

	hl = p && p->lchild ? p->lchild->height : 0;
	hr = p && p->rchild ? p->rchild->height : 0;

	return hl - hr;
}

struct Node *LLRotation(struct Node *p)
{
	struct Node *pl = p->lchild;
	struct Node *plr = pl->rchild;

	pl->rchild = p;
	p->lchild = plr;

	//update height
	p->height = nodeheight(p);
	pl->height = nodeheight(pl);

	//update root
	if(root == p)
		root = pl;

	return pl;
}

struct Node *LRRotation(struct Node *p)
{
	struct Node *pl = p->lchild;
	struct Node *plr = pl->rchild;

	pl->rchild = plr->lchild;
	p->lchild = plr->rchild;
	
	plr->lchild = pl;
	plr->rchild = p;

	//update height
	pl->height = nodeheight(pl);
	p->height = nodeheight(p);
	plr->height = nodeheight(plr);
	
	//update root
	if(root == p)
		root = plr;
	
	return plr;
}

struct Node *RRRotation(struct Node *p)
{
	struct Node* pr = p->rchild;
	struct Node* prl = pr->lchild;

	pr->lchild = p;
	p->rchild = prl;

	// Update height
	p->height = nodeheight(p);
	pr->height = nodeheight(pr);

	// Update root
	if(root == p)
		root = pr;
	
	return pr;
}

struct Node *RLRotation(struct Node *p)
{
	struct Node *pr = p->rchild;
	struct Node *prl = pr->lchild;

	pr->lchild = prl->rchild;
	p->rchild = prl->lchild;

	prl->rchild = pr;
	prl->lchild = p;

	p->height = nodeheight(p);
	pr->height = nodeheight(pr);
	prl->height = nodeheight(prl);

	if(root == p)
		root = prl;

	return prl;
}

struct Node *rInsert(struct Node *p, int key)
{
	struct Node *t = NULL;
	if(p == NULL)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = key;
		t->height = 1;
		t->lchild = t->rchild = NULL;
		return t;
	}
	if(key < p->data)
		p->lchild = rInsert(p->lchild, key);
	else if(key > p->data)
		p->rchild = rInsert(p->rchild, key);

	//update height of every nodes
	p->height = nodeheight(p);

	//check the balance factor
	if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
		return LLRotation(p);
	else if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)
		return LRRotation(p);
	else if(balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1)
		return RRRotation(p);
	else if(balanceFactor(p) == -2 && balanceFactor(p->lchild) == 1)
		return RLRotation(p);
	return p;
}

int main()
{
	root = rInsert(root, 10);
	rInsert(root, 5);
	rInsert(root, 2);

	return 0;
}