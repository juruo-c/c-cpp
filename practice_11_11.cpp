#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int T, M, v[100], w[100],F[1000];
//	cin >> T >> M;
//	for (int i = 1; i <= M; i++)
//	{
//		cin >> w[i] >> v[i];
//	}
//	for (int i = 0; i <= T; i++)
//	{
//		F[i] = 0;
//	}
//	for (int i = 1; i <= M; i++)
//	{
//		for (int j = T; j >= w[i]; j--)
//		{
//			F[j] = max(F[j], F[j - w[i]] + v[i]);
//		}
//	}
//	cout << F[T] << endl;
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//bool cmp(int a, int b)
//{
//	return a > b;
//}
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	int a[1005];
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//	}
//	sort(a+1, a + n+1,cmp);
//	cout << a[k]<<endl;
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//struct S
//{
//	long long id;
//	long long score;
//}s[100005];
//bool cmp(struct S a, struct S b)
//{
//	if (a.score == b.score)
//		return a.id < b.id;
//	else
//		return a.score > b.score;
//}
//long long ans[100005];
//int T;
//long n;
//int main()
//{
//	cin >> T;
//	while (T--)
//	{
//		cin >> n;
//		for (long i = 0; i < n; i++)
//		{
//			cin >> s[i].id;
//		}
//		for (long i = 0; i < n; i++)
//		{
//			cin >> s[i].score;
//		}
//		sort(s, s + n, cmp);
//		for (long i = 0; i < n; i++)
//		{
//			ans[s[i].id] = n - i;
//		}
//		for (long i = 1; i <= n; i++)
//		{
//			cout << ans[i] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//long long a[1005];
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	sort(a, a + n);
//	for (int i = 0; i < n; i++)
//	{
//		cout << a[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//long long a[100005];
//long ans[100005];
//int main()
//{
//	long n;
//	cin >> n;
//	for (long i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	for (long i = 0; i < n; i++)
//	{
//		int cnt = 0;
//		for (long j = i + 1; j < n; j++)
//		{
//			
//			if (a[j] < a[i])
//			{
//				cnt++;
//			}
//		}
//		ans[i] = cnt;
//	}
//	long long sum = 0;
//	for (long i = 0; i < n; i++)
//	{
//		sum += ans[i];
//	}
//	cout << sum<<endl;
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int v[1005], w[1005], F[1005], N, V;
//	cin >> N >> V;
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> v[i] >> w[i];
//	}
//	for (int i = 0; i <= V; i++)
//	{
//		F[i] = 0;
//	}
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = v[i]; j <= V; j++)
//		{
//			F[j] = max(F[j],F[j-v[i]]+w[i]);
//		}
//	}
//	cout << F[V]<<endl;
//	return 0;
//}