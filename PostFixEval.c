#include<stdio.h>
#include<stdlib.h>
#define size 20

int stack[size];
int j = -1;

void push(int);
int pop();
void show();
void isEmpty();
int eval(char exp[]);

int main()
{
    char exp[] = "231*+9-";
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

void show()
{
	int i;
    for(i = size-1; i >= 0 ; i--)
    {
        printf("\n%d", stack[i]);
    }
    return;
}

void isEmpty()
{
    if (j == -1)
    {
        printf("\nStack is Empty!");
    } else {
        printf("\nStack is not Empty!");
    }
}
