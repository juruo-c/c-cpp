//
// Created by 19116 on 2021/3/17.
//

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//const int N = 1010;
//int n,m;
//int a[N][N];
//bool vis[N][N];
//struct P{
//    int x,y;
//};
//int dir[4][2] = {1,0,-1,0,0,1,0,-1};
//bool check(int mid){
//    memset(vis,0,sizeof(vis));
//    queue<P> q;
//    P cur,next;
//    cur.x = 0,cur.y = 0;
//    q.push(cur);
//    vis[0][0] = 1;
//    while(!q.empty()){
//        P u = q.front();q.pop();
//        if(u.x == n) return true;
//        for(int i = 0;i < 4;i ++){
//            int tx = u.x + dir[i][0];
//            int ty = u.y + dir[i][1];
//            if(tx >= 0 && ty >= 0 && tx < n && ty < n && !vis[tx][ty] && a[tx][ty] <= mid){
//                vis[tx][ty] = 1;
//                next.x = tx,next.y = ty;
//                q.push(next);
//            }
//        }
//    }
//    return false;
//}
//
//int main(){
//    cin >> n >> m;
//    int minn = 0x3f3f3f3f,maxx = 0;
//    for(int i = 0;i < n;i ++){
//        for(int j = 0;j < m;j ++){
//            cin >> a[i][j];
//            minn = min(minn,a[i][j]);
//            maxx = max(maxx,a[i][j]);
//        }
//    }
//
//    int l = minn,r = maxx;
//    int ans;
//    while(l <= r){
//        int mid = (l + r) / 2;
//        if(check(mid)) r = mid - 1,ans = mid;
//        else l = mid + 1;
//    }
//
//    cout << ans << endl;
//    return 0;
//}


//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//const int N = 1010,INF = 0x3f3f3f3f;
//int dir[4][2] = {1,0,-1,0,0,1,0,-1};
//int a[N][N],vis[N][N];
//int n,m;
//
//bool bfs(int maxn){
//    queue<pair<int,int> > q;
//    q.push(make_pair(1,1));
//    vis[1][1] = 1;
//    while(!q.empty()){
//        int xx = q.front().first;
//        int yy = q.front().second;
//        q.pop();
//        if(xx == n) return true;
//        for(int i = 0;i < 4;i ++){
//            int tx = xx + dir[i][0];
//            int ty = yy + dir[i][1];
//            if(tx < 1 || ty < 1 || tx > n || ty > m || vis[tx][ty] || a[tx][ty] > maxn)
//                continue;
//            vis[tx][ty] = 1;
//            q.push(make_pair(tx,ty));
//        }
//    }
//    return false;
//}
//
//int main(){
//    cin >> n >> m;
//    int r = 0,l = INF;
//    for(int i = 1;i <= n;i ++){
//        for(int j = 1;j <= m;j ++){
//            cin >> a[i][j];
//            r = max(r,a[i][j]);
//            l = min(l,a[i][j]);
//        }
//    }
//    int ans;
//    while(l <= r){
//        int mid = (l + r) >> 1;
//        memset(vis,0,sizeof(vis));
//        if(bfs(mid)) r = mid - 1,ans = mid;
//        else l = mid + 1;
//    }
//
//    cout << ans << endl;
//    return 0;
//}
//
//#include<cstdio>
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 2e5 + 10;
//typedef long long ll;
//int w[N],v[N],l[N],r[N];
//ll sum[N],val[N];
//ll s;
//ll Y,ss;
//int n,m,mx = -1,mn = 0x3f3f3f3f;
//
//bool check(int W){
//    Y = 0,ss = 0;
//    memset(sum,0,sizeof(sum));
//    memset(val,0,sizeof(val));
//
//    for(int i = 1;i <= n;i ++){
//        if(w[i] >= W) sum[i] = sum[i - 1] + 1,val[i] = val[i - 1] + v[i];
//        else sum[i] = sum[i - 1],val[i] = val[i - 1];
//    }
//
//    for(int i = 1;i <= m;i ++) Y += (sum[r[i]] - sum[l[i] - 1]) * (val[r[i]] - val[l[i] - 1]);
//    ss = llabs(Y - s);
//    if(Y > s) return true;
//    else return false;
//}
//int main(){
//    scanf("%d%d%lld",&n,&m,&s);
//    for(int i = 1;i <= n;i ++){
//        scanf("%d%d",&w[i],&v[i]);
//        mx = max(mx,w[i]);
//        mn = min(mn,w[i]);
//    }
//    for(int i = 1;i <= m;i ++)scanf("%d%d",&l[i],&r[i]);
//    int left = mn - 1,right = mx + 2;
//
//    ll ans = 99999999999999999;
//    while(left <= right){
//        int mid = left + right >> 1;
//        if(check(mid)) left = mid + 1;
//        else right = mid - 1;
//        ans = min(ans,ss);
//    }
//
//    printf("%lld\n",ans);
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<cstdio>
//
//using namespace std;
//typedef long long ll;
//const int N = 1e6 + 10;
//int a[N];int d[N],s[N],t[N];
//int n,m;
//
//bool check(int mid){
//    ll c[N] = {0};
//    for(int i = 1;i <= mid;i ++){
//        c[s[i]] += d[i];c[t[i] + 1] -= d[i];
//    }
//    for(int i = 1;i <= n;i ++) c[i] += c[i - 1];
//    for(int i = 1;i <= n;i ++){
//        if(c[i] > a[i]) return false;
//    }
//    return true;
//}
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 1;i <= n;i ++) scanf("%d",&a[i]);
//    for(int i = 1;i <= m;i ++){
//        scanf("%d%d%d",&d[i],&s[i],&t[i]);
//    }
//    int l = 1,r = m;
//    if(check(m)) { puts("0"); return 0;}
//    while(l < r){
//        int mid = (l + r) / 2;
//        if(check(mid)) l = mid + 1;
//        else r = mid;
//    }
//    printf("-1\n%d\n",l);
//    return 0;
//}

//
//#include<iostream>
//#include<cstdio>
//#define ll long long
//using namespace std;
//const int N=100007;
//struct node{
//    int l,r;
//    ll sum,lazy;
//}a[N<<2];
//ll num[N],b[N];
//int n,m;
//void update(int k)//
//{
//    a[k].sum=a[k<<1].sum+a[k<<1|1].sum;//
//}
//void build(int k,int l,int r)///k属于4*n 表示树  l和r在n之内 表示序号
//{
//    a[k].l=l,a[k].r=r;
//    a[k].lazy=0;
//    if(l==r)
//    {
//        a[k].sum=num[l];
//        return;
//    }
//    int mid=(l+r)/2;///其实现在当前区间的左右节点也是当前节点的左右节点
//    build(k<<1,l,mid);
//    build(k<<1|1,mid+1,r);
//    update(k);//如果出现更新必然是需要update的
//}
//
//void pushdown(int k)
//{
//
//    if(a[k].lazy)
//    {
//        a[k<<1].lazy+=a[k].lazy;
//        a[k<<1|1].lazy+=a[k].lazy;
//        a[k<<1].sum+=(a[k<<1].r-a[k<<1].l+1)*a[k].lazy;
//        a[k<<1|1].sum+=(a[k<<1|1].r-a[k<<1|1].l+1)*a[k].lazy;//
//        a[k].lazy=0;
//    }
//
//}
//void changesegment(int k,int l,int r,ll x)
//{
//    ///四种情况
//    if(a[k].l>=l&&a[k].r<=r)
//    {
//        a[k].lazy+=x;
//        a[k].sum+=(a[k].r-a[k].l+1)*x;
//        return;
//    }
//    pushdown(k);
//    if(a[k<<1].r>=l)changesegment(k<<1,l,r,x);
//    if(a[k<<1|1].l<=r)changesegment(k<<1|1,l,r,x);
//    update(k);
//
//}
//ll query(int l,int r,int k)
//{
//    if(a[k].l >= l && a[k].r <= r) return a[k].sum;
//    pushdown(k);
//    ll s=0;
//    if(a[k<<1].r>=l)s+=query(k<<1,l,r);
//    if(a[k<<1|1].l<=r)s+=query(k<<1|1,l,r);
//    return s;
//
//}
//int main()
//{
//    cin>>n>>m;
//    for(int i=1;i<=n;i++)
//    {
//
//        scanf("%lld",&b[i]);
//        num[i]=b[i]+num[i-1];
//    }
//    build(1,1,n);
////    for(int i=1;i<=16;i++)
////    {
////        printf("l:%d r:%d i:%d\n",a[i].l,a[i].r,i);
////    }
//    while(m--)
//    {
//        string op;
//        cin>>op;
//        if(op=="Modify")
//        {
//            ll z;
//            int x;
//            scanf("%d%lld",&x,&z);
//            changesegment(1,x,n,z-b[x]);
//        }
//        else if(op=="Query")
//        {
//            int x;
//            scanf("%d",&x);
//            printf("%lld\n",query(1,x,1));
//        }
//    }
//
//    return 0;
//}'

#include<iostream>
#include<cstring>

using namespace std;
const int N = 1e6 + 10;
int n,m;
int c[N],sum[N],s[N],t[N],d[N],a[N];

bool check(int x){
    memset(c,0,sizeof(c));
    for(int i = 1;i <= x;i ++){
        c[s[i]] += d[i];
        c[t[i] + 1] -= d[i];
    }
    for(int i = 1;i <= n;i ++){
        sum[i] = sum[i - 1] + c[i];
        if(sum[i] > a[i]) return false;
    }
    return true;
}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++) cin >> a[i];
    for(int i = 1;i <= m;i ++) cin >> d[i] >> s[i] >> t[i];
    int l = 1,r = m;
    if(check(m)){cout << 0 << endl;return 0;}
    while(l < r){
        int mid = (l + r) / 2;
        if(check(mid)) l = mid + 1;
        else r = mid;
    }
    cout << -1 << endl << l << endl;
    return 0;
}