#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int n, a[1010], b[1010];
//	int kase = 0;
//	while (scanf("%d", &n) == 1 && n)
//	{
//		printf("Game %d:\n", ++kase);
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d", &b[i]);
//		}
//		while (1)
//		{
//			int A = 0, B = 0;
//			for (int i = 0; i < n; i++)
//			{
//				scanf("%d", &a[i]);
//				if (a[i] == b[i])
//					A++;
//			}
//			if (!a[0])
//				break;
//			for (int i = 1; i <= 9; i++)
//			{
//				int c1 = 0, c2 = 0;
//				for (int j = 0; j < n; j++)
//				{
//					if (a[j] == i)
//						c1++;
//					if (b[j] == i)
//						c2++;
//				}
//				if (c1 < c2)
//					B += c1;
//				else
//					B += c2;
//			}
//			printf("(%d,%d)\n", A, B - A);
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int ans[100005] = { 0 };
//	for (int i = 1; i < 100005; i++)
//	{
//		int x = i, y = i;
//		while (x > 0)
//		{
//			y += x % 10;
//			x /= 10;
//		}
//		if (ans[y] == 0 || i < ans[y])
//			ans[y] = i;
//	}
//	int T, n;
//	scanf("%d", &T);
//	while (T--)
//	{
//		scanf("%d", &n);
//		printf("%d\n", ans[n]);
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	char s[85];
//	while (n--)
//	{
//		scanf("%s", s);
//		int cnt = 1;
//		int ans = 0;
//		for (int i = 0; s[i]!='\0'; i++)
//		{
//			if (s[i] == 'O')
//			{
//				ans += cnt;
//				cnt++;
//			}
//			if (s[i] == 'X')
//			{
//				cnt = 1;
//			}
//		}
//		cout << ans<<endl;
//	}
//	return 0;
//}

#include<iostream>
using namespace std;
int main()
{
	double m[4] = { 12.01,1.008,16.00,14.01 };
	int n;
	cin >> n;
	char a[100];
	while (n--)
	{
		cin >> a;
		double sum = 0.0;
		for (int i = 0; a[i]; i++)
		{
			
			
			
		}
		printf("%.3lf\n", sum);
	}
	return 0;
}