//*Copyright (c) 2022 Hiromasa Morita. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER 25

int Ransu(void)
{
	return rand() % 75 +1;
}

void Bingo_process(void)
{
	int i, j;
	int bingo[NUMBER], cpu[NUMBER];
	int you;
	int count = 0;
	srand(time(NULL));
	
	for(i = 0; i < NUMBER; i++)
	{
		if(i == 0)	bingo[i] = Ransu();
		else
		{
			int same;
			do
			{
				same = -1;
				bingo[i] = Ransu();
				for(j = 0; j < i; j++)
				{
					if(bingo[i] == bingo[j])
					{
						same = 1;
					}
				}
			}while(same == 1);
		}
	}
	
	do
	{
		j = 0;
		for(i = 1; i <= NUMBER; i++)
		{
			if(cpu[i] == bingo[i])	printf("__");
			else	printf("%2d", bingo[i-1]);
			putchar('\t');
			if(i % 5 == 0)
			{
				putchar('\n');
			}
		}
		for(i = 0; i < NUMBER; i++)
		{
			do
			{
				printf("1でスタート：");
				scanf("%d", &you);
			}while(you != 1);
			if(i == 0)	cpu[i] = Ransu();
			else
			{
				int same;
			do
			{
				same = -1;
				cpu[i] = Ransu();
				for(j = 0; j < i; j++)
				{
					if(cpu[i] == cpu[j])
					{
						same = 1;
					}
				}
			}while(same == 1);
			}
			printf("%d番目：%d\n", i + 1, cpu[i]);
			if(cpu[i] == bingo[i])
			{
				printf("あった！\n");
				count++;
			}	
		}
	}while(count < NUMBER);
}

void Bingo_print(void)
{
	Bingo_process();
}

int main(void)
{
	Bingo_print();
	return 0;
}
