////
//// Created by 19116 on 2021/1/15.
////
//
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//const int N = 5e5 + 10;
//const int INF = 0x3f3f3f3f;
//int n,m,c;
//int d[N],lay[N],head[N],tot;
//bool vis[N];
//
//struct edge{
//    int next,to,w;
//}e[N << 2];
//
//void init(){
//    memset(e,0,sizeof(e));
//    memset(head, -1,sizeof(head));
//    memset(lay,0,sizeof(lay));
//    memset(vis,0,sizeof(vis));
//    tot = 0;
//}
//
//void add_edge(int u,int v,int w){
//    e[++ tot].next = head[u];
//    e[tot].to = v;
//    e[tot].w = w;
//    head[u] = tot;
//}
//
//void creat_point(int n,int c){
//    add_edge(n + 1, 2 * n + 2, c);
//    for(int i = 2;i < n;i ++){
//        add_edge(n + i, 2 * n + i - 1, c);
//        add_edge(n + i, 2 * n + i + 1, c);
//    }
//    add_edge(2 * n, 2 * n + n - 1, c);
//}
//struct node{
//    int d,s;
//    bool operator < (const node& b) const {
//        return d > b.d;
//    }
//};
//void dij(){
//    for(int i = 1;i <= N;i ++) d[i] = INF;
//    priority_queue<node> q;
//    d[1] = 0;
//    q.push((node){0,1});
//    while(!q.empty()){
//        int u = q.top().s;q.pop();
//        if(vis[u]) continue;
//        vis[u] = 1;
//        for(int i = head[u];i != -1;i = e[i].next){
//            int v = e[i].to;
//            int w = e[i].w;
//            if(d[v] > d[u] + w){
//                d[v] = d[u] + w;
//                q.push((node){d[v],v});
//            }
//        }
//    }
//}
//int main(){
//    int kase = 0;
//    int t;scanf("%d",&t);
//    while(t --){
//        init();
//        scanf("%d%d%d",&n,&m,&c);
//        creat_point(n,c);
//        for(int i = 1;i <= n;i ++){
//            int x;
//            scanf("%d", &x);
//            add_edge(i,x + n,0);
//            add_edge(x + 2 * n, i,0);
//        }
//        for(int i = 0;i < m;i ++){
//            int u,v,w;
//            scanf("%d%d%d",&u,&v,&w);
//            add_edge(u,v,w);
//            add_edge(v,u,w);
//        }
//
//        dij();
//
//        printf("Case #%d: ", ++ kase);
//        if(d[n] != INF)printf("%d\n",d[n]);
//        else printf("-1\n");
//    }
//    return 0;
//}

//#include <cstdio>
//#include <iostream>
//#include <cstring>
//#include <queue>
//using namespace std;
//const int INF = 0x3fffffff;
//const int maxn = 5e5 + 10;
//int path[maxn], head[maxn], lay[maxn], T, n, m, c, u, v, x, l, cnt, ca;
//bool vis[maxn];
//
//struct Edge {
//    int next, to, len;
//} edge[maxn << 2];
//
//struct node {
//    int x, len;
//    friend bool operator < (node a, node b) {
//        return a.len > b.len;
//    }
//};
//
//void init() {
//    memset(edge, 0, sizeof edge);
//    memset(head, 0, sizeof head);
//    memset(lay, 0, sizeof lay);
//    memset(vis, false, sizeof vis);
//    cnt = 0;
//    fill(path, path + maxn, INF);
//}
//
//void add_edge(int x, int y, int len) {
//    edge[++cnt].next = head[x];
//    edge[cnt].to = y;
//    edge[cnt].len = len;
//    head[x] = cnt;
//}
//
//void spfa() {
//    queue<int> q;
//    q.push(1);
//    path[1] = 0;
//    while (!q.empty()) {
//        int now = q.front(); q.pop();
//        vis[now] = false;
//        //printf("now : %d %d\n", now, path[now]);
//        for (int i = head[now]; i; i = edge[i].next) {
//            int next = edge[i].to, len = edge[i].len;
//            if (path[next] > path[now] + len) {
//                path[next] = path[now] + len;
//                if (!vis[next]) {
//                    q.push(next);
//                    vis[next] = true;
//                }
//            }
//        }
//    }
//}
//
//void dij() {
//    priority_queue<node> q;
//    q.push({1, 0});
//    path[1] = 0;
//    while (!q.empty()) {
//        node now = q.top(); q.pop();
//        if (vis[now.x]) continue;
//        //printf("now:%d %d\n", now.x, path[now.x]);
//        vis[now.x] = true;
//        for (int i = head[now.x]; i; i = edge[i].next) {
//            int next = edge[i].to, len = edge[i].len;
//            if (path[next] > path[now.x] + len) {
//                path[next] = path[now.x] + len;
//                q.push({next, path[next]});
//            }
//        }
//    }
//}
//
//void creat_point(int n, int c) {
//    add_edge(n + 1, 2*n + 2, c);
//    for (int i = 2; i < n; i++) {
//        add_edge(n + i, 2 * n + i - 1, c);
//        add_edge(n + i, 2 * n + i + 1, c);
//    }
//    add_edge(2 * n, 3 * n - 1, c);
//}
//
//int main()
//{
//    scanf("%d", &T);
//    while (T--) {
//        init();
//        scanf("%d %d %d", &n, &m, &c);
//        creat_point(n, c);
//        for (int i = 1; i <= n; i++) {
//            scanf("%d", &x);
//            add_edge(i, x + n, 0);
//            add_edge(x + 2 * n, i, 0);
//        }
//        for (int i = 0; i < m; i++) {
//            scanf("%d %d %d", &u, &v, &l);
//            add_edge(u, v, l);
//            add_edge(v, u, l);
//        }
//        //spfa();
//        dij();
//        printf("Case #%d: ", ++ca);
//        if (path[n] != INF) printf("%d\n", path[n]);
//        else printf("-1\n");
//    }
//
//    return 0;
//}
//

//#include<iostream>
//#include<cstring>
//
//using namespace std;
//const int N = 110;
//const int INF = 0x3f3f3f3f;
//int n,d[N],g[N][N];
//bool vis[N];

//int prim(){
//    int ans = 0;
//    memset(d,0x3f,sizeof(d));
//    memset(vis,0,sizeof(vis));
//    for(int i = 0;i < n;i ++){
//        int t = 0;
//        for(int j = 1;j <= n;j ++){
//            if(!vis[j] && (t == 0 || d[j] < d[t])){
//                t = j;
//            }
//        }
//
//        if(i && d[t] == INF) return INF;
//        if(i) ans += d[t];
//        vis[t] = 1;
//        for(int j = 1;j <= n;j ++){
//            if(!vis[j]) d[j] = min(d[j],g[t][j]);
//        }
//    }
//
//    return ans;
//}

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 1e5 + 10;
//const int M = 1e5 + 10;
//int fa[N],cnt;
//int n,m;
//int getf(int x){
//    return x == fa[x] ? x : fa[x] = getf(fa[x]);
//}
//struct edge{
//    int u,v,w;
//    bool operator < (const edge& b)const {
//        return w < b.w;
//    }
//}e[M];
//
//int kruskal(){
//    int ans = 0;
//    for(int i = 1;i <= n;i ++) fa[i] = i;
//
//    sort(e, e + cnt);
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
//
//}
//
//int main(){
//    cin >> n >> m;
//
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 305;
//const int INF = 0x3f3f3f3f;
//int n,cir,g[N][N],d[N];
//int ans ;
//bool vis[N];
//
//void dij(int s){
//    memset(vis,0,sizeof(vis));
//    memset(d,0x3f,sizeof(d));
//    d[s] = 0;
//    for(int i = 0;i < n;i ++){
//        int t = 0;
//        for(int j = 1;j <= n;j ++){
//            if(!vis[j] && (t == 0 || d[j] < d[t])){
//                t = j;
//            }
//        }
//        vis[t] = 1;
//        for(int j = 1;j <= n;j ++){
//            d[j] = min(d[j], d[t] + g[t][j]);
//            if(j == s && t != s) cir = min(cir,d[t] + g[t][j]);
//        }
//    }
//}
//int main(){
//    while(~scanf("%d",&n)){
//        for(int i = 1;i <= n;i ++){
//            for(int j = 1;j <= n;j ++){
//                scanf("%d",&g[i][j]);
//            }
//        }
//        cir = INF;
//        dij(1);
//        ans = d[n];
//        int t = cir;
//        cir = INF;
//        dij(n);
//        t += cir;
//        printf("%d\n",min(t,ans));
//    }
//    return 0;
//}

//#include<iostream>
//#include<cmath>
//
//using namespace std;
//const int N = 1e8 + 10;
//int n,m,sum;
//int ans[N];
//
//int main(){
//    cin >> n;
//    string s;cin >> s;
//    cin >> m;
//    for(int i = 0;i < s.size();i ++){
//        int t = pow(n,s.size() - 1 - i);
//        if(s[i] >= 'A'){
//            t *= (s[i] - 'A' + 10);
//            sum += t;
//        }
//        else{
//            t *= (s[i] - '0');
//            sum += t;
//        }
//    }
//
//    int cnt = 0;
//    while(sum){
//        ans[cnt ++] = sum % m;
//        sum /= m;
//    }
//    for(int i = cnt - 1;i >= 0;i --){
//        if(ans[i] >= 10 ) cout << (char)(ans[i] + 'A' - 10);
//        else cout << ans[i];
//    }
//    return 0;
//}

//#include<cstdio>
//
//void change(int n,int r){
//    if(n == 0)return ;
//    int m = n % r;
//
//    if(m < 0) m -= r,n += r;
//
//    if(m >= 10) m = 'A' + m - 10;
//    else m += '0';
//
//    change(n / r,r);
//
//    printf("%c",m);
//}
//
//int main(){
//    int n,r;
//    scanf("%d%d",&n,&r);
//    printf("%d=",n);
//    change(n,r);
//    printf("(base%d)",r);
//    return 0;
//}


//#include<cstdio>
//
//void change(int n,int m){
//    if(n == 0) return;
//
//    int t = n % m;
//    if(t < 0) t -= m,n += m;
//
//    if(t >= 10) t += 'A' - 10;
//    else t += '0';
//
//    change(n / m,m);
//
//    printf("%c",t);
//}
//int main(){
//    int n,m;
//    scanf("%d%d",&n,&m);
//    printf("%d=",n);
//    change(n,m);
//    printf("(base%d)",m);
//    return 0;
//}
//#include<iostream>
//#include<queue>
//
//using namespace std;
//const int N = 110;
//const int INF = 0x3f3f3f3f;
//int n;
//int g[N][N];//邻接矩阵
//int d[N];//最短路
//int inf[N];//进队次数
//bool vis[N];
//
//bool spfa(int s){
//    for(int i = 1;i <= n;i ++) d[i] = INF;
//    queue<int> q;
//    d[s] = 0;
//    q.push(s);vis[s] = 1;
//    while(!q.empty()){
//        int u = q.front();q.pop();
//        vis[u] = 0;
//        for(int i = 1;i <= n;i ++){
//            if(g[u][i] && d[i] > d[u] + g[u][i]){
//                d[i] = d[u] + g[u][i];
//                if(!vis[i]){
//                    q.push(i);
//                    vis[i] = 1;
//                    inf[i] ++;
//                    if(inf[i] > n) return false;//出现负环
//                }
//            }
//        }
//    }
//    return true;
//}
//
//int main(){
//
//    return 0;
//}
//
//#include<iostream>
//#include<stack>
//using namespace std;
//const int N = 110;
//int n;
//int g[N][N];//邻接矩阵
//int d[N];//最短路
//int inf[N];//进栈次数
//bool vis[N];
//bool spfa(int s){
//    stack<int> stk;
//    stk.push(s);
//    while(!stk.empty()){
//        int u = stk.top();stk.pop();
//        vis[u] = 0;
//        for(int i = 1;i <= n;i ++){
//            if(d[i] > d[u] + g[u][i] && g[u][i]){
//                d[i] = d[u] + g[u][i];
//                if(!vis[i]){
//                    stk.push(i);
//                    vis[i] = 1;
//                    inf[i] ++;
//                    if(inf[i] > n) return false;
//                }
//            }
//        }
//    }
//    return true;
//}
//
//int main(){
//    return 0;
//}
//#include<iostream>
//
//using namespace std;
//
////将十进制数n转化为m进制数并输出
//void change(int n,int m){
//    if( n == 0 ) return;
//
//    int t = n % m;
//    if(t < 0) t -= m,n += m;
//
//    if(t >= 10) t += 'A' - 10;
//    else t += '0';
//
//    change(n / m,m);
//
//    printf("%c",t);//递归输出
//}
//
//int main(){
//    int n,m;
//    cin >> n;
//
//}

//#include<iostream>
//using namespace std;
//const int N = 110;
//int na[N],nb[N];
//
//string add(string a,string b){
//    string res;
//    if(a.size() < b.size()) return add(b,a);
//    int len = max(a.size(), b.size());
//    for(int i = a.size();i > 0;i --) na[i] = a[a.size() - i] - '0';
//    for(int i = b.size();i > 0;i --) nb[i] = b[b.size() - i] - '0';
//
//    int t = 0;
//    for(int i = 1;i <= len;i ++){
//        na[i] += nb[i] + t;
//        t = na[i] / 10;
//        na[i] %= 10;
//    }
//
//    if(t) na[++len] = t;
//    while(na[len] == 0)len --;
//    for(int i = len;i > 0;i --) res += na[i] + '0';
//    return res;
//}
//
//int main(){
//    string a,b;
//    cin >> a >> b;
//    cout << add(a,b) << endl;
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//const int N = 110;
//
//string mul(string a,int k){
//    int na[N] = {0};
//    string res;
//    for(int i = a.size();i > 0;i --) na[i] = a[a.size() - i] - '0';
//
//    int t = 0;
//    for(int i = 1;i <= a.size();i ++){
//        na[i] = na[i] * k + t;
//        t = na[i] / 10;
//        na[i] %= 10;
//    }
//
//    int len = a.size();
//    if(t) na[++len] = t;
//    for(int i = len;i > 0;i --) res += na[i] + '0';
//    return res;
//}
//int main(){
//    string a;
//    int k;
//    cin >> a >> k;
//    cout << mul(a,k);
//    return 0;
//}

#include<iostream>

using namespace std;
const int N = 110;
string div(string a,int k){
    string res;
    int na[N] = {0};
    for(int i = a.size();i > 0;i --) na[i] = a[i - 1] - '0';

    int t = 0;
    for(int i = 1;i <= a.size();i ++){
        t = t * 10 + na[i];
        na[i] = t / k;
        t %= k;
    }

    int len = a.size();
    while(na[len] == 0 && len > 1) len --;
    for(int i = len;i > 0;i --) res += na[i] + '0';
    return res;
}

int main(){
    string a;
    int k;
    cin >> a >> k;
    cout << div(a,k) << endl;
    return 0;
}