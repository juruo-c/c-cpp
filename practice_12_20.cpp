//#include<iostream>
//#include<vector>
//#include<cstring>
//#include<map>
//
//using namespace std;
//typedef long long ll;
//const int N = 2e5+10;
//int n, k;
//ll dep, dept, ans;
//bool vis[N];
//struct edge{
//    int v,w;
//};
//vector<edge> t[N];
//struct node
//{
//    int u,v,w;
//};
//map<int,node> ma;
//map<pair<int,int>,bool> m;
//
//void add_edge(int u,int v,int w)
//{
//    t[u].push_back(edge{v,w});
//}
//void break_edge(int u,int v,int w)
//{
//    for(int i = 0;i < t[u].size();i++){
//        if(t[u][i].v == v) m[{u,v}] = 1;
//    }
//}
//ll f[N];
//void dfs1(int u)
//{
//    for(auto x:t[u]){
//        int v = x.v,w = x.w;
//        if(!vis[v]){
//            ans += w;
//            vis[v] = 1;
//            dfs1(v);
//            ans -= w;
//        }
//    }
//    f[u] = ans;
//}
//
//void dfs2(int u)
//{
//    for(auto x : t[u]){
//        int v = x.v,w = x.w;
//        if(!vis[v] && !m[{u,v}]){
//            vis[v] = 1;
//            dfs2(v);
//        }
//    }
//    dep = max(f[u],dep);
//}
//
//void dfs(int u)
//{
//    for(auto x : t[u]){
//        int v = x.v;
//        if(!vis[v] && !m[{u,v}]){
//            vis[v] = 1;
//            dfs(v);
//        }
//    }
//    dept = max(f[u],dept);
//}
//
//int main()
//{
//    cin >> n >> k ;
//    int u,v,w;
//    for(int i = 0;i < n-1;i ++){
//        cin >> u >> v >> w;
//        ma[i+1] = {u,v,w};
//        m[{u,v}] = 0;
//        add_edge(u,v,w);
//    }
//
//    memset(vis,0,sizeof(vis));
//    ans = 0;
//    dfs1(1);
//
//    for(int i = 1;i <= n;i ++){
//        cout << i << ": " << f[i] << endl;
//    }
//
//    vector<int> opera;
//    while(k --){
//        int op;cin >> op;
//        opera.push_back(op);
//        node tmp = ma[op];
//        break_edge(tmp.u,tmp.v,tmp.w);
//    }
//
//    dep = 0;
//    memset(vis,0,sizeof(vis));
//    dfs2(1);
//
//    vector<ll> depth;
//    depth.push_back(dep);
//
//    for(int i = opera.size() - 1;i >= 0;i --){
//        int x = opera[i];
//        node tmp = ma[x];
//        int u = tmp.u,v = tmp.v;
//        m[{u,v}] = 0;
//        dept = 0;
//        memset(vis,0,sizeof(vis));
//        dfs(1);
//        dep = max(dept,dep);
//        depth.push_back(dep);
//    }
//
//    for(int i = depth.size() - 2;i >= 0;i --)
//        cout << depth[i] << endl;
//
//    return 0;
//}

//#include<iostream>
//#include<stack>
//
//using namespace std;
//const int N = 1010;
//int a[N];
//
//int main()
//{
//    int n;
//    while(cin >> n && n){
//        while(cin >> a[1] && a[1]){
//            for(int i = 2;i <= n;i ++){
//                cin >> a[i];
//            }
//            int j = 1;
//            stack<int> stk;
//            for(int i = 1;i <= n;i ++){
//                stk.push(i);
//                while(!stk.empty() && stk.top() == a[j]){
//                    j ++;
//                    stk.pop();
//                }
//            }
//            if(j == n+1 && stk.empty()) cout << "Yes" << endl;
//            else cout << "No" << endl;
//        }
//        cout << endl;
//    }
//    return 0;
//}

#include<iostream>
#include<cstdio>
#include<stack>
#include<string>

using namespace std;

struct matrix{
    int a,b;
    matrix(int a = 0, int b = 0):a(a),b(b){}
}m[26];

stack<matrix> s;

int main()
{
    int n;cin >> n;
    for(int i = 0;i < n;i ++){
        string name;cin >> name;
        int k = name[0] - 'A';
        cin >> m[k].a >> m[k].b;
    }
    string expr;
    while(cin >> expr){
        int len = expr.length();
        bool error = false;
        int ans = 0;
        for(int i = 0;i < len;i ++){
            if(isalpha(expr[i])) s.push(m[expr[i] - 'A']);
            else if(expr[i] == ')')
            {
                matrix m2 = s.top();s.pop();
                matrix m1 = s.top();s.pop();
                if(m1.b != m2.a ){
                    error = 1;break;
                }
                ans += m1.a*m1.b*m2.b;
                s.push(matrix(m1.a,m2.b));
            }
        }
        if(error) cout << "error" << endl;
        else cout << ans << endl;
    }
    return 0;
}








