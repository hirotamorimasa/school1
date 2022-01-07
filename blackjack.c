//*Copyright (c) 2022 Hiromasa Morita. All rights reserved.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define TYPE 4
#define NUMBER 52
#define SUM 20


char *str[TYPE] = {"A", "J", "Q", "K"};
char *ttr[TYPE] = {"クローバー", "ダイア", "ハート", "クローバー"};


int Ransu_1(void)
{
	return (rand() % 3);
}

int Ransu_2(void)
{
	return (rand() % 11);
}

void Blackjack_print(int ransu1 , int ransu2, int you)
{
	switch(ransu1)
	{
		case 0: printf("%s", ttr[0]); break;
		case 1: printf("%s", ttr[1]); break;
		case 2: printf("%s", ttr[2]); break;
		case 3: printf("%s", ttr[3]); break;
		default: break;
	}
	switch(ransu2)
	{
		case 0: printf("%s", str[0]); break;
		case 10: printf("%s", str[1]); break;
		case 11: printf("%s", str[2]); break;
		case 12: printf("%s", str[3]); break;
		default: printf("%d", ransu2+1);
	}
	putchar('\n');
	printf("sum=%d\n", you);
}

void Result(int you, int cpu)
{
	printf("\nyou:%d\tcpu:%d\n", you, cpu);
	if(you < cpu && cpu <= SUM)
	{
		printf("私の勝ちです\n");
	}
	else if(you > cpu && you <= SUM)
	{
		printf("あなたの勝ちです\n");
	}
	else if(you == cpu && you <= SUM)
	{
		printf("引き分けです\n");
	}
	else if(you < cpu && cpu > SUM)
	{
		printf("あなたの勝ちです\n");
	}
	else if(you > cpu && cpu > SUM)
	{
		printf("あなたの負けです\n");
	}
}

void you_Judge(int point)
{
	printf("あなたが%dで%dを越えたのであなたの負けです\n", point, SUM);
}

void cpu_Judge(int point)
{	
	printf("私が%dで%dを越えたのであなたの勝ちです\n", point, SUM);
}

void Blackjack_process(void)
{
	int you = 0, cpu = 0;  //プレイヤー、コンピュータ
	int count = 0;		//偶奇のカウント
	int i = 0, j;		//カウント変数
	int card_t[NUMBER];	//カードの種類
	int card_n[NUMBER];	//カードの番号
	int retry = 0;	//同じカードが出ないように繰り返す
	int turn = 0;  //先行後攻の順番
	int keepon_you = 1, keepon_cpu = 1;	//続けるか
	srand(time(NULL));

	printf("先行..1/後攻..2:");
	scanf("%d", &turn);
	
	while(1)
	{
		if(keepon_you == 1 || keepon_cpu == 1){ 
		do
		{
			retry = 0;
			card_t[count] = Ransu_1();
			card_n[count] = Ransu_2();
			for(j = 0; j < count; j++)
			{
				if(card_t[count] == card_t[j] && card_n[count] == card_n[j])
				{
					retry = -1;
				}
			}
			count++;
		}while(retry == -1);
	
		//プレイヤーが先行のとき
		if(turn == 1 && i % 2 == 0 && keepon_you == 1)
		{
			printf("you:\t");
			you += (card_n[i] + 1);	
			Blackjack_print(card_t[i], card_n[i], you);

			printf("続けますか..1/いいえ..-1:");
			scanf("%d", &keepon_you);
		}
		else if(turn == 1 && i % 2 == 1 && keepon_cpu == 1)
		{
			cpu += (card_n[i] + 1);
			if(cpu >= 15)
			{
				keepon_cpu = -1;
				printf("cpu: pass\n");
			}
		}

		//プレイヤーが後攻のとき
		else if(turn == 2 && i % 2 == 1 && keepon_you == 1)
		{
			printf("you:\t");
			you += (card_n[i] + 1);
			Blackjack_print(card_t[i], card_n[i], you);

			//続けるか否か
			printf("続けますか..1/いいえ..-1:");
			scanf("%d", &keepon_you);
		}
		else if(turn == 2 && i % 2 == 0 && keepon_cpu == 1)
		{
			cpu += (card_n[i] + 1);
			if(cpu >= 15)
			{
				keepon_cpu = -1;
				printf("cpu: pass\n");
			}
		}
		
		if(you > SUM + 1)
		{
			you_Judge(you);
			break;
		}
		else if(cpu  > SUM + 1)
		{
			cpu_Judge(cpu);
			break;
		}
		
		i++;
		}
		
		if(cpu >= 15 && keepon_cpu == -1 && keepon_you == -1)
		{
			
			break;
		}
	}
	Result(you, cpu);
}

void Blackjack(void)
{
	Blackjack_process();
}

int main(void)
{
	Blackjack();
	return 0;
}

