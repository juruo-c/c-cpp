#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	//雷的信息存储
	//1.布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };
	//2.排查出的雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');
	//打印棋盘
	Displayboard(show, ROW, COL);
	//布置雷
	Setmine(mine, ROW, COL);

	//扫雷
	Findmine(mine, show, ROW, COL);
	

}
void menu()
{
	printf("*******************************\n");
	printf("***      1.play  0.exit     ***\n");
	printf("*******************************\n");
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新选择!");
			break;
		}

	} while (input);
}
int main()
{
	test();
	return 0;
}