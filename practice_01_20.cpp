//
// Created by 19116 on 2021/1/20.
//

//#include<cstdio>
//
//int qpow(int a,int b,int p){
//    int ans = 1;
//    a = (b + a % p) % p;
//    for(; b; b >>= 1){
//        if(b & 1) ans = ans * a % p;
//        a = a * a % p;
//    }
//    return ans;
//}
//
//int main(){
//    int kase = 0;
//    int p,e,i,d;
//    while(true){
//        scanf("%d%d%d%d",&p,&e,&i,&d);
//        if(p == -1 && e == -1 && i == -1 && d == -1) break;
//        int a[4] = {0,23,28,33};
//        int b[4];
//        b[1] = p,b[2] = e,b[3] = i;
//        int s[4] = {0};
//        s[0] = 1;
//        for(int i = 1;i <= 3;i ++) s[i] = s[i - 1] * a[i];
//        int m[4];
//        for(int i = 1;i <= 3;i ++) m[i] = s[3] / a[i];
//        int mv[4];
//        for(int i = 1;i <= 3;i ++) mv[i] = qpow(m[i], a[i] - 2, a[i]);
//        int ans = 0;
//        for(int i = 1;i <= 3;i ++) ans += b[i] * m[i] % s[3] * mv[i] % s[3];
//        printf("Case %d: the next triple peak occurs in %d days.\n",++kase,ans);
//    }
//    return 0;
//}

//#include<cstdio>
//
//int qpow(int a,int b,int p){
//    int ans = 1;
//    a = (a % p + p) % p;
//    for(; b; b >>= 1){
//        if(b & 1) ans = ans * a % p;
//        a = a * a % p;
//    }
//    return ans;
//}
//
//int main(){
//    int p,e,i,d;
//    int kase = 0;
//    while(scanf("%d%d%d%d",&p,&e,&i,&d) != EOF && p >= 0){
//        int n1,n2,n3;
//
//        p = p % 23 + 1;
//        e = e % 28 + 1;
//        i = i % 33 + 1;
//
//        int m1 = 28 * 33;
//        int mv1 = qpow(m1,23 - 2,23);
//
//        int m2 = 23 * 33;
//        int mv2 = qpow(m2,28 - 2,28);
//
//        int m3 = 28 * 23;
//        int mv3 = qpow(m3,33 - 2,33);
//
//        int m = 23 * 28 * 33;
//        int t = p * m1 % m * mv1 % m;
//        t = (t + e * m2 % m * mv2 % m) % m;
//        int ans = (t + i * m3 % m * mv3 % m) % m;
//
//        printf("Case %d: the next triple peak occurs in %d days.\n",++kase, ans);
//    }
//    return 0;
//}

#include<cstdio>

//int qpow(int a,int b,int p){
//    int ans = 1;
//    a = (a % p + p) % p;
//    for(; b; b >>= 1){
//        if(b & 1) ans = ans * a % p;
//        a = a * a % p;
//    }
//    return ans;
//}

void exgcd(int a,int b,int& x,int& y){
    if(b == 0){
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b, x, y);
    int t = y;
    y = x - (a / b) * y;
    x = t;
}

int CRT(int a[],int m[],int n){
    int M = 1;
    int ans = 0;
    for(int i = 1;i <= n;i ++)
        M *= m[i];
    for(int i = 1;i <= n;i ++){
        int Mi = M / m[i];
        int x,y;
        exgcd(Mi,m[i],x,y);
        ans = (ans + Mi * x * a[i]) % M;
    }
    if(ans < 0) ans += M;
    return ans;
}
int main(){
    int p,e,i,d,kase = 1;
    int a[4] = {0},m[4] = {0};
    m[1] = 23,m[2] = 28,m[3] = 33;
    while(~scanf("%d%d%d%d",&p,&e,&i,&d) && p >= 0){
        a[1] = p,a[2] = e,a[3] = i;
        int ans = CRT(a,m,3);
        if(ans <= d) ans += 21252;
        printf("Case %d: the next triple peak occurs in %d days.\n", kase++, ans-d);
    }
    return 0;
}