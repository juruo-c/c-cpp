//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 2e3;
//int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
//int n,m;char ch;
//bool fl,a[N][N];
//int vis[N][N][3];
//int stx,sty;
//
//void dfs(int x,int y,int lx,int ly)
//{
//    if(fl) return;
//    if(vis[x][y][0] && (vis[x][y][1] != lx || vis[x][y][2] != ly)){
//        fl = 1;
//        return;
//    }
//    vis[x][y][0] = 1,vis[x][y][1] = lx,vis[x][y][2] = ly;
//    for(int i = 0;i < 4;i ++){
//        int xx = (x + dir[i][0] + n) % n;
//        int yy = (y + dir[i][1] + m) % m;
//        int lxx = lx + dir[i][0];
//        int lyy = ly + dir[i][1];
//        if(a[xx][yy]){
//            if(!vis[xx][yy][0] || vis[xx][yy][1] != lxx || vis[xx][yy][2] != lyy){
//                dfs(xx,yy,lxx,lyy);
//            }
//        }
//    }
//}
//
//int main()
//{
//    while(cin >> n >> m){
//        fl = 0;
//        memset(vis,0,sizeof(vis));
//        memset(a,1,sizeof(a));
//        for(int i = 0;i < n;i ++){
//            for(int j = 0;j < m;j ++){
//                cin >> ch;
//                if(ch == 'S')stx = i,sty = j;
//                if(ch == '#') a[i][j] = 0;
//            }
//        }
//        dfs(stx,sty,stx,sty);
//
//        if(fl) cout << "Yes" << endl;
//        else cout << "No" << endl;
//
//    }
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<vector>
//#include<queue>
//
//using namespace std;
//const int N = 1e4 + 10;
//const int INF = 0x3f3f3f3f;
//
//int n,m,hp;
//struct edge
//{
//    int v,w;
//};
//vector<edge> g[N];
//
//struct node
//{
//    long long d;
//    int u;
//    bool operator < (const node& b)const{
//        return d > b.d;
//    }
//};
//long long  d[N];
//int ans,f[N];
//bool vis[N];
//
//void dijkstra(int s)
//{
//    memset(d,0x3f,sizeof(d));
//    priority_queue<node> q;
//    d[s] = f[s];
//    q.push((node){d[s],s});
//    while(!q.empty()){
//        node x = q.top();q.pop();
//        int u = x.u;
//        if(vis[u]) continue;
//        vis[u] = 1;
//        for(int i = 0;i < g[u].size();i ++){
//            int v = g[u][i].v;
//            int w = g[u][i].w;
//            if(d[v] > d[u] + f[v] && hp - w > 0){
//                d[v] = d[u] + f[v];
//                ans = max(ans,f[v]);
//                q.push((node){d[v],v});
//            }
//        }
//    }
//}
//
//int main()
//{
//    cin >> n >> m >> hp;
//    for(int i = 1;i <= n;i ++)cin >> f[i];
//    for(int i = 0,u,v,w;i < m;i ++){
//        cin >> u >> v >> w;
//        g[u].push_back((edge){v,w});
//        g[v].push_back((edge){u,w});
//    }
//    ans = f[1];
//    dijkstra(1);
//
//    if(d[n] == INF) cout << "AFK" << endl;
//    else cout << ans << endl;
//    return 0;
//}
//

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<queue>
//#define MAXN 1e9 + 5
//
//using namespace std;
//const int N = 1e4 + 10;
//const int M = 1e5 + 10;
//
//int f[N],d[N];
//bool vis[N];
//int head[N];
//priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
//int n,m,hp,tot;
//struct edge
//{
//    int to,next,len;
//}e[M];
//
//void add(int u,int v,int w)
//{
//    e[++tot].len = w;
//    e[tot].to = v;
//    e[tot].next = head[u];
//    head[u] = tot;
//}
//
//bool check(int x)
//{
//    if(x < f[1])return false;
//    for(int i = 1;i <= n;i ++)d[i] = 1e9;
//    memset(vis,0,sizeof(vis));
//    d[1] = 0;
//    q.push(make_pair(0,1));
//    while(!q.empty()){
//        int u = q.top().second;q.pop();
//        if(vis[u]) continue;
//        vis[u] = 1;
//        int v = head[u];
//        while(v){
//            if(f[e[v].to] <= x && !vis[e[v].to] && d[u] + e[v].len < d[e[v].to]){
//                d[e[v].to] = d[u] + e[v].len;
//                q.push(make_pair(d[e[v].to],e[v].to));
//            }
//            v = e[v].next;
//        }
//    }
//    if(d[n] < hp)return true;
//    else return false;
//}
//
//int main()
//{
//    cin >> n >> m >> hp;
//    for(int i = 1;i <= n;i ++)cin >> f[i];
//    for(int i = 1,u,v,w;i <= m;i ++){
//        cin >> u >> v >> w;
//        add(u,v,w);
//        add(v,u,w);
//    }
//
//    if(check(MAXN) == 0){
//        cout << "AFK" << endl;
//        return 0;
//    }
//
//    int l = 1,r = MAXN;//二分金钱
//    while(l <= r){
//        int mid = l + r >> 1;
//        if(check(mid))
//            r = mid - 1;
//        else l = mid + 1;
//    }
//    cout << l << endl;
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<vector>
//#include<queue>
//#define MAXN 1e9 + 10
//
//using namespace std;
//const int N = 1e4 + 10;
//
//int n,m,hp;
//int d[N],f[N];
//bool vis[N];
//
//struct edge
//{
//    int v,w;
//};
//vector<edge> g[N];
//struct node
//{
//    int d,u;
//    bool operator < (const node& b) const {
//        return d > b.d;
//    }
//};
//
//bool check(int x)
//{
//    if(x < f[1]) return false;
//    for(int i = 1;i <= n;i ++)d[i] = 1e9;
//    memset(vis,0,sizeof(vis));
//    d[1] = 0;
//    priority_queue<node> q;
//    q.push((node){0,1});
//    while(!q.empty()){
//        node s = q.top();q.pop();
//        int u = s.u;
//        if(vis[u])continue;
//        vis[u] = 1;
//        for(int i = 0;i < g[u].size();i ++){
//            int v = g[u][i].v;
//            int w = g[u][i].w;
//            if(f[v] <= x && !vis[v] && d[v] > d[u] + w){
//                d[v] = d[u] + w;
//                q.push((node){d[v],v});
//            }
//        }
//    }
//
//    if(d[n] < hp) return true;
//    else return false;
//}
//
//int main()
//{
//    cin >> n >> m >> hp;
//    for(int i = 1;i <= n;i ++)cin >> f[i];
//    for(int i = 0;i < m;i ++){
//        int u,v,w;cin >> u >> v >> w;
//        g[u].push_back((edge){v,w});
//        g[v].push_back((edge){u,w});
//    }
//
//    if(!check(MAXN)){
//        cout << "AFK" << endl;
//        return 0;
//    }
//
//    int l = 1,r = MAXN;//二分费用
//    while(l <= r){
//        int mid = l + r >> 1;
//        if(check(mid)) r = mid - 1;
//        else l = mid + 1;
//    }
//    cout << l << endl;
//
//    return 0;
//}

//#include<iostream>
//#include<map>
//
//using namespace std;
//const int N = 10;
//const int M = (1 << N);
//int a[M];
//int n,m;
//
//
//int main()
//{
//    while(cin >> n && n){
//        map<string,pair<int,int> > val;
//        string s;
//        for(int i = 1;i <= n;i ++){
//            cin >> s;
//            val[s].first = i;
//        }
//        char ch;
//        for(int i = (1 << n);i < (i << n + 1);i ++){
//            cin >> ch;
//            int a[i] = ch - '0';
//        }
//        cin >> m;
//        for(int i = 0;i < m;i ++){
//            cin >> s;
//            getid()
//        }
//    }
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//
//using namespace std;
//const int N = 10;
//const int M = (1 << N);
//int n,m,kase;
//
//
//int main()
//{
//    while(cin >> n && n){
//        string tem;int num[N];char q[N];
//        for(int i = 0;i < n;i ++){
//            cin >> tem;
//            num[i] = tem[1] - '0';
//        }
//        string s;
//        cin >> s >> m;
//        for(int i = 0;i < m;i ++){
//            cin >> tem;
//            int k = 0;
//            for(int j = 0;j < n;j ++){
//                k = tem[num[j] - 1] == '1' ? (k << 1) + 1 : (k << 1);
//            }
//            q[i] = s[k];
//        }
//        q[m] = '\0';
//        printf("S-Tree #%d:\n%s\n\n",++kase,q);
//    }
//    return 0;
//}
//
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//string pre,in;
//
//void build(int l1,int r1,int l2,int r2)
//{
//    int root = in.find(pre[l1]);
//    if(root > l2) build(l1 + 1,l1 + root - l2,l2, root - 1);//建左树
//    if(root < r2) build(r1 - r2 + root + 1,r1,root + 1,r2 );//建右树
//    cout << pre[l1];
//}
//
//int main()
//{
//    while(cin >> pre >> in){
//        build(0,pre.size() - 1, 0, in.size() - 1);
//        cout << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<queue>
//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//const int N = 10;
//bool vis[N][N];
//string s,st;
//int stx,sty,ex,ey;
//int dir[][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
//struct node
//{
//    int x,y,step;
//};
//
//bool check(int x,int y)
//{
//    if(x <= 0 || y <= 0 || x > 8 || y > 8 || vis[x][y])return false;
//    return true;
//}
//
//int bfs()
//{
//    memset(vis,0,sizeof(vis));
//    queue<node> q;
//    node cur,next;
//    cur = (node){stx,sty,0};
//    vis[cur.x][cur.y] = 1;
//    q.push(cur);
//    while(!q.empty()){
//        cur = q.front();q.pop();
//        if(cur.x == ex && cur.y == ey) return cur.step;
//        for(int i = 0;i < 8;i ++){
//            next.x = cur.x + dir[i][0];
//            next.y = cur.y + dir[i][1];
//            if(check(next.x,next.y)){
//                next.step = cur.step + 1;
//                vis[next.x][next.y] = 1;
//                q.push(next);
//            }
//        }
//    }
//}
//
//int main()
//{
//    while(cin >> s >> st){
//        stx = s[0] - 'a' + 1;
//        sty = s[1] - '0';
//        ex = st[0] - 'a' + 1;
//        ey = st[1] - '0';
//        printf("To get from %s to %s takes %d knight moves.\n",s.c_str(),st.c_str(),bfs());
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//const int N = 25;
//
//int a[N][N];
//int n,m,k,hp;
//struct node
//{
//    int x,y,step;
//};
//int dir[][2] = {{1,0},{0,1},{0,-1},{-1,0}};
//bool vis[N][N];
//
//bool judge(int x,int y)
//{
//    if(x < 1 || y < 1 || x > n || y > m) return false;
//    return true;
//}
//int bfs()
//{
//    memset(vis,0,sizeof(vis));
//    queue<node> q;
//    node cur;
//    cur = (node){1,1,0};
//    vis[cur.x][cur.y] = 1;
//    q.push(cur);
//    while(!q.empty()){
//        cur = q.front();q.pop();
//        if(cur.x == n && cur.y == m){
//            return cur.step;
//        }
//        for(int i = 0;i < 4;i ++){
//            int tx = cur.x + dir[i][0];
//            int ty = cur.y + dir[i][1];
//            if(vis[tx][ty])continue;
//            if(!judge(tx,ty))continue;
//            if(a[tx][ty]){
//                if(hp > 0)hp --;
//                else continue;
//            }
//            else hp = k;
//            vis[tx][ty] = 1;
//            q.push((node){tx,ty,cur.step + 1});
//        }
//    }
//    return -1;
//}
//
//int main()
//{
//    int t; cin >> t;
//    while(t -- ){
//        cin >> n >> m >> k;
//        hp = k;
//        for(int i = 1;i <= n;i ++){
//            for(int j = 1;j <= m;j ++){
//                cin >> a[i][j];
//            }
//        }
//        cout << bfs() << endl;
//    }
//    return 0;
//}

#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
const int N = 25;
int a[N][N],d[N][N][N];
int n,m,k;
int dir[][2] = {{1,0},{-1,0},{0,1},{0,-1}};

struct node
{
    int x,y,k;
};

void bfs()
{
    queue<node> q;
    d[1][1][0] = 0;
    node cur = {1,1,0};
    q.push(cur);
    while(!q.empty()){
        cur = q.front();q.pop();
        for(int i = 0;i < 4;i ++){
            int xx = cur.x + dir[i][0];
            int yy = cur.y + dir[i][1];
            if(xx >= 1 && xx <= n && yy >= 1 && yy <= m){
                node next = {xx,yy,cur.k};
                if(a[xx][yy] && next.k + 1 <= k && d[xx][yy][next.k + 1] == -1){
                    next.k ++;
                    d[xx][yy][next.k] = d[cur.x][cur.y][cur.k] + 1;
                    q.push(next);
                }
                else if(a[xx][yy] == 0 && d[xx][yy][0] == -1){
                    d[xx][yy][0] = d[cur.x][cur.y][cur.k] + 1;
                    next.k = 0;
                    q.push(next);
                }
            }
        }
    }
}

int main()
{
    int t;cin >> t;
    while(t --){
        cin >> n >> m >> k;
        memset(d,-1,sizeof(d));
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= m;j ++)
            cin >> a[i][j];
        bfs();
        cout << d[n][m][0] << endl;
    }
    return 0;
}










