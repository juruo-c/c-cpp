//
// Created by 19116 on 2021/3/7.
//

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//template<class T>
//inline T read(){
//    T x = 0;T f = 1;char c = getchar();
//    while(!isdigit(c)) {
//        if(c == '-') f = -1;
//        c = getchar();
//    }
//    while(isdigit(c)) x = x * 10 + c - '0',c = getchar();
//    return f * x;
//}
//int main(){
//
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//typedef long long ll;
//int main(){
//    int t;cin >> t;
//    while(t --){
//        ll n;cin >> n;
//        ll ans;
//        if(n % 2) ans = (n + 1) / 2 * n;
//        else ans = n / 2 * (n + 1);
////        cout << ans << endl;
//        for(ll i = 1;i <= n;i *= 2)
//            ans -= i,ans -= i;
//        cout << ans << endl;
//    }
//    return 0;
//}

//#include<iostream>
//using namespace std;
//int main(){
//    int n;cin >> n;
//    int cnt = 0;
//    int ans = 0;
//    for(int i = 1;i <= n;i ++){
//        int a;cin >> a;
//        if(a % 2 == 0 && a % 4) cnt ++;
//        if(a % 4 == 0){
//            ans += 2;
//        }
//    }
//    if(cnt >= 2) ans += cnt;
//    else if(cnt < 2 && ans == n - 1) ans = n;
//    if(ans >= n) cout << "Yes" << endl;
//    else cout << "No" << endl;
//    return 0;
//}


//#include<iostream>
//using namespace std;
//const int inf = 0xffffffff;
//const int maxn = 6e4+10;
//double p[maxn],v[maxn];
//double high,low,m,l,r;
//double maxp,minp=inf;
//int n;
//int main()
//{
//    scanf("%d",&n);
//    for(int i=0;i<n;i++){
//        scanf("%lf",&p[i]);
//        maxp=max(p[i],maxp);
//        minp=min(p[i],minp);
//    }
//    for(int i=0;i<n;i++)scanf("%lf",&v[i]);
//    high=maxp,low=minp;
//    while(high-low>=1e-7){
//        m=(high+low)/2;
//        l = r = 0;
//        for(int i=0;i<n;i++){
//            if(p[i]<m){
//                l=max((m-p[i])/v[i],l);
//            }
//            else{
//                r=max((p[i]-m)/v[i],r);
//            }
//        }
//        if(l==r)break;
//        else if(l>r) high = m;
//        else if(l<r) low = m;
//    }
//    printf("%.12lf",(l+r)/2);
//    return 0;
//}




