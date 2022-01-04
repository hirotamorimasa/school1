#include <stdio.h>

#define NUMBER 15

void pascal_triangle(void)
{
	int i, j;
	int a[NUMBER][NUMBER];
	
	for(i = 0; i < NUMBER; i++)
	{
		a[i][0] = 1;
		for(j = 1; j < NUMBER; j++)
		{
			 a[i][j] = 0;
		}
	}

	for(i = 1; i < NUMBER; i++)
	{
		for(j = 1; j < i+2; j++)
		{
			a[i][j] = a[i-1][j-1] + a[i-1][j];
		}
	} 

	for(i = 0; i < NUMBER; i++)
	{
		for(j = 0; j < NUMBER; j++)
		{
			printf(" %d", a[i][j]);
		}
		putchar('\n');
	}
}

int main(void)
{
	pascal_triangle();
	return 0;
}
