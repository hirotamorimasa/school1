#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER 6
#define SURGES 25
#define OPERATOR 5

int Multi(int y, int x)
{
	return (y *= x);
} 

int Squre(int x, int count)
{
	int i; 
	int squre = 1;
	
	for(i = 1; i < count; i++)
		squre += 10;
	return (x * squre);
}

int Trans(int str[NUMBER], int count)
{
	int i;
	int total = 0; 

	for(i = 0; i < count; i++)
			total += Squre(str[i], count - 1);
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

void Sum(int operator[SURGES], int x[SURGES], int count)
{
	int i, j;
	int o_count = 0;
	int total = 0;

	for(i = 1; i <= count; i++)
	{
		if(operator[i] == 42 && i < count)
		{
			o_count++;
			x[i-1] = Multi(x[i], x[i-1]);
			for(j = i; j <= count; j++)
			{
				x[j] = x[j + 1];
				operator[j] = operator[j + 1];
			}
		}
		if(operator[i] == 42 && i == count)
		{
			o_count++;
			x[i-1] = Multi(x[i], x[i-1]);
		}
	}

	for(i = 1; i <= count - o_count; i++)
	{
		printf("%d", x[i-1]);
		
		printf("%d", operator[1]);
	}
}

void keisan(int str[NUMBER], int ttr[SURGES], int utr[SURGES], int operator[OPERATOR])
{
	int ch;
	int x;
	int i = 0, count = 0;
	FILE *fp;
	char fname[] = "test.txt";

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
	printf("\ni=%d\n", i);
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
