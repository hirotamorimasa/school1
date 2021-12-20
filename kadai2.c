//SPDX-Lincese-Identifier:GPL-2.0
//*Copyright (c) 2021 Hiromasa Morita. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define S_ALPHA 97
#define L_ALPHA 65
#define ALPHA 26

const char str[] = "abcdefghijklmnopqrstuvwxyz";

void Print_alpha(void)
{
	int i;
	int ch;
	int s_alpha, l_alpha;
	int count[26];
	FILE *fp;
	char fname[] = "test.txt";

	for(i = 0; i < ALPHA; i++)
	{
		count[i] = 0;
	}

	fp = fopen(fname, "r");
	if(fp == NULL)
	{
		printf("%s file don't open.\n", fname);
	}

	while((ch = fgetc(fp)) != EOF)
	{
		s_alpha = S_ALPHA;
		l_alpha = L_ALPHA;

		for(i = 0; i < ALPHA; i++)
		{
			if(ch == s_alpha)
			{
				count[i] += 1;
				break;
			}
			else if(ch == l_alpha)
			{
				count[i] += 1;
				break;
			}
			else
			{
				s_alpha++;
				l_alpha++;
			}
		}
	}

	printf("\n");
	for(i = 0; i < ALPHA; i++)
	{
		printf("%c:%d個\n", str[i], count[i]);
	}

	fclose(fp);
}

int main(void)
{
	Print_alpha();
	return 0;
}

