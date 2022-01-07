//*Copyright (c) 2022 Hiromasa Morita. All rights reserved.


#include <stdio.h>
#include <stdlib.h>


void aho_process(void)
{
	int i;
	int start, end;

	printf("start:");	scanf("%d", &start);
	printf("end:");	scanf("%d", &end);
	
	for(i=start; i<=end; i++)
	{
		if(i % 3 == 0)	printf("aho\t");
		printf("%d\n", i);
	}
}

void aho_print(void)
{
	aho_process();
}

int main(void)
{
	aho_process();
	return 0;
}

