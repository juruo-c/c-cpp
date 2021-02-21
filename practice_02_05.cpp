//
// Created by Administrator on 2021/2/5.
//

//
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<set>
//using namespace std;
//int a[4];
//bool vis[4];
//int ans[4];
//int last;
//set<int> s;
//int flag = 1;
//void solve(int cur){
//    if(cur == 4){
//
//        int tmp = 0;
//        for(int i = 0;i < 4;i ++){
//            tmp = tmp * 10 + ans[i];
//        }
//        if(tmp > 999){
//            if(ans[0] != last){
//                cout << endl;
//                flag = 1;
//                last = ans[0];
//            }
//            if(!s.count(tmp)){
//                if(flag){
//                    cout << tmp;
//                    flag = 0;
//                }
//                else cout << " " << tmp;
//                s.insert(tmp);
//            }
//        }
//        return;
//    }
//    for(int i = 0;i < 4;i ++){
//        if(!vis[i]){
//            ans[cur] = a[i];
//            vis[i] = 1;
//            solve(cur + 1);
//            vis[i] = 0;
//        }
//    }
//}
//int main(){
//    int kase = 0;
//    while(cin >> a[0] >> a[1] >> a[2] >> a[3] && (a[0] + a[1] + a[2] + a[3])){
//        if(kase) cout << endl;
//        sort(a,a + 4);
//        for(int i = 0;i < 4;i ++){
//            if(a[i]){
//                last = a[i];
//                break;
//            }
//        }
//        flag = 1;
//        memset(vis,0,sizeof(vis));
//        s.clear();
//        solve(0);
//        cout << endl;
//        kase ++;
//    }
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e4 + 10;
//int n,m;
//int a[N];
//int main(){
//    cin >> n >> m;
//    for(int i = 0;i < n;i ++){
//        cin >> a[i];
//    }
//    while(m--) next_permutation(a,a + n);
//    for(int i = 0;i < n;i ++) cout << a[i] << " " ;
//    return 0;
//}

//#include<cstdio>
//#include<algorithm>
//
//using namespace std;
//const int N = 5e4 + 10;
//struct Node{
//    int pos[22],p[22];
//}node[N];
//int n,k;int a[25];
//bool cmp(Node x,Node y){
//    for(int i = 1;i < n;i ++){
//        if(x.p[i] != y.p[i])
//            return x.p[i] < y.p[i];
//    }
//}
//int main(){
//    int t; scanf("%d",&t);
//    while(t --){
//        scanf("%d%d",&n,&k);
//        if(n <= 8){
//            for(int i = 1;i <= n;i ++) a[i] = i;
//            for(int i = 1;i <= n;i ++) node[1].pos[i] = a[i];
//            for(int i = 2;i <= n;i ++) node[1].p[i - 1] = a[i] - a[i - 1];
//
//            int num = 2;
//            while(next_permutation(a + 1,a + 1 + n)){
//                for(int i = 1;i <= n;i ++) node[num].pos[i] = a[i];
//                for(int i = 2;i <= n;i ++) node[num].p[i - 1] = a[i] - a[i - 1];
//                num ++;
//            }
//
//            sort(node + 1,node + num,cmp);
//            for(int i = 1;i <= n - 1;i ++)
//                printf("%d ",node[k].pos[i]);
//            printf("%d\n",node[k].pos[n]);
//        }
//        else{
//            printf("%d ",n);
//            for(int i = 1;i <= n - 1;i ++) a[i] = i;
//            if(k == 1){
//                for(int i = 1;i <= n - 2;i ++) printf("%d ", a[i]);
//                printf("%d\n",a[n - 1]);
//            }
//            else{
//                int num = 1;
//                while(next_permutation(a + 1,a + 1 + (n - 1))){
//                    num ++;
//                    if(num == k){
//                        for(int i = 1;i <= n - 2;i ++) printf("%d ",a[i]);
//                        printf("%d\n",a[n - 1]);
//                        break;
//                    }
//                }
//            }
//        }
//    }
//    return 0;
//}

//
//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//typedef long long ll;
//const int N = 1e3 + 10;
//const int mod = 1e6 + 3;
//ll C[N][N];
//ll a[100];
//void init(){
//    for(int i = 0;i < N;i ++){
//        C[0][i] = 0;
//        C[i][0] = 1;
//    }
//    for(int i = 1;i < N;i ++){
//        for(int j = 1;j < N;j ++){
//            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
//        }
//    }
//}
//int main(){
//    int n;
//    init();
//    while(~scanf("%d",&n)){
//        memset(a,0,sizeof(a));
//        int t = n;
//        while(t --){
//            ll x;
//            scanf("%lld",&x);
//            for(int j = 1;x;j ++){
//                if(x & 1) a[j] ++;
//                x >>= 1;
//            }
//        }
//        for(int i = 1;i <= n;i ++){
//            ll ans = 0;
//            for(int j = 1;j <= 32;j ++){
//                for(int k = 1;k <= i && k <= a[j];k += 2){
//                    ans = (ans + C[a[j]][k] * C[n - a[j]][i - k] % mod * (1LL << (j - 1)) % mod ) % mod;
//                }
//            }
//            printf("%lld",ans);
//            if(i == n) printf("\n");
//            else printf(" ");
//        }
//    }
//    return 0;
//}

//#include<cstdio>
//
//using namespace std;
//typedef long long ll;
//ll cal(ll n,ll m){
//    if(2 * m > n) m = n - m;
//    ll sum = 1;
//    for(ll i = 1,j = n;i <= m;i ++,j --)
//        sum = sum * j / i;
//    return sum;
//}
//int main(){
//    ll n,m;
//    while(~scanf("%lld%lld",&n,&m) && (n + m)){
//        printf("%lld things taken %lld at a time is %lld exactly.\n",n,m,cal(n,m));
//    }
//    return 0;
//}

//#include<cstdio>
//
//using namespace std;
//
//typedef long long ll;
//ll cal(ll n,ll m){
//    if(2 * m > n) m = n - m;
//    ll sum = 1;
//    for(ll i = 1,j = n;i <= m;i ++,j --)
//        sum = sum * j / i;
//    return sum;
//}
//int main(){
//    ll n,k;
//    while(~scanf("%lld%lld",&n,&k) && (n + k)){
//        ll res = cal(n,k);
//        printf("%lld\n",res);
//    }
//    return 0;
//}
//
//#include<iostream>
//
//using namespace std;
//int mod;
//const int N = 1e4 + 10;
//typedef long long ll;
//ll qpow(ll a,ll b){
//    ll ans = 1;
//    while(b){
//        if(b & 1) ans = ans * a % mod;
//        a = a * a % mod;
//        b >>= 1;
//    }
//    return ans;
//}
//
//ll inv(ll x){
//    return qpow(x,mod - 2);
//}
//ll fac[N];
//int main(){
//    ll n,m;
//    scanf("%lld%lld%lld",&n,&m,&mod);
//    fac[0] = 1;
//    for(int i = 1;i <= n;i ++)
//        fac[i] = fac[i - 1] * i % mod;
//
//    ll res = fac[n] * inv(fac[m]) % mod * inv(fac[n - m]) % mod;
//    printf("%lld\n",res);
//    return 0;
//}
//
//int c[N][N];
//void init(){
//    for(int i = 0;i < N;i ++) {
//        c[i][i] = 1;
//        c[i][0] = 1;
//        for(int j = 1;j < i;j ++){
//            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
//        }
//    }
//}
//int main(){
//    init();
//    for(int i = 1;i <= 5;i ++){
//        for(int j = 1;j <= i;j ++){
//            cout << c[i][j] << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}

//#include<cstdio>
//
//using namespace std;
//int n,cnt;
//long long qpow(int a,int b){
//    long long ans = 1;
//    while(b){
//        if(b & 1) ans *= a;
//        a *= a;
//        b >>= 1;
//    }
//    return ans;
//}
//int main(){
//    while(~scanf("%d",&n)){
//        cnt = 0;
//        while(n){
//            if(n & 1) cnt ++;
//            n >>= 1;
//        }
//        printf("%lld\n",qpow(2,cnt));
//    }
//    return 0;
//}
//
//#include<cstdio>
//
//using namespace std;
//
//const int N = 1e6 + 10;
//const int mod = 1e9 + 7;
//typedef long long ll;
//ll qpow(ll a,ll b){
//    ll ans = 1;
//    a %= mod;
//    while(b){
//        if(b & 1) ans = ans * a % mod;
//        a = a * a % mod;
//        b >>= 1;
//    }
//    return ans;
//}
//ll fac[N];
//int main(){
//    int n,m;
//    scanf("%d%d",&n,&m);
//    fac[0] = 1;
//    for(int i = 1;i <= n + m - 2;i ++){
//        fac[i] = fac[i - 1] * i % mod;
////        cout << fac[i] << " ";
//    }
//
//    ll ans = fac[n + m - 2] * qpow(fac[n - 1],mod - 2) % mod * qpow(fac[m - 1],mod - 2) % mod;
//    printf("%lld\n",ans);
//    return 0;
//}

#include<cstdio>

using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
ll qpow(ll a,ll b){
    ll ans = 1;
    while(b){
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

ll getc(ll n,ll m){
    if(n < m) return 0;
    if(m > n - m) m = n - m;\
    ll s1 = 1,s2 = 1;
    for(int i = 0;i < m;i ++){
        s1 = s1 * (n - i) % mod;
        s2 = s2 * (i + 1) % mod;
    }
    return s1 * qpow(s2,mod - 2) % mod;
}
ll lucas(ll n,ll m){
    if(!m) return 1;
    return getc(n % mod,m % mod) * lucas(n / mod,m / mod) % mod;
}
int main(){
    ll n,m;
    scanf("%lld%lld",&n,&m);
    printf("%lld\n",lucas(n + m - 2,m - 1));
    return 0;
}