/*
Name : Prakhar Sharma
Branch : SE IT
Roll Num : 53
Program : Write a C program to roll_no, name , percentange of 5 students using array of structure and
display the records in descending order of percentange.
*/

#include<stdio.h>

struct Student 
{
	int roll_no;
	char name[50];
	float percentage;
};

int main()
{
	struct Student s[5];
	struct Student temp;
	int i, j; 
	
	//Taking Data Input from user
	for(i = 0; i < 5; i++)
	{
		printf("Enter Student%d Roll Number : ", i+1);
		scanf("%d", &s[i].roll_no);
		printf("Enter Student%d Name : ", i+1);
		scanf("%s", s[i].name);
		printf("Enter Student%d Percentage : ", i+1);
		scanf("%f", &s[i].percentage);
	}
	
	// Sorting data in decreasing order of percentage
	for(i = 0; i < 4; i++)
	{
		for(j = i+1; j < 5; j++)
		{
			if(s[j].percentage > s[i].percentage) // sorting condition
			{
				// swap
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
		}
	}	
	
	// displaying sorted data as output
	printf("------------------------------------------\n");
	for(i = 0; i < 5; i++)
	{
		printf("Roll Number : %d\n", s[i].roll_no);
		printf("Name : %s\n", s[i].name);
		printf("Percentage : %f\n", s[i].percentage);
		printf("------------------------------------------\n");
	}
	
	return 0;
}
