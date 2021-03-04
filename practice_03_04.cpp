//
// Created by 19116 on 2021/3/4.
//


//#include<iostream>
//#include<cmath>
//using namespace std;
//typedef long long ll;
//typedef long double lb;
//int main(){
//    lb p,a,b,c;
//    int tt;cin >> tt;
//    while(tt --){
//        cin >> p >> a >> b >> c;
//        lb ta,tb,tc;
//        ta = a * ceil(p * 1.0 / a);
//        tb = b * ceil(p * 1.0 / b);
//        tc = c * ceil(p * 1.0 / c);
//        cout << (ll)min(min(ta - p,tb - p),tc - p) << endl;
//    }
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<map>
//
//using namespace std;
//const int N = 1e5 + 10;
//int n,k;
//struct edge{
//    int next,to,w;
//}e[N << 1];
//int head[N],cnt;
//map<int,bool> ma;
//int st,id,maxx;
//int d,ed;
//
//void dfs(int u,int fa,int val){
//    if(val >= maxx){
//        maxx = val;
//        id = u;
//    }
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(v != fa){
//            dfs(v,u,val + e[i].w);
//        }
//    }
//}
//
//void add(int u,int v){
//    e[++ cnt].next = head[u];
//    e[cnt].to = v;
//    e[cnt].w = 1;
//    head[u] = cnt;
//}
//bool fl;int fr[N];
//void dfs2(int u,int fa,int det){
//    if(fl) return;
//    for(int i = head[u];i;i = e[i].next){
//        if(fl) return;
//        int v = e[i].to;
//        if(v == fa) continue;
//        if(v == det){
//            fr[u] = v;
//            fl = true;
//            return;
//        }
//        fr[u] = v;
//        dfs2(v,u,det);
//        if(fl) return;
//    }
//}
//
//int d1,dis[N];
//void dp(int u,int fa){
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(v == fa) continue;
//        dp(v,u);
//        d1 = max(d1,dis[u] + dis[v] + e[i].w);
//        dis[u] = max(dis[u],dis[v] + e[i].w);
//    }
//}
//
//
//int main(){
//    scanf("%d%d",&n,&k);
//    for(int i = 2;i <= n;i ++){
//        int u,v;
//        scanf("%d%d",&u,&v);
//        add(u,v);
//        add(v,u);
//    }
//    dfs(1,0,0);
//    maxx = 0;st = id;
//    dfs(st,0,0);
//    d = maxx,ed = id;
//
//    if(k == 1){
//        printf("%d",(2 * (n - 1) - d + 1));
//    }
//    else{
//        dfs2(st,0,ed);
//        ma[ed] = 1;ma[st] = 1;
//        for(int i = st;i != ed;i = fr[i]) ma[i] = 1;
//        for(int i = 1;i <= n;i ++){
//            if(ma[i] == 1){
//                for(int j = head[i];j;j = e[j].next){
//                    if(ma[e[j].to] == 1) e[j].w = -1;
//                }
//            }
//        }
//
//        dp(1,0);
//        printf("%d",2 * n - d - d1);
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e5 + 10;
//int n,k;
//struct edge{
//    int next,to;
//}e[N];
//int cnt,head[N];
//int dep[N],f[N],mxdep[N],ans[N];
//
//bool cmp(int a,int b){return a > b;}
//
//void add(int u,int v){
//    e[++ cnt].next = head[u];
//    e[cnt].to = v;
//    head[u] = cnt;
//}
//int maxx;
//int st,id;
//void dfs(int u,int fa,int val){
//    if(val >= maxx){
//        maxx = val;
//        id = u;
//    }
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(v != fa) dfs(v,u,val + 1);
//    }
//}
//void dfs1(int u,int fa,int val){
//    if(val >= maxx){
//        maxx = val;
//        id = u;
//    }
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(v != fa){
//            f[v] = u;
//            dfs(v,u,val + 1);
//        }
//    }
//}
//
//void dfs2(int u,int fa){
//    mxdep[u] = dep[u];
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(v != fa){
//            dep[v] = dep[u] + 1;
//            dfs2(v,fa);
//            mxdep[u] = max(mxdep[u],mxdep[v]);
//        }
//    }
//}
//int main(){
//    scanf("%d%d",&n,&k);
//    for(int i = 1;i < n;i ++){
//        int u,v;
//        scanf("%d%d",&u,&v);
//        add(u,v),add(v,u);
//    }
//    dfs(1,0,0);
//    maxx = 0,st = id;
//    dfs1(st,0,0);
//    int t = id;
//    for(int i = 1;i <= (maxx + 1) / 2;i ++) t = f[t];
//    dfs2(t,0);
//    for(int i = 1;i <= n;i ++) ans[i] = mxdep[i] - dep[i];
//    sort(ans + 1,ans + 1 + n,cmp);
//    printf("%d",ans[k + 1] + 1);
//    return 0;
//}

//#include<iostream>
//
//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e5 + 10;
//int n,k;
//struct edge{
//    int next,to;
//}e[N << 1];
//int cnt,head[N];
//int dep[N],f[N],mxdep[N],ans[N];
//
//bool cmp(int a,int b){return a > b;}
//
//void add(int u,int v){
//    e[++ cnt].next = head[u];
//    e[cnt].to = v;
//    head[u] = cnt;
//}
//int maxx;
//int st,id;
//void dfs(int u,int fa,int val){
//    if(val >= maxx){
//        maxx = val;
//        id = u;
//    }
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(v != fa) dfs(v,u,val + 1);
//    }
//}
//void dfs1(int u,int fa,int val){
//    if(val >= maxx){
//        maxx = val;
//        id = u;
//    }
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(v != fa){
//            f[v] = u;
//            dfs(v,u,val + 1);
//        }
//    }
//}
//
//void dfs2(int u,int fa){
//    mxdep[u] = dep[u];
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(v != fa){
//            dep[v] = dep[u] + 1;
//            dfs2(v,fa);
//            mxdep[u] = max(mxdep[u],mxdep[v]);
//        }
//    }
//}
//int main(){
//    scanf("%d%d",&n,&k);
//    for(int i = 1;i < n;i ++){
//        int u,v;
//        scanf("%d%d",&u,&v);
//        add(u,v),add(v,u);
//    }
//    dfs(1,0,0);
//    maxx = 0,st = id;
//    dfs1(st,0,0);
//    int t = id;
//    for(int i = 1;i <= (maxx + 1) / 2;i ++) t = f[t];
//    dfs2(t,0);
//    for(int i = 1;i <= n;i ++) ans[i] = mxdep[i] - dep[i];
//    sort(ans + 1,ans + 1 + n,cmp);
//    printf("%d",ans[k + 1] + 1);
//    return 0;
//}


//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<cstdio>
//
//using namespace std;
//const int N = 1e5 + 10;
//int n,k,c,maxx,ans_k;
//int cnt,head[N];
//struct edge{
//    int next,to;
//}e[N << 1];
//int dep[N],f[N],mxdep[N],ans[N];
//
//void add(int u,int v){
//    e[++ cnt].next = head[u];
//    e[cnt].to = v;
//    head[u] = cnt;
//}
//
//bool cmp(int a,int b){
//    return a > b;
//}
//
//void dfs1(int u,int fa){
//    if(dep[u] > maxx){
//        maxx = dep[u];
//        c = u;
//    }
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].next;
//        if(v != fa){
//            dep[v] = dep[u] + 1;
//            dfs1(v,u);
//        }
//    }
//}
//
//void dfs2(int u,int fa){
//    if(dep[u] > maxx){
//        maxx = dep[u];
//        c = u;
//    }
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].next;
//        if(v != fa){
//            dep[v] = dep[u] + 1;
//            f[v] = u;
//            dfs1(v,u);
//        }
//    }
//}
//
//void dfs3(int u,int fa){
//    mxdep[u] = dep[u];
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(v != fa){
//            dep[v] = dep[u] + 1;
//            dfs3(v,u);
//            mxdep[u] = max(mxdep[u],mxdep[v]);
//        }
//    }
//}
//int main(){
//    scanf("%d%d",&n,&k);
//    for(int i = 1;i < n;i ++){
//        int u,v;
//        scanf("%d%d",&u,&v);
//        add(u,v),add(v,u);
//    }
//    dfs1(1,0);
//    memset(dep,0,sizeof(dep));
//    maxx = 0;
//    dfs2(c,0);
//
//    int t = c;
//    for(int i = 1;i <= (dep[c] + 1) / 2;i ++) t = f[t];
//    memset(dep,0,sizeof(dep));
//    dfs3(t,0);
//    for(int i = 1;i <= n;i ++) ans[i] = mxdep[i] - dep[i];
//    sort(ans + 1,ans + 1 + n , cmp);
//    for(int i = k + 1;i <= n;i ++) ans_k = max(ans_k,ans[i]);
//    printf("%d\n",ans_k + 1);
//    return 0;
//}


#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e5 + 10;
//int n,k;
//struct edge{
//    int next,to;
//}e[N << 1];
//int head[N],cnt;
//int dep[N],f[N],mxdep[N],ans[N];
//int zj,num,ans_k;
//
//void add(int u,int v){
//    e[++ cnt].next = head[u];
//    e[cnt].to = v;
//    head[u] = cnt;
//}
//
//void dfs1(int u,int fa){
//    if(dep[u] > zj){
//        zj = dep[u];
//        num = u;
//    }
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(v != fa){
//            dep[v] = dep[u] + 1;
//            dfs1(v,u);
//        }
//    }
//}
//
//void dfs2(int u,int fa){
//    if(dep[u] > zj){
//        zj = dep[u];
//        num = u;
//    }
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(v != fa){
//            dep[v] = dep[u] + 1;
//            f[v] = u;
//            dfs2(v,u);
//        }
//    }
//}
//
//void dfs3(int u,int fa){
//    mxdep[u] = dep[u];
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(v != fa){
//            dep[v] = dep[u] + 1;
//            dfs3(v,u);
//            mxdep[u] = max(mxdep[u],mxdep[v]);
//        }
//    }
//}
//
//bool cmp(int a,int b) { return a >b;}
//
//int main(){
//    scanf("%d%d",&n,&k);
//    for(int i = 1;i < n;i ++){
//        int u,v;
//        scanf("%d%d",&u,&v);
//        add(u,v);
//        add(v,u);
//    }
//    dfs1(1,0);
//    memset(dep,0,sizeof(dep));
//    zj = 0;
//    dfs2(num,0);
//    int t = num;
//    for(int i = 1;i <= (dep[num] + 1) / 2;i ++) t = f[t];
//    memset(dep,0,sizeof(dep));
//    dfs3(t,0);
//    for(int i = 1;i <= n;i ++) ans[i] = mxdep[i] - dep[i];
//    sort(ans + 1,ans + n + 1,cmp);
//    for(int i = k + 1;i <= n;i ++) ans_k = max(ans_k,ans[i] + 1);
//    printf("%d\n",ans_k);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 2e5 + 10;
//typedef long long ll;
//struct edge{
//    ll next,to,w;
//}e[N << 2];
//ll head[N],cnt;
//ll n,m;
//ll dis1[N],dis2[N];
//int st,ed;
//
//void add(int u,int v,int w){
//    e[++ cnt].next = head[u];
//    e[cnt].to = v;
//    e[cnt].w = w;
//    head[u] = cnt;
//}
//
//void dfs1(int u,int fa){
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(v != fa){
//            dis1[v] = dis1[u] + e[i].w;
//            if(dis1[v] > dis1[st]) st = v;
//            dfs1(v,u);
//        }
//    }
//}
//
//void dfs2(int u,int fa){
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(v != fa){
//            dis2[v] = dis2[u] + e[i].w;
//            if(dis2[v] > dis2[ed]) ed = v;
//            dfs2(v,u);
//        }
//    }
//}
//
//void dfs3(int u,int fa){
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(v != fa){
//            dis1[v] = dis1[u] + e[i].w;
//            dfs3(v,u);
//        }
//    }
//}
//
//void dfs4(int u,int fa){
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(v != fa){
//            dis2[v] = dis2[u] + e[i].w;
//            dfs4(v,u);
//        }
//    }
//}
//
//int main(){
//    scanf("%lld%lld",&n,&m);
//    for(int i = 0;i < m;i ++){
//        ll u,v,w;
//        scanf("%lld%lld%lld",&u,&v,&w);
//        add(u,v,w);
//        add(v,u,w);
//    }
//    dfs1(1,0);
//    dfs2(st,0);
//    ll ans = dis2[ed];
//    memset(dis1,0,sizeof(dis1)),memset(dis2,0,sizeof(dis2));
//    dfs3(st,0),dfs4(ed,0);
//    ll t = 0;
//    for(int i = 1;i <= n;i ++){
//        ll d = min(dis1[i],dis2[i]);
//        t = max(d,t);
//    }
//    printf("%lld\n",ans + t);
//    return 0;
//}



//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 5e5 + 10;
//int n,m,s;
//struct edge{
//    int next,to;
//}e[N];
//int head[N],cnt;
//int lg[N];
//void add(int u,int v){
//    e[++ cnt].next = head[u];
//    head[u] = cnt;
//    e[cnt].to = v;
//}
//int dep[N],fa[N][20];
//bool vis[N];
//void dfs(int u){
//    for(int i = 1;i <= 16;i ++){
//        if(dep[u] < ( 1 << i )) break;
//        fa[u][i] = fa[fa[u][i - 1]][i - 1];
//    }
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(v != fa[u][0]){
//            fa[v][0] = u;
//            dep[v] = dep[u] + 1;
//            dfs(v);
//        }
//    }
//}
//
//int LCA(int x,int y){
//    if(dep[x] < dep[y]) swap(x,y);
//    int t = dep[x] - dep[y];
//    for(int i = 0;i <= 16;i ++) if(t & (1 << i)) x = fa[x][i];
//    if(x == y)return x;
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
//    scanf("%d%d%d",&n,&m,&s);
//    for(int i = 1;i < n;i ++){
//        int u,v;scanf("%d%d",&u,&v);
//        add(u,v);add(v,u);
//    }
//
//    dfs(s);
//
//    for(int i = 1;i <= m;i ++){
//        int x,y;scanf("%d%d",&x,&y);
//        printf("%d\n",LCA(x,y));
//    }
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 5e5 + 10;
//int fa[N][20],dep[N];
//int n,m,s;
//int head[N],cnt;
//struct edge{
//    int next,to;
//}e[N];
//
//void add(int u,int v){
//    e[++ cnt].next = head[u];
//    e[cnt].to = v;
//    head[u] = cnt;
//}
//
//void dfs(int u){
//    for(int i = 1;i <= 16;i ++){
//        fa[u][i] = fa[fa[u][i - 1]][i - 1];
//    }
//
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(v != fa[u][0]){
//            fa[v][0] = u;
//            dep[v] = dep[u] + 1;
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
//int main(){
//    scanf("%d%d%d",&n,&m,&s);
//    for(int i = 1;i < n;i ++){
//        int u,v;scanf("%d%d",&u,&v);
//        add(u,v);add(v,u);
//    }
//
//    dfs(s);
//
//    for(int i = 1;i <= m;i ++){
//        int x,y;
//        scanf("%d%d",&x,&y);
//        printf("%d\n",LCA(x,y));
//    }
//    return 0;
//}

//
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//typedef long long ll;
//ll m,a,b;
//inline ll rd(){
//    ll x = 0;
//    char c = getchar();
//    while(!isdigit(c)) c = getchar();
//    while(isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48),c = getchar();
//    return x;
//}
//ll f[100];
//inline void lca(ll a,ll b){
//    if(a < b)swap(a,b);
//    if(a == b){printf("%lld\n",a);return;}
//    lca(b,a - f[a]);
//}
//
//int main(){
//    m = rd();
//    f[1] = 0;f[2] = 1;
//    for(int i = 3;i <= 61;i ++) f[i] = f[i - 1] + f[i - 2];
//    for(int i = 0;i < m;i ++){
//        a = rd(),b = rd();
//        lca(a,b);
//    }
//    return 0;
//}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 5e3 + 10,M = 2e5 + 10;
int fa[N];int n,m;
struct edge{
    int u,v,w;
    bool operator <(const edge& b)const{
        return w < b.w;
    }
}e[M];

int getf(int x){return x == fa[x] ? x : fa[x] = getf(fa[x]);}

int kruscal(){
    for(int i = 1;i <= n;i ++) fa[i] = i;
    sort(e,e + m);
    int ans = 0;
    for(int i = 0;i < m;i ++){
        int fu = getf(e[i].u);
        int fv = getf(e[i].v);
        if(fu != fv){
            fa[fu] = fv;
            ans += e[i].w;
        }
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i ++) fa[i] = i;
    for(int i = 0;i < m;i ++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        int fu = getf(u),fv = getf(v);
        if(fu != fv) fa[fu] = fv;
        e[i] = {u,v,w};
    }
    bool fl = 1;
    int t = fa[1];
    for(int i = 2;i <= n;i ++){
        if(fa[i] != t){
            fl = 0;
            break;
        }
    }

    if(!fl) puts("orz");
    else printf("%d\n",kruscal());
    return 0;
}

