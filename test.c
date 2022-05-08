#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 4
#define NUMBER 20

//文字数をカウントする関数
int Count(char str[NUMBER])
{
	int count = 0;
	for(int i = 0; str[i] != '\0'; i++)
		count++;
	return count;
}

//最初にずれている要素数を確認する関数
int Gap(char str[NUMBER], char str1[NUMBER])
{
	int count;
	for(int i = 0; ; i++)
	{
		if(str[i] != str1[i])
		{
			count = i;
			break;
		}
	}
	return count;
}

//入力と出力の文字列数の差
int diff(char str[NUMBER], char str1[NUMBER])
{
	if(Count(str) > Count(str1))
		return 0;
	else if(Count(str) < Count(str1))
		return Count(str) - Count(str1);
}

//文字をずらす関数
void Slide(char str[NUMBER], char str1[NUMBER], char ttr[NUMBER])
{
	int s_count = 0;
	
	//出力の文字列のほうが多いとき
	if(Count(str) > Count(str1))
	{
		s_count = Count(str);;
		goto CONTINUE;
	}
	//入力された文字列の方は多いとき
	else if(Count(str) < Count(str1))
		s_count = Count(str1);
	
	
	//文字をずらす
	for(int i = 0; i < s_count + diff(str, str1) + 1; i++)
	{
		if(i < Gap(str, str1) - 1)
			ttr[i] = str[i];
		else if(i == Gap(str, str1) - 1)
			ttr[i] = ' ';
		else if(i > Gap(str, str1) - 1)
			ttr[i] = str[i-1];
		else if(i == s_count + 1)
			ttr[i] = '\0';
	}
	printf("%s\n%s\n", ttr, str1);
	return;

	CONTINUE:
	for(int i = 0; i < s_count + diff(str, str1) + 1; i++)
	{
		if(i < Gap(str, str1))
			ttr[i] = str1[i];
		else if(i == Gap(str, str1))
			ttr[i] = ' ';
		else if(i > Gap(str, str1))
			ttr[i] = str1[i-1];
		else if(i == s_count + 1)
			ttr[i] = '\0';
	}
	printf("%s\n%s\n", str, ttr);
	return;
}


// o/の表示(マッチしていればo)
void Match_Print(char str[NUMBER], char str1[NUMBER])
{
	for(int i = 0; i < Count(str) + diff(str, str1); i++)
	{
		if(str[i] == str1[i])
			putchar('o');
		else if(str[i] != str1[i])
			putchar('/');
	}
	printf("\n\n");
}

//文字列を入力する関数
void Input_data(char str[NUMBER], char str1[NUMBER])
{
	printf("%s\n", str);

	//文字列を入力する
	scanf("%s", str1);
}

//乱数で決まった文字列を格納するための関数
void storage(char str[NUM][NUMBER], char output[NUMBER])
{
	int ransu;
	ransu = rand() % 4;

	for(int i = 0; str[ransu][i] != '\0'; i++)
		output[i] = str[ransu][i];
}

//残りを処理する関数git
void process(char input[NUMBER], char output[NUMBER], char ttr[NUMBER])
{
	Match_Print(output, input);

	if(Count(input) == Count(output))
		return;
	Slide(output, input, ttr);

	if(Count(output) > Count(input))
		Match_Print(output, ttr);	
	else if(Count(output) < Count(input))
		Match_Print(ttr, input);
}

int main(void)
{
	char input[NUMBER];	//出力する文字列
	char output[NUMBER];	//入力する文字列
	char ttr[NUMBER];	//ずらした文字列を格納するための文字列

	char str[NUM][NUMBER] = {"tsudanuma", "chiba", "narashino", "shinnarashino"};
	srand(time(NULL));
	
	storage(str, output);
	Input_data(output, input);
	process(input, output, ttr);
	
	return 0;
}



	

