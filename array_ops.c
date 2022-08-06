/* including rewuired header files */

#include<stdio.h>
#include<stdlib.h>

/* compare() : compares two array and return 1 if they are same otherwise 0 */
int compare(int *arr1, int *arr2)
{
    // for loop starts //
    for(int i = 0; i < 5; i++)
    {
        if(arr1[i] != arr2[i])
        {
            return 0;
        }
    } // for loop ends //
    return 1;
}

/* main */
int main()
{
    // Declaration and Init. of Array //
    int arr1[5] = {1,2,3,7,5}; 
    int arr2[5] = {1,2,3,7,5};

    // Displaying Output //
    printf("%d", compare(arr1, arr2))
    
    return 0;
} // main function ends //