/* header files */
#include<stdio.h>
#include<stdlib.h>

/* defining 5 as size */
#define size 5

/* Declaration and Initialization of Queue*/
int queue[size];
/* Initialization condition */
int f = -1;
int r = -1;

/* function prototypes */
void enqueue(int);
void dequeue();
void show();
void isEmpty();

/* main functions */
int main()
{
	/* Declaration of variables */
	int ch, n;

    /* while loop */
    while(1)
    {
        printf("\n----Queue_Menu-----");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.isEmpty");
        printf("\n4.Show");
        printf("\n5.Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        /* switch case starts here */
        switch(ch)
        {
            case 1:
            	printf("Enter a integer : ");
            	scanf("%d", &n);
                enqueue(n);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                isEmpty();
                break;
            case 4:
                show();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nInvalid Choice!");
        }   /* switch case ends here */
    }   /* while loop ends here */
} /* main function ends here */

/* enqueue(int) -> adds element into queue */
void enqueue(int x)
{
	// Adding First Element of Queue //
    if(f == -1 && r == -1)
    {
        f++;
        queue[++r] = x;
    } else {
    	// Other Element //
        if(f == (r++)%size)
        {
            printf("\nqueue overflow!");
        } else {
        	r = (r++)%size;
            queue[r] = x;
        }
    }
}
/* enqueue() ends here */

/* dequeue() -> removes an element from front */
void dequeue()
{
	// Empty Queue Condition //
	if(r == -1 && f == -1)
    {
    	printf("\nQueue is Empty!");
	} 
	// One Element Condition //
    else if(r == f)
    {
        f = -1;
        r = -1;
    } 
    // Other Element //
	else {
        f = (f++)%size;
    }
    
} 
/* dequeue() ends here */

/* isEmpty() -> checks if the queue is empty or not */
void isEmpty()
{
    if(f == -1 && r == -1)
    {
        printf("\nQueue is Empty!");
    } else {
        printf("\nQueue is Not Empty!");
    }
}
/* isEmpty() ends here */

/* show() -> displays queue */
void show()
{
    int i, j;
    /* empty condition */
    if(f == -1 && r == -1)
    {
        printf("\nQueue is Empty!");
    } else {
        for(i = f; i <= size; i++)
        {
        	j = i%size;
        	/* display front and rear pointers */
        	if(r == f)
        	{
        		printf("\n%d <- front & rear", queue[j]);
			}
        	else if(i == f)
        	{
        		printf("\n%d <- front",queue[j]);
			}
			else if(i == r)
			{
				printf("\n%d <- rear ",queue[j]);
			} 
			else
			{
            	printf("\n%d", queue[j]);
        	}
        }
    }
}
/* show() ends here */
