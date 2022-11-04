#include<stdio.h>

// displays array 
void displayArray(int *arr) {
	int i;
	for(i = 0; i<5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// main function 
int main() {
	
	// array declaration and defination
	int arr[] = {1,5,2,3,4};
	// variables
	int len, i, j;
	// calculating array lenght
	len = sizeof(arr)/sizeof(arr[0]);
	
	// displaying array before sorting
	printf("Array before sorting : ");
	displayArray(arr);
	
	// selection sorting
	for(i = 0; i<len-1; i++) {
		for(j = i+1; j < len; j++) {
			// condition for swap
			if(arr[j] < arr[i]) {
				// swap without using extra variable
				arr[j] = arr[i] + arr[j];
				arr[i] = arr[j] - arr[i];
				arr[j] = arr[j] - arr[i];
			}
		}
	}
	
	// displaying array after sorting
	printf("Array after sorting : ");
	displayArray(arr);
	
	return 0;
}