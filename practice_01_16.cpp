//
// Created by 19116 on 2021/1/16.
//

//#include<iostream>
//
//using namespace std;
//typedef long long ll;
//const int N = 1e6 + 10;
//bool vis[N];
//int prime[N];
//int cnt;
//void oula_prime(ll range){
//    for(ll i = 2;i < range;i ++){
//        if(!vis[i]) prime[cnt ++] = i;
//        for(int j = 0;j < cnt;j ++){
//            if(i * prime[j] >= range) break;
//            vis[i * prime[j]] = 1;
//            if(i % prime[j] == 0) break;
//        }
//    }
//}
//
//int main(){
//    int n;cin >> n;
//    oula_prime(n);
//    for(int i = 0;i < cnt;i ++)
//        cout << prime[i] << " ";
//    return 0;
//}

//
//int gcd(int a,int b){
//    if(b == 0) return a;
//    return gcd(b,a % b);
//}

//int exgcd(int a,int b,int& x,int& y){
//    if(b == 0){
//        x = 1;
//        y = 0;
//        return a;
//    }
//    int r = exgcd(b,a % b,x, y);
//    int t = y;
//    y = x - (a / b) * y;
//    x = t;
//    return r;
//}

//int exgcd(int a,int b,int& x,int& y){
//    if(b == 0){
//        x = 1;
//        y = 0;
//        return a;
//    }
//    int r = exgcd(b,a % b,x,y);
//    int t = y;
//    y = x - (a / b) * y;
//    x = t;
//    return r;
//}

//int exgcd(int a,int b,int& x,int& y){
//    if(b == 0){
//        x = 1;
//        y = 0;
//        return a;
//    }
//    int r = exgcd(b, a % b, x, y);
//    int t = y;
//    y = x - a / b * y;
//    x = t;
//    return r;
//}

#include<iostream>
#include<vector>

using namespace std;

vector<int> breakdown(int n){
    vector<int> res;
    for(int i = 2;i * i <= n;i ++){
        if(n % i == 0){
            while(n % i == 0){
                n /= i;
                res.push_back(i);
            }
        }
    }
    if(n != 1) res.push_back(n);
    return res;
}






