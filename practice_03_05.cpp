////
//// Created by 19116 on 2021/3/5.
////
//
//#include<iostream>
//#include<stack>
//#include<vector>
//
//using namespace std;
//const int N = 1e5 + 10;
//
//
//int main(){
//    int tt ;cin >> tt;
//    while(tt --){
//        int n,a[N];
//        cin >> n;
//        vector<int> s;
//        stack<int> st;
//        vector<int> ans;
//        for(int i = 1;i <= n;i ++){
//            cin >> a[i];
//            s.push_back(i);
//        }
//        for(int i = n;i >= 1;i --){
//            if(s[s.size() - 1] != a[i]){
//                st.push(a[i]);
//            }
//            else{
//                ans.push_back(a[i]);
//                while(!st.empty()){
//                    ans.push_back(st.top());
//                    st.pop();
//                }
//            }
//            s.erase(lower_bound(s.begin(),s.end(),a[i]));
//        }
//
//        while(!st.empty()){
//            ans.push_back(st.top());
//            st.pop();
//        }
//
//        for(int i = 0;i < ans.size();i ++) cout << ans[i] << " ";
//        cout << endl;
//    }
//    return 0;
//}

//
//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//const int N = 5e5 + 10;
//struct edge{
//    int next,to;
//}e[N];
//int head[N], cnt;
//int n,m;
//int fa[N][20],dep[N];
//
//void add(int u,int v){
//    e[++ cnt].next = head[u];
//    e[cnt].to = v;
//    head[u] = cnt;
//}
//
//void dfs(int u){
//    for(int i = 1;i <= 16;i ++){
//        if(dep[u] < (1 << i)) break;
//        fa[u][i] = fa[fa[u][i - 1]][i - 1];
//    }
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(v != fa[u][0]){
//            dep[v] = dep[u] + 1;
//            fa[v][0] = u;
//            dfs(v);
//        }
//    }
//}
//
//int LCA(int x,int y){
//    if(dep[x] < dep[y]) swap(x,y);
//    int t = dep[x] - dep[y];
//    for(int i = 0;i <= 16;i ++) if(t & (1 << i)) x = fa[x][i];
//    if(x == y) return x;
//    for(int i = 16;i >= 0;i --){
//        if(fa[x][i] != fa[y][i]){
//            x = fa[x][i];
//            y = fa[y][i];
//        }
//    }
//    return fa[x][0];
//}
//
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 1;i < n;i ++){
//        int u,v;
//        scanf("%d%d",&u,&v);
//        add(u,v);add(v,u);
//    }
//    dfs(1);
//    for(int i = 0;i < m;i ++){
//        int x,y,z;
//        scanf("%d%d%d",&x,&y,&z);
//        int t1 = LCA(x,y);
//        int t2 = LCA(y,z);
//        int t3 = LCA(x,z);
//        int p;
//        if(t1 == t2) p = t3;
//        if(t2 == t3) p = t1;
//        if(t1 == t3) p = t2;
//        int c = dep[x] + dep[y] + dep[z] - dep[t1] - dep[t2] - dep[t3];
//        printf("%d %d\n",p,c);
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 2e5 + 10;
//int n,m;
//struct edge{
//    int u,v,w;
//    bool operator < (const edge& b) const{
//        return w < b.w;
//    }
//}e[N];
//int fa[N];
//int getf(int x){return fa[x] == x ? x : fa[x] = getf(fa[x]);}
//
//int kruscal(){
//    int ans = 0;
//    for(int i = 1;i <= n;i ++) fa[i] = i;
//    sort(e,e + m);
//    for(int i = 0;i < m;i ++){
//        int fu = getf(e[i].u);
//        int fv = getf(e[i].v);
//        if(fu != fv){
//            fa[fu] = fv;
//            ans += e[i].w;
//        }
//    }
//    return ans;
//}
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 0;i < m;i ++){
//        int u,v,w;
//        scanf("%d%d%d",&u,&v,&w);
//        e[i] = {u,v,w};
//    }
//    int ans = kruscal();
//    int t = fa[1];bool fl = true;
//    for(int i = 1;i <= m;i ++){
//        if(t != fa[i]) fl = false;
//    }
//    if(fl) printf("%d\n",ans);
//    else printf("%d\n",ans);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<cmath>
//
//using namespace std;
//const int N = 1e3 + 10,M = 1e6 + 10;
//struct edge{
//    int u,v;
//    double w;
//    bool operator < (const edge& b)const{
//        return w < b.w;
//    }
//}e[M];
//int cnt;
//struct p{
//    double x,y;
//}a[N];
//int n,m;
//double dis(int i,int j){
//    return sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y));
//}
//
//int fa[N];
//int getf(int x){return x == fa[x] ? x : fa[x] = getf(fa[x]);}
//
//double kruscal(){
//    double ans = 0;
//    for(int i = 0;i < cnt;i ++){
//        int fu = getf(e[i].u),fv = getf(e[i].v);
//        if(fu != fv){
//            fa[fu] = fv;
//            ans += e[i].w;
//        }
//    }
//    return ans;
//}
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 1;i <= n;i ++) scanf("%lf%lf",&a[i].x,&a[i].y);
//    for(int i = 1;i <= n;i ++){
//        for(int j = i + 1;j <= n;j ++){
//            e[cnt ++] = {i,j,dis(i,j)};
//        }
//    }
//    sort(e, e + cnt);
//    for(int i = 1;i <= n;i ++) fa[i] = i;
//    for(int i = 1;i <= m;i ++){
//        int u,v;scanf("%d%d",&u,&v);
//        int fu = getf(u),fv = getf(v);
//        if(fu != fv) fa[fu] = fv;
//    }
//    printf("%.2f\n",kruscal());
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<cmath>
//
//using namespace std;
//const int N = 1e6 + 10;
//struct edge{
//    int u,v;
//    double w;
//    bool operator < (const edge& b)const{
//        return w < b.w;
//    }
//}e[N];
//int cnt;
//struct p{
//    double x,y;
//}a[N];
//double dis(int i,int j){
//    return sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y));
//}
//int fa[N];
//int getf(int x){return x == fa[x] ? x : fa[x] = getf(fa[x]);}
//int s,p;
//double kruscal(){
//    double ans = 0;int sum = 0;
//    for(int i = 1;i <= p;i ++) fa[i] = i;
//    for(int i = 0;i < cnt;i ++){
//        int fu = getf(e[i].u),fv = getf(e[i].v);
//        if(fu != fv){
//            fa[fu] = fv;
//            ans = max(ans,e[i].w);
//            sum ++;
//            if(sum == p - 1 - (s - 1)) break;
//        }
//    }
//    return ans;
//}
//int main(){
//    scanf("%d%d",&s,&p);
//    for(int i = 1;i <= p;i ++) scanf("%lf%lf",&a[i].x,&a[i].y);
//    for(int i = 1;i <= p;i ++){
//        for(int j = i + 1;j <= p;j ++){
//            e[cnt ++] = {i,j,dis(i,j)};
//        }
//    }
//    sort(e, e + cnt);
//    printf("%.2f\n",kruscal());
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cmath>
//#include<cstring>
//
//using namespace std;
//const int N = 1e5 + 10;
//int n,m;
//struct edge{
//    int u,v,w,in;
//    bool operator < (const edge& b)const{
//        return w < b.w;
//    }
//}e[N * 3];
//struct node{
//    int u,v,w,next;
//}G[(N * 3) << 1];
//int head[N],fat[N],cnt;
//int fa[N][25],d1[N][25],d2[N][25],dep[N];
//
//long long ans;int minn = 1e9;
//
//inline int read(){
//    int x = 0;char c = getchar();
//    while(!isdigit(c)) c = getchar();
//    while(isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48),c = getchar();
//    return x;
//}
//
//void add(int u,int v,int w){
//    G[++ cnt].next = head[u];
//    G[cnt].v = v;
//    G[cnt].w = w;
//    head[u] = cnt;
//}
//int getf(int x){return x == fat[x] ? x : fat[x] = getf(fat[x]);}
//
//void kruscal(){
//    int sum = 0;
//    for(int i = 1;sum != n - 1;i ++){
//        int u = e[i].u,v = e[i].v,fu = getf(u),fv = getf(v);
//        if(fu != fv){
//            fat[fu] = fv;
//            sum ++;
//            e[i].in = 1;
//            ans += e[i].w;
//            add(e[i].u,e[i].v,e[i].w);
//            add(e[i].v,e[i].u,e[i].w);
//        }
//    }
//}
//
//void dfs(int u){
//    for(int i = 1;i <= 16;i ++){
//        if(dep[u] < (1 << i)) break;
//        fa[u][i] = fa[fa[u][i - 1]][i - 1];
//        d1[u][i] = max(d1[u][i - 1],d1[fa[u][i - 1]][i - 1]);
//        if(d1[u][i - 1] == d1[fa[u][i - 1]][i - 1]){
//            d2[u][i] = max(d2[u][i - 1],d2[fa[u][i - 1]][i - 1]);
//        }
//        else{
//            d2[u][i] = max(min(d1[u][i - 1],d1[fa[u][i - 1]][i - 1]),
//                           max(d2[u][i - 1],d2[fa[u][i - 1]][i - 1]));
//        }
//    }
//
//    for(int i = head[u];i;i = G[i].next){
//        int v = G[i].v;
//        if(v != fa[u][0]){
//            fa[v][0] = u;
//            dep[v] = dep[u] + 1;
//            d1[v][0] = G[i].w;
//            d2[v][0] = -1;
//            dfs(v);
//        }
//    }
//}
//
//int LCA(int x,int y){
//    if(dep[x] < dep[y]) swap(x,y);
//    int t = dep[x] - dep[y];
//    for(int i = 0;i <= 16;i ++) if(t & (1 << i)) x = fa[x][i];
//    if(x == y) return x;
//    for(int i = 16;i >= 0;i --){
//        if(fa[x][i] != fa[y][i]){
//            x = fa[x][i];
//            y = fa[y][i];
//        }
//    }
//    return fa[x][0];
//}
//
//void solve(int s,int t,int w){
//    int m1 = 0,m2 = 0,k = dep[s] - dep[t];
//    for(int i = 0;i <= 16;i ++){
//        if(k & (1 << i)) {
//            m2 = max(m2,d2[s][i]);
//            if(d1[s][i] > m1) {
//                m2 = max(m2,m1);
//                m1 = d1[s][i];
//            }
//        }
//    }
//    if(m1 == w) minn = min(minn,w - m2);
//    else minn = min(minn ,w - m1);
//}
//int main(){
//    n = read(),m = read();
//    for( int i = 1;i <= n;i ++) fat[i] = i;
//    for(int i = 1;i <= m;i ++) {
//        e[i].u = read();
//        e[i].v = read();
//        e[i].w = read();
//    }
//    sort(e + 1,e + m + 1);
//    kruscal();
//    dfs(1);
//    for(int i = 1;i <= m;i ++){
//        if(!e[i].in){
//            int u = e[i].u,v = e[i].v;
//            int p = LCA(u,v);
//            solve(u,p,e[i].w);
//            solve(v,p,e[i].w);
//        }
//    }
//    printf("%d\n",ans + minn);
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#define INF 1111111111111111111
//
//using namespace std;
//typedef long long ll;
//const int N = 4e5 + 10,M = 9e5 + 10;
//
//inline ll read(){
//    ll x = 0;char c = getchar();
//    while(!isdigit(c)) c = getchar();
//    while(isdigit(c)) x = x * 10 + c - '0',c = getchar();
//    return x;
//}
//struct edge{
//    ll u,v,w;
//    ll next;
//    bool operator < (const edge& b)const{
//        return w < b.w;
//    }
//}G[N << 1];
//ll head[N],cnt;
//void add(ll u,ll v,ll w){
//    G[++ cnt].next = head[u];
//    G[cnt].v = v;
//    G[cnt].w = w;
//    G[cnt].u = u;
//    head[u] = cnt;
//}
//
//ll fa[N][20],dep[N];
//ll d1[N][20],d2[N][20];
//
//void dfs(ll u,ll f){
//    fa[u][0] = f;
//    for(ll i = head[u];i;i = G[i].next){
//        ll v = G[i].v;
//        if(v != f){
//            dep[v] = dep[u] + 1;
//            d1[v][0] = G[i].w;
//            d2[v][0] = -INF;
//            dfs(v,u);
//        }
//    }
//}
//
//ll n;
//void work(){
//    for(ll i = 1;i <= 16;i ++){
//        for(ll j = 1;j <= n;j ++){
//            fa[j][i] = fa[fa[j][i - 1]][i - 1];
//            d1[j][i] = max(d1[j][i - 1],d1[fa[j][i - 1]][i - 1]);
//            d2[j][i] = max(d2[j][i - 1],d2[fa[j][i - 1]][i - 1]);
//            if(d1[j][i - 1] > d1[fa[j][i - 1]][i - 1]) d2[j][i] = max(d2[j][i],d1[fa[j][i - 1]][i - 1]);
//            else if(d1[j][i - 1] < d1[fa[j][i - 1]][i - 1])
//                d2[j][i] = max(d2[j][i],d1[j][i - 1]);
//        }
//    }
//}
//
//ll LCA(ll x,ll y){
//    if(dep[x] < dep[y]) swap(x,y);
//    ll t = dep[x] - dep[y];
//    for(int i = 0;i <= 16;i ++) if(t & (1 << i)) x = fa[x][i];
//    if(x == y) return x;
//    for(int i = 16;i >= 0;i --){
//        if(fa[x][i] != fa[y][i]){
//            x = fa[x][i];
//            y = fa[y][i];
//        }
//    }
//    return fa[x][0];
//}
//
//ll qmax(ll u,ll v,ll maxx){
//    ll ans = -INF;
//    for(int i = 18;i >= 0;i --){
//        if(dep[fa[u][i]] >= dep[v]){
//            if(maxx != d1[u][i]) ans = max(ans,d1[u][i]);
//            else ans = max(ans,d2[u][i]);
//            u = fa[u][i];
//        }
//    }
//    return ans;
//}
//ll m;edge a[M << 1];
//ll fat[N];
//ll getf(ll x){return x == fat[x] ? x : fat[x] = getf(fat[x]);}
//
//bool fl[M << 1];
//
//int main(){
//    n = read();m = read();
//    for(int i = 1;i <= m;i ++){
//        a[i].u = read(),a[i].v = read(),a[i].w = read();
//    }
//    sort(a + 1,a + 1 + m);
//
//    for(int i = 1;i <= n;i ++) fat[i] = i;
//    ll sum = 0;
//    for(int i = 1;i <= m;i ++){
//        ll fu = getf(a[i].u);
//        ll fv = getf(a[i].v);
//        if(fu != fv){
//            fat[fu] = fv;
//            cnt += a[i].w;
//            add(a[i].u,a[i].v,a[i].w);
//            add(a[i].v,a[i].u,a[i].w);
//            fl[i] = true;
//        }
//    }
//
//    d2[1][0] = -INF;
//    dep[1] = 1;
//    dfs(1,-1);
//    work();
//    ll ans = INF;
//
//    for(ll i = 1;i <= m;i ++){
//        if(!fl[i]){
//            ll u = a[i].u;
//            ll v = a[i].v;
//            ll w = a[i].w;
//            ll lca = LCA(u,v);
//            ll mu = qmax(u,lca,w);
//            ll mv = qmax(v,lca,w);
//            ans = min(ans,sum - max(mu,mv) + w);
//        }
//    }
//
//    printf("%lld",ans);
//    return 0;
//}