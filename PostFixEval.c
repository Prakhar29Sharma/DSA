#include<stdio.h>
#include<stdlib.h>
#define size 20

int stack[size];
int j = -1;

void push(int);
int pop();
int eval(char exp[]);

int main()
{
    char exp[100];
    printf("Enter a PostFix Expression : ");
    scanf("%s", exp);
    int result;
    result = eval(exp);
    printf("result : %d\n", result);
    return 0;
}

int eval(char *exp)
{
    int len, i;

    len = 0;

    for(i = 0; exp[i] != '\0'; i++)
    {
        len+=1;
    }

    for(i = 0; i < len; i++)
    {
        if(exp[i] >='0' && exp[i] <= '9')
        {
            int value;
            value = exp[i] - '0';
            // printf("value : %d\n", value);
            push(value);
        } else {
            int val1, val2;
            val1 = pop();
            val2 = pop();

            switch(exp[i])
            {
                case '+':
                    push(val2 + val1);break;
                case '-':
                    push(val2 - val1);break;
                case '*':
                    push(val2 * val1);break;
                case '/':
                    push(val2 / val1);break;
                case '%':
                    push(val2 / val1);break;
            }
        }
    }

    return pop();

}

void push(int n)
{
    if (j == size-1)
    {
        printf("\nstack is full!");
    } else {
        j++;
        stack[j] = n;
    }
    return;
}

int pop()
{
    if(j == -1)
    {
        printf("\nStack is Empty!");
    }
    else
    {
        return stack[j--];
    }
}

