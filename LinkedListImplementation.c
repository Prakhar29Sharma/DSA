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

void display()
{
	int i;
	struct node *t;
	t = list;
	if(t == NULL)
	{
		printf("List is Empty!\n");
	}
	else
	{
		while(t!=NULL)
		{
			printf("%d ", t->info);
			t=t->next;
		}
	}
}


void insertbeg(int x)
{
	struct node *nn;
	nn = getnode();
	nn->info = x;
	nn->next = list;
	list = nn;
	display();
}

void insertend(int x)
{
	struct node *nn, *temp;
	nn = getnode();
	nn->info = x;
	nn->next = NULL;
	temp = list;
	if(temp == NULL)
	{
		list = nn;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = nn;
	}
	freenode(temp);
	display();
}


void insert(int p, int x)
{
	if(list == NULL)
	{	
		char ch;
		printf("List is Empty!\n");
		printf("Do you want to add first element ? ");
		scanf("%c", &ch);
		if(ch == 'y')
		{
			insertbeg(x);
		}
		else
		{
			return;
		}
	}
	else
	{
		int count;
		count = 1;
		struct node *temp, *nn;
		temp = list;
		while(temp->next!=NULL)
		{
			temp = temp->next;
			count++;
			if(count == p-1)
			{
				nn = getnode();
				nn->info = x;
				nn->next = temp->next;
				temp->next = nn;
			}
		}
		display();
	}
}

int main()
{
	display();
	insertbeg(4);
	insertbeg(5);
	insertend(2);
	insert(2,1);
	return 0;
}
