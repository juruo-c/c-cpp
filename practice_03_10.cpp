//
// Created by 19116 on 2021/3/10.
//

//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int n;cin >> n;
//        int a[110];
//        for(int i = 1;i <= n;i ++) cin >> a[i];
//        sort(a + 1,a + 1 + n);
//        int fl = 0;
//        for(int i = 2;i <= n;i ++){
//            if(a[i] > a[1]){
//                fl = i;
//                break;
//            }
//        }
//        if(fl)
//        cout << n - fl + 1 << endl;
//        else cout << fl << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<algorithm>
//
//using namespace std;
//
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int n,k;
//        cin >> n >> k;
//        if(n % 2 == 0) cout << (k - 1) % n + 1 << endl;
//        else{
//            if(k < (n + 1) / 2) cout << k << endl;
//            else{
//                int tt = k / ((n + 1) / 2) + 1;
//                cout << (k - 1 + tt) % n + 1 << endl;
//            }
//        }
//    }
//    return 0;
//}
//#include<iostream>
//#include<cmath>
//using namespace std;
//
//int main(){
//    double a = 0.064;
//    double b = 0.08;
//    cout << sqrt(a * a + b * b);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e4 + 10;
//struct edge{
//    int next,to;
//}e[N * 20];
//int head[20 * N],cnt,dfn[N],low[N];
//int n,m,t;
//int stk[N],top;
//int tot;
//int id[N],sum[N],out[N];
//bool vis[N];
//
//void add(int u,int v){
//    e[++ cnt].to = v;
//    e[cnt].next = head[u];
//    head[u] = cnt;
//}
//
//void tarjan(int u){
//    low[u] = dfn[u] = ++ t;
//    stk[++ top] = u;vis[u] = 1;
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(!dfn[v]){
//            tarjan(v);
//            low[u] = min(low[u],low[v]);
//        }
//        else if(vis[v]){
//            low[u] = min(low[u],dfn[v]);
//        }
//    }
//    if(low[u] == dfn[u]){
//        int y;
//        ++ tot;
//        while(y = stk[top --]){
//            vis[y] = 0;
//            id[y] = tot;
//            sum[tot] ++;
//            if(u == y) break;
//        }
//    }
//
//}
//
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 1;i <= m;i ++){
//        int u,v;
//        scanf("%d%d",&u,&v);
//        add(u,v);
//    }
//    for(int i = 1;i <= n;i ++) if(!dfn[i]) tarjan(i);
//    for(int i = 1; i<= n;i ++){
//        for(int j = head[i];j;j = e[j].next){
//            int v = e[j].to;
//            if(id[i] != id[v]) out[id[i]] ++;
//        }
//    }
//    int tt = 0;
//    for(int i = 1;i <= tot;i ++){
//        if(!out[i]){
//            if(tt){puts("0");return 0;}
//            tt = i;
//        }
//    }
//    printf("%d\n",sum[tt]);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e4 + 10,M = 5e4 + 10;
//struct edge{
//    int next,to;
//}e[M];
//int n,m;
//int head[N],cnt;
//int dfn[N],low[N],t;
//int stk[N],top;
//bool vis[N];
//int id[N],sum[N],tot;
//void add(int u,int v){
//    e[++ cnt].next = head[u];
//    e[cnt].to = v;
//    head[u] = cnt;
//}
//void tarjan(int x){
//    low[x] = dfn[x] = ++ t;
//    stk[++ top] = x;vis[x] = 1;
//    for(int i = head[x];i;i = e[i].next){
//        int v = e[i].to;
//        if(!dfn[v]){
//            tarjan(v);
//            low[x] = min(low[x],low[v]);
//        }
//        else if(vis[v]){
//            low[x] = min(low[x],dfn[v]);
//        }
//    }
//    if(low[x] == dfn[x]){
//        int y;
//        ++ tot;
//        while(y = stk[top --]){
//            vis[y] = 0;
//            id[y] = tot;
//            sum[tot] ++;
//            if(x == y) break;
//        }
//    }
//}
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 1;i <= m;i ++){
//        int u,v;
//        scanf("%d%d",&u,&v);
//        add(u,v);
//    }
//    for(int i = 1;i <= n;i ++) if(!dfn[i]) tarjan(i);
//    int ans = 0;
//    for(int i = 1;i <= tot;i ++){
//        if(sum[i] > 1) ans ++;
//    }
//    printf("%d\n",ans);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//const int N = 1e3 + 10;
//struct edge{
//    int next,v;
//}e[N * N];
//int head[N],cnt;
//int dfn[N],low[N],t;
//int stk[N],top;
//bool vis[N];
//int id[N],tot;
//void add(int u,int v){
//    e[++ cnt].v = v;
//    e[cnt].next = head[u];
//    head[u] = cnt;
//}
//void tarjan(int u){
//    low[u] = dfn[u] = ++ t;
//    stk[++ top] = u;vis[u] = 1;
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].v;
//        if(!dfn[v]){
//            tarjan(v);
//            low[u] = min(low[u],low[v]);
//        }
//        else if(vis[v]){
//            low[u] = min(low[u],dfn[v]);
//        }
//    }
//    if(low[u] == dfn[u]){
//        int v;
//        ++ tot;
//        while(v = stk[top --]){
//            id[v] = tot;
//            vis[v] = 0;
//            if(v == u) break;
//        }
//    }
//}
//int n;
//int in[N],out[N];
//int main(){
//    scanf("%d",&n);
//    for(int i = 1;i <= n;i ++){
//        int v;while(scanf("%d",&v) && v){
//            add(i,v);
//        }
//    }
//    for(int i = 1;i <= n;i ++) if(!dfn[i]) tarjan(i);
//    for(int u = 1;u <= n;u ++){
//        for(int i = head[u];i;i = e[i].next){
//            int v = e[i].v;
//            if(id[u] != id[v]){
//                out[id[u]] ++;
//                in[id[v]] ++;
//            }
//        }
//    }
//    int A = 0;
//    for(int i = 1;i <= tot;i ++){
//        if(!in[i]) A ++;
//    }
//    int B = 0;
//    for(int i = 1;i <= tot;i ++){
//        if(!out[i]) B ++;
//    }
//    if(tot == 1) printf("1\n0");
//    else printf("%d\n%d\n",A,max(A,B));
//    return 0;
//}

#include<iostream>
#include<string>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t --){
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        int cnt = 0;
        int i;
        for(i = 0;i < n / 2;i ++){
            if(s[i] == s[n - 1 - i]) cnt ++;
            else break;
        }
        if(i < n / 2) cnt ++;
        if(k + 1 <= cnt) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}