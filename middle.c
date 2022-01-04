#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER 3

int compare(int a, int b)
{
	return(a > b ? 1 : -1);
}

void Middle(void)
{
	int a[NUMBER];
	int i;
	int middle;
	srand(time(NULL));

	a[0] = rand() % 100;
	
	do{
		a[1] = rand() % 100;
	}while(a[0] == a[1]);

	do{
		a[2] = rand() % 100;
	}while(a[0] == a[2] || a[1] == a[2]);
	
	for(i=0; i<NUMBER; i++)
	{
		printf("%d\t", a[i]);
	}

	if(compare(a[0], a[1] ) == 1)
	{
		middle = a[0];
		a[0] = a[1];
		a[1] = middle;
	}

	if(compare(a[0], a[2]) == 1)
	{
		middle= a[0];
		a[0] = a[2];
		a[2] = middle;
	}

	if(compare(a[1], a[2]) == 1)
	{
		middle = a[1];
		a[1] = a[2];
		a[2] = middle;
	}

	printf("\n中間値：%d\n", a[1]);
	for(i=0 ; i<NUMBER ; i++)
	{
		printf("%d\t", a[i]);
	}
	putchar('\n');
}	


int main(void)
{
	Middle();
	return 0;
}
