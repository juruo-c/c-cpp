//
// Created by 19116 on 2021/3/2.
//
//
//#include<iostream>
//#include<vector>
//#include<cstdio>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e4 + 10;
//int n,d = 0;
//int d1[N],d2[N];
//vector<int> e[N];
//void dfs(int u,int fa){
//    for(auto v : e[u]){
//        if(v == fa) continue;
//        dfs(v,u);
//        int t = d1[v] + 1;
//        if(t > d1[u]) d2[u] = d1[u],d1[u] = t;
//        else if(t > d2[u]) d2[u] = t;
//    }
//    d = max(d,d1[u] + d2[u]);
//}
//int main(){
//
//    return 0;
//}
//
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<cmath>
//#define db double
//using namespace std;
//const int N = 200,INF = 1e9;
//char G[N][N];
//int n;db f[N][N];
//struct node{
//    db x,y;
//}a[N];
//db d[N];
//int fa[N];
//int getf(int x){return x == fa[x] ? x : fa[x] = getf(fa[x]);}
//db gd(int i,int j){
//    return sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y));
//}
//int main(){
//    scanf("%d",&n);
//    for(int i = 1;i <= n;i ++){
//        for(int j = 1;j <= n;j ++){
//            if(i == j) f[i][j] = 0;
//            else f[i][j] = INF;
//        }
//    }
//    for(int i = 1;i <= n;i ++) fa[i] = i;
//    for(int i = 1;i <= n;i ++)scanf("%lf%lf",&a[i].x, &a[i].y);
//    for(int i = 1;i <= n;i ++){
//        for(int j = 1;j <= n;j ++){
//            scanf("\n%c",&G[i][j]);
//            if(G[i][j] == '1'){
//                f[i][j] = gd(i,j);
//                int fi = getf(i);
//                int fj = getf(j);
//                if(fi != fj) fa[fi] = fj;
//            }
//        }
//    }
//
//    for(int k = 1;k <= n;k ++){
//        for(int i = 1;i <= n;i ++){
//            for(int j = 1;j <= n;j ++){
//                f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
//            }
//        }
//    }
//
//    db now = 0;
//    for(int i = 1;i <= n;i ++){
//        for(int j = 1;j <= n;j ++){
//            if(f[i][j] != INF && i != j){
//                d[i] = max(f[i][j],d[i]);
//            }
//        }
//        now = max(d[i],now);
//    }
//
//    db ans = 1e9;
//    for(int i = 1;i <= n;i ++){
//        for(int j = i + 1;j <= n;j ++){
//            int fi = getf(i);
//            int fj = getf(j);
//            if(f[i][j] == INF && fi != fj){
//                ans = min(ans,gd(i,j) + d[i] + d[j]);
//            }
//        }
//    }
//
//    ans = max(now,ans);
//
//    printf("%.6f",ans);
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//
//int main(){
//    int t;
//    cin >> t;
//    string s;
//    while(t --){
//        int fl = 1;
//        cin >> s;
//        if(s[0] == s[s.size() - 1]) fl = 0;
//        int a = 0,b = 0,c = 0;
//        for(int i = 0;i < s.size();i ++){
//            if(s[i] == 'A') a ++;
//            if(s[i] == 'B') b ++;
//            if(s[i] == 'C') c ++;
//        }
//        if(a + b != c && a + c != b && b + c != a) fl = 0;
//
//
//        if(fl) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//const int N = 1e3 + 10;
//int main(){
//    int tt;cin >> tt;
//    while(tt --){
//        string s;cin >> s;
//        if(s[0] == s[s.size() - 1]){
//            cout << "NO" << endl;
//            continue;
//        }
//        char stk[N];int top = 0;
//        stk[++ top] = s[0];
//
//        for(int i = 1;i < s.size();i ++){
//            if(s[i] != stk[top] && top) top --;
//            else stk[++ top] = s[i];
//        }
//        if(top) cout << "NO" << endl;
//        else cout << "YES" << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//const int N = 1e3 + 10;
//int main(){
//    int tt;cin >> tt;
//    while(tt --){
//        string s;cin >> s;
//        char c[N];
//        if(s[0] == s[s.size() - 1]){
//            cout << "NO" << endl;
//            continue;
//        }
//        char st = s[0];
//        char ed = s[s.size() - 1];
//        for(int i = 0;i < s.size();i ++){
//            if(s[i] == st) c[i] = '(';
//            else if(s[i] == ed) c[i] = ')';
//            else c[i] = s[i];
//        }
////        for(int i = 0;i < s.size();i ++)
////        cout << c[i] ;
////        cout << endl;
//        char t[N];
//        for(int i = 0;i < s.size();i ++) t[i] = c[i];
//
//        {
//            for(int i = 0;i < s.size();i ++){
//                if(isalpha(t[i])) t[i] = '(';
//            }
//            char stk[N];int top = 0;
//            stk[++ top] = t[0];
//            for(int i = 1;i < s.size();i ++){
//                if(t[i] != stk[top] && top) top --;
//                else stk[++ top] = t[i];
//                if(top >= 1 && stk[top] == ')') break;
//            }
//            if(!top){
//                cout << "YES" << endl;
//                continue;
//            }
//        }
//
//        {
//            for(int i = 0;i < s.size();i ++){
//                if(isalpha(c[i])) c[i] = ')';
//            }
//            char stk[N];int top = 0;
//            stk[++ top] = c[0];
//            for(int i = 1;i < s.size();i ++){
//                if(c[i] != stk[top] && top) top --;
//                else stk[++ top] = c[i];
//                if(top >= 1 && stk[top] == ')') break;
//            }
//            if(!top){
//                cout << "YES" << endl;
//                continue;
//            }
//        }
//        cout << "NO" << endl;
//    }
//    return 0;
//}