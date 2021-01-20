//
// Created by 19116 on 2021/1/17.
//

//#include<iostream>
//
//using namespace std;
//const int N = 3e6 + 10;
//int n,p;
//long long inv[N];
//int main(){
//    cin >> n >> p;
//    inv[1] = 1;cout << 1 << endl;
//    for(int i = 2;i <= n;i ++){
//        inv[i] = (long long)(p - p / i) * inv[p % i] % p;
//        cout << inv[i] << endl;
//    }
//    return 0 ;
//}
//

//inv[1] = 1;
//for(int i = 2;i <= n;i ++){
//    inv[i] = (long long)( p - p / i ) * inv[p % i] % p;
//}

//#include<cstdio>
//
//
//const int p = 1e9 + 7;
//const int N = 5e6 + 10;
//const int M = 998244353;
//int qpow(long long a,int b){
//    int ans = 1;
//    a = ( a % p + p ) % p;
//    for(;b; b >>= 1){
//        if(b & 1) ans = (a * ans) % p;
//        a = (a * a) % p;
//    }
//    return ans;
//}
//long long s[N];
//int n,a[N];
//long long sv[N],inv[N];
//int main(){
//    scanf("%d",&n);
//    s[0] = 1;
//    for(int i = 1;i <= n;i ++){
//        scanf("%d",&a[i]);
//        s[i] = s[i - 1] * a[i] % p;
//    }
//    sv[n] = qpow(s[n],p - 2);
//    for(int i = n;i >= 1;i --) sv[i - 1] = sv[i] * a[i] % p;
//    for(int i = 1;i <= n;i ++) inv[i] = s[i - 1] * sv[i] % p;
//
////    for(int i = 1;i <= n;i ++) printf("%d\n",inv[i]);
//    long long sum = 0;
//    long long t = 1;
//    for(int i = n;i >= 1;i --){
//        sum = (sum + inv[i] * t) % p;
//        t = t * M % p;
//    }
//
//    printf("%lld\n",sum);
//    return 0;
//}
//

