#include<stdio.h>

struct node
{
	int info;
	struct node *next;
};

struct node *list = NULL;

struct node* getnode(void)
{
	return ((struct node*)malloc(sizeof(struct node)));
}

void freenode(struct node *p)
{
	free(p);
}

void insertbeg(int x)
{
	struct node *newnode;
	newnode = getnode();
	newnode->info=x;
	newnode->next=list;
	list=newnode;
	display();
}

void insertend(int x)
{
	struct node *newnode, *temp;
	newnode = getnode();
	newnode->info=x;
	newnode->next=NULL;
	temp=list;
	if(temp==NULL)
		list=newnode;
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
	display();
}

void display()
{
	int i;
	struct node *t;
	t = list;
	if(t == NULL)
		printf("\nList is Empty!");
	else
	{
		while(t!=NULL)
		{
			printf("%d", t->info);
			t=t->next;
		}
	}
}

int main()
{
	
}
