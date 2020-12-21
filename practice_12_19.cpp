//#include<iostream>
//#include<map>
//#include<set>
//#include<vector>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 5e5+10;
//
//int n;
//vector<int> v;
//
//
//int main()
//{
//    while(cin >> n && n){
//        v.clear();map<int,multiset<int> > ma;
//        map<int,int> p;
//        for(int i = 0 ;i < n;i++){
//            int a ,b;
//            cin >> a >> b;
//            v.push_back(a);
//            p[a] = b;
//            ma[a].insert(b);
//        }
//
//
//        int flag = 1;
//        for(auto x:v){
//            if(ma[p[x]].count(x)){
//                auto pos = ma[p[x]].find(x);
//                ma[p[x]].erase(pos);
//                for(auto y:v){
//                    cout << y << ":" ;
//                    for(auto i : ma[y]){
//                        cout << i << " ";
//                    }
//                    cout << endl ;
//                }
//                cout << endl;
//            }
//            else{
//                flag = 0;
//                cout << "NO" << endl;
//                break;
//            }
//
//        }
//        if(flag) cout << "YES" << endl;
//    }
//    return 0;
//}
//#include<iostream>
//#include<map>
//
//using namespace std;
//
//int n,a,b;
//
//int main()
//{
//    while(cin >> n && n != 0){
//        map<pair<int,int>,int> cnt;
//        for(int i = 0;i < n;i++){
//            cin >> a >> b;
//            if(a < b) ++ cnt[{a,b}];
//            else if(a > b) --cnt[{b,a}];
//        }
//        bool flag = 1;
//        for(auto p : cnt){
//            if(p.second != 0){
//                flag = 0;
//                break;
//            }
//        }
//        if(flag) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}
//

//#include<iostream>
//#include<string>
//#include<cstring>
//#include<algorithm>
//#include<set>
//
//using namespace std;
//
//string s;
//set<string> _set;
//
//int main()
//{
//    while(cin >> s) _set.insert(s);
//    for(auto x : _set){
//        int flag = 0;
//        for(int len = 1;len < x.length(); len ++){
//            if(_set.count(x.substr(0,len)) && _set.count(x.substr(len)))flag = 1;
//        }
//        if(flag) cout << x << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<map>
//#include<set>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//set<int> _set;
//
//int n;
//
//int main()
//{
//    int t;cin >> t;
//    while(t--){
//        _set.clear();map<int,vector<int> > ma;
//        int x,y;
//        cin >> n;
//        for(int i = 0;i < n;i++){
//            cin >> x >> y;
//            ma[y].push_back(x);
//        }
//
//        for(auto x : ma){
//            sort(x.second.begin(),x.second.end());
//            int mid = (x.second.size() % 2 == 0) ? x.second.size()/2 : x.second.size()/2 + 1;
//            for(int i = 0;i < mid ;i ++){
//                _set.insert(x.second[i] + x.second[x.second.size() - 1 - i]);
//            }
//        }
//
//        if(_set.size() == 1) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//struct node
//{
//    int po,val;
//};
//
//int main()
//{
//    int t; cin >> t;
//    while(t --){
//        int n,pos,val;
//        int ans = 0 ;
//        vector<node> v;
//        cin >> n >> pos;
//        for(int i = 0;i < n;i ++ ){
//            cin >> val;
//            v.push_back(node{i,val});
//        }
//        while(1){
//            node cur = v[0];
//            auto it = v.begin();
//            v.erase(it);int flag = 1;
//            for(int i = 0;i < v.size();i++){
//                if(v[i].val > cur.val){
//                    flag = 0;
//                    break;
//                }
//            }
//            if(flag){
//                ans ++;
//                if(cur.po == pos){
//                    cout << ans << endl ;
//                    break;
//                }
//            }
//            else{
//                v.push_back(cur);
//            }
//        }
//
//    }
//    return 0;
//}
#include<iostream>
#include<vector>
#include<cstring>
#include<map>

using namespace std;
typedef long long ll;
const int N = 2e5+10;
int n,k;ll ans;ll out;
bool vis[N];
struct edge{
    int v,w;
};
vector<edge> t[N];
struct node
{
    int u,v,w;
};
map<int,node> ma;
map<pair<int,int>,bool> m;

void add_edge(int u,int v,int w)
{
    t[u].push_back(edge{v,w});
}
void break_edge(int u,int v,int w)
{
    for(int i = 0;i < t[u].size();i++){
        if(t[u][i].v == v) m[{u,v}] = 1;
    }
}
ll f[N];
void dfs1(int u)
{
//    if(ans < f[u]){
//        return;
//    }
    for(auto x:t[u]){
        int v = x.v,w = x.w;
        if(!vis[v]){
            ans += w;
            vis[v] = 1;
            dfs(v);
            ans -= w;
        }
    }

    f[u] = ans;
//    out = max(out,ans);
}

int dfs2(int u)
{
    for(auto x : t[u]){
        int tmp
    }
}

int main()
{
    cin >> n >> k ;
    int u,v,w;
    for(int i = 0;i < n-1;i ++){
        cin >> u >> v >> w;
        ma[i+1] = {u,v,w};
        m[{u,v}] = 0;
        add_edge(u,v,w);
    }

    memset(vis,0,sizeof(vis));
    ans = 0;
    dfs1(1);

    vector<int> opera;
    while(k --){
        int op;cin >> op;
        opera.push_back(op);
        node tmp = ma[op];
        break_edge(tmp.u,tmp.v,tmp.w);
    }

    int dep = dfs2(1);


    return 0;
}

//#include<stack>
//#include<iostream>
//using namespace std;
//
//const int N = 1e3+10;
//
//int n,ta[N];
//
//int main()
//{
//
//    while(cin >> n && n){
//        stack<int>  s;
//        int a = 1, b = 1;
//        for(int i = 1;i <= n;i ++){
//            cin >> ta[i];
//        }
//        int ok = 1;
//        while(b <= n){
//            if(a == ta[b]){
//                a ++;b ++;
//            }
//            else if(!s.empty() && s.top() == ta[b]){
//                s.pop();b ++;
//            }
//            else if(a <= n) s.push(a ++);
//            else {
//                ok = 0;
//                break;
//            }
//        }
//        if(ok) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}
//

//#include<iostream>
//#include<stack>
//#include<cstring>
//#include<cstdlib>
//
//using namespace std;
//
//int n,a[1010];
//
//int main()
//{
//    while(cin >> n && n){
//        while(cin >> a[1] && a[1]){
//            for(int i = 2;i <= n;i ++) cin >> a[i];
//            stack<int> stk;
//            int j = 1;
//            for(int i = 1;i <= n;i ++){
//                stk.push(i);
//                while(!stk.empty() && stk.top() == a[j]) stk.pop(),j ++;
//            }
//            if(stk.empty() && j == n + 1) cout << "Yes" << endl;
//            else cout << "NO" << endl;
//        }
//        puts("");
//    }
//    return 0;
//}















