//
// Created by 19116 on 2021/3/23.
//

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e5 + 10;
//int n,sum[N],q[N],h[N];
//struct node{
//    int s,a;
//    bool operator < (const node& b) const{
//        return a > b.a;
//    }
//}v[N];
//
//int main(){
//    scanf("%d",&n);
//    for(int i = 1;i <= n;i ++) scanf("%d",&v[i].s);
//    for(int i = 1;i <= n;i ++) scanf("%d",&v[i].a);
//    sort(v + 1,v + 1 + n);
//    for(int i = 1;i <= n;i ++) sum[i] = sum[i - 1] + v[i].a;
//    for(int i = 1;i <= n;i ++) q[i] = max(q[i - 1],2 * v[i].s);
//    for(int i = n;i >= 1;i --) h[i] = max(h[i + 1],2 * v[i].s + v[i].a);
//    for(int i = 1;i <= n;i ++) printf("%d\n",max(sum[i] + q[i],sum[i - 1] + h[i]));
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<cstdio>
//
//using namespace std;
//const int N = 510;
//int a[N][N];
//
//int main(){
//    int n;cin >>n;
//    for(int i = 1;i <= n;i ++){
//        for(int j = i + 1;j <= n;j ++){
//            cin >> a[i][j];
//            a[j][i] = a[i][j];
//        }
//    }
//    int ans = 0;
//    for(int i = 1;i <= n;i ++){
//        sort(a[i] + 1,a[i] + 1 + n);
//        ans = max(ans,a[i][n - 1]);
//    }
//    cout << 1 << endl << ans << endl;
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//
//using namespace std;
//const int N = 5e3 + 10;
//int b;int a[N];
//int main(){
//    string s;
//    cin >> s >> b;
//    int cnt = N - 1;
//    for(int i = s.size() - 1;i >= 0;i --) a[cnt --] = s[i] - '0';
//    int tmp = 0;
//    for(int i = 0;i < N;i ++){
//        tmp = tmp * 10 + a[i];
//        a[i] = tmp / b ;
//        tmp %= b;
//    }
//    int i;
//    for(i = 0;i < N;i ++) if(a[i]) break;
//    for(;i < N;i ++) cout << a[i];
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 25;
//int n;
//int g[N][N];
//int len[N];
//string a[N];
//int vis[N];
//int res = 0;
//void dfs(int cur,int nl){
//    bool fl = false;
////    cout << "cur: " << cur << endl;
//    for(int i = 1;i <= n;i ++){
//        if(vis[i] < 2 && g[cur][i]) {
//            vis[i] ++;
//            fl = true;
////            cout << i << " ";
//            dfs(i,nl + len[i] - g[cur][i]);
//            vis[i] --;
//        }
//    }
//    if(!fl)
//    res = max(res,nl);
//}
//
//int work(int x,int y){
//    bool fl = 1;
//    int ky = 0;
//    for(int i = a[x].size() - 1;i >= 0;i --){
//        for(int j = i;j < a[x].size();j ++){
//            if(a[x][j] != a[y][ky ++]){
//                fl = false;
//                break;
//            }
//        }
//
//        if(fl) return a[x].size() - i;
//        ky = 0;
//        fl = 1;
//    }
//    return 0;
//}
//int main(){
//    cin >> n;
//    for(int i = 1;i <= n;i++) {
//        cin >> a[i];
//        len[i] = a[i].size();
//    }
//    for(int i = 1;i <= n;i ++){
//        for(int j = 1;j <= n;j ++){
//            g[i][j] = work(i,j);
//            if(g[i][j] == len[i] || g[i][j] == len[j]) g[i][j] = 0;
//        }
//    }
//
////    for(int i = 1;i <= n;i ++){
////        for(int j = 1;j <= n;j ++){
////            cout << g[i][j] << " " ;
////        }
////        cout << endl;
////    }
//
//    char ch;
//    cin >> ch;
//    int ans = 0;
//    for(int i = 1;i <= n;i ++) {
////        cout << i << " ";
//        res = 0;
//        if(a[i][0] == ch) {
//            vis[i] ++;
//            dfs(i,len[i]);
//            vis[i] --;
//        }
//        ans = max(ans,res);
////        cout << endl;
//    }
//    cout << ans << endl;
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 1e3 + 10;
//int n,c,a[N];
//int ans;
//int vis[N];
//int id;
//void dfs(int cur,int nl){
//    if(nl > c) return;
//    ans = max(ans,nl);
//    if(cur > id) return;
//    vis[cur] = 1;
//    dfs(cur + 1,nl + a[cur]);
//    vis[cur] = 0;
//    dfs(cur + 1,nl);
//}
//
//int main(){
//    scanf("%d%d",&n,&c);
//
//    for(int i = 1;i <= n;i ++){
//        scanf("%d",&a[i]);
//        if(a[i] <= c) id = i;
//    }
//
//    dfs(1,0);
//
//    printf("%d\n",ans);
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e3 + 10;
//long long sum[N],a[N],ans,n,c;
//
//void dfs(int cur,long long now){
//    if(now > c) return;
//    if(sum[cur - 1] + now <= c){
//        ans = max(sum[cur - 1] + now,ans);
//        return ;
//    }
//    ans = max(ans,now);
//    for(int i = 1;i < cur;i ++) dfs(i,now + a[i]);
//}
//
//int main(){
//    cin >> n >> c;
//    for(int i = 1;i <= n;i ++){
//        cin >> a[i];
//        sum[i] = sum[i - 1] + a[i];
//    }
//    dfs(n + 1,0);
//
//    cout << ans << endl;
//    return 0;
//}