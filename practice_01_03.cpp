//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cmath>
//
//using namespace std;
//const int N = 500 + 10;
//int fa[N],n,cnt,m;
//struct node
//{
//    double x,y;
//}s[N];
//struct S
//{
//    int u,v;
//    double d;
//}e[N * N];
//
//int cmp(S a,S b){
//    return a.d < b.d;
//}
//
//int getf(int x)
//{
//    return x == fa[x] ? x : fa[x] = getf(fa[x]);
//}
//
//double kruskal()
//{
//    for(int i = 1;i <= n;i ++)fa[i] = i;
//    sort(e,e + cnt,cmp);
//    int ans = 0;
//    double sum;
//    for(int i = 0;i < cnt;i ++){
//        int fu = getf(e[i].u);
//        int fv = getf(e[i].v);
//        if(fu != fv){
//            ans ++;
//            fa[fu] = fv;
//            if(ans == n - m){
//                sum = e[i].d;
//                break;
//            }
//        }
//    }
//    return sum;
//}
//
//double dis(double a1,double b1,double a2,double b2){
//    return sqrt((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2));
//}
//
//int main()
//{
//    int t;cin >> t;
//    while(t --){
//        cin >> m >> n;
//        for(int i = 1;i <= n;i ++)cin >> s[i].x >> s[i].y;
//        cnt = 0;
//        for(int i = 1;i < n;i ++){
//            for(int j = i + 1;j <= n;j ++){
//                e[cnt].d = dis(s[i].x,s[i].y,s[j].x,s[j].y);
//                e[cnt].u = i;e[cnt].v = j;
//                cnt ++;
//            }
//        }
//        printf("%.2lf\n",kruskal());
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cmath>
//#include<vector>
//
//using namespace std;
//const int N = 750 + 5;
//int n,m,fa[N],cnt;
//pair<double,double> p[N];
//vector<pair<int,int> > poi;
//struct edge
//{
//    int u,v;
//    double w;
//    bool operator < (const edge& b) const {
//        return w < b.w;
//    }
//}e[N * N];
//
//int getf(int x)
//{
//    return x == fa[x] ? x : fa[x] = getf(fa[x]);
//}
//
//double dis(double a,double b,double c,double d)
//{
//    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
//}
//
//void kruskal()
//{
//    sort(e,e + cnt);
//    for(int i = 0;i < cnt;i ++){
//        int fu = getf(e[i].u);
//        int fv = getf(e[i].v);
//        if(fu != fv){
//            fa[fu] = fv;
//            poi.push_back(make_pair(e[i].u,e[i].v));
//        }
//    }
//}
//
//int main()
//{
//    cin >> n;
//    for(int i = 1;i <= n;i ++)cin >> p[i].first >> p[i].second;
//    for(int i = 1;i <= n;i ++)fa[i] = i;
//    cin >> m;
//    for(int i = 0;i < m;i ++){
//        int u,v; cin >> u >> v;
//        int fu = getf(u);
//        int fv = getf(v);
//        if(fu != fv)fa[fu] = fv;
//    }
//
//    for(int i = 1;i < n;i ++){
//        for(int j = i + 1;j <= n;j ++){
//            e[cnt].u = i,e[cnt].v = j;
//            e[cnt ++].w = dis(p[i].first,p[i].second,p[j].first,p[j].second);
//        }
//    }
//
//    kruskal();
//
//    if(poi.empty()) puts("");
//    for(int i = 0;i < poi.size();i ++){
//        cout << poi[i].first << " " << poi[i].second << endl;
//    }
//
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//const int N = 110;
//int n,fa[N],cnt,g[N][N];
//
//struct edge
//{
//    int u,v,w;
//    bool operator < (const edge& b)const{
//        return w < b.w;
//    }
//}e[N * N];
//int getf(int x)
//{
//    return x == fa[x] ? x : fa[x] = getf(fa[x]);
//}
//
//int kruskal()
//{
//    int ans = 0;
//    for(int i = 1;i <= n;i ++)fa[i] = i;
//    sort(e,e + cnt);
//
//    for(int i = 0;i < cnt;i ++){
//        int fu = getf(e[i].u);
//        int fv = getf(e[i].v);
//        if(fu != fv){
//            fa[fu] = fv;
//            ans += e[i].w;
//        }
//    }
//    return ans;
//}
//
//int main()
//{
//    while(cin >> n){
//        cnt = 0 ;
//        for(int i = 1;i <= n;i ++){
//            for(int j = 1;j <= n;j ++){
//                cin >> g[i][j];
//            }
//        }
//
//        for(int i = 1;i <= n;i ++){
//            for(int j = i + 1;j <= n;j ++){
//                e[cnt].u = i;
//                e[cnt].v = j;
//                e[cnt ++].w = g[i][j];
//            }
//        }
//
//        cout << kruskal() << endl;
//
//    }
//
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 110;
//int n,m,fa[N],cnt;
//struct edge
//{
//    int u,v,w;
//    bool operator < (const edge& b) const {
//        return w < b.w;
//    }
//}e[N * N];
//
//int getf(int x)
//{
//    return x == fa[x] ? x : fa[x] = getf(fa[x]);
//}
//bool book[N * N];
//int kruskal(int jump)
//{
//    int ans = 0;
//    for(int i = 1;i <= n;i ++)fa[i] = i;
//    sort(e,e + cnt);
//
//    for(int i = 0;i < cnt;i ++){
//        if(i == jump)continue;
//        int fu = getf(e[i].u);
//        int fv = getf(e[i].v);
//        if(fu != fv){
//            fa[fu] = fv;
//            ans += e[i].w;
//            if(jump == -1)book[i] = 1;
//        }
//    }
//    for(int i = 1;i < n;i ++){
//        if(getf(i) != getf(i + 1)){
//            ans = -1;break;
//        }
//    }
//    return ans;
//}
//
//int main()
//{
//    int t;cin >> t;
//    while(t --){
//        memset(book,0,sizeof(book));
//        cnt = 0;
//        cin >> n >> m;
//        for(int i = 0;i < m;i ++){
//            int u,v,w;
//            cin >> u >> v >> w;
//            e[cnt].u = u;
//            e[cnt].v = v;
//            e[cnt ++].w = w;
//        }
//
//        int ans = kruskal(-1);
//        for(int i = 0;i < cnt;i ++){
//            if(book[i]){
//                int tp = kruskal(i);
//                if(tp == ans){
//                    ans = -1;
//                    break;
//                }
//            }
//        }
//        if(ans == -1) cout << "Not Unique!" << endl;
//        else cout << ans << endl;
//    }
//    return 0;
//}


//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//const int N = 110;
//int n,fa[N],cnt;
//struct edge
//{
//    int u,v,w;
//    bool operator < (const edge& b) const{
//        return w < b.w;
//    }
//}e[N * N];
//
//int getf(int x)
//{
//    return x == fa[x] ? x : fa[x] = getf(fa[x]);
//}
//
//int kruskal()
//{
//    int ans = 0;
//    for(int i = 1;i <= n;i ++)fa[i] = i;
//    sort(e,e + cnt);
//    for(int i = 0;i < cnt;i ++){
//        int fu = getf(e[i].u);
//        int fv = getf(e[i].v);
//        if(fu != fv){
//            fa[fu] = fv;
//            ans += e[i].w;
//        }
//    }
//    return ans;
//}
//
//int main()
//{
//    while(cin >> n && n){
//        cnt = 0;
//        for(int i = 0;i < n * (n - 1) / 2;i ++){
//            int u,v,w;cin >> u >> v >> w;
//            e[cnt].u = u,e[cnt].v = v;
//            e[cnt ++].w = w;
//        }
//        cout << kruskal() << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//const int N = 30;
//int n,fa[N],cnt;
//
//struct edge
//{
//    int u,v,w;
//    bool operator < (const edge& b) const {
//        return w < b.w;
//    }
//}e[80];
//
//int getf(int x)
//{
//    return x == fa[x] ? x : fa[x] = getf(fa[x]);
//}
//
//int kruskal()
//{
//    int ans = 0;
//    for(int i = 1;i <= n;i ++)fa[i] = i;
//    sort(e, e + cnt);
//    for(int i = 0;i < cnt;i ++){
//        int fu = getf(e[i].u);
//        int fv = getf(e[i].v);
//        if(fu != fv){
//            fa[fu] = fv;
//            ans += e[i].w;
//        }
//    }
//    return ans;
//}
//
//int main()
//{
//    while(cin >> n && n){
//        cnt = 0;
//        for(int i = 0;i < n - 1;i ++){
//            char u;int m;
//            cin >> u >> m;
//            for(int i = 0;i < m;i ++){
//                char v;int w;
//                cin >> v >> w;
//                e[cnt].u = u - 'A' + 1;
//                e[cnt].v = v - 'A' + 1;
//                e[cnt ++].w = w;
//            }
//        }
//
//        cout << kruskal() << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cmath>
//
//using namespace std;
//const int N = 110;
//int n,fa[N],cnt;
//
//struct edge
//{
//    int u,v;
//    double w;
//    bool operator < (const edge& a){
//        return w < a.w;
//    }
//}e[N * N];
//pair<double,double> p[N];
//
//int getf(int x)
//{
//    return x == fa[x] ? x : fa[x] = getf(fa[x]);
//}
//double dis(double a,double b,double c,double d){
//    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
//}
//
//double kruskal()
//{
//    double ans = 0;
//    for(int i = 1;i <= n;i ++)fa[i] = i;
//    sort(e,e + cnt);
//    for(int i = 0;i < cnt;i ++){
//        int fu = getf(e[i].u);
//        int fv = getf(e[i].v);
//        if(fu != fv && (e[i].w >= 10 && e[i].w <= 1000) ){
//            ans += e[i].w;
//            fa[fu] = fv;
//        }
//    }
//    for(int i = 1;i < n;i ++){
//        if(getf(i) != getf(i + 1)){
//            ans = -1;
//            break;
//        }
//    }
//    return ans;
//}
//
//int main()
//{
//    int t; cin >> t;
//    while(t --){
//        cnt = 0;
//        cin >> n;
//        for(int i = 1;i <= n;i ++)cin >> p[i].first >> p[i].second;
//        for(int i = 1;i < n;i ++){
//            for(int j = i + 1;j <= n;j ++){
//                e[cnt].u = i,e[cnt].v = j;
//                e[cnt ++].w = dis(p[i].first,p[i].second,p[j].first,p[j].second);
//            }
//        }
//
//        double ans = kruskal();
//
//        if(ans == -1) cout << "oh!" << endl;
//        else printf("%.1f\n",ans * 100);
//    }
//    return 0;
//}

//
//#include<iostream>
//#include<cstring>
//#include<cmath>
//#include<cstdlib>
//#include<queue>
//#define INF 0x3f3f3f3f
//
//using namespace std;
//const int N = 55;
//struct node
//{
//    int x,y;
//    int step;
//};
//char m[N][N];
//int r[N * 2],c[N * 2],ans,rear,x,y;
//int edge[N][N],dis[N];
//bool vis[N];
//bool v[N][N];
//int dir[][2] = {{-1,0},{1,0},{0,1},{0,-1}};
//queue<node> q;
//
//void bfs(int i)
//{
//    while(!q.empty())q.pop();
//    node cur,next;
//    int num = 0;
//
//    cur.x = r[i],cur.y = c[i];
//    cur.step = 0;
//    q.push(cur);
//    v[cur.x][cur.y] = 1;
//    while(!q.empty()){
//        cur = q.front();
//        q.pop();
//        for(int k = 0;k < rear;k ++){
//            if(cur.x == r[k] && cur.y == c[k]){
//                edge[k][i] = edge[i][k] = cur.step;
//                num ++;
//                break;
//            }
//        }
//        if(num == rear)break;
//        for(int k = 0;k < 4;k ++){
//            next.x = cur.x + dir[k][0];
//            next.y = cur.y + dir[k][1];
//            next.step = cur.step + 1;
//        }
//
//        if(next.x >= 1 && next.y >= 1 && next.x <= y && next.y <= x && m[next.x][next.y] != '#' && !v[next.x][next.y]){
//            v[next.x][next.y] = 1;
//            q.push(next);
//        }
//    }
//}
//
//void prim()
//{
//    int u = 0;
//    for(int i = 1;i < rear;i ++) dis[i] = edge[u][i];
//    vis[u] = 1;
//    for(int i = 1;i < rear;i ++){
//        int minc = INF;
//        for(int j = 0;j < rear;j ++){
//            if(!vis[j] && dis[j] < minc){
//                u = j;
//                minc = dis[j];
//            }
//        }
//        ans += minc;
//        vis[u] = 1;
//        for(int j = 0;j < rear;j ++){
//            if(!vis[j] && edge[u][j] < dis[j]) dis[j] = edge[u][j];
//        }
//    }
//}
//
//int main()
//{
//    int t,sx,sy;
//    char a[N];
//    cin >> t;
//    while(t --){
//        memset(vis,0,sizeof(vis));
//
//        cin >> x >> y;
//        gets(a);
//        for(int i = 1;i <= y;i ++) gets(m[i] + 1);
//
//        rear = 0;
//        for(int i = 1;i <= y;i ++){
//            for(int j = 1;j <= x;j ++){
//                if(m[i][j] == 'S'){
//                    sx = i;
//                    sy = j;
//                }
//                else if(m[i][j] == 'A'){
//                    r[rear] = i;
//                    c[rear ++] = j;
//                }
//            }
//        }
//        r[rear] = sx;
//        c[rear ++] = sy;
//        for(int i = 0;i < rear;i ++){
//            memset(v,0,sizeof(v));
//            bfs(i);
//        }
//        ans = 0;
//        prim();
//        cout << ans << endl;
//    }
//    return 0;
//}
//

//#include<iostream>
//#include<cstdio>
//using namespace std;
//
//int main()
//{
//    int n,t;
//    double a[1010];
//    cin >> t;int kase = 0;
//    while(t --){
//        cin >> n;
//        for(int i = 1;i <= 6;i ++) cin >> a[i];
//        double sum = 0;
//        for(int i = 1;i <= 6;i ++)sum += a[i] * i;
//        printf("Case #%d: %.4lf\n",++kase,sum * n);
//    }
//    return 0;
//}
//
//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//    int a[10];int sum = 0;int ans = 0;
//    for(int i = 0;i < 10;i ++){
//        cin >> a[i]; sum += a[i];
//    }
//    sum /= 10;
//    for(int i = 0;i < 10;i ++){
//        if(a[i] > sum) ans ++;
//    }
//    cout << ans << endl;
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//using namespace std;
//
//int main()
//{
//    int t;cin >> t;
//    getchar();char a[110];
//    while(t --){
//        gets(a);
//        int flag = 1;
//        if(a[0] != '_' && !isalpha(a[0]))flag = 0;
//        if(strlen(a) > 31) flag = 0;
//        for(int i = 0;i < strlen(a);i ++){
//            if(a[i] != '_' && !isdigit(a[i]) && !isalpha(a[i]))flag = 0;
//        }
//        if(flag) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<set>
//
//using namespace std;
//
//bool judge(int x,int y,int a[][10])
//{
//    set<int> _set;
//    for(int i = x;i < x + 3;i ++){
//        for(int j = y;j < y + 3;j ++){
//            if(_set.count(a[i][j])) return false;
//            else _set.insert(a[i][j]);
//        }
//    }
//    return true;
//}
//
//int main()
//{
//    int t;cin >> t;
//    int a[10][10];
//    while(t --){
//        for(int i = 0;i < 9;i ++){
//            for(int j = 0;j < 9;j ++)
//                cin >> a[i][j];
//        }
//        int flag = 1;
//
//        for(int i = 0;i < 9;i ++){
//            set<int> rset,cset;
//            for(int j = 0;j < 9;j ++){
//                if(!rset.count(a[i][j]))rset.insert(a[i][j]);
//                else{
//                    flag = 0;break;
//                }
//                if(!cset.count(a[j][i]))cset.insert(a[j][i]);
//                else {
//                    flag = 0;break;
//                }
//            }
//        }
//        if(flag == 0){
//            cout << "NO" << endl;
//            continue;
//        }
//        for(int i = 0;i < 3;i ++){
//            for(int j = 0;j < 3;j ++){
//                if(!judge(i * 3,j * 3,a)){
//                    flag = 0;
//                    break;
//                }
//            }
//        }
//        if(flag) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//
//using namespace std;
//struct city
//{
//    string s;
//    double p;
//}a[40],b[40];
//void merge_sort(int l,int r)
//{
//    if(l == r)return;
//    int mid = l + r >> 1;
//    merge_sort(l, mid),merge_sort(mid + 1,r);
//    int i = l,k = l,j = mid + 1;
//    while(i <= mid && j <= r){
//        if(a[i].p > a[j].p){
//            b[k].p = a[i].p;
//            b[k ++].s = a[i ++].s;
//        }
//        else {
//            b[k].p = a[j].p;
//            b[k ++].s = a[j ++].s;
//        }
//    }
//    while(i <= mid){
//        b[k].p = a[i].p;
//        b[k ++].s = a[i++].s;
//    }
//    while(j <= r){
//        b[k].p = a[j].p;
//        b[k ++].s = a[j ++].s;
//    }
//    for(int m = l;m <= r;m ++)a[m] = b[m];
//}
//int main()
//{
//    int n;
//    cin >> n;
//    for(int i = 0;i < n;i ++){
//        getchar();
//        cin >> a[i].s >> a[i].p;
//    }
//
//    merge_sort(0,n-1);
//    for(int i = 0;i < n;i ++){
//        printf("%s %gÍòÈË\n",a[i].s.c_str(),a[i].p);
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<vector>
//#include<map>
//#include<sstream>
//
//using namespace std;
//
//int main()
//{
//    string a;cin >> a;
//    for(int i = 0;i < a.size();i ++) a[i] = tolower(a[i]);
//    getchar();
//    string b;getline(cin,b);
//    for(int i = 0;i < b.size();i ++){
//        if(isalpha(b[i])) b[i] = tolower(b[i]);
//    }
//    vector<string> s;
//    stringstream ss(b);
//    string st;
//    while(ss >> st)
//        s.push_back(st);
//    int ans = 0;int flag = 0;int pos;
//    int len = 0;
//    for(int i = 0;i < s.size();i ++){
//        if(s[i] == a)ans ++;
//        if(s[i] == a && !flag ){
//            pos = len;
//            flag = 1;
//        }
//        len += s[i].size() + 1;
//    }
//    if(ans) cout << ans << " " << pos << endl;
//    else cout << -1 << endl;
//    return 0;
//}
//
//
//#include<iostream>
//#include<cstdio>
//#include<sstream>
//#include<cstring>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//    int t;cin >> t;
//    getchar();
//    while(t --){
//        vector<string> word;
//        string s;
//        getline(cin,s);
//        stringstream ss(s);
//        string st;
//        while(ss >> st){
//            word.push_back(st);
//        }
//        int maxn = 0;
//        for(int i = 0;i < word.size();i ++){
//            maxn = max(maxn,(int)word[i].size());
//        }
//        int cnt = 0;
//        for(int i = 0;i <word.size();i++){
//            if(word[i].size() == maxn){
//                if(cnt ++)cout << " ";
//                cout << word[i];
//            }
//        }
//        cout << endl;
//    }
//    return 0;
//}


//#include<iostream>
//
//using namespace std;
//const int N = 110;
//int n,m;char a[N][N];
//int dir[][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
//
//int main()
//{
//    while(cin >> n >> m){
//        for(int i = 0;i <= n + 1;i ++)
//            for(int j = 0;j <= m + 1;j ++)
//                a[i][j] = '?';
//        for(int i = 1;i <= n;i ++){
//            for(int j = 1;j <= m;j ++){
//                cin >> a[i][j];
//            }
//        }
//        for(int i = 1;i <= n;i ++){
//            for(int j = 1;j <= m;j ++){
//                if(a[i][j] == '*')continue;
//                int num = 0;
//                for(int k = 0;k < 8;k ++){
//                    int x = i + dir[k][0];
//                    int y = j + dir[k][1];
//                    if(a[x][y] == '*')num ++;
//                }
//                a[i][j] = num + '0';
//            }
//        }
//        for(int i = 1;i <= n;i ++){
//            for(int j = 1;j <= m;j ++){
//                cout << a[i][j];
//            }
//            cout << endl;
//        }
//    }
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e3 + 10;
//int n;
//
//struct Rec
//{
//    int num,l,w;
//}rec[N];
//
//bool cmp(Rec a,Rec b)
//{
//    if(a.num == b.num){
//        if(a.l == b.l)return a.w < b.w;
//        return a.l < b.l;
//    }
//    return a.num < b.num;
//}
//
//int main()
//{
//    int t; cin >> t;
//    while(t --){
//        cin >> n;
//        int cnt = 0;
//        while(n -- ){
//            int num,l,w;cin >> num >> l >> w;
//            if(l < w) swap(l,w);
//            int flag = 1;
//            for(int i = 0;i < cnt;i ++){
//                if(rec[i].l == l && rec[i].num == num && rec[i].w == w){
//                    flag = 0;
//                    break;
//                }
//            }
//            if(flag){
//                rec[cnt].num = num;
//                rec[cnt].l = l;
//                rec[cnt ++].w = w;
//            }
//
//        }
//        sort(rec,rec + cnt,cmp);
//            for(int i = 0;i < cnt;i ++)
//                cout << rec[i].num << " " << rec[i].l << " " << rec[i].w << endl;
//    }
//    return 0;
//}

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>

using namespace std;
const int N = 110;
char g[N][N];
int a[N][N];
int n,m;
int dir[][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int cost[N][N];
int t[N][N];

void bfs(int sx,int sy)
{
    memset(t,-1,sizeof(t));
    queue<pair<int,int> > q;
    q.push(make_pair(sx,sy));
    t[sx][sy] = 0;
    while(!q.empty()){
        pair<int,int> u = q.front();
        q.pop();
        if(a[u.first][u.second] != -1){
            cost[a[sx][sy]][a[u.first][u.second]] = t[u.first][u.second];
        }
        for(int i = 0;i < 4;i ++){
            int x = u.first + dir[i][0];
            int y = u.second + dir[i][1];
            if(g[x][y] == '#' || t[x][y] != -1)continue;
            t[x][y] = t[u.first][u.second] + 1;
            q.push(make_pair(x,y));
        }
    }
}
const int inf = 0x3f3f3f3f;
bool vis[N];
int lowc[N];

int prim(int n)
{
    int ans = 0;
    memset(vis,0,sizeof(vis));
    vis[0] = 1;
    for(int i = 1;i < n;i ++)lowc[i] = cost[0][i];
    for(int i = 1;i < n;i ++){
        int minc = inf;
        int p = -1;
        for(int j = 0;j < n;j ++){
            if(!vis[j] && minc > lowc[j]){
                minc = lowc[j];
                p = j;
            }
        }
        if(minc == inf)return -1;
        ans += minc;
        vis[p] = 1;
        for(int j = 0;j < n;j ++){
            if(!vis[j] && lowc[j] > cost[p][j]) lowc[j] = cost[p][j];
        }
    }
    return ans;
}

int main()
{
    int t;cin >> t;
    while(t --){
        cin >> m >> n;
        gets(g[0]);
        int tot = 0;
        for(int i = 0;i < n;i ++)gets(g[i]);
        memset(a,-1,sizeof(a));
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < m;j ++){
                if(g[i][j] == 'S' || g[i][j] == 'A')
                    a[i][j] = tot ++;
            }
        }
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < m;j ++){
                if(a[i][j] != -1)bfs(i,j);
            }
        }
        cout << prim(tot) << endl;
    }
    return 0;
}










