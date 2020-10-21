#define _CRT_SECURE_NO_WARNINGS 
//#include<iostream>
//using namespace std;
//long long n, m, x;
//long long a[10000000];
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//	}
//	for (int i = 1; i <= m; i++)
//	{
//		cin >> x;
//		cout << a[x] << endl;
//	}
//	return 0;
//}

//#include<stdio.h>
//int three(int n)
//{
//	return n * n * n;
//}
//int main()
//{
//	int n;
//	int a, b, c;
//	
//	scanf("%d", &n);
//	int ret = n;
//	if (n < 100||n>999)
//		printf("ERROR");
//	else
//	{
//		a = n / 100;
//		n %= 100;
//		b = n / 10;
//		n %= 10;
//		c = n;
//		if (three(a) + three(b) + three(c) == ret)
//			printf("1");
//		else
//			printf("0");
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char c;
//	scanf("%c", &c);
//	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
//		printf("ALPHA");
//	else
//		printf("NO");
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a, b, c;
//	scanf("%d-%d-%d", &a, &b, &c);
//	if (a % b == 3 && b % c == 3)
//	{
//		printf("YES");
//	}
//	else
//		printf("NO");
//	return 0;
//}

//#include<stdio.h>
//int min(int a, int b)
//{
//	if (a < b)
//		return a;
//	else
//		return b;
//}
//int main()
//{
//	int M, N;
//	scanf("%d%d", &M, &N);
//	printf("%d", min((M - 1 + (N - 1) * M), (N - 1 + (M - 1) * N)));
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	long n, m;
//	cin >> n >> m;
//	long ans;
//	double pmax = 0;
//	double p;
//	double sum;
//	if (n == 1 && m == 1)
//		ans = 1;
//	else
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			if (i == m)
//				continue;
//			if (i < m)
//			{
//				sum = i + (m - i + 1) / 2 - 1;
//				p = sum / n;
//				if (p > pmax)
//				{
//					pmax = p;
//					ans = i;
//				}
//			}
//			else
//			{
//				sum = n - i + 1 + (i - m + 1) / 2 - 1;
//				p = sum / n;
//				if (p > pmax)
//				{
//					pmax = p;
//					ans = i;
//				}
//			}
//
//		}
//	}
//	cout << ans;
//	return 0;
//}


//
//#include<iostream>
//using namespace std;
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	int paper = n / (2 * (1 + k));
//	int book = k * paper;
//	int leave = n - (book+paper);
//	cout << paper << " " << book << " " << leave;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int min(int a, int b)
//{
//	if (a < b)
//		return a;
//	else
//		return b;
//}
//int max(int a, int b)
//{
//	if (a > b)
//		return a;
//	else
//		return b;
//}
//int main()
//{
//	int l, r, a;
//	cin >> l >> r >> a;
//	int minn = min(l, r);
//	int maxn = max(l, r);
//	if (minn + a <= maxn)
//	{
//		cout << 2 * (minn + a);
//	}
//	else
//	{
//		cout << ((minn + a - maxn) / 2 + maxn) * 2;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	long n, k, t;
//	cin >> n >> k >> t;
//	if (t <= k)
//	{
//		cout << t;
//	}
//	else if(t>k&&t<=n)
//	{
//		cout << k;
//	}
//	else
//	{
//		cout << k - (t - n);
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	long n;
//	cin >> n;
//	int a[100001];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	int cur = 0;
//	while ()
//	{
//		int sumfirst = 0,sumsecond=0;
//		
//	}
//	
//	return 0;
//}

