//
// Created by 19116 on 2021/2/26.
//

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 5e6 + 10;
//int ch[N][26],cnt,fl[N],mx[N];
//int n;
//char s[30],a[30];char t[N];
//char ans[N],tot,print;
//
//void insert(char s[]){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        int v = s[i] - 'a';
//        if(!ch[u][v]) ch[u][v] = ++ cnt;
//        t[ch[u][v]] = v + 'a';
//        u = ch[u][v];
//    }
//    fl[u] = 1;
//}
//
//void dfs(char s[]){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        u = ch[u][s[i] - 'a'];
//        mx[u] = 1;
//    }
//}
//
//void solve(int u){
//    if(fl[u]){
//        print ++;
//        ans[tot ++] = 'P';
//    }
//    if(print == n){
//        printf("%d\n",tot);
//        for(int i = 0;i < tot;i ++){
//            printf("%c\n",ans[i]);
//        }
//        return ;
//    }
//
//    for(int i = 0;i < 26;i ++){
//        if(!mx[ch[u][i]] && ch[u][i]){
//            ans[tot ++] = t[ch[u][i]];
//            solve(ch[u][i]);
//            ans[tot ++] = '-';
//        }
//    }
//
//    for(int i = 0;i < 26;i ++){
//        if(mx[ch[u][i]] && ch[u][i]){
//            ans[tot ++] = t[ch[u][i]];
//            solve(ch[u][i]);
//            ans[tot ++] = '-';
//        }
//    }
//}
//
//
//int main(){
//    scanf("%d",&n);
//    int mxl = 0;
//    for(int i = 0;i < n;i ++){
//        scanf("%s",s);
//        insert(s);
//        if(mxl < strlen(s)){
//            mxl = strlen(s);
//            for(int j = 0;j <= strlen(s);j ++){
//                a[j] = s[j];
//            }
//        }
//    }
//    dfs(a);
//    solve(0);
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 5e6 + 10;
//int ch[N][26],cnt,fl[N],mx[N];
//string s,a,ss;char t[N];
//int n,tot;
//
//template <class T>
//inline void read(T& x){
//    x = 0;int f = 1;
//    char c = getchar();
//    while(!isdigit(c)){
//        if(c == '-') f = -1;
//        c = getchar();
//    }
//    while(isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48),c = getchar();
//    x *= f;
//}
//
//void insert(string s){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        int v = s[i] - 'a';
//        if(!ch[u][v]) ch[u][v] = ++ cnt;
//        u = ch[u][v];
//        t[u] = v + 'a';
//    }
//    fl[u] = 1;
//}
//
//void dfs(string a){
//    int u = 0;
//    for(int i = 0;a[i];i ++){
//        u = ch[u][a[i] - 'a'];
//        mx[u] = 1;
//    }
//}
//
//void solve(int u){
//    if(fl[u]){
//        tot ++;
//        ss += 'P';
//    }
//    if(tot == n){
//        cout << ss.size() << endl;
//        for(int i = 0;ss[i];i ++){
//            cout << ss[i] << endl;
//        }
//        return;
//    }
//
//    for(int i = 0;i < 26;i ++){
//        if(ch[u][i] && !mx[ch[u][i]]){
//            ss += t[ch[u][i]];
//            solve(ch[u][i]);
//            ss += '-';
//        }
//    }
//    for(int i = 0;i < 26;i ++){
//        if(ch[u][i] && mx[ch[u][i]]){
//            ss += t[ch[u][i]];
//            solve(ch[u][i]);
//            ss += '-';
//        }
//    }
//}
//int main(){
//    read(n);
//    int mxl = 0;
//    for(int i = 0;i < n;i ++){
//        cin >> s;
//        insert(s);
//        if(mxl < s.size()){
//            mxl = s.size();
//            a = s;
//        }
//    }
//    dfs(a);
//    solve(0);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 3e5 + 10;
//int ch[N][26],cnt,fl[N];
//char s[N];
//void insert(char s[]){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        bool v = s[i] - '0';
//        if(!ch[u][v]) ch[u][v] = ++ cnt;
//        u = ch[u][v];
//        fl[u] = 1;
//    }
//}
//
//bool dfs(){
//    int u = 0;
//    for(int i = 0;i < 2;i ++){
//
//    }
//}
//
//int n;
//int main(){
//    scanf("%d",&n);
//    for(int i = 0;i < n;i ++){
//        scanf("%s",s);
//        insert(s);
//    }
//    return 0;
//}
//
//


//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//const int N = 3e5 + 10;
//int ch[N][2],cnt,fail[N],fl[N];
//bool vis[N],in[N],flag;
//char s[N];
//void insert(char s[]){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        bool v = s[i] - '0';
//        if(!ch[u][v]) ch[u][v] = ++ cnt;
//        u = ch[u][v];
//    }
//    fl[u] = 1;
//}
//
//void getfail(){
//    queue<int> q;
//    for(int i = 0;i < 2;i ++) if(ch[0][i]) q.push(ch[0][i]);
//    while(!q.empty()){
//        int u = q.front();q.pop();
//        for(int i = 0;i < 2;i ++){
//            if(ch[u][i]){
//                fail[ch[u][i]] = ch[fail[u]][i];
//                fl[ch[u][i]] |= fl[fail[ch[u][i]]];
//                q.push(ch[u][i]);
//            }
//            else ch[u][i] = ch[fail[u]][i];
//        }
//    }
//}
//
//void dfs(int u){
//    if(in[u]){
//        flag = 1;
//        return;
//    }
//    if(vis[u] || fl[u]) return;
//    in[u] = vis[u] = 1;
//    dfs(ch[u][0]);
//    dfs(ch[u][1]);
//    in[u] = 0;
//}
//int n;
//int main(){
//    scanf("%d",&n);
//    for(int i = 0;i < n;i ++){
//        scanf("%s",s);
//        insert(s);
//    }
//    getfail();
//    flag = 0;
//    dfs(0);
//    if(flag) puts("TAK");
//    else puts("NIE");
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//const int N = 2e6 + 10;
//struct PAM_t{
//    int ch[26];
//    int fail,len,num;
//};
//
//struct PAM{
//    PAM_t b[N];
//    char s[N];
//    int cur,cnt,n;
//    PAM(){
//        b[0].len = 0,b[1].len = -1;
//        b[0].fail = 1,b[1].fail = 0;
//        cur = 0;
//        cnt = 1;
//    }
//    void read(){
//        scanf("%s",s);
//    }
//    int getfail(int x){
//        while(s[n - b[x].len - 1] != s[n] || n - b[x].len - 1 < 0)
//            x = b[x].fail;
//        return x;
//    }
//    void insert(){
//        int pre = getfail(cur);
//        if(!b[pre].ch[s[n]]){
//            b[++ cnt].len = b[pre].len + 2;
//            int tmp = getfail(b[pre].fail);
//            b[cnt].fail = b[tmp].ch[s[n]];
//            b[cnt].num = b[b[cnt].fail].num + 1;
//            b[pre].ch[s[n]] = cnt;
//        }
//        cur = b[pre].ch[s[n]];
//    }
//
//    void solve(){
//        int k = 0;
//        for(n = 0;s[n];n ++){
//            s[n] = (s[n] - 97 + k) % 26 + 97;
//            s[n] -= 'a';
//            insert();
//            printf("%d ",b[cur].num);
//            k = b[cur].num;
//        }
//    }
//}P;
//int main(){
//    P.read();
//    P.solve();
//    return 0;
//}

//#include<cstdio>
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 2e5 + 10;
//
//struct PAM_t{
//    int ch[26],fail,len,num;
//};
//
//struct PAM{
//    PAM_t b[N];
//    char s[N];
//    int cur,n,cnt;
//    PAM(){
//        b[0].len = 0,b[1].len = -1;
//        b[0].fail = 1,b[1].fail = 0;
//        cnt = 1;
//        cur = 0;
//    }
//    void read(){
//        scanf("%s",s);
//    }
//    int getfail(int x){
//        while(s[n - b[x].len - 1] != s[n] || n - b[x].len - 1 < 0) x = b[x].fail;
//        return x;
//    }
//
//    void insert(){
//        int pre = getfail(cur);
//        if(!b[pre].ch[s[n]]){
//            b[++ cnt].len = b[pre].len + 2;
//            int tmp = getfail(b[pre].fail);
//            b[cnt].fail = b[tmp].ch[s[n]];
//            b[cnt].num = b[b[cnt].fail].num + 1;
//            b[pre].ch[s[n]] = cnt;
//        }
//        cur = b[pre].ch[s[n]];
//    }
//
//    void solve(){
//        int k = 0;
//        for(n = 0;s[n];n ++){
//            s[n] = (s[n] - 97 + k) % 26 + 97;
//            s[n] -= 'a';
//            insert();
//            printf("%d ",b[cur].num);
//            k = b[cur].num;
//        }
//    }
//}P;
//int main(){
//    P.read();
//    P.solve();
//    return 0;
//}

//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<iostream>
//
//using namespace std;
//const int N = 2e6 + 10;
//struct PAM_T{
//    int ch[26],fail,len,num;
//};
//
//struct PAM{
//    PAM_T b[N];
//    char s[N];
//    int cnt,n,cur;
//    PAM(){
//        b[0].len = 0,b[1].len = -1;
//        b[0].fail = 1,b[1].fail = 0;
//        cnt = 1;
//        cur = 0;
//    }
//    void read(){
//        scanf("%s",s);
//    }
//    int getfail(int x){
//        while(s[n - b[x].len - 1] != s[n]) x = b[x].fail;
//        return x;
//    }
//    void insert(){
//        int pre = getfail(cur);
//        if(!b[pre].ch[s[n]]){
//            b[++ cnt].len = b[pre].len + 2;
//            int tmp = getfail(b[pre].fail);
//            b[cnt].fail = b[tmp].ch[s[n]];
//            b[pre].ch[s[n]] = cnt;
//        }
//        cur = b[pre].ch[s[n]];
//        b[cur].num ++;
//    }
//    void solve(){
//        for(n = 0;s[n];n ++){
//            s[n] -= 'a';
//            insert();
//        }
//        long long ans = 0;
//        for(int i = cnt;i;i --){
//            b[b[i].fail].num += b[i].num;
//            if(b[i].num * 1ll * b[i].len > ans) ans = b[i].num * 1ll * b[i].len;
//        }
//        printf("%lld\n",ans);
//    }
//}P;
//int main(){
//    P.read();
//    P.solve();
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 2e6 + 10;
//struct PAM_T{
//    int ch[26],fail,len,trans;
//};
//struct PAM{
//    PAM_T b[N];char s[N];
//    int cnt,n,cur,length;
//    PAM(){
//        b[0].len = 0,b[1].len = -1;
//        b[0].fail = 1,b[1].fail = 0;
//        cnt = 1;
//        cur = 0;
//    }
//    void read(){
//        scanf("%d",&length);
//        scanf("%s",s);
//    }
//    int getfail(int x){
//        while(s[n - b[x].len - 1] != s[n]) x = b[x].fail;
//        return x;
//    }
//    void insert(){
//        int p = getfail(cur);
//        if(!b[p].ch[s[n]]){
//            b[++ cnt].len = b[p].len + 2;
//            int tmp = getfail(b[p].fail);
//            b[cnt].fail = b[tmp].ch[s[n]];
//            b[p].ch[s[n]] = cnt;
//            if(b[cnt].len <= 2) b[cnt].trans = b[cnt].fail;
//            else{
//                int tmp = b[p].trans;
//                while(s[n - b[tmp].len - 1] != s[n] || (b[tmp].len + 2) * 2 > b[cnt].len) tmp = b[tmp].fail;
//                b[cnt].trans = b[tmp].ch[s[n]];
//            }
//        }
//        cur = b[p].ch[s[n]];
//    }
//    void solve(){
//        for(n = 0;s[n];n ++){
//            s[n] -= 'a';
//            insert();
//        }
//        int ans = 0;
//        for(int i = 2;i <= cnt;i ++){
//            if(b[b[i].trans].len * 2 == b[i].len && b[i].len % 4 == 0) ans = max(ans,b[i].len);
//        }
//        printf("%d\n",ans);
//    }
//}P;
//int main(){
//    P.read();
//    P.solve();
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 5e5 + 10;
//int ch[N][26],fail[N],len[N],trans[N];
//int n,cnt,ans,cur;
//char s[N];
//int getfail(int x,int i){
//    while(s[i - len[x] - 1] != s[i]) x = fail[x];
//    return x;
//}
//
//void build(){
//    for(int i = 0;s[i];i ++){
//        int x = s[i] - 'a';
//        int p = getfail(cur,i);
//        if(!ch[p][x]){
//            len[++ cnt] = len[p] + 2;
//            fail[cnt] = ch[getfail(fail[p],i)][x];
//            ch[p][x] = cnt;
//            if(len[cnt] <= 2) trans[cnt] = fail[cnt];
//            else{
//                int tmp = trans[p];
//                while(s[i - 1 - len[tmp]] != s[i] || (len[tmp] + 2) * 2 > len[cnt]) tmp = fail[tmp];
//                trans[cnt] = ch[tmp][x];
//            }
//        }
//        cur = ch[p][x];
//    }
//}
//int main(){
//    scanf("%d",&n);
//    scanf("%s",s);
//    fail[0] = 1,fail[1] = 0;
//    len[0] = 0,len[1] = -1;
//    cur = 0,cnt = 1;
//    build();
//    for(int i = 2;i <= cnt;i ++){
//        if((len[trans[i]] * 2) == len[i] && len[i] % 4 == 0)
//            ans = max(ans,len[i]);
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
//const int N = 1e6 + 10;
//char s[N];
//int y[N];//第二关键字排名为i的数，第一关键字的位置
//int x[N];//第一关键字
//int c[N];//桶
//int sa[N];//排名为i的后缀的起始位置的下标
//int rk[N];//起始位置为i的后缀的排名
//int n,m;
//inline void getsa(){
//    for(int i = 1;i <= n;i ++) c[x[i] = s[i]] ++;
//    for(int i = 2;i <= m;i ++) c[i] += c[i - 1];
//    for(int i = n;i >= 1;i --) sa[c[x[i]] --] = i;
//    for(int k = 1;k <= n;k <<= 1){
//        int num = 0;
//        for(int i = n - k + 1;i <= n;i ++) y[++ num] = i;
//
//        for(int i = 1;i <= n;i ++) if(sa[i] > k) y[++ num] = sa[i] - k;
//
//        for(int i = 1;i <= m;i ++) c[i] = 0;
//
//        for(int i = 1;i <= n;i ++) c[x[i]] ++;
//
//        for(int i = 2;i <= m;i ++) c[i] += c[i - 1];
//
//        for(int i = n;i >= 1;i --) sa[c[x[y[i]]] --] = y[i],y[i] = 0;
//
//        swap(x,y);
//
//        x[sa[1]] = 1,num = 1;
//        for(int i = 2;i <= n;i ++){
//            x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? num : ++ num;
//        }
//
//        if(num == n) break;
//
//        m = num;
//    }
//    for(int i = 1;i <= n;i ++) printf("%d ",sa[i]);
//}
//int main(){
//
//    return 0;
//}


//#include<iostream>
//#include<string>
//
//using namespace std;
//
//class CPU{
//public:
//
//    virtual void calculate() = 0;
//};
//class Showcard{
//public:
//    virtual void show() = 0;
//};
//class memory{
//public:
//    virtual void cunchu() = 0;
//};
//
//class computer{
//public:
//    Computer(){
//        m_cpu =
//    }
//private:
//    CPU* m_cpu;
//    Showcard* m_vc;
//    memory* mem;
//};
//int main(){
//
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//int main(){
//    string s;
//    cin >> s;
//    s += "$";
//    int n = s.size();
//    vector<int> p(n),c(n);
//
//    vector<pair<char,int> > a(n);
//    for(int i = 0;i < n;i ++) a[i] = {s[i],i};
//    sort(a.begin(),a.end());
//
//    for(int i = 0;i < n;i ++) p[i] = a[i].second;
//    c[p[0]] = 0;
//    for(int i = 1;i < n;i ++) {
//        if (a[i].first == a[i - 1].first) {
//            c[p[i]] = c[p[i - 1]];
//        } else c[p[i]] = c[p[i - 1]] + 1;
//    }
//
//    int k = 0;
//    while((1 << k) < n){
//        vector<pair<pair<int,int> ,int > > a(n);
//        for(int i = 0;i < n;i ++){
//            a[i] = {{c[i],c[(i + (1 << k)) % n]},i};
//        }
//        sort(a.begin(),a.end());
//
//        for(int i = 0;i < n;i ++) p[i] = a[i].second;
//        c[p[0]] = 0;
//        for(int i = 1;i < n;i ++){
//            if(a[i].first == a[i - 1].first){
//                c[p[i]] = c[p[i - 1]];
//            }
//            else c[p[i]] = c[p[i - 1]] + 1;
//        }
//        k ++;
//    }
//    for(int i = 1;i < n;i ++) cout << p[i] + 1 << " ";
//    return 0;
//}
const int N = 2e5 + 10;
struct PAM_T{
    int ch[26],fail,len,num,trans;
};
struct PAM{
    PAM_T b[N];
    char s[N];
    int cur,n,cnt;
    PAM(){
        b[0].len = 0,b[1].len = -1;
        b[0].fail = 1,b[1].fail = 0;
        cnt = 1;
        cur = 0;
    }
    void read(){
        scanf("%s",s + 1);
    }
    int getfail(int x){
        while(s[n - b[x].len - 1] == s[n]) x = b[x].fail;
        return x;
    }

    void insert(){
        int p = getfail(cur);
        int x = s[n] - 'a';
        if(!b[p].ch[x]){
            b[++ cnt].len = b[p].len + 1;
            int tmp = getfail(b[p].fail);
            b[cnt].fail = b[tmp].ch[x];
            b[p].ch[x] = cnt;
            if(b[cnt].len <= 2) b[cnt].trans = b[cnt].fail;
            else{
                int tmp = b[p].trans;
                while(s[n - b[tmp].len - 1] != s[n] || (b[tmp].len + 2) * 2 > b[cnt].len) tmp = b[tmp].fail;
                b[cnt].trans = b[tmp].ch[x];
            }
        }
        cur = b[p].ch[x];
        b[cur].num ++;
    }
}P;