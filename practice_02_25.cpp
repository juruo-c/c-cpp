//
// Created by lenovo on 2021/2/25.
//

//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<iostream>
//#include<vector>
//
//using namespace std;
//const int N = 5.1e5 + 10;
//long long ans;
//int cnt,last[N],sz[N],n;
//char s[N];
//vector<int> g[N];
//struct node{
//    int nt[26];
//    bool fl;
//};
//template <class T>
//inline void read(T& x){
//    x = 0;int fl = 1;
//    char c = getchar();
//    while(!isdigit(c)) c = getchar();
//    while(isdigit(c)) x = x * 10 + c - '0',c = getchar();
//    x *= fl;
//}
//template <class T>
//inline void write(T x){
//    if(x < 0) putchar('-'),write(-x);
//    else{
//        if(x > 9) write(x / 10);
//        putchar('0' + x % 10);
//    }
//}
//
//struct trie{
//    node a[N];
//    int cnt;
//    void insert(char s[]){
//        int u = 0;
//        for(int i = 0;s[i];i ++){
//            if(!a[u].nt[s[i] - 'a']) a[u].nt[s[i] - 'a'] = ++cnt;
//            u = a[u].nt[s[i] - 'a'];
//        }
//        a[u].fl = 1;
//    }
//
//    void doit(int u){//重构Trie树
//        if(a[u].fl && u){
//            g[last[u]].push_back(u);
//            last[u] = u;
//        }
//        for(int i = 0;i < 26;i ++){
//            if(a[u].nt[i]){
//                last[a[u].nt[i]] = last[u];
//                doit(a[u].nt[i]);
//            }
//        }
//    }
//}tr;
//
//bool cmp(int x,int y){
//    return sz[x] < sz[y];
//}
//void dfs(int u){//重排重构树
//    sz[u] = 1;
//    for(int i = 0;i < g[u].size();i ++){
//        dfs(g[u][i]);
//        sz[u] += sz[g[u][i]];
//    }
//    sort(g[u].begin(),g[u].end(),cmp);
//}
//
//void solve(int u){//用dfs序统计答案
//    int dfn = cnt ++;
//    for(int i = 0;i < g[u].size();i ++){
//        ans += cnt - dfn;
//        solve(g[u][i]);
//    }
//}
//int main(){
//    read(n);
//    for(int i = 1;i <= n;i ++){
//        scanf("%s",s);
//        reverse(s,s + strlen(s));
//        tr.insert(s);
//    }
//    tr.a[0].fl = 1;
//    tr.doit(0);
//    dfs(0);
//    solve(0);
//    write(ans);
//    return 0;
//}
//
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 5e5 + 10;
//int n,m;
//char s[N];
//template<class T>
//inline void read(T& x){
//    x = 0;int fl = 1;
//    char c = getchar();
//    while(!isdigit(c)) {
//        if(c == '-') fl = -1;
//        c = getchar();
//    }
//    while(isdigit(c)) x = x * 10 + c - '0',c = getchar();
//    x *= fl;
//}
//
//template<class T>
//inline void write(T x){
//    if(x < 0) putchar('-'),write(-x);
//    else{
//        if(x > 9) write(x / 10);
//        putchar('0' + x % 10);
//    }
//}
//int ch[N][26],cnt;
//bool bo[N];
//int sum[N],tot[N];
//void insert(char s[]){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        int v = s[i] - 'a';
//        if(!ch[u][v]) ch[u][v] = ++cnt;
//        u = ch[u][v];
//        sum[u] ++;
//    }
//    bo[u] = 1;
//    tot[u] ++;
//}
//
//int query(char s[]){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        int v = s[i] - 'a';
//        if(!ch[u][v]) return u;
//        u = ch[u][v];
//    }
//    if(bo[u]) return -1;
//    return u;
//}
//int main(){
//    read(n),read(m);
//    for(int i = 0;i < n;i ++){
//        scanf("%s",s);
//        insert(s);
//    }
//    for(int i = 0;i < n;i ++){
//        scanf("%s",s);
//        int res = query(s);
//    }
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e5 + 10;
//int ch[N * 20][26],cnt;
//char s[22];
//bool bo[N * 20],vis[N * 20],isword;
//int n,m,tot;
//
//void insert(char s[]){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        int v = s[i] - 'a';
//        if(!ch[u][v]) ch[u][v] = ++ cnt;
//        u = ch[u][v];
//    }
//    bo[u] = 1;
//}
//int len;
//void dfs(int rt,int l,int f){
//    if(l == len && bo[rt] && !f){
//        isword = true;return;
//    }
//    if(l == len && bo[rt] && f){
//        if(!vis[rt]){
//            vis[rt] = 1;
//            tot ++;
//        }
//        return;
//    }
//    int c = s[l] - 'a';
//    if(!f){
//        if(l < len) dfs(rt,l + 1,1);//删除0
//        for(int i = 0;i < 26;i ++){
//            if(ch[rt][i]){
//                dfs(ch[rt][i],l,1);//添加
//                if(i != c) dfs(ch[rt][i],l + 1,1); // 替换
//            }
//        }
//    }
//    if(l >= len) return;
//    if(ch[rt][c]) dfs(ch[rt][c],l + 1,f);//直接查
//}
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 0;i < n;i ++){
//        scanf("%s",s);
//        insert(s);
//    }
//    for(int i = 0;i < m;i ++){
//        scanf("%s",s);
//        len = strlen(s);
//        dfs(0,0,0);
//        if(isword) printf("-1\n");
//        else printf("%d\n",tot);
//        memset(vis,0,sizeof(vis));
//        tot = 0;
//        isword = 0;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//const int N = 5e5 + 10;
//queue<int> q;
//int ch[N][26],val[N],fail[N],cnt;
//
//void insert(char s[]){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        int c = s[i] - 'a';
//        if(!ch[u][c]) ch[u][c] = ++ cnt;
//        u = ch[u][c];
//    }
//    val[u] ++;
//}
//
//void getfail(){
//    for(int i = 0;i < 26;i ++){
//        if(ch[0][i]) fail[ch[0][i]] = 0,q.push(ch[0][i]);
//    }
//    while(!q.empty()){
//        int u =q.front();q.pop();
//        for(int i = 0;i < 26;i ++){
//            if(ch[u][i]){
//                fail[ch[u][i]] = ch[fail[u]][i];
//                q.push(ch[u][i]);
//            }
//            else ch[u][i] = ch[fail[u]][i];
//        }
//    }
//}
//
//int query(char s[]){
//    int u = 0;int ans = 0;
//    for(int i = 0;s[i];i ++){
//        u = ch[u][s[i] - 'a'];
//        for(int j = u;j && ~val[j]; j = fail[j]) ans += val[j],val[j] = -1;
//    }
//    return ans;
//}
//int n;char s[1000010];
//int main(){
//    scanf("%d",&n);
//    for(int i = 0;i < n;i ++){
//        scanf("%s",s);
//        insert(s);
//    }
//    getfail();
//    scanf("%s",s);
//    printf("%d\n",query(s));
//    return 0;
//}
//

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<queue>
//
//using namespace std;
//const int N = 1e5 + 10;
//int ch[N][26],fail[N],bo[N];
//int cnt;
//struct cuan{
//    int num,pos;
//    bool operator < (const cuan& b) const{
//        if(num == b.num) return pos < b.pos;
//        return num > b.num;
//    }
//}ans[N];
//
//string s[N];
//
//void insert(string s,int x){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        int v = s[i] - 'a';
//        if(!ch[u][v]) ch[u][v] = ++cnt;
//        u = ch[u][v];
//    }
//    bo[u] = x;
//}
//
//void getfail(){
//    queue<int> q;
//    for(int i = 0;i < 26;i ++){
//        if(ch[0][i]){
//            fail[ch[0][i]] = 0;
//            q.push(ch[0][i]);
//        }
//    }
//    while(!q.empty()){
//        int u = q.front();
//        q.pop();
//        for(int i = 0;i < 26;i ++){
//            if(ch[u][i]){
//                fail[ch[u][i]] = ch[fail[u]][i];
//                q.push(ch[u][i]);
//            }
//            else ch[u][i] = ch[fail[u]][i];
//        }
//    }
//}
//
//void query(string s){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        u = ch[u][s[i] - 'a'];
//        for(int j = u;j;j = fail[j]) ans[bo[j]].num ++;
//    }
//}
//void init(){
//    memset(ch,0,sizeof(ch));
//    memset(fail,0,sizeof(fail));
//    memset(bo,0,sizeof(bo));
//}
//int main(){
//    int n;
//    while(cin >> n && n){
//        init();
//        cnt = 0;
//        for(int i = 1;i <= n;i ++){
//            cin >> s[i];
//            ans[i].num = 0;
//            ans[i].pos = i;
//            insert(s[i],i);
//        }
//        getfail();
//        cin >> s[0];
//        query(s[0]);
//        sort(ans + 1,ans + 1 + n);
//        cout << ans[1].num << endl;
//        cout << s[ans[1].pos] << endl;
//        for(int i = 2;i <= n;i ++){
//            if(ans[i].num == ans[1].num) cout << s[ans[i].pos] << endl;
//            else break;
//        }
//    }
//    return 0;
//}


//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<queue>
//
//using namespace std;
//const int N = 2e6 + 10;
//int ch[N][26],fail[N],bo[N],cnt;
//int ans[N];
//int n;
//char s[N];
//void insert(char s[],int x){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        int v = s[i] - 'a';
//        if(!ch[u][v]) ch[u][v] = ++ cnt;
//        u = ch[u][v];
//    }
//    bo[u] = x;
//}
//
//void getfail(){
//    queue<int> q;
//    for(int i = 0;i < 26;i ++){
//        if(ch[0][i]) fail[ch[0][i]] = 0,q.push(ch[0][i]);
//    }
//    while(!q.empty()){
//        int u = q.front();
//        q.pop();
//        for(int i = 0;i < 26;i ++){
//            if(ch[u][i]){
//                fail[ch[u][i]] = ch[fail[u]][i];
//                q.push(ch[u][i]);
//            }
//            else ch[u][i] = ch[fail[u]][i];
//        }
//    }
//}
//
//void query(char s[]){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        u = ch[u][s[i] - 'a'];
//        for(int j = u;j;j = fail[j]) ans[bo[j]] ++;
//    }
//}
//int main(){
//    scanf("%d",&n);
//    for(int i = 1;i <= n;i ++){
//        scanf("%s",s);
//        insert(s,i);
//    }
//    getfail();
//    scanf("%s",s);
//    query(s);
//    for(int i = 1;i <= n;i ++) printf("%d\n",ans[i]);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<queue>
//
//using namespace std;
//const int N = 2e6 + 10;
//char s[N];
//int ch[N][26],cnt,fail[N],ans[N],fl[N];
//int n,vis[N],map[N],in[N];
//void insert(char s[],int x){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        int v = s[i] - 'a';
//        if(!ch[u][v]) ch[u][v] = ++ cnt;
//        u = ch[u][v];
//    }
//    if(!fl[u]) fl[u] = x;
//    map[x] = fl[u];
//}
//
//void getfail(){
//    queue<int> q;
//    for(int i = 0;i < 26;i ++){
//        if(ch[0][i]){
//            fail[ch[0][i]] = 0;
//            q.push(ch[0][i]);
//        }
//    }
//    while(!q.empty()){
//        int u = q.front();q.pop();
//        for(int i = 0;i < 26;i ++){
//            if(ch[u][i]){
//                fail[ch[u][i]] = ch[fail[u]][i];
//                in[fail[ch[u][i]]] ++;
//                q.push(ch[u][i]);
//            }
//            else ch[u][i] = ch[fail[u]][i];
//        }
//    }
//}
//
//void toposort(){
//    queue<int> q;
//    for(int i = 0;i <= cnt;i ++) if(!in[i]) q.push(i);
//    while(!q.empty()){
//        int u = q.front();q.pop();
//        vis[fl[u]] = ans[u];
//        int v = fail[u];in[v] --;
//        ans[v] += ans[u];
//        if(!in[v]) q.push(v);
//    }
//}
//
//void query(char s[]){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        u = ch[u][s[i] - 'c'];
//        ans[u] ++;
//    }
//}
//
//int main(){
//    scanf("%d",&n);
//    for(int i = 1;i <= n;i ++){
//        scanf("%s",s);
//        insert(s,i);
//    }
//    getfail();
//    scanf("%s",s);
//    query(s);toposort();
//    for(int i = 1;i <= n;i ++) printf("%d\n",vis[map[i]]);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//const int N = 2e6 + 10;
//char s[N];
//int n,cnt;
//int vis[N],in[N],map[N];
//struct node{
//    int son[26],fail,fl,ans;
//}ch[N];
//queue<int> q;
//void insert(char s[],int x){
//    int u = 1;
//    for(int i = 0;s[i];i ++){
//        int v = s[i] - 'a';
//        if(!ch[u].son[v]) ch[u].son[v] = ++cnt;
//        u = ch[u].son[v];
//    }
//    if(!ch[u].fl) ch[u].fl = x;
//    map[x] = ch[u].fl;
//}
//
//void getfail(){
//    for(int i = 0;i < 26;i ++) ch[0].son[i] = 1;
//    q.push(1);
//    while(!q.empty()){
//        int u = q.front();
//        q.pop();
//        int F = ch[u].fail;
//        for(int i = 0;i < 26;i ++){
//            int v = ch[u].son[i];
//            if(v){
//                ch[v].fail = ch[F].son[i];
//                in[ch[v].fail] ++;
//                q.push(v);
//            }
//            else ch[u].son[i] = ch[F].son[i];
//        }
//    }
//}
//
//void query(char s[]){
//    int u = 1;
//    for(int i = 0;s[i];i ++){
//        u = ch[u].son[s[i] - 'a'];
//        ch[u].ans ++;
//    }
//}
//
//void topu(){
//    for(int i = 1;i <= cnt;i ++){
//        if(!in[i]) q.push(i);
//    }
//    while(!q.empty()){
//        int u = q.front();q.pop();
//        vis[ch[u].fl] = ch[u].ans;
//        int v = ch[u].fail;in[v] --;
//        ch[v].ans += ch[u].ans;
//        if(!in[v]) q.push(v);
//    }
//}
//int main(){
//    scanf("%d",&n);
//    cnt = 1;
//    for(int i = 1;i <= n;i ++){
//        scanf("%s",s);
//        insert(s,i);
//    }
//    getfail();
//    scanf("%s",s);
//    query(s);topu();
//    for(int i = 1;i <= n;i ++) printf("%d\n",vis[map[i]]);
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//const int N = 2e6 + 10;
//int n,cnt;
//int in[N],vis[N],map[N];
//struct node{
//    int son[26],fail,ans,fl;
//}ch[N];
//
//void insert(string s,int x){
//    int u = 1;
//    for(int i = 0;s[i];i ++){
//        int v = s[i] - 'a';
//        if(!ch[u].son[v]) ch[u].son[v] = ++ cnt;
//        u = ch[u].son[v];
//    }
//    if(!ch[u].fl) ch[u].fl = x;
//    map[x] = ch[u].fl;
//}
//queue<int> q;
//void getfail(){
//    for(int i = 0;i < 26;i ++) ch[0].son[i] = 1;
//    q.push(1);
//    while(!q.empty()){
//        int u = q.front();q.pop();
//        int F = ch[u].fail;
//        for(int i = 0;i < 26;i ++){
//            int v = ch[u].son[i];
//            if(v){
//                ch[v].fail = ch[F].son[i];
//                in[ch[v].fail] ++;
//                q.push(v);
//            }
//            else ch[u].son[i] = ch[F].son[i];
//        }
//    }
//}
//
//void topu(){
//    for(int i = 1;i <= cnt;i ++)if(!in[i]) q.push(i);
//    while(!q.empty()){
//        int u = q.front();
//        q.pop();vis[ch[u].fl] = ch[u].ans;
//        int v = ch[u].fail;
//        in[v] --;ch[v].ans += ch[u].ans;
//        if(!in[v]) q.push(v);
//    }
//}
//
//void query(string s){
//    int u = 1;
//    for(int i = 0;s[i];i ++){
//        u = ch[u].son[s[i] - 'a'];
//        ch[u].ans ++;
//    }
//}
//string s[210];
//int main(){
//    cin >> n;string sal;cnt = 1;
//    for(int i = 1;i <= n ;i ++){
//        cin >> s[i];
//        sal += s[i];
//        insert(s[i],i);
//    }
//    getfail();
//    query(sal);topu();
//    for(int i = 1;i <= n;i ++) cout << vis[map[i]] << endl;
//    return 0;
//}


//#include<cstdio>
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//const int N = 2e6 + 10;
//int n,cnt;int ans[N];
//char s[201][N];
//int vis[N],map[N],sum[N],fl[N];
//int ch[N][26],fail[N];
//queue<int> q;
//void insert(char s[],int x){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        int v = s[i] - 'a';
//        if(!ch[u][v]) ch[u][v] = ++cnt;
//        u = ch[u][v];
//        sum[u] ++;
//    }
//    if(fl[u]) map[x] = fl[u];
//    else fl[u] = x;
//}
//
//void getfail(){
//    for(int i = 0;i < 26;i ++) if(ch[0][i]) q.push(ch[0][i]);
//    while(!q.empty()){
//        int u = q.front();q.pop();
//        for(int i = 0;i < 26;i ++){
//            if(ch[u][i]){
//                fail[ch[u][i]] = ch[fail[u]][i];
//                q.push(ch[u][i]);
//            }
//            else ch[u][i] = ch[fail[u]][i];
//        }
//    }
//}
//
//void query(char s[]){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        u = ch[u][s[i] - 'a'];
//        for(int j = u;j;j = fail[j]) if(fl[j] && !vis[u]) ans[fl[j]] += sum[u];
//        vis[u] = 1;
//    }
//}
//int main(){
//    scanf("%d",&n);
//    for(int i = 1;i <= n;i ++){
//        scanf("%s",s[i]);
//        insert(s[i],i);
//    }
//    getfail();
//    for(int i = 1;i <= n;i ++){
//        if(!map[i]) query(s[i]);
//    }
//    for(int i = 1;i <= n;i ++){
//        if(!map[i]) printf("%d\n",ans[i]);
//        else printf("%d\n",ans[map[i]]);
//    }
//    return 0;
//}


//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<queue>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e5 + 10;
//char s[N],ss[N];
//int n,cnt,top;
//int ch[N][26],fail[N],fl[N];
//int stk1[N],stk2[N];
//
//void insert(char s[]){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        int v = s[i] - 'a';
//        if(!ch[u][v]) ch[u][v] = ++cnt;
//        u = ch[u][v];
//    }
//    fl[u] = strlen(s);
//}
//void getfail(){
//    queue<int> q;
//    for(int i = 0;i < 26;i ++){
//        if(ch[0][i]) q.push(ch[0][i]);
//    }
//    while(!q.empty()){
//        int u = q.front();
//        q.pop();
//        for(int i = 0;i < 26;i ++){
//            if(ch[u][i]){
//                fail[ch[u][i]] = ch[fail[u]][i];
//                q.push(ch[u][i]);
//            }
//            else ch[u][i] = ch[fail[u]][i];
//        }
//    }
//}
//
//void solve(char s[]){
//    int u = 0;
//    int i = 0;
//    while(i < strlen(s)){
//        int v = s[i] - 'a';
//        u = ch[u][v];
//        stk2[++ top] = u;
//        stk1[top] = i;
//        if(fl[u]){
//            top -= fl[u];
//            if(!top) u = 0;
//            else u = stk2[top];
//        }
//        i ++;
//    }
//
//}
//int main(){
//    scanf("%s",s);
//    scanf("%d",&n);
//    for(int i = 0;i < n;i ++){
//        scanf("%s",ss);
//        insert(ss);
//    }
//    getfail();
//    solve(s);
//    for(int i = 1;i <= top;i ++)
//        printf("%c",s[stk1[i]]);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<queue>
//
//using namespace std;
//const int N = 2e5 + 10;
//int cnt,m;
//int ch[N][26],fail[N],fl[N],bo[N];
//char s[N],st[N];int tot,top;
//
//void insert(char s[],int x){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        int v = s[i] - 'a';
//        if(!ch[u][v]) ch[u][v] = ++ cnt;
//        u = ch[u][v];
//    }
//    bo[u] = x;
//    fl[x] = u;
//}
//
//void getfail(){
//    queue<int> q;
//    for(int i = 0;i < 26;i ++) if(ch[0][i]) q.push(ch[0][i]);
//    while(!q.empty()){
//        int u = q.front();q.pop();
//        for(int i = 0;i < 26;i ++){
//            if(ch[u][i]) fail[ch[u][i]] = ch[fail[u]][i],q.push(ch[u][i]);
//            else ch[u][i] = ch[fail[u]][i];
//        }
//    }
//}
//
//void solve(int x,int y){
//
//}
//int main(){
//    scanf("%s",s);
//    for(int i = 0;s[i];i ++){
//        if(s[i] == 'P'){
//            st[top ++] = '\0';
//            insert(st,++ tot);
//            top = 0;
//        }
//        else if(s[i] == 'B')top --;
//        else st[top ++] = s[i];
//    }
//    scanf("%d",&m);
//    for(int i = 0;i < m;i ++){
//        int x,y;
//        scanf("%d%d",&x,&y);
//    }
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 2e6 + 10;
//struct E{
//    int next,w,to;
//}e[N];
//int head[N],tot;
//int sum[N];int n;
//void addedge(int u,int v,int w){
//    e[++tot].next = head[u];
//    head[u] = tot;
//    e[tot].to = v;
//    e[tot].w = w;
//}
//
//void dfs(int u,int fa){
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;int w = e[i].w;
//        if(v != fa){
//            sum[v] = sum[u] ^ w;
//            dfs(v,u);
//        }
//    }
//}
//
//int ch[N][2],cnt;
//void buildtrie(int x){
//    int u = 0;
//    for(int i = (1 << 30);i;i >>= 1){
//        bool c = x & i;
//        if(!ch[u][c]) ch[u][c] = ++ cnt;
//        u = ch[u][c];
//    }
//}
//
//int query(int x){
//    int u = 0;
//    int ans = 0;
//    for(int i = (1 << 30);i;i >>= 1){
//        bool c = x & i;
//        if(ch[u][!c]){
//            ans += i;
//            u = ch[u][!c];
//        }
//        else u = ch[u][c];
//    }
//    return ans;
//}
//int main(){
//    scanf("%d",&n);
//    for(int i = 0;i < n;i ++){
//        int u,v,w;
//        scanf("%d%d%d",&u,&v,&w);
//        addedge(u,v,w);
//        addedge(v,u,w);
//    }
//    dfs(1,-1);
//    for(int i = 1;i <= n;i ++) buildtrie(sum[i]);
//    int ans = 0;
//    for(int i = 1;i <= n;i ++){
//        ans = max(ans,query(sum[i]));
//    }
//    printf("%d\n",ans);
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 2e6 + 10;
//struct E{
//    int next,to,w;
//}e[N];
//int head[N],tot = -1;
//void add(int u,int v,int w){
//    e[++tot].next = head[u];
//    head[u] = tot;
//    e[tot].to = v;
//    e[tot].w = w;
//}
//int sum[N];
//void dfs(int u,int fa){
//    for(int i = head[u];~i;i = e[i].next){
//        int v = e[i].to,w = e[i].w;
//        if(v != fa){
//            sum[v] = sum[u] ^ w;
//            dfs(v,u);
//        }
//    }
//}
//
//int ch[N][2],cnt;
//void insert(int x){
//    int u = 0;
//    for(int i = (1 << 30);i;i >>= 1){
//        bool c = x & i;
//        if(!ch[u][c]) ch[u][c] = ++cnt;
//        u = ch[u][c];
//    }
//}
//
//int query(int x){
//    int u = 0;
//    int ans = 0;
//    for(int i = (1 << 30);i;i >>= 1){
//        bool c = x & i;
//        if(ch[u][!c]){
//            ans += i;
//            u = ch[u][!c];
//        }
//        else u = ch[u][c];
//    }
//    return ans;
//}
//int main(){
//    memset(head,-1,sizeof(head));
//    int n;
//    scanf("%d",&n);
//    for(int i = 1;i < n;i ++){
//        int u,v,w;
//        scanf("%d%d%d",&u,&v,&w);
//        add(u,v,w);
//        add(v,u,w);
//    }
//    dfs(1,-1);
//    for(int i = 1;i <= n;i ++) insert(sum[i]);
//    int ans = 0;
//    for(int i = 1;i <= n;i ++){
//        ans = max(ans,query(sum[i]));
//    }
//    printf("%d\n",ans);
//    return 0;
//}

//#include<cstdio>
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//const int N = 2e6 + 10;
//char s[N];
//int head[N],tot;
//int ch[N][26],fail[N],cnt,fl[N],sum[N];
//struct E{
//    int next,to;
//}e[N];
//void insert(char s[],int x){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        int v = s[i] - 'a';
//        if(!ch[u][v]) ch[u][v] = ++ cnt;
//        u = ch[u][v];
//    }
//    fl[x] = u;
//}
//
//void getfail(){
//    queue<int> q;
//    for(int i = 0;i < 26;i ++) if(ch[0][i]) q.push(ch[0][i]);
//    while(!q.empty()){
//        int u = q.front();q.pop();
//        for(int i = 0;i < 26;i ++){
//            if(ch[u][i]){
//                fail[ch[u][i]] = ch[fail[u]][i];
//                q.push(ch[u][i]);
//            }
//            else ch[u][i] = ch[fail[u]][i];
//        }
//    }
//}
//
//void query(char s[]){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        u = ch[u][s[i] - 'a'];
//        sum[u] ++;
//    }
//}
//
//void add(int u,int v){
//    e[++ tot].next = head[u];
//    head[u] = tot;
//    e[tot].to = v;
//}
//
//void dfs(int u){
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        dfs(v);
//        sum[u] += sum[v];
//    }
//}
//int n;
//int main(){
//    scanf("%d",&n);
//    for(int i = 1;i <= n;i ++){
//        scanf("%s",s);
//        insert(s,i);
//    }
//    getfail();
//    scanf("%s",s);
//    query(s);
//    for(int i = 1;i <= cnt;i ++) add(fail[i],i);
//    dfs(0);
//    for(int i = 1;i <= n;i ++) printf("%d\n",sum[fl[i]]);
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//const int N = 1e5 + 10;
//char s[N],ss[N];
//int n,cnt,top;
//int ch[N][26],fail[N],fl[N];
//int stk1[N],stk2[N];
//
//void insert(char s[]){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        int v = s[i] - 'a';
//        if(!ch[u][v]) ch[u][v] = ++ cnt;
//        u = ch[u][v];
//    }
//    fl[u] = strlen(s);
//}
//
//void getfail(){
//    queue<int> q;
//    for(int i = 0;i < 26;i ++) if(ch[0][i]) q.push(ch[0][i]);
//    while(!q.empty()){
//        int u = q.front();q.pop();
//        for(int i = 0;i < 26;i ++){
//            if(ch[u][i]){
//                fail[ch[u][i]] = ch[fail[u]][i];
//                q.push(ch[u][i]);
//            }
//            else ch[u][i] = ch[fail[u]][i];
//        }
//    }
//}
//
//void solve(char s[]){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        int v = s[i] - 'a';
//        u = ch[u][v];
//        stk2[++ top] = u;
//        stk1[top] = i;
//        if(fl[u]){
//            top -= fl[u];
//            if(!top) u = 0;
//            else u = stk2[top];
//        }
//    }
//}
//
//int main(){
//    scanf("%s",s);
//    scanf("%d",&n);
//    for(int i = 0;i < n;i ++){
//        scanf("%s",ss);
//        insert(ss);
//    }
//    getfail();
//    solve(s);
//    for(int i = 1;i <= top;i ++) printf("%c",s[stk1[i]]);
//    return 0;
//}


//void insert(char s[]){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        int v = s[i] - 'a';
//        if(!ch[u][v]) ch[u][v] = ++ cnt;
//        u = ch[u][v];
//    }
//}
//
//void getfail(){
//    queue<int> q;
//    for(int i = 0;i < 26;i ++) if(ch[0][i]) q.push(ch[0][i]);
//    while(!q.empty()){
//        int u = q.front();q.pop();
//        for(int i = 0;i < 26;i ++){
//            if(ch[u][i]){
//                fail[ch[u][i]] = ch[fail[u]][i];
//                q.push(ch[u][i]);
//            }
//            else ch[u][i] = ch[fail[u]][i];
//        }
//    }
//}
//void query(char s[]){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        u = ch[u][s[i] - 'a'];
//        for(int j = u;j;j = fail[j]) ...
//    }
//}