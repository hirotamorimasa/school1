//SPDX-License-Identifier:GPL-2.0
//*Copyright (c) 2021 Hiromasa Morita. All rights reserved.


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define RANSU 500

//テキストファイルの文字数を導出
int text_number(void)
{
	int count = 0;
	int ch;
	FILE *fp;
	char fname[] = "test.txt";

	fp = fopen(fname, "r");
	if(fp == NULL)
	{
		return -1;
	}

	while((ch = fgetc(fp)) != EOF)
	{
		count++;
	}
	fclose(fp);
	return count;
}

//乱数ｋの生成
int Ransu(void)
{
	return (rand() % text_number());
}

void Print_alpha(void)
{
	FILE *fp;
	char fname[] = "test.txt";
	int k;    //k番目、ｋ’番目
	int x;    //x番目
	int ch, ch_dash;
	int i, count = 0;
	int moji_count;
	srand(time(NULL));
	
	k = Ransu();

	if(text_number() == -1)
	{
		printf("%s file don't open.", fname);
		return;
	}

	fp = fopen(fname, "r");
	while((ch = fgetc(fp)) != EOF)
	{
		count++;
		if(count == k && (ch == 32 || isalpha(ch)))
		{
			putchar(tolower(ch));
		}
		else if(count == (k + 1) && (ch == 32 || isalpha(ch)))
		{
			putchar(tolower(ch));
			ch_dash = ch;
		}
	}

	for(i = 0; i < RANSU; i++)
	{
		k = Ransu();
		x = -1;
		count = 0;
		moji_count = 0;

		fp = fopen(fname, "r");
		while((ch = fgetc(fp)) != EOF)
		{
			count++;
			if(k == count  && ch == ch_dash && moji_count == 0)
			{
				x = count;
				moji_count++;
			}
			if((x + 1) == count && (ch == 32 || isalpha(ch)))
			{
				putchar(tolower(ch));
			}
		}
	}
	printf("\n文字数：%d\n", text_number());
	fclose(fp);
}

int main(void)
{
	Print_alpha();
	return 0;
}


























