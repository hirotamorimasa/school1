#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER 20 

int Ransu(int max)
{
	return rand() % max + 1;
}

void Process(void)
{
	int i;
	int you, cpu[NUMBER];
	int reply = 0;
	int max = 100, min = 0;
	srand(time(NULL));

	do
	{
		printf("you:");	
		scanf("%d", &you);
	}while(you < 1 || you > 100); 
	
	cpu[0] = Ransu(max);
	for(i = 1; i < NUMBER; i++)
	{
		if(you != cpu[i-1])
		{
			printf("%dですか:", cpu[i-1]);
			scanf("%d", &reply);
		}

		if(reply == -1)
		{
			max = cpu[i-1];
			do
			{
				cpu[i] = Ransu(max);
			}while(cpu[i] < min+1 || max-1 < cpu[i]); 
		}
		else if(reply == 1)
		{
			min = cpu[i-1];
			do
			{
				cpu[i] = Ransu(max);
			}while(cpu[i] < min+1  || max-1 < cpu[i]);
		}
		
		if(i >= NUMBER)
		{
			printf("正解は%dです\n", you);
		}
		else if(you == cpu[i])
		{
			printf("%dですね\n", cpu[i]);
		}
	}
}

void Number_Print(void)
{
	Process();
}

int main(void)
{
	Number_Print();
	return 0;
}
