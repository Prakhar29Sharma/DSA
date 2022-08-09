/* Problem Statement : WAP to take Students Roll Number and their marks and sort them into descending order using 2 D Array */
#include<stdio.h>

/* main function starts here */
int main()
{
    // Declaration //
    int data[2][10];
    int i, j, temp;

    /* for loop starts here */
    for(j = 0; j < 10; i++, j++)
    {
        // Taking Roll Number and Marks (Input)//
        printf("Enter Student Roll Number and Marks : ");
        scanf("%d %d", &data[0][j], &data[1][j]);
    }
    /* for loop ends here */

    /* for loop starts here */
    for(i = 0; i < 9; i++)
    {
        for(j = i+1; j < 10; j++)
        {
            // sorting //
            if(data[1][i] < data[1][j])
            {

                data[1][i] = data[1][i] + data[1][j];
                data[1][j] = data[1][i] - data[1][j];
                data[1][i] = data[1][i] - data[1][j];

                data[0][i] = data[0][i] + data[0][j];
                data[0][j] = data[0][i] - data[0][j];
                data[0][i] = data[0][i] - data[0][j];

            }
        }
    }
    /*for loop ends here*/

    printf("Sorted Data : \n");

    printf("\n------------------------------\n");

    // for loop starts here //
    for(j = 0; j < 10; j++)
    {
        // output //
        printf("Roll No : %d, Marks : %d\n", data[0][j], data[1][j]);
    }
    // for loop ends //

    printf("\n------------------------------\n");

    return 0;
}
/* main functions ends here */