#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int t;
//	long long n;
//	scanf("%d", &t);
//	while (t--)
//	{
//		scanf("%lld", &n);
//		long long sum = 0;
//		for (long long i = 1; i <= n; i++)
//		{
//			if (i % 5 == 0 || i % 7 == 0)
//			{
//				sum += i;
//			}
//		}
//		printf("%lld\n", sum);
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int T;
//	scanf("%d", &T);
//	char s[110];
//	getchar();
//	while (T--)
//	{
//		int sum = 0;
//		int sum_temp = 0;
//		int flag = 1;
//		scanf("%s", s);
//		int len = strlen(s);
//		for (int i = 0; i < len; i++)
//		{
//			if (s[i] == '-')
//			{
//				sum += sum_temp;
//				sum_temp = 0;
//				flag = -1;
//				continue;
//			}
//			if (s[i] == '+')
//			{
//				sum += sum_temp;
//				sum_temp = 0;
//				continue;
//			}
//			if (s[i] >= '0'&&s[i] <= '9')
//			{
//				sum_temp = sum_temp * 16 + s[i] - '0';
//			}
//			else if (s[i] >= 'a'&&s[i] <= 'z')
//				sum_temp = sum_temp * 16 + s[i] - 'a' + 10;
//			else
//				sum_temp = sum_temp * 16 + s[i] - 'A' + 10;
//		}
//		printf("%o\n", sum + flag*sum_temp);
//		
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int T,n,k;
//	scanf("%d", &T);
//	while (T--)
//	{
//		scanf("%d%d", &n, &k);
//		int cnt = n;
//		int leave = n;
//		while (leave >= k)
//		{
//			cnt += leave / k;
//			leave = leave - (leave / k)*k +leave/k;
//		}
//		printf("%d\n", cnt);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 32; i <= 99; i++)
//	{
//		int tmp = i*i;
//		int a, b, c, d;
//		a = tmp % 10;
//		tmp /= 10;
//		b = tmp % 10;
//		tmp /= 10;
//		c = tmp % 10;
//		tmp /= 10;
//		d = tmp % 10;
//		if (a == b && c == d)
//			printf("%d\n", i*i);
//	}
//
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int T;
//	char c, s[110];
//	scanf("%d", &T);
//	while (T--)
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
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int n;
//long long k, w[25];
//int main()
//{
//	cin >> n >> k;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> w[i];
//	}
//	int flag = 1;
//	for (int s = 0; s < (1 << n); s++)
//	{
//		long long sum = 0;
//		for (int i = 0; i < n; i++)
//		{
//			if ((s >> i)&1)
//			{
//				sum += w[i];
//			}
//		}
//		if (sum == k)
//		{
//			cout << "YES" << endl;
//			for (int i = 0; i < n; i++)
//			{
//				if ((s >> i)&1)
//					cout << w[i] << " ";
//			}
//			cout << endl;
//
//			flag = 0;
//			break;
//		}
//		
//	}
//	if (flag)
//		cout << "NO" << endl;
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//typedef long long ll;
//ll a[50],ans, b[50];
//int n, k;
//void dfs(ll cur, int pos, int cnt)
//{
//	if (cnt == k)
//		ans = min(ans, cur);
//	if (cnt >= k)
//		return;
//	if (cnt + (n - pos + 1) < k)
//		return;
//	if ((cur&b[pos] )>= ans)
//		return;
//	dfs(cur&a[pos], pos + 1, cnt + 1);
//	dfs(cur, pos + 1, cnt);
//}
//int main()
//{
//	cin >> n >> k;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//	}
//	ans = a[1];
//	sort(a, a + n);
//	b[n] = a[n];
//	for (int i = n - 1; i >= 1; i--)
//	{
//		b[i] = a[i] & b[i + 1];
//	}
//	dfs((1LL << 61) - 1, 1, 0);
//	cout << ans<<endl;
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//typedef long long ll;
//char a[10] = "CAIKUN";
//char b[10]="CHICKEN" ;
//int n;
//ll f[110], k;
//void init()
//{
//	f[1] = 6;
//	f[2] = 7;
//	for (int i = 3; i <= 60; i++)
//	{
//		f[i] = f[i - 2] + f[i - 1];
//		/*if (f[i] > 1e12 + 10)
//			cout << "pos:" << i << endl;*/
//	}
//}
//void solve(int n, ll k)
//{
//	if (n == 1)
//	{
//		cout << a[k - 1];
//		return;
//	}
//	if (n == 2)
//	{
//		cout << b[k - 1];
//		return;
//	}
//	if (n - 2 >= 56 || f[n - 2] >= k)
//		solve(n - 2, k);
//	else
//		solve(n - 1, k - f[n - 2]);
//}
//int main()
//{
//	init();
//	cin >> n >> k;
//	int len;
//	if (n >= 56)
//		len = 10;
//	else
//		len = min(10LL, f[n] - k + 1);
//	for (ll i = k; i <= k + len - 1; i++)
//	{
//		solve(n, i);
//	}
//	cout << endl;
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//const int n = 8;
//int ans,vis[10][10],queen[10];
//bool check(int cur, int num)
//{
//	for (int i = 1; i <cur; i++)
//	{
//		if (queen[i] == num || abs(queen[i] - num) == abs(cur - i))
//			return false;
//	}
//	return true;
//}
//void dfs(int cur)
//{
//	if (cur == n + 1)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= n; j++)
//			{
//				if (vis[i][j])
//					cout << "(" << i - 1 << "," << j - 1 << ")";
//			}
//		}
//		cout << endl;
//		ans++;
//		return;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (check(cur, i))
//		{
//			queen[cur] = i;
//			vis[cur][i] = 1;
//			dfs(cur + 1);
//			vis[cur][i] = 0;
//		}
//	}
//}
//int main()
//{
//	dfs(1);
//	cout << ans << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int n;
//char a[60];
//int main()
//{
//	cin >> n;
//	while (n--)
//	{
//		getchar();
//		int flag = 1;
//		cin >> a;
//		int i = 0;
//		if (a[0] >= '0'&&a[i] <= '9')
//		{
//			flag = 0;
//		}
//		while (a[i] != '\0')
//		{
//			if ((a[i] >= '0'&&a[i] <= '9') || (a[i] >= 'a'&&a[i] <= 'z') || (a[i] >= 'A'&&a[i] <= 'Z') || a[i] == '_')
//			{
//				i++;
//				continue;
//			}
//			else
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag)
//			cout << "yes" << endl;
//		else
//			cout << "no" << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//char a[110];
//int main()
//{
//	while (cin >> a)
//	{
//		int i = 1;
//		int max = a[0];
//		while (a[i] != '\0')
//		{
//			if (a[i] > max)
//			{
//				max = a[i];
//			}
//			i++;
//		}
//		i = 0;
//		while (a[i] != '\0')
//		{
//			if (a[i] == max)
//				cout << a[i] << "(max)";
//			else
//				cout << a[i];
//			i++;
//		}
//		cout << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	char a[110];
//	while (gets(a))
//	{
//
//	}
//	return 0;
//
//}

#include<iostream>
using namespace std;
int n, a[10101];
int main()
{
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int sum = 1;
		for (int i = 0; i < n; i++)
		{
			sum *= a[i];
		}
		int max = a[0];
		for (int i = 1; i < n; i++)
		{
			if (a[i] > max)
			{
				max = a[i];
			}
		}
		for (int i = max; i <= sum; i++)
		{
			int flag = 1;
			for (int j = 0; j < n; j++)
			{
				if (i%a[j])
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}