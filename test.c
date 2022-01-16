//*Copyright (c) 2022 Hiromasa Morita. All rights reserved.


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


#define NUMBER 6
#define SURGES 25
#define OPERATOR 5
#define PI 3.1415926


double Plus(double y, double x)
{
	return (y + x);
}

double Minus(double y, double x)
{
	return (y - x);
}

double Multi(double y, double x)
{
	return (y * x);
}

double Divis(double y, double x)
{
	if(x == 0)
		x = 1;
	else if(y == 0)
		return x;
	return (y / x);
}

double Sin(double x)
{
	double radian = x * PI / 180.0; 
	return sin(radian);
}

double Cos(double x)
{
	double radian = x * PI / 180.0;
	return cos(radian);
}

double Tan(double x)
{
	double radian = x * PI / 180.0;
	return tan(radian);
}

double Squre(int x, int count)
{
	double squre = 1.0;
	double trans;
	trans = (double)x;

	for(int i = 1; i < count; i++)
		squre *= 10.0;
	return(trans * squre);
}

double Float_Squre(int x, int count)
{
	double squre = 1.0;
	double trans;
	trans = (double)x;

	for(int i = 0; i <= count; i++)
		squre /= 10.0;
	return (trans * squre);
}

double Trans(int str[NUMBER], int count)
{
	double total = 0.0;

	for(int i = 0; i < count; i++)
		total += Squre(str[i], count - 1);
	return total;
}

double Float_Trans(int str[NUMBER], int count)
{
	int point = 0;
	double total = 0.0;
	for(int i = 0; i < count; i++)
	{
		if(str[i] == 46)
		{
			point = i;
			break;
		}
	}
	//整数部
	for(int j = 0; j < point; j++)
	{
		total += Squre(str[j], point - j);
	}
	point++;
	
	//少数部
	for(int j = 0; j < count - point; j++)
	{
		total += Float_Squre(str[point+1], j+1);
		point++;
	}
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

void Sum(int utr[SURGES],  double x[SURGES], int count)
{
	int o_count = 0;
	double total = 0;
	
/*	for(i = 1; i <= count; i++)
		printf("%f\t\b", x[i-1]);
	putchar('\n');
*/
	CONTINUE:
	for(int i = 1; i <= count; i++)
	{
		if(utr[i] == 42 && i < count)
		{
			o_count++;
			x[i-1] = Multi(x[i-1], x[i]);
			for(int j = i; j <= count; j++)
			{
				x[j] = x[j + 1];
				utr[j] = utr[j+1];
			}
			goto CONTINUE;
		}
		else if(utr[i] == 47 && i < count)
		{
			o_count++;
			x[i-1] = Divis(x[i-1], x[i]);
			for(int j = i; j <= count; j++)
			{
				x[j] = x[j + 1];
				utr[j] = utr[j + 1];
			}
			goto CONTINUE;
		}
		
		if(utr[i] == 42 && i == count)
		{
			o_count++;
			x[i-1] = Multi(x[i], x[i-1]);
			goto CONTINUE;
		}
		else if(utr[i] == 47 && i == count)
		{
			o_count++;
			x[i-1] = Divis(x[i-1], x[i]);
			goto CONTINUE;
		}
	}
//確認用の表示
/*
	for(int i = 1; i <= count; i++)
	{
		printf("&f ", x[i-1]);
		printf("%d ", utr[i]);
	putchar('\n');
*/
	if((count - o_count) == 1)
		goto END;
	
	for(int i = 1; i <= count - o_count; i++)
	{
//		printf("total=%f\n", total);
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
			printf("total=%f\n", total);
			break;
		}
	}
	return;

	END: printf("total=%f\n", x[0]);
}


void Keisan(int str[NUMBER], double ttr[SURGES], int utr[SURGES], int operator[OPERATOR])
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

	fp= fopen(fname, "r");
	while((ch = fgetc(fp)) != EOF)
	{
		// .
		if(ch == 46)
		{
			str[count++] = 46;
		}
		//0~9
		else if(ch >= 48 && ch <= 57)
		{
			str[count++] = (ch - 48);
			ttr[i] = Trans(str, count);
		}
		//小数点の確認
		for(int j = 0; j < count; j++)
		{
			if(str[j] == 46)
			{
				ttr[i] = Float_Trans(str, count);
			}
		}
		//sin, cos, tan
		
		// + - * /
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
			case 47:
				utr[++i] = operator[3];
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

/*
	for(i = 0; i < count; i++)
		printf("%3d", str[i]);
	putchar('\n');
*/	
}

void Keisan_print(void)
{
	int str[NUMBER];
	double ttr[SURGES];
	int utr[SURGES];
	int operator[OPERATOR];
	Keisan(str, ttr, utr, operator);
}

int main(void)
{
	Keisan_print();
	return 0;
}
