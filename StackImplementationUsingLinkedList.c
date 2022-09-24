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
	return (struct node*)malloc(sizeof(struct node));
}

void push(int x)
{
	if(list == NULL)
	{
		struct node *nn;
		nn = getnode();
		nn->info = x;
		nn->next = NULL;
		list = nn;

	}
	else
	{
		struct node *nn, *temp;
		nn = getnode();
		temp = list;
		nn->info = x;
		nn->next = NULL;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = nn;
	}
}

void pop()
{
	if(list == NULL)
	{
		printf("Stack is Empty!\n");
	}
	else
	{
		struct node *temp, *prev;
		temp = list;
		while(temp->next!=NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
		printf("%d got popped!\n",temp->info);
	}
}

void show()
{
	if(list == NULL)
	{
		printf("Stack is Empty!\n");
	}
	else
	{
		struct node *temp;
		temp = list;
		while(temp!=NULL)
		{
			printf("%d\n", temp->info);
			temp = temp->next;
		}
	}
}

int main()
{
	
    int ch, n;
    while(1) {
        printf("\n------stack_menu-------");
        printf("\n1. push");
        printf("\n2. pop");
        printf("\n3. show");
        printf("\n4. Exit");

        printf("\nEnter Your Choice : ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter a Number to push : ");
                scanf("%d", &n);
                push(n);break;
            case 2:
                pop();
                break;
            case 3:
                show();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nInvalid Choice! Try Again!");
        }
	}

    return 0;
}