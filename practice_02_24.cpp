//
// Created by 19116 on 2021/2/24.
//

//#include<iostream>
//
//using namespace std;
//
//class Person{
//public:
//    Person(int a) : age(a){}
//    Person& add(Person& b){
//        this -> age += b.age;
//        return *this;
//    }
//    int age;
//};
//void test(){
//    Person p1(10);
//    Person p2(10);
//    p2.add(p1).add(p1).add(p1);
//    cout << p2.age << endl;
//}
//int main(){
//    test();
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//class Person{
//    friend void test();
//    friend ostream & operator<<(ostream &cout,Person &p);
//    Person(int a = 0,int b = 0) : a(a),b(b){}
//    int a,b;
//};
//ostream & operator<<(ostream &cout,Person &p){
//    cout << p.a << " " << p.b;
//    return cout;
//}
//void test(){
//    Person p1(10,10);
//    cout << p1 << endl;
//};
//int main(){
//    test();
//    return 0;
//}


//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 5e5 + 10,INF = 0x3f3f3f3f;
//char s[N],tmp[N];
//int ne1[N],ne2[N];
//void getnext(char a[],int ne[]){
//    int len = strlen(a);
//    int j = 0,k = -1;
//    ne[j] = k;
//    while(j < len){
//        if(k == -1 || a[j] == a[k]) ne[++ j] = ++ k;
//        else k = ne[k];
//    }
//}
//int pos[N],tot;
//void KMP(char a[],char b[]){
//    int i = 0,j = 0;
//    int la = strlen(a),lb = strlen(b);
//    while(i < la && j < lb){
//        if(j == -1 || a[i] == b[j]) i ++, j ++;
//        else j = ne2[j];
//        if(j == lb){
//            pos[tot ++] = i - lb;
//            j = ne2[j];
//        }
//    }
//}
//int ans = INF;
//int main(){
//    scanf("%s",s);
//    getnext(s,ne1);
//    int n = strlen(s);
//    while(ne1[n]){
//        n = ne1[n];
//        for(int i = 0;i < n;i ++) tmp[i] = s[i];
//        tmp[n] = '\0';
////        cout << strlen(tmp) << endl;
//        getnext(tmp,ne2);
//        tot = 0;
//        KMP(s,tmp);
//        int flag = 1;
//        for(int i = 0;i < tot - 1;i ++){
//            if(pos[i + 1] - pos[i] > n) flag = 0;
//        }
//        if(flag) ans = min(ans,n);
//    }
//    printf("%d\n",ans);
//    return 0;
//}

//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 5e5 + 10;
//int n;int ne[N];
//int f[N],t[N];
//char s[N];
//int main(){
//    scanf("%s",s + 1);
//    n = strlen(s + 1);
//    int flag = 1;
//    for(int i = 1;i < n;i ++){
//        if(s[i] != s[i + 1]) flag = 0;
//    }
//    if(flag){
//        puts("1");
//        return 0;
//    }
//    for(int i = 2,j = 0;i <= n;i ++){
//        while(j && s[i] != s[j + 1]) j = ne[j];
//        if(s[i] == s[j + 1]) j ++;
//        ne[i] = j;
//    }
//    f[1] = 1;
//    for(int i = 2;i <= n;i ++){
//        f[i] = i;
//        if(t[f[ne[i]]] >= i - ne[i]) f[i] = f[ne[i]];
//        t[f[i]] = i;
//    }
//    printf("%d\n",f[n]);
//    return 0;
//}

//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e5 + 10;
//char s[N << 1];int cnt;
//void read(){
//    char c = getchar();
//    s[0] = '~';
//    s[1] = '|';
//    cnt = 1;
//    while(c < 'a' || c > 'z') c = getchar();
//    while(c >= 'a' && c <= 'z') s[++ cnt] = c,s[++ cnt] = '|',c = getchar();
//}
//int r[N << 1];
//int ll[N << 1],rr[N << 1];
//void manacher(){
//    int rb = 0,mid = 0;
//    for(int i = 1;i <= cnt;i ++){
//        if(i < rb) r[i] = min(r[mid * 2 - i],rb - i);
//        while(s[i - r[i]] == s[i + r[i]]) r[i] ++;
//        if(r[i] + i > rb) rb = r[i] + i,mid = i;
//        ll[i + r[i] - 1] = max(ll[i + r[i] - 1],r[i] - 1);
//        rr[i - r[i] + 1] = max(ll[i - r[i] + 1],r[i] - 1);
//    }
//}
//int ans;
//int main(){
//    read();
//    manacher();
//    for(int i = 2;i <= cnt;i ++)
//        rr[i] = max(rr[i],rr[i - 2] - 2);
//    for(int i = cnt;i >= 2;i --){
//        ll[i] = max(ll[i],ll[i + 2] - 2);
//    }
//    for(int i = 2;i <= cnt;i ++)
//        if(rr[i] && ll[i]) ans = max(ans,ll[i] + rr[i]);
//    printf("%d\n",ans);
//    return 0;
//}

//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 1.1e7 + 10;
//char s[N << 1];
//int r[N << 1];
//int mid,rb;
//int cnt;
//void read(){
//    char c = getchar();
//    s[0] = '~',s[1] = '|';
//    cnt = 1;
//    while(c < 'a' || c > 'z') c = getchar();
//    while(c >= 'a' && c <= 'z') s[++ cnt] = c,s[++ cnt] = '|',c = getchar();
//}
//void manacher(){
//    mid = 0,rb = 0;
//    for(int i = 1;i <= cnt;i ++){
//        if(i < rb) r[i] = min(r[mid * 2 - 1],rb - i);
//        while(s[i + r[i]] == s[i - r[i]]) r[i] ++;
//        if(r[i] + i > rb) rb = r[i] + i,mid = i;
//    }
//}
//int main(){
//    read();
//    manacher();
//    int ans = 0;
//    for(int i = 1;i <= cnt;i ++){
//        ans = max(ans,r[i]);
//    }
//    printf("%d\n",ans - 1);
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 11000010;
//char s[N << 1];
//int p[N << 1],cnt,ans;
//void read(){
//    char c = getchar();
//    s[0] = '~',s[cnt = 1] = '|';
//    while(c < 'a' || c > 'z') c = getchar();
//    while(c >= 'a' && c <= 'z') s[++ cnt] = c,s[++ cnt] = '|',c = getchar();
//}
//void manacher(){
//    int r = 0,mid = 0;
//    for(int i = 1;i <= cnt;i ++){
//        if(i < r) p[i] = min(p[mid * 2 - i],r - i);
//        while(s[i + p[i]] == s[i - p[i]]) p[i] ++;
//        if(i + p[i] > r) r = i + p[i],mid = i;
//        ans = max(ans,p[i]);
//    }
//}
//int main(){
//    read();
//    manacher();
//    printf("%d\n",ans - 1);
//    return 0;
//}

//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 1e5 + 10;
//char s[N << 1];
//int p[N << 1],ll[N << 1],rr[N << 1];
//int ans,cnt;
//void read() {
//    char c = getchar();
//    s[++ cnt] = '~', s[++ cnt] = '|';
//    while (c < 'a' || c > 'z') c = getchar();
//    while (c >= 'a' && c <= 'z') s[++cnt] = c, s[++cnt] = '|', c = getchar();
//    s[++ cnt] = '\0';
//}
//void manacher(){
//    int mid = 0,r = 0;
//    for(int i = 1;i <= cnt;i ++){
//        if(i < r) p[i] = min(p[mid * 2 - i], r - i);
//        while(s[i + p[i]] == s[i - p[i]]) p[i] ++;
//        if(i + p[i] > r) r = i + p[i],mid = i;
//        ll[i + p[i] - 1] = max(ll[i + p[i] - 1],p[i] - 1);
//        rr[i - p[i] + 1] = max(rr[i - p[i] + 1],p[i] - 1);
//    }
//}
//int main(){
//    read();
//    manacher();
//    for(int i = 2;i <= cnt;i += 2) rr[i] = max(rr[i],rr[i - 2] - 2);
//    for(int i = cnt;i >= 2;i -= 2) ll[i] = max(ll[i],ll[i + 2] - 2);
//    for(int i = 2;i <= cnt;i += 2) if(rr[i] && ll[i]) ans = max(ans,ll[i] + rr[i]);
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
//const int mod = 19930726;
//typedef long long ll;
//int n;ll k;
//char s[N << 1];
//int p[N << 1];
//int cnt;int tot[N];
//ll ans = 1;
//void read(){
//    char c = getchar();
//    s[0] = '~',s[cnt = 1] = '|';
//    while(c < 'a' || c > 'z') c = getchar();
//    while(c >= 'a' && c <= 'z') s[++ cnt] = c,s[++ cnt] = '|',c = getchar();
//}
//ll qpow(ll a,int b){
//    ll ans = 1;
//    while(b){
//        if(b & 1) ans = ans * a % mod;
//        a = a * a % mod;
//        b >>= 1;
//    }
//    return ans;
//}
//void manacher(){
//    int mid = 0,r = 0;
//    for(int i = 1;i <= cnt;i ++){
//        if(i < r) p[i] = min(p[mid * 2 - i], r - i);
//        while(s[i + p[i]] == s[i - p[i]]) p[i] ++;
//        if(i + p[i] > r) r = i + p[i],mid = i;
//        if((p[i] - 1) % 2) tot[p[i] - 1] ++;
//    }
//}
//int main(){
//    scanf("%d%lld",&n,&k);
//    read();
//    manacher();
//    int sum = 0;
//    for(int i = n;i >= 1;i --){
//        if(i % 2 == 0) continue;
//        sum += tot[i];
//        if(k >= sum){
//            ans = (ans * qpow(i,sum)) % mod;
//            k -= sum;
//        }
//        else {
//            ans = (ans * qpow(i,k)) % mod;
//            k -= sum;
//            break;
//        }
//    }
//    if(k > 0) ans = -1;
//    printf("%lld\n",ans);
//    return 0;
//}

//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<bitset>
//#include<iostream>
//
//using namespace std;
//const int N = 1e4 + 10;
//const int M = 5e5 + 10;
//char s[N];
//int ne[M][26],n,cnt = 0;
//bitset<1001> vis[N];
//void insert(int x){
//    scanf("%s",s + 1);
//    int u = 0;
//    for(int i = 1;s[i];i ++){
//        int v = s[i] - 'a';
//        if(!ne[u][v]) ne[u][v] = ++cnt;
//        u = ne[u][v];
//    }
//    vis[u][x] = 1;
//}
//
//void check(){
//    scanf("%s",s + 1);
//    int u = 0,flag = 1;
//    for(int i = 1;s[i];i ++){
//        int v = s[i] - 'a';
//        if(!ne[u][v]){
//            flag = 0;break;
//        }
//        u = ne[u][v];
//    }
//    if(flag){
//        for(int i = 1;i <= n;i ++){
//            if(vis[u][i]) printf("%d ",i);
//        }
//    }
//    puts("");
//}
//int main(){
//    scanf("%d",&n);
//    for(int i = 1;i <= n;i ++){
//        int x;scanf("%d",&x);
//        for(int j = 0;j < x;j ++) insert(i);
//    }
//    int m;scanf("%d",&m);
//    for(int i = 0;i < m;i ++) check();
//    return 0;
//}


//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<iostream>
//
//using namespace std;
//const int N = 1e6 + 10;
//char s[20],t[N];
//int ch[N][26],cnt;
//int n,m;
//void insert(){
//    scanf("%s",s);
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        int v = s[i] - 'a';
//        if(!ch[u][v]) ch[u][v] = ++cnt;
//        u = ch[u][v];
//    }
//}
//
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 0;i < n;i ++){
//        insert();
//    }
//    for(int i = 0;i < m;i ++){
//        scanf("%s",t);
//        for(int j = 0;j < strlen(t);j ++){
//
//        }
//    }
//    return 0;
//}

//#include<map>
//#include<cstring>
//#include<cstdio>
//#include<algorithm>
//#include<iostream>
//
//using namespace std;
//const int N = 1e6 + 10;
//char s[N << 4];
//int cnt,ch[1010][26];
//int n,m;
//bool flag[N];
//map<string,bool> m1;
//map<string,int> m2;
//
//inline int read(){
//    int ans = 0,f1 = 1;
//    char c = getchar();
//    while(c < '0' || c > '9'){
//        if(c == '-') f1 = -1;
//        c = getchar();
//    }
//    while(c >= '0' && c <= '9'){
//        ans = ans * 10 + c - '0';
//        c = getchar();
//    }
//    return ans * f1;
//}
//
//void insert(){
//    scanf("%s",s + 1);
//    int u = 0;
//    for(int i = 1;s[i];i ++){
//        int v = s[i] - 'a';
//        if(!ch[u][v]) ch[u][v] = ++cnt;
//        u = ch[u][v];
//    }
//    flag[u] = 1;
//}
//bool f[N << 1];
//int query(){
//    scanf("%s",s + 1);
//    if(m1[s + 1])return m2[s + 1];
//    memset(f,false,sizeof(f));
//    f[0] = true;int ans;
//    int len = strlen(s + 1);
//    for(int i = 0;i <= len;i ++){
//        if(!f[i]) continue;
//        else ans = i;
//        for(int j = i + 1,u = 0;s[j];j ++){
//            int v = s[j] - 'a';
//            u = ch[u][v];
//            if(!u) break;
//            if(flag[u]) f[j] = true;
//        }
//    }
//    m1[s + 1] = true;
//    m2[s + 1] = ans ;
//    return ans;
//}
//
//int main(){
//    n = read(),m = read();
//    for(int i = 0;i < n;i ++) insert();
//    for(int i = 0;i < m;i ++) printf("%d\n",query()) ;
//    return 0;
//}


//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<iostream>
//#include<queue>
//
//using namespace std;
//const int N = 1e4 + 10;
//int s[N];
//int m,n;
//int ch[500010][2],cnt;
//int sum[500010],bo[500010];
//void insert(int len){
//    int u = 0;
//    for(int i = 0;i < len;i ++){
//        if(ch[u][s[i]] == -1) ch[u][s[i]] = ++ cnt;
//        u = ch[u][s[i]];
//        sum[u] ++;
//    }
//    bo[u] ++;
//}
//int query(int len){
//    int ans = 0;
//    int u = 0;
//    for(int i = 0;i < len;i ++){
//        if(ch[u][s[i]] == -1) return ans;
//        u = ch[u][s[i]];
//        ans += bo[u];
//    }
//    return ans - bo[u] + sum[u];
//}
//int main(){
//    scanf("%d%d",&m,&n);
//    memset(ch,-1,sizeof(ch));
//    for(int i = 0;i < m;i ++) {
//        int x;
//        scanf("%d", &x);
//        for (int j = 0; j < x; j++) scanf("%d",&s[j]);
//        insert(x);
//    }
//    for(int i = 0;i < n;i ++){
//        int x;
//        scanf("%d",&x);
//        for(int j = 0;j < x;j ++)scanf("%d",&s[j]);
//        printf("%d\n",query(x));
//    }
//    return 0;
//}


//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<iostream>
//#include<queue>
//
//using namespace std;
//const int N = 3e4 + 10,M = 3e5 + 10;
//int n,ans;
//string s[N];
//bool ok[N];
//int tot,ch[M][26];
//int in[26],e[26][26];
//bool ed[M];
//template <class T>
//inline void read(T& res){
//    res = 0;
//    char c = getchar();
//    int f = 1;
//    while(c < '0' || c > '9'){
//        if(c == '-') f = -1;
//        c = getchar();
//    }
//    while(c >= '0' && c <= '9'){
//        res = res * 10 + c - '0';
//        c = getchar();
//    }
//    res *= f;
//}
//template<class T>
//inline void write(T& x){
//    if(x < 0){
//        putchar('-');
//        x = -x;
//    }
//    T y = 1;
//    int len = 1;
//    for(;y <= x / 10;y *= 10) len ++;
//    for(;len;len --,x %= y,y /= 10) putchar(x / y + '0');
//}
//void insert(string x){
//    int u = 0;
//    for(int i = 0;x[i];i ++){
//        int v = x[i] - 'a';
//        if(!ch[u][v]) ch[u][v] = ++ tot;
//        u = ch[u][v];
//    }
//    ed[u] = true;
//}
//queue<int> q;
//void toposort(){
//    while(!q.empty()) q.pop();
//    for(int i = 0;i < 26;i ++)if(!in[i]) q.push(i);
//    while(!q.empty()){
//        int u = q.front();
//        q.pop();
//        for(int i = 0;i < 26;i ++){
//            if(e[u][i]){
//                -- in[i];
//                if(!in[i]) q.push(i);
//            }
//        }
//    }
//}
//
//bool check(string x){
//    int u = 0;
//    memset(e,0,sizeof(e));
//    memset(in,0,sizeof(in));
//    for(int i = 0;x[i];i ++){
//        if(ed[u]) return false;
//        int v = x[i] - 'a';
//        for(int j = 0;j < 26;j ++){
//            if(!e[v][j] && v != j && ch[u][j]){
//                e[v][j] = 1;
//                ++ in[j];
//            }
//        }
//        u = ch[u][v];
//    }
//    toposort();
//    for(int i = 0;i < 26;i ++) if(in[i]) return false;
//    return true;
//}
//int main(){
//    read(n);
//
//    for(int i = 0;i < n;i ++){
//        cin >> s[i];
//        insert(s[i]);
//    }
//    for(int i = 0;i < n;i ++){
//        if(check(s[i])){
//            ans ++;
//            ok[i] = 1;
//        }
//    }
//    write(ans);
//    putchar('\n');
//    for(int i = 0;i < n;i ++){
//        if(ok[i]) cout << s[i] << endl;
//    }
//    return 0;
//}