//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//const int N = 110;
//int n,m,cnt;
//int g[N][N];
//
//
//struct edge
//{
//    int u,v,w;
//    bool operator < (const edge& b)const{
//        return w < b.w;
//    }
//
//}e[N * N];
//
//int fa[N];
//int getf(int x)
//{
//    return x == fa[x] ? x : fa[x] = getf(fa[x]);
//}
//
//int kruskal()
//{
//    int ans = 0;
//
//    sort(e,e + cnt);
//
//    for(int i = 0;i < cnt;i ++){
//        int fu = getf(e[i].u);
//        int fv = getf(e[i].v);
//        if(fu != fv){
//            ans += e[i].w;
//            fa[fu] = fv;
//        }
//    }
//    return ans;
//}
//
//int main()
//{
//    cin >> n;
//    for(int i = 0;i < n;i ++)
//        for(int j = 0;j < n; j++)
//            cin >> g[i][j];
//
//    for(int i = 0;i < n;i ++)
//        for(int j = i + 1;j < n;j ++)
//        e[cnt ++] = edge{i + 1,j + 1,g[i][j]};
//
//    for(int i = 1;i <= n;i ++)fa[i] = i;
//
//    cin >> m;
//    for(int i = 0;i < m;i ++){
//        int u,v;cin >> u >> v;
//        int fu = getf(u);
//        int fv = getf(v);
//        if(fu != fv)fa[fu] = fv;
//    }
//    cout << kruskal() << endl;
//    return 0;
//}
//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//
//using namespace std;
//const int N = 2e3 + 10;
//int n,cnt;char a[N][8];
//
//struct edge
//{
//    int u,v,w;
//    bool operator < (const edge& b)const{
//        return w < b.w;
//    }
//}e[N * N];
//
//int dis(int i,int j)
//{
//    int ans = 0;
//    for(int k = 0;k < 7;k ++){
//        if(a[i][k] != a[j][k]) ans ++;
//    }
//    return ans;
//}
//
//int fa[N];
//int getf(int x)
//{
//    return x == fa[x] ? x : fa[x] = getf(fa[x]);
//}
//
//int kruskal()
//{
//    int ans = 0;
//    for(int i = 1;i <= n;i ++)fa[i] = i;
//
//    sort(e,e + cnt);
//    for(int i = 0;i < cnt;i ++){
//        int fu = getf(e[i].u);
//        int fv = getf(e[i].v);
//        if(fu != fv){
//            ans += e[i].w;
//            fa[fu] = fv;
//        }
//    }
//    return ans;
//}
//int main()
//{
//    while(cin >> n && n){
//        cnt = 0;
//        for(int i = 0;i < n;i ++) cin >> a[i];
//        for(int i = 0;i < n;i ++){
//            for(int j = i + 1;j < n;j ++){
//                e[cnt ++] = edge{i + 1,j + 1,dis(i,j)};
//            }
//        }
//
//        printf("The highest possible quality is 1/%d.\n",kruskal());
//    }
//    return 0;
//}

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;
const int N = 500 + 10;
const int M = N * N;
struct point
{
    double x,y;
}p[N];

struct edge
{
    int u,v;double dist;
    bool operator <  (const edge& b)const {
        return dist < b.dist;
    }
}e[M];

int n,s,fa[N],cnt;
int getf(int x)
{
    return x == fa[x] ? x : fa[x] = getf(fa[x]);
}

double dis(int i,int j)
{
    double x1 = p[i].x, y1 = p[i].y,x2 = p[j].x, y2 = p[j].y;
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double kruskal()
{
    double ans = 0;
    sort(e,e + cnt);
    int num = 0;
    for(int i = 0;i < cnt;i ++){
        int fu = getf(e[i].u);
        int fv = getf(e[i].v);
        if(fu != fv){
//            cout << fu << fv << endl;
            fa[fu] = fv;
            num ++;
            if( num >= n - s ){
                ans = e[i].dist;
                break;
            }
        }
    }
    return ans;
}

int main()
{
    int t,s;cin >> t;
    while(t -- ){
        cnt = 0;
        cin >> s >> n;
        for(int i = 0;i < n;i ++) fa[i] = i;
        for(int i = 0;i < n;i ++)cin >> p[i].x >> p[i].y;
        for(int i = 0;i < n;i ++){
            for(int j = i + 1;j < n;j ++){
                e[cnt ++] = edge{i,j,dis(i,j)};
            }
        }

//        for(int i = 0;i < cnt;i ++){
//            cout << e[i].dist << endl;
//        }

        printf("%.2lf\n",kruskal());
    }
    return 0;
}







