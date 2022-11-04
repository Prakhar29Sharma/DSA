#include<stdio.h>

void insertIth(int a[], int n, int i)
{
    int key = a[i];
    int j = i-1;
    while(j >= 0 && a[j] > key) {
        a[j+1] = a[j];
        j = j - 1;
    }
    a[j+1] = key;
}

void display(int a[], int n) 
{
    int i = 0;
    while(i < n)
    {
        printf("%d ", a[i]);
        i++;
    }
    printf("\n");
}

void insertSort(int a[], int n)
{
    int i = 1;
    while(i < n) 
    {
        insertIth(a, n, i);
        i++;
    }
}



int main() 
{
    int arr[] = {1,5,2,6,2,1,7};
    int size = sizeof(arr)/sizeof(int);
    printf("Before Sort : ");
    display(arr, size);
    insertSort(arr, size);
    printf("After Sort : ");
    display(arr, size);
    return 0;
}