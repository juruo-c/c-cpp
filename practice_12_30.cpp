//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<sstream>
//#include<vector>
//#include<map>
//
//using namespace std;
//string s,st;int ans,n;
//vector<int> g[10];
//
//void dfs(cur)
//{
//    if(cur == n)
//}
//
//int main()
//{
//    while(getline(cin,s) && s[0] != '#'){
//        ans = 0;n = 0;
//        for(int i = 0;i < 10;i ++) g[i].clear();
//        for(int i = 0;i < s.length();i ++)
//            if(s[i] == ';') s[i] = ' ';
//        stringstream input(s);
//        while(input >> st){
//            int tmp = st[0] - 'A' + 1;
//            for(int i = 2;i < st.length();i ++){
//                g[tmp].push_back(st[i] - 'A' + 1);
//            }
//        }
//
//        dfs();
//    }
//    return 0;
//}
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<map>
//#include<set>
//#include<vector>
//#include<sstream>
//
//using namespace std;
//
//int minn, vis[26];
//map<char,set<char> > g;
//vector<char> ans,tans,node;
//
//void cal()
//{
//    map<char,int> pos;
//    for(int i = 0;i < tans.size();i ++) pos[tans[i]] = i;
//    int maxw = -1;
//    for(char u : tans){
//        for(char v : g[u]) maxw = max(maxw,abs(pos[u] - pos[v]));
//    }
//    if(minn > maxw){
//        minn = maxw;
//        ans = tans;
//    }
//}
//
//void dfs(int cur){
//    if(cur == node.size()){
//        cal();
//        return;
//    }
//    for(char v : node){
//        if(vis[v - 'A'] == 0){
//            tans.push_back(v);
//            vis[v - 'A'] = 1;
//            dfs(cur + 1);
//            tans.pop_back();
//            vis[v - 'A'] = 0;
//        }
//    }
//}
//
//int main()
//{
//    string line,s;
//    while(getline(cin,line) && line[0] != '#'){
//        g.clear();stringstream input(line);
//        while(getline(input , s, ';')){
//            for(char v : s.substr(2)){
//                g[s[0]].insert(v);g[v].insert(s[0]);
//            }
//        }
//        node.clear();
//        for(auto p : g)node.push_back(p.first);
//        minn = 0x3f3f3f3f;
//        memset(vis,0,sizeof(vis));
//        dfs(0);
//        for(int i = 0;i < ans.size();i ++)
//            cout << ans[i] << " ";
//        cout << "-> " << minn << endl;
//    }
//    return 0;
//}
//#include<bits/stdc++.h>
//
//using namespace std;
//set<char> _set;
//vector<char> ans,tmp;
//bool e[30][30];
//int best,tmp_best;
//
//void dfs(int cur){
//    if(cur == _set.size()){
//        best = tmp_best;
//        ans = tmp;
//        return;
//    }
//    for(auto u : _set){
//        bool ok = 1;
//        tmp.push_back(u);
//        for(int i = 0;i < cur;i ++){
//            if(tmp[i] == u){
//                ok = 0;
//                break;
//            }
//        }
//        for(int i = 0;i < cur && ok;i ++){
//            if(e[u - 'A'][tmp[i] - 'A'] && cur - i > tmp_best) tmp_best = cur - i;
//            if(tmp_best >= best){
//                ok = 0;
//                break;
//            }
//        }
//        int last = tmp_best;
//        if(ok) dfs(cur + 1);
//        tmp.pop_back();
//        tmp_best = last;
//    }
//}
//
//int main()
//{
//    string s;
//    while(getline(cin,s) && s[0] != '#'){
//        _set.clear();tmp.clear();
//        memset(e,0,sizeof(e));
//        for(int i = 0;i < s.size();i ++) if(!isalpha(s[i])) s[i] = ' ';
//        stringstream ss(s);
//        char a;string b;
//        while(ss >> a >> b){
//            _set.insert(a);
//            for(int i = 0;i < b.size();i ++){
//                _set.insert(b[i]);
//                e[a - 'A'][b[i] - 'A'] = e[b[i] - 'A'][a - 'A'] = 1;
//            }
//        }
//        best = 100;tmp_best = 0;
//        dfs(0);
//        for(int i = 0;i < ans.size();i ++) cout << ans[i] << " ";
//        cout << "-> " << best << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//void itostr(int num,char str[])
//{
//    if(!num){
//        str[0] = '0';
//        str[1] = '\0';
//        return;
//    }
//    int cur = 0;
//    if(num < 0){
//        str[cur++] = '-';
//        num = -num;
//    }
//    char tmp[30];
//    tmp[0] = '\0';
//    int k = 1;
//    while(num){
//        tmp[k ++] = num % 10 + '0';
//        num /= 10;
//    }
//    for(int i = k - 1;i >= 0;i --){
//        str[cur ++] = tmp[i];
//    }
//}
//
//int main()
//{
//    const int SIZE = 20;
//    int t,num;
//    char str[SIZE];
//
//    cin >> t;
//    while(t --){
//        cin >> num;
//        itostr(num,str);
//        cout << str << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//void dfs(char s[],int cur,int n)
//{
//    if(cur == n - 1){
//        cout << s[cur];
//        return;
//    }
//    dfs(s,cur + 1,n);
//    cout << s[cur];
//}
//
//int main()
//{
//    int n;cin >> n;
//    char s[100];
//    for(int i = 0;i < n;i ++) cin >> s[i];
//    dfs(s,0,n);
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//
//using namespace std;
//bool vis[110];
//int n,m,ans;
//
//void dfs(int cur)
//{
//    if(cur == m){
//        ans ++;
//        return;
//    }
//    if(cur > m) return;
//    for(int i = 1;i <= 2;i ++){
//        dfs(cur + i);
//    }
//}
//
//int main()
//{
//    int t;cin >> t;
//    while(t --){
//        ans = 0;
//        memset(vis,0,sizeof(vis));
//        cin >> n >> m;
//        vis[n] = 1;
//        dfs(n);
//        cout << ans << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//int n;
//
//int main()
//{
//    while(cin >> n){
//        int f[110];
//        f[1] = 3;
//        f[2] = 3 * 2;
//        f[3] = 3 * 2 * 1;
//        for(int i = 4;i <= n;i ++){
//            f[i] = f[i - 1] + f[i - 2] * 2;
//        }
//        cout << f[n] << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//    int t;cin >> t;
//    getchar();
//    while(t --){
//        string s;
//        getline(cin,s);
//        int flag = 1;
//        if((s[0] != '_' && !isalpha(s[0]))|| s.size() > 31){
//            flag = 0;
//        }
//        for(int i = 0;i < s.size();i ++){
//            if(!isalpha(s[i]) && !isdigit(s[i]) && s[i] != '_')
//            {
//                flag = 0;
//                break;
//            }
//        }
//        if(flag) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//    int t; cin >> t;
//    while(t --){
//        int a[10];
//        for(int i = 0;i < 10;i ++)cin >> a[i];
//        int n;cin >> n;
//        int flag = 0;
//        int index;
//        for(int i = 0;i < 10;i ++){
//            if(a[i] == n){
//                index = i;
//                flag = 1;
//                break;
//            }
//        }
//        if(flag) cout << index << endl;
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
//    int t; cin >> t;
//    while(t --){
//        int a[10];int ans =0;
//        for(int i = 0;i < 10;i ++){
//            cin >> a[i];
//            if(a[i] < 0) ans ++;
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}
//
//#include<iostream>
//#include<map>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e3 + 10;
//int cntr[N],cntc[N];
//struct node
//{
//    int num,pos;
//}r[N],c[N];
//bool cmp1(node a,node b)
//{
//    return a.num > b.num;
//}
//bool cmp2(node a,node b)
//{
//    return a.pos < b.pos;
//}
//int main()
//{
//    int m,n,k,l,d;
//    cin >> m >> n >> k >> l >> d;
//    while(d --){
//        int x,y,p,q;
//        cin >> x >> y >> p >> q;
//        if(x == p) cntc[min(y,q)] ++;
//        if(y == q) cntr[min(x,p)] ++;
//    }
//
//    for(int i = 1;i <= m;i ++){
//        r[i].num = cntr[i];
//        r[i].pos = i;
//    }
//    for(int i = 1;i <= n;i ++){
//        c[i].num = cntc[i];
//        c[i].pos = i;
//    }
//
//    sort(r + 1,r + m + 1, cmp1);
//    sort(c + 1,c + n + 1, cmp1);
//    sort(r + 1,r + k + 1, cmp2);
//    sort(c + 1,c + l + 1, cmp2);
//
//    for(int i = 1;i <= k;i ++){
//        cout << r[i].pos;
//        if(i < k) cout << " ";
//    }
//    cout << endl;
//    for(int i = 1;i <= l;i ++){
//        cout << c[i].pos;
//        if(i < l) cout << " ";
//    }
//    cout << endl;
//    return 0;
//}
//#include<iostream>
//
//using namespace std;
//
//int f(int cur,int dest,int peo,int d_peo,int x)
//{
//    if(cur == dest){
//
//    }
//
//}
//
//int main()
//{
//    int a,n,m,x;
//    cin >> a >> n >> m >> x;
//    int tmp = f(1,n,5,5,32,1);
//    return 0;
//}
//

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//    int n;
//    while(cin >> n){
//        int a[110];
//        for(int i = 0;i < n;i ++){
//            cin >> a[i];
//        }
//        if(n == 1){
//            cout << "YES" << endl;
//            continue;
//        }
//        int ok = 1,le = 0;
//        for(int i = 0;i < n - 1;i ++){
//            if(a[i] < a[i + 1]){
//                if(le == 2 || le == 3){
//                    ok = 0;
//                    break;
//                }
//                le = 1;
//            }
//            if(a[i] == a[i + 1]){
//                if(le == 3){
//                    ok = 0;
//                    break;
//                }
//                le = 2;
//            }
//            if(a[i] > a[i + 1])le = 3;
//        }
//        if(ok) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int add(int a,int n,int y)
//{
//    if(n == 1)return a;
//    else if(n == 2)return 0;
//    else if(n == 3)return a;
//    else if(n == 4)return y;
//    else if(n >= 5) return (add(a,n - 1, y) + add(a,n - 2, y));
//}
//int main()
//{
//    int a,n,m,x;
//    int sum = 0;
//    cin >> a >> n >> m >> x;
//    int y;
//    for(y = 1;;y ++){
//        sum = 0;
//        for(int i = 1;i < n;i ++){
//            sum +=add(a,i,y);
//        }
//        if(sum == m)break;
//    }
//    sum = 0;
//    for(int i = 1;i <= x;i ++)sum += add(a,i,y);
//    cout << sum << endl;
//    return 0;
//}

//
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<cmath>
//
//using namespace std;
//
//double strToDouble(char str[])
//{
//    if(strcmp(str,"") == 0) return 0;
//    double ans = 0.0, ans_p = 0.0;int flag = 1;
//    if(str[0] == '-')flag = -1;
//    int point = 0;int k = 1;
//    for(int i = 0;i < strlen(str);i ++){
//        if(str[i] == '.') point = 1;
//        if(isdigit(str[i]) && !point) ans = ans * 10 + str[i] - '0';
//        if(isdigit(str[i]) && point) ans_p += pow(0.1,k ++) * (str[i] - '0');
//    }
//    return (ans + ans_p)* flag;
//}
//
//int main()
//{
//    char s[20];
//    while(gets(s)){
//        printf("%.6g\n",strToDouble(s));
//    }
//    return 0;
//}
//#include<iostream>
//
//using namespace std;
//
//bool f(int n)
//{
//    if(n < 10) return true;
//    int a = 0;
//    int tmp = n;
//    while(tmp)
//    {
//        a = a * 10 + tmp % 10;
//        tmp /= 10;
//    }
//    if(a == n)return true;
//    else return false;
//}
//
//int main()
//{
//    int t; cin >> t;
//    while(t --){
//        int n;cin >> n;
//        if(f(n))cout << "Yes" << endl;
//        else cout << "No" << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//long long f(int n)
//{
//    long long sum = 1;
//    for(int i = 1;i <= n;i ++)sum *= i;
//    return sum;
//}
//
//int main()
//{
//    int n; cin >> n;
//    long long ans = 0;
//    for(int i = 1;i <= n;i ++){
//        ans += f(i);
//    }
//    cout << ans << endl;
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//char l[] = {'1','0','X','9','8','7','6','5','4','3','2'};
//int a[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
//int main()
//{
//    int t; cin >> t;
//    while(t --){
//        string s;
//        cin >> s;
//        s = s.substr(0,6) + "19" + s.substr(6);
//        int sum = 0;
//        for(int i = 0;i < s.size();i ++){
//            sum += a[i] * (s[i] - '0');
//        }
//        s += l[sum % 11];
//        cout << s << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//
//using namespace std;
//const int N = 1e3 + 10;
//int stx,sty;
//int a[N][N];
//bool vis[N][N];
//int n,m,ans;
//int dir[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
//
//bool judge(int x,int y){
//    if(x <= 0 || y <= 0 || x > n || y > n || vis[x][y])return false;
//    return true;
//}
//void dfs(int x,int y)
//{
//    ans ++;
//    vis[x][y] = 1;
//    for(int i = 0;i < 4;i ++){
//        int tx = x + dir[i][0];
//        int ty = y + dir[i][1];
//        if(judge(tx,ty) && a[x][y] != a[tx][ty]){
//            dfs(tx,ty);
//        }
//    }
//}
//
//int main(){
//    cin >> n >> m;
//    for(int i = 1;i <= n;i ++)
//        for(int j = 1;j <= n; j++)
//            cin >> a[i][j];
//    while(m --){
//        ans = 0;
//        memset(vis,0,sizeof(vis));
//        int x,y;cin >> x >> y;
//        stx = x,sty = y;
//        dfs(stx,sty);
//        cout << ans << endl;
//    }
//    return 0;
//}
#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
const int N = 200 + 5;
int vis[N][N],cap[3],ans[N];

struct node{
    int v[3],dist;
    bool operator < (const node& b) const {
        return dist > b.dist;
    }
};

void update_ans(const node& u){
    for(int i = 0;i < 3;i ++){
        int d = u.v[i];
        if(ans[d] < 0 || u.dist < ans[d]) ans[d] = u.dist;
    }
}

void bfs(int a,int b,int c,int d)
{
    cap[0] = a,cap[1] = b,cap[2] = c;
    memset(vis,0,sizeof(vis));
    memset(ans,-1,sizeof(ans));
    priority_queue<node> q;

    node cur;
    cur.dist = 0;
    cur.v[0] = 0,cur.v[1] = 0,cur.v[2] = c;
    q.push(cur);

    vis[0][0] = 1;
    while(!q.empty()){
        node u = q.top();q.pop();
        update_ans(u);
        if(ans[d] >= 0)break;
        for(int i = 0;i < 3;i ++){
            for(int j = 0;j < 3;j ++){
                if(i != j){
                    if(u.v[i] == 0 || u.v[j] == cap[j]) continue;
                    int amount = min(cap[j],u.v[i] + u.v[j])- u.v[j];
                    node u2;memcpy(&u2,&u,sizeof(u));
                    u2.dist = u.dist + amount;
                    u2.v[i] -= amount;
                    u2.v[j] += amount;
                    if(!vis[u2.v[0]][u2.v[1]]){
                        vis[u2.v[0]][u2.v[1]] = 1;
                        q.push(u2);
                    }
                }
            }
        }

    }while(d >= 0){
            if(ans[d] >= 0){
                cout << ans[d] << " " << d << endl;
                return;
            }
            d --;
        }
}

int main()
{
    int t; cin >> t;
    while(t --){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        bfs(a,b,c,d);
    }
    return 0;
}














