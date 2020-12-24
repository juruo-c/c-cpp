//#include<bits/stdc++.h>
//
//using namespace std;
//
//int h,w,kase;
//string s,img[210],img_2[210];
//map<char,string> mp; // 16进制字符 -> 2进制字符串
//char word[] = {'W','A','K','J','S','D'};
//
//void tran()
//{
//    char c[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
//    for(int i = 0;i < 16;i ++){
//        bitset<4> bt(i);
//        mp[c[i]] = bt.to_string();
//    }
//}
//
//void dfs(int x,int y,char tag)
//{
//    if(tag == '0') img[x][y] = '0';
//    if(tag == '0') img_2[x + 1][y + 1] = '1';
//    else img_2[x][y] = '1';
//    int xx, yy, ht, wt;
//    for(int i = -1;i <= 1; i++){
//        for(int j = -1;j <= 1;j ++){
//            if(i == 0 && j == 0) continue;
//            xx = x + i, yy = y + j;
//            ht = (tag == '1') ? h + 2 : h;
//            wt = (tag == '1') ? w * 4 + 2 : w * 4;
//            if(xx >= 0 && xx < ht && yy >= 0 && yy < wt){
//                if(tag == '0' && img[xx][yy] == '1' || tag == '1' && img_2[xx][yy] == '0'){
//                    dfs(xx, yy, tag);
//                }
//            }
//        }
//    }
//}
//
//int main()
//{
//    tran();
//    while(cin >> h >> w && (h != 0 && w != 0)){
//        for(int i = 0;i < h;i ++){
//            cin >> s;img[i].clear();
//            for(int j = 0;j < s.size();j ++){
//                img[i].append(mp[s[j]]);
//            }
//        }
//        vector<char> res;
//        for(int i = 0;i < h;i ++){
//            for(int j = 0;j < w * 4;j ++){
//                if(img[i][j] == '1'){
//                    for(int k = 0;k < h + 2;k ++){
//                        img_2[k] = string(4 * w + 2, '0');
//                    }
//                    dfs(i,j, '0');// 拷贝黑色联通块
//                    int cnt = 0;
//                    for(int i2 = 0;i2 < h + 2;i2 ++){
//                        for(int j2 = 0;j2 < 4 * w + 2;j2 ++){
//                            if(img_2[i2][j2] == '0'){
//                                cnt ++;
//                                dfs(i2,j2, '1');//统计白色块个数
//                            }
//                        }
//                    }
//                    res.push_back(word[cnt - 1]);
//                }
//            }
//        }
//        sort(res.begin(),res.end());
//        printf("Case %d: ", ++ kase);
//        for(auto c : res){
//            cout << c;
//        }
//        puts("");
//    }
//    return 0;
//}
//#include<iostream>
//#include<queue>
//#include<cstring>
//#include<algorithm>
//#include<sstream>
//
//using namespace std;
//const int N = 10;
//const char* dirs = "NESW";
//const char* turns = "FR L";
//string name,s;
//int stx,sty,sdir,ex,ey,edir;
//char stdir;
//bool have_edge[N][N][4][4],vis[N][N][4];
//int dirt[][2] = {{0,1},{1,0},{0,-1},{-1,0}};
//struct node
//{
//    int x,y,dir;
//};
//node pre[N][N][4];
//node init = {0,0,0};
//
//void print()
//{
//    vector<node> pa;
//    node u = {ex,ey,edir};
//    while(1){
//        node t = pre[u.x][u.y][u.dir];
//        if(t.x == 0 && t.y == 0 && t.dir == 0)break;
//        pa.push_back(u);
//        u = pre[u.x][u.y][u.dir];
//    }
//    for(int i = 0;i < pa.size();i ++){
//        printf("(%d,%d)",pa[i].x,pa[i].y);
//        if(i < pa.size() - 1) cout << " " ;
//    }
//}
//
//void bfs()
//{
//    queue<node> q;
//    node cur,next;
//    cur.x = stx,cur.y = sty,cur.dir = sdir;
//    vis[cur.x][cur.y][cur.dir] = 1;
//    q.push(cur);
//    while(!q.empty()){
//        cur = q.front();
//        q.pop();
//        if(cur.x == ex && cur.y == ey){
//            print();
//            return ;
//        }
//        for(int i = 0;i < 3;i ++){
//            if(have_edge[cur.x][cur.y][cur.dir][i]){
//                next.x = cur.x + dirt[0][cur.dir];
//                next.y = cur.y + dirt[1][cur.dir];
//                next.dir = (cur.dir + i) % 4;
//                if(vis[next.x][next.y][next.dir] == 0){
//                    edir = next.dir;
//                    pre[next.x][next.y][next.dir] = {cur.x,cur.y,cur.dir};
//                    q.push(next);
//                    vis[next.x][next.y][next.dir] = 1;
//                }
//            }
//        }
//    }
//    cout << "No Solution Possible" << endl;
//}
//int main()
//{
//    while(getline(cin,name) && name[0] != 'E'){
//        cout << name << endl;
//        memset(have_edge,0,sizeof(have_edge));
//        memset(vis,0,sizeof(vis));
//        cin >> stx >> sty >> stdir >> ex >> ey;
//        pre[stx][sty][stdir] = init;
//        sdir = strchr(dirs,stdir) - dirs;
//        while(getline(cin,s) && s[0] != '0'){
//            stringstream ss(s);
//            int x,y;ss >> x >> y;
//            string st;
//            while(ss >> st && st[0] != '*'){
//                char ch = st[0];
//                int t = strchr(dirs,ch) - dirs;
//                for(int i = 1;i < st.length();i ++){
//                    int tt = strchr(turns,st[i]) - turns;
//                    have_edge[x][y][t][tt] = 1;
//                }
//            }
//        }
//        bfs();
//    }
//    return 0;
//}

//#include<cstdio>
//#include<cstring>
//#include<queue>
//#include<vector>
//#include<iostream>
//
//using namespace std;
//
//const int  dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
//const char* dirs = "NESW";
//const char* turns = "LFR";
//const int N = 10;
//int stx,sty,ex,ey,d[N][N][4],fd,ns[N][N];
//bool has_edge[N][N][4][3];
//char sdir;
//string tag;
//
//struct node
//{
//    int x,y,dir;
//};
//
//node p[N][N][4];
//
//node walk(node u,int i)
//{
//    int d = u.dir;
//    if(i == 0) d = (d + 3) % 4;
//    if(i == 2) d = (d + 1) % 4;
//    u.x += dir[d][0],u.y += dir[d][1],u.dir = d;
//    return u;
//}
//
//void print(node& u)
//{
//    vector<node> nodes;
//    while(1){
//        nodes.push_back(u);
//        if(d[u.x][u.y][u.dir] == 0) break;
//        u = p[u.x][u.y][u.dir];
//    }
//
//    int len = nodes.size();
//    printf("  (%d,%d)",stx,sty);
//    for(int i = len - 1;i >= 0;i --){
//        if((len - i) % 10 == 0) printf("\n ");
//        printf(" (%d,%d)",nodes[i].x,nodes[i].y);
//    }
//    cout << endl;
//}
//
//void bfs()
//{
//    queue<node> q;
//    node u = node{stx,sty,fd};
//    node v = walk(u,1);
//    p[v.x][v.y][v.dir] = u;
//    q.push(v);
//    d[v.x][v.y][v.dir] = 0;
//    while(!q.empty()){
//        node u = q.front(); q.pop();
//        if(u.x == ex && u.y == ey){
//            print(u);
//            return;
//        }
//        for(int i = 0;i < 3;i ++){
//            node v = walk(u,i);
//            if(d[v.x][v.y][v.dir] < 0 && ns[v.x][v.y] && has_edge[u.x][u.y][u.dir][i]){
//                d[v.x][v.y][v.dir] = d[u.x][u.y][u.dir] + 1;
//                p[v.x][v.y][v.dir] = u;
//                q.push(v);
//            }
//        }
//    }
//    printf("  No Solution Possible\n");
//}
//
//int main()
//{
//    while(cin >> tag){
//        if(tag == "END") break;
//        cout << tag << endl;
//        memset(d,-1,sizeof(d));
//        memset(ns,0,sizeof(ns));
//        memset(has_edge,0,sizeof(has_edge));
//        cin >> stx >> sty >> sdir >> ex >> ey;
//        ns[stx][sty] = ns[ex][ey] = 1;
//        fd = strchr(dirs,sdir) - dirs;
//        while(1){
//            int x,y;cin >> x;
//            if(x == 0) break;
//            cin >> y;
//            ns[x][y] = 1;
//            string st;
//            while(cin >> st && st[0] != '*'){
////                cout << st << endl;
//                int t = strchr(dirs,st[0]) - dirs;
//                for(int i = 1;i < st.length();i ++){
//                    int tt = strchr(turns,st[i]) - turns;
//                    has_edge[x][y][t][tt] = 1;
//                }
//            }
//        }
//
//        bfs();
//
//    }
//    return 0;
//}


//#include <cstdio>
//#include <cstring>
//#include <queue>
//#include <vector>
//const int dx[] = {-1, 0, 1, 0};
//const int dy[] = {0, 1, 0, -1};
//const char *dirs = "NESW";
//const char *turns = "LFR";
//int x0, y0, x2, y2, d[10][10][4], has_edge[10][10][4][3], fd, ns[10][10];
//char firstd, tag[25];
////AC码参考
////终于做出来了。。。
//
//struct Node {
//    int x, y, dir;
//};
//
//Node p[10][10][4];
//
//Node walk(Node u, int i) {
//    int &d = u.dir;
//    if (i == 0) d = (d + 3) % 4;
//    if (i == 2) d = (d + 1) % 4;
//    u.x += dx[d], u.y += dy[d];
//    return u;
//}
//
//void print_ans(Node& u) {
//    std::vector<Node> nodes;
//    for (;;) {
//        nodes.push_back(u);
//        if (d[u.x][u.y][u.dir] == 0) break;
//        u = p[u.x][u.y][u.dir];
//    }
//
//    int len = nodes.size();
//    printf("\n  (%d,%d)", x0, y0);
//    for (int i = len-1; i >= 0; i--) {
//        if ((len - i) % 10 == 0) printf("\n ");
//        printf(" (%d,%d)", nodes[i].x, nodes[i].y);
//    }
//    printf("\n");
//}
//
//int find(const char *str, char v) {
//    int len = strlen(str);
//    for (int i = 0; i < len; i++) if (str[i] == v) return i;
//    return -1;
//}
//
//void solve() {
//    std::queue<Node> q;
//    Node u = Node{x0, y0, fd};
//    Node v = walk(u, 1);
//    p[v.x][v.y][v.dir] = u;
//    q.push(v);
//    d[v.x][v.y][v.dir] = 0;
//    while (!q.empty()) {
//        Node u = q.front(); q.pop();
//        if (u.x == x2 && u.y == y2) {print_ans(u); return;}
//        else for (int i = 0; i < 3; i++) {
//            Node v = walk(u, i);
//            if (d[v.x][v.y][v.dir] < 0 && ns[v.x][v.y] && has_edge[u.x][u.y][u.dir][i]) {
//                d[v.x][v.y][v.dir] = d[u.x][u.y][u.dir] + 1;
//                p[v.x][v.y][v.dir] = u;
//                q.push(v);
//            }
//        }
//    }
//    printf("\n  No Solution Possible\n");
//}
//
//int main() {
//    while (scanf("%s", &tag) == 1) {
//        if (tag[0] == 'E' && tag[1] == 'N' && tag[2] == 'D' && tag[3] == '\0') break;
//        printf("%s", tag);
//        memset(d, -1, sizeof(d));
//        memset(ns, 0, sizeof(ns));
//        memset(has_edge, 0, sizeof(has_edge));
//        scanf("%d %d %c %d %d\n", &x0, &y0, &firstd, &x2, &y2);
//        ns[x0][y0] = ns[x2][y2] = 1;
//        fd = find(dirs, firstd);
//        for (;;) {
//            int x, y;
//            scanf("%d", &x);
//            if (x == 0) break;
//            scanf("%d", &y);
//            ns[x][y] = 1;
//            char temp[10];
//            memset(temp, 0, sizeof(temp));
//            while (scanf("%s", &temp) == 1 && temp[0] != '*') {
//                int *temp2 = has_edge[x][y][find(dirs, temp[0])], len = strlen(temp);
//                for (int i = 1; i < len; i++) {
//                    temp2[find(turns, temp[i])] = 1;
//                }
//            }
//        }
//        solve();
//    }
//    return 0;
//}
//
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 500;
//int n,m,a,t,b;
//int G[N][N];
//int d[N],top[N];
//
//bool dfs(int u){
//    d[u] = -1;
//    for(int v = 1;v <= n;v ++){
//        if(G[u][v]){
//            if(d[v] < 0) return false;
//            else if(!d[v]) dfs(v);
//        }
//    }
//    d[u] = 1;
//    top[t--] = u;
//    return true;
//}
//
//bool toposort(){
//    for(int u = 1;u <= n;u ++){
//        if(!d[u]){
//            if(!dfs(u)){
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//int main()
//{
//    while(cin >> n >> m && n){
//        memset(d,0,sizeof(d));
//        memset(G,0,sizeof(G));
//
//        for(int i = 1;i <= m;i ++){
//            cin >> a >> b;
//            G[a][b] = 1;
//        }
//
//        t = n;
//
//        if(toposort()){
//            for(int i = 1;i < n;i ++){
//                cout << top[i] << " ";
//            }
//            cout << top[n] << endl;
//        }
//    }
//    return 0;
//}
//#include<iostream>
//#include<map>
//#include<vector>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<sstream>
//#include<cstdio>
//
//using namespace std;
//map<string,string> old_list,new_list;
//vector<string> od;
//vector<string> add;
//vector<string> del;
//vector<string> mod;
//string s,st,a,b;
//
//int main()
//{
//    int t; cin >> t;
//    getchar();
//    while(t-- ){
//        int flag = 0;
//        od.clear();
//        old_list.clear();new_list.clear();
//        add.clear();del.clear();mod.clear();
//        getline(cin,s);s = s.substr(1);
//        while(s.find(',') != s.npos){
//            int tt = s.find(',');
//            st = s.substr(0,tt);
//            int tmp = st.find(':');
//            a = st.substr(0,tmp);
//            b = st.substr(tmp + 1);
//            od.push_back(a);
//            old_list[a] = b;
//            s = s.substr(tt + 1);
//        }
//        int tmp = s.find(':');
//        a = s.substr(0,tmp);
//        od.push_back(a);
//        b = s.substr(tmp + 1,s.length() - tmp - 2);
//        old_list[a] = b;
////        for(int i = 0;i < od.size();i ++){
////            cout << od[i] << ": " << old_list[od[i]] << endl;
////        }
//        getline(cin,s);s = s.substr(1);
//        while(s.find(',') != s.npos){
//            int tt = s.find(',');
//            st = s.substr(0, tt);
//            int tmp = st.find(':');
//            a = st.substr(0,tmp);
//            b = st.substr(tmp + 1);
//            new_list[a] = b;
//            if(old_list[a].empty()){
//                add.push_back(a);
//                flag = 1;
//            }
//            else{
//                if(old_list[a] != b){
//                    mod.push_back(a);
//                    flag = 1;
//                }
//            }
//            s = s.substr(tt + 1);
//        }
//        tmp = s.find(':');
//        a = s.substr(0,tmp);
//        b = s.substr(tmp + 1,s.length() - tmp - 2);
//        new_list[a] = b;
//        if(old_list[a].empty()){
//            add.push_back(a);
//            flag = 1;
//        }
//        else{
//            if(old_list[a] != b){
//                mod.push_back(a);
//                flag = 1;
//            }
//        }
//
//        for(int i = 0;i < od.size();i ++){
//            if(new_list[od[i]].empty()){
//                del.push_back(od[i]);
//                flag = 1;
//            }
//        }
//
//        if(flag){
//            if(!add.empty()){
//                sort(add.begin(),add.end());
//            	cout << "+" << add[0];
//            	for(int i = 1;i < add.size();i ++) cout << "," << add[i];
//           	 	cout << endl;
//			}
//
//            if(!del.empty()){
//                sort(del.begin(),del.end());
//            	cout << "-" << del[0];
//            	for(int i = 1;i < del.size();i ++) cout << "," << del[i];
//				cout << endl;
//			}
//
//            if(!mod.empty()){
//                sort(mod.begin(),mod.end());
//            	cout << "*" << mod[0];
//            	for(int i = 1;i < mod.size();i ++) cout << "," << mod[i];
//            	cout << endl;
//			}
//        }
//        else{
//            cout << "No changes" << endl;
//        }
//        if(t) puts("");
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//
//using namespace std;
//int t;
//string sa,sb;
//
//void getDict(map<string,string>& mp,string s)
//{
//    for(auto& ch : s)
//    if(ch == '{' || ch == '}' || ch == ',' || ch == ':') ch = ' ';
//    stringstream input(s);
//    string sk,sv;
//    while(input >> sk >> sv) mp[sk] = sv;
//}
//
//void print(char mess,const set<string>& _set)
//{
//    if(_set.empty()) return;
//    cout << mess;
//    for(auto p : _set) printf("%s%s",p.c_str(),p == *_set.rbegin() ? "\n" : ",");
//}
//int main()
//{
//    cin >> t;
//    while(t --){
//        cin >> sa >> sb;
//        map<string,string> mpa,mpb;
//        getDict(mpa,sa);getDict(mpb,sb);
//        set<string> del,chg,inc;
//        for(auto p : mpa){
//            if(mpb.find(p.first) == mpb.end()) del.insert(p.first);
//            else{
//                if(mpa[p.first] != mpb[p.first]) chg.insert(p.first);
//                mpb.erase(p.first);
//            }
//        }
//        for(auto p : mpb) inc.insert(p.first);
//        print('+',inc);print('-',del);print('*',chg);
//        if(inc.empty() && del.empty() && chg.empty()) puts("No changes");
//        puts("");
//    }
//    return 0;
//}















