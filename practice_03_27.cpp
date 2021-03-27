//
// Created by 19116 on 2021/3/27.
//

//#include<iostream>
//#include<cstdio>
//
//using namespace std;
//typedef long long ll;
//
//int main(){
//    int t;scanf("%d",&t);
//    while(t --){
//        ll a,b;
//        scanf("%lld%lld",&a,&b);
//        ll cnt = 0,sum,ans = 0xffffffff;
//        if(b == 1){
//            sum = 1;
//            b = 2;
//            cnt ++;
//        }
//        else sum = 0;
//        while(true){
//            int tt = a;
//            while(tt){
//                tt /= b;
//                sum ++;
//            }
//            if(ans >= sum) ans = sum;
//            else break;
//            cnt ++;
//            sum = cnt;
//            b ++;
//        }
//
//
//        printf("%lld\n",ans);
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//
//using namespace std;
//typedef long long ll;
//const int N = 1e5 + 10;
//int main(){
//    int n,q,k;
//    int a[N] = {0};
//    int c[N] = {0};
//    int s[N] = {0};
//    scanf("%d%d%d",&n,&q,&k);
//    for(int i = 1;i <= n;i ++) scanf("%d",&a[i]);
//    c[1] = a[2] - 2;c[n] = k - a[n - 1] - 1;
//    for(int i = 2;i < n;i ++) c[i] = a[i + 1] - a[i - 1] - 2;
//    for(int i = 1;i <= n;i ++) s[i] = s[i - 1] + c[i];
//
//    for(int i = 0;i < q;i ++){
//        int l,r;
//        scanf("%d%d",&l,&r);
//        int res = s[r] - s[l - 1];
//        if(l != 1) res += a[l - 1];
//        if(r != n) res += k - a[r + 1] + 1;
//        printf("%d\n",res);
//    }
//    return 0;
//}


//#include<iostream>
//
//using namespace std;
//
//const int N = 1e6 + 10;
//int main(){
//    int n;cin >> n;
//    int a[N] = {0};
//    int c[N] = {0};
//    for(int i = 1;i <= n;i ++) cin >> a[i];
//
//    for(int i = 1;i <= n;i ++) c[i] = a[i] - a[i - 1];
//
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//
//using namespace std;
//const int N = 1e5 + 10;
//
//int read(){
//    int x = 0;
//    char c = getchar();
//    while(!isdigit(c)) c = getchar();
//    while(isdigit(c)) x = x * 10 + c - '0',c = getchar();
//    return x;
//}
//int a[N];
//int ans;
//void solve(int l,int r,int x){
//    if(l == r){
//        if(a[l] % x == 0) ans ++;
//        return;
//    }
//    int mid = l + r >> 1;
//    solve(l,mid,x);
//    solve(mid + 1,r,x);
//}
//int main(){
//    int n,q;
//    n = read(),q = read();
//    for(int i = 1;i <= n;i ++){
//        a[i] = read();
//    }
//
//    for(int i = 1;i <= q;i ++){
//        int l,r,x;
//        l = read();r = read();x = read();
//        ans = 0;
//        solve(l,r,x);
//        printf("%d\n",ans);
//    }
//    return 0;
//}

//#include<iostream>
//#include<set>
//#include<cstdio>
//#include<vector>
//
//using namespace std;
//const int N = 1e5 + 10;
//int a[N];
//int cnt ;
//int prime[N];
//bool p[N];
//typedef long long ll;
//void isprime(){
//    p[1] = 1;
//    for(int i = 2;i <= N;i ++){
//        if(p[i] == 0){
//            prime[++ cnt] = i;
//            for(int j = i * 2;j <= N;j += 2){
//                p[j] = 1;
//            }
//        }
//    }
//}
//int work(int t){
//    set<int> s;
//    for(int i = 1;i <= cnt && t != 1;i ++){
//        if(t % prime[i] == 0){
//            s.insert(prime[i]);
//            while(t % prime[i] == 0) t /= prime[i];
//        }
//    }
//    int res = 1;
//    for(auto x : s) res *= x;
//    return res;
//}
//int solve(int t,int x){
//    int ans = 0;
//    vector<int> s;
//    for(int i = 1;i <= cnt && t != 1;i ++){
//        if(t % prime[i] == 0){
//            while(t % prime[i] == 0) {
//                s.push_back(prime[i]);
//                t /= prime[i];
//            }
//        }
//    }
//    for(auto n : s){
//        if(n == x) ans ++;
//    }
//    return ans;
//}
//struct tree{
//    int l,r;ll sum;
//}t[N << 2];
//
//void build(int i,int l,int r){
//    t[i].l = l,t[i].r = r;
//    if(l == r){
//        t[i].sum = a[l];
//        return;
//    }
//    int mid = (l + r) >> 1;
//    build(i << 1,l,mid);
//    build(i << 1 | 1,mid + 1,r);
//    t[i].sum = t[i << 1].sum + t[i << 1 | 1].sum;
//}
//
//ll query(int i,int l,int r,int x){
//    if(t[i].l >= l && t[i].r <= r){
//        return solve(t[i].sum,x);
//    }
//    ll s = 0;
//    if(t[i << 1].r >= l) s += query(i << 1,l,r,x);
//    if(t[i << 1 | 1].l <= r) s += query(i << 1 | 1,l,r,x);
//    return s;
//}
//
//int main(){
//    int n,q;scanf("%d%d",&n,&q);
//    isprime();
//    for(int i = 1;i <= n;i ++){
//        int t;scanf("%d",&t);
//        a[i] = work(t);
//    }
//    for(int i = 1;i <= n;i ++) cout << a[i] << " " ;
//    cout << endl;
//    build(1,1,n);
//
//    for(int i = 0;i < q;i ++){
//        int l,r,x;
//        scanf("%d%d%d",&l,&r,&x);
//        printf("%lld\n",query(1,l,r,x));
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//int vis[210] ;
//int main(){
//    int n,m,cur = 0;
//    cin >> n >> m;
//    for(int i = 0;i < n;i ++){
//        for(int j = 0;j < m;j ++){
//            if(++ cur > n) cur = 1;
//            if(vis[cur]) j --;
//        }
//        printf("%d ",cur);
//        vis[cur] = 1;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 1e5 + 10;
//int n,m;
//
//struct T{
//    int l,r,d;
//}t[N];
//
//void add(int i,int k,int f){
//    if(f == 1){//右
//        t[i].r = t[k].r;
//        t[i].l = k;
//        t[k].r = i;
//        t[t[i].r].l = i;
//    }
//    else{
//        t[i].r = k;
//        t[i].l = t[k].l;
//        t[k].l = i;
//        t[t[i].l].r = i;
//    }
//}
//
//int main(){
//    cin >> n;
//    t[0].r = 0,t[0].l = 0;
//    add(1,0,1);
//    for(int i = 2;i <= n;i ++){
//        int k,p;
//        cin >> k >> p;
//        add(i,k,p);
//    }
//    cin >> m;
//    for(int i = 0;i < m;i ++){
//        int x;cin >> x;
//        t[x].d = 1;
//    }
//    for(int i = t[0].r;i;i = t[i].r){
//        if(!t[i].d) cout << i << " ";
//    }
//    return 0;
//}

//#include<iostream>
//#include<stack>
//
//using namespace std;
//int work(string s){
//    int res = 0;
//    for(int i = 0;i < s.size();i ++){
//        res = res * 10 + s[i] - '0';
//    }
//    return res;
//}
//int main(){
//    string s;
//    cin >> s;
//    string num;
//    stack<int> stk;
//    for(int i = 0;i < s.size();i ++){
//        if(s[i] == '@') break;
//        if(isdigit(s[i])) num += s[i];
//        if(s[i] == '.'){
////            cout << num << endl;
//            stk.push(work(num));
//            num = "";
//        }
//        if(!isdigit(s[i]) && s[i] != '.'){
//            int t1 = stk.top();stk.pop();
//            int t2 = stk.top();stk.pop();
////            cout << t1 << " " << t2 << endl;
//            if(s[i] == '+') stk.push(t1 + t2);
//            else if(s[i] == '*') stk.push(t1 * t2);
//            else if(s[i] == '/') stk.push(t2 / t1);
//            else if(s[i] == '-') stk.push(t2 - t1);
//        }
//    }
//    cout << stk.top() << endl;
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<stack>
//
//using namespace std;
//
//int main(){
//    char c;
//    stack<char> stk;
//    while((c = getchar()) != '@'){
//        if(c == '(') stk.push(c);
//        if(c == ')'){
//            if(stk.top() == '(') stk.pop();
//            else stk.push(c);
//        }
//    }
//    if(!stk.empty()) cout << "NO" << endl;
//    else cout << "YES" << endl;
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//using namespace std;
//
//int main(){
//    char c;int top = 0;
//    while((c = getchar()) != '@'){
//        if(c == '(') top ++;
//        else if(c == ')') top --;
//        if(top == -1) break;
//    }
//    if(top == 0) cout << "YES" << endl;
//    else cout << "NO" << endl;
//    return 0;
//}
//
//#include<iostream>
//#include<stack>
//
//using namespace std;
//typedef long long ll;
//stack<ll> stk;
//
//ll work(string num){
//    ll res = 0;
//    for(int i = 0;i < num.size();i ++) res = res * 10 + num[i] - '0';
//    return res;
//}
//int main(){
//    string s;cin >> s;
//    int fl = 1;
//    string num;
//    for(int i = 0;s[i];i ++){
//        if(isdigit(s[i])) num += s[i];
//        if(!isdigit(s[i])){
//            if(s[i] == '+'){
//                if(num == "") continue;
////                cout << num << endl;
//                stk.push(fl * work(num));
//                num = "";
//            }
//            else if(s[i] == '*' ){
//                i ++;
//                ll t1;
//                if(num != "")t1 = work(num);
//                else t1 = stk.top(),stk.pop();
//                num = "";
//                while(isdigit(s[i])) num += s[i],i ++;
//                cout << t1 << " " << work(num) << endl;
//                stk.push(t1 * work(num));
//                num = "";
//                i --;
//            }
//        }
//    }
//    if(num != "") stk.push(work(num));
//    ll ans = 0;
//    while(!stk.empty()) {
//        ans += stk.top();
////        cout << stk.top() << " ";
//        stk.pop();
//    }
////    cout << endl;
//    cout << ans % 10000 << endl;
//    return 0;
//}

#include<iostream>
#include<stack>

using namespace std;
const int MOD = 1e4;
stack<int> s;
int main(){
    int a,b;
    char c;
    cin >> a;
    a = a % MOD;
    s.push(a);
    while(cin >> c >> b){
        if(c == '*'){
            a = s.top();
            s.pop();
            b %= MOD;
            s.push(a * b % MOD);
        }
        else s.push(b % MOD);
    }
    int ans = 0;
    while(!s.empty()){
        ans += s.top();
        ans %= MOD;
        s.pop();
    }
    cout << ans << endl;
    return 0;
}