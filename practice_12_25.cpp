//#include<iostream>
//#include<cctype>
//#include<cstring>
//
//using namespace std;
//const int N = 210;
//int n;
//char buf[N][N];
//
//void dfs(int r,int c)
//{
//    printf("%c(",buf[r][c]);
//    if(r + 1 < n && buf[r + 1][c] == '|'){
//        int i = c;
//        while(i - 1 >= 0 && buf[r + 2][i - 1] == '-') i --;
//        while(buf[r + 2][i] == '-' && buf[r + 3][i] != '\0'){
//            if(!isspace(buf[r + 3][i])) dfs(r + 3, i);
//            i ++;
//        }
//    }
//    printf(")");
//}
//
//void solve()
//{
//    n = 0;
//    for(;;){
//        fgets(buf[n],N,stdin);
//        if(buf[n][0] == '#') break;
//        else n ++;
//    }
//    printf("(");
//    if(n){
//        for(int i = 0;i < strlen(buf[0]); i++){
//            if(buf[0][i] != ' '){
//                dfs(0,i);
//                break;
//            }
//        }
//
//    }
//    printf(")\n");
//}
//
//int main()
//{
//    int T;
//    fgets(buf[0],N,stdin);
//    sscanf(buf[0],"%d", &T);
//    while(T--) solve();
//    return 0;
//}
//#include<cstdio>
//#include<algorithm>
//#include<iostream>
//
//using namespace std;
//const int N = 110;
//
//struct building
//{
//    int id;
//    double x,y,w,d,h;
//    bool operator < (const building& b)const{
//        return x < b.x || (y < b.y && x == b.x);
//    }
//}b[N];
//int n;double x[N * 2];
//
//bool cover(int i,double mx)
//{
//    return b[i].x <= mx && b[i].x + b[i].w >= mx;
//}
//
//bool visible(int i,double mx){
//    if(!cover(i,mx)) return false;
//    for(int k = 0;k < n;k ++){
//        if(b[k].y < b[i].y && b[k].h >= b[i].h && cover(k,mx)) return false;
//    }
//    return true;
//}
//
//int main()
//{
//    int kase = 0;
//    while(cin >> n && n){
//        for(int i = 0;i < n;i ++){
//            cin >> b[i].x >> b[i].y >> b[i].w >> b[i].d >> b[i].h;
//            x[i * 2] = b[i].x;x[i * 2 + 1] = b[i].x + b[i].w;
//            b[i].id = i + 1;
//        }
//        sort(b,b + n);
//        sort(x,x + n * 2);
//        int m = unique(x, x + n * 2) - x;
//
//        if(kase ++) cout << endl;
//        printf("For map #%d, the visible buildings are numbered as follows:\n%d",kase,b[0].id);
//        for(int i = 1;i < n;i ++){
//            bool vis = false;
//            for(int j = 0;j < m - 1;j ++){
//                if(visible(i, (x[j] + x[j + 1]) / 2)){
//                    vis = true;
//                    break;
//                }
//            }
//            if(vis) printf(" %d",b[i].id);
//
//        }
//        printf("\n");
//    }
//    return 0;
//}

//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<queue>
//#include<cstring>
//
//using namespace std;
//
//const int maxn = 55,maxp = 1001;//长方体个数最大值，坐标最大值
//int color[maxn * 2][maxn * 2][maxn * 2];//标记
//int x0[maxn], x1[maxn], y0[maxn], y1[maxn], z0[maxn], z1[maxn];//原始数据
//int xs[2 * maxn], ys[2 * maxn], zs[maxn * 2];//离散化数据
//int nx,ny,nz;//记录xs，ys，zs的长度
//int dirt[6][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
//
//void discretize(int a[],int& n)//离散化
//{
//    sort(a,a+n);
//    n = unique(a,a+n) - a;
//}
//
//int getid(int a[],int n,int val)
//{
//    return lower_bound(a, a + n,val) - a;
//}
//
//struct Cell{
//    int x,y,z;
//    Cell(int _x, int _y,int _z) : x(_x),y(_y),z(_z){}
//    bool isValid(){//判断位置是否合法
//        return (0 <= x && x < nx - 1 && 0 <=y && y < ny - 1 && 0 <= z && z < nz - 1);
//    }
//    Cell getNeighbor(int dir){
//        return Cell(x + dirt[dir][0],y + dirt[dir][1],z + dirt[dir][2]);
//    }
//    int getVolume(){
//        return (xs[x + 1] - xs[x]) * (ys[y + 1] - ys[y]) * (zs[z + 1] - zs[z]);
//    }
//    int getArea(int dir){
//        if(dirt[dir][0] != 0)return (ys[y + 1] - ys[y]) * (zs[z + 1] - zs[z]);
//        else if(dirt[dir][1] != 0) return (xs[x + 1] - xs[x]) * (zs[z + 1] - zs[z]);
//        else if(dirt[dir][2] != 0) return (xs[x + 1] - xs[x]) * (ys[y + 1] - ys[y]);
//        return -1;
//    }
//    bool isCopper(){
//        return color[x][y][z] == 1;
//    }
//    bool isVisited(){
//        return color[x][y][z] == 2;
//    }
//    void setVisited(){
//        color[x][y][z] = 2;
//    }
//};
//
//void bfs(int& v,int& m)
//{
//    queue<Cell> q;
//    q.push(Cell(0,0,0));color[0][0][0] = 2;
//    while(!q.empty()){
//        Cell cur = q.front();q.pop();
//        v += cur.getVolume();
//        for(int i = 0;i < 6;i ++){
//            Cell neb = cur.getNeighbor(i);
//            if(neb.isValid()){
//                if(neb.isCopper()) m += cur.getArea(i);
//                else if(!neb.isVisited()){
//                    neb.setVisited();
//                    q.push(neb);
//                }
//            }
//        }
//    }
//    v = (maxp*maxp*maxp) - v;
//}
//
//int main()
//{
//    int T, n, lx, ly, lz;cin >> T;
//    while(T--){
//        cin >> n;
//        xs[0] = 0,ys[0] = 0,zs[0] = 0;
//        xs[1] = maxp,ys[1] = maxp,zs[1] = maxp;
//        nx = ny = nz = 2;
//        for(int i = 0;i < n;i ++){
//            cin >> x0[i] >> y0[i] >> z0[i] >> lx >> ly >> lz;
//            x1[i] = x0[i] + lx,y1[i] = y0[i] + ly, z1[i] = z0[i] + lz;
//            xs[nx++] = x0[i],xs[nx++] = x1[i];
//            ys[ny++] = y0[i],ys[ny++] = y1[i];
//            zs[nz++] = z0[i],zs[nz++] = z1[i];
//        }
//
//        discretize(xs, nx);discretize(ys,ny);discretize(zs,nz);
//        memset(color, 0, sizeof(color));
//        for(int i = 0;i < n;i ++){//标记铜块
//            int X0 = getid(xs,nx,x0[i]),X1 = getid(xs,nx,x1[i]);
//            int Y0 = getid(ys,ny,y0[i]),Y1 = getid(ys,ny,y1[i]);
//            int Z0 = getid(zs,nz,z0[i]),Z1 = getid(zs,nz,z1[i]);
//            for(int x = X0;x < X1;x ++){
//                for(int y = Y0;y < Y1;y ++){
//                    for(int z = Z0;z < Z1;z ++){
//                        color[x][y][z] = 1;
//                    }
//                }
//            }
//        }
//        int v = 0,m = 0;
//        bfs(v, m);
//        printf("%d %d\n", m, v);
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//
//using namespace std;
//vector<set<int> > adj;
//int vis[52];
//
//int getid(char c1,char c2)//构造
//{
//    return (c1 - 'A') * 2 + ((c2 == '+') ? 0 : 1);
//}
//
//void connect(char a1,char a2,char b1,char b2)
//{
//    if(a1 == '0' || b1 == '0') return;
//    adj[getid(a1,a2) ^ 1].insert(getid(b1,b2));
//}
//
//bool dfs(int u )
//{
//    vis[u] = -1;
//    for(auto v : adj[u]){
//        if(vis[v] == -1 || (vis[v] == 0 && dfs(v))) return true;
//    }
//    vis[u] = 1;
//    return false;
//}
//
//bool find_circle()
//{
//    memset(vis,0,sizeof(vis));
//    for(int i = 0;i < 52;i ++){
//        if(vis[i] == 0 && dfs(i)) return true;
//    }
//    return false;
//}
//
//int main()
//{
//    int n;string s;
//    while(cin >> n){
//        adj.clear();adj.resize(52);
//        for(int i = 0;i < n;i ++){
//            cin >> s;
//            for(int j = 0;j < 4;j ++){
//                for(int k = 0;k < 4;k ++){
//                    if(j != k) connect(s[j * 2],s[j * 2 + 1],s[k * 2],s[k * 2 + 1]);
//                }
//            }
//        }
//        printf("%s\n",find_circle() ? "unbounded" : "bounded");
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//
//using namespace std;
//const int N = 1e5 + 10;
//struct Edge
//{
//    int u, v, c;
//    Edge(int _u, int _v, int _c) : u(_u), v(_v), c(_c){}
//};
//vector<Edge> edge;//边的缓存优化
//vector<int> G[N];
//
//int n, m, a, b, c;
//int d[N], vis[N];
//
//void revbfs()
//{
//    memset(d, 0, sizeof(d));
//    memset(vis, 0, sizeof(vis));
//    queue<int> q;
//    q.push(n - 1);vis[n - 1] = 1;
//    while(!q.empty()){
//        int u = q.front();q.pop();
//        for(int e : G[u]){
//            int v = (u == edge[e].u) ? edge[e].v : edge[e].u;
//            if(!vis[v]){
//                d[v] = d[u] + 1;
//                q.push(v);
//                vis[v] = 1;
//            }
//        }
//    }
//}
//
//void bfs()
//{
//    printf("%d\n",d[0]);
//    memset(vis,0,sizeof(vis));
//    vector<int> next{0}, ans;
//    for(int i =0 ;i < d[0]; i++ ){
//        int mincol = 0x3f3f3f3f;
//        for(int u : next){
//            for(int e : G[u]){
//                int v = (u == edge[e].u) ? edge[e].v : edge[e].u;
//                if(d[u] == d[v] + 1 && edge[e].c < mincol) mincol = edge[e].c;
//            }
//        }
//        ans.push_back(mincol);
//        vector<int> tnext;
//        for(int u : next){
//            for(int e : G[u]){
//                int v = (u == edge[e].u) ? edge[e].v : edge[e].u;
//                if(d[u] == d[v] + 1 && vis[v] == 0 && edge[e].c == mincol){
//                    tnext.push_back(v);
//                    vis[v] = 1;
//                }
//            }
//        }
//        next = tnext;
//    }
//    for(int i = 0; i < ans.size();i ++){
//        printf("%d%s",ans[i],i == ans.size() - 1 ? "\n" : " ");
//    }
//}
//
//int main()
//{
//    while(cin >> n >> m){
//        edge.clear();fill(G,G+N,vector<int>{});
//        while(m --){
//            cin >> a >> b >> c;
//            if(a == b) continue;
//            G[a - 1].push_back(edge.size());
//            G[b - 1].push_back(edge.size());
//            edge.push_back({a - 1, b - 1, c});
//        }
//        revbfs();
//        bfs();
//    }
//    return 0;
//}
//#include<iostream>
//#include<stack>
//#include<cstring>
//#include<string>
//#include<algorithm>
//#include<map>
//
//using namespace std;
//string s;
//map<char,char> mp;
//int main()
//{
//    int t; cin >> t;
//    mp[']'] = '[';
//    mp[')'] = '(';
//    getchar();
//    while(t -- ){
//        int flag = 1;
//        stack<char> stk;
//        getline(cin,s);
//        for(int i = 0;i < s.length();i ++){
//            if(s[i] == '(' || s[i] == '[') stk.push(s[i]);
//            else if(s[i] == ')' || s[i] == ']'){
//                if(stk.empty()){
//                    flag = 0;
//                    break;
//                }
//                char tt = stk.top();
////                cout << tt << endl;
//                if(tt == mp[s[i]]) stk.pop();
//                else{
//                    flag = 0;
//                    break;
//                }
//            }
//            else if(s[i] == ' ') continue;
//            else{
//                flag = 0;
//                break;
//            }
//        }
//        if(!stk.empty())flag = 0;
//        if(flag) cout << "Yes" << endl;
//        else cout << "No" << endl;
//    }
//    return 0;
//}
















