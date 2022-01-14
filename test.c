#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUMBER 6
#define SURGES 25
#define OPERATOR 5

int Plus(int y, int x)
{
	return (y += x);
}

int Minus(int y, int x)
{
	return (y -= x);
}

int Multi(int y, int x)
{
	return (y *= x);
}

int Squre(int x, int count)
{
	int i;
	int squre = 1;
	for(i = 1; i < count; i++)
		squre *= 10;
	return (x * squre);
}

int Trans(int str[NUMBER], int count)
{
	int i;
	int total = 0;
	
	for(i = 0; i < count; i++)
	{
		total += Squre(str[i], count - i);
	}
	return total;
}

void Operator(int operator[OPERATOR])
{
	int i = 0;
	operator[i++] = 42;  // *
	operator[i++] = 43;  // +
	operator[i++] = 45;  // -
	operator[i++] = 47;  // /
	operator[i++] = 61;  // =
}

void Sum(int operator[SURGES], int x[SURGES], int count)
{
	int i, j;
	int o_count = 0;
	int total = 0;

	//加減
	for(i = 1; i <= count; i++)
	{
		
		if(operator[i] == 43)
		{
			if(i == 1)
				total = Plus(x[i], x[i-1]);
			else
				total += x[i];
		}
		else if(operator[i] == 45)
		{
			if(i == 1)
				total = Minus(x[i], x[i-1]);
			else
				total -= x[i];
		}
		else if(operator[i] == 61)
		{
			printf("total=%d\n", total);
			break;
		}
	}
}

void Keisan(int str[NUMBER], int ttr[SURGES], int utr[SURGES], int operator[OPERATOR])
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
			default: break;
		}

		if(ch == operator[4])
		{
			utr[++i] = operator[4];
			Sum(utr, ttr, i);
			break;
		}
	}
/*	for(int j = 0; j < i; j++)
		printf("ttr[%d]=%d\t", j, ttr[j]);
*/
	printf("\nch=%d\ti=%d\n", operator[2], i);

}

void Keisan_print(void)
{
	int str[NUMBER];   //読み込み数値の変換用
	int ttr[SURGES], utr[SURGES]; //オペランド、演算子保存用
	int operator[OPERATOR];
	Keisan(str, ttr, utr, operator);
}

int main(void)
{
	Keisan_print();
	return 0;
}
