//
// Created by Administrator on 2021/1/30.
//


//#include<cstdio>
//
//using namespace std;
//
//int n,k;
//
//int main(){
//    int t;scanf("%d",&t);
//    while(t --){
//        scanf("%d%d",&n,&k);
//        int ans;
//        if(n <= k){
//            if(k % n) ans = k / n + 1;
//            else ans = k / n;
//        }
//        else{
//            if(n % k){
//                int tmp = n / k + 1;
//                k *= tmp;
//                ans = k / n + 1;
//            }
//            else ans = 1;
//        }
//        printf("%d\n",ans);
//    }
//    return 0;
//}


#include<iostream>

using namespace std;


int main(){
    int t;cin >> t;
    while(t --){
        int a[110] = {0}, s[110] = {0};
        int n,k;
        cin >> n >> k;
        for(int i = 1;i <= n;i ++) {
            cin >> a[i];
            s[i] = a[i];
            s[i] += s[i - 1];
        }
        int cnt = 0;
        for(int i = 2;i <= n;i ++){
            while(a[i] * 100 > k * s[i]){
                s[i] ++;
                cnt ++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
