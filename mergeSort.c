#include<stdio.h>

void merge(int A[], int s, int m, int h) {
    
    int i, j, k;
    int B[100];
    
    i = s;
    j = m+1;
    k = s;
    
    while(i<=m && j<=h)
    {
        if(A[i] < A[j])
        {
            B[k] = A[i];
            i++;k++;
        } else {
            B[k] = A[j];
            j++;k++;
        }
        
    }
    
    while(i <= m)
    {
        B[k] = A[i];
        k++; i++;
    }

    while(j <= h)
    {
        B[k] = A[j];
        k++; j++;
    }


    for(int i = s; i <= h; i++)
    {
        A[i] = B[i];
    }
    
    
}

void mergeSort(int A[], int s, int h)
{
    int mid;
    if(s < h)
    {
        mid = (s+h)/2;
        mergeSort(A, s, mid);
        mergeSort(A, mid+1, h);
        merge(A, s, mid, h);

    }
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

int main()
{

    int A[] = {9,3,4,2,1,7,2,8,3};
    int size = 9;

    display(A, size);
    mergeSort(A, 0, size-1);
    display(A, size);

    return 0;
}