#define _CRT_SECURE_NO_WARNINGS 1
//#include<cmath>
//#include<iostream>
//using namespace std;
//int arr[15],ans,n;
//int a[100],b[100], c[100], d[100];
////bool check(int cur, int num)
////{
////	/*for (int i = 1; i < cur; i++)
////	{
////		if (arr[i] == num || abs(cur - i) == abs(arr[i] - num))
////			return false;
////	}*/
////	
////	return true;
////}
//void dfs(int cur)
//{
//	if (cur == n + 1)
//	{
//		ans++;
//		if (ans < 4)
//		{
//			for (int i = 1; i <= n; i++)
//			{
//				cout << a[i];
//				if (i< n)
//					printf(" ");
//			}
//			printf("\n");
//
//		}
//		return;
//	}
//	for (int j = 1; j <= n; j++)
//	{
//		if (!b[j] && !c[cur + j] && !d[cur - j + n])
//		{
//			a[cur] = j;
//			b[j] = 1;
//			c[cur + j] = 1;
//			d[cur - j + n] = 1;
//			dfs(cur + 1);
//			a[cur] = 0;
//			b[j] = 0;
//			c[cur + j] = 0;
//			d[cur - j + n] = 0;//回溯体现
//		}
//	}
//}
//int main()
//{
//	cin >> n;
//	dfs(1);
//	cout << ans << endl;
//	return 0;
//}


//#include<iostream>
//#include<algorithm>
//using namespace std;
//int n,m, vis[100][100],len,startx,starty,endx, endy, ans, T, broad[100][100], dis[2][4] = { 1,0,-1,0,0,1,0,-1 };
//bool check(int tx, int ty)
//{
//	if (tx > n || ty > m || tx < 1 || ty < 1 || vis[tx][ty] || broad[tx][ty])
//		return false;
//	return true;
//}
//void dfs(int curx, int cury)
//{
//	if (curx == endx && cury == endy)
//	{
//		ans++;
//		return;
//	}
//	for (int i = 0; i < 4; i++)
//	{
//		int tx = curx + dis[0][i];
//		int ty = cury + dis[1][i];
//		if (check(tx, ty))
//		{
//			vis[tx][ty] = 1;
//			dfs(tx, ty);
//			vis[tx][ty] = 0;//回溯体现
//		}
//	}
//}
//int main()
//{
//	cin >> n >> m >> T>>startx>>starty>>endx>>endy;
//	vis[startx][starty] = 1;//起点要手动标记已访问
//	while (T--)
//	{
//		int x, y;
//		cin >> x>> y;
//		broad[x][y]++;
//	}
//	dfs(startx, starty);
//	cout << ans << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int n;
//long long k, w[25];
//void bfs()
//{
//
//}
//int main()
//{
//	cin >> n >> k;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> w[i];
//	}
//	bfs();
//	return 0;
//}

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct point
{
	int x, y, step;
}st;
queue<point> q;
int vis[100010];
int n, m;
int flat;
int bfs()
{
	memset(vis, 0, sizeof(vis));
	vis[st.x] = 1;
	q.push(st);
	while (!q.empty())
	{
		point now = q.front();
		if (now.x == m)
		{
			return now.step;
		}
		q.pop();
		for (int j = 0; j < 3; j++)
		{
			point next = now;
			if (j == 0)
			{
				next.x = next.x - 1;
			}
			else if (j == 1)
			{
				next.x = next.x + 1;
			}
			else if (j == 2)
			{
				next.x = next.x * 2;
			}
			++next.step;
			if (next.x == m)
			{
				return next.step;
			}
			if (next.x >= 0 && next.x <= 100000 && !vis[next.x])
			{
				vis[next.x] = 1;
				q.push(next);
			}
		} 
	}
}
int main()
{
	while (scanf("%d%d", &n, &m))
	{
		st.x = n;
		st.step = 0;
		printf("%d\n", bfs());
	}
	return 0;
}