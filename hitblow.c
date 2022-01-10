//*Copyright (c) 2022 Hiromasa Morita. All rights reserved.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER 4 

int Ransu(void)
{
	return rand() % 9000 + 1000;
}

void Hitblow_process(void)
{
	int you, cpu, cpu1;
	int you_copy[NUMBER], cpu_copy[NUMBER];
	int i, j;
	int hit = 0, blow = 0;
	srand(time(NULL));
	
//	cpu = Ransu();
	cpu = 1112;
	cpu1 = cpu;
	
	printf("you:");	scanf("%d", &you);
	
	if(you == cpu)
	{
		printf("正解です\n");
	}
	else
	{
		for(i = 0; i < NUMBER; i++)
		{
			you_copy[i] = you % 10;
			cpu_copy[i] = cpu % 10;
			you /= 10;
			cpu /= 10;
		}
//		printf("you=%d\tcpu=%d\n", you, cpu);
		for(i = 0; i < NUMBER; i++)
		{
			//hitをカウント
			if(you_copy[i] == cpu_copy[i])
			{
				hit++;
			}
			
			for(j = 0; j < NUMBER; j++)
			{
				//blowをカウント
				if(cpu_copy[i] == you_copy[j] && i != j)
				{
					blow++;
				}
			}
		}
		printf("%d  hit\t%d  blow\n", hit, blow);
	}
	printf("cpu=%d\n", cpu1);
}
			
void Hitblow_print(void)
{
	Hitblow_process();
}

int main(void)
{
	Hitblow_print();
	return 0;
}
