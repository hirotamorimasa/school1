#include <stdio.h>
#include <stdlib.h>

#define NUMBER 6
#define SURGES 25
#define OPERATOR 5


double Squre(int x, int count)
{
	double squre = 1.0;
	double trans;
	trans = (double)x;
	
	for(int i = 1; i < count; i++)
		squre *= 10.0;
	return (trans * squre);
}

double Float_Squre(int x, int count)
{
	double squre = 1.0;
	double trans;
	trans = (double)x;

	for(int i = 0; i < count ; i++)
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
	int i = 0, point = 0; 
	double total = 0.0;
	for(i; i < count; i++)
	{
		if(str[i] == 46)
		{
			point = i; //point = 2
			break;
		}
	}

	//整数部
	for(int j = 0; j < point; j++)
		total += Squre(str[j], point - j);
	point++; //point = 3

	//少数部
	for(int j = 0; j < count - i; j++)
	{
		total += Float_Squre(str[point++], j+1);
	}
	return total;
}

void Operator(int operator[OPERATOR])
{
	int i = 0;
	operator[i++] = 61;
}

void Sum(int utr[SURGES], double x[SURGES], int count)
{
	int o_count = 0;
	double total = 0;

//	printf("total=%3.5f\n", x[0]);
}

void Keisan(int str[NUMBER], double ttr[SURGES], int utr[SURGES], int operator[OPERATOR])
{
	int ch;
	int i = 0, count = 0;
	FILE *fp;
	char fname[] = "test.txt";

	Operator(operator);
	
	fp = fopen(fname, "r");
	while((ch = fgetc(fp)) != EOF)
	{
		// =
		if(ch == operator[4])
		{
			utr[++i] = operator[4];
			Sum(utr, ttr, i);
			break;
		}
		// .
		else if(ch == 46)
			str[count++] = 46;
		// 0~9
		else if(ch >= 48 && ch <= 57)
		{
			str[count++] = (ch - 48);
			ttr[i] = Trans(str, count);
		}
		//小数点の確認
		for(int j = 0; j < count; j++)
		{
			if(str[j] == 46)
				ttr[i] = Float_Trans(str, count);
		}
	}

	printf("total=%3.5f\n", ttr[0]);
	for(int j = 0; j < count; j++)
		printf("str[%d]=%3d\n", j, str[j]);
	putchar('\n');
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
