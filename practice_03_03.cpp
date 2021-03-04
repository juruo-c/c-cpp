//
// Created by 19116 on 2021/3/3.
//

//#include<iostream>
//
//using namespace std;
//
//int main(){
//    int t; cin >> t;
//    while(t --){
//        int n;cin >> n;
//        int U,R,D,L,u,r,d,l;
//        cin >> U >> R >> D >> L;
//        u = r = d = l = 0;
//        if(U == n) r++ ,l ++;
//        if(R == n) u++ ,d ++;
//        if(D == n) r ++,l++;
//        if(L == n) u ++,d ++;
//
//        if(U == n - 1) (r >= R) ? l ++:r ++;
//        if(D == n - 1) (r >= R) ? l ++:r ++;
//        if(R == n - 1) (u >= U) ? d ++:u ++;
//        if(L == n - 1) (u >= U) ? d ++:u ++;
//        if(d > D || u > U || r > R || l > L) cout << "NO" << endl;
//        else cout << "YES" << endl;
//    }
//
//    return 0;
//}



//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 3e5 + 10;
//int fa[N];
//int getf(int x){return fa[x] == x ? x : fa[x] = getf(fa[x]);}
//int n,m,q;
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
//
//int d[N];
//int c;
//bool vis[N];
//int maxx;
//void dfs(int u,int val){
//    if(maxx < val) maxx = val,c = u;
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(vis[v]) continue;
//        vis[v] = true;
//        dfs(v,val + 1);
//    }
//    vis[u] = false;
//}
//void dfs2(int u,int val){
//    if(maxx < val) maxx = val;
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(vis[v]) continue;
//        vis[v] = true;
//        dfs(v,val + 1);
//    }
//    vis[u] = false;
//}
//
//
//
//int main(){
//    scanf("%d%d%d",&n,&m,&q);
//    for(int i = 1;i <= n;i ++) fa[i] = i;
//    for(int i = 0;i < m;i ++){
//        int u,v;
//        scanf("%d%d",&u,&v);
//        add(u,v,1);
//        add(v,u,1);
//        int fu = getf(u);
//        int fv = getf(v);
//        if(fu != fv) fa[fu] = fv;
//    }
//    for(int i = 1;i <= n;i ++){
//        int x = getf(i);
//        if(d[x]) continue;
//        maxx = -1;
//        vis[x] = true;
//        dfs(x,0);
//        maxx = -1;
//        vis[c] = true;
//        dfs2(c,0);
//        d[x] = maxx;
//    }
//    for(int i = 0;i < q;i ++){
//        int op;int x,y;
//        scanf("%d",&op);
//        if(op == 1){
//            scanf("%d",&x);
//            printf("%d\n",d[getf(x)]);
//        }
//        else {
//            scanf("%d%d",&x,&y);
//            int fx = getf(x);
//            int fy = getf(y);
//            if(fx == fy) continue;
//            fa[fx] = fy;
//            int ans = max(d[fx],d[fy]);
//            d[fy] = max(ans,(d[fx] + 1) / 2 + (d[fy] + 1) / 2 + 1);
//        }
//    }
//    return 0;
//}