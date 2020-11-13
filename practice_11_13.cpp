#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//int main()
//{
//	int row,col;
//	char board[15][15];
//	int count[15][15] = { 0 };
//	int cnt = 0;
//	while (1)
//	{
//		cin >> row;
//		if (!row)
//			break;
//		cin >> col;
//		cout << "puzzle #" << ++cnt << ":" << endl;
//		for (int i = 0; i < row; i++)
//		{
//			for (int j = 0; j < col; j++)
//			{
//				cin >> board[i][j];
//			}
//		}
//		int num = 0;
//		for (int i = 0; i < row; i++)
//		{
//			for (int j = 0; j < col; j++)
//			{
//				if ((i == 0 || j == 0 || board[i - 1][j] == '*' || board[i][j - 1] == '*')&&board[i][j]!='*')
//					count[i][j] = ++num;
//			}
//		}
//		cout << "Across" << endl;
//		int i, j;
//		for (i = 0; i < row; i++)
//		{
//			int flag = 1;
//			for (j = 0; j < col; j++)
//			{
//				if (board[i][j] == '*')
//				{
//					if (flag)
//						continue;
//					else
//					{
//						flag = 1;
//						cout << endl;
//						continue;
//					}
//				}
//				else
//				{
//					if (flag)
//					{
//						printf("%3d", count[i][j]);
//						cout<< "." << board[i][j];
//						flag = 0;
//					}
//					else
//					{
//						cout << board[i][j];
//					}
//				}
//			}
//			if(board[i][j-1]!='*')
//			cout << endl;
//		}
//		cout << "Down" << endl;
//		int board_flag[15][15] = { 0 };
//		for (i=0;i<row;i++)
//		{
//			for (j = 0; j < col; j++)
//			{
//				int flag = 0;
//				if (count[i][j])
//				{
//					if(!board_flag[i][j])
//					printf("%3d.", count[i][j]);
//					int k = i;
//					while (board[k][j] != '*'&&k < row)
//					{
//						if (!board_flag[k][j])
//						{
//							cout << board[k][j];
//							board_flag[k][j] = 1;
//							flag = 1;
//						}
//						k++;
//					}
//					if(flag)
//						cout << endl;
//					
//				}
//			}
//		}
//		cout << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//double a, b;
//int num[51];
//int main()
//{
//	while(cin >> a >> b)
//	{
//		
//	}
//	return 0;
//}

//#include<stdio.h>
//int length(long long n)
//{
//	int cnt = 0;
//	while (n)
//	{
//		n /= 10;
//		cnt++;
//	}
//	return cnt;
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	long long a;
//	while (t--)
//	{
//		scanf("%lld", &a);
//		if (a % 10 == 6 || a % 6 == 0 || length(a) == 6)
//		{
//			printf("Yes\n");
//		}
//		else
//			printf("No\n");
//	}
//	return 0;
//}

#include<stdio.h>
int main()
{
	int t;
	scanf("%d", &t);
	int x1, y1, x2, y2, x3, y3, x4, y4;
	while (t--)
	{
		scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
		if (x4<x1 || x3 > x2 || y4 < y1 || y3 > y2)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}

//#include<stdio.h>
//#include<math.h>
//int is_prime(int n)
//{
//	if (n < 2)
//		return 0;
//	int i;
//	for (i = 2; i <= (int)sqrt(n); i++)
//	{
//		if (n%i == 0)
//			return 0;
//	}
//	return 1;
//}
//int is_mirror(int n)
//{
//	int c = 0;
//	int tmp = n;
//	while (n)
//	{
//		c = c * 10 + n % 10;
//		n /= 10;
//	}
//	if (c == tmp)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int T;
//	scanf("%d", &T);
//	int a;
//	while (T--)
//	{
//		scanf("%d", &a);
//		if(is_prime(a)&&is_mirror(a))
//			printf("Yes\n");
//		else
//			printf("No\n");
//		
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n,a;
//	scanf("%d", &n);
//	while (n--)
//	{
//		scanf("%d", &a);
//		if (a % 2)
//			printf("0 0\n");
//		else
//		{
//			printf("%d ", a / 4 + a % 4 / 2);
//			printf("%d\n", a / 2 + a % 2 / 4);
//
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//int is_prime(long long n)
//{
//	if (n < 2)
//		return 0;
//	long long i;
//	for (i = 2; i <=(long long)sqrt(n); i++)
//	{
//		if (n%i == 0)
//			return 0;
//	}
//	return 1;
//}
//int main()
//{
//	long long n,i;
//	int flag = 1;
//	scanf("%lld", &n);
//	for (i = 1; i <= n-2; i++)
//	{
//		if (is_prime(i) && is_prime(i - 2) && is_prime(i + 2))
//		{
//			printf("%lld %lld %lld\n", i - 2, i, i + 2);
//			flag = 0;
//		}
//	}
//	if (flag)
//		printf("No triple\n");
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int t,a,s[5];
//	scanf("%d", &t);
//	while (t--)
//	{
//		scanf("%d", &a);
//		if (a < 1000&&a>9999)
//		{
//			printf("NO\n");
//			continue;
//		}
//		int tmp = a;
//		int cnt = 0;
//		while (a)
//		{
//			s[cnt] = a % 10;
//			a /= 10;
//			cnt++;
//		}
//		int sum1 = s[1] * 10 + s[0];
//		int sum2 = s[3] * 10 + s[2];
//		if ((sum1 + sum2)*(sum1 + sum2) == tmp)
//		{
//			printf("YES\n");
//
//		}
//		else
//			printf("NO\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//long long pow(int n, int k)
//{
//	long long sum = 1;
//	for (int i = 0; i < k; i++)
//	{
//		sum *= n;
//	}
//	return sum;
//}
//int main()
//{
//	int t,n,k;
//	scanf("%d", &t);
//	while (t--)
//	{
//		long long sum = 0;
//		scanf("%d%d", &n, &k);
//		for (int i = 1; i <= k; i++)
//		{
//			sum += pow(n, i);
//		}
//		printf("%lld\n", sum);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int h1, m1, s1,h2,m2,s2;
//	scanf("%d:%d:%d", &h1,& m1, &s1);
//	scanf("%d:%d:%d",& h2,& m2,& s2);
//	int h = h1 - h2;
//	int m = m1 - m2;
//	int s = s1 - s2;
//	if (s < 0)
//	{
//		s += 60;
//		m--;
//	}
//	if (m < 0)
//	{
//		m += 60;
//		h--;
//	}
//	printf("%d:%d:%d", h, m, s);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int i = 2;
//	while (n!=1)
//	{
//		if (n%i == 0)
//		{
//			printf("%d ", i);
//			n /= i;
//		}
//		else
//			i++;
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int t;
//	char c, s[105];
//	scanf("%d", &t);
//	while (t--)
//	{
//		int cnt = 0;
//		getchar();
//		scanf("%c", &c);
//		scanf("%s", s);
//		int i = 0;
//		while (s[i] != '\0')
//		{
//			if (s[i] == c || s[i] == c - 32)
//			{
//				cnt++;
//			}
//			i++;
//		}
//		printf("%d\n", cnt);
//	}
//}

//#include<stdio.h>
//int main()
//{
//	printf("####\n");
//	printf(" ####\n");
//	printf("  ####\n");
//	printf("   ####\n");
//	return 0;
//}

//#include<stdio.h>
//int is_leap(int year)
//{
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//		return 1;
//	else
//		return 0;
//}
//int s[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//int main()
//{
//	int t,year,month,day;
//	scanf("%d", &t);
//	while (t--)
//	{
//		scanf("%d/%d/%d", &year, &month, &day);
//		int sum = 0;
//		int i = 0;
//		for (i = 0; i < month - 1; i++)
//		{
//			sum += s[i];
//		}
//		if (is_leap(year)&&month>2)
//			sum++;
//		printf("%d\n", sum + day);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n;
//	double x,k;
//	scanf("%d", &n);
//	while (n--)
//	{
//		scanf("%lf", &k);
//		for (int i = 1; i <= 2 * k; i++)
//		{
//			if ((i - k) == 0)
//			{
//				continue;
//			}
//			x = k * i / (i - k);
//			int tmp = (int)x;
//			if (x == tmp && x > 0)
//			{
//				printf("1/%d=1/%d+1/%d\n", (int)k, tmp, i);
//			}
//		}
//	}
//	return 0;
//}