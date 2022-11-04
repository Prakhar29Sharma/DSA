#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 30


/* Stack Declaration */
char stack[size];
/* Initializing top to -1 */
int top = -1;

/* function prototype */
void push(char);
char pop();


/* Function Definition */

/* push() : adds an element into stack and returns nothing */
void push(char ch)
{
    if(top==size-1)
    {
        // stack overflow condition //
        printf("Stack is Full!\n");
    } else {
        stack[++top] = ch;
    }
}
/* push function ends here */


/* pop() : remove topmost element in stack and returns element */
char pop()
{
    if(top == -1)
    {
        printf("Stack is Empty!\n");
    } else {
        return stack[top--];
    }
}
/* pop function ends */

int main()
{
    char text[30], revtext[30];
    int i, len;
    printf("Enter a text : ");
    scanf("%s", text);
    len = strlen(text);

    for(i = 0; i < len; i++)
    {
        push(text[i]);
    }

    for(i = 0; i < len; i++)
    {
        revtext[i] = pop();
    }

    
    for(i = 0; i < len; i++)
    {
        if(revtext[i]!=text[i])
        {
            printf("Not a palindrome!\n");
            return 0;
        }
    }
    printf("Palindrome!\n");
}