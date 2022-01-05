//*Copyright (c) 2022 Hiromasa Morita. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int coprime(int a, int b)
{
	int i;
	int count = 0;
	if(a > b)
	{
		for(i = 2; i < b; i++)
		 {
			 if(a % i == 0 && b % i == 0)
			{
				return 1;
				count++;
			}	
		 	else if(count == 0)	return -1;
		}
	}
	else 
	{
		for(i = 2; i < a; i++)
		 {
			 if(a%i == 0 && a%i==0)
			{
				return 1;
				count++;
			}
		 	else if(count == 0)	return -1;
		}
	}
}

void coprime_print(void)
{
	int a, b;
	srand(time(NULL));
	
	a = rand() % 100 + 1;
	b = rand() % 100 + 1;
	
	printf("a=%d\tb=%d\n", a, b);
	if(coprime(a,b) == -1)
		printf("互いに素である.\n");
	else if(coprime(a,b) == 1)
		printf("互いに素ではない..\n");	

}


int main(void)
{
	coprime_print();
	return 0;
}

