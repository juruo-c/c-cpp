//#include<iostream>
//#include<vector>
//#include<cstring>
//#include<algorithm>
//#include<cmath>
//
//using namespace std;
//const int N = 1000 + 10;
//
//struct edge
//{
//    int u,v;
//    double w;
//};
//
//vector<edge> e;
//int d[N];
//int n,q;
//bool vis[N];
//vector<pair<int,int> > loca;
//
//bool cmp(edge a,edge b)
//{
//    return a.w < b.w;
//}
//
//struct Sub
//{
//    int num,cost,city[N];
//}sub[10];
//
//void init()
//{
//    memset(d,0x3f,sizeof(d));
//    memset(vis,0,sizeof(vis));
//    for(int i = 1;i <= n;i ++){
//        e[i].clear();
//    }
//}
//
//double distan(int a,int b,int c,int d)
//{
//    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
//}
//
//int fa[N];
//int getfa(int i)
//{
//    return fa[i] == i ? i : fa[i] == getfa(fa[i]);
//}
//
//int Kruskal()
//{
//    int ans = 0;
//    for(int i = 0;i < n;i ++) p[i] = i;
//
//}
//
//
//int main()
//{
//    int T; cin >> T;
//    while(T --){
//        //输入
//        cin >> n >> q;
//        init();
//        for(int i = 0;i < q;i ++){
//            cin >> sub[i].num >> sub[i].cost;
//            for(int j = 0;j < sub[i].num;j ++){
//                cin >> sub[i].city[j];
//            }
//        }
//        for(int i = 0;i < n;i ++){
//            int x,y;cin >> x >> y;
//            loca.push_back(make_pair(x,y));
//        }
//        //算两点距离并建图
//        for(int i = 0;i < loca.size();i ++){
//            for(int j = 0;j < loca.size();j ++){
//                if(i != j){
//                    double dis = distan(loca[i].first,loca[i].first,loca[i].second,loca[j].first,loca[j].second);
//                    e.push_back(edge{i,j,dis});
//                }
//            }
//        }
//
//        int sum = Kruskal();
//
//    }
//    return 0;
//}

//#include<iostream>
//#include<set>
//
//using namespace std;
//const int N = 1e3 + 10;
//int fa[N];bool m;
//
//int getfa(int i)
//{
//    return fa[i] == i ? i : fa[i] = getfa(fa[i]);
//}
//
//int main()
//{
//    int t;cin >> t;
//    while(t --){
//        int n;cin >> n;
//        for(int i = 1;i <= n;i ++)fa[i] = i;
//
//        for(int i = 1;i <= n;i ++){
//            for(int j = 1;j <= n;j ++){
//                cin >> m;
//                if(i != j && m){
//                    int fi = getfa(i);
//                    int fj = getfa(j);
//                    if(fi != fj) fa[fi] = fj;
//                }
//            }
//        }
//
//        int cnt = 0;
//        set<int> p;
//        for(int i = 1;i <= n;i ++){
//            int fi = fa[i];
//            if(!p.count(fi)){
//                cnt ++;
//                p.insert(fi);
//            }
//        }
//
//        if(cnt == 1) cout << "Yes" << endl;
//        else cout << "No" << endl;
//
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//
//using namespace std;
//const int N = 1e3 + 10;
//int m[N][N];bool vis[N];
//int n;
//void dfs(int u)
//{
//    vis[u] = 1;
//    for(int i = 1;i <= n;i ++){
//        if(!vis[i] && m[u][i]){
//            dfs(i);
//        }
//    }
//}
//
//int main()
//{
//    int t; cin >> t;
//    while(t --){
//        cin >> n;
//        for(int i = 1;i <= n;i ++)
//            for(int j = 1;j <= n;j ++)
//            cin >> m[i][j];
//        int flag = 1;
//
//        for(int i = 1;i <= n;i ++){
//            memset(vis,0,sizeof(vis));
//            dfs(i);
//            for(int i = 1;i <= n;i ++){
//                if(!vis[i]) flag = 0;
//            }
//            if(!flag) break;
//        }
//
//        if(flag) cout << "Yes" << endl;
//        else cout << "No" << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//
//using namespace std;
//const int N = 1e3 + 10;
//int g[N][N];
//int ans[N][N];
//int n;
//int vis[N];
//
//void dfs(int u,int ori)
//{
//
//    for(int i = 1;i <= n;i ++){
//        if(!vis[i] && g[u][i]){
//            vis[i] = 1;
//            ans[ori][i] = 1;
//            dfs(i,ori);
//        }
//    }
//}
//
//int main()
//{
//    cin >> n;
//    for(int i = 1;i <= n;i ++)
//        for(int j = 1;j <= n;j ++)
//        cin >> g[i][j];
//
//    for(int i = 1;i <= n;i ++){
//        memset(vis,0,sizeof(vis));
//        dfs(i,i);
//    }
//
//    for(int i = 1;i <= n;i ++){
//        for(int j = 1;j <= n;j ++){
//            cout << ans[i][j];
//            if(j < n) cout << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<map>
//#include<vector>
//
//using namespace std;
//const int N = 1e3 + 10;
//int n,m,flag;
//int vis[N];
//struct edge
//{
//    int v;
//    double w;
//};
//vector<edge> e[N];
//double ans = 1.0;
//
//void dfs(int u)
//{
//    for(auto x : e[u]){
//        int v = x.v;
//        double w = x.w;
//        if(vis[v] < 0){
////            cout << ans * w << endl;
//            if(ans * w > 1.0) flag = 1;
//        }
//        else if(!vis[v]){
//            ans *= w;
//            vis[v] = 1;
//            dfs(v);
//            vis[v] = 0;
//            ans /= w;
//        }
//    }
//}
//
//int main()
//{
//    int T; cin >> T;
//    while(T --){
//        map<string,int> id;
//        cin >> n >> m;string s;
//        for(int i = 1;i <= n;i ++)e[i].clear();
//        for(int i = 1;i <= n;i ++){
//            cin >> s;
//            id[s] = i;
//        }
//        while(m --){
//            string u,v;
//            double w;
//            cin >> u >> w >> v;
////            cout << id[u] << "      " << id[v] << endl;
//            e[id[u]].push_back(edge{id[v],w});
//        }
////
//        for(int i = 1;i <= n;i ++){
//            cout << i << ": ";
//            for(auto x : e[i]){
//                cout << x.v << " " << x.w << ",";
//            }
//        }
//
//        flag = 0;
//
//        for(int i = 1;i <= n;i ++){
//            memset(vis,0,sizeof(vis));
//            ans = 1;
//            vis[i] = -1;
//            dfs(i);
//            vis[i] = 0;
//            if(flag) break;
//        }
//
//        if(flag) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<vector>
//#include<cstdio>
//#include<cstdlib>
//
//using namespace std;
//const int N = 110;
//int G[N][N];
//int fa[N];
//int n,q,cnt;
//struct edge
//{
//    int u,v,w;
//}e[N * N];
//
//int getf(int i)
//{
//    return i == fa[i] ? i : fa[i] = getf(fa[i]);
//}
//
//bool cmp(edge a,edge b)
//{
//    return a.w < b.w;
//}
//
//int kruskal()
//{
//    int ans = 0;
//    sort(e + 1,e + cnt + 1,cmp);
//    for(int i = 1;i <= cnt;i ++){
//        int x = getf(e[i].u);
//        int y = getf(e[i].v);
//        if(x != y){
//            ans += e[i].w;
//            fa[x] = y;
//        }
//    }
//    return ans;
//}
//
//int main()
//{
//    while(cin >> n){
//        cnt = 0;
//        for(int i = 1;i <= n;i ++)
//            for(int j = 1;j <= n;j ++)
//            cin >> G[i][j];
//        for(int i = 1;i <= n;i ++)
//            for(int j = i + 1;j <= n;j ++)
//            {
//                e[++cnt].u = i;
//                e[cnt].v = j;
//                e[cnt].w = G[i][j];
//            }
//
//        for(int i = 1;i <= n;i ++)fa[i] = i;
//
//        cin >> q;
//        while(q --){
//            int u,v;
//            cin >> u >> v;
//            int fu = getf(u);
//            int fv = getf(v);
//            if(fu != fv) fa[fu] = fv;
//        }
//
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
//const int N = 1e3 + 10;
//
//int n,m;
//int fa[N];
//struct edge
//{
//    int u,v;
//    double w;
//}e[N * N];
//int cnt,num;
//pair<int,int> loca[N];
//
//double distan(int a,int b,int c,int d)
//{
//    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
//}
//
//int findf(int i)
//{
//    return i == fa[i] ? i : fa[i] = findf(fa[i]);
//}
//
//bool cmp(edge a,edge b)
//{
//    return a.w < b.w;
//}
//
//double solve()
//{
//    double ans = 0;
//    for(int i = 0;i < n;i ++)fa[i] = i;
//    sort(e + 1,e + 1 + cnt,cmp);
//    for(int i = 1;i <= cnt;i ++){
//        int x = findf(e[i].u);
//        int y = findf(e[i].v);
//        if(x != y)
//        {
//            fa[x] = y;
//            num ++;
//        }
//        if(num == n - m + 1){
//            ans = e[i].w;
//            break;
//        }
//    }
//    return ans;
//}
//
//int main()
//{
//    cin >> n >> m;
//    for(int i = 0;i < n;i ++){
//        cin >> loca[i].first >> loca[i].second;
//    }
//
//    for(int i = 0;i < n;i ++){
//        for(int j = i + 1;j < n;j ++){
//            e[++cnt].u = i;
//            e[cnt].v = j;
//            e[cnt].w = distan(loca[i].first,loca[i].second,loca[j].first,loca[j].second);
//        }
//    }
//
//    printf("%.2lf\n",solve());
//
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<cmath>
//#include<algorithm>
//
//using namespace std;
//typedef pair<double,double> pdd;
//const int N = 110;
//struct edge
//{
//    int u,v;
//    double w;
//}e[N * N];
//
//int n,cnt,fa[N];
//pair<pdd,pdd> a[N];
//
//int getf(int x)
//{
//    return x == fa[x] ? x : fa[x] = getf(fa[x]);
//}
//
//typedef double d;
//d distan(d a,d b,d c,d a1,d b1,d c1)
//{
//    return sqrt((a - a1) * (a - a1) + (b - b1) * (b - b1) + (c - c1) * (c - c1));
//}
//
//bool cmp(edge a,edge b)
//{
//    return a.w < b.w;
//}
//double kruskal()
//{
//    double ans = 0;
//    sort(e + 1,e + 1 + cnt,cmp);
//    for(int i = 1;i <= cnt;i ++){
//        int x = getf(e[i].u);
//        int y = getf(e[i].v);
//        if(x != y){
//            ans += e[i].w;
//            fa[x] = y;
//        }
//    }
//    return ans;
//}
//
//int main()
//{
//    while(cin >> n && n){
//        cnt = 0;
//        for(int i = 0;i < n;i ++)
//            cin >> a[i].first.first >> a[i].first.second >> a[i].second.first >> a[i].second.second;
//
//        for(int i = 0;i < n;i ++)fa[i] = i;
//
//        for(int i = 0;i < n;i ++){
//            for(int j = i + 1;j < n;j ++){
//                double dis = distan(a[i].first.first,a[i].first.second,a[i].second.first,a[j].first.first,a[j].first.second,a[j].second.first);
//                if(dis <= a[i].second.second + a[j].second.second){
//                    int fi = getf(i);int fj = getf(j);
//                    if(fi != fj) fa[fi] = fj;
//                }
//                else{
//                    e[++cnt].u = i;
//                    e[cnt].v = j;
//                    e[cnt].w = dis - a[i].second.second - a[j].second.second;
//                }
//            }
//        }
//        printf("%.3lf\n",kruskal());
//    }
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 1e3 + 10;
//
//int n,a[N],G[N][N],cnt;
//int fa[N];
//struct edge
//{
//    int u,v,w;
//}e[N * N];
//
//int findf(int x)
//{
//    return x == fa[x] ? x : fa[x] = findf(fa[x]);
//}
//
//bool cmp(edge a,edge b)
//{
//    return a.w < b.w;
//}
//
//int kruskal()
//{
//    int ans = 0;
//    sort(e + 1,e + cnt + 1,cmp);
//    for(int i = 1;i <= cnt;i ++){
//        int x = findf(e[i].u);
//        int y = findf(e[i].v);
//        if(x != y){
//            ans += e[i].w;
//            fa[x] = y;
//        }
//    }
//    return ans;
//}
//
//int main()
//{
//    int t;cin >> t;
//    while(t --){
//        cnt = 0;
//        cin >> n;
//        for(int i = 0;i < n;i ++) cin >> a[i];
//        for(int i = 0;i < n;i ++)
//            for(int j = 0;j < n;j ++)
//            cin >> G[i][j];
//
//        for(int i = 0;i < n;i ++) fa[i] = i;
//
//        for(int i = 0;i < n;i ++){
//            for(int j = i + 1;j < n;j ++){
//                e[++cnt].u = i;
//                e[cnt].v = j;
//                e[cnt].w = a[i] + a[j] + G[i][j];
//            }
//        }
//
//        cout << kruskal() << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<queue>
//#include<cstring>
//#include<algorithm>
//#include<vector>
//#include<map>
//
//using namespace std;
//const int N = 1e3 + 10;
//
//int n,G[N][N];
//map<string,int> vertex;
//struct edge
//{
//    int u,v,w;
//};
//vector<edge> g[N];
//int d[N];
//
//struct node
//{
//    int d,u;
//    bool operator < (const node& b)const{
//        return d > b.d;
//    }
//};
//
//bool vis[N];edge p[N];
//void dijkstra(int s)
//{
//    priority_queue<node> q;
//    d[s] = 0;
//    memset(vis,0,sizeof(vis));
//    q.push((node){0,s});
//    while(!q.empty()){
//        node x = q.top();q.pop();
//        int u = x.u;
//        if(vis[u]) continue;
//        vis[u] = 1;
//        for(int i = 0;i < g[u].size();i ++){
//            int v = g[u][i].v;
//            int w = g[u][i].w;
//            if(d[v] > d[u] + w){
//                d[v] = d[u] + w;
//                p[v] = g[u][i];
//                q.push((node){d[v],v});
//            }
//        }
//    }
//}
//
//string findc(int i)
//{
//    for(auto x : vertex){
//        if(x.second == i)
//            return x.first;
//    }
//}
//
//int main()
//{
//    int t;cin >> t;
//    while(t --){
//        cin >> n;vertex.clear();
//        for(int i = 0;i < n;i ++)g[i].clear();
//        for(int i = 0;i < n;i ++){
//            string ch;cin >> ch;
//            vertex[ch] = i;
//        }
//        for(int i = 0;i < n;i ++){
//            for(int j = 0;j < n;j ++){
//                cin >> G[i][j];
//                if(G[i][j]) g[i].push_back(edge{i,j,G[i][j]});
//            }
//        }
//        string s;cin >> s;
//
//        memset(d,0x3f,sizeof(d));
//        dijkstra(vertex[s]);
//
//        int tmp = vertex[s];
//
//        for(int i = 0;i < n;i ++){
//            vector<string> path;
//            if(i == tmp) continue;
//            if(d[i] == 0x3f3f3f3f){
//                cout << findc(tmp) << "-" << findc(i) << "--" << 1 << endl;
//                continue;
//            }
//            cout << findc(tmp) << "-" << findc(i) << "-" << d[i];
//            cout << "----[";
//            int j = i;
//            path.push_back(findc(p[j].v));
//            while(1){
//                int u = p[j].u;
//                path.push_back(findc(u));
//                j = u;
//                if(j == tmp)break;
//            }
//            for(int i = path.size() - 1;i >= 0;i --){
//                cout << path[i] << " ";
//            }
//            cout << "]\n";
//        }
//    }
//    return 0;
//}

//#include<iostream>
//#include<vector>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//const int N = 1e5 + 10;
//struct edge
//{
//    int v,w;
//};
//int n,m,d[N];
//vector<edge> g[N];
//
//struct node
//{
//    int d,u;
//    bool operator < (const node& b) const{
//        return d > b.d;
//    }
//};
//bool vis[N];
//void dijkstra(int s)
//{
//    memset(d,0x3f,sizeof(vis));
//    memset(vis,0,sizeof(vis));
//    priority_queue<node> q;
//    d[s] = 0;
//    q.push((node){0,s});
//    while(!q.empty()){
//        node x = q.top();q.pop();
//        int u = x.u;
//        if(vis[u]) continue;
//        vis[u] = 1;
//        for(int i = 0;i < g[u].size();i ++){
//            int v = g[u][i].v;
//            int w = g[u][i].w;
//            if(d[v] > d[u] + w){
//                d[v] = d[u] + w;
//                q.push((node){d[v],v});
//            }
//        }
//    }
//}
//
//int main()
//{
//    cin >> n >> m;
//    for(int i = 0;i < m;i ++){
//        int u,v,w;
//        cin >> u >> v >> w;
//        g[u].push_back((edge){v,w});
//        g[v + n].push_back((edge){u + n,w});
//    }
//
//    dijkstra(1);
//
//    long long ans = 0;
//    for(int i = 2;i <= n;i ++){
//        ans += d[i];
//    }
//
//    dijkstra(1 + n);
//
//    for(int i = 2 + n;i <= n * 2;i ++){
//        ans += d[i];
//    }
//
//
//    cout << ans << endl;
//
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//
//using namespace std;
//const int N = 1e3 + 10;
//int dis[N][N];
//int n,m;
//
//int main()
//{
//    memset(dis,0x3f,sizeof(dis));
//    cin >> n >> m;
//    for(int i = 0,x,y,z;i < m;i ++){
//        cin >> x >> y >> z;
//        dis[x][y] = min(dis[x][y],z);
//    }
//
//    for(int k = 1;k <= n;k ++){
//        for(int i = 1;i <= n;i ++){
//            for(int j = 1;j <= n;j ++){
//                dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
//            }
//        }
//    }
//
//    int ans = 0;
//    for(int i = 2;i <= n;i ++){
//        ans += (dis[i][1] + dis[1][i]);
//    }
//    cout << ans << endl;
//
//    return 0;
//}

#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
const int N = 1e6 + 10;
const int mod = 1e5 + 3;

int n,m,d[N];
struct edge
{
    int v,w;
};
vector<edge> g[N];
struct node
{
    int d,u;
    bool operator < (const node& b) const{
        return d > b.d;
    }
};

int ans[N];
bool vis[N];
void dijkstra(int s)
{
    priority_queue<node> q;
    memset(d,0x3f,sizeof(d));
    d[s] = 0;
    q.push((node){0,s});
    while(!q.empty()){
        node x = q.top();q.pop();
        int u = x.u;
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = 0;i < g[u].size();i ++){
            int v = g[u][i].v;
            int w = g[u][i].w;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                ans[v] = ans[u];
                q.push((node){d[v],v});
            }
            else if(d[v] == d[u] + w){
                ans[v] += ans[u];
                ans[v] %= mod;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0,u,v;i < m;i ++){
        cin >> u >> v;
        g[u].push_back((edge){v,1});
        g[v].push_back((edge){u,1});
    }
    ans[1] = 1;
    dijkstra(1);

    for(int i = 1;i <= n;i ++){
        cout << ans[i] << endl;
    }
    return 0;
}









