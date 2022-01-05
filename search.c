#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Ransu(void)
{
	return rand() % 100 + 1;
}

void Process(void)
{
	int you, cpu;
	int count = 0;
	srand(time(NULL));
	
	cpu = Ransu();

	do
	{
		printf("you:");
		scanf("%d", &you);
		count++;
		if(cpu > you)
		{
			printf("%dより大きいです\n", you);
		}
		else if(cpu < you)
		{
			printf("%dより小さいです\n", you);
		}
	}while(you != cpu || count < 7);

	if(count == 0)
	{
		printf("正解は%dです\n", cpu);
	}
	else	printf("%d回で正解しました\n", count);
}

void Number_search(void)
{
	Process();
}

int main(void)
{
	Number_search();
	return 0;
}
