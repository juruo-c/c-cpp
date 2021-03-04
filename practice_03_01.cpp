//
// Created by 19116 on 2021/3/1.
//

//#include<iostream>
//#define iv inline void
//
//template<class T>
//iv rd(T &x){
//    x = 0;int fl = 1;
//    char c = getchar();
//    while(!isdigit(c)){
//        if(c == '-') fl = -1;
//        c = getchar();
//    }
//    while(isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48),c = getchar();
//}
//
//template<class T>
//inline void wr(T &x){
//    if(x < 0) x = -x,putchar('-');
//    T sta[35];
//    T top = 0;
//    do{
//        sta[top ++] = x % 10,x /= 10;
//    }while(x);
//    while(top) putchar(sta[-- top] + '0');
//}
//
//int main(){
//    int n;
//    while(true){
//        rd(n);
//        if(!n)break;
//        wr(n);
//    }
//    return 0;
//}
//#include<iostream>
//#define rep(i,a,b) for(int i = (a);i <= (b);i ++)
//using namespace std;
//
//int main(){
//    rep(i,1,2){
//        cout << i << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cmath>
//#include<algorithm>
//#define vc pt
//#define db double
//#define rep(i,a,b) for(int i = (a);i <= (b);i ++)
//#define _rep(i,a,b) for(int i = (a);i >= (b);i --)
//using namespace std;
//const int N = 1e5 + 10;
//const db eps = 1e-8;
//int dcmp(db x){if(fabs(x) <= eps) return 0;return x > 0 ? 1 : -1;}
//struct pt{
//    db x,y;
//    pt(){}
//    pt(db x,db y): x(x),y(y) {}
//}p[N],s[N];
//pt operator - (pt a,pt b){return pt(a.x - b.x,a.y - b.y);}
//pt operator + (pt a,pt b){return pt(a.x + b.x,a.y + b.y);}
//pt operator * (pt a,db d){return pt(a.x * d,a.y * d);}
//db operator * (pt a,pt b){return a.x * b.x + a.y * b.y;}
//db len(vc a){return sqrt(a * a);}
//db cs(vc a,vc b){return a.x * b.y - a.y * b.x;}
//
//bool Acmp(pt a,pt b){
//    if(fabs(a.x - b.x) <= eps) return a.y < b.y;
//    return a.x < b.x;
//}
//int Andrew(pt p[],int n,pt s[]){
//    sort(p + 1,p + 1 + n,Acmp);
//    s[1] = p[1];
//    int m = 1;
//    rep(i,2,n){
//        while(m > 1 && cs(s[m] - s[m - 1],p[i] - s[m]) <= 0) m -- ;
//        s[++ m] = p[i];
//    }
//    int k = m;
//    _rep(i,n - 1,1){
//        while(m > k && cs(s[m] - s[m - 1],p[i] - s[m]) <= 0) m --;
//        s[++ m] = p[i];
//    }
//    if(n > 1) m --;
//    return m;
//}
//
//#include<iostream>
//#include<cstdio>
//#include<cmath>
//#include<algorithm>
//#define vc pt
//#define db double
//#define rep(i,a,b) for(int i = (a);i <= (b);i ++)
//#define _rep(i,a,b) for(int i = (a);i >= (b);i --)
//using namespace std;
//const int N = 1e5 + 10;
//const db eps = 1e-8;
//int dcmp(db x){if(fabs(x) <= eps) return 0;return x > 0 ? 1 : -1;}
//struct pt{
//    db x,y;
//    pt(){}
//    pt(db x,db y): x(x),y(y) {}
//}p[N],s[N];
//pt operator - (pt a,pt b){return pt(a.x - b.x,a.y - b.y);}
//pt operator + (pt a,pt b){return pt(a.x + b.x,a.y + b.y);}
//pt operator * (pt a,db d){return pt(a.x * d,a.y * d);}
//db operator * (pt a,pt b){return a.x * b.x + a.y * b.y;}
//db len(vc a){return sqrt(a * a);}
//db cs(vc a,vc b){return a.x * b.y - a.y * b.x;}
//db cs(pt a,pt b,pt c){return (b - a).x * (c - a).y - (b - a).y * (c - a).x;}
//struct line{
//    pt s,e;
//    db deg;
//    line(){}
//    line(pt s,pt e) :s(s),e(e) {deg = atan2((e - s).y,(e - s).x);}
//    bool operator < (const line& b)const{
//        if(fabs(deg - b.deg) < eps) return cs(s,b.s,e) < eps;
//        return deg < b.deg;
//    }
//};
//pt lip(line a,line b){
//    pt v = a.e - a.s,w = b.e - b.s,u = a.e - b.e;
//    db t = cs(u,w) / cs(v,w);
//    return a.e + v * t;
//}
//bool oR(pt a,line b){
//    return cs(b.s,b.e,a) < eps;
//}
//int HPI(line L[],line q[],int n,pt t[]){
//    sort(L + 1,L + 1 + n);
//    int l = 1,r = 1;q[1] = L[1];
//    rep(i,2,n){
//        if(!dcmp(L[i].deg - L[i - 1].deg)) continue;
//        while(l < r && oR(t[r - 1],L[i])) r--;
//        while(l < r && oR(t[l],L[i])) l ++;
//        q[++ r] = L[i];
//        if(l < r) t[r - 1] = lip(q[r],q[r - 1]);
//    }
//    while(l < r && oR(t[r - 1],q[l])) r --;
//    while(l < r && oR(t[l],q[r])) l ++;
//    s[r] = lip(q[l],q[r]);
//    if(r - l + 1 <= 1) return 0;
//    return r - l + 1;
//}

//#include<iostream>
//#include<cstdio>
//#include<cmath>
//#include<algorithm>
//#define db double
//#define rep(i,a,b) for(int i = (a);i <= (b);i ++)
//#define _rep(i,a,b) for(int i = (a);i >= (b);i --)
//using namespace std;
//const int N = 2e5 + 10;
//struct pt{
//    db x,y;
//    int id;
//};
//bool cmp_x(pt a,pt b){
//    return a.x < b.x || (a.x == b.x && a.y < b.y);
//}
//bool cmp_y(pt a,pt b){
//    return a.y < b.y;
//}
//int n;
//pt a[N];
//db md;//mindist
//int ansa,ansb;
//inline void upd_ans(pt a,pt b){
//    db d = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + .0);
//    if(d < md) md = d,ansa = a.id,ansb = b.id;
//}
//void solve(int l,int r){
//    if(r - l <= 3){
//        rep(i,l,r){
//            rep(j,i + 1,r){
//                upd_ans(a[i],a[j]);
//            }
//            sort(a + l,a + r + 1,cmp_y);
//        }
//        return;
//    }
//    int m = (l + r) >> 1;
//    int midx = a[m].x;
//    solve(l,m),solve(m + 1,r);
//    pt t[N];
//    merge(a + l,a + m + 1,a + m + 1,a + r + 1,t,cmp_y);
//    copy(t,t + r - l + 1,a + l);
//    int tsz = 0;
//    rep(i,l,r){
//        if(abs(a[i].x - midx) < md){
//            for(int j = tsz - 1;j >= 0 && a[i].y - t[j].y < md;j --)
//                upd_ans(a[i],t[j]);
//            t[tsz ++] = a[i];
//        }
//    }
//}
//int main(){
//    scanf("%d",&n);
//    rep(i,0,n - 1) scanf("%lf%lf",&a[i].x,&a[i].y);
//    sort(a,a + n,cmp_x);
//    md = 1e20;
//    solve(0,n - 1);
//    printf("%.4f",md);
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<cstdio>
//#define rep(i,a,b) for(int i = (a);i <= (b);i ++)
//#define _rep(i,a,b) for(int i = (a);i >= (b);i --)
//#define db double
//using namespace std;
//const int N = 310;
//const db INF = 9999999999.0;
//struct line{
//    db k,b;
//    line(){}
//    line(db k,db b) : k(k),b(b) {}
//}l[N];
//int n;db x[N],y[N];
//db work(db x){
//    db ans = 0;
//    rep(i,1,n - 1) ans = max(ans,l[i].k * x + l[i].b);
//    return ans;
//}
//int main(){
//    scanf("%d",&n);
//    rep(i,1,n) scanf("%lf",&x[i]);
//    rep(i,1,n) scanf("%lf",&y[i]);
//    rep(i,1,n - 1){
//        db k = (y[i + 1] - y[i]) / (x[i + 1] - x[i]);
//        db b = - k * x[i] + y[i];
//        l[i] = line(k,b);
//    }
//    db ans = INF;
//    rep(i,1,n){
//        ans = min(ans,work(x[i]) - y[i]);
//    }
//    rep(i,1,n - 1){
//        rep(j,i + 1,n - 1){
//            db o = (l[j].b - l[i].b) / (l[i].k - l[j].k);
//            rep(k,1,n - 1){
//                if(x[k] <= o && o <= x[k + 1]){
//                    ans = min(ans,work(o) - l[k].k * o - l[k].b);
//                }
//            }
//        }
//    }
//    printf("%.3f",ans);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cmath>
//#include<algorithm>
//#define vc pt
//#define db double
//#define rep(i,a,b) for(int i = (a);i <= (b);i ++)
//#define _rep(i,a,b) for(int i = (a);i >= (b);i --)
//using namespace std;
//const int N = 1e5 + 10;
//const db eps = 1e-8;
//int dcmp(db x){if(fabs(x) <= eps) return 0;return x > 0 ? 1 : -1;}
//struct pt{
//    db x,y;
//    pt(){}
//    pt(db x,db y): x(x),y(y) {}
//}p[N],s[N];
//pt operator - (pt a,pt b){return pt(a.x - b.x,a.y - b.y);}
//pt operator + (pt a,pt b){return pt(a.x + b.x,a.y + b.y);}
//pt operator * (pt a,db d){return pt(a.x * d,a.y * d);}
//db operator * (pt a,pt b){return a.x * b.x + a.y * b.y;}
//db len(vc a){return sqrt(a * a);}
//db cs(vc a,vc b){return a.x * b.y - a.y * b.x;}
//db cs(pt a,pt b,pt c){return (b - a).x * (c - a).y - (b - a).y * (c - a).x;}
//
//bool Acmp(pt a,pt b){
//    if(fabs(a.x - b.x) <= eps) return a.y < b.y;
//    return a.x < b.x;
//}
//int Andrew(pt p[],int n,pt s[]){
//    sort(p + 1,p + 1 + n,Acmp);
//    int m = 0;
//    rep(i,1,n){
//        while(m > 1 && cs(s[m] - s[m - 1],p[i] - s[m]) <= 0) m -- ;
//        s[m ++] = p[i];
//    }
//    int k = m;
//    _rep(i,n - 1,1){
//        while(m > k && cs(s[m] - s[m - 1],p[i] - s[m]) <= 0) m --;
//        s[m ++] = p[i];
//    }
//    if(n > 1) m --;
//    return m;
//}
//int gd(pt a,pt b){return (b - a).x * (b - a).x + (b - a).y * (b - a).y;}
//int rc(pt s[],int m){//rotating_calipers
//    int ans = 0,cur = 1;
//    rep(i,0,m - 1){
//        while(cs(s[i],s[i + 1],s[cur]) < cs(s[i],s[i + 1],s[cur + 1]))
//            cur = (cur + 1) % m;
//        ans = max(ans,max(gd(s[i],s[cur]),gd(s[i + 1],s[cur])));
//    }
//    return ans;
//}


//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#define rep(i,a,b) for(int (i) = (a);(i) <= (b);(i) ++)
//#include<vector>
//
//using namespace std;
//const int N = 2e5 + 10;
//const int inf = 0x3f3f3f3f;
//int n;
//struct edge{
//    int next,to;
//}e[N];
//int head[N],cnt;
//bool vis[N];
//int ans;
//void add(int u,int v){
//    e[++ cnt].next = head[u];
//    e[cnt].to = v;
//    head[u] = cnt;
//}
//void dfs(int u,int now,int len){
//    if(u == now && vis[u]){
//        ans = min(ans,len);
//    }
//    if(vis[u]) return;
////    cout << u << " " << len << endl;
//    vis[u] = 1;
//    for(int i = head[u];~i;i = e[i].next){
//        int v = e[i].to;
//        dfs(v,now,len + 1);
//    }
//}
//int main(){
//    memset(head,-1,sizeof(head));
//    scanf("%d",&n);
//    rep(i,1,n){
//        int v;scanf("%d",&v);
//        add(i,v);
//    }
////    rep(i,1,n){
////        cout << i << ": " ;
////        rep(j,0,e[i].size() - 1){
////            cout << e[i][j] << " " ;
////        }
////        cout << endl;
////    }
//    ans = inf;
//    rep(i,1,n){
//        memset(vis,0,sizeof(vis));
//        dfs(i,i,0);
//    }
//    printf("%d",ans);
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#define rep(i,a,b) for(int (i) = (a);(i) <= (b);(i) ++)
//using namespace std;
//const int N = 2e5 + 10;
//int fa[N];
//int getf(int x,int& cnt){
//    cnt ++;
//    return x == fa[x] ? x : getf(fa[x],cnt);
//}
//int n;
//int main(){
//    scanf("%d",&n);
//    rep(i,1,n) fa[i] = i;
//    int ans = 0x3f3f3f3f;
//    rep(i,1,n){
//        int cnt = 0,x;
//        scanf("%d",&x);
//        if(getf(x,cnt) == i) ans = min(ans,cnt);
//        else fa[i] = x;
//    }
//    printf("%d",ans);
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//
//using namespace std;
//const int N = 1e5 + 10;
//int n,h[N],d[N],s[N],fl;
//bool vis[N];
//int dfs(int now,int sum){
//    if(h[now]) return sum - 1 + h[now];
//    if(vis[now]){
//        h[now] = sum - s[now];
//        fl = now;
//        return sum - 1;
//    }
//    vis[now] = true;
//    s[now] = sum;
//    int ans = dfs(d[now],sum + 1);
//    if(fl){
//        if(now == fl) fl = 0;
//        else h[now] = h[fl];
//    }
//    else h[now] = h[d[now]] + 1;
//    vis[now] = false;
//    return ans;
//}
//
//int main(){
//    scanf("%d",&n);
//    for(int i = 1;i <= n;i ++) scanf("%d",&d[i]);
//    for(int i = 1;i <= n;i ++) printf("%d\n",dfs(i,1));
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#define rep(i,a,b) for(int (i) = (a);(i) <= (b);(i) ++)
//using namespace std;
//const int N = 1e5 + 10;
//int d[N],h[N],s[N],vis[N],fl;
//int dfs(int now,int sum){
//    if(h[now]) return sum - 1 + h[now];
//    if(vis[now]){
//        h[now] = sum - s[now];
//        fl = now;
//        return sum - 1;
//    }
//    vis[now] = true;
//    s[now] = sum;
//    int ans = dfs(d[now],sum + 1);
//    if(fl){
//        if(fl == now) fl = 0;
//        else h[now] = h[fl];
//    }
//    else h[now] = h[d[now]] + 1;
//    vis[now] = false;
//    return ans;
//}
//int main(){
//    int n;scanf("%d",&n);
//    rep(i,1,n) scanf("%d",&d[i]);
//    rep(i,1,n) printf("%d\n",dfs(i,1));
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//using namespace std;
//const int N = 5e5 + 10,INF = 2147483647;
//int n,m,s;
//struct edge{
//    int next,to,w;
//}e[N];
//int head[N],cnt;
//void add(int u,int v,int w){
//    e[++ cnt].next = head[u];
//    head[u] = cnt;
//    e[cnt].to = v;
//    e[cnt].w = w;
//}
//bool vis[N];
//int d[N];
//struct node{
//    int d,s;
//    bool operator < (const node& b)const{
//        return d > b.d;
//    }
//};
//void dijstra(int s){
//    for(int i = 1;i <= n;i ++) d[i] = INF;
//    priority_queue<node> q;
//    d[s] = 0;
//    q.push(node{0,s});
//    while(!q.empty()){
//        int u = q.top().s;q.pop();
//        if(vis[u]) continue;
//        vis[u] = true;
//        for(int i = head[u];~i;i = e[i].next){
//            int v = e[i].to;
//            if(!vis[v] && d[v] > d[u] + e[i].w){
//                d[v] = d[u] + e[i].w;
//                q.push((node){d[v],v});
//            }
//        }
//    }
//}
//int main(){
//    memset(head,-1,sizeof(head));
//    scanf("%d%d%d",&n,&m,&s);
//    for(int i = 0;i < m;i ++){
//        int u,v,w;
//        scanf("%d%d%d",&u,&v,&w);
//        add(u,v,w);
//    }
//    dijstra(s);
//    for(int i = 1;i <= n;i ++) printf("%d ",d[i]);
//    return 0;
//}

//
//#include<cstring>
//#include<iostream>
//#include<queue>
//#include<algorithm>
//#include<cstdio>
//#define rep(i,a,b) for(int (i) = (a);(i) <= (b);(i) ++)
//
//using namespace std;
//const int N = 6e3 + 10,INF = 1e9;
//struct edge{
//    int next,to;long long w;
//}e[100010];
//int head[N],cnt;
//int n,m;
//void add(int u,int v,long long w){
//    e[++ cnt].next = head[u];
//    head[u] = cnt;
//    e[cnt].to = v;
//    e[cnt].w = w;
//}
//int inq[N];
//long long h[N],d[N];
//bool vis[N];
//
////bool bellman_ford(int s){
////    for(int i = 1;i <= n;i ++) h[i] = INF;
////    d[s] = 0;
////    for(int i = 1;i <= n + m;i ++)
////}
//bool spfa(int s){
//    queue<int> q;
//    memset(h,0x3f,sizeof(h));
//    h[s] = 0,vis[s] = true;
//    q.push(s);
//    while(!q.empty()){
//        int u = q.front();
//        q.pop();
//        vis[u] = false;
//        for(int i = head[u];i;i = e[i].next){
//            int v = e[i].to;
//            if(h[v] > h[u] + e[i].w){
//                h[v] = h[u] + e[i].w;
//                if(!vis[v]){
//                    vis[v] = true;
//                    q.push(v);
//                    inq[v] ++;
//                    if(inq[v] == n) return true;
//                }
//            }
//        }
//    }
//    return false;
//}
//struct node{
//    long long d;int s;
//    bool operator < (const node& b)const{
//        return d > b.d;
//    }
//};
//void dijkstra(int s){
//    priority_queue<node> q;
//    rep(i,1,n) d[i] = INF;
//    memset(vis,0,sizeof(vis));
//    d[s] = 0;
//    q.push(node{0,s});
//    while(!q.empty()){
//        int u = q.top().s;q.pop();
//        if(vis[u]) continue;
//        vis[u] = true;
//        for(int i = head[u];i;i = e[i].next){
//            int v = e[i].to;
//            if(d[v] > d[u] + e[i].w){
//                d[v] = d[u] + e[i].w;
//                if(!vis[v])
//                q.push((node){d[v],v});
//            }
//        }
//    }
//}
//
//int main(){
//    scanf("%d%d",&n,&m);
//    rep(i,1,m){
//        int u,v,w;
//        scanf("%d%d%d",&u,&v,&w);
//        add(u,v,w);
//    }
//    rep(i,1,n) add(0,i,0);
//    if(spfa(0)){puts("-1");return 0;}
//    rep(u,1,n){
//        for(int i = head[u];i;i = e[i].next)
//            e[i].w += h[u] - h[e[i].to];
//    }
//    rep(i,1,n){
//        dijkstra(i);
//        long long ans = 0;
//        rep(j,1,n){
//            if(d[j] == INF) ans += j * INF;
//            else ans += j * (d[j] + h[j] - h[i]);
//        }
//        printf("%lld\n",ans);
//    }
//    return 0;
//}

#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;
const int N = 1e5 + 10,M = 6e3 + 10,INF = 1e9;
struct edge{
    int to,w,next;
}e[N];
struct node{
    int d,s;
    bool operator < (const node& b)const{
        return d > b.d;
    }
    node(int d,int s):d(d),s(s) {}
};
int head[N],cnt;
int vis[N],inq[N];
long long h[N],d[N];
int n,m;

void add(int u,int v,int w){
    e[++ cnt].next = head[u];
    e[cnt].to = v;
    e[cnt].w = w;
    head[u] = cnt;
}
struct Edge{
    int u,v,w;
}E[N];
int tot;
bool bellman_ford(int s){
    for(int i = 0;i <= n;i ++) h[i] = INF;
    h[s] = 0;
    for(int i = head[0];i;i = e[i].next){
        int v = e[i].to;
        h[v] = e[i].w;
    }
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < tot;j ++){
            int u = E[j].u;
            int v = E[j].v;
            if(d[v] > d[u] + E[j].w)
                d[v] = d[u] + E[j].w;
        }
    }
    for(int i = 0;i < tot;i ++){
        int u = E[i].u;
        int v = E[i].v;
        if(d[v] > d[u] + E[i].w){
            return true;
        }
    }
    return true;
}
void dijkstra(int s){
    priority_queue<node> q;
    for(int i = 1;i <= n;i ++) d[i] = INF;
    memset(vis,0,sizeof(vis));
    d[s] = 0;
    q.push(node(0,s));
    while(!q.empty()){
        int u = q.top().s;q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = head[u];i;i = e[i].next){
            int v = e[i].to;
            if(d[v] > d[u] + e[i].w){
                d[v] = d[u] + e[i].w;
                if(!vis[v]) q.push(node(d[v],v));
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= m;i ++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        E[tot ++] = (Edge){u,v,w};
    }
    for(int i = 1;i <= n;i ++){
        add(0,i,0);
        E[tot ++] = (Edge){0,i,0};
    }
    if(bellman_ford(0)) {puts("-1");return 0;}
    for(int u = 1;u <= n;u ++){
        for(int i = head[u];i;i = e[i].next){
            e[i].w += (h[u] - h[e[i].to]);
        }
    }
    for(int i = 1;i <= n;i ++){
        dijkstra(i);
        long long ans = 0;
        for(int j = 1;j <= n;j ++){
            if(d[j] == INF) ans += j * INF;
            else ans += j * (d[j] + h[j] - h[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
