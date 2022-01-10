//*Copyright (c) 2022 Hiromasa Morita. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER 25
#define BINGO 75


//カードの乱数
int Ransu(void)
{
	return rand() % BINGO +1;
}

void start(int you)
{
	do
	{
		printf("1でスタート：");
		scanf("%d", &you);
	}while(you != 1);
}

void Bingo_card(int bingo[NUMBER])
{
	int i, j;
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
}

void Bingo_range(int bingo[NUMBER])
{
	int i;
	for(i = 1; i <= NUMBER; i++)
	{
		printf("%2d\t", bingo[i-1]);
		if(i % 5 == 0)
			putchar('\n');
	}
}

//同番を探す
void research(int bingo[NUMBER],int lottery)
{
	int i;
	for(i = 0; i < NUMBER; i++)
	{
		if(bingo[i] == lottery)
		{
			printf("あった！\n");
			break;
		}
	}

}

void Bingo_line(int bingo[NUMBER], int lottery[BINGO])
{
	int i, j;
	for(i = 0; i < NUMBER; i++)
	{
		for(j = 0; j <= i; j++)
		{
			if(bingo[i] == lottery[j])
			{
				printf("__\t");
				break;
			}
			else 
			{
				printf("%2d\t", bingo[i]);
				break;
			}
		}
		if((i+1) % 5 == 0)
			putchar('\n');
	}
}

void Bingo_print(int bingo[NUMBER], int lottery[BINGO])
{
	int i, j;
	int you;
	for(i = 0; i < BINGO; i++)
	{
		start(you);
		if(i == 0)	lottery[i] = Ransu();
		else
		{
			int same;
			do
			{
				same = -1;
				lottery[i] = Ransu();
				for(j = 0; j < i; j++)
				{
					if(lottery[j] == lottery[i])
						same = 1;
				}
			}while(same == 1);
		}
		printf("%d番目：%d\n", i + 1, lottery[i]);
		research(bingo, lottery[i]);
		Bingo_line(bingo, lottery);
		putchar('\n');
	}
}

void Bingo_process(void)
{
	int i, j;
	int bingo[NUMBER], lottery[BINGO];
	int you;
	int count = 0;
	srand(time(NULL));
	
	Bingo_card(bingo);
	Bingo_range(bingo);

	Bingo_print(bingo, lottery);
}

int main(void)
{
	Bingo_process();
	return 0;
}
