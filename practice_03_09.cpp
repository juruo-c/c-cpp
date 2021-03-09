//
// Created by 19116 on 2021/3/9.
//

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<vector>
//using namespace std;
//typedef long long ll;
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int n;cin >> n;
//        vector<int> x(n),y(n);
//        for(int i = 0;i < n;i ++){
//            cin >> x[i] >> y[i];
//        }
//        if(n % 2) cout << 1 << endl;
//        else{
//            sort(x.begin(),x.end());
//            sort(y.begin(),y.end());
//            int tx = x[n / 2] - x[n / 2 - 1] + 1;
//            int ty = y[n / 2] - y[n / 2 - 1] + 1;
//            cout << (ll)tx * (ll)ty << endl;
//        }
//    }
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//const int N = 1e5 + 10;
//typedef long long ll;
//struct edge{
//    int next,to,w;
//}e[N << 2];
//int head[N],cnt;
//void add(int u,int v,int w){
//    e[++ cnt].to = v;
//    e[cnt].next = head[u];
//    e[cnt].w = w;
//    head[u] = cnt;
//}
//int n,m;
//
//ll d[N];bool vis[N];
//int inq[N];
//bool spfa(int s){
//    queue<int> q;
//    q.push(s);vis[s] = 1;
//    while(!q.empty()){
//        int u = q.front();q.pop();
//        vis[u] = 0;
//        for(int i = head[u];i;i = e[i].next){
//            int v = e[i].to;
//            if(d[v] < d[u] + e[i].w){
//                d[v] = d[u] + e[i].w;
//                if(!vis[v]){
//                    vis[v] = 1;
//                    q.push(v);
//                    inq[v]++;
//                    if(inq[v] > n) return true;
//                }
//            }
//        }
//    }
//    return false;
//}
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 1;i <= m;i ++){
//        int a,b,c;
//        scanf("%d%d%d",&a,&b,&c);
//        if(a == 1) add(b,c,0),add(c,b,0);
//        else if(a == 2){
//            if(b == c){cout << - 1 << endl;return 0;}
//            add(b,c,1);
//        }
//        else if(a == 3) add(c,b,0);
//        else if(a == 4){
//            if(b == c){cout << - 1 << endl;return 0;}
//            add(c,b,1);
//        }
//        else add(b,c,0);
//    }
//    for(int i = n;i >= 1;i --) add(0,i,1);
//    if(spfa(0)){
//        cout << -1 << endl;
//    }
//    else {
//        ll ans = 0;
//        for(int i = 1;i <= n;i ++) ans += d[i];
//        cout << ans << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//const int N = 1e4 + 10,INF = 0x3f3f3f3f;
//struct edge{
//    int next,to,w;
//}e[N];
//int head[N],cnt;
//void add(int u,int v,int w){
//    e[++ cnt].next = head[u];
//    e[cnt].to = v;
//    e[cnt].w = w;
//    head[u] = cnt;
//}
//int n,m;
//int d[N],inq[N];
//bool vis[N];
//
//bool spfa(int s){
//    for(int i = 1;i <= n;i ++) d[i] = -INF;
//    queue<int> q;d[s] = 0;
//    q.push(s);vis[s] = 1;
//    while(!q.empty()){
//        int u = q.front();q.pop();
//        vis[u] = 0;
//        if(inq[u] == n - 1) return true;
//        inq[u] ++;
//        for(int i = head[u];i;i = e[i].next){
//            int v = e[i].to;
//            if(d[v] < d[u] + e[i].w){
//                d[v] = d[u] + e[i].w;
//                if(!vis[v]){
//                    q.push(v);
//                    vis[v] = 1;
//                }
//            }
//        }
//    }
//    return false;
//}
//int main(){
//    int tt;scanf("%d",&tt);
//    while(tt --){
//        scanf("%d%d",&n,&m);
//        memset(inq,0,sizeof(inq));
//        memset(vis,0,sizeof(vis));
//        memset(head,0,sizeof(head));
//        for(int i = 0;i < m;i ++){
//            int s,t,v;
//            scanf("%d%d%d",&s,&t,&v);
//            add(s - 1,t,v);
//            add(t,s - 1,-v);
//        }
//        bool fl = false;
//        for(int i = 0;i <= n;i ++){
//            if(!inq[i]){
//                if(spfa(i)){
//                    fl = true;
//                    break;
//                }
//            }
//        }
//        if(!fl) puts("true");
//        else puts("false");
//    }
//    return 0;
//}

//
//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//#include<cstring>
//#include<queue>
//
//using namespace std;
//const int N = 1e5 + 10;
//int n,m,t;
//int dfn[N],low[N],p[N],sd[N];
//int stk[N],top,vis[N];
//int head[N],cnt,tot;
//int in[N];
//struct edge{
//    int next,u,v;
//}e[N * 10],ed[N * 10];
//void add(int u,int v){
//    e[++ cnt].next = head[u];
//    e[cnt].u = u;
//    e[cnt].v = v;
//    head[u] = cnt;
//}
//
//void tarjan(int x){
//    low[x] = dfn[x] = ++ t;
//    stk[++ top] = x,vis[x] = 1;
//    for(int i = head[x];i;i = e[i].next){
//        int v = e[i].v;
//        if(!dfn[v]){
//            tarjan(v);
//            low[x] = min(low[x],low[v]);
//        }
//        else if(vis[v]){
//            low[x] = min(low[x],dfn[v]);
//        }
//    }
//    if(dfn[x] == low[x]){
//        int y;
//        while(true){
//            y = stk[top --];
//            sd[y] = x;
//            vis[y] = 0;
//            if(x == y) break;
//            p[x] += p[y];
//        }
//    }
//}
//int dis[N];
//int topo(){
//    queue<int> q;
//    for(int i = 1;i <= n;i ++){
//        if(sd[i] == i && !in[i]){
//            q.push(i);
//            dis[i] = p[i];
//        }
//    }
//    while(!q.empty()){
//        int u = q.front();q.pop();
//        for(int i = head[u];i;i = ed[i].next){
//            int v = ed[i].v;
//            dis[v] = max(dis[v],dis[u] + p[v]);
//            in[v] --;
//            if(in[v] == 0) q.push(v);
//        }
//    }
//    int ans = 0;
//    for(int i = 1;i <= n;i ++) ans = max(ans,dis[i]);
//    return ans;
//}
//
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 1;i <= n;i ++){
//        scanf("%d",&p[i]);
//    }
//    for(int i = 1;i <= m;i ++){
//        int u,v;
//        scanf("%d%d",&u,&v);
//        add(u,v);
//    }
//    for(int i = 1;i <= n;i ++) if(!dfn[i]) tarjan(i);
//    for(int i = 1;i <= m;i ++){
//        int u = sd[e[i].u],v = sd[e[i].v];
//        if(u != v){
//            ed[++ tot].next = head[u];
//            ed[tot].v = v;
//            ed[tot].u = u;
//            head[u] = tot;
//            in[v] ++;
//        }
//    }
//    printf("%d",topo());
//    return 0;
//}
//


//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//typedef pair<int, int> PII;
//const int N = 310;
//
//int n, m;
//int h[N][N];
//int f[N][N];
//PII path[N];
//
//int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
//
//int dp(int x, int y)
//{
//    int &v = f[x][y];
//    if(v != -1) return v;
//
//    v = 1;
//    for(int i = 0; i < 4; i ++ )
//    {
//        int a = x + dx[i], b = y + dy[i];
//        if(a >= 1 && a <= n && b >= 1 && b <= n && h[a][b] < h[x][y])
//            if(v < dp(a, b) + 1)
//            {
//                v = dp(a, b) + 1;
//
//                path[v] = {a, b};
//                cout << v << ": " << endl;
//                cout << h[a][b] << endl;
//            }
//    }
//
//    return v;
//}
//
//int main()
//{
//    scanf("%d", &n);
//
//    for(int i = 1; i <= n; i ++ )
//        for(int j = 1; j <= n; j ++ )
//            scanf("%d", &h[i][j]);
//
//    memset(f, -1, sizeof f);
//
//    int res = 0;
//    for(int i = 1; i <= n; i ++ )
//        for(int j = 1; j <= n; j ++ ){
//            if(f[i][j] == -1)
//            res = max(res, dp(i,j));
//            else res = max(res,f[i][j]);
//        }
//
//
//    printf("%d\n", res);
//
//    int M = 0;
//    for(int i = 1; i <= n; i ++ )
//        for(int j = 1; j <= n; j ++ )
//        {
//            if(M < h[i][j])
//            {
//                M = h[i][j];
//                path[0] = {i, j};
//            }
//        }
//
//
//    int x = path[0].first, y = path[0].second;
//    cout << h[x][y] << "-";
//    for(int i = res; i > 1; i -- )
//    {
//        x = path[i].first, y = path[i].second;
//        cout << h[x][y] << "-";
//    }
//
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//const int N = 1e4 + 10;
//int n,m,t;
//int top,cnt,tot;
//int p[N],head[N],sd[N],dfn[N],low[N];
//int stk[N],vis[N];
//int h[N],in[N],d[N];
//struct edge{
//    int next,u,v;
//}e[N * 10],e2[N * 10];
//void add(int u,int v){
//    e[++ cnt].u = u;
//    e[cnt].next = head[u];
//    e[cnt].v = v;
//    head[u] = cnt;
//}
//void tarjan(int x){
//    low[x] = dfn[x] = ++ t;
//    stk[++ top] = x;vis[x] = 1;
//    for(int i = head[x];i;i = e[i].next){
//        int v = e[i].v;
//        if(!dfn[v]){
//            tarjan(v);
//            low[x] = min(low[x],low[v]);
//        }
//        else if(vis[v]){
//            low[x] = min(low[x],dfn[v]);
//        }
//    }
//    if(dfn[x] == low[x]){
//        int y;
//        while(y = stk[top --]){
//            vis[y] = 0;
//            sd[y] = x;
//            if(x == y) break;
//            p[x] += p[y];
//        }
//    }
//}
//
//int topo(){
//    queue<int> q;
//    for(int i = 1;i <= n;i ++){
//        if(sd[i] == i && !in[i]){
//            q.push(i);
//            d[i] = p[i];
//        }
//    }
//    while(!q.empty()){
//        int u = q.front();q.pop();
//        for(int i = h[u];i;i = e2[i].next){
//            int v = e2[i].v;
//            d[v] = max(d[v],d[u] + p[v]);
//            in[v] --;
//            if(!in[v]) q.push(v);
//        }
//    }
//    int ans = 0;
//    for(int i = 1;i <= n;i ++) ans = max(ans,d[i]);
//    return ans;
//}
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 1;i <= n;i ++){
//        scanf("%d",&p[i]);
//    }
//    for(int i = 1;i <= m;i ++){
//        int u,v;
//        scanf("%d%d",&u,&v);
//        add(u,v);
//    }
//    for(int i = 1;i <= n;i ++){
//        if(!dfn[i]) tarjan(i);
//    }
//    for(int i = 1;i <= m;i ++){
//        int u = sd[e[i].u], v = sd[e[i].v];
//        if(u != v){
//            e2[++ tot].next = h[u];
//            e2[tot].v = v;
//            e2[tot].u = u;
//            h[u] = tot;
//            in[v] ++;
//        }
//    }
//    printf("%d\n",topo());
//    return 0;
//}


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 1e5 + 10;
int dfn[N],low[N];
int t;
bool cut[N];
struct edge{
    int next,to;
}e[N];
int head[N],cnt;
void add(int u,int v){
    e[++ cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}
void tarjan(int u,int fa){
    low[u] = dfn[u] = ++ t;
    int son = 0;
    for(int i = head[u];i;i = e[i].next){
        int v = e[i].to;
        if(!dfn[v]){
            tarjan(v,fa);
            low[u] = min(low[v],low[u]);
            if(low[v] >= dfn[u] && u != fa)
                cut[u] = 1;
            if(u == fa) son ++;
        }
        low[u] = min(low[u],dfn[v]);
    }
    if(son >= 2 && u == fa) cut[u] = 1;
}
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= m;i ++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    for(int i = 1;i <= n;i ++) if(!dfn[i]) tarjan(i,i);
    int sum = 0;
    for(int i = 1;i <= n;i ++){
        if(cut[i]) sum ++;
    }
    printf("%d\n",sum);
    for(int i = 1;i <= n;i ++){
        if(cut[i]) printf("%d ",i);
    }
    return 0;
}