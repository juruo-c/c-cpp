//
// Created by 19116 on 2021/1/14.
//

//#include<iostream>
//#include<algorithm>
//#include<cmath>
//#include<cstdio>
//#include<queue>
//#include<sstream>
//
//using namespace std;
//const int N = 501;
//const int INF = 0x3f3f3f3f;
//int stx,sty,ex,ey;
//struct node{
//    int x,y;
//}p[N];
//double map[N][N],dis[N];
//bool vis[N];
//void init(){
//    for(int i = 1;i < N;i ++){
//        for(int j = 1;j < N;j ++){
//            if(i == j) map[i][j] = 0;
//            else map[i][j] = INF;
//        }
//    }
//
//}
//
//double distan(int i,int j){
//    return sqrt(1.0 * (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y));
//}
//
//struct Node{
//    double d;
//    int s;
//    bool operator<( const Node& b)const {
//        return d > b.d;
//    }
//};
//void dij(int s,int n){
//    priority_queue<Node> q;
//    dis[s] = 0;
//    q.push((Node){0,s});
//    while(!q.empty()){
//        int u = q.top().s;q.pop();
//        if(vis[u]) continue;
//        vis[u] = 1;
//        for(int i = 1;i < n;i ++){
//            if(!vis[i] && dis[i] > dis[u] + map[u][i]){
//                dis[i] = dis[u] + map[u][i];
//                q.push((Node){dis[i],i});
//            }
//        }
//    }
//
//}
//
//int main(){
//    double v1 = 40000.0 / 60;
//    double v2 = 10000.0 / 60;
//    init();
//    scanf("%d%d%d%d",&p[1].x,&p[1].y,&p[2].x,&p[2].y);
//    int n = 3,last = 3;
//    while(scanf("%d%d",&p[n].x,&p[n].y) != EOF){
////        if(p[n].x == 1 && p[n].y == 1)break;
//        if(p[n].x == -1 && p[n].y == -1){
//            last = n;
//            continue;
//        }
//        if(last != n)map[n - 1][n] = map[n][n - 1] = distan(n - 1,n) / v1;
//        n ++;
//    }
//    for(int i = 1;i < n;i ++){
//        for(int j = 1;j < n;j ++){
//            map[i][j] = min(map[i][j],distan(i,j) / v2);
//        }
//    }
//    for(int i = 1;i < n;i ++)dis[i] = INF;
//    dij(1,n);
//    printf("%.0f\n",dis[2]);
//    return 0;
//}
//
//#include<iostream>
//#include<queue>
//#include<algorithm>
//
//using namespace std;
//const int N = 110;
//const int INF = 0x3f3f3f3f;
//int m,n;int map[N][N];
//
//struct subject{
//    int p,l,x;
//    pair<int,int> sub[N];
//}s[N];
//
//struct node{
//    int d,s;
//    bool operator<(const node& b)const {
//        return d > b.d;
//    }
//};
//bool vis[N];int d[N];
//
//void dij(int s){
//    priority_queue<node> q;
//    d[s] = 0;
//    q.push((node){0,s});
//    while(!q.empty()){
//        int u = q.top().s;q.pop();
//        if(vis[u]) continue;
//        vis[u] = 1;
//        for(int i = 1;i <= n + 1;i ++){
//            if(!vis[i] && d[i] > d[u] + map[u][i]){
//                d[i] = d[u] + map[u][i];
//                q.push((node){d[i],i});
//            }
//        }
//    }
//
//}
//int main(){
//
//    cin >> m >> n;
//    for(int i = 1;i <= n;i ++){
//        for(int j = 1;j <= n;j ++){
//            if(i == j ) map[i][j] = 0;
//            else map[i][j] = INF;
//        }
//    }
//    for(int i = 1;i <= n;i ++){
//        int p,l,x;
//        cin >> p >> l >> x;
//        s[i].p = p,s[i].l = l,s[i].x = x;
//        map[n + 1][i] = p;
//        for(int j = 0;j < x;j ++){
//            int num,pri;
//            cin >> num >> pri;
//            s[i].sub[j] = make_pair(num,pri);
//        }
//    }
//
//    for(int i = 1;i <= n;i ++){
//        for(int j = 0;j < s[i].x;j ++){
//            int num = s[i].sub[j].first;
//            int pri = s[i].sub[j].second;
//            if(abs(s[i].l - s[num].l) > m) continue;
//
//            map[num][i] = min(map[num][i],pri);
//        }
//    }
//
//    for(int i = 1;i <= n + 1;i ++) d[i] = INF;
//    dij(n + 1);
//    cout << d[1] << endl;
//    return 0;
//}
//
//#include<iostream>
//#include<algorithm>
//#include<queue>
//#include<cstring>
//
//using namespace std;
//const int N = 110;
//const int INF = 0x3f3f3f3f;
//int m,n;
//int cost[N][N],d[N],val[N],level[N];
//bool is[N],vis[N];
//
//struct node{
//    int d,s;
//    bool operator < (const node& b)const {
//        return d > b.d;
//    }
//};
//
//int dij(){
//    int res = INF;
//    memset(vis,0,sizeof(vis));
//    for(int i = 1;i <= n;i ++)d[i] = INF;
//    priority_queue<node> q;
//    d[1] = 0;
//    q.push((node){0,1});
//    while(!q.empty()){
//        int u = q.top().s;q.pop();
//        if(vis[u])continue;
//        vis[u] = 1;
//        for(int i = 1;i <= n;i ++){
//            if(is[i] && d[i] > d[u] + cost[u][i]){
//                d[i] = d[u] + cost[u][i];
//                q.push((node){d[i],i});
//            }
//        }
//    }
//    for(int i = 1;i <= n;i ++){
//        d[i] += val[i];
//        res = min(res,d[i]);
//    }
//    return res;
//}
//
//int main(){
//    cin >> m >> n;
//    for(int i = 1;i <= n;i ++){
//        for(int j = 1;j <= n;j ++){
//            if(i == j) cost[i][j] = 0;
//            else cost[i][j] = INF;
//        }
//    }
//    for(int i = 1;i <= n;i ++){
//        int p,l,x;
//        cin >> p >> l >> x;
//        val[i] = p;level[i] = l;
//        for(int j = 0;j < x;j ++){
//            int num,v;
//            cin >> num >> v;
//            cost[i][num] = v;
//        }
//    }
//
//    int ans = INF;
//    for(int i = 0;i <= m;i ++){
//        memset(is,0,sizeof(is));
//        for(int j = 1;j <= n;j ++){
//            if(level[1] - i <= level[j] && level[j] <= level[1] - i + m)
//                is[j] = true;
//        }
//        ans = min(ans,dij());
//    }
//
//    cout << ans << endl;
//
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<queue>
//#include<vector>
//
//using namespace std;
//const int N = 110;
//const int INF = 0x3f3f3f3f;
//struct edge{
//    int v,w;
//};
//vector<edge> g[N];
//int n,a,b;
//int d[N];
//bool vis[N];
//struct node{
//    int d,s;
//    bool operator< (const node& x)const {
//        return d > x.d;
//    }
//};
//void dij(int s){
//    for(int i = 1;i <= n;i ++) d[i] = INF;
//    priority_queue<node> q;
//    d[s] = 0;
//    q.push((node){0,s});
//    while(!q.empty()){
//        int u = q.top().s;q.pop();
//        if(vis[u])continue;
//        vis[u] = 1;
//        for(int i = 0;i < g[u].size();i ++){
//            int v = g[u][i].v;
//            int w = g[u][i].w;
//            if(!vis[v] && d[v] > w + d[u]){
//                d[v] = w + d[u];
//                q.push((node){d[v],v});
//            }
//        }
//    }
//}
//
//int main(){
//    cin >> n >> a >> b;
//    for(int i = 1;i <= n;i ++){
//        int k;
//        cin >> k;
//        for(int j = 0;j < k;j ++){
//            int v,w;
//            if(j) w = 1;
//            else w = 0;
//            cin >> v;
//            g[i].push_back((edge{v,w}));
//        }
//    }
//
//    dij(a);
//
//    if(d[b] == INF) cout << -1 << endl;
//    else cout << d[b] << endl;
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//#include<vector>
//
//using namespace std;
//const int N = 210;
//const int INF = 0x3f3f3f3f;
//int n,m,q;int busy[N];
//
//struct edge{
//    int v,w;
//};
//vector<edge> g[N];
//int amount(int a,int b){
//    return (a - b) * (a - b) * (a - b);
//}
//
//struct node{
//    int d,s;
//    bool operator<(const node& b)const {
//        return d > b.d;
//    }
//};
//int d[N];bool vis[N];
//int inf[N];
//void spfa(int s){
//    memset(inf,0,sizeof(inf));
//    memset(vis,0,sizeof(vis));
//    for(int i = 1;i <= n;i ++) d[i] = INF;
//    queue<int> q;
//    d[s] = 0;
//    q.push(s);
//    while(!q.empty()){
//        int u = q.front();q.pop();vis[u] = 0;
//        for(int i = 0;i < g[u].size();i ++){
//            int v = g[u][i].v;
//            int w = g[u][i].w;
//            if(d[v] > d[u] + w){
//                d[v] = d[u] + w;
//                if(!vis[v] && inf[v] <= n){
//                    inf[v] ++;
//                    q.push(v);
//                    vis[v] = 1;
//                }
//            }
//        }
//    }
//}
//int main(){
//    int kase = 0;
//    int t;cin >> t;
//    while(t --){
//        cin >> n;
//        for(int i = 1;i <= n;i ++)g[i].clear();
//        for(int i = 1;i <= n;i ++)cin >> busy[i];
//        cin >> m;
//        for(int i = 0;i < m;i ++){
//            int u,v;
//            cin >> u >> v;
//            g[u].push_back((edge){v,amount(busy[v],busy[u])});
//        }
//
//        spfa(1);
//        cout << "Case " << ++kase << ":\n";
//        cin >> q;
//        while(q --){
//            int v;cin >> v;
//            if(d[v] == INF || d[v] < 3 || inf[v] > n) cout << "?\n";
//            else cout << d[v] << endl;
//        }
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<algorithm>
//#include<queue>
//#include<vector>
//
//using namespace std;
//const int N = 1e5 + 10;
//const int INF = 0x3f3f3f3f;
//int n,m,c;
//int layer[N];
//int d[N];
//bool vis[N];
//
//struct edge{
//    int v,w;
//};
//vector<edge> g[N];
//struct node{
//    int d,s;
//    bool operator < (const node& b)const {
//        return d > b.d;
//    }
//};
//
//void dij(int s){
//    memset(vis,0,sizeof(vis));
//    for(int i = 1;i <= n;i ++) d[i] = INF;
//    priority_queue<node> q;
//    d[s] = 0;
//    q.push((node){0,s});
//    while(!q.empty()){
//        int u = q.top().s;q.pop();
//        if(vis[u]) continue;
//        vis[u] = 1;
//        for(int i = 0;i < g[u].size();i ++){
//            int v = g[u][i].v;
//            int w = g[u][i].w;
//            if(!vis[v] && d[v] > d[u] + w){
//                d[v] = d[u] + w;
//                q.push((node){d[v],v});
//            }
//        }
//    }
//}
//int main(){
//    int t; scanf("%d",&t);
//    int kase = 0;
//    while(t --){
//        scanf("%d%d%d",&n,&m,&c);
//
//        for(int i = 1;i <= n;i++)g[i].clear();
//        for(int i = 1;i <= n;i ++) {
//            int tmp;cin >> tmp;
//            layer[tmp] = i;
//        }
//        for(int i = 1;i < n;i ++){
//            int t1 = layer[i],t2 = layer[i + 1];
//            if(!t1 || !t2) continue;
//            g[t1].push_back((edge){t2,c});
//            g[t2].push_back((edge){t1,c});
//        }
//
//        for(int i = 0;i < m;i ++){
//            int u,v,w;
//            scanf("%d%d%d",&u,&v,&w);
//            g[u].push_back((edge){v,w});
//            g[v].push_back((edge){u,w});
//        }
//
//        dij(1);
//        printf("Case #%d: %d\n", ++ kase,d[n]);
//    }
//    return 0;
//}

//
//#include<iostream>
//
//using namespace std;
//const int N = 2001;
//int a[N],c[N];
//void add(){
//    int tmp = 0;
//    for(int i = 1;i <= 1000;i ++){
//        c[i] += a[i] + tmp;
//        tmp = c[i] / 10;
//        c[i] %= 10;
//    }
//}
//
//void mul(int k){
//    int tmp = 0;
//    for(int i = 1;i <= 1000;i ++){
//        a[i] = a[i] * k + tmp;
//        tmp = a[i] / 10;
//        a[i] %= 10;
//    }
//}
//int main(){
//    int n; cin >> n;
//    a[1] = 1;
//    for(int i = 1;i <= n;i ++){
//        mul(i);
//        add();
//    }
//    bool flag = 0;
//    for(int i = 1000;i >= 1;i --){
//        if(c[i]) flag = 1;
//        if(flag) cout << c[i];
//    }
//
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//
//using namespace std;
//const int N = 5000;
//int cnt,b[N];
//void mul(int k){
//    int tmp = 0;
//    for(int i = 1;i <= N;i ++){
//        b[i] = b[i] * k + tmp;
//        tmp = b[i] / 10;
//        b[i] %= 10;
//    }
//}
//int main(){
//    int t;cin >> t;
//    while(t --){
//        memset(b,0,sizeof(b));
//        cnt = 0;
//        int n,a;
//        cin >> n >> a;
//        b[1] = 1;
//        for(int i = 1;i <= n;i ++){
//            mul(i);
//        }
//        int flag = 0;
//        for(int i = N;i >= 1;i --){
//            if(b[i]) flag = 1;
//            if(flag && a == b[i]) cnt ++;
//        }
//        cout << cnt << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//const int N = 1e4 + 10;
//string sub(string a,string b){
//    int na[N] = {0},nb[N] = {0},ans[N] = {0};
//    string diff;
//
//    if((a < b && a.size() <= b.size()) || b.size() > a.size())
//        return "-" + sub(b,a);
//
//    for(int i = a.size();i > 0;i --) na[i] = a[a.size() - i] - '0';
//    for(int i = b.size();i > 0;i --) nb[i] = b[b.size() - i] - '0';
//
//    int maxl = max(a.size(),b.size());
//
//    for(int i = 1;i <= maxl;i ++){
//        if(na[i] < nb[i]){
//            na[i + 1] --;
//            na[i] += 10;
//        }
//        ans[i] = na[i] - nb[i];
//    }
//
//    while(ans[maxl] == 0) maxl --;
//    if(maxl < 1) return "0";
//    for(int i = maxl;i > 0;i --) diff += ans[i] + '0';
//    return diff;
//}
//int main(){
//    string a,b;
//    cin >> a >> b;
//    cout << sub(a,b);
//    return 0;
//}


#include<iostream>

using namespace std;
const int N = 1e4 + 10;
string sub(string a,string b){
    string res;
    int na[N] = {0},nb[N] = {0},ans[N] = {0};

    if(a < b && a.size() == b.size() || b.size() > a.size()){
        return "-" + sub(b,a);
    }
    for(int i = a.size();i > 0;i --) na[i] = a[a.size() - i] - '0';
    for(int i = b.size();i > 0;i --) nb[i] = b[b.size() - i] - '0';

    int len = max(a.size(),b.size());

    for(int i = 1;i <= len;i ++){
        if(na[i] < nb[i]){
            na[i + 1] --;
            na[i] += 10;
        }
        ans[i] = na[i] - nb[i];
    }
    while(ans[len] == 0) len --;
    if(len < 1) return "0";
    for(int i = len;i > 0;i --) res += ans[i] + '0';
    return res;
}
int main(){
    string a,b;
    cin >> a >> b;
    cout << sub(a,b) << endl;
    return 0;
}