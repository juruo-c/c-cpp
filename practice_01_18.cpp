//
// Created by 19116 on 2021/1/18.
//

//#include<cstdio>
//typedef long long ll;
//void exgcd(ll a,ll b,ll& x,ll& y){
//    if(b == 0) {
//        x = 1;
//        y = 0;
//        return;
//    }
//    exgcd(b, a % b, x, y);
//    int t = y;
//    y = x - (a / b) * y;
//    x = t;
//}
//
//int main(){
//    long long a,b,x,y;
//    scanf("%lld%lld",&a,&b);
//    exgcd(a,b,x,y);
//    x = (x % b + b) % b;
//    printf("%lld\n",x);
//    return 0;
//}

#include<cstdio>
typedef long long ll;
const int p = 1e9 + 7;
const int N = 1e6 + 10;
int n,m;
ll s[N],inv[N],f[N];

ll qpow(ll a,ll b){
    ll ans = 1;
    a = (a % p + p) % p;
    for(; b; b >>= 1){
        if(b & 1) ans = ans * a % p;
        a = a * a % p;
    }
    return ans;
}

int main(){
    int t;scanf("%d",&t);
    s[0] = 1;inv[0] = 1;
    for(int i = 1;i <= N;i ++){
        s[i] = s[i - 1] * i % p;
        inv[i] = qpow(s[i],p - 2);
    }
    f[0] = f[2] = 1;

    for(int i = 3;i <= N;i ++){
        f[i] = (f[i - 1] + f[i - 2]) % p * (i - 1) % p;
    }
    while(t --){
        scanf("%d%d",&n,&m);
        printf("%lld\n",s[n] * inv[n - m] % p * inv[m] % p * f[n- m] % p);
    }
    return 0;
}