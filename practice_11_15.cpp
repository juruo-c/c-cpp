#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<queue>
//using namespace std;
//int vis[200010];
//int n, m;
//struct point
//{
//	int x, step;
//}st;
//int bfs()
//{
//	queue<point> q;
//	q.push(st);
//	while (!q.empty())
//	{
//		point now = q.front();
//		if (now.x == m)
//		{
//			return now.step;
//		}
//		q.pop();
//		for (int j = 0; j < 3; j++)
//		{
//			point next = now;
//			if (j == 0)
//			{
//				next.x++;
//			}
//			else if (j == 1)
//			{
//				next.x--;
//			}
//			else
//			{
//				next.x *= 2;
//			}
//			next.step++;
//			if (next.x == m)
//				return next.step;
//			if (next.x >= 0 && next.x <= 200000 && !vis[next.x])
//			{
//				vis[next.x] = 1;
//				q.push(next);
//			}
//		}
//	}
//}
//int main()
//{
//	while (~scanf("%d%d", &n, &m))
//	{
//		st.x = n;
//		st.step = 0;
//		printf("%d\n", bfs());
//	}
//	return 0;
//}

//#include<iostream>
//#include<queue>
//using namespace std;
//int n;
//long long k,w[25],vis[25];
//
//int flag,tag;
//int cnt;
//void dfs(long long ans,int i)
//{
//	if (ans == k)
//	{
//		flag = 1;
//		return;
//	}
//	if (flag || i > n)
//	{
//		return;
//	}
//	vis[i] = 1;
//	int tmp = tag;
//	tag = i;
//	dfs(ans + w[i], i + 1);
//	if (flag)
//		return;
//	tag = tmp;
//	vis[i] = 0;
//	dfs(ans, i + 1);
//}
//int main()
//{
//	cin >> n >> k;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> w[i];
//	}
//	dfs(0,0);
//	if (flag)
//	{
//		cout << "YES" << endl;
//		for (int i = 1; i <= n; i++)
//		{
//			if (vis[i])
//			{
//				if (i == tag)
//					cout << w[i] << endl;
//				else
//					cout << w[i] << " ";
//			}
//		}
//	}
//	else
//		cout << "NO" << endl;
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//int R, C,tx,ty, h[110][110], vis[110][110], stx, sty;
//int d[2][4] = { 1,0,-1,0,0,1,0,-1 };
//int ans, len;
//bool check_1(int x, int y)
//{
//	for (int i = 0; i < 4;i++)
//	{
//		int x_new =x +d[0][i];
//		int y_new =x +d[0][i];
//		if (!vis[x_new][y_new] && x_new > 0 && y_new > 0 && x_new < R&&y_new < C&&h[x_new][y_new] < h[x][y])
//			return false;
//	}
//	return true;
//}
//bool check_2(int tx, int ty, int curx, int cury)
//{
//	if (tx<0 || ty<0 || tx>R || ty>C || vis[tx][ty] || h[tx][ty] > h[curx][cury])
//	{
//		return false;
//	}
//	return true;
//}
//void dfs(int curx,int cury,int len)
//{
//	if (check_1(curx,cury))
//	{
//		ans = max(ans, len);
//	}
//	for (int i = 0; i < 4; i++)
//	{
//		tx = curx + d[0][i];
//		ty = cury + d[1][i];
//		if (check_2(tx, ty, curx, cury))
//		{
//			vis[tx][ty] = 1;
//			dfs(tx, ty, len + 1);
//			vis[tx][ty] = 0;
//		}
//	}
//}
//int main()
//{
//	cin >> R>> C;
//	for (int i = 1; i <= R; i++)
//	{
//		for (int j = 1; j <= C; j++)
//		{
//			cin >> h[i][j];
//		}
//	}
//	for (int i = 1; i <= R; i++)
//	{
//		for (int j = 1; j <= C; j++)
//		{
//			stx = i;
//			sty = j;
//			vis[stx][sty] = 1;
//			dfs(i, j, 1);
//			vis[stx][sty] = 0;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int n, m, a[110];
//int main()
//{
//	while (cin >> n >> m)
//	{
//		int i;
//		for (i = 1; i <= n; i++)
//		{
//			a[i] = i * 2;
//		}
//		int flag = 1;
//		for (i = 1; i <= n - m+1; i += m)
//		{
//			int sum = 0;
//			for (int j = i; j < i + m; j++)
//			{
//				sum += a[j];
//			}
//			if (flag)
//			{
//				cout << sum / m;
//				flag = 0;
//			}
//			else
//			cout <<" "<< sum / m;
//		}
//		if (i <= n)
//		{
//			int sum = 0;
//			int cnt = 0;
//			for (int j = i; j <= n; j++)
//			{
//				sum += a[j];
//				cnt++;
//			}
//			cout <<" "<< sum / cnt;
//		}
//		cout << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int n, a[110];
//int main()
//{
//	while (cin >> n && n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			cin >> a[i];
//		}
//		int min = a[0];
//		int k=0;
//		for (int i = 0; i < n; i++)
//		{
//			if (a[i] < min)
//			{
//				min = a[i];
//				k = i;
//			}
//		}
//		int tmp = a[0];
//		a[0] = a[k];
//		a[k] = tmp;
//		for (int i = 0; i < n; i++)
//		{
//			cout << a[i];
//			if (i < n - 1)
//			{
//				cout << " ";
//			}
//		}
//		cout << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//int n,a[110];
//bool cmp(int a, int b)
//{
//	return abs(a) > abs(b);
//}
//int main()
//{
//	while (cin >> n && n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			cin >> a[i];
//		}
//		sort(a, a + n, cmp);
//		for (int i = 0; i < n; i++)
//		{
//			cout << a[i];
//			if (i < n - 1)
//				cout << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int n, m,a[110];
//int main()
//{
//	while (cin >> n >> m)
//	{
//		if (!n && !m)
//		{
//			break;
//		}
//		for (int i = 0; i < n; i++)
//		{
//			cin >> a[i];
//		}
//		int flag = 0;
//		int k;
//		for (int i = 0; i < n-1; i++)
//		{
//			if (a[i]<=m&&a[i + 1]>=m)
//			{
//				flag = 1;
//				k = i + 1;
//			}
//		}
//		if (flag)
//		{
//			for (int i = n - 1; i >= k; i--)
//			{
//				a[i + 1] = a[i];
//			}
//			a[k] = m;
//			for (int i = 0; i <= n; i++)
//			{
//				cout << a[i];
//				if (i < n)
//					cout << " ";
//			}
//			cout << endl;
//		}
//		else
//		{
//			if (m <= a[0])
//			{
//				cout << m << " ";
//				for (int i = 0; i < n; i++)
//				{
//					cout << a[i];
//					if (i < n - 1)
//						cout << " ";
//				}
//				cout << endl;
//			}
//			else
//			{
//				for (int i = 0; i < n; i++)
//				{
//					cout << a[i] << " ";
//				}
//				cout << m << endl;
//			}
//		}
//		
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int n,a[60];
//int main()
//{
//	a[1] = 1;
//	a[2] = 2;
//	a[3] = 3;
//	a[4] = 4;
//	while (cin >> n && n)
//	{
//		for (int i = 5; i <= n; i++)
//		{
//			a[i] = a[i - 1] + a[i - 3];
//		}
//		cout << a[n] << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int maxn = 110;
//int h[maxn][maxn], dp[maxn][maxn];
//int n, m,ans;
//int d[2][4] = { 0,0,1,-1,1,-1,0,0 };
//bool check(int x, int y)
//{
//	if (x<1 || x>n || y<1 || y>m)
//		return false;
//	return true;
//}
//int dfs(int x, int y)
//{
//	if (dp[x][y])
//		return dp[x][y];
//	dp[x][y] = 1;
//	for (int i = 0; i < 4; i++)
//	{
//		int tx = x + d[0][i];
//		int ty = y + d[1][i];
//		if (!check(tx, ty))
//		{
//			continue;
//		}
//		if (h[x][y] <= h[tx][ty])
//			continue;
//		dfs(tx, ty);
//		dp[x][y] = max(dp[x][y], dp[tx][ty] + 1);
//	}
//	return dp[x][y];
//}
//int main()
//{
//	while (~scanf("%d%d", &n, &m))
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= m; j++)
//			{
//				cin >> h[i][j];
//			}
//		}
//		for (int i = 1; i <= n; i++)
//		{
//			
//			for (int j = 1; j <= m; j++)
//			{
//				if (!dp[i][j])
//				{
//					dfs(i, j);
//				}
//				ans = max(dp[i][j], ans);
//			}
//		}
//		cout << ans << endl;
//	}
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//int m, n;
//int main()
//{
//	while (cin >> m >> n)
//	{
//		int sum1 = 0;
//		int sum2 = 0;
//		int x = min(m, n);
//		int y = max(m, n);
//		for (int i = x; i <= y; i++)
//		{
//			if (i % 2)
//				sum1 += pow(i, 3);
//			else
//				sum2 += pow(i, 2);
//		}
//		cout << sum2 << " " << sum1 << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int n, a[110], b[6] = { 100,50,10,5,2,1 };
//int main()
//{
//	while (cin >> n&&n)
//	{
//		int cnt = 0;
//		for (int i = 1; i <= n; i++)
//		{
//			cin >> a[i];
//		}
//		for (int i = 1; i <= n; i++)
//		{
//			int j = 0;
//			while (a[i]>1)
//			{
//				if (a[i] / b[j])
//				{
//					cnt += a[i] / b[j];
//					a[i] %= b[j];
//				}
//				j++;
//			}
//			cnt += a[i];
//		}
//		cout << cnt << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//int m, n, a[1010][1010];
//int main()
//{
//	while (cin >> m >> n)
//	{
//		for (int i = 1; i <= m; i++)
//		{
//			for (int j = 1; j <= n; j++)
//			{
//				cin >> a[i][j];
//			}
//		}
//		int max = abs(a[1][1]);
//		int row = 1;
//		int col = 1;
//		for (int i = 1; i <= m; i++)
//		{
//			for (int j = 1; j <= n; j++)
//			{
//				if (abs(max) < abs(a[i][j]))
//				{
//					max = a[i][j];
//					row = i;
//					col = j;
//				}
//			}
//		}
//		cout << row << " " << col << " " << a[row][col] << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int n, m;
//double a[55][10], s[10];
//int main()
//{
//	while (cin >> n >> m)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= m; j++)
//			{
//				cin >> a[i][j];
//			}
//		}
//		for (int i = 1; i <= n; i++)
//		{
//			double sum = 0.0;
//			for (int j = 1; j <= m; j++)
//			{
//				sum += a[i][j];
//			}
//			printf("%.2lf", sum / m);
//			if (i < n)
//				printf(" ");
//		}
//		cout << endl;
//		for (int i = 1; i <= m; i++)
//		{
//			double sum = 0.0;
//			for (int j = 1; j <= n; j++)
//			{
//				sum += a[j][i];
//			}
//			s[i] = sum / n;
//			printf("%.2lf", sum / n);
//			if (i < m)
//				cout << " ";
//		}
//		cout << endl;
//		int cnt = 0;
//		for (int i = 1; i <= n; i++)
//		{
//			int j;
//			for (j = 1; j <= m; j++)
//			{
//				if (a[i][j] < s[j])
//					break;
//			}
//			if (j > m)
//			{
//				cnt++;
//			}
//		}
//		cout << cnt << endl<<endl;
//	}
//	return 0;
//}

#include<iostream>
using namespace std;
int n, k;
long long a[50];
int main()
{
	cin>>n>>k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	return 0;
}