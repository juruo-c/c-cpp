//
// Created by Administrator on 2021/2/6.
//
//
//#include<iostream>
//
//using namespace std;
//typedef long long ll;
//const int N = 100;
//ll c[N];
//int main(){
//    int n;int kase = 0;
//    c[0] = c[1] = 1;
//    for(int i = 2;i <= 36;i ++){
//        c[i] = 0;
//        for(int j = 0;j < i;j ++){
//            c[i] += (c[j] * c[i - j - 1]);
//        }
//    }
//    while(cin >> n && (n != -1)){
//        printf("%d %d %lld\n",++kase,n,c[n] * 2);
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//
//using namespace std;
//const int N = 110;
//const int BASE = 1e4;
//int a[N][N];
//void mul(int num,int n,int b){
//    int tmp = 0;
//    for(int i = n - 1;i >= 0;i --){
//        tmp += b * a[num][i];
//        a[num][i] = tmp % BASE;
//        tmp /= BASE;
//    }
//}
//void div(int num,int n,int b){
//    int tmp = 0;
//    for(int i = 0;i < n;i ++){
//        tmp = tmp * BASE + a[num][i];
//        a[num][i] = tmp / b;
//        tmp %= b;
//    }
//}
//void init(){
//    memset(a,0,sizeof(a));
//    a[1][100 - 1] = 1;
//    for(int i = 2;i <= 100;i ++){
//        memcpy(a[i],a[i - 1],sizeof(a[i - 1]));
//        mul(i,100,4 * i - 2);
//        div(i,100,i + 1);
//    }
//}
//int main(){
//    init();
//    int n;
//    while(cin >> n && (n != -1)){
//        int i;
//        for( i = 0;i < 100 && a[n][i] == 0;i ++);
//        printf("%d",a[n][i ++]);
//
//        for(;i < 100;i ++)
//            printf("%04d",a[n][i]);
//        printf("\n");
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<cstdio>
//using namespace std;
//const int N = 110;
//const int BASE = 1e4;
//int a[N][N];
//void mul(int num,int n,int b){
//    int tmp = 0;
//    for(int i = n - 1;i >= 0;i --){
//        tmp += b * a[num][i];
//        a[num][i] = tmp % 10;
//        tmp /= 10;
//    }
//}
//void div(int num,int n,int b){
//    int tmp = 0;
//    for(int i = 0;i < n;i ++){
//        tmp = tmp * 10 + a[num][i];
//        a[num][i] = tmp / b;
//        tmp %= b;
//    }
//}
//void init(){
//    memset(a,0,sizeof(a));
//    a[1][100 - 1] = 1;
//    for(int i = 2;i <= 100;i ++){
//        memcpy(a[i],a[i - 1],sizeof(a[i - 1]));
//        mul(i,100,4 * i - 2);
//        div(i,100,i + 1);
//    }
//}
//int main(){
//    init();
//    int n;
//    while(cin >> n && n != -1){
//        int i;
//        for(i = 0;i < 100 && a[n][i] == 0;i ++);
//        printf("%d",a[n][i ++]);
//        for(;i < 100;i ++)
//            printf("%d",a[n][i]);
//        printf("\n");
//    }
//    return 0;
//}