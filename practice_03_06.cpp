//
// Created by 19116 on 2021/3/6.
//

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//int main(){
//    int t; cin >> t;
//    while(t --){
//        int n;cin >> n;
//        long long a[110] = {0};
//        for(int i = 1;i <= n;i ++){
//            cin >> a[i];
//            a[i] += a[i - 1];
//        }
//        bool fl = true;
//        for(int i = 1;i <= n;i ++){
//            if(a[i] < (i - 1) * i / 2) fl = false;
//        }
//        if(fl) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#define INF 99999999999999999
//using namespace std;
//const int N = 4e5 + 10,M = 9e5 + 10;
//typedef long long ll;
//inline ll read(){
//    ll x = 0;
//    char c = getchar();
//    while(!isdigit(c)) c = getchar();
//    while(isdigit(c)) x = x * 10 + c - '0',c = getchar();
//    return x;
//}
//struct edge{
//    ll u,v,w,next;
//    bool operator < (const edge& b)const{
//        return w < b.w;
//    }
//}e[N << 1],a[M << 1];
//ll head[N],cnt;
//void add(ll u,ll v,ll w){
//    e[++ cnt].u = u;
//    e[cnt].next = head[u];
//    e[cnt].v = v;
//    e[cnt].w = w;
//    head[u] = cnt;
//}
//
//ll fa[N][20],d1[N][20],d2[N][20];
//ll dep[N];
//void dfs(ll u,ll f){
//    fa[u][0] = f;
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].v;
//        if(v != f){
//            dep[v] = dep[u] + 1ll;
//            d1[v][0] = e[i].w;
//            d2[v][0] = -1;
//            dfs(v,u);
//        }
//    }
//}
//
//ll n,m;
//void work(){
//    for(int i = 1;i <= 18;i ++){
//        for(int j = 1;j <= n;j ++){
//            fa[j][i] = fa[fa[j][i - 1]][i - 1];
//            d1[j][i] = max(d1[j][i - 1],d1[fa[j][i - 1]][i - 1]);
//            d2[j][i] = max(d2[j][i - 1],d2[fa[j][i - 1]][i - 1]);
//            if(d1[j][i - 1] > d1[fa[j][i - 1]][i - 1]) d2[j][i] = max(d2[j][i],d1[fa[j][i - 1]][i - 1]);
//            else if(d1[j][i - 1] < d1[fa[j][i - 1]][i - 1]) d2[j][i] = max(d2[j][i],d1[j][i - 1]);
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
//ll solve(ll u,ll v,ll maxx){
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
//
//ll fat[N];
//ll getf(ll x){return x == fat[x] ? x : fat[x] = getf(fat[x]);}
//bool fl[M << 1];
//int main(){
//    n = read(),m = read();
//    for(int i = 1;i <= m;i ++){
//        a[i].u = read(),a[i].v = read(),a[i].w = read();
//    }
//    sort(a + 1,a + m + 1);
//    for(int i = 1;i <= n;i ++) fat[i] = i;
//
//    ll sum = 0ll;
//    for(int i = 1;i <= m;i ++){
//        ll fu = getf(a[i].u);
//        ll fv = getf(a[i].v);
//        if(fu != fv){
//            fat[fu] = fv;
//            sum += a[i].w;
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
//    for(int i = 1;i <= m;i ++) {
//        if(!fl[i]){
//            ll u = a[i].u,v = a[i].v,w = a[i].w;
//            ll lca = LCA(u,v);
//            ll mu = solve(u,lca,w);
//            ll mv = solve(v,lca,w);
//            ans = min(ans,sum - max(mu,mv) + w);
//        }
//    }
//    printf("%lld",ans);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//const int N = 5e5 + 10;
//struct edge{
//    int next,to;
//}e[N << 1];
//int head[N],c;
//int n;
//int in[N],ans[N],a[N];
//queue<int> q;
//void add(int u,int v){
//    e[++ c].next = head[u];
//    e[c].to = v;
//    head[u] = c;
//}
//int main(){
//    scanf("%d",&n);
//    for(int i = 1;i <= n;i ++){
//        int u;scanf("%d",&u);
//        scanf("%d",&a[i]);
//        int v;
//        while(scanf("%d",&v) && v){
//            add(u,v);
//            in[v] ++;
//        }
//    }
//
//    for(int i = 1;i <= n;i ++) if(!in[i]) q.push(i),ans[i] = a[i];
//    while(!q.empty()){
//        int u = q.front();q.pop();
//        for(int i = head[u];i;i = e[i].next){
//            int v = e[i].to;
//            in[v] --;
//            if(!in[v]) q.push(v);
//            ans[v] = max(ans[v],ans[u] + a[v]);
//        }
//    }
//
//    int t = 0;
//    for(int i = 1;i <= n;i ++) t = max(t,ans[i]);
//    printf("%d\n",t);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//const int N = 1e3 + 10,M = 1e6 + 10;
//int n,m;
//struct edge{
//    int next,to;
//}e[M];
//int head[N],cnt;
//bool is[N];
//void add(int u,int v){
//    e[++ cnt].next = head[u];
//    e[cnt].to = v;
//    head[u] = cnt;
//}
//int in[N];
//int topu(){
//    queue<int> q;
//    for(int i = 1;i <= n;i ++) if(!in[i]) q.push(i);
//}
//
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 1;i <= m;i ++){
//        memset(is,false,sizeof(is));
//        int x;scanf("%d",&x);
//        for(int j = 1;j <= x;j ++){
//            int t;scanf("%d",&t);
//            is[t] = true;
//        }
//        for(int j = 1;j <= n;j ++){
//            if(is[j]){
//                for(int k = 1;k <= n;k ++){
//                    if(!is[k]) add(j,k),in[k] ++;
//                }
//            }
//        }
//    }
//
//    printf("%d\n",topu());
//
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e3 + 10;
//int n,m,ans;
//int st[N],e[N][N],in[N];
//int stk[N],top;
//bool is[N],fl[N];
//
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 1;i <= m;i ++){
//        memset(is,0,sizeof(is));
//        int s;scanf("%d",&s);
//        for(int j = 1;j <= s;j ++){
//            scanf("%d",&st[j]);is[st[j]] = true;
//        }
//        for(int j = st[1];j <= st[s];j ++){
//            if(!is[j]){
//                for(int k = 1;k <= s;k ++){
//                    if(!e[j][st[k]]) e[j][st[k]] = 1,in[st[k]] ++;
//                }
//            }
//        }
//    }
//
//    do{
//        top = 0;
//        for(int i = 1;i <= n;i ++){
//            if(!in[i] && !fl[i]){
//                stk[++ top] = i;fl[i] = true;
//            }
//        }
//
//        for(int i = 1;i <= top;i ++){
//            for(int j = 1;j <= n;j ++){
//                if(e[stk[i]][j]) e[stk[i]][j] = 0,in[j] --;
//            }
//        }
//        ans ++;
//    }while(top);
//
//    printf("%d",ans - 1);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 110;
//int n,m;
//int e[N][N],stk[N],top;
//int in[N],out[N];
//bool fl[N];
//int c[N],u[N];
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 1;i <= n;i ++){
//        scanf("%d%d",&c[i],&u[i]);
//    }
//    for(int i = 1;i <= m;i ++){
//        int u,v,w;
//        scanf("%d%d%d",&u,&v,&w);
//        if(!e[u][v]) e[u][v] = w,in[v] ++,out[u] ++;
//    }
//    int cnt = 0;
//    do{
//        top = 0;
//        for(int i = 1;i <= n;i ++){
//            if(!in[i] && !fl[i]){
//                if(cnt) c[i] -= u[i];
//                stk[++ top] = i;
//                fl[i] = true;
//            }
//        }
//
//        for(int i = 1;i <= top;i ++){
//            if(c[stk[i]] <= 0) continue;
//            for(int j = 1;j <= n;j ++){
//                if(e[stk[i]][j]){
//                    c[j] += e[stk[i]][j] * c[stk[i]];
////                    cout << j << ": " << c[j] << endl;
//                    in[j] --;
//                    e[stk[i]][j] = 0;
//                }
//            }
//        }
//        cnt ++;
//    }while(top);
//    int flag = 0;
//    for(int i = 1;i <= n;i ++){
//        if(!out[i] && c[i] > 0){
//            printf("%d %d\n",i,c[i]);
//            flag = 1;
//        }
//    }
//    if(!flag) puts("NULL");
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//const int N = 110;
//struct edge{
//    int next,to,w;
//}e[N * N];
//int head[N],cnt;
//void add(int u,int v,int w){
//    e[++ cnt].next = head[u];
//    e[cnt].to = v;
//    e[cnt].w = w;
//    head[u] = cnt;
//}
//int n,m;
//int out[N],vis[N];
//int c[N];
//int main(){
//    queue<int> q;
//    scanf("%d%d",&n,&m);
//    for(int i = 1;i <= n;i++){
//        int u;
//        scanf("%d%d",&c[i],&u);
//        if(c[i] > 0){q.push(i);vis[i] = 1;}
//        else c[i] -= u;
//    }
//    for(int i = 1;i <= m;i ++){
//        int u,v,w;
//        scanf("%d%d%d",&u,&v,&w);
//        add(u,v,w);
//        out[u] = 1;
//    }
//    while(!q.empty()){
//        int u = q.front();q.pop();
//        if(c[u] <= 0) continue;
//        for(int i = head[u];i;i = e[i].next){
//            int v = e[i].to;
//            c[v] += e[i].w * c[u];
//            if(!vis[v]){
//                q.push(v);
//                vis[v] = 1;
//            }
//        }
//    }
//    int flag = 0;
//    for(int i = 1;i <= n;i ++){
//        if(!out[i] && c[i] > 0){
//            printf("%d %d\n",i,c[i]);
//            flag = 1;
//        }
//    }
//    if(!flag) puts("NULL");
//    return 0;
//}

