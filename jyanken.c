//*Copyright (c) 2022 Hiromasa Morita. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER 3

char *str[NUMBER] = {"グー", "チョキ", "パー"};

int Ransu(void)
{
	return (rand() % 2);
}
	
void jyanken_print(void)
{
	int you, cpu;
	int result;

	do
	{
		printf("0グー..1チョキ..2パー:");
		scanf("%d", &you);
	}while(you < 0 || you > 2);
	
	cpu = Ransu();
	result = (you - cpu + 3) % 3;
	printf("cpu=%d\tyou=%d\n", cpu, you);
	switch(result)
	{
		case 2 :
			printf("私は%sなので貴方の勝ちです\n", str[cpu]);
			break;
		case 1:
			printf("私は%sなので貴方負けです\n", str[cpu]);
			break;
		case 0:
			printf("私は%sなので引き分けです\n", str[cpu]);
			break;
		default: break;
	}

}

int main(void)
{
	jyanken_print();
	return 0;
}
