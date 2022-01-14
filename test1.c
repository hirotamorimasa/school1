#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void Slide()
{
}

void print(void)
{
	int ch;
	FILE *fp;
	char fname[] = "test.txt";

	fp = fopen(fname, "r");
	if(fp == NULL)
	{
		printf("%s file don't open.\n", fname);
	}

	fp = fopen(fname, "r");

	while((ch = fgetc(fp)) != EOF)
	{
		
}

int main(void)
{
	Slide_print();
	return 0;
}
