/* including header files */
#include<stdio.h>


// compare(array1, array2) : compare two arrays and returns 0 if they are identical otherwise 1 // 
int compare(int arr1[], int arr2[])
{
	int i, len, isIdentical;
	
	isIdentical = 0;
	// len : length of array //
	
	// checking if length of both arrays are same or not //
	// if lenght of both array is not same then they are not identical //
	if((sizeof(arr1)/sizeof(arr1[0])) != (sizeof(arr2)/sizeof(arr2[0])))
	{
		return 1;
	}
	
	len = sizeof(arr1)/sizeof(arr1[0]);
	
	/* for loop starts */
	for(i = 0; i < len; i++)
	{
		if(arr1[i] != arr2[i])
		{
			isIdentical = 1;
			break;
		}
	}
	/* for loop ends */
	
	return isIdentical;
}

/* main */
int main()
{
	// Declaration of arrays // 
	int arr1[5] = {1,2,3,4,5};
	int arr2[5] = {1,2,3,4,5};
	int arr3[5] = {6,7,8,9,2};
	
	int identical;
	
	// calling compare method, passing two args and storing returned value in a variable // 
	identical = compare(arr1, arr3); 
	
	// if condition //
	if(identical == 1)
	{
		printf("Not Identical!\n");
	} 
	else
	{
		printf("Identical!\n");
	}
	
	return 0;
	
}
/* main block ends*/
