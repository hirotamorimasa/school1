//*Copyright (c) 2022 Hiromasa Morita. All rights reserved. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TYPE 4
#define NUMBER 13

char *str[TYPE] = {"A", "J", "Q", "K"};
char *ttr[TYPE] = {"クローバー", "ダイア", "ハート", "スペード"};

int Ransu_1(void)
{
	return (rand() % 3);
}

int Ransu_2(void)
{
	return (rand() % 12);
}

void Judge(void)
{
	switch(Ransu_2())
	{
		case 0:		printf("%s", str[0]); break; 
		case 10:	printf("%s", str[1]); break;
		case 11:	printf("%s", str[2]); break;
		case 12:	printf("%s", str[3]); break;
		default:	printf("%d", Ransu_2()+1); break;
	}
	putchar('\n');
}

void Process(void)
{
	srand(time(NULL));
	
	switch(Ransu_1())
	{
		case 0:	printf("%s", ttr[0]);	break;	
		case 1:	printf("%s", ttr[1]);	break;
		case 2:	printf("%s", ttr[2]);	break;
		case 3:	printf("%s", ttr[3]);	break;
		default: break;
	}
	Judge();
}
	

void Trump_Print(void)
{
	Process();
}


int main(void)
{
	Trump_Print();
	return 0;
}

