#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cmath>
//using namespace std;
//int main()
//{
//	int n;
//	long a[100001];
//	while (1)
//	{
//		cin >> n;
//		if (!n)
//			break;
//		double sum = 0.0;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> a[i];
//			sum += sqrt(a[i]);
//		}
//		if (sum - (int)sum)
//		{
//			cout << "NO" << endl;
//		}
//		else
//			cout << "Yes" << endl;
//	}
//	return 0;
//}

#include<iostream>
using namespace std;
typedef struct Color
{
	int sta;
	int flag;
}Color;
void Initcolor(Color color[50][50], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			color[i][j].flag = 0;
			color[i][j].sta = 0;
		}
	}
}
int full_color(Color color[50][50], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (color[i][j].sta != 1)
				return 0;
		}
	}
	return 1;
}
int main()
{
	int row, col;
	cin >> row >> col;
	int board[50][50] = { 0 };
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> board[i][j];
		}
	}
	Color color[50][50];
	Initcolor(color,row,col);
	int cnt = 0;
	while (!full_color(color,row,col))
	{

	}
	cout << cnt;
	return 0;
}