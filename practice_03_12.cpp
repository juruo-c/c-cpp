//
// Created by 19116 on 2021/3/12.
//

//#include<iostream>
//
//using namespace std;
//
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int n,k;
//        cin >> n >> k;
//        string s;cin >> s;
//        int i;
//        int cnt = 0;
//        for(i = 0;i < n / 2;i ++){
//            if(s[i] == s[n - 1 - i]) cnt ++;
//            else break;
//        }
//        if(i < n / 2 || n % 2) cnt ++;
//        if(k + 1 <= cnt) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<set>
//
//using namespace std;
//const int N = 1e5 + 10;
//typedef long long ll;
//int main(){
//    int t;cin >> t;
//    while(t --){
//        set<ll> s;
//        ll n,k;
//        cin >> n >> k;
//        ll a[N];
//        ll maxx = 0;
//        for(int i = 0;i < n;i ++){
//            cin >> a[i];
//            s.insert(a[i]);
//            maxx = max(a[i],maxx);
//        }
//        sort(a ,a + n);
//        ll mex;
//        bool fl = 0;
//        for(int i = 0;i < n;i ++){
//            if(a[i] > i){
//                mex = i;
//                fl = 1;
//                break;
//            }
//        }
//        if(!fl) mex = n;
////        cout << "mex: " << mex << endl;
//        if(mex > maxx) cout << n + k << endl;
//        else{
//            if(k > 0 && !s.count((maxx + mex + 1) / 2))
//                cout << n + 1 << endl;
//            else cout << n << endl;
//        }
//    }
//    return 0;
//}

//
//#include<iostream>
//
//using namespace std;
//
//class Stack{
//public:
//    Stack();
//    Stack(int s);
//    int get(int index);
//    void push(int n);
//    bool isempty();
//    int pop();
//    ~Stack();
//
//private:
//    int* a;
//    int size,top;
//};
//
//Stack::Stack(){
//    a = new int[10];
//    size = 10;
//}
//Stack::Stack(int s){
//    a = new int[s];
//    size = s;
//}
//int Stack::get(int index){
//    return a[index];
//}
//void Stack::push(int n){
//    a[top ++] = n;
//}
//bool Stack::isempty(){
//    return !top;
//}
//int Stack::pop(){
//    if(top > 0) return a[-- top];
//    else return a[top];
//}
//Stack::~Stack(){
//    if(a != NULL){
//        delete[] a;
//        a = NULL;
//    }
//}
//
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int n;cin >> n;
//        Stack stk(n);
//        for(int i = 0; i < n;i ++){
//            int tt;cin >> tt;
//            stk.push(tt);
//        }
//        for(int i = 0;i < n; i++){
//            if(i) cout << " ";
//            cout << stk.pop() ;
//        }
//        cout << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main(){
//    double n;cin >> n;
//    ios_base::fmtflags orig = cout.setf(ios_base::fixed,ios_base::floatfield);
//    streamsize prec = cout.precision(2);
//    cout << n << endl;
//    double a;cin >> a;
//    cout << a << endl;
//    cout.precision(prec);
//    cout << a << endl;
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//typedef long long ll;
//const int N = 1e4 + 10,M = 2e5 + 10;
//int n,m,s,t;
//struct edge{
//    int next,to;ll w;
//}e[M];
//ll head[N],cnt = 1;
//void add(int u,int v,ll w){
//    e[++ cnt].to = v;
//    e[cnt].next = head[u];
//    e[cnt].w = w;
//    head[u] = cnt;
//}
//bool vis[N];
//ll dfs(int u,ll flow){
//    if(u == t) return flow;
//    vis[u] = 1;
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        int res = 0;
//        if((res = dfs(v,min(flow,e[i].w))) > 0){
//            e[i].w -= res;
//            e[i ^ 1].w += res;
//            return res;
//        }
//    }
//    return 0;
//}
//
//int main(){
//    scanf("%d%d%d%d",&n,&m,&s,&t);
//    for(int i = 1;i <= m;i ++){
//        int u,v; ll w;
//        scanf("%d%d%lld",&u,&v,&w);
//        add(u,v,w);
//        add(v,u,0);
//    }
//    ll res = 0,tot = 0;
//    while(memset(vis,0,sizeof(vis)) && (res = dfs(s,1e18)) > 0)
//        tot += res;
//    printf("%lld\n",tot);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//typedef long long ll;
//const int N = 1e4 + 10,M = 2e5 + 10;
//int n,m,s,t;ll ans = 0;
//ll cnt = 1,head[N];
//struct edge{
//    ll next,to,w;
//}e[M];
//inline void add(ll u,ll v,ll w){
//    e[++ cnt].to = v;
//    e[cnt].next = head[u];
//    e[cnt].w = w;
//    head[u] = cnt;
//}
//int dep[N],q[N],l,r;
//bool bfs(){
//    memset(dep,0,sizeof(dep));
//
//    q[l = r = 1] = s;
//    dep[s] = 1;
//    while(l <= r){
//        int u = q[l ++];
//        for(int i = head[u];i;i = e[i].next){
//            int v = e[i].to;
//            if(e[i].w && !dep[v]){
//                dep[v] = dep[u] + 1;
//                q[++ r] = v;
//            }
//        }
//    }
//    return dep[t];
//}
//
//ll dfs(int u,ll in){
//    if(u == t) return in;
//    ll out = 0;
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(e[i].w && dep[v] == dep[u] + 1){
//            ll res = dfs(v,min(e[i].w,in));
//            e[i].w -= res;
//            e[i ^ 1].w += res;
//            in -= res;
//            out += res;
//        }
//    }
//    if(out == 0) dep[u] = 0;
//    return out;
//}
//
//int main(){
//    scanf("%d%d%d%d",&n,&m,&s,&t);
//    for(int i = 1;i <= m;i ++){
//        int u,v; ll w;
//        scanf("%d%d%lld",&u,&v,&w);
//        add(u,v,w);
//        add(v,u,0);
//    }
//    while(bfs()){
//        ans += dfs(s,1e18);
//    }
//    printf("%lld\n",ans);
//    return 0;
//}



//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//typedef long long ll;
//const int N = 1e4 + 10,M = 2e5 + 10;
//struct edge{
//    ll next,to,w;
//}e[M];
//ll head[N],cnt = 1;
//void add(ll u,ll v,ll w){
//    e[++ cnt].to = v;
//    e[cnt].next = head[u];
//    e[cnt].w = w;
//    head[u] = cnt;
//}
//int dep[N],q[N],l,r;
//int n,m,s,t;
//ll ans = 0;
//bool bfs(){
//    memset(dep,0,sizeof(dep));
//
//    q[l = r = 1] = s;
//    dep[s] = 1;
//    while(l <= r){
//        int u = q[l ++];
//        for(int i = head[u];i;i = e[i].next){
//            int v = e[i].to;
//            if(e[i].w && !dep[v]){
//                dep[v] = dep[u] + 1;
//                q[++ r] = v;
//            }
//        }
//    }
//    return dep[t];
//}
//ll dfs(int u,ll in){
//    if(u == t) return in;
//    ll out = 0;
//    for(int i = head[u];i && in;i = e[i].next){
//        int v = e[i].to;
//        if(e[i].w && dep[v] == dep[u] + 1){
//            ll res = dfs(v,min(e[i].w,in));
//            e[i].w -= res;
//            e[i ^ 1].w += res;
//            in -= res;
//            out += res;
//        }
//    }
//    if(!out) dep[u] = 0;
//    return out;
//}
//int main(){
//    scanf("%d%d%d%d",&n,&m,&s,&t);
//    for(int i = 1;i <= m;i ++){
//        int u,v;ll w;
//        scanf("%d%d%lld",&u,&v,&w);
//        add(u,v,w);
//        add(v,u,0);
//    }
//    while(bfs()){
//        ans += dfs(s,1e18);
//    }
//    printf("%lld\n",ans);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//const int N = 2e4 + 10,M = 2e5 + 10,INF = 0x3f3f3f3f;
//int n,s,t;
//struct edge{
//    int next,to,w;
//}e[M << 1];
//int head[N],cnt;
//int h[N],et[N],gap[N << 1],inq[N];
//struct cmp{
//    inline bool operator() (int a,int b) const{
//        return h[a] < h[b];
//    }
//};
//queue<int> q;
//priority_queue<int,vector<int>,cmp) pq;
//
//void add(int u,int v,int w){
//
//}
//int main(){
//
//    return 0;
//}


//#include<bits/stdc++.h>
//
//using namespace std;
//typedef long long ll;
//const int N = 1e4 + 10,M = 2e5 + 10;
//int n,m,s,t;ll ans = 0;
//ll cnt = 1,head[N];
//struct edge{
//    ll next,to,w;
//}e[M];
//void add(ll u,ll v,ll w){
//    e[++ cnt].to = v;
//    e[cnt].next = head[u];
//    e[cnt].w = w;
//    head[u] = cnt;
//}
//int dep[N],q[N],l,r;
//
//bool bfs(){
//    memset(dep,0,sizeof(dep));
//    q[l = r = 1] = s;
//    dep[s] = 1;
//    while(l <= r){
//        int u = q[l ++];
//        for(int i = head[u];i;i = e[i].next){
//            int v = e[i].to;
//            if(e[i].w && !dep[v]){
//                dep[v] = dep[u] + 1;
//                q[++ r] = v;
//            }
//        }
//    }
//    return dep[t];
//}
//
//ll dfs(int u,ll in){
//    if(u == t) return in;
//    ll out = 0;
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(e[i].w && dep[v] == dep[u] + 1){
//            ll res = dfs(v,min(e[i].w,in));
//            e[i].w -= res;
//            e[i ^ 1].w += res;
//            in -= res;
//            out += res;
//        }
//    }
//    if(!out) dep[u] = 0;
//    return out;
//}
//int main(){
//    scanf("%d%d%d%d",&n,&m,&s,&t);
//    for(int i = 1;i <= m;i ++){
//        int u,v;ll w;
//        scanf("%d%d%lld",&u,&v,&w);
//        add(u,v,w);
//        add(v,u,0);
//    }
//    while(bfs()){
//        ans += dfs(s,1e18);
//    }
//    printf("%lld\n",ans);
//    return 0;
//}

//#include<bits/stdc++.h>
//
//using namespace std;
//typedef long long ll;
//const int N = 1e4 + 10,M = 2e5 + 10;
//int n,m,s,t;ll ans = 0;
//ll cnt = 1,head[N];
//struct edge{
//    ll next,to,w;
//}e[M];
//void add(int u,int v,ll w){
//    e[++ cnt].to = v;
//    e[cnt].w = w;
//    e[cnt].next = head[u];
//    head[u] = cnt;
//}
//int dep[N],q[N],l,r;
//bool bfs(){
//    memset(dep,0,sizeof(dep));
//    q[l = r = 1] = s;
//    dep[s] = 1;
//    while(l <= r){
//        int u = q[l ++];
//        for(int i = head[u];i;i = e[i].next){
//            int v = e[i].w;
//            if(e[i].w && !dep[v]){
//                dep[v] = dep[u] + 1;
//                q[++ r] = v;
//            }
//        }
//    }
//    return dep[t];
//}
//
//ll dfs(int u,ll in){
//    if(u == t) return in;
//    ll out = 0;
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(e[i].w && dep[v] == dep[u] + 1){
//            ll res = dfs(v,min(e[i].w,in));
//            e[i].w -= res;
//            e[i ^ 1].w += res;
//            in -= res;
//            out += res;
//        }
//    }
//    if(!out) dep[u] = 0;
//    return out;
//}
//int main(){
//
//    return 0;
//}

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e4 + 10,M = 2e5 + 10;
struct edge{
    ll next,to,w;
}e[M];
ll head[N],cnt = 1;
void add(int u,int v,ll w){
    e[++ cnt].to = v;
    e[cnt].next = head[u];
    e[cnt].w = w;
    head[u] = cnt;
}
int n,m,s,t;ll ans;
int dep[N],q[N],l,r;
bool bfs(){
    memset(dep,0,sizeof(dep));
    q[l = r = 1] = s;
    dep[s] = 1;
    while(l <= r){
        int u = q[l ++];
        for(int i = head[u];i;i = e[i].next){
            int v = e[i].to;
            if(e[i].w && !dep[v]){
                dep[v] = dep[u] + 1;
                q[++ r] = v;
            }
        }
    }
    return dep[t];
}

ll dfs(int u,ll in){
    if(u == t) return in;
    ll out = 0;
    for(int i = head[u];i && in;i = e[i].next){
        int v = e[i].to;
        if(e[i].w && dep[v] == dep[u] + 1){
            ll res = dfs(v,min(e[i].w,in));
            e[i].w -= res;
            e[i ^ 1].w += res;
            in -= res;
            out += res;
        }
    }
    if(!out) dep[u] = 0;
    return out;
}
int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i = 1;i <= m;i ++){
        int u,v;ll w;
        scanf("%d%d%lld",&u,&v,&w);
        add(u,v,w);
        add(v,u,0);
    }
    while(bfs()){
        ans += dfs(s,1e18);
    }
    printf("%lld",ans);
    return 0;
}

