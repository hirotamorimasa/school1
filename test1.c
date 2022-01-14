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

void Sum(int utr[SURGES], int ttr[SURGES], int count)
{
	int i, j;
	int o_count = 0;
	int total = 0;

	for(i = 0; i < count; i++)
		printf("%d\t", ttr[i]);
	putchar('\n');

	for(i = 1; i <= count; i++)
	{
		if(utr[i] == 42 && i < count)
		{
			o_count++;
			ttr[i-1] = Multi(ttr[i], ttr[i-1]);
			for(j = i; j <= count; j++)
			{
				ttr[j] = ttr[j + 1];
				utr[j] = utr[j + 1];
			}
		}
		if(utr[i] == 42 && i == count)
		{
			o_count++;
			ttr[i-1] = Multi(ttr[i], ttr[i-1]);
		}
	}

	for(i = 1; i <= count - o_count; i++)
	{
		printf("%d", ttr[i-1]);	
		switch(utr[i])
		{
			case 43:
				putchar('+');
				break;
			case 45:
				putchar('-');
				break;
		}
	}
	putchar('\n');
}

void keisan(int str[NUMBER], int ttr[SURGES], int utr[SURGES], int operator[OPERATOR])
{
	int ch;
	int x;
	int i = 0, j, count = 0;
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
	
	for(j = 0; j < i; j++)
		printf("%d\t", ttr[i]);
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
