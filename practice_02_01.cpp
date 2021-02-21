//
// Created by Administrator on 2021/2/1.
//

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//
//using namespace std;
//const int N = 2e5 + 10;
//const int M = 5e5 + 10;
//int n,m;
//int dis[M][25],maxr;
//
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 1;i <= n;i ++){
//        int l,r;
//        scanf("%d%d",&l,&r);
//        maxr = max(r,maxr);
//        dis[l][0] = max(r,dis[l][0]);
//    }
//    dis[0][0] = max(dis[0][0],0);
//
//    for(int i = 1;i < M;i ++) dis[i][0] = max({dis[i][0],i,dis[i - 1][0]});
//
//    for(int j = 1;j <= 20;j ++){
//        for(int i = 0;i <= maxr;i ++){
//            dis[i][j] = dis[dis[i][j - 1]][j - 1];
//        }
//    }
//
//    while(m -- ){
//        int l,r;
//        scanf("%d%d",&l,&r);
//        if(r > maxr || r > dis[l][20]) puts("-1");
//        else {
//            int ans = 0;
//            for(int i = 20;i >= 0;i --)
//                if(dis[l][i] < r) l = dis[l][i],ans += 1 << i;
//            ans ++;
//            printf("%d\n",ans);
//        }
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cmath>
//#include<algorithm>
//
//using namespace std;
//const int N = 3e5 + 10;
//int n;
//int a[N],last[N];
//int f[N][20],r[N];
//void init(){
//    for(int i = 1;i <= n;i ++) f[i][0] = a[i];
//    for(int j = 1;(1 << j) <= n;j ++){
//        for(int i = 1;i + (1 << j) - 1 <= n;i ++){
//            f[i][j] = max(f[i][j - 1],f[i + (1 << (j - 1))][j - 1]);
//        }
//    }
//}
//
//int query(int l,int r){
//    int k = log2(r - l + 1);
//    return max(f[l][k],f[r - (1 << k) + 1][k]);
//}
//int main(){
//    scanf("%d",&n);
//    for(int i = 1;i <= n;i ++) scanf("%d",&a[i]);
//    r[n + 1] = n;
//    for(int i = n;i >= 1;i --){
//        if(last[a[i]]) r[i] = min(r[i + 1],last[a[i]] - 1);
//        else r[i] = r[i + 1];
//        last[a[i]] = i;
//    }
//
//    init();
//
//    int ans = 0;
//    for(int i = 1;i <= n;i ++){
//        int j = i;
//        while(j <= r[i]){
//            if(query(i,j) == j - i + 1) ans ++,j ++;
//            else j = i + query(i,j) - 1;
//        }
//    }
//
//    printf("%d\n",ans);
//    return 0;
//}

//
//#include<cstdio>
//
//using namespace std;
//const int N = 5e5 + 10;
//struct tree{
//    int l,r,sum;
//}t[N << 2];
//int n,m;
//void push_up(int i){
//    t[i].sum = t[i << 1].sum + t[i << 1 | 1].sum;
//}
//void build(int i,int l,int r){
//    t[i].l = l,t[i].r = r;
//    if(l == r){
//        scanf("%d",&t[i].sum);
//        return;
//    }
//    int mid = (l + r) >> 1;
//    build(i << 1,l , mid);
//    build(i << 1 | 1,mid + 1, r);
//    push_up(i);
//}
//
//void add(int i,int x,int y){
//    if(t[i].l == t[i].r){
//        t[i].sum += y;
//        return;
//    }
//    if(x <= t[i << 1].r) add(i << 1,x, y);
//    else add(i << 1 | 1,x ,y);
//    push_up(i);
//}
//int query(int i,int l,int r){
//    if(t[i].l >= l && t[i].r <= r) return t[i].sum;
//    if(t[i].l > r || t[i].r < l ) return 0;
//    int s = 0;
//    if(t[i << 1].r >= l) s += query(i << 1,l,r);
//    if(t[i << 1 | 1].l <= r) s += query(i << 1 | 1, l, r);
//    return s;
//}
//int main(){
//    scanf("%d%d",&n,&m);
//    build(1,1,n);
//    for(int i = 0;i < m;i ++){
//        int op,x,y;
//        scanf("%d%d%d",&op,&x,&y);
//        if(op == 1) add(1,x,y);
//        else if(op == 2) printf("%d\n",query(1,x,y));
//    }
//    return 0;
//}

//#include<cstdio>
//using namespace std;
//
//const int N = 5e5 + 10;
//int n,m;
//struct tree{
//    int l,r,sum;
//}t[N << 2];
//int a[N];
//
//void build(int i,int l,int r){
//    t[i].l = l,t[i].r = r;
//    t[i].sum = 0;
//    if(l == r) return;
//    int mid = l + r >> 1;
//    build(i << 1, l, mid );
//    build(i << 1 | 1, mid + 1, r);
//}
//
//void add(int i,int l,int r,int k){
//    if(t[i].l >= l && t[i].r <= r){
//        t[i].sum += k;
//        return;
//    }
//    if(t[i << 1].r >= l) add(i << 1,l,r,k);
//    if(t[i << 1 | 1].l <= r) add(i << 1 | 1,l,r,k);
//}
//int ans;
//void query(int i,int pos){
//    ans += t[i].sum;
//    if(t[i].l == t[i].r) return;
//    if(pos <= t[i << 1].r) query(i << 1,pos);
//    else query(i << 1 | 1,pos);
//}
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 1;i <= n;i ++) scanf("%d",&a[i]);
//    build(1,1,n);
//    for(int i = 0;i < m;i ++){
//        int op;
//        scanf("%d",&op);
//        if(op == 1){
//            int x,y,k;
//            scanf("%d%d%d",&x,&y,&k);
//            add(1,x,y,k);
//        }
//        else if(op == 2){
//            int x;
//            scanf("%d",&x);
//            ans = 0;
//            query(1,x);
//            printf("%d\n",ans + a[x]);
//        }
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//typedef long long ll;
//const int N = 1e5 +10;
//struct tree{
//    int l,r,lz;
//    ll sum;
//}t[N << 2];
//int n,m;
//void push_up(int i){
//    t[i].sum = t[i << 1].sum + t[i << 1 | 1].sum;
//}
//void push_down(int i){
//    if(t[i].lz){
//        t[i << 1].lz += t[i].lz;
//        t[i << 1 | 1].lz += t[i].lz;
//        t[i << 1].sum += t[i].lz * (t[i << 1].r - t[i << 1].l + 1);
//        t[i << 1 | 1].sum += t[i].lz * (t[i << 1 | 1].r - t[i << 1 | 1].l + 1);
//        t[i].lz = 0;
//    }
//}
//void build(int i,int l,int r){
//    t[i].l = l,t[i].r = r;
//    t[i].lz = 0;
//    if(l == r){
//        cin >> t[i].sum;
//        return;
//    }
//    int mid = l + r >> 1;
//    build(i << 1, l, mid);
//    build(i << 1 | 1, mid + 1, r);
//    push_up(i);
//}
//
//void add(int i,int l,int r,int k){
//    if(t[i].l >= l && t[i].r <= r){
//        t[i].sum += k * (t[i].r - t[i].l + 1);
//        t[i].lz += k;
//        return;
//    }
//    push_down(i);
//    if(t[i << 1].r >= l) add(i << 1, l, r, k);
//    if(t[i << 1 | 1].l <= r) add(i << 1 | 1, l, r, k);
//    push_up(i);
//}
//
//ll query(int i,int l,int r){
//    if(t[i].l >= l && t[i].r <= r){
//        return t[i].sum;
//    }
//    if(t[i].l > r || t[i].r < l) return 0;
//    push_down(i);
//    ll s = 0;
//    if(t[i << 1].r >= l) s += query(i << 1,l,r);
//    if(t[i << 1 | 1].l <= r) s += query(i << 1 | 1, l, r);
//    return s;
//}
//
//int main(){
//    cin >> n >> m;
//    build(1,1,n);
//    for(int i = 0;i < m;i ++){
//        int op;
//        cin >> op;
//        if(op == 1){
//            int x,y,k;
//            cin >> x >> y >> k;
//            add(1,x,y,k);
//        }
//        else if(op == 2){
//            int x,y;
//            cin >> x >> y;
//            cout << query(1,x,y) << endl;
//        }
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//const int N = 1e5 + 10;
//int n,m,p;
//typedef long long ll;
//struct Tree{
//    ll l,r,alz,mlz;
//    ll sum;
//}t[N << 2];
//
//void push_up(int i){
//    t[i].sum = (t[i << 1].sum + t[i << 1 | 1].sum) % p;
//}
//
//void push_down(int i){
//    int mlz = t[i].mlz,alz = t[i].alz;
//    t[i << 1].sum = (mlz * t[i << 1].sum +(alz * (t[i << 1].r - t[i << 1].l + 1)) % p) % p;
//    t[i << 1 | 1].sum = (mlz * t[i << 1 | 1].sum + (alz * (t[i << 1 | 1].r - t[i << 1 | 1].l + 1)) % p) % p;
//    t[i << 1].mlz = (t[i << 1].mlz * mlz) % p;
//    t[i << 1].alz = (t[i << 1].alz * mlz + alz) % p;
//    t[i << 1 | 1].mlz = (t[i << 1 | 1].mlz * mlz) % p;
//    t[i << 1 | 1].alz = (t[i << 1 | 1].alz * mlz + alz) % p;
//    t[i].alz = 0,t[i].mlz = 1;
//}
//void build(int i,ll l,ll r){
//    t[i].l = l,t[i].r = r;
//    t[i].alz = 0,t[i].mlz = 1;
//    if(l == r){
//        int tmp;
//        cin >> tmp;
//        t[i].sum = tmp % p;
//        return;
//    }
//    ll mid = l + r >> 1;
//    build(i << 1, l, mid);
//    build(i << 1 | 1,mid + 1, r);
//    push_up(i);
//}
//void add(int i,ll l,ll r,ll k){
//    if(t[i].l >= l && t[i].r <= r){
//        t[i].alz = (t[i].alz + k) % p;
//        t[i].sum = (t[i].sum + k * (t[i].r - t[i].l + 1)) % p;
//        return;
//    }
//    push_down(i);
//    if(t[i << 1].r >= l) add(i << 1,l,r,k);
//    if(t[i << 1 | 1].l <= r) add(i << 1 | 1, l, r, k);
//    push_up(i);
//}
//
//void mul(int i,ll l,ll r,ll k){
//    if(t[i].l >= l && t[i].r <= r){
//        t[i].mlz = t[i].mlz * k % p;
//        t[i].alz = t[i].alz * k % p;
//        t[i].sum = t[i].sum * k % p;
//        return;
//    }
//    push_down(i);
//    if(t[i << 1].r >= l) mul(i << 1,l,r,k);
//    if(t[i << 1 | 1].l <= r) mul(i << 1 | 1,l,r,k);
//    push_up(i);
//}
//
//ll query(int i,ll l,ll r){
//    if(t[i].l >= l && t[i].r <= r){
//        return t[i].sum;
//    }
//    push_down(i);
//    ll s = 0;
//    if(t[i << 1].r >= l) s = (s + query(i << 1,l,r)) % p;
//    if(t[i << 1 | 1].l <= r) s = (s + query(i << 1 | 1,l ,r)) % p;
//    return s;
//}
//int main(){
//    cin >> n >> m >> p;
//    build(1,1,n);
//    for(int i = 0;i < m;i ++){
//        int op;
//        cin >> op;
//        if(op == 1){
//            ll x,y,k;
//            cin >> x >> y >> k;
//            mul(1,x,y,k);
//        }
//        else if(op == 2){
//            ll x,y,k;
//            cin >> x >> y >> k;
//            add(1,x,y,k);
//        }
//        else if(op == 3){
//            ll x,y;
//            cin >> x >> y;
//            cout << query(1,x,y) << endl;
//        }
//    }
//    return 0;
//}

//#include<cstdio>
//
//using namespace std;
//const int N = 5e5 + 10;
//struct tree{
//    int l,r,sum;
//}t[N << 2];
//void build(int i,int l,int r){
//    t[i].l = l,t[i].r = r;
//    if(l == r){
//        scanf("%d",&t[i].sum);
//        return;
//    }
//    int mid = l + r >> 1;
//    build(i << 1,l,mid);
//    build(i << 1 | 1,mid + 1,r);
//    t[i].sum = t[i << 1].sum + t[i << 1 | 1].sum;
//}
//
//void add(int i,int pos,int k){
//    if(t[i].r == t[i].l){
//        t[i].sum += k;
//        return;
//    }
//    if(pos <= t[i << 1].r) add(i << 1,pos,k);
//    else add(i << 1 | 1,pos,k);
//    t[i].sum = t[i << 1].sum + t[i << 1 | 1].sum;
//}
//
//int query(int i,int l,int r){
//    if(t[i].l >= l && t[i].r <= r) return t[i].sum;
//    if(t[i].l > r || t[i].r < l) return 0;
//    int s = 0;
//    if(t[i << 1].r >= l) s += query(i << 1,l,r);
//    if(t[i << 1 | 1].l <= r) s += query(i << 1 | 1,l,r);
//    return s;
//}
//int main(){
//    int kase = 0;
//    int tt; scanf("%d",&tt);
//    while(tt --){
//        int n;scanf("%d",&n);
//        build(1,1,n);
//        char s[20];
//        printf("Case %d:\n",++kase);
//        while(scanf("%s",s) != EOF && s[0] != 'E'){
//            int x,y;scanf("%d%d",&x,&y);
//            if(s[0] == 'Q') printf("%d\n",query(1,x,y));
//            else if(s[0] == 'A') add(1,x,y);
//            else if(s[0] == 'S') add(1,x,-y);
//        }
//    }
//    return 0;
//}
//

//#include<cstdio>
//#include<iostream>
//
//using namespace std;
//const int N = 2e5 + 10;
//struct tree{
//    int l,r,sum;
//}t[N << 2];
//void build(int i,int l,int r){
//    t[i].l = l,t[i].r = r;
//    if(l == r){
//        scanf("%d",&t[i].sum);
//        return ;
//    }
//    int mid = l + r >> 1;
//    build(i << 1,l,mid);
//    build(i << 1 | 1,mid + 1,r);
//    t[i].sum = max(t[i << 1].sum,t[i << 1 | 1].sum);
//}
//
//void change(int i,int pos,int k){
//    if(t[i].l == t[i].r){
//        t[i].sum = k;
//        return;
//    }
//    if(t[i << 1].r >= pos) change(i << 1,pos,k);
//    else change(i << 1 | 1,pos,k);
//    t[i].sum = max(t[i << 1].sum,t[i << 1 | 1].sum);
//}
//
//int query(int i,int l,int r){
//    if(t[i].l >= l && t[i].r <= r) return t[i].sum;
//    int s = 0;
//    if(t[i << 1].r >= l) s = max(s,query(i << 1,l,r));
//    if(t[i << 1 | 1].l <= r) s = max(s,query(i << 1 | 1,l ,r));
//    return s;
//}
//int main(){
//    int n,m;
//    while(~scanf("%d%d",&n,&m)){
//        build(1,1,n);
//        for(int i = 0;i < m;i ++){
//            char ch;int x,y;
//            scanf("\n%c%d%d",&ch,&x,&y);
//            if(ch == 'Q') printf("%d\n",query(1,x,y));
//            else change(1,x,y);
//        }
//    }
//    return 0;
//}

//#include<cstdio>
//
//using namespace std;
//const int N = 1e5 + 10;
//typedef long long ll;
//struct tree{
//    int l,r;ll lz;
//    ll sum;
//}t[N << 2];
//void push_up(int i){
//    t[i].sum = t[i << 1].sum + t[i << 1 | 1].sum;
//}
//void push_down(int i){
//    if(t[i].lz){
//        t[i << 1].lz += t[i].lz;
//        t[i << 1 | 1].lz += t[i].lz;
//        t[i << 1].sum += t[i].lz * (t[i << 1].r - t[i << 1].l + 1);
//        t[i << 1 | 1].sum += t[i].lz * (t[i << 1 | 1].r - t[i << 1 | 1].l + 1);
//        t[i].lz = 0;
//    }
//}
//void build(int i,int l,int r){
//    t[i].l = l,t[i].r = r,t[i].lz = 0;
//    if(l == r){
//        scanf("%lld",&t[i].sum);
//        return;
//    }
//    int mid = l + r >> 1;
//    build(i << 1,l,mid);
//    build(i << 1 | 1,mid + 1,r);
//    push_up(i);
//}
//
//void add(int i,int l,int r,int k){
//    if(t[i].l >= l && t[i].r <= r){
//        t[i].sum += k * (t[i].r - t[i].l + 1);
//        t[i].lz +=k;
//        return;
//    }
//    push_down(i);
//    if(t[i << 1].r >= l) add(i << 1,l,r,k);
//    if(t[i << 1 | 1].l <= r) add(i << 1 | 1,l,r,k);
//    push_up(i);
//}
//
//ll query(int i,int l,int r){
//    if(t[i].l >= l && t[i].r <= r){
//        return t[i].sum;
//    }
//    if(t[i].l > r || t[i].r < l) return 0;
//    push_down(i);
//    ll s = 0;
//    if(t[i << 1].r >= l) s += query(i << 1,l,r);
//    if(t[i << 1 | 1].l <= r) s += query(i << 1 | 1,l,r);
//    return s;
//}
//int main(){
//    int n,m;
//    scanf("%d%d",&n,&m);
//    build(1,1,n);
//    for(int i = 0;i < m;i ++){
//        char ch;
//        scanf("\n%c",&ch);
//        if(ch == 'Q'){
//            int x,y;scanf("%d%d",&x,&y);
//            printf("%lld\n",query(1,x,y));
//        }
//        else {
//            int x,y,k;
//            scanf("%d%d%d",&x,&y,&k);
//            add(1,x,y,k);
//        }
//    }
//    return 0;
//}
//












