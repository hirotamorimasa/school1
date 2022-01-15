//*Copyright (c) 2022 Hiromasa Morita. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


#define NUMBER 6
#define SURGES 25
#define OPERATOR 5


int Plus(int y, int x)
{
	return (y + x);
}

int Minus(int y, int x)
{
	return (y - x);
}

int Multi(int y, int x)
{
	return (y * x);
} 

int Divis(int y, int x)
{
	if(x == 0) 
		x = 1;
	else if(y == 0) 
		return x;
	return (y / x);
}

int Squre(int x, int count)
{
	int squre = 1;
	
	for(int i = 1; i < count; i++)
		squre *= 10;
	return (x * squre);
}

int Trans(int str[NUMBER], int count)
{
	int total = 0; 

	for(int i = 0; i < count; i++)
		total += Squre(str[i], count - i);
	return total;
}

void Operator(int operator[OPERATOR])
{
	int i = 0;
	operator[i++] = 42;
	operator[i++] = 43;
	operator[i++] = 45;
	operator[i++] = 47;
	operator[i++] = 61;
}

void Sum(int utr[SURGES], int x[SURGES], int count)
{
	int i, j;
	int o_count = 0;
	int total = 0;

/*	for(i = 1; i <= count; i++)
		printf("%d\t\b", x[i-1]);
	putchar('\n');
*/
		CONTINUE:
		for(i = 1; i <= count; i++)
		{
			if(utr[i] == 42 && i < count)
			{
				o_count++;
				x[i-1] = Multi(x[i-1], x[i]);
				for(j = i; j <= count; j++)
				{
					x[j] = x[j + 1];
					utr[j] = utr[j + 1];
				}
				goto CONTINUE;
			}
/*			else if(utr[i] == 47 && i < count)
			{
				o_count++;
				x[i-1] = Divis(x[i-1], x[i]);
				for(j = i; j <= count; j++)
				{
					x[j] = x[j + 1];
					utr[j] = utr[j + 1];
				}
				goto CONTINUE;
			}
*/

			if(utr[i] == 42 && i == count)
			{
				o_count++;
				x[i-1] = Multi(x[i-1], x[i]);
				goto CONTINUE;
			}
/*			else if(utr[i] == 47)
			{
				o_count++;
				x[i-1] = Divis(x[i], x[i-1]);
				goto CONTINUE;
			}
*/		}

/*	for(i = 1; i <= count - o_count; i++)
	{
		printf("%d ", x[i-1]);
		printf("%d ", utr[i]);
	}
	putchar('\n');
*/

	for(i = 1; i <= count - o_count; i++)
	{
//		printf("total=%d\n", total);
		if(utr[i] == 43)
		{
			if(i == 1)
				total = Plus(x[i-1], x[i]);
			else
				total += x[i];
		}
		else if(utr[i] == 45)
		{
			if(i == 1)
				total = Minus(x[i-1], x[i]);
			else
				total -= x[i];
		}
		else if(utr[i] == 61)
		{
			printf("total=%d\n", total);
			break;
		}
	}
}

void keisan(int str[NUMBER], int ttr[SURGES], int utr[SURGES], int operator[OPERATOR])
{
	int ch;
	int x;
	int i = 0, count = 0;
	FILE *fp;
	char fname[] = "test1.txt";

	Operator(operator);

	fp = fopen(fname, "r");
	if(fp == NULL)
	{
		printf("%s file don't open.\n", fname);
	}

	fp = fopen(fname, "r");
	while((ch = fgetc(fp)) != EOF)
	{
		if(ch >= 48 && ch <= 57)
		{
			str[count] = (ch - 48);
			count++;
			ttr[i] = Trans(str, count);
		}
		switch(ch)
		{
			case 42:
				utr[++i] = operator[0];
				count = 0;
				break;
			case 43:
				utr[++i] = operator[1];
				count = 0;
				break;
			case 45:
				utr[++i] = operator[2];
				count = 0;
				break;
			default:
				break;
		}
		
		if(ch == operator[4])
		{
			utr[++i] = operator[4];
			Sum(utr, ttr, i);
			break;
		}
	}
	
}

void Keisan_print(void)
{
	int str[NUMBER];
	int ttr[SURGES], utr[SURGES];
	int operator[OPERATOR];
	keisan(str, ttr, utr, operator);
}

int main(void)
{
	Keisan_print();
	return 0;
}
