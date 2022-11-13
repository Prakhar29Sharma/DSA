/* including header files */
#include<stdio.h>
#include<stdlib.h>

/* struct declaration */
struct time_struct
{
	int hour;
	int minute;
	int second;
};

struct time_struct time;

// setTime(hour, minutes, seconds) : sets time //
void setTime(int h, int m, int s)
{
	time.hour = h;
	time.minute = m;
	time.second = s;
	return;
}

// displayTime() : displays time //
void displayTime()
{
	printf("%d:%d:%d\n", time.hour, time.minute, time.second);
	return;
}

// updateTime() : updates time by 1 second every time called //
void updateTime()
{
	time.second += 1;
	
	if(time.second == 60)
	{
		time.second = 0;
		time.minute += 1;
		
		if(time.minute == 60)
		{
			time.minute = 0;
			time.hour += 1;
			
			if(time.hour == 24)
			{
				time.hour = 0;
			}
			
		}
		
	}
	return;
}

/* main */
int main() 
{
	int ch, h, m, s;
	
	/* while loop start */
	while(1)
	{
		printf("Menu : \n");
		printf("1. setTime\n2. displayTime\n3. updateTime\n4. Exit\n");
		printf("Enter your choice : ");
		scanf("%d", &ch);
		
		updateTime();
		
		/* switch start*/
		switch(ch)
		{
			case 1:
				printf("Enter hour, min and sec value : ");
				scanf("%d %d %d", &h, &m, &s);
				setTime(h, m, s);
				break;
			case 2:
				displayTime();
				break;
			case 3:
				updateTime();
				break;
			case 4:
				exit(0);break;
			default:
				printf("Invalid Choice!\n");
		}
		/* switch end */
	} 
	/* while loop end */
}
/* main function block end*/
