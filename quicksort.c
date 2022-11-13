#include<stdio.h>
# include <stdlib.h>
//# include <conio.h>
void quicksort(int [10],int,int);

void main()
{
  int a[20],size,i;
//  clrscr();

  printf("Enter size of the array: ");
  scanf("%d",&size);

  printf("Enter %d elements: ",size);
  for(i=0;i<size;i++)
    scanf("%d",&a[i]);

  printf("\nThe elements are : ");
  for(i=0;i<size;i++)
    printf("%d  ",a[i]);

  quicksort(a,0,size-1);

  printf("\nSorted elements are: ");
  for(i=0;i<size;i++)
    printf("%d  ",a[i]);

//  getch();
}

void quicksort(int a[10],int first,int last)
{
  int pivot,j,temp,i;

  if(first<last)
  {
    pivot=first;
    i=first;
    j=last;

   while(i<j)
   {
     while(a[i]<=a[pivot]&&i<last)
      i++;
     while(a[j]>a[pivot])
      j--;
     if(i<j)
     {
       temp=a[i];
       a[i]=a[j];
       a[j]=temp;
     }
   }

   temp=a[pivot];
   a[pivot]=a[j];
   a[j]=temp;

   quicksort(a,first,j-1);
   quicksort(a,j+1,last);
  }
}