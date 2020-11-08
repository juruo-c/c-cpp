#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//int main()
//{
//	int n;
//	int a[101];
//	while (cin >> n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			cin >> a[i];
//		}
//		int max = a[0];
//		int min = a[0];
//		double sum = 0;
//		for (int i = 1; i < n; i++)
//		{
//			if (a[i] > max)
//				max = a[i];
//			if (a[i] < min)
//				min = a[i];
//			sum += a[i];
//		}
//		sum += a[0];
//		printf("%.2lf\n", (sum - max - min) / (n - 2));
//
//	}
//	return 0;
//}

//#include<iostream>
//#include<cstring>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	char s[10000];
//	while (n--)
//	{
//		cin >> s;
//		int len = strlen(s);
//		int i;
//		for ( i = 0; i < len / 2; i++)
//		{
//			if (s[i] != s[len - i - 1])
//			{
//				cout << "no" << endl;
//				break;
//			}
//		}
//		if (i == len / 2)
//			cout << "yes" << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<cmath>
//using namespace std;
//int n, ans, mp[10][10];
//int queen[10];
//bool check(int num)
//{
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = i + 1; j <= n; j++)
//		{
//			if (queen[i] == queen[j] || abs(queen[i] - queen[j]) == (j - i))
//			{
//				return false;
//			}
//		}
//	}
//	return true;
//}
//void dfs(int num)
//{
//	if (num == n + 1)
//	{
//		if (!check(n))
//			return;
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= n; j++)
//			{
//				if (mp[i][j])
//					cout << "(" << i - 1 << "," << j - 1 << ")";
//			}
//		}
//		cout << endl;
//		ans++;
//		return;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		queen[num] = i;
//		mp[num][i] = 1;
//		dfs(num + 1);
//		mp[num][i] = 0;
//	}
//}
//int main()
//{
//	n = 8;
//	dfs(1);
//	cout << ans << endl;
//	return 0;
//}

#include<iostream>
#include<algorithm>
using namespace std;
int T, M, v[101], w[101];
int f(int t, int i,int v[],int w[])
{
	if (t<=0)
		return 0;
	if (i <= 0)
		return -1;
	return max(f(t, i - 1, v, w), f(t - v[i], i - 1, v, w)+w[i]);
}
int main()
{
	cin >> T >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> v[i] >> w[i];
	}
	cout << f(T, M, v, w) << endl;
	return 0;
}