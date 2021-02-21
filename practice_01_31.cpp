//
// Created by Administrator on 2021/1/31.
//

//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//const int N = 5e5 + 10;
//int fa[N][25],lg[N],dep[N];
//int head[N],tot;
//struct edge{
//    int to,next;
//}e[N << 1];
//
//void add(int x,int y){
//    e[++tot].to = y;
//    e[tot].next = head[x];
//    head[x] = tot;
//}
//
//void dfs(int now,int fath){
//    fa[now][0] = fath;dep[now] = dep[fath] + 1;
//    for(int i = 1;i <= lg[dep[now]]; i ++)
//        fa[now][i] = fa[fa[now][i - 1]][i - 1];
//    for(int i = head[now];i;i = e[i].next)
//        if(e[i].to != fath) dfs(e[i].to,now);
//}
//
//int LCA(int x,int y){
//    if(dep[x] < dep[y]) swap(x,y);
//    while(dep[x] > dep[y])
//        x = fa[x][lg[dep[x] - dep[y]] - 1];
//    if(x == y) return x;
//    for(int k = lg[dep[x]] - 1;k >= 0;k --)
//        if(fa[x][k] != fa[y][k])
//            x = fa[x][k],y = fa[y][k];
//    return fa[x][0];
//}
//int main(){
//    int n,m,s;
//    cin >> n >> m >> s;
//    for(int i = 1;i <= n - 1;i ++){
//        int x,y;cin >> x >> y;
//        add(x,y);add(y,x);
//    }
//
//    for(int i = 1;i <= n;i ++)
//        lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
//
//    dfs(s,0);
//
//    for(int i = 1;i <= m;i ++){
//        int x,y;cin >> x >> y;
//        cout << LCA(x,y) << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e4 + 10;
//struct edge{
//    int to,next;
//}e[N << 1];
//int head[N],tot;
//int fa[N][25],dep[N],lg[N];
//void add(int x,int y){
//    e[++tot].to = y;
//    e[tot].next = head[x];
//    head[x] = tot;
//}
//
//void dfs(int now,int fath){
//    fa[now][0] = fath;dep[now] = dep[fath] + 1 ;
//    for(int i = 1;i <= lg[dep[now]];i ++)
//        fa[now][i] = fa[fa[now][i - 1]][i - 1];
//    for(int i = head[now];i;i = e[i].next)
//        if(e[i].to != fath) dfs(e[i].to,now);
//}
//
//int LCA(int x,int y){
//    if(dep[x] < dep[y]) swap(x,y);
//    while(dep[x] > dep[y])
//        x = fa[x][lg[dep[x] - dep[y]] - 1];
//    if(x == y) return x;
//    for(int i = lg[dep[x]] - 1;i >= 0;i --)
//        if(fa[x][i] != fa[y][i])
//            x = fa[x][i],y = fa[y][i];
//    return fa[x][0];
//}
//int inq[N];
//int findroot(int n){
//    memset(inq,0,sizeof(inq));
//    for(int i = 1;i <= tot;i ++){
//        inq[e[i].to] ++;
//    }
//    for(int i = 1;i <= n;i ++)
//        if(!inq[i])return i;
//}
//int main(){
//    int t; cin >> t;
//    while(t --){
//        memset(head,0,sizeof(head));
//        memset(lg,0,sizeof(lg));
//        memset(dep,0,sizeof(dep));
//        memset(fa,0,sizeof(fa));
//        tot = 0;
//        int n;cin >> n;
//        for(int i = 1;i <= n;i ++)
//            lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
//        for(int i = 0;i < n - 1;i ++){
//            int x,y;
//            cin >> x >> y ;
//            add(x,y);
//        }
//        int root = findroot(n);
////        cout << root << endl;
//        dfs(root,0);
//
//        int x,y;
//        cin >> x >> y;
//        cout << LCA(x,y) << endl;
//    }
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<sstream>
//
//using namespace std;
//const int N = 1e3 + 10;
//struct edge{
//    int to,next;
//}e[N << 1];
//int head[N],tot;
//int fa[N][25],dep[N],lg[N];
//int cnt[N];
//
//void add(int x,int y){
//    e[++tot].to = y;
//    e[tot].next = head[x];
//    head[x] = tot;
//}
//void init(){
//    memset(cnt,0,sizeof(cnt));
//    memset(head,0,sizeof(head));
//    memset(fa,0,sizeof(fa));
//    memset(dep,0,sizeof(dep));
//    memset(lg,0,sizeof(lg));
//    tot = 0;
//}
//
//void dfs(int now,int fath){
//    fa[now][0] = fath;dep[now] = dep[fath] + 1;
//    for(int i = 1;i <= lg[dep[now]];i ++){
//        fa[now][i] = fa[fa[now][i - 1]][i - 1];
//    }
//    for(int i = head[now];i;i = e[i].next){
//        dfs(e[i].to,now);
//    }
//}
//
//int LCA(int x,int y){
//    if(dep[x] < dep[y]) swap(x,y);
//    while(dep[x] > dep[y]){
//        x = fa[x][lg[dep[x] - dep[y]] - 1];
//    }
//    if(x == y) return x;
//    for(int k = lg[dep[x] - 1];k >= 0;k --){
//        if(fa[x][k] != fa[y][k]) x = fa[x][k],y = fa[y][k];
//    }
//    return fa[x][0];
//}
//
//int inq[N];
//int findroot(int n){
//    memset(inq,0,sizeof(inq));
//    for(int i = 1;i <= tot;i ++){
//        inq[e[i].to] ++;
//    }
//    for(int i = 1;i <= n;i ++)
//        if(!inq[i]) return i;
//}
//int main(){
//    int n;
//    while(~scanf("%d",&n)){
//        init();
//        for(int i = 0;i < n;i ++){
//            int x,y,num;
//            scanf("%d:(%d)",&x,&num);
//            for(int j = 0;j < num;j ++){
//                scanf("%d",&y);
//                add(x,y);
//            }
//        }
//        for(int i = 1;i <= n;i ++)
//            lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
//        int root = findroot(n);
//        dfs(root,0);
//        int m;cin >> m;
//        while(m -- ){
//            char s1[5],s2[5];
//            int x, y;
//            scanf("%1s%d%d%1s",s1,&x,&y,s2);
//            cnt[LCA(x,y)] ++;
//        }
//
//        for(int i = 1;i <= n;i ++){
//            if(cnt[i]) cout << i << ":" << cnt[i] << endl;
//        }
//    }
//    return 0;
//}


//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<map>
//#include<set>
//
//using namespace std;
//const int N = 1e5 + 10;
//struct edge{
//    int to,next;
//}e[N << 1];
//int head[N],tot;int n,m;
//int fa[N][25],dep[N],lg[N];
//int inq[N];
//void add(int x,int y){
//    e[++tot].to = y;
//    e[tot].next = head[x];
//    head[x] = tot;
//}
//int findroot(){
//    memset(inq,0,sizeof(inq));
//    for(int i = 1;i <= tot;i ++){
//        inq[e[i].to] ++;
//    }
//    for(int i = 1;i <= n;i ++){
//        if(!inq[i]) return i;
//    }
//}
//
//void dfs(int now,int fath){
//    fa[now][0] = fath;dep[now] = dep[fath] + 1;
//    for(int i = 1;i <= lg[dep[now]];i ++){
//        fa[now][i] = fa[fa[now][i - 1]][i - 1];
//    }
//    for(int i = head[now];i;i = e[i].next){
//        dfs(e[i].to,now);
//    }
//}
//
//int LCA(int x,int y){
//    if(dep[x] < dep[y]) swap(x,y);
//    while(dep[x] > dep[y]) x = fa[x][lg[dep[x] - dep[y]] - 1];
//    if(x == y) return x;
//    for(int k = lg[dep[x]] - 1;k >= 0;k --){
//        if(fa[x][k] != fa[y][k]) x = fa[x][k],y = fa[y][k];
//    }
//    return fa[x][0];
//}
//void init(){
//    memset(head,0,sizeof(head));
//    memset(fa,0,sizeof(fa));
//    memset(dep,0,sizeof(dep));
//    memset(lg,0,sizeof(lg));
//    tot = 0;
//}
//int main(){
//    int t;cin >> t;
//    while(t --){
//        init();
//        int cnt = 0;
//        set<string> _set;
//        map<string,int> ma;
//        cin >> n >> m;
//        string s1,s2;
//        for(int i = 1;i < n;i ++){
//            cin >> s1 >> s2;
//            if(!_set.count(s1)){
//                _set.insert(s1);
//                ma[s1] = ++cnt;
//            }
//            if(!_set.count(s2)){
//                _set.insert(s2);
//                ma[s2] = ++cnt;
//            }
//            int x = ma[s1],y = ma[s2];
//            add(y,x);
//        }
//        for(int i = 1;i <= n;i ++) lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
//
//        int root = findroot();
//        dfs(root,0);
//
//        int ans;
//        for(int i = 0;i < m;i ++) {
//            cin >> s1 >> s2;
//            int x = ma[s1], y = ma[s2];
//            if(x == y){
//                cout << 0 << endl;
//                continue;
//            }
//            if (LCA(x, y) == x) {
//                ans = 1;
//            }
//            else if(LCA(x,y) == y){
//                ans = dep[x] - dep[y];
//            }
//            else {
//                ans = dep[x] - dep[LCA(x,y)] + 1;
//            }
//            cout << ans << endl;
//        }
//    }
//    return 0;
//}
//
//#include<iostream>
//#include<cstdio>
//#include<cmath>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e6 + 10;
//int f[N][21];
//
//int query(int l,int r){
//    int k = log2(r - l + 1);
//    return max(f[l][k],f[r - (1 << k) + 1][k]);
//}
//int main(){
//    int n,m;
//    scanf("%d%d",&n,&m);
//    for(int i = 1;i <= n;i ++) cin >> f[i][0];
//    for(int j = 1;(1 << j) <= n;j ++){
//        for(int i = 1;i + (1 << j) - 1 <= n;i ++){
//            f[i][j] = max(f[i][j - 1],f[i + (1 << (j - 1))][j - 1]);
//        }
//    }
//
//    for(int i = 1;i <= m;i ++){
//        int l,r;
//        scanf("%d%d",&l,&r);
//        printf("%d\n",query(l,r));
//    }
//    return 0;
//}
//
//


//#include<iostream>
//#include<cstdio>
//#include<cmath>
//#include<cstring>
//using namespace std;
//const int N = 1e5 + 10;
//int f[N][21];
//
//int query(int l,int r){
//    int k = log2(r - l + 1);
//    return min(f[l][k],f[r - (1 << k) + 1][k]);
//}
//int main(){
//    int m,n;
//    scanf("%d%d",&m,&n);
//    memset(f,0x3f,sizeof(f));
//    for(int i = 1;i <= m;i ++) cin >> f[i][0];
//
//    for(int j = 1;(1 << j) <= m;j ++){
//        for(int i = 1;i + (1 << j) - 1 <= m;i ++){
//            f[i][j] = min(f[i][j - 1],f[i + (1 << (j - 1))][j - 1]);
//        }
//    }
//
//    for(int i = 1;i <= n;i ++){
//        int l,r;
//        scanf("%d%d",&l,&r);
//        printf("%d ",query(l,r));
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<cmath>
//
//using namespace std;
//const int N = 5e4 + 10;
//int f1[N][25],f2[N][25];
//
//int query(int l,int r){
//    int k = log2(r - l + 1);
//    return max(f1[l][k],f1[r - (1 << k) + 1][k]) - min(f2[l][k],f2[r - (1 << k) + 1][k]);
//}
//int main(){
//    int n,m;
//    scanf("%d%d",&n,&m);
//    memset(f2,0x3f,sizeof(f2));
//    for(int i = 1;i <= n;i ++){
//        scanf("%d",&f1[i][0]);
//        f2[i][0] = f1[i][0];
//    }
//
//    for(int j = 1;(1 << j) <= n;j ++){
//        for(int i = 1;i + (1 << j) - 1 <= n;i ++){
//            f1[i][j] = max(f1[i][j - 1],f1[i + (1 << (j - 1))][j - 1]);
//            f2[i][j] = min(f2[i][j - 1],f2[i + (1 << (j - 1))][j - 1]);
//        }
//    }
//    for(int i = 1;i <= m;i ++){
//        int l,r;
//        scanf("%d%d",&l,&r);
//        printf("%d\n",query(l,r));
//    }
//    return 0;
//}

//void dfs(int now,int fath){
//    fa[now][0] = fath;dep[now] = dep[fath] + 1;
//    for(int i = 1;i <= lg[dep[now]];i ++){
//        fa[now][i] = fa[fa[now][i - 1]][i - 1];
//    }
//    for(int i = head[now];i;i = e[i].next){
//        if(e[i].to != fath) dfs(e[i].to,now);
//    }
//}

//void dfs(int now,int fath){
//    fa[now][0] = fath;dep[now] = dep[fath] + 1;
//    for(int i = 1;i <= lg[dep[now]];i ++){
//        fa[now][i] = fa[fa[now][i - 1]][i - 1];
//    }
//    for(int i = head[now];i;i = e[i].next){
//        dfs(e[i].to,now);
//    }
//}

//int LCA(int x,int y){
//    if(dep[x] < dep[y]) sawp(x,y);
//    while(dep[x] > dep[y]) x = fa[x][lg[dep[x] - dep[y]] - 1];
//    if(x == y) return x;
//    for(int k = lg[dep[x]] - 1;k >= 0;k --){
//        if(fa[x][k] != fa[y][k]) x = fa[x][k],y = fa[y][k];
//    }
//    return fa[x][0];
//}

//int LCA(int x,int y){
//    if(dep[x] < dep[y]) swap(x,y);
//    while(dep[x] > dep[y]) x = fa[x][lg[dep[x] - dep[y]] - 1];
//    if(x == y) return x;
//    for(int k = lg[dep[x]] - 1;k >= 0;k --){
//        if(fa[x][k] != fa[y][k]) x = fa[x][k],y = fa[y][k];
//    }
//    return fa[x][0];
//}
//for(int j = 1;(1 << j) <= n;j ++){
//    for(int i = 1;i + (1 << j) - 1 <= n;i ++){
//        f[i][j] = max(f[i][j - 1],f[i + (1 << j)][j - 1]);
//        //f[i][j] = min(f[i][j - 1],f[i + (1 << j)][j - 1]);
//    }
//}
//
//int query(int l,int r){
//    int k = log2(r - l + 1);
//    return max(f[l][k],f[r - (1 << k) + 1][k]);
//    //return min(f[l][k],f[r - (1 << k) + 1][k]);
//}