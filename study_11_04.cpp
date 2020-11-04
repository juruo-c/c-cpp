#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//double l[4] = { 12.01,1.008,16.00,14.01 };
//int main()
//{
//	int T;
//	cin >> T;
//	char s[100];
//	while (T--)
//	{
//		cin >> s;
//		
//		double m, sum = 0.0;
//		int i = 0;
//		while(s[i])
//		{
//			if (s[i] >= 'A'&&s[i] <= 'Z')
//			{
//
//				switch (s[i])
//				{
//				case 'C':
//					m = l[0];
//					i++;
//					break;
//				case 'H':
//					m = l[1];
//					i++;
//					break;
//				case 'O':
//					m = l[2];
//					i++;
//					break;
//				case 'N':
//					m = l[3];
//					i++;
//					break;
//				}
//				if ((s[i] >= 'A'&&s[i] <= 'Z')||!s[i])
//				{
//					sum += m;
//				}
//				else
//				{
//					int num = 0;
//					while (s[i] > '0'&&s[i] <= '9')
//					{
//						num = (num + (s[i] - '0')) * 10;
//						i++;
//					}
//					sum += m * (num / 10);
//					
//				}
//			}
//		}
//		printf("%.3lf\n", sum);
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//char* locate(char a[])
//{
//	char* p = a;
//	while (*(p++))
//	{
//		;
//	}
//	return --p;
//}
//int main()
//{
//	int T, n;
//	cin >> T;
//	char a[1000000];
//	
//	while (T--)
//	{
//		int ans[10] = { 0 };
//		cin >> n;
//		for (int i = 1; i <= n; i++)
//		{
//			if (i ==1)
//				sprintf(a, "%d", i);
//			else
//				sprintf(locate(a), "%d", i);
//		}
//		for (int i = 0; a[i]; i++)
//		{
//			ans[a[i] - '0']++;
//		}
//		for (int i = 0; i < 10; i++)
//		{
//			cout << ans[i];
//			if (i < 9)
//			{
//				cout << " ";
//			}
//		}
//		cout << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int is_same1(char* p1, char* p2,char a[])
//{
//	for (int i = 1; i < p2 - p1; i++)
//	{
//		if (*(p1 + i) != *(p2 + i))
//		{
//			return 0;
//		}
//		
//	}
//	return 1;
//}
//int main()
//{
//	int n;
//	char a[85];
//	cin >> n;
//	while (n--)
//	{
//		cin >> a;
//		char* p1, *p2;
//		p1 = p2 = a;
//		while (*p2)
//		{
//			p2++;
//			if (*p1 == *p2)
//			{
//				if (is_same1(p1, p2,a))
//				{
//					printf("%d\n\n", p2 - p1);
//					break;
//				}
//			}
//
//		}
//	}
//	return 0;
//}

#include<iostream>
using namespace std;
int main()
{
	char board[5][5];
	int col = 5; 
	int row = 5;
	int count = 0;
	char operate[1000];
	while (1)
	{
		int space_row, space_col;
		int flag = 1;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				char c = getchar();
				if (c != '\n')
					board[i][j] = c;
				else
					board[i][j] = getchar();
				if (board[i][j] == 'Z')
				{
					flag = 0;
					break;
				}
				if (board[i][j] == ' ')
				{
					space_row = i;
					space_col = j;
				}
			}
			if (!flag)
				break;
		}
		if (!flag)
			break;
		cout << "Puzzle #" << ++count << ":" << endl;
		char c_1;
		int cnt = 0;
		while ((c_1 = getchar() )!= '0')
		{
			if (c_1 == '\n')
				continue;
			else
			{
				operate[cnt] = c_1;
				cnt++;
			}
		}
		operate[cnt] = c_1;
		cnt = 0;
		while (operate[cnt]!='0')
		{
			
			switch (operate[cnt])
			{
			case 'A':
				if (space_row - 1 >= 0)
				{
					board[space_row][space_col] = board[space_row - 1][space_col];
					space_row--;
					board[space_row][space_col] = ' ';
				}
				else
				{
					cout << "This puzzle has no final configuration." << endl;
					flag = 0;
				}
				break;
			case 'B':
				if (space_row +1 < row)
				{
					board[space_row][space_col] = board[space_row + 1][space_col];
					space_row++;
					board[space_row][space_col] = ' ';
				}
				else
				{
					cout << "This puzzle has no final configuration." << endl;
					flag = 0;
				}
				break;
			case 'R':
				if (space_col + 1 < col)
				{
					board[space_row][space_col] = board[space_row][space_col+1];
					space_col++;
					board[space_row][space_col] = ' ';
				}
				else
				{
					cout << "This puzzle has no final configuration." << endl;
					flag = 0;
				}
				break;
			case 'L':
				if (space_col - 1 >= 0)
				{
					board[space_row][space_col] = board[space_row][space_col-1];
					space_col--;
					board[space_row][space_col] = ' ';
				}
				else
				{
					cout << "This puzzle has no final configuration." << endl;
					flag = 0;
				}
				break;
			}
			if (!flag)
				break;
			cnt++;
		}
		if (flag)
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					cout << board[i][j];
					if (j < col - 1)
						cout << " ";
				}
				cout << endl;
			}
		}
		cout << endl;
	}
	return 0;
}





