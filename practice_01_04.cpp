//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<sstream>
//#include<algorithm>
//
//using namespace std;
//
//bool cmp(double a,double b){
//    return a > b;
//}
//
//int main()
//{
//    string s = "",st;
//    while(getline(cin,st))
//        s += st;
//
//    for(int i = 0;i < s.size();i ++){
//        if(!isdigit(s[i]) && s[i] != '.') s[i] = ' ';
//    }
//
//    stringstream ss(s);
//    double a[100];
//    int cnt = 0;
//    while(ss >> st){
//        if(st[st.size() - 1] == '.')st = st.substr(0,st.size() - 1);
//        a[cnt ++] = atof(st.c_str());
//    }
//
//    sort(a,a + cnt,cmp);
//
//    for(int i = 0;i < cnt; i++){
//        if(i) printf(" ");
//        printf("%.2lf",a[i]);
//    }
//    return 0;
//}


//#include<iostream>
//
//using namespace std;
//
//int f(int a[],int b[],int n)
//{
//    int ans = 0;
//    for(int i = 0;i < n;i ++){
//        ans += a[i] * b[i];
//    }
//    return ans;
//}
//int main()
//{
//    int n;
//    cin >> n;
//    int a[1010],b[1010];
//    for(int i = 0;i < n;i ++) cin >> a[i];
//    for(int i = 0;i < n;i ++) cin >> b[i];
//    cout << f(a,b,n) << endl;
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//    int t;cin >> t;
//    while(t --){
//        int f[50];
//        f[1] = f[2] = 1;
//        int n;cin >> n;
//        for(int i = 3;i <= n;i ++){
//            f[i] = f[i - 1] + f[i - 2];
//        }
//        cout << f[n] << endl;
//    }
//    return 0;
//}
//
//#include<iostream>
//#include<map>
//#include<set>
//#include<algorithm>
//using namespace std;
//struct Node
//{
//    int pos,num;
//    bool operator < (const Node& b)const {
//        return num > b.num;
//    }
//}node[110];
//
//int main()
//{
//    string s;
//    map<string,int> ma;
//    map<int,string> mp;
//    int num[110];
//    set<string> _set;
//    int cnt = 0;
//    while(cin >> s && s[0] != '0'){
//        if(!_set.count(s)){
//            num[cnt] = 1;
//            ma[s] = cnt;
//            mp[cnt++] = s;
//            _set.insert(s);
//        }
//        else{
//            num[ma[s]] ++;
//        }
//    }
//    for(int i = 0;i < cnt;i ++){
//        node[i].num = num[i];
//        node[i].pos = i;
//    }
//    sort(node,node + cnt);
//
//    for(int i = 0;i < cnt; i++){
//        cout << node[i].num << " " << mp[node[i].pos] << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//
//using namespace std;
//int f(char* a,char* b,int n)
//{
//    int ans = 0;
//    for(int i = 0;i < n;i ++){
//        if(*(a + i) == *b){
//            char* p1 = a + i;
//            char* p2 = b;
//            while(*p2 != '\0'){
//                if(*p1 != *p2)break;
//                p1 ++;
//                p2 ++;
//            }
//            if(*p2 == '\0')ans ++;
//        }
//    }
//    return ans;
//}
//
//int main()
//{
//    char a[25],b[25];
//    cin >> a >> b;
//    cout << f(a,b,strlen(a)) << endl;
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<sstream>
//
//using namespace std;
//
//int main()
//{
//    string a,b;
//    cin >> a;getchar();
//    getline(cin,b);
//    for(int i = 0;i < a.size();i ++) a[i] = tolower(a[i]);
//    for(int i = 0;i < b.size();i ++)
//        if(isalpha(b[i])) b[i] = tolower(b[i]);
//
//    int ans = 0;
//    stringstream ss(b);
//    string st;
//    int flag = 0;int len = 0;int pos;
//    while(ss >> st){
//        if(st == a)ans ++;
//        if(st == a && !flag){
//            pos = len;
//            flag = 1;
//        }
//        len += st.size();
//    }
//    if(ans) cout << ans << " " << pos;
//    else cout << -1 << endl;
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//using namespace std;
//
//int f1(char s[],int n){
//    int ans = 0;
//    for(int i = 0;i < n - 1;i ++){
//        if(s[i] > s[i + 1]) ans ++;
//    }
//    return ans;
//}
//
//void f2(char s[],int n){
//    for(int i = 0;i < n - 1;i ++){
//        if(s[i] > s[i + 1]) cout << s[i] << " " << s[i + 1] << endl;
//    }
//}
//int main()
//{
//    char s[30];
//    int t; cin >> t;
//    while(t -- ){
//        cin >> s;
//        cout << f1(s,strlen(s)) << endl;
//        f2(s,strlen(s));
//    }
//    return 0;
//}
//
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<sstream>
//
//using namespace std;
//
//int main()
//{
//    string s,st;string a[10];
//    int t; cin >> t;
//    while(t --){
//        cin >> s;
//        for(int i = 0;i < s.size();i ++){
//            if(s[i] == ':') s[i] = ' ';
//        }
//        stringstream ss(s);
//        for(int i = 0;i < 8;i ++)ss >> a[i];
//        for(int i = 0;i < 8;i ++){
//            string stt = "";int flag = 0;
//            for(int j = 0;j < a[i].size() - 1;j ++){
//                if(a[i][j] == '0' && !flag)continue;
//                else{
//                    stt += a[i][j];
//                    flag = 1;
//                }
//            }
//            stt += a[i][a[i].size() - 1];
//            a[i] = stt;
//        }
//
////        for(int i = 0;i < 8;i ++ ) cout << a[i] << endl;
//        int flag = 0;
//        string stt =  "";
//        for(int i = 0;i < 8;){
//            if(a[i] == "0" && !flag){
//                if(i == 0) stt += ":";
//                flag = 1;
//                while(a[++i] == "0");
//                stt += ":";
//                continue;
//            }
//            stt += a[i];
//            if(i < 7) stt += ":";
//            i ++;
//        }
//        cout << stt << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//int a[10][10];
//
//bool check(int x,int y,int n)
//{
//    for(int i = 0;i < 9;i ++){
//        if(a[x][i] == n)return false;
//        if(a[i][y] == n)return false;
//    }
//
//    int a0 = x / 3 * 3;
//    int b = a0 + 3;
//    int c = y / 3 * 3;
//    int d = c + 3;
//    for(int i = a0;i < b;i++){
//        for(int j = c;j < d;j ++){
//            if(a[i][j] == n)return false;
//        }
//    }
//    return true;
//}
//
//void dfs(int x,int y){
//    if(x > 8){
//        for(int i = 0;i < 9;i ++){
//            for(int j = 0;j < 9;j ++){
//                cout << a[i][j];
//                if(j < 8) cout << " ";
//            }
//            cout << endl;
//        }
//        return ;
//    }
//
//    if(a[x][y])dfs(x + (y + 1) / 9,(y + 1) % 9);
//    else{
//        for(int i = 1;i <= 9;i ++){
//            if(check(x,y,i)){
//                a[x][y] = i;
//                dfs(x+(y + 1) / 9,(y + 1) % 9);
//                a[x][y] = 0;
//            }
//        }
//    }
//}
//int main()
//{
//    for(int i = 0;i < 9;i ++)
//        for(int j = 0;j < 9;j ++)
//            cin >> a[i][j];
//
//    dfs(0,0);
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<queue>
//#include<vector>
//
//using namespace std;
//const int N = 1e3 + 10;
//const int inf = 0x3f3f3f3f;
//int n,m;
//struct edge{
//    int v,w;
//};
//struct node
//{
//    int d,s;
//    bool operator < (const node& b)const {
//        return d > b.d;
//    }
//};
//int d[N];
//vector<edge> g[N];
//
//void dijkstra(int s)
//{
//    priority_queue<node> q;
//    for(int i = 0 ;i <= m;i ++)d[i] = inf;
//    d[s] = 0;
//    q.push((node){0,s});
//    while(!q.empty()){
//        node x = q.top();
//        q.pop();
//        int u = x.s;
//        if(d[u] < x.d)continue;
//        for(int i = 0;i < g[u].size();i ++){
//            int v = g[u][i].v;
//            int w = g[u][i].w;
//            if(d[v] > d[u] + w){
//                d[v] = d[u] + w;
//                q.push((node){d[v],v});
//            }
//        }
//    }
//}
//int main()
//{
//    while(cin >> n >> m){
//        for(int i = 0;i < n;i ++){
//            int u,v,w;
//            cin >> u >> v >> w;
//            g[u].push_back(edge{v,w});
//            g[v].push_back(edge{u,w});
//        }
//        dijkstra(m);
//
//        cout << d[1] << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//
//using namespace std;
//
//int main()
//{
//    int t;cin >> t;
//    while(t --){
//        int a[50],n;
//        cin >> n;
//        for(int i = 0;i < n;i ++) cin >> a[i];
//        double sum = 0;
//        for(int i = 0;i < n;i ++) sum += a[i];
//        printf("%.2lf ",sum / n);
//        int cntmin = 0,cntmax = 0;
//        for(int i = 0;i < n;i ++){
//            if(a[i] > (sum / n))cntmax ++;
//            if(a[i] < (sum / n))cntmin ++;
//        }
//        cout << cntmax << " " << cntmin << endl;
//        int cntz = 0,cntf = 0;
//        for(int i = 0;i < n;i ++){
//            if(a[i] > 0) cntz ++;
//            if(a[i] < 0) cntf ++;
//        }
//        cout << cntz << " " << cntf << endl;
//        int minn = a[0],maxn = a[0];
//        for(int i = 0;i < n;i ++){
//            minn = min(a[i],minn);
//            maxn = max(a[i],maxn);
//        }
//        cout << "max=" << maxn << " " << "min=" << minn << endl;
//        cout << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//void reset(char str[],char result[])
//{
//    int i = 0;int k = 0;
//    while(str[i] != '\0'){
//        if(isalpha(str[i]))result[k++] = str[i];
//        i ++;
//    }
//    result[k] = '\0';
//    sort(result,result + k);
//}
//
//int main()
//{
//    char a[110],b[110];
//    gets(a);
//    reset(a,b);
//    cout << b << endl;
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 55;
//string a[N];
//bool cmp(string a,string b)
//{
//    if(a.size() == b.size())
//    return a > b;
//    return a.size() < b.size();
//}
//int main()
//{
//    int n;cin >> n;
//    for(int i = 0;i < n;i ++)cin >> a[i];
//    sort(a,a + n,cmp);
//    for(int i = 0;i < n;i ++) cout << a[i] << endl;
//    return 0;
//}

//#include<iostream>
//#include<vector>
//#include<cstring>
//
//using namespace std;
//const int N = 1e5 + 10;
//bool vis[N];int n,k,a[110];
//vector<int> num;int flag;
//void dfs(int cur,int sum,int k)
//{
//    if(sum == k){
//        cout << "YES" << endl;
//        for(int i = 0;i < num.size();i ++){
//            if(i) cout << " ";
//            cout << num[i];
//        }
//        cout << endl;
//        flag = 1;
//        return ;
//    }
//    if(sum > k) return;
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
//        memset(vis,0,sizeof(vis));
//        num.clear();flag = 0;
//        dfs(0,0,k);
//        if(!flag) cout << "NO" << endl;
//    }
//    return 0;
//}
//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//    int n,k;
//    while(cin >> n >> k){
//        int a[100];
//        vector<int> num;
//        int flag = 0;
//        for(int i = 0;i < n;i ++)cin >> a[i];
//        for(int s = 0;s < (1 << n);s ++){
//            int sum = 0;num.clear();
//            for(int i = 0;i < n;i ++){
//                if((s >> i) & 1){
//                    sum += a[i];
//                    num.push_back(a[i]);
//                }
//            }
//            if(sum == k){
//                cout << "YES" << endl;
//                flag = 1;
//                for(int i = 0;i < num.size();i ++){
//                    if(i) cout << " ";
//                    cout << num[i];
//                }
//                cout << endl;
//                break;
//            }
//        }
//        if(!flag ) cout << "NO" << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//
//using namespace std;
//
//int main()
//{
//    long long c[2];
//    char s[31];
//    int i, k, len;
//    int cnt = 0;
//    cin >> s;
//    len = strlen(s);
//    c[0] = c[1] = 0;
//    for(int i = 0;i < len - 15;i ++){
//        c[0] = 10 * c[0] + s[i] - '0';
//    }
//    for(int i = len - 15;i < len;i ++){
//        if(i >= 0)
//        c[1] = 10 * c[1] + s[i] - '0';
//    }
//
//    for(int k = 2;k <= 9;k ++){
//        long long tmp = 0;
//        tmp = (c[0] % k) * 1e15 + c[1];
//        if(tmp % k == 0){
//            cnt ++;
//            if(cnt > 1)cout << " ";
//            cout << k;
//        }
//    }
//    cout << endl;
//    if(!cnt)cout << "none" << endl;
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//    int i = 2;
//    while(n > 1){
//        if(n % i == 0){
//            cout << i << " ";
//            n /= i;
//        }
//        else i ++;
//    }
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int main()
//{
//    int t;cin >> t;
//    while(t --){
//        char c;cin >> c;
//        string s; cin >> s;
//        c = tolower(c);
//        int ans = 0;
//        for(int i = 0;i < s.size();i ++){
//            s[i] = tolower(s[i]);
//            if(s[i] == c)ans ++;
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//    cout << "####" << endl;
//    cout << " ####" << endl;
//    cout << "  ####" << endl;
//    cout << "   ####" << endl;
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//using namespace std;
//int l[] = {31,28,31,30,31,30,31,31,30,31,30,31};
//int main()
//{
//    int t,y,m,d;cin >> t;
//    while(t --){
//        scanf("%d/%d/%d",&y,&m,&d);
//        int ans = 0;
//        for(int i = 0;i < m - 1;i ++)ans += l[i];
//        if((y % 4 == 0 && y % 100 != 0 || y % 400 == 0) && m > 2)ans ++;
//        ans += d;
//        cout << ans << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<queue>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 110;
//int n,m,sx,sy,ex,ey;
//bool vis[N][N];
//int a[N][N];
//struct node
//{
//    int x,y,step,dir,turn;
//};
//int dir[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
//
//bool judge(int x,int y)
//{
//    if(x == ex && y == ey)return true;
//    if(x < 0 || y < 0 || x >= n || y >= m || vis[x][y])return false;
//    if(a[x][y])return false;
//    return true;
//}
//
//int bfs()
//{
//    node cur,next;
//    queue<node> q;
//    cur.x = sx,cur.y = sy,cur.step = 1;
//    cur.turn = 0;cur.dir = -1;
//    vis[cur.x][cur.y] = 1;
//    q.push(cur);
//    while(!q.empty()){
//        cur = q.front();q.pop();
//        if(cur.x == ex && cur.y == ey && cur.turn <= 2){
//            return cur.step;
//        }
//        for(int i = 0;i < 4;i ++){
//            next.x = cur.x + dir[i][0];
//            next.y = cur.y + dir[i][1];
//            next.dir = i;
//            if(judge(next.x,next.y)){
//                vis[next.x][next.y] = 1;
//                if(next.dir != cur.dir && cur.dir != -1)next.turn = cur.turn + 1;
//                else next.turn = cur.turn;
//                next.step = cur.step + 1;
////                cout << next.x << " " << next.y << endl;
////                cout << next.dir << " " << next.turn << endl;
//                q.push(next);
//            }
//        }
//    }
//    return -1;
//}
//int main()
//{
//    while(cin >> n >> m){
//        memset(vis,0,sizeof(vis));
//        for(int i = 0;i < n;i ++){
//            for(int j = 0;j < m;j ++){
//                cin >> a[i][j];
//            }
//        }
//        cin >> sx >> sy >> ex >> ey;
//        if(a[sx][sy] != a[ex][ey]){
//            cout << -1 << endl;
//            continue;
//        }
//        cout << bfs() << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//#include<vector>
//#include<cstdio>
//#include<cmath>
//
//using namespace std;
//const int N = 2e3 + 10;
//int n;
//struct edge
//{
//    int v;
//    double w;
//};
//vector<edge> e[N];
//pair<double,double> point[N];
//
//double dis(int a,int b,int c,int d)
//{
//    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
//}
//struct node
//{
//    double d;
//    int s;
//    bool operator < (const node& b)const {
//        return d > b.d;
//    }
//};
//double d[N];
//void dijkstra(int s)
//{
//    memset(d,0x3f,sizeof(d));
//    priority_queue<node> q;
//    d[s] = 0;
//    q.push((node){0,s});
//    while(!q.empty()){
//        node x = q.top();q.pop();
//        int u = x.s;
//        if(d[u] < x.d) continue;
//        for(int i = 0;i < e[u].size();i ++){
//            int v = e[u][i].v;
//            int w = e[u][i].w;
//            if(d[v] > d[u] + w){
//                d[v] = d[u] + w;
//                q.push((node){d[v],v});
//            }
//        }
//    }
//}
//int main()
//{
//    int kase = 0;
//    while(cin >> n && n){
//        for(int i = 1;i <= n;i ++){
//            cin >> point[i].first >> point[i].second;
//        }
//        for(int i = 1;i <= n;i ++){
//            for(int j = 1;j <= n;j ++){
//                if(i != j){
//                    e[i].push_back((edge){j,dis(point[i].first,point[i].second,point[j].first,point[j].second)});
//                }
//            }
//        }
////        for(int i = 1;i <= n;i ++){
////            cout << i << ": " << endl;
////            for(int j = 0;j < e[i].size();j++){
////                cout << e[i][j].v << " " << e[i][j].w << endl;
////            }
////        }
//        dijkstra(1);
//        if(kase) puts("");
//        printf("Scenario #%d\n",++kase);
//        printf("Frog Distance = %.3lf\n",d[2]);
//    }
//    return 0;
//}

//#include<iostream>
//#include<cmath>
//#include<cstdio>
//
//using namespace std;
//const int N = 210;
//int n;
//double p[N][N];
//pair<double,double> point[N];
//
//void floyd()
//{
//    for(int k = 1;k <= n;k ++){
//        for(int i = 1;i <= n;i ++){
//            for(int j = 1;j <= n;j ++){
//                p[i][j] = min(p[i][j],max(p[i][k],p[k][j]));
//            }
//        }
//    }
//}
//
//int main(){
//    int kase = 0;
//    while(cin >> n && n){
//        for(int i = 1;i <= n;i ++)cin >> point[i].first >> point[i].second;
//
//        for(int i = 1;i <= n - 1;i ++){
//            for(int j = i + 1;j <= n;j ++){
//                double x = point[i].first - point[j].first;
//                double y = point[i].second - point[j].second;
//                p[i][j] = p[j][i] = sqrt(x * x + y * y);
//            }
//        }
//        floyd();
//        cout << "Scenario #" << ++kase << endl;
//        printf("Frog Distance = %.3lf\n",p[1][2]);
//        puts("");
//    }
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//
//using namespace std;
//const int N = 1010;
//int n,m,f[N][N];
//
//void floyd()
//{
//    for(int k = 1;k <= n;k ++)
//        for(int i = 1;i <= n;i ++)
//            for(int j = 1;j <= n;j ++)
//                f[i][j] = max(f[i][j],min(f[i][k],f[k][j]));
//}
//
//int main()
//{
//    int t;cin >> t;
//    int kase = 0;
//    while(t --){
//        cin >> n >> m;
//        for(int i = 0;i < m;i ++){
//            int u,v,w;
//            cin >> u >> v >> w;
//            f[u][v] = f[v][u] = w;
//        }
//        floyd();
//        printf("Scenario #%d:\n%d\n\n",++kase,f[1][n]);
//    }
//    return 0;
//}

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1010;
int g[N][N];int d[N];
int vis[N];
int n,m;

int dij()
{
    memset(vis,0,sizeof(vis));
    vis[1] = 1;
    for(int i = 1;i <= n;i ++){
        d[i] = g[1][i];
    }
    for(int i = 1;i < n;i ++){
        int mm = 0, k = 0;
        for(int j = 1;j <= n;j ++){
            if(!vis[j] && d[j] > mm){
                mm = d[j];k = j;
            }
        }
        vis[k] = 1;
        for(int j = 1;j <= n;j ++){
            if(d[j] < min(d[k],g[k][j])){
                d[j] = min(d[k],g[k][j]);
            }
        }
    }
    return d[n];
}

int main()
{
    int t;cin >> t;
    int kase = 0;
    while(t --){
        cin >> n >> m;
        memset(g,0,sizeof(g));
        for(int i = 0;i < m;i ++){
            int u,v,w;cin >> u >> v >> w;
            g[u][v] = g[v][u] = max(g[u][v],w);
        }
        printf("Scenario #%d\n%d\n\n",++kase,dij());
    }
    return 0;
}








