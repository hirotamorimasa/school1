//SPDX-License-Identifier:GPL-2.0
//*Copyright (c) 2021 Hiromasa Morita. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define RANSU 100

int text_number(void)
{
	int ch;
	int count = 0;
	FILE *fp;
	char fname[] = "text.txt";

	fp = fopen(fname, "r");
	while((ch = fgetc(fp)) != EOF)
	{
		count++;
	}
	fclose(fp);

	return count;
}	


int Ransu(void)
{
	return rand() % text_number(); 
}

void Print_alpha(void)
{
	int i, count;
	int ch;
	int k;
	FILE *fp;
	char fname[] = "text.txt";

	srand(time(NULL));
	count = 0;

	fp = fopen(fname, "r");
	if(fp == NULL)
	{
		printf("%s file don't open.\n", fname);
        }

	for(i = 0; i < RANSU; i++)
	{
		k = Ransu();
		count = 0;

		fp = fopen(fname, "r");
		while((ch = fgetc(fp)) != EOF)
		{
			count += 1;
			if(k == count && (ch == 32 || isalpha(ch)))
			{
				putchar(tolower(ch));
			}
		}
	}
	putchar('\n');
	fclose(fp);
}

int main(void)
{
	Print_alpha();
	return 0;
}
