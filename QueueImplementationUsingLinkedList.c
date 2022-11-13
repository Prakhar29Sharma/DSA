#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *list = NULL;

struct node* getnode()
{
    return (struct node*)malloc(sizeof(struct node));
}

void enqueue(int x)
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
        temp -> next = nn;
    }
}

void dequeue()
{
    if(list == NULL)
    {
        printf("Queue is Empty!\n");
    }
    else
    { 
        struct node *temp;
        temp = list;
        list = temp->next;
        printf("%d is dequeued!\n", temp->info);
        free(temp);
    }
}

void show()
{
    if(list == NULL)
    {
        printf("List is Empty!\n");
    }
    else
    {
    struct node *temp;
    temp = list;
    while(temp!=NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
    }
}

int main()
{
    int ch, n;
    while(1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Show\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1:
            printf("Enter a value : ");
            scanf("%d", &n);
            enqueue(n);break;
            case 2:
            dequeue();
            break;
            case 3:
            show();
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("Invalid Choice! Try Again!\n");
        }
    }
}