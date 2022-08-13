#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 20


/* Stack Declaration */
char stack[size];
/* Initializing top to -1 */
int top = -1;

/* function prototype */
void push(char);
char pop();


/* main function */
int main()
{
    /* Declaration */
    char infix[25], postfix[25];
    int len, i, j;
    j = -1;

    /* Taking an infix expression as input */
    printf("Enter a Infix Expression : ");
    scanf("%s", infix);

    /* len : length of infix expression */
    len = strlen(infix);

    /* loop starts here */
    for(i = 0; i < len; i++)
    {
        if(infix[i] >=  '0' && infix[i] <= '9')
        {
            postfix[++j] = infix[i];
        } else {
            if(infix[i] == '(')
            {
                push(infix[i]);
            }
            if(infix[i] == ')')
            {
                char ch = '/';
                while(ch != '(')
                {
                    ch = pop();
                    if(ch != '(')
                    {
                        postfix[++j] = ch;
                    }
                    
                }
            }
            if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
            {
                char y;
                y = stack[top];
                if(top == -1 || y == '(' || y < infix[i])
                {
                    push(infix[i]);
                }
                if(y >= infix[i])
                {
                    postfix[j] = pop();
                    push(infix[i]);
                }
            }
        }
    }
    /* for loop end's here */

    /* popping elements till stack gets empty (top == -1)*/
    while(top != -1)
    {
        postfix[++j] = pop();
    }

    /* Displaying postfix expression */
    printf("postfix exp : %s\n", postfix);

    return 0;
}
/* main function ends here */

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