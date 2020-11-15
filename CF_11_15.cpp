#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int a[110],n;
//bool check(int a[])
//{
//	int k = a[0];
//	for (int i = 1; i <= n; i++)
//	{
//		if (a[i] != k)
//			return false;
//	}
//	return true;
//}
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		cin >> n;
//		for (int i = 1; i <= n; i++)
//		{
//			a[i] = i;
//		}
//		int cnt = 1;
//		for (int i = n; i >= n / 2; i--)
//		{
//			for (int j = 1; j <= i; j++)
//			{
//				for(int i=)
//			}
//		}
//	}
//	return 0;
//}

#include<iostream>
#include<algorithm>
using namespace std;
int ans,tx,ty,n, m,a[20][20],dp[20][20];
int d[2][4] = { 1,0,-1,0,0,1,0,-1 };
int sum_all(int a[][20])
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			sum += a[i][j];
		}
	}
	return sum;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> a[i][j];
			}
		}
		ans = sum_all(a);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				for (int k = 1; k < 4; k++)
				{
					tx = i + d[0][k];
					ty = j + d[1][k];
					if (tx > 0 || ty > 0 || ty <= m || tx <= n)
					{
						a[i][j] = -a[i][j];
						a[tx][ty] = -a[tx][ty];
						if (sum_all(a) > ans)
							ans = sum_all(a);
						else
						{
							a[i][j] = -a[i][j];
							a[tx][ty] = -a[tx][ty];
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}