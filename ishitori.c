//*Copyright (c) 2022 Hiromasa Morita. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER 15

int Ransu(void)
{
	return (rand() % 3 + 1);
}

void LEVEL(int *level)
{
	int you, cpu;
	int sum = NUMBER;
	int count = 0;
	while(sum > 0)
	{
		if(sum == 1)
		{
			printf("あなたの負けです\n");
			break;
		}
		do
		{
			printf("you:"); scanf("%d", &you);
			if(sum - you > 0)
			{
				sum -= you;
				count++;
			}
		}while(count == 0 && (you < 0 || you > 3));
		printf("sum=%d\n", sum);
		if(sum == 1)
		{
			printf("あなたの勝ちです\n");
			break;
		}
		do
		{
			if(*level == 1 && (sum > 1 && sum < 4))
			 {
				 switch(sum)
				{
					case 2: cpu = 1;
						break;
					case 3: cpu = 2;
						break;
				}
			}
			else if(*level == 2 && (sum > 1 && sum < 5))
			 {
				 switch(sum)
				 {
					 case 2: cpu = 1;
					 	 break;
					 case 3: cpu = 2;
					 	 break;
					 case 4: cpu = 3;
					 	break;
					 default: break;
				}
			}	
			else	 cpu = Ransu();
	
			if(sum - cpu > 0)
			{
				sum -= cpu;
				count++;
			}
		}while(count == 0);
		count = 0;
		printf("cpu:%d\nsum=%d\n", cpu, sum);
	}
	putchar('\n');
}

void Process(void)
{
	int level;
	srand(time(NULL));
	printf("LEVEL0~2:");	scanf("%d", &level);
	
	printf("start=%d\n", NUMBER);
	switch(level)
	{
		case 0:	LEVEL(&level); break;
		case 1: LEVEL(&level); break;
		case 2: LEVEL(&level); break; 
		default: break;
	}

}

void Game_Print(void)
{
	Process();
}

int main(void)
{
	Game_Print();
	return 0;
}
