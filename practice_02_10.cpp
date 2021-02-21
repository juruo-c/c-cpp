//
// Created by Administrator on 2021/2/10.
//

//#include<cstdio>
//
//const int N = 1e6 + 10;
//int phi[N];
//void euler(int n){
//    phi[1] = 1;
//    for(int i = 2;i <= n;i ++){
//        if(!phi[i]){
//            for(int j = i;j <= n;j += i){
//                if(!phi[j]) phi[j] = j;
//                phi[j] = phi[j] / i * (i - 1);
//            }
//        }
//    }
//}
//int phi[110];
//void euler(int n){
//    phi[1] = 1;
//    for(int i = 2;i <= n;i ++){
//        if(!phi[i]){
//            for(int j = i;j <= n;j += i){
//                if(!phi[j]) phi[j] = j;
//                phi[j] = phi[j] / i * (i - 1);
//            }
//        }
//    }
//}
//const int N = 1e4 + 10;
//int phi[N],prime[N],vis[N];
//int cnt;
//void euler(int n){
//    phi[1] = 1;
//    for(int i = 2;i <= n;i ++){
//        if(!vis[i]){
//            prime[++ cnt] = i;
//            phi[i] = i - 1;
//        }
//        for(int j = 1;j <= cnt;j ++){
//            if(i * prime[j] > n){
//                break;
//            }
//            vis[i * prime[j]] = 1;
//            if(i % prime[j] == 0){
//                phi[i * prime[j]] = phi[i] * prime[j];
//                break;
//            }
//            else{
//                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
//            }
//        }
//    }
//}


