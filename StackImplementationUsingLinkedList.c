#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *list = NULL;

struct node* getnode()
{
	return ((struct node*)malloc(sizeof(struct node)));
}

void freenode(struct node *p)
{
	free(p);
}

void insertbeg(int x)
{
	struct node *nn;
	nn = getnode();
	nn->info = x;
	nn->next = list;
	list = nn;
}

void insertend(int x)
{
	struct node *nn, *temp;
	nn = getnode();
	nn->info = x;
	nn->next = NULL;
	temp = list;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = nn;
}

void push(int x) 
{
	return;
}

int pop()
{
	return 0;
}

void display()
{
	return;
}
