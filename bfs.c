#include<stdio.h>
#include<stdlib.h>

int front = -1, rear = -1;


struct node
{
    int data;
    struct node *next;
};

struct node* getnode() 
{
    return (struct node*) malloc(sizeof(struct node));
}

struct node *list = NULL;

void deleteFirstElement() 
{
    if(list == NULL)
    {
        printf("List is Empty!\n");
        return;
    }
    struct node *tmp = list;
    list = list->next;
    free(tmp);
}

int deleteLastElement()
{
    if(list == NULL)
    {
        printf("List is Empty!\n");
    }
    struct node *tmp = NULL, *prev = NULL;
    tmp = list;
    while(tmp->next!=NULL)
    {
        prev = tmp;
        tmp=tmp->next;
    }
    prev->next = NULL;
    int a = prev->data;
    free(tmp);
    return a;

}

void display()
{
    if(list == NULL)
    {
        printf("List is Empty!\n");
        return;
    } else {
        struct node *tmp = list;
        printf("List : ");
        while(tmp!=NULL)
        {
            printf("%d ", tmp->data);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

void insertAtStart(int x) 
{
    struct node *nn = NULL;
    nn = getnode();

    if(list == NULL)
    {
        nn->data = x;
        nn->next = NULL;
        list = nn;
    }
    else
    {
        nn->data = x;
        nn->next = list;
        list = nn;
    }
}

int lenghtOfList()
{
    if(list == NULL)
    {
        return 0;
    }
    struct node *t = list;
    int len = 0;
    while(t!=NULL)
    {
        len++;
        t=t->next;
    }
    return len;
}

void insertAt(int pos, int value)
{
    if(list == NULL)
    {
        int ch;
        printf("Press 1 to continue\n");
        printf("List is empty! Do you want to enter first element ? : ");
        scanf("%d", &ch);
        if(ch == 1) 
        {
            struct node *nn = getnode();
            nn->next = NULL;
            nn->data = value;   
            list = nn;
        } 
        return;
    } else {
        
        int counter = 1;
        int len = lenghtOfList();

        if(pos > len)
        {
            printf("position is greater than list length!\n");
            return;
        }
        else
        {
            struct node *temp = NULL, *prev = NULL;
            temp = list;
            while(temp->next!=NULL)
            {
                prev = temp;
                temp=temp->next;
                counter++;
                if(counter == pos)
                {
                    struct node *nn = getnode();
                    nn->data = value;
                    nn->next = temp;
                    prev->next = nn;
                    break;
                }
            }

            if(counter < pos)
            {
                printf("There're less element!\n");
            }
        }

    }
}

void deleteAt(int pos)
{
    if(list == NULL)
    {
        printf("List is empty!\n");
        return;
    } else {
        if(pos == 1)
        {
            deleteFirstElement();
            return;
        } 
        if(pos == lenghtOfList())
        {
            deleteLastElement();
            return;
        }
        struct node *temp = NULL, *prev = NULL;
        temp = list;
        int counter = 1;
        while(temp->next!=NULL)
        {
            counter++;
            prev = temp;
            temp = temp->next;
            if(counter == pos)
            {
                prev->next = temp->next;
            }
            
        }

        if(counter < pos)
        {
            printf("There're less element in list!\n");
        }
    }
}

void insertAtEnd(int x) 
{
    struct node *nn = NULL;
    nn = getnode();
    nn->data = x;
    nn->next = NULL;
    if(list == NULL)
    {
        int ch;
        printf("Press 1 to continue\n");
        printf("List is empty! Do you want to enter first element ? : ");
        scanf("%d", &ch);
        if(ch == 1) 
        {
            
            list = nn;
        } 
        return;
    }
    else 
    {
        struct node *tmp = NULL;
        tmp = list;
        while(tmp->next!=NULL)
        {
            tmp=tmp->next;
        }
        tmp->next = nn;
    }
}



void enqueue(int value)
{
    if(front == -1 && rear == -1)
    {
        front++;
        rear++;
        insertAtStart(value);
    }
    else
    {
        rear++;
        insertAtStart(value);  
    }
}

int dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("list is empty!");
    }
    else if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
        return deleteLastElement();
    }
    
}

int isEmpty()
{
    if(front == -1 && rear == -1)
    {
        return 0;
    } else {
        return 1;
    }
}

int main()
{
    int node;
    int i = 0;
    int visited[7] = {0,0,0,0,0,0,0};
    
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };

    printf("%d", i);
    visited[i] = 1;
    enqueue(i); // for exploration
    while(isEmpty() == 1)
    {
        node = dequeue();
        for(int j = 0; j < 7; j++)
        {
            if(a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }


    return 0;
}