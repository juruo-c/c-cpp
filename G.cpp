//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//typedef long long ll;
//ll n;
//const int mod = 1e9 + 7;
//ll tmp[2][2];
//ll a[2][2] = {0,1,1,1};
//ll res[2][2];
//ll temp[1][2];
//ll ans = 1;
//
//void mul(ll a[][2],ll b[][2])
//{
//    memset(tmp,0,sizeof(tmp));
//    for(int i = 0;i < 2;i ++){
//        for(int j = 0;j < 2;j ++){
//            for(int k = 0;k < 2;k ++){
//                tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j] % mod) % mod;
//            }
//        }
//    }
//    for(int i = 0;i < 2;i ++){
//        for(int j = 0;j < 2;j ++){
//            a[i][j] = tmp[i][j];
//        }
//    }
//}
//
//void fun(int nn){
//    memset(res,0,sizeof(res));
//    for(int i = 0;i < 2;i ++){
//        res[i][i] = 1;
//    }
//    while(nn){
//        if(nn & 1) mul(res,a);
//        mul(a,a);
//        nn >>= 1;
//    }
//}
//
//int main()
//{
//    int T;cin >> T;
//    while(T --){
//        ans = 1;
//        cin >> n;
//        ll t = 0;
//        while(n){
//            t = t * 9 + (n % 9);
//            n /= 9;
//        }
//        fun(t);
//        ans = (a[0][0] % mod + a[1][0] % mod) % mod;
//        cout << ans << endl;
//    }
//
//    return 0;
//}
