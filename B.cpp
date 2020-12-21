//#include<iostream>
//
//using namespace std;
//const int N = 1e6 + 10;
//int a[N];
//
//int main()
//{
//    int n, m;cin >> n >> m;
//    while(m --){
//        int l,r,num;
//        cin >> l >> r >> num;
//        if(l < r)
//        a[l] += num, a[r] -= num;
//        else{
//            a[l] += num;
//            a[1] += num;
//            a[r] -= num;
//        }
//    }
//    for(int i = 1;i <= n;i ++){
//        a[i] += a[i - 1];
//    }
//    int maxx = 0;
//    for(int i = 1;i <= n;i ++){
//        maxx = max(maxx, a[i]);
//    }
//    int ans = 0;
//    if(maxx % 36) ans = maxx / 36 + 1;
//    else ans = maxx / 36;
//
//    cout << ans << endl;
//    return 0;
//}
