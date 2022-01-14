#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


void Sum(int sum, int x)
{
	sum += x;
}

void Subtraction(int sum, int x)
{
	sum -= x;
}

void Multiplication(int sum, int x)
{
	sum *= x;
}

void Division(int sum, int x)
{
	if(x != 0) sum /= x;
}

void Dentaku_process(void)
{
	int ch;
	int x;
	int sum = 0;   //初期値
	int count = 1;  //カウント変数
	FILE *fp;
	char fname[] = "dentaku.txt";

	fp = fopen(fname, "r");
	if(fp == NULL)
	{
		printf("%s file don't open\n", fname);
	}
	
	fp = fopen(fname, "r");
	while((ch = fgetc(fp)) != EOF)
	{
		
		x = ch * count;
		count *= 10;
		switch(ch)
		{
			case 43: //+
				Sum(sum, x);
				count = 1;
				break;
			case 45: //-
				Subtraction(sum, x);
				count = 1;
				break;
			case 47: // /
				Division(sum, x);
				count = 1;
				break;
			case 48: // 0
				x += 0 * 10;
				count *= 10;
				break;
			case 49: // 1
				x += 1 * 10;
				count *= 10;
				break;
			case 50: // 2
				x += 2 * 10;
				count *= 10;
				break;
			case 51: // 3
				x += 3 * 10;
				count *= 10;
				break;
			case 52: // 4
				x += 4 * 10;
				count *= 10;
				break;
			case 53: // 5
				x += 5 * 10;
				count *= 10;
				break;
			case 54: //6
				x += 6 * 10;
				count *= 10;
				break;
			case 55: //7
				x += 7 * 10;
				count *= 10;
				break;
			case 56: //8
				x += 8 * 10;
				count *= 10;
				break;
			case 57: //9
				x += 9 * 10;
				count *= 10;
				break;
			case 61: // =
				printf("=%d", sum);
				goto END;
			case 94: // ^
				x += 
			default:	break;
		}
		

}


void Dentaku_print(void)
{
	int you;
	int sum = 0; 
	Dentaku_process();
}

int main(void)
{
	Dentaku_print();
	return 0;
}
