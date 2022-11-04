#include<stdio.h>

int swap(int a[], int x, int y)
{
    a[x] = a[x] + a[y];
    a[y] = a[x] - a[y];
    a[x] = a[x] - a[y];
}

void bubble(int a[], int n) 
{
    int i = n-1;
    while(i > 0) 
    {
        if(a[i] < a[i-1]) 
        {
            swap(a, i, i-1);
        }
        i--;
    }

}

void bubbleSort(int a[], int n) 
{
    int i = 0; 
    while(i < n-1) 
    {
        bubble(a, n);
        i++;
    }
}

void display(int a[], int size) 
{
    int i = 0;
    while(i < size) 
    {
        printf("%d ", a[i]);
        i++;
    }
    printf("\n");
}

int main()
{
    int arr[] = {1,5,2,6,2,1,7};
    int size = sizeof(arr)/sizeof(int);
    printf("Before Sort : ");
    display(arr, size);
    bubbleSort(arr, size);
    printf("After Sort : ");
    display(arr, size);
    return 0;
}