//
// Created by Administrator on 2021/2/7.
//

//#include<cstdio>
//
//using namespace std;
//const int mod = 20100403;
//int n,m;
//const int N = 1e4 + 10;
//typedef long long ll;
//ll fac[N],inv[N];
//ll qpow(ll a,int b){
//    ll res = 1;
//    while(b){
//        if(b & 1) res = res * a % mod;
//        a = a * a % mod;
//        b >>= 1;
//    }
//    return res;
//}
//ll C(int a,int b){
//    ll ans = fac[a] * inv[b] % mod;
//    return ans * inv[a - b] % mod;
//}
//int main(){
//    scanf("%d%d",&n,&m);
//    fac[0] = 1;
//    for(int i = 1;i <= n + m;i ++){
//        fac[i] = fac[i - 1] * i % mod;
//    }
//    inv[n + m] = qpow(fac[n + m],mod - 2);
//    for(int i = n + m - 1;i >= 1;i --){
//        inv[i] = inv[i + 1] * (i + 1) % mod;
//    }
//    printf("%lld\n",(C(n + m,n) - C(n + m,m - 1) + mod) % mod);
//    return 0;
//}

//#include<cstdio>
//#include<cstring>
//using namespace std;
//const int N = 1e4 + 10;
//
//int fac[N][N],ans1[N],ans2[N];
//void mul(int num,int n,int b){
//    int tmp = 0;
//    for(int i = n - 1;i >= 0;i --){
//        tmp += b * fac[num][i];
//        fac[num][i] = tmp % 10;
//        tmp /= 10;
//    }
//}
//
//void div(int num,int n,int b){
//    int tmp = 0;
//    for(int i = 0;i < n;i ++){
//        tmp = tmp * 10 + fac[num][i];
//        fac[num][i] = tmp / b;
//        tmp %= b;
//    }
//}
//
//int main(){
//    int n,m;
//    scanf("%d%d",&n,&m);
//    fac[1][N - 1] = 1;
//    for(int i = 2;i <= n + m;i ++){
//        memcpy(fac[i],fac[i - 1],sizeof(fac[i - 1]));
//        mul(i,N,i);
//    }
//    memcpy(ans1,fac[n + m],sizeof(fac[n + m]));
//    memcpy(ans2,fac[n + m],sizeof(fac[n + m]));
//
//    return 0;
//}
//
//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//const int N = 510;
//int f[N][N];
//void mul(int num,int n,int b){
//    int tmp = 0;
//    for(int i = n - 1;i >= 0;i --){
//        tmp += b * f[num][i];
//        f[num][i] = tmp % 10;
//        tmp /= 10;
//    }
//}
//
//void div(int num,int n,int b){
//    int tmp = 0;
//    for(int i = 0;i < n;i ++){
//        tmp = tmp * 10 + f[num][i];
//        f[num][i] = tmp / b;
//        tmp %= b;
//    }
//}
//int main(){
//    int n;
//    scanf("%d",&n);
//    f[1][N - 1] = 1;
//    for(int i = 2;i <= n;i ++){
//        memcpy(f[i],f[i - 1],sizeof(f[i - 1]));
//        mul(i,N,4 * i - 2);
//        div(i,N,i + 1);
//    }
//    int i;
//    for(i = 0;i < N && !f[n][i];i ++);
//    printf("%d",f[n][i ++]);
//    for(;i < N;i ++) printf("%d",f[n][i]);
//    printf("\n");
//}

#include<cstdio>

using namespace std;
const int N = 2e6 + 10;
typedef long long ll;
int mp[N],prime[N],cnt[N],p;
ll qpow(ll a,int b){
    ll ans = 1;
    while(b){
        if(b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

int main(){
    int n;scanf("%d%d",&n,&p);
    int tot = 0;
    for(int i = 2;i <= 2 * n;i ++){
        if(!mp[i]){
            prime[++ tot] = i;
            mp[i] = i;
        }
        for(int j = 1;j <= tot && i * prime[j] <= 2 * n;j ++){
            mp[i * prime[j]] = prime[j];
            if(i % prime[j] == 0) break;
        }
    }

    for(int i = 1;i <= n;i ++) cnt[i] = -1;
    for(int i = n + 2;i <= 2 * n;i ++) cnt[i] = 1;
    for(int i = 2 * n;i > 1;i --){
        if(mp[i] < i){
            cnt[mp[i]] += cnt[i];
            cnt[i / mp[i]] += cnt[i];
        }
    }
    ll ans = 1;
    for(int i = 2;i <= 2 * n;i ++){
        if(mp[i] == i) ans = ans * qpow(i,cnt[i]) % p;
    }
    printf("%lld\n",ans);
    return 0;
}