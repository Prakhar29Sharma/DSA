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

void deletebeg()
{
	if(list == NULL)
	{
		printf("List is Empty!\n");
		return;
	}
	struct node *temp = list;
	list = temp->next;
	freenode(temp);
	return;
}

void deleteend()
{
	if(list == NULL)
	{
		printf("List is Empty!\n");
		return;
	}
	struct node *temp, *prevtemp;
	temp = list;
	while(temp->next!=NULL)
	{
		prevtemp = temp;
		temp=temp->next;
	}
	prevtemp->next = NULL;
	freenode(temp);
	return;
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
			freenode(temp1);
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
			if(count < pos)
			{
				printf("There are less elements!\n");
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

void get_length()
{
	struct node *temp;
	int length;
	length = 0;
	temp = list;
	while(temp!=NULL)
	{
		length++;
		temp = temp->next;
	}
	printf("length of list is %d\n", length);
	return;
}


void search(int target)
{
	struct node *temp;
	temp = list;
	while(temp->next!=NULL)
	{
		if(temp->info == target)
		{
			printf("Found!\n");
			return;
		}
		temp = temp->next;
	}
	printf("Not Found!\n");
	return;
}

void reverse(){
    struct node *t1, *t2, *temp;
    t1 = t2 = NULL;
    if (list == NULL){
        printf("List is empty");
    } else {
        while (list != NULL) {
            t2 = list->next;
            list->next = t1;
            t1 = list;
            list = t2;
        }
        list = t1;
        temp = list;
        printf("Reversed linked list is : ");
        while (temp != NULL) {
            printf("%d ", temp->info);
            temp = temp->next;
        }
        printf("\n");

    }
}

int main()
{
	int choice, n, pos;
	while(1)
	{
		printf("---ADT Menu---\n");
		printf("1. INSERT AT BEGINNING\n");
		printf("2. INSERT AT END\n");
		printf("3. INSERT AT LOCATION\n");
		printf("4. DELETE AT BEGINENNING\n");
		printf("5. DELETE AT END\n");
		printf("6. DELETE AT LOCATION\n");
		printf("7. DISPLAY\n");
		printf("8. SEARCH\n");
		printf("9. COUNT\n");
		printf("10. COPY\n");
		printf("11. CONCATENATE\n");
		printf("12. SPLIT\n");
		printf("13. REVERSE\n");
		printf("14. EXIT\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch(choice) 
		{
			case 1:
				printf("Enter a Number : ");
				scanf("%d", n);
				insertbeg(n);
				break;
			case 2:
				printf("Enter a Number : ");
				scanf("%d", &n);
				insertend(n);
				break;
			case 3:
				printf("Enter a Number : ");
				scanf("%d", &n);
				printf("Enter a position : ");
				scanf("%d", &pos);
				insert(pos, n);
				break;
			case 4:
				deletebeg();
				break;
			case 5:
				deleteend();
				break;
			case 6:
				printf("Enter a position : ");
				scanf("%d", &pos);
				delete(pos);
				break;
			case 7:
				display();
				break;
			case 8:
				printf("Enter a Number to search : ");
				scanf("%d", &n);
				search(n);
				break;
			case 9:
				get_length();
				break;
			case 10:
				// copy()
				break;
			case 11:
				// concat()
				break;
			case 12:
				// split()
				break;
			case 13:
				reverse();
				break;
			case 14:
				exit(0);
				break;
			default:
				printf("Invalid Choice! Try Again\n");
			
		}
	}
	return 0;
}
