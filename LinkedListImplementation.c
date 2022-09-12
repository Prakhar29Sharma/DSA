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

void delete(int pos)
{
	if(list == NULL)
	{
		printf("List is Empty!\n");
	}
	else
	{
		struct node *temp1 = list;
		if(pos == 1)
		{
			list = list->next;
			free(temp1);
			return;
		}
		else
		{
			struct node *temp2;
			temp2 = list;
			int count;
			count = 1;
			while(temp1->next!=NULL)
			{
				if(count == pos-1)
				{
					temp2=temp2->next;
					temp1->next = temp2->next;
				}
				count++;
				temp1=temp1->next;
				temp2=temp2->next;
			}
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

void insert(int pos, int val)
{
	
	if(list == NULL)
	{
		char ch;
		printf("List is Empty!\n");
		printf("Do you want to add element at first position ? ");
		scanf("%c", &ch);
		if(ch == 'y' || ch == 'Y')
		{
			insertbeg(val);
		}
		else
		{
			return;
		}
	}
	else
	{
		int count = 1;
		struct node *nn, *t;
		t = list;
		
		while(t->next!=NULL)
		{

			if(count == pos-1)
			{
				nn = getnode();
				nn->info = val;
				nn->next = t->next;
				t->next = nn;
				break;
			}
			t=t->next;
			count++;
		}
	}

}

void display()
{
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
			t = t->next;
		}
	}
	printf("\n");
}

int main()
{
	display();
	insertbeg(3);
	insertbeg(5);
	insertbeg(2);
	display();
	insertend(1);
	display();
	insert(2,8);
	display();
	delete(2);
	display();
	return 0;
}
