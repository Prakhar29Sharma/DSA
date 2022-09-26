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

struct node *list = NULL;

void insert(int x)
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
        nn->info = x;
        nn->next = NULL;
        temp = list;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
}

void show()
{
    if(list == NULL)
    {
        printf("List is Empty!\n");
        return;
    }
    struct node *temp;
    temp = list;
    while(temp!=NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

void reverse()
{
    struct node* prev = NULL;
    struct node* current = list;
    struct node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;
 
        // Reverse current node's pointer
        current->next = prev;
 
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    list = prev;
}

int main()
{
    int ch, n;
    
    while(1){
    printf("----Menu----\n");
    printf("1. Insert Element\n");
    printf("2. Show Element\n");
    printf("3. Reverse List\n");
    printf("4. Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1:
            printf("Enter a value to insert : ");
            scanf("%d", &n);
            insert(n);
            break;
        case 2:
            show();
            break;
        case 3:
            reverse();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid Choice! Try Again!\n");
    }
    }
    return 0;
    
}
