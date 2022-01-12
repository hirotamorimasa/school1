//*Copyright (c) 2022 Hiromasa Morita. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARD 25
#define NUMBER 75
#define BINGO 5
#define REACH 4
#define SLANT 2  //ナナメ
#define AOU 12

int count = 0;
int b_count;

//カードの乱数
int Ransu(void)
{
	return rand() % NUMBER +1;
}

void start(int you)
{
	do
	{
		printf("1でくじをまわす：");
		scanf("%d", &you);
	}while(you != 1);
}

void Bingo_card(int bingo[CARD])
{
	int i, j;
	srand(time(NULL));
	
	for(i = 0; i < CARD; i++)
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

void Bingo_range(int bingo[CARD])
{
	int i;
	for(i = 1; i <= CARD; i++)
	{
		printf("%2d\t", bingo[i-1]);
		if(i % 5 == 0)
			putchar('\n');
	}
}

void research(int bingo[CARD], int lottery, int hit[CARD])
{
	int i;
	for(i = 0; i < CARD; i++)
	{
		if(bingo[i] == lottery)
		{
			printf("あった！\n");
			hit[count++] = lottery;
			break;
		}
	}
}

//初期化
void Init(int aou[AOU])
{
	int i;
	for(i = 0; i < AOU; i++)
		aou[i] = 0;
}

void Yoko_reach(int bingo[CARD], int hit[NUMBER], int aou[AOU])
{
	int i, j, k;
	
	j = 0;
	for(i = 1 ; i <= BINGO; i++)
	{
		for(j; j < BINGO * i; j++)
		{
			for(k = 0; k < count; k++)
			{
				if(bingo[j] == hit[k])
					aou[i-1] += 1;
			}
		}
	}
}

void Tate_reach(int bingo[CARD], int hit[NUMBER], int aou[AOU])
{
	int i, j, k;
	
	for(i = 0; i < BINGO; i++)
	{
		for(j = i; j < CARD - 4 + i; j += 5)
		{
			for(k = 0; k < count; k++)
			{
				if(hit[k] == bingo[j])
					aou[i + 5] += 1;
			}
		}
	}
}

void Right_Naname_reach(int bingo[CARD], int hit[NUMBER], int aou[AOU])
{
	int i, j;
	
	for(i = 0; i < CARD; i += 6)
	{
		for(j = 0; j < count; j++)
		{
			if(hit[j] == bingo[i])
				aou[10] += 1;
		}
	}
}
	
void Left_Naname_reach(int bingo[CARD], int hit[NUMBER], int aou[AOU])
{
	int i, j;
	
	for(i = 4; i < CARD - 4; i += 4)
	{
		for(j = 0; j < count; j++)
		 {
			if(hit[j] == bingo[i])
				aou[11] += 1;
		}
	}
}

void Reach(int bingo[CARD], int hit[NUMBER], int aou[AOU])
{
	int i, j, k;
	Init(aou);

	Yoko_reach(bingo, hit, aou);
	Tate_reach(bingo, hit, aou);
	Right_Naname_reach(bingo, hit, aou);
	Left_Naname_reach(bingo, hit, aou);
}

void Reach_print(int bingo[CARD], int hit[NUMBER], int aou[NUMBER], int r_count)
{
	int i;
	
	//AOU = 12, SLANT = 2
	for(i = 0; i < AOU - SLANT; i++)
	{
		if(aou[i] == REACH)
			r_count++;
		else if(aou[i] == BINGO)
			b_count++;
	}

	for(i = AOU - SLANT; i < AOU; i++)
	{
		if(aou[i] == REACH)
			r_count++;
		else if(aou[i] == BINGO)
			b_count++;
	}

	printf("\n%2dリーチ\t%2dビンゴ\n", r_count, b_count);
	putchar('\n');
}

void Bingo_line(int bingo[CARD], int hit[CARD])
{
	int i, j;
	int zou;	
	for(i = 0; i < CARD; i++)
	{
		for(j = 0; j < count; j++)
		{
			if(bingo[i] == hit[j])
			{
				printf("__\t");
				zou = j;
				break;
			}
		}
		if(bingo[i] != hit[zou])
			printf("%2d\t", bingo[i]);
		if((i+1) % 5 == 0)
			putchar('\n');
	}
}

void Bingo_print(int bingo[CARD], int lottery[NUMBER], int hit[CARD])

{
	int i, j;
	int you;
	int aou[AOU];
	int r_count;
	
	Init(aou);
	for(i = 0; i < NUMBER; i++)
	{
		r_count = 0;	b_count = 0;
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
		research(bingo, lottery[i], hit);
		Reach(bingo, hit, aou);
		Reach_print(bingo, hit, aou, r_count);
		Bingo_line(bingo, hit);
		putchar('\n');
		if(b_count > 0)	break;
	}
}

void Bingo_process(void)
{
	int i, j;
	int bingo[CARD], lottery[NUMBER], hit[CARD];
	int you;
	int count = 0;
	srand(time(NULL));
	
	Bingo_card(bingo);
	Bingo_range(bingo);
	Bingo_print(bingo, lottery, hit);
}

int main(void)
{
	Bingo_process();
	return 0;
}
