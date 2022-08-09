/*
Name : Prakhar Sharma
Branch : SE IT
Roll Num : 53
Program : Write a C program to find largest element in an array
*/

#include<stdio.h>

int main()
{
	// Declaration of Array
	int arr[100];
	int n, i, max_value;
	
	printf("Enter Size of Array : ");
	scanf("%d", &n); // Taking Input
	
	for(i = 0; i < n; i++)
	{
		printf("Enter Element A%d : ", i+1);
		scanf("%d", &arr[i]); // Taking Input for Array Elements
	}
	
	max_value = arr[0];
	
	for(i = 0; i < n; i++)
	{
		if(arr[i] > max_value)
		{
			max_value = arr[i];
		}
	}
	
	printf("The largest element in array : %d\n", max_value); // output
	
	return 0;
	
}
