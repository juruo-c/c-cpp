////
//// Created by 19116 on 2021/1/6.
////
//
//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//    char a[110];
//    for(int i = 0;i < n;i ++) cin >> a[i];
//    for(int i = 0;i < (1 << n);i ++){
//        cout << "{";
//        int cnt = 0;
//        for(int j = 0;j < n;j ++){
//            if((i >> j) & 1){
//                if(cnt) cout << ",";
//                cout << a[j];
//                cnt ++;
//            }
//        }
//        cout << "}" << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//int index;char a[110],b[110];
//
//void dfs(int start,int pos,int len,int nowlen){
//    if(start > pos){
//        if(nowlen == len){
//            cout << "{";
//            for(int i = 1;i <= index;i ++){
//                cout << b[i] << ",";
//            }
//            cout << a[pos + 1] << "}" << endl;
//        }
//        return;
//    }
//
//    b[++index] = a[start];
//    dfs(start + 1,pos,len,nowlen + 1);
//    index --;
//    dfs(start + 1,pos,len,nowlen);
//}
//
//int main()
//{
//    int t;cin >> t;
//    while(t --){
//        index = 0;
//        int n;cin >> n;
//        for(int i = 1;i <= n;i ++) cin >> a[i];
//
//        cout << (1 << n) << endl;
//        cout << "{}" << endl;
//        for(int pos = 1;pos <= n;pos ++){
//            for(int len = 0;len <= pos - 1;len ++){
//                dfs(1,pos - 1,len,0);
//            }
//        }
//
//    }
//    return 0;
//}
//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//    int n;cin >> n;
//    while(n --){
//        int a[10];int ans = 0;
//        for(int i = 0;i < 10;i ++){
//            cin >> a[i];
//            if(a[i] < 0)ans ++;
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}


//#include<iostream>
//
//using namespace std;
//
//int main(){
//    int a[20];
//    for(int i = 0;i < 20;i ++)cin >> a[i];
//    for(int i = 0;i < 20;i ++){
//        for(int j = 0;j < 20;j ++){
//            if(i == j)continue;
//            if(a[i] % a[j] == 0){
//                cout << a[i] << endl;
//                break;
//            }
//        }
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//    int a[6],b[8];
//    for(int i = 0;i < 6;i ++) cin >> a[i];
//    for(int i = 0;i < 8;i ++) cin >> b[i];
//    for(int i = 0;i < 6;i ++)
//        for(int j = 0;j < 8;j ++)
//            if(a[i] == b[j]) cout << a[i] << endl;
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//    int t;cin >>t;
//    while(t --){
//        int a[10];
//        for(int i = 0;i < 10;i ++)cin >> a[i];
//        int k; cin >> k;
//        int flag = 0;
//        for(int i = 0;i < 10;i ++){
//            if(a[i] == k){
//                flag = 1;
//                for(int j = i;j < 9;j ++)
//                    a[j] = a[j + 1];
//            }
//        }
//        if(flag){
//            for(int i = 0;i < 9;i ++) {
//                if (i) cout << " ";
//                cout << a[i];
//            }
//            cout << endl;
//        }
//        else cout << "Not found" << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//    int a[10];
//    for(int i = 0;i < 9;i ++)cin >> a[i];
//    int k;cin >> k;
//    for(int i = 0;i < 9;i ++){
//        if(a[i] <= k && a[i + 1] >= k) {
//            for(int j = 9;j > i + 1;j --)
//                a[j] = a[j - 1];
//            a[i + 1] = k;
//            break;
//        }
//    }
//
//    for(int i = 0;i < 10;i ++)
//        cout << a[i] << endl;
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//    int t;
//    cin >> t;
//    while(t --){
//        int n;int a[110];
//        cin >> n;
//        for(int i = 0;i < n;i ++)cin >> a[i];
//        int l = 0,r = n - 1;
//        while(l < r){
//            while(a[l] % 2 == 0)l ++;
//            while(a[r] % 2) r --;
//            if(l > r) break;
//            swap(a[l],a[r]);
//            l ++;
//            r --;
//        }
//        cout << n;
//        for(int i = 0;i < n;i ++) cout << " " << a[i];
//        cout << endl;
//    }
//    return 0;
//}
//
//#include<iostream>
//#include<cstring>
//#include<queue>
//#include<cstdio>
//
//using namespace std;
//const int N = 1e6 + 10;
//const int INF = 1e9 + 7;
//typedef long long ll;
//ll d[N],res[N];int tot;
//int n,m;
//bool vis[N];
//struct Edge
//{
//    int to,w,next;
//}g[N],a[N];
//int headg[N];
//struct node{
//    ll d;int s;
//    bool operator < (const node& b)const {
//        return d > b.d;
//    }
//};
//
//void dij(int s){
//    priority_queue<node> q;
//    for(int i = 1;i <= n;i ++)d[i] = INF;
//    memset(vis,0,sizeof(vis));
//    d[s] = 0;
//    q.push((node){0,s});
//    while(!q.empty()){
//        int u = q.top().s;q.pop();
//        if(vis[u])continue;
//        vis[u] = 1;
//        for(int i = headg[u];i != -1;i = g[i].next){
//            int w = g[i].w;
//            int v = g[i].to;
//            if(!vis[v] && d[v] > d[u] + w){
//                d[v] = d[u] + w;
//                q.push((node){d[v],v});
//            }
//        }
//    }
//}
//
//void add_edge(int u,int v,int w){
//    g[tot].to = v;
//    g[tot].next = headg[u];
//    g[tot].w = w;
//    headg[u] = tot ++;
//}
//void init()
//{
//    memset(headg,-1,sizeof(headg));
//    tot = 0;
//}
//
//struct edge
//{
//    int u,v,w;
//}point[N];
//
//int main(){
//    int t;scanf("%d",&t);
//    while(t --){
//        init();
//        memset(res,0,sizeof(res));
//        scanf("%d%d",&n,&m);
//
//        for(int i = 0;i < m;i ++){
//            int u,v,w;
//            scanf("%d%d%d",&u,&v,&w);
//            point[i].u = u;
//            point[i].v = v;
//            point[i].w = w;
//            add_edge(u,v,w);
//        }
//
//        dij(1);
//        for(int i = 2;i <= n;i ++)res[i] += d[i];
//
//
//        init();
//        for(int i = 0;i < m;i ++){
//            edge e = point[i];
//            add_edge(e.v,e.u,e.w);
//        }
//
////        for(int i = 1;i <= n;i ++){
////            cout << i << ": " << endl;
////            for(int j = 0;j < g[i].size();j ++)
////                cout << g[i][j].v << " " << g[i][j].w << endl;
////            cout << endl;
////        }
//
//        dij(1);
//        ll ans = 0;
//        for(int i = 2;i <= n;i ++){
//            res[i] += d[i];
//            ans += res[i];
//        }
//
//        printf("%lld\n",ans);
//    }
//    return 0;
//}
//
//#include <stdio.h>
//int n,k,flag=0,ans;
//int a[1010];
//void sum(int num[],int floor,int count,int s);
//int main()
//{
//    while (scanf("%d%d",&n,&k)!=EOF){
//        flag=0;
//        ans=0;
//        int num[1010]={0};
//        for (int i=0;i<n;i++)
//            scanf("%d",&a[i]);
//        sum(num,0,0,0);
//        if (!flag) puts("NO");
//    }
//}
//
//void sum(int num[],int floor,int pos,int s)
//{
//    if (pos==n){
//        ans=1;
//        return;
//    }
//    for (int i=pos;i<n;i++){
//        num[floor]=a[i];
//        if (s+num[floor]==k){
//            flag=1;
//            puts("YES");
//            ans=1;
//            for (int j=0;j<=floor;j++)
//                if (j!=floor) printf("%d ",num[j]);
//                else printf("%d\n",num[j]);
//            return;
//        }
//        if (s+num[floor]>k) continue;
//        if (i==n-1) return;
//        sum(num,floor+1,i+1,s+num[floor]);
//        if (ans) return;
//    }
//}


//#include<iostream>
//#include<cstdio>
//#include<vector>
//#include<cstring>
//#include<queue>
//
//using namespace std;
//const int N = 3e4 + 10;
//const int INF = 0x3f3f3f3f;
//int n, m,d[N];
//struct edge{
//    int v,w;
//};
//vector<edge> G[N];
//struct node
//{
//    int d,s;
//    bool operator < (const node& b)const {
//        return d > b.d;
//    }
//};
//bool vis[N];
//void spfa(int s){
//    memset(vis,0,sizeof(vis));
//    for(int i = 1;i <= n;i ++)d[i] = INF;
//    queue<int> q;
//    d[s] = 0;
//    q.push(s);vis[s] = 1;
//    while(!q.empty()){
//        int u = q.front();q.pop();
//        vis[u] = 0;
//        for(int i = 0;i < G[u].size();i ++){
//            int v = G[u][i].v;
//            int w = G[u][i].w;
//            if(d[v] > d[u] + w){
//                d[v] = d[u] + w;
//                if(!vis[v]){
//                    q.push(v);
//                    vis[v] = 1;
//                }
//            }
//        }
//    }
//}
//int main(){
//    while(scanf("%d%d",&n,&m) != EOF)
//    {
//        for(int i = 1;i <= n;i ++)G[i].clear();
//        for(int i = 0;i < m;i ++){
//            int u,v,w;
//            scanf("%d%d%d",&u,&v,&w);
//            G[u].push_back((edge){v,w});
//        }
//
//        spfa(1);
//
//        printf("%d\n",d[n]);
//    }
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<stack>
//#include<algorithm>
//
//using namespace std;
//const int N = 3e4 + 10;
//const int INF = 0x3f3f3f3f;
//int n,m;int head[N],d[N];
//bool vis[N];
//struct edge{
//    int u,v,w,next;
//}e[N * 10];
//
//void add_edge(int u,int v,int w,int k){
//    e[k].u = u;
//    e[k].v = v;
//    e[k].w = w;
//    e[k].next = head[u];
//    head[u] = k;
//}
//
//void spfa()
//{
//    stack<int> stk;
//    stk.push(1);
//    while(stk.size()){
//        int i = stk.top();stk.pop();
//        vis[i] = 0;
//        for(int j = head[i];j != 0;j = e[j].next){
//            int u = e[j].u,v = e[j].v,w = e[j].w;
//            if(d[v] > d[u] + w){
//                d[v] = d[u] + w;
//                if(!vis[v]){
//                    vis[v] = 1;
//                    stk.push(v);
//                }
//            }
//        }
//    }
//}
//int main(){
//    while(scanf("%d%d",&n,&m) != EOF){
//        for(int i = 1;i <= n;i ++)
//            d[i] = INF,head[i] = 0;
//        d[1] = 0;
//        for(int i = 1;i <= m;i ++){
//            int u,v,w;
//            scanf("%d%d%d",&u,&v,&w);
//            add_edge(u,v,w,i);
//        }
//
//        spfa();
//
//        printf("%d\n",d[n]);
//    }
//    return 0;
//}

//#include<iostream>
//#include<vector>
//#include<cstring>
//
//using namespace std;
//int n,k,a[110];
//vector<int> num;int flag;
//void dfs(int cur,int sum,int k)
//{
//    if(flag)return;
//    if(sum == k && num.size()){
//        cout << "YES" << endl;
//        for(int i = 0;i < num.size();i ++){
//            if(i) cout << " ";
//            cout << num[i];
//        }
//        cout << endl;
//        flag = 1;
//        return ;
//    }
//    if(cur == n)return;
//    num.push_back(a[cur]);
//    dfs(cur + 1,sum + a[cur],k);
//    num.pop_back();
//    dfs(cur + 1,sum,k);
//}
//int main()
//{
//    while(cin >> n >> k){
//        for(int i = 0;i < n;i ++)cin >> a[i];
//        num.clear();flag = 0;
//        dfs(0,0,k);
//        if(!flag) cout << "NO" << endl;
//    }
//    return 0;
//}

#include<iostream>

using namespace std;

int main()
{

    return 0;
}