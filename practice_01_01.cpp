//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//int n,m,cnt;
//const int N = 55;
//struct edge
//{
//    int u,v,w;
//    bool operator < (const edge& b) const {
//        return w < b.w;
//    }
//};
//vector<edge> e;
//int fa[N];
//int getf(int x)
//{
//    return x == fa[x] ? x : fa[x] = getf(fa[x]);
//}
//int kruskal()
//{
//    int ans = 0;
//    for(int i = 1;i <= n;i ++)fa[i] = i;
//    sort(e.begin(),e.end());
//    for(int i = 0;i < e.size();i++){
//        int fu = getf(e[i].u);
//        int fv = getf(e[i].v);
//        if(fu != fv){
//            fa[fu] = fv;
//            ans += e[i].w;
//        }
//    }
//    return ans;
//}
//
//int main()
//{
//    while(cin >> n && n){
//        cnt = 0;e.clear();
//        cin >> m;
//        for(int i = 0;i < m;i ++){
//            int u,v,w;
//            cin >> u >> v >> w;
//            e.push_back(edge{u,v,w});
//        }
//        cout << kruskal() << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<cmath>
//#include<cstdio>
//
//using namespace std;
//const int N = 110;
//int n,cnt;
//struct node
//{
//    double x,y,z,r;
//}node[N];
//
//struct edge
//{
//    int u,v;
//    double w;
//    bool operator < (const edge& a)const {
//        return w < a.w;
//    }
//}e[N * N];
//int fa[N];
//int getf(int x)
//{
//    return x == fa[x] ? x : fa[x] = getf(fa[x]);
//}
//
//double dis(double a,double b,double c,double d,double e,double f)
//{
//    return sqrt((a - d) * (a - d) + (b - e) * (b - e) + (c - f) * (c - f));
//}
//
//double kruskal()
//{
//    double ans = 0;
//    for(int i = 0;i < n;i ++)fa[i] = i;
//    for(int i = 0;i < n;i ++){
//        for(int j = i + 1;j < n;j ++){
//            double d = dis(node[i].x,node[i].y,node[i].z,node[j].x,node[j].y,node[j].z);
//            if(d <= node[i].r + node[j].r){
//                int fi = getf(i);int fj = getf(j);
//                if(fi != fj) fa[fi] = fj;
//            }
//            else
//                e[cnt ++] = edge{i,j,d - node[i].r - node[j].r};
//        }
//    }
//
//    sort(e,e + cnt);
//    for(int i = 0;i < cnt;i ++){
//        int fu = getf(e[i].u);
//        int fv = getf(e[i].v);
//        if(fu != fv){
//            fa[fu] = fv;
//            ans += e[i].w;
//        }
//    }
//
//    return ans;
//}
//
//int main()
//{
//    while(cin >> n && n){
//        cnt = 0;
//
//        for(int i = 0;i < n;i ++){
//            double x,y,z,r;
//            cin >> x >> y >> z >> r;
//            node[i].x = x,node[i].y = y,node[i].z = z,node[i].r = r;
//        }
//
//        printf("%.3lf\n",kruskal());
//    }
//    return 0;
//}

#include<iostream>
#include<algorithm>

using namespace std;
const int N = 110;
int g[N][N];int n,m;

struct edge
{
    int u,v,w;
    bool operator < (const edge& a)const{
        return w < a.w;
    }
}e[N * N];
int fa[N];int cnt;

int getf(int x)
{
    return x == fa[x] ? x : fa[x] = getf(fa[x]);
}

int kruskal()
{
    int ans = 0;

    sort(e,e + cnt);
    for(int i = 0;i < cnt;i ++){
        int fu = getf(e[i].u);
        int fv = getf(e[i].v);
        if(fu != fv){
            ans += e[i].w;
            fa[fu] = fv;
        }
    }

    return ans;
}

int main()
{
    cin >> n;
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < n;j ++){
            cin >> g[i][j];
        }
    }

    for(int i = 0;i < n;i ++){
        for(int j = i + 1;j < n;j ++){
            e[cnt ++] = edge{i,j,g[i][j]};
        }
    }
    for(int i = 0;i < n;i ++) fa[i] = i;
    cin >> m;
    for(int i = 0;i < m;i ++){
        int u,v;
        cin >> u >> v;
        int fu = getf(u);
        int fv = getf(v);
        if(fu != fv) fa[fu] = fv;
    }

    cout << kruskal() << endl;

    return 0;
}











