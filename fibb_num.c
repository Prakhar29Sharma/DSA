/*
Name : Prakhar Sharma
Branch : SE IT
Roll Num : 53
Program : Write a C program to check if a given number is Fibonacci number
*/

#include<stdio.h> 

int main()
{
	int n, t1, t2, nt; //Declaration of variables
	
	t1 = 0; // assigning values
	t2 = 1;
	
	printf("Enter the Number : ");
	scanf("%d", &n); //taking user input
	
	if(n == 0 || n == 1)
	{
		printf("Fibonacci Number!\n"); 
		return 0;
	} else {
		while(1) // while(true)
		{
			nt = t1 + t2; // calc of next term
			
			if(nt == n) // checking condition
			{
				printf("Fibonacci Number!\n"); //output statement
				return 0;
			}
			else if(nt > n) // loop breaking condition
			{
				break;
			}
			else
			{
				t1 = t2;
				t2 = nt;
			} 
		}
		
		printf("Not a Fibonacci Number!\n"); // output statement
		return 0;
	}
	
	
}
