//
// Created by 19116 on 2021/1/5.
//

//#include<iostream>
//
//using namespace std;
//const int N = 110;
//int g[N][N];
//int n,m;
//
//void floyd()
//{
//    for(int k = 1;k <= n;k ++)
//        for(int i = 1;i <= n;i ++)
//            for(int j = 1;j <= n;j ++)
//                g[i][j] = g[i][j] || (g[i][k] && g[k][j]);
//}
//int main()
//{
//    cin >> n >> m;
//    for(int i = 0;i < m; i++){
//        int u,v;
//        cin >> u >> v;
//        g[u][v] = 1;
//    }
//
//    floyd();
//
//    int ans = 0;
//    for(int i = 1;i <= n;i ++){
//        int sum = 0;
//        for(int j = 1;j <= n;j ++){
//            if(i == j)continue;
//            if(g[i][j] || g[j][i])sum ++;
//        }
//        if(sum == n - 1)ans ++;
//    }
//
//    cout << ans << endl;
//
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 150 + 10;
//int g[N][N];
//int n;
//int main()
//{
//    int n;
//    cin >> n;
//    for(int i = 0;i < n;i ++){
//
//    }
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<queue>
//#include<vector>
//
//using namespace std;
//const int N = 1e3 + 10;
//const int INF = 0x3f3f3f3f;
//int n,m,x;
//struct edge
//{
//    int v,w;
//};
//vector<edge> g[N];
//bool vis[N];
//int dis[N][N],d[N];
//
//void floyd()
//{
//    for(int k = 1;k <= n;k ++){
//        for(int i = 1;i <= n;i ++){
//            for(int j = 1;j <= n;j ++){
//                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
//            }
//        }
//    }
//}
//
//struct node{
//    int d,s;
//    bool operator < (const node& b)const{
//        return d > b.d;
//    }
//};
//void dij(int s)
//{
//    priority_queue<node> q;
//    d[s] = 0;
//    q.push((node){0,s});
//    while(!q.empty()){
//        node x = q.top();q.pop();
//        int u = x.s;
//        if(vis[u])continue;
//        vis[u] = 1;
//        for(int i = 0;i < g[u].size();i++){
//            int v = g[u][i].v;
//            int w = g[u][i].w;
//            if(!vis[v] && d[v] > d[u] + w){
//                d[v] = d[u] + w;
//                q.push((node){d[v],v});
//            }
//        }
//    }
//}
//int main()
//{
//    cin >> n >> m >> x;
//    for(int i = 1;i <= n;i ++){
//        d[i] = INF;
//        for(int j = 1;j <= n;j ++){
//            if(i == j) dis[i][j] = 0;
//            else dis[i][j] = INF;
//        }
//    }
//    for(int i = 0;i < m;i ++){
//        int u,v,w;
//        cin >> u >> v >> w;
//        g[u].push_back((edge){v,w});
//        dis[u][v] = w;
//    }
//    floyd();
//    dij(x);
//
//    int maxx = 0;
//    for(int i = 1;i <= n;i ++){
//        maxx = max(dis[i][x] + d[i],maxx);
//    }
//
//    cout << maxx << endl;
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<queue>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e3 + 10;
//const int INF = 1e8;
//int n,m,x;
//int d[N],res[N];
//bool vis[N];
//int g[N][N],a[N][N];
//
//struct node{
//    int d,s;
//    bool operator < (const node& b)const {
//        return d > b.d;
//    }
//};
//void dij(int s){
//    priority_queue<node> q;
//    memset(vis,0,sizeof(vis));
//    for(int i = 1;i <= n;i ++)d[i] = INF;
//    d[s] = 0;
//    q.push((node){0,s});
//    while(!q.empty()){
//        int u = q.top().s;q.pop();
//        if(vis[u])continue;
//        vis[u] = true;
//        for(int i = 1;i <= n;i ++){
//            if(g[u][i] != INF && !vis[i] && d[i] > d[u] + g[u][i]){
//                d[i] = d[u] + g[u][i];
//                q.push((node){d[i],i});
//            }
//        }
//    }
//}
//int main()
//{
//
//    cin >> n >> m >> x;
//    for(int i = 1;i <= n;i ++)
//        for(int j = 1;j <= n;j ++)
//           g[i][j] = INF;
//
//    for(int i = 0;i < m;i ++){
//        int u,v,w;
//        cin >> u >> v >> w;
//        g[u][v] = w;
//    }
//    dij(x);
//    for(int i = 1;i <= n;i ++)res[i] += d[i];
//
//    for(int i = 1;i <= n;i ++)
//        for(int j = 1;j <= n;j ++)
//            a[j][i] = g[i][j];
//
//    for(int i = 1;i <= n;i ++)
//        for(int j = 1;j <= n;j ++)
//            g[i][j] = a[i][j];
//    dij(x);
//    int maxx = 0;
//    for(int i = 1;i <= n;i ++){
//        res[i] += d[i];
//        maxx = max(res[i], maxx);
//    }
////    for(int i = 1;i <= n;i ++)
////        cout << i << ": " << res[i] << endl;
//    cout << maxx << endl;
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<queue>
//
//using namespace std;
//const int N = 505;
//const int INF = 0x3f3f3f3f;
//int d[N][N];
//int res[N],inq[N];
//bool vis[N];
//int n,m,w;
//queue<int> q;
//bool spfa(int s){
//    memset(vis,0,sizeof(vis));
//    memset(res,0x3f,sizeof(res));
//    memset(inq,0,sizeof(inq));
//    q.push(s);
//    res[s] = 0;
//    inq[s] = 1;
//    vis[s] = 1;
//    while(!q.empty()){
//        int now = q.front();q.pop();
//        vis[now] = 0;
//        for(int i = 1;i <= n;i ++){
//            if(i == now)continue;
//            if(res[i] > res[now] + d[now][i]) {
//                res[i] = res[now] + d[now][i];
//                if(!vis[i]){
//                    vis[i] = 1;
//                    q.push(i);
//                    inq[i] ++;
//                    if(inq[i] > n)return true;
//                }
//            }
//        }
//    }
//    return false;
//}
//int main()
//{
//    int t; cin >> t;
//    while(t --){
//        memset(d,0x3f,sizeof(d));
//        cin >> n >> m >> w;
//        for(int i = 0;i < m;i ++){
//            int u,v,w;
//            cin >> u >> v >> w;
//            d[u][v] = d[v][u] = min(d[u][v], w);
//        }
//
//        for(int i = 0;i < w;i ++){
//            int u,v,w;
//            cin >> u >> v >> w;
//            d[u][v] = min(d[u][v], -w);
//        }
//
//        if(!spfa(1))cout << "NO" << endl;
//        else cout << "YES" << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<sstream>
//
//using namespace std;
//const int N = 110;
//const int INF = 0x3f3f3f3f;
//int n,g[N][N];
//
//void floyd()
//{
//    for(int k = 1;k <= n;k ++)
//        for(int i = 1;i <= n;i ++)
//            for(int j = 1;j <= n;j ++)
//                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
//}
//
//int main()
//{
//    cin >> n;
//    for(int i = 1;i <= n;i ++)
//        for(int j = 1;j <= n;j ++)
//            if(i == j)g[i][j] = 0;
//            else g[i][j] = INF;
//
//    for(int i = 1;i <= n;i ++){
//        for(int j = 1;j < i;j ++){
//            string s;cin >> s;
//            if(s != "x")
//            {
//                stringstream ss(s);
//                int w; ss >> w;
//                g[i][j] = g[j][i] = w;
//            }
//        }
//    }
//
//    floyd();
//
//    int maxx = 0;
//    for(int i = 1;i <= n;i ++)
//            maxx = max(maxx, g[1][i]);
//
//        cout << maxx << endl;
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//    int n ;cin >> n;
//    while(n --){
//        int k; cin >> k;
//        for(int i = k + 1;i <= 2 * k;i ++){
//            if((i * k) % (i - k) == 0)
//                cout << 1 << "/" << k << "=" << 1 << "/" << i * k /(i - k) << "+" << 1 << "/" << i << endl;
//        }
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//    char a[5],b[5];
//    pair<bool,bool> p[5];
//    while(1){
//        p[0].first = 1;p[0].second = 0;
//        for(int i = 1;i < 5;i ++){
//
//        }
//        int flag = 1;
//        for(int i = 0;i < 5;i ++){
//            if((!p[i].first && p[i].second) ||(!p[i].second && p[i].first))continue;
//            else flag = 0;
//        }
//        if(flag){
//            for(int i = 0;i < 5;i ++){
//
//            }
//            break;
//        }
//    }
//
//    int t; cin >> t;
//    while(t --){
//        for(int i = 0;i < 5;i ++)cin >> a[i];
//
//    }
//    return 0;
//}


#include<iostream>
#include<cstdio>
#include<map>

using namespace std;
const int N = 35;
int n,m;string s;
double d[N][N];

void floyd(){
    for(int k = 1;k <= n;k ++)
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= n;j ++)
                d[i][j] = max(d[i][j],d[i][k] * d[k][j]);
}

int main()
{
    int kase = 0;
    while(cin >> n && n){
        map<string,int> mp;
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= n;j ++)
                if(i == j )d[i][j] = 1;
                else d[i][j] = 0;
        for(int i = 1;i <= n;i ++){
            cin >> s;
            mp[s] = i;
        }
        cin >> m;
        for(int i = 0;i < m;i ++){
            string u,v;
            double w;
            cin >> u >> w >> v;
            d[mp[u]][mp[v]] = w;
        }

        floyd();
        int flag = 0;
        for(int i = 1;i <= n;i ++)
            if(d[i][i] > 1) flag = 1;

        if(flag ) printf("Case %d: Yes\n",++kase);
        else printf("Case %d: No\n",++kase);
    }
    return 0;
}