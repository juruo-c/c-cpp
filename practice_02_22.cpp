//
// Created by 19116 on 2021/2/22.
//

//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<iostream>
//
//using namespace std;
//char a[11][70];
//char tmp[70],ans[70];
//int ne[70];
//void getnext(int len,char s[]){
//    int j = 0,k = -1;
//    ne[j] = k;
//    while(j < len){
//        if(k == -1 || s[j] == s[k]) ne[++ j] = ++ k;
//        else k = ne[k];
//    }
//}
//bool KMP(char s[],int sl,char t[],int tl){
//    getnext(sl,s);
//    int i = 0,j = 0;
//    while(i < tl){
//        if(j == -1 || t[i] == s[j]) i ++ ,j ++;
//        else j = ne[j];
//        if(j == sl)return true;
//    }
//    return false;
//}
//
//int main(){
//    int T;scanf("%d",&T);
//    while(T --){
//        int n,flag = 0;
//        scanf("%d",&n);
//        for(int i = 0;i < n;i ++) scanf("%s",a[i]);
//        for(int i = 0;i < strlen(a[0]);i ++){
//            int tot = 0,k;
//            tmp[tot ++] = a[0][i];
//            for(int j = i + 1;j < strlen(a[0]);j ++){
//                tmp[tot ++] = a[0][j];
//                tmp[tot] = '\0';
//                for(k = 1;k < n;k ++){
//                    if(!KMP(tmp,tot,a[k],strlen(a[k])))break;
//                }
//                if(k >= n){
//                    if(flag == 0 || tot > strlen(ans)){
//                        flag = 1;
//                        strcpy(ans,tmp);
//                    }
//                    else{
//                        if(tot == strlen(ans) && strcmp(tmp,ans) < 0)
//                            strcpy(ans,tmp);
//                    }
//                }
//            }
//        }
//        if(flag == 0 || strlen(ans) < 3) printf("no significant commonalities\n");
//        else printf("%s\n",ans);
//    }
//    return 0;
//}

//#include<cstdio>
//#include<iostream>
//#include<cstring>
//
//using namespace std;
//const int N = 5e4 + 10;
//char s[N],t[N];
//int sl,tl;
//int ne[N],ext[N];
//
//void getnext(){
//    ne[0] = tl;
//    int now = 0;
//    while(t[now] == t[now + 1] && now + 1 < tl) now ++;
//    ne[1] = now;
//    int p0 = 1;
//    for(int i = 2;i < tl;i ++){
//        if(i + ne[i - p0] < ne[p0] + p0) ne[i] = ne[i - p0];
//        else{
//            int now = ne[p0] + p0 - i;
//            now = max(0,now);
//            while(t[now] == t[now + 1] && i + now < tl) now ++;
//            ne[i] = now;
//            p0 = i;
//        }
//    }
//}
//
//void exkmp(){
//    getnext();
//    int now = 0;
//    while(s[now] == t[now] && now < min(sl,tl)) now ++;
//    ext[0] = now;
//    int p0 = 0;
//    for(int i = 1;i < sl;i ++){
//        if(i + ne[i - p0] < ext[p0] + p0) ext[i] = ne[i - p0];
//        else{
//            int now = ext[p0] + p0 - i;
//            now = max(0,now);
//            while(t[now] == s[i + now] && now < tl && now + i < sl) now ++;
//            ext[i] = now;
//            p0 = i;
//        }
//    }
//}
//
//int main(){
//    while(~scanf("%s%s",t,s)){
//        tl = strlen(t),sl = strlen(s);
//        exkmp();
//        int flag = 0;
//        for(int i = 0;i < sl;i ++){
//            if(ext[i] == sl - i){
//                for(int j = i;j < i + ext[i];j ++) printf("%c",s[j]);
//                printf(" %d\n",ext[i]);
//                flag = 1;
//                break;
//            }
//        }
//        if(!flag) printf("0\n");
//    }
//    return 0;
//}

//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//const int N = 5e4 + 10;
//int ne[N];
//char a[N],b[N];
//int la,lb;
//
//void getnext(){
//    int j = 0,k = -1;
//    ne[j] = k;
//    while(j < la){
//        if(k == -1 || a[j] == a[k]) ne[++ j] = ++ k;
//        else k = ne[k];
//    }
//}
//
//int KMP(){
//    int i = 0,j = 0;
//    while(i < lb && j < la){
//        if(j == -1 || a[j] == b[i]){
//            i ++,j ++;
//            if(j == la && i != lb) j = ne[j];
//        }
//        else j = ne[j];
//    }
//    return j;
//}
//int main(){
//    while(~scanf("%s%s",a,b)){
//        la = strlen(a),lb = strlen(b);
//        getnext();
//        int ans = KMP();
//        if(ans){
//            a[ans] = '\0';
//            printf("%s %d\n",a,ans);
//        }
//        else puts("0");
//    }
//    return 0;
//}

//#include<cstdio>
//
//using namespace std;
//const int N = 2e5 + 10;
//int n,ne[N];int dp[N];
//char s[N];
//void getnext(){
//    int j = 0,k = -1;
//    ne[j] = k;
//    while(j < n){
//        if(k == -1 || s[j] == s[k]) ne[++ j] = ++ k;
//        else k = ne[k];
//    }
//}
//int main(){
//    int t;
//    scanf("%d",&t);
//    while(t --){
//        scanf("%d%s",&n,s);
//        getnext();
//        int ans = 0;
//        for(int i = 1;i <= n;i ++){
//            dp[i] = (dp[ne[i]] + 1) % 10007;
//            ans = (ans + dp[i]) % 10007;
//        }
//        printf("%d\n",ans);
//    }
//    return 0;
//}

//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//int n,m,q;
//const int INF = 0x3f3f3f3f;
//const int N = 5e4 + 10;
//struct edge{
//    int u,v,w;
//    int flag;
//    bool operator < (const edge& b)const{
//        return w > b.w;
//    }
//}e[N];
//struct Edge{
//    int next,to,w;
//}tree[N];
//int tot;
//int fa[N];
//int getfa(int x){return fa[x] == x ? x : fa[x] = getfa(fa[x]);}
//void kruscal(){
//    for(int i = 1;i <= n;i ++) fa[i] = i;
//    sort(e,e + tot);
//    for(int i = 0;i < tot;i ++){
//        int fu = getfa(e[i].u);
//        int fv = getfa(e[i].v);
//        if(fu != fv){
//            fa[fu] = fv;
//            e[i].flag = 1;
//        }
//    }
//}
//int cnt,head[N];
//void add_edge(int u,int v,int w){
//    tree[++ cnt].to = v;
//    tree[cnt].next = head[u];
//    tree[cnt].w = w;
//    head[u] = tot;
//}
//int d[N][20],fath[N][20];
//int dep[N];
//void dfs(int now,int f){
//    fath[now][0] = f;dep[now] = dep[f] + 1;
//    for(int i = 1;i < 20;i ++){
//        fath[now][i] = fath[fath[now][i - 1]][i - 1];
//        d[now][i] = min(d[now][i - 1],d[fath[now][i - 1]][i - 1]);
//    }
//
//    for(int i = head[now];i;i = tree[i].next)
//        if(tree[i].to != f){
//            d[now][0] = tree[i].w;
//            dfs(tree[i].to,now);
//        }
//}
//int LCA(int x,int y){
//    if(dep[x] < dep[y]) swap(x,y);
//    int t = dep[x] - dep[y];
//    for(int i = 0;i <= 16;i ++){
//        if(t & (1 << i)) x = fath[x][i];
//    }
//    if(x == y) return x;
//    for(int i = 16;i >= 0;i --){
//        if(fath[x][i] != fath[y][i]){
//            x = fath[x][i];
//            y = fath[y][i];
//        }
//    }
//    return fath[x][0];
//}
//
//int solve(int u,int v){
//    int t = dep[u] - dep[v];
//    int ans = INF;
//    for(int i = 0; i <= 16;i ++){
//        if(t & (1 << i)){
//            ans = min(ans,d[u][i]);
//            u = fath[u][i];
//        }
//    }
//    return ans;
//}
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 0;i < m;i ++){
//        int x,y,z;
//        scanf("%d%d%d",&x,&y,&z);
//        e[tot ++] = {x,y,z,0};
//    }
//    kruscal();
//    for(int i = 0;i < tot;i ++){
//        if(e[i].flag){
//            add_edge(e[i].u,e[i].v,e[i].w);
//            add_edge(e[i].v,e[i].u,e[i].w);
//        }
//    }
//    dfs(tree[1].to,0);
//    scanf("%d",&q);
//    for(int i = 0;i < q;i ++){
//        int u,v;
//        scanf("%d%d",&u,&v);
//        if(getfa(u) != getfa(v)) printf("-1\n");
//        else {
//            int t = LCA(u,v);
//            printf("%d\n",min(solve(u,t),solve(v,t)));
//        }
//    }
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 1e5 + 10,M = 5e5 + 10,INF = 0x3f3f3f3f;
//int head[N],tot;
//int n,m,q;
//int Fa[N];
//int fa[N][20],d[N][20],dep[N];
//int vis[N];
//struct Edge{
//    int v,w,next;
//}e[M << 1];
//struct node{
//    int u,v,w;
//    bool operator < (const node& b)const{
//        return w > b.w;
//    }
//}a[N];
//void add(int u,int v,int w){
//    e[tot].v = v;
//    e[tot].next = head[u];
//    e[tot].w = w;
//    head[u] = tot ++;
//}
//int getf(int x){return x == Fa[x] ? x : Fa[x] = getf(Fa[x]);}
//void kruscal(){
//    for(int i = 1;i <= n;i ++) Fa[i] = i;
//    sort(a,a + m);
////    for(int i = 0;i < m;i ++) cout << a[i].w << " ";
////    cout << endl;
//    for(int i = 0;i < m;i ++){
//        int fu = getf(a[i].u);
//        int fv = getf(a[i].v);
//        int u = a[i].u,v = a[i].v,w = a[i].w;
//        if(fu != fv){
//            Fa[fu] = fv;
//            add(u,v,w);
//            add(v,u,w);
//        }
//    }
//}
//
//void dfs(int u){
//    vis[u] = 1;
//    for(int i = 1;i <= 16;i ++){
//        if(dep[u] < (1 << i)) break;
//        fa[u][i] = fa[fa[u][i - 1]][i - 1];
//        d[u][i] = min(d[u][i - 1],d[fa[u][i - 1]][i - 1]);
//    }
//    for(int i = head[u];~i;i = e[i].next){
//        int v = e[i].v,w = e[i].w;
//        if(v != fa[u][0]){
//            fa[v][0] = u;
//            dep[v] = dep[u] + 1;
//            d[v][0] = w;
//            dfs(v);
//        }
//    }
//}
//int LCA(int x,int y){
//    if(dep[x] < dep[y]) swap(x,y);
//    int t = dep[x] - dep[y];
//    for(int i = 0;i <= 16;i ++){
//        if(t & (1 << i)) x = fa[x][i];
//    }
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
//int solve(int u,int v){
//    int t = dep[u] - dep[v];
//    int ans = INF;
//    for(int i = 0;i <= 16;i ++){
//        if(t & (1 << i)){
//            ans = min(ans,d[u][i]);
//            u = fa[u][i];
//        }
//    }
//    return ans;
//}
//int main(){
//    memset(head,-1,sizeof(head));
//    cin >> n >> m;
//    for(int i = 0;i < m;i ++){
//        cin >> a[i].u >> a[i].v >> a[i].w;
//    }
//    kruscal();//最大生成树
//    for(int i = 1;i <= n;i ++)//预处理出fa[][],d[][],dep[]
//        if(!vis[i]) dfs(i);
//
//    cin >> q;
//    for(int i = 0;i < q;i ++){
//        int u,v;
//        cin >> u >> v;
//        if(getf(u) != getf(v)) cout << -1 << endl;
//        else{
//            int t = LCA(u,v);
//            cout << min(solve(u,t),solve(v,t)) << endl;
//        }
//    }
//    return 0;
//}

//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 5e5 + 10;
//typedef long long ll;
//int n,m;
//ll k;ll a[N];
//ll b[N];
//ll c[N];//归并排序用到的中间数组
//void Sort(int nowr,int p,int nowl){
//    sort(b + nowr + 1,b + nowr + p + 1);
//    int i = nowl;
//    int j = nowr + 1;
//    int mid = nowl;
//    while(i <= nowr && j <= nowr + p){
//        if(b[i] < b[j]) c[mid ++] = b[i ++];
//        else c[mid ++] = b[j ++];
//    }
//    while(i <= nowr) c[mid ++] = b[i ++];
//    while(j <= nowr + p) c[mid ++] = b[j ++];
//    for(int t = nowl;t <= nowr + p;t ++) b[t] = b[t];
//}
//int main(){
//    int tt;scanf("%d",&tt);
//    while(tt --){
//        scanf("%d%d%lld",&n,&m,&k);
//        for(int i = 1;i <= n;i ++) scanf("%lld",&a[i]);
//        //
//        int ans = 0;
//        int p = 1,nowr = 1,nowl = 1;
//        while(nowr <= n){
//            if(nowr + p <= n){
//                for(int i = nowl;i <= nowr + p;i ++) b[i] = a[i];
//                Sort(nowr,p,nowl);
//                ll T = 0;int cnt = 0;
//                int len = nowr - nowl + 1;
//                for(int i = nowl;i <= len / 2;i ++){
//                    T += (b[i] - b[len - i + 1]) * (b[i] - b[len - i + 1]);
//                    cnt ++;
//                    if(cnt == m) break;
//                }
//                if(T <= k){
//                    nowr += p;
//                    p *= 2;
//                    for(int i = nowl;i <= nowr;i ++) a[i] = b[i];
//                }
//                else{
//                    p /= 2;
//                    if(p == 0){
//                        ans ++;
//                        nowl = nowr + 1;
//                        nowr += 1;
//                        p = 1;
//                    }
//                }
//            }
//            else {
//                p /= 2;
//                if(!p) break;
//            }
//        }
//        printf("%d\n",ans);
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 5e5 + 10;
//int T,n,m;
//typedef long long ll;
//ll k;
//ll a[N],b[N],c[N];
//int ans,R;
//
//void Merge(int l,int mid,int r){
//    int i = l,j = mid + 1,t = l;
//    while(i <= mid && j <= r){
//        if(b[i] <= b[j]) c[t ++] = b[i ++];
//        else c[t ++] = b[j ++];
//    }
//    while(i <= mid) c[t ++] = b[i ++];
//    while(j <= r) c[t ++] = b[j ++];
//}
//
//ll cal(int l,int r){
//    ll res = 0;
//    for(int i = R + 1;i <= r;i ++){
//        b[i] = a[i];
//    }
//    sort(b + R + 1,b + 1 + r);
//    Merge(l,R,r);
//    for(int i = 1;i <= min(m,(r - l + 1) >> 1);i ++){
//        res += (c[l + i - 1] - c[r - i + 1]) * (c[l + i - 1] - c[r - i + 1]);
//    }
//    return res;
//}
//int work(int l){
//    int p = 1,r = l - 1;
//    while(p){
//        ll res = cal(l,min(n,r + p));
//        if(res <= k){
//            R = r = min(n,r + p);
//            for(int i = l;i <= r;i ++) b[i] = c[i];
//            if(r == n) break;
//            p <<= 1;
//        }
//        else p >>= 1;
//    }
//    return r;
//}
//int main(){
//    scanf("%d",&T);
//    while(T --){
//        ans = 0;
//        R = 0;
//        scanf("%d%d%lld",&n,&m,&k);
//        for(int i = 1;i <= n;i ++) scanf("%lld",&a[i]);
//        int l = 1;
//        while(l <= n){
//            l = work(l) + 1;
//            ans ++;
//        }
//        printf("%d\n",ans);
//        printf("\n");
//    }
//    return 0;
//}

//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e6 + 10;
//char a[30],b[N],c[30];
//int l;
//int ne[N];
//
//int main(){
//    int tt;
//    scanf("%d",&tt);
//    while(tt --){
//        scanf("%s%s",a,b);
//        l = strlen(b);
//        for(int i = 0;i < 26;i ++) c[a[i]] =(char)('a' + i);
//        int mid = l / 2;
//        for(int i = 0;i < mid;i ++) b[i] = c[b[i]];
////        printf("%s\n",b);
//        int i = mid;
//        while(true){
//            if(b[i] != b[0]){
//                b[i] = c[b[i]];
//                i ++;
//            }
//            else break;
//        }
//        for(int k = 0;k < i;k ++)printf("%c",a[b[k] - 'a']);
//        for(int k = 0;k < i;k ++) printf("%c",b[k]);
//        printf("\n");
//    }
//    return 0;
//}

//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 1e6 + 10;
//int n;
//char s[N];
//int ne[N];
//void getnext(){
//    int j = 0,k = -1;
//    ne[j] = k;
//    while(j < n){
//        if(k == -1 || s[j] == s[k]) ne[++ j] = ++ k;
//        else k = ne[k];
//    }
//}
//int getmin(){
//    int i = 0,j = 1,k = 0;
//    while(i < n && j < n && k < n){
//        int t = s[(i + k) % n] - s[(j + k) % n];
//        if(!t) k ++;
//        else{
//            if(t > 0) i += k + 1;
//            else j += k + 1;
//            if(i == j) j ++;
//            k = 0;
//        }
//    }
//    return i < j ? i : j;
//}
//int getmax(){
//    int i = 0,j = 1,k = 0;
//    while(i < n && j < n && k < n){
//        int t = s[(i + k) % n] - s[(j + k) % n];
//        if(!t) k ++;
//        else{
//            if(t > 0) j+= k + 1;
//            else i += k + 1;
//            if(i == j) j ++;
//            k = 0;
//        }
//    }
//    return i < j ? i : j;
//}
//int main(){
//    while(~scanf("%s",s)){
//        n = strlen(s);
//        getnext();
//        int minn = getmin() + 1;
//        int maxx = getmax() + 1;
//        int t = n - ne[n];
//        if(n % t) printf("%d %d %d %d\n",minn,1,maxx,1);
//        else printf("%d %d %d %d\n",minn,n / t,maxx,n / t);
//    }
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<set>
//
//using namespace std;
//const int N = 1e4 + 10;
//int n;
//string s;
//set<string> a;
//void getmin(){
//    int i = 0,j = 1,k = 0;
//    int len = s.size();
//    while(i < len && j < len && k < len){
//        int t = s[(i + k) % len] - s[(j + k) % len];
//        if(!t) k ++;
//        else{
//            if(t > 0) i += k + 1;
//            else j += k + 1;
//            if(i == j) j ++;
//            k = 0;
//        }
//    }
//    int tt = (i < j ? i : j);
//    string b;
//    b = s.substr(tt) + s.substr(0,tt);
//    a.insert(b);
//}
//int main(){
//    while(cin >> n){
//        a.clear();
//        for(int i = 0;i < n;i ++){
//            cin >> s;
//            getmin();
//        }
//        printf("%d\n",a.size());
//    }
//    return 0;
//}

//int getmin(char s[]){
//    int i = 0,j = 1, k = 0;
//    int n = strlen(s);
//    while(i < n && j < n && k < n){
//        int t = s[(i + k) % n] - s[(j + k) % n];
//        if(!t) k ++;
//        else{
//            if(t > 0) i += k + 1;
//            else j += k + 1;
//            if(i == j) j ++;
//            k = 0;
//        }
//    }
//    return i < j ? i : j;
//}
//int getmax(char s[]){
//    int i = 0,j = 1,k = 0;
//    int n = strlen(s);
//    while(i < n && j < n && k < n){
//        int t = s[(i + k) % n] - s[(j + k) % n];
//        if(!t) k ++;
//        else{
//            if(t > 0) j += k + 1;
//            else i += k + 1;
//            if(i == j) j ++;
//            k = 0;
//        }
//    }
//    return i < j ? i : j;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<set>
//using namespace std;
//const int N = 1e6 + 10;
//char s[N];
//int n,ne[N];
//set<int> a;
//void getnext(){
//    int j = 0,k = -1;
//    ne[j] = k;
//    while(j < n){
//        if(k == -1 || s[j] == s[k]) ne[++ j] = ++ k;
//        else k = ne[k];
//    }
//}
//int main(){
//    int kase = 0;
//    int tt;scanf("%d",&tt);
//    while(tt --){
//        a.clear();
//        scanf("%s",s);
//        n = strlen(s);
//        getnext();
//        int ans[N] = {0};
//        int cnt = 0;
//        for(int i = 0;i < n;i ++){
//            if(ne[i] && i / ne[i] == 2){
//                if(!a.count(ne[i])){
//                    ans[cnt ++] = ne[i];
//                    a.insert(ne[i]);
//                }
//            }
//        }
//        sort(ans,ans + cnt);
//        printf("Case #%d: %d",++ kase,cnt);
//        for(int i = 0;i < cnt;i ++) printf("%d ",ans[i]);
//        puts("");
//    }
//    return 0;
//}

#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 1e6 + 10;
char s[N];
int n,ne[N];
vector<int> a;
void getnext(){
    int j = 0,k = -1;
    ne[j] = k;
    while(j < n){
        if(k == -1 || s[j] == s[k]) ne[++ j] = ++ k;
        else k = ne[k];
    }
}
int main(){
    int kase = 0;
    int T;scanf("%d",&T);
    while(T --){
        a.clear();
        scanf("%s",s);
        n = strlen(s);

        getnext();
        int i = n;
        while(i > 0){
            a.push_back(n - ne[i]);
            i = ne[i];
        }
        printf("Case #%d: %d\n",++ kase,a.size());
        for(i = 0;i < a.size();i ++){
            printf("%d",a[i]);
            if(i == a.size() - 1) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}