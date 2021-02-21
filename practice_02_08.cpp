//
// Created by Administrator on 2021/2/8.
//

//#include<cstdio>
//
//using namespace std;
//typedef long long ll;
//const int N = 1e5 + 10;
//ll n,a[N],b[N];
//
//ll read(){
//    ll f = 1,x = 0;
//    char ss = getchar();
//    while(ss < '0' || ss > '9'){
//        if(ss == '-')f = -1;
//        ss = getchar();
//    }
//    while(ss >= '0' && ss <= '9'){
//        x = x * 10 + ss - '0';
//        ss = getchar();
//    }
//    return f * x;
//}
//
//ll qmul(ll a,ll b,ll mod){
//    ll res = 0;
//    while(b){
//        if(b & 1) res = (res + a) % mod;
//        a = (a + a) % mod;
//        b >>= 1;
//    }
//    return res;
//}
//
//ll exgcd(ll a,ll b,ll &x,ll &y){
//    if(!b){
//        x = 1,y = 0;
//        return a;
//    }
//    ll gcd = exgcd(b,a % b,x,y);
//    ll t = y;
//    y = x - a / b * y;
//    x = t;
//    return gcd;
//}
//
//ll excrt(){
//    ll m = a[1],ans = b[1];
//    ll x,y;
//    for(int i = 2;i <= n;i ++){
//        ll c = (b[i] - ans % a[i] + a[i]) % a[i];
//        ll gcd = exgcd(m,a[i],x,y),ag = a[i] / gcd;
//        if(c % gcd) return -1;
//        x = qmul(x, c / gcd, ag);
//        ans += x * m;
//        m *= ag;
//        ans = (ans % m + m) % m;
//    }
//    return (ans % m + m) % m;
//}
//int main(){
//    n = read();
//    for(int i = 1;i <= n;i ++){
//        a[i] = read(),b[i] = read();
//    }
//    printf("%lld\n",excrt());
//    return 0;
//}

//#include<cstdio>
//
//using namespace std;
//typedef long long ll;
//ll qpow(ll a,ll b,ll mod){
//    ll ans = 1;
//    a = a % mod;
//    while(b){
//        if(b & 1) ans = ans * a % mod;
//        a = a * a % mod;
//        b >>= 1;
//    }
//    return ans;
//}
//
//bool Miller_Rabin_1(ll n){
//    ll t = 0;
//    ll b = n - 1;
//    while(!(b & 1)){
//        t ++;
//        b >>= 1;
//    }
//    ll a = 2;
//    ll x = qpow(a,b,n);
//    for(ll i = 1;i <= t;i ++){
//        ll y = qpow(x,2,n);
//        if(y == 1 && x != -1 && x != n - 1) return false;
//        x = y;
//    }
//    if(x != -1) return false;
//    else return true;
//}
//
//bool Miller_Rabin_2(ll n){
//    ll p = n - 1;
//    ll a = 2;
//    ll x = qpow(a,p,n);
//    if(x == n - 1) return true;
//    else{
//        ll w;
//        do{
//            p >>= 1;
//            w = qpow(a,p,n);
//            if(w == n - 1) return true;
//            else if(w != 1) return false;
//        }
//        while((p & 1) != 1);
//
//        if(w == 1 || w == n - 1) return true;
//        else return false;
//    }
//}
//int main(){
//    if(Miller_Rabin_1(22222222222222222)) printf("Yes\n");
//    else printf("No\n");
//
//    return 0;
//}

#include<cstdio>
#include<unordered_map>
using namespace std;
typedef long long ll;
ll num[3] = {2,7,61};
ll qmul(ll a,ll b,ll mod){
    ll ans = 0;
    while(b){
        if(b & 1) ans = (ans + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return ans;
}
ll qpow(ll a,ll b,ll mod){
    ll ans = 1;
    while(b){
        if(b & 1) ans = qmul(ans,a,mod);
        a = qmul(a,a,mod);
        b >>= 1;
    }
    return ans;
}
bool Miller_Rabin(ll n,ll a,ll d){
    if(!(n & 1)) return false;
    while(!(d & 1)) d >>= 1;
    ll t = qpow(a,d,n);
    while(d != n - 1 && t != n - 1 && t != 1){
        t = qmul(t,t,n);
        d <<= 1;
    }
    return t == n - 1 || (d & 1);
}
bool is_p(ll n){
    for(int i = 0;i < 3;i ++){
        if(n == num[i])return true;
        if(!Miller_Rabin(n,num[i],n - 1)) return false;
    }
    return true;
}
unordered_map<ll,int> factor;
ll gcd(ll a,ll b){return !b ? a : gcd(b,a % b);}
ll Pollard_Rho(ll n,ll c){
    ll i = 1,k = 2;
    ll x = rand() % n;
    ll y = x;
    while(1){
        i ++;
        x = (qmul(x,x,n) + c) % n;
        ll g = gcd(y - x,n);
        if(g < 0) g = -g;
        if(g > 1 && g < n) return g;
        if(y == x) return n;
        if(i == k){
            y = x;
            k <<= 1;
        }
    }
}
void find_fac(ll n){
    if(is_p(n)){
        factor[n] ++;
        return;
    }
    ll p = n;
    while(p >= n) p = Pollard_Rho(p,rand() % (n - 1) + 1);
    find_fac(p);
    find_fac(n / p);
}
int main(){
    ll N;
    scanf("%lld",&N);
    if(N == 1) printf("No\n");
    else{
        if(is_p(N)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}


