#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 1000  //繰り返し回数

int Ransu(void)
{
	return rand() % 1000;
}

double POW(double x)
{
	return x * x;
}


void monte_calro_method(void)
{
	int i;		//カウント変数
	int count = 0;  //カウント変数
	double sum;		//円の面積
	double r = 0.5;    //半径
	float a, b;
	srand(time(NULL));

	for(i = 0; i < COUNT; i++)
	{
		a = (float)Ransu() / 1000;
		b = (float)Ransu() / 1000;

		if(POW(a-0.5) + POW(b-0.5) <= POW(0.5))
		{
			count++;
		}
	}
		sum = (double)count /(double)COUNT;
		printf("円の面積=%lf\tπ=%lf\n", sum, sum / POW(r));
}

int main(void)
{
	monte_calro_method();
	return 0;
}
