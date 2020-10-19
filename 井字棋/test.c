#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"

void menu()
{
	printf("*************************\n");
	printf("***  1.play  0.exit   ***\n");
	printf("*************************\n");
}
void game()
{
	char ret = 0;
	//创建数组存放走出的棋盘信息
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	Initboard(board, ROW, COL);
	//打印棋盘
	Displayboard(board,ROW,COL);
	//下棋
	while (1)
	{
		//玩家下棋
		Playermove(board,ROW,COL);
		Displayboard(board, ROW, COL);
		//判断玩家是否赢
		ret=Is_win(board,ROW,COL);
		if (ret != 'C')
			break;
		//电脑下棋
		Computermove(board,ROW,COL);
		Displayboard(board, ROW, COL);
		//判断电脑是否赢
		ret=Is_win(board,ROW,COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
		printf("玩家赢\n");
	else if (ret == '#')
		printf("电脑赢\n");
	else
		printf("平局\n");
}
void test()
{
	int input=0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("井字棋\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}