//
// Created by 19116 on 2021/3/7.
//

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//int bo[10] = {1,1,1,0,0,1,0,0,1,0};
//int to[10] = {0,1,5,0,0,2,0,0,8,0};
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int h,m;
//        cin >> h >> m;
//        int a,b,c,d;
//        scanf("%1d%1d:%1d%1d",&a,&b,&c,&d);
//        int fl = 0;
//        for(int i = a * 10 + b;i < h;i ++){
//            int a1 = i / 10,b1 = i % 10;
//            if(!bo[a1] || !bo[b1]) continue;
//            int t1 = to[a1],t2 = to[b1];
//            if(t2 * 10 + t1 < m){
//                if(i == a * 10 + b){
//                    for(int j = c * 10 + d;j < m;j ++){
//                        int c1 = j / 10,d1 = j % 10;
//                        if(!bo[c1] || !bo[d1]) continue;
//                        int t3 = to[c1],t4 = to[d1];
//                        if(t4 * 10 + t3 < h ){
//                            fl = 1;
//                            cout << a1 << b1 << ":" << c1 << d1 << endl;
//                            break;
//                        }
//                    }
//                }
//                else {
//                    for(int j = 0;j < m;j ++){
//                        int c1 = j / 10,d1 = j % 10;
//                        if(!bo[c1] || !bo[d1]) continue;
//                        int t3 = to[c1],t4 = to[d1];
//                        if(t4 * 10 + t3 < h){
//                            fl = 1;
//                            cout << a1 << b1 << ":" << c1 << d1 << endl;
//                            break;
//                        }
//                    }
//                }
//            }
//            if(fl) break;
//        }
//        if(!fl) cout << "00:00" << endl;
//    }
//    return 0 ;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 5e5 + 10;
//int n,m,a[N];
//int dp[N][22];
//int main(){
//    cin >> n >> m;
//    int mxr = 0;
//    for(int i = 0;i < n;i ++){
//        int l,r;cin >> l >> r;
//        a[l] = max(a[l],r);
//        mxr = max(r,mxr);
//    }
//    for(int i = 1;i <= mxr;i ++) a[i] = max(a[i],a[i - 1]);
//    for(int i = 0;i <= mxr;i ++) dp[i][0] = a[i];
//    for(int j = 1;j <= 20;j ++){
//        for(int i = 0;i <= mxr;i ++){
//            dp[i][j] = dp[dp[i][j - 1]][j - 1];
//        }
//    }
//
//    for(int i = 0;i < m;i ++){
//        int ans = 0;
//        int x,y;cin >> x >> y;
//        for(int j = 20;j >= 0;j --){
//            if(dp[x][j] < y) ans += (1 << j),x = dp[x][j];
//        }
//        if(a[x] >= y) cout << ans + 1 << endl;
//        else cout << - 1 << endl;
//    }
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//
//using namespace std;
//
//int gcd(int a,int b){
//    return !b ? a : gcd(b,a % b);
//}
//int f[1010][1010];
//int main(){
//    int t;scanf("%d",&t);
//    for(int i = 1;i <= 1000;i ++){
//        for(int j = 1;j <= 1000;j ++){
//            f[i][j] = max(f[i][j - 1],f[i - 1][j]) + (gcd(i,j) == 1);
//        }
//    }
//    while(t --){
//        int a,b;
//        scanf("%d%d",&a,&b);
//        printf("%d\n",f[a][b]);
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<algorithm>
//
//using namespace std;
//const int N = 4e3 + 10;
//int a[N][N];
//int sum[N][N];
//bool is[N][N];
//int n,k,t_n;
//int main(){
//    scanf("%d%d",&n,&k);
//    for(int i = 1;i <= n;i ++){
//        for(int j = 1;j <= n;j ++){
//            int t;
//            scanf("%d",&t);
//            a[i + j][n - i + j] = t;
//            is[i + j][n - i + j] = t;
//        }
//    }
//    t_n = n;
//    n = 2 * n - 1;
//    k = 2 * k - 1;
//    for(int i = 1;i <= n;i ++){
//        for(int j = 1;j <= n;j ++){
//            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];
//        }
//    }
//    int maxx = 0;
//    for(int i = 1;i <= n && i + k <= n;i ++){
//        for(int j = 1;j <= n && j + k <= n;j ++){
//            if(!is[i][j]) continue;
//            maxx = max(maxx,sum[i + k][j + k] - sum[i][j + k] - sum[i + k][j] + sum[i][j]);
//        }
//    }
//    printf("%d\n",maxx);
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<cstdlib>
//
//using namespace std;
//const int N = 2e3 + 10;
//typedef long long ll;
//ll n,m,a[N][N],ans,maxx;
//ll read(){
//    ll x = 0,f = 1;
//    char c = getchar();
//    while(c < '0' || c > '9') {
//        if(c == '-') f = -1;
//        c = getchar();
//    }
//    while(c >= '0' && c <= '9') x = x * 10 + c - '0',c = getchar();
//    return x * f;
//}
//
//int main(){
//    n = read(), m = read();
//    for(int i = 1;i <= n;i ++){
//        for(int j = 1;j <= n;j ++){
//            a[i][j] = read();
//            a[i][j] += a[i][j - 1];
//        }
//    }
//    for(int i = 1;i <= n;i ++){
//        for(int j = 1;j <= n;j ++){
//            maxx = 0;
//            maxx += a[i][min(n,j + m - 1)] - a[i][max((ll)0,j - m)];
//            for(int k = 1;k < m;k ++){
//                ll s = min(n,j + m - 1 - k),ss = max((ll)0,j - m + k);
//                if(i + k <= n) maxx += a[i + k][s] - a[i + k][ss];
//                if(i - k >= 1) maxx += a[i - k][s] - a[i - k][ss];
//            }
//            ans = max(ans,maxx);
//        }
//    }
//    printf("%lld\n",ans);
//    return 0;
//}


