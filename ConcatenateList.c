// Concatenate Linked List

#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node* getnode()
{
    return (struct node*)malloc(sizeof(struct node));
}

struct node *list1 = NULL;
struct node *list2 = NULL;
struct node *list3 = NULL;

void insertbeg(struct node *list, int x)
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
        struct node *nn;
        nn = getnode();
        nn->info = x;
        nn->next = list;
        list = nn;
    }
}

void insertend(struct node *list, int x)
{
    if(list == NULL)
    {
        int ch;
        printf("List is Empty!\n");
        printf("Do you want to insert at beginning?\n");
        printf("Enter 1 to do so : ");
        scanf("%d", &ch);
        if(ch == 1)
        {
            insertbeg(list, x);
        }
    }
    else
    {
        struct node *nn, *temp;
        temp = list;
        nn = getnode();
        nn->info = x;
        nn->next = NULL;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
}

void show(struct node* list)
{
    struct node *temp;
    temp = list;
    while(temp!=NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
    return;
}

struct node* concat(struct node *list1, struct node *list2)
{
    struct node *list3 = NULL;
    struct node *temp;
    temp = list1;
    while(temp->next!=NULL)
    {
        insertend(list3, temp->info);
        temp = temp->next;
    }
    temp = list3;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = list2;
    temp = list2;
    while(temp->next!=NULL)
    {
        insertend(list3, temp->info);
        temp = temp->next;
    }
    return list3;
}

int main()
{
    int ch, n;
    while(1)
    {
        printf("-----main options----\n");
        printf("1. Perform ops on List1\n");
        printf("2. Perform ops on List2\n");
        printf("3. Concatenate List1 and List2\n");
        printf("4. Exit");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        if(ch == 1)
        {
            while(1)
            {
            printf("----list1 menu----\n");
            printf("1. Insert at beginning\n");
            printf("2. Insert at end\n");
            printf("3. Show\n");
            printf("4. Exit\n");
            printf("Enter your choice : ");
            scanf("%d", &ch);
            switch(ch)
            {
                case 1:
                    printf("Enter a value to insert at beg : ");
                    scanf("%d", &n);
                    insertbeg(list1, n);
                    break;
                case 2:
                    printf("Enter a value to insert at end : ");
                    scanf("%d", &n);
                    insertend(list1, n);
                    break;
                case 3:
                    printf("List 1 : ");
                    show(list1);
                    break;
                case 4:
                    exit(0);
                    break;
                default:
                    printf("Invalid Choice! Try Again!\n");
            }
            }
        }
        else if(ch == 2)
        {
            while(1)
            {
            printf("----list2 menu----\n");
            printf("1. Insert at beginning\n");
            printf("2. Insert at end\n");
            printf("3. Show\n");
            printf("4. Exit\n");
            printf("Enter your choice : ");
            scanf("%d", &ch);
            switch(ch)
            {
                case 1:
                    printf("Enter a value to insert at beg : ");
                    scanf("%d", &n);
                    insertbeg(list2, n);
                    break;
                case 2:
                    printf("Enter a value to insert at end : ");
                    scanf("%d", &n);
                    insertend(list2, n);
                    break;
                case 3:
                    printf("List 2 : ");
                    show(list2);
                    break;
                case 4:
                    exit(0);
                    break;
                default:
                    printf("Invalid Choice! Try Again!\n");
            }
            }
        }
        else if(ch == 3)
        {
            list3 = concat(list1, list2);
            show(list3);
        }
        else if(ch == 4)
        {
            exit(0);
        }
        else
        {
            printf("Invalid Choice Try Again!\n");
        }
    }
}