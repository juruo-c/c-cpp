//
// Created by Administrator on 2021/2/2.
//

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e4 + 10;
//struct tree{
//    int l,r,lz;
//}t[N << 3];
//
//struct node{
//    int l,r;
//}ps[N << 2];
//
//int vis[N];int ans;
//void build(int i,int l,int r){
//    t[i].l = l,t[i].r = r;
//    t[i].lz = 0;
//    if(l == r) return;
//    int mid = l + r >> 1;
//    build(i << 1,l, mid);
//    build(i << 1 | 1,mid + 1,r);
//}
//void push_down(int i){
//    if(t[i].lz){
//        t[i << 1].lz = t[i << 1 | 1].lz = t[i].lz;
//        t[i].lz = 0;
//    }
//}
//void update(int i,int l,int r,int k){
//    if(t[i].l >= l && t[i].r <= r){
//        t[i].lz = k;
//        return;
//    }
//    push_down(i);
//    if(t[i << 1].r >= l) update(i << 1,l,r,k);
//    if(t[i << 1 | 1].l <= r) update(i << 1 | 1,l,r,k);
//}
//
//void query(int i,int l,int r){
//    if(t[i].lz){
//        if(!vis[t[i].lz]){
//            ans ++;
//            vis[t[i].lz] = 1;
//        }
//        return;
//    }
//    if(t[i].l == t[i].r) return;
//    push_down(i);
//    if(t[i << 1].r >= l) query(i << 1,l,r);
//    if(t[i << 1 | 1].l <= r) query(i << 1 | 1,l,r);
//}
//int lsh[N << 2];
//int main(){
//    int tt;scanf("%d",&tt);
//    while(tt --){
//        int id = 0;
//        memset(lsh,0,sizeof(lsh));
//        memset(vis,0,sizeof(vis));
//        ans = 0;
//        int n;scanf("%d",&n);
//        for(int i = 0;i < n;i ++){
//            scanf("%d %d",&ps[i].l,&ps[i].r);
//            lsh[id ++] = ps[i].l,lsh[id ++] = ps[i].r;
//        }
//        sort(lsh,lsh + id);
//        int cnt = unique(lsh,lsh + id) - lsh;
//        build(1,1,cnt + 1);
//        for(int i = 0;i < n;i ++){
//            int L = lower_bound(lsh,lsh + cnt,ps[i].l) - lsh + 1;
//            int R = lower_bound(lsh,lsh + cnt,ps[i].r) - lsh + 1;
//            update(1,L,R,i + 1);
//        }
//        query(1,1,cnt + 1);
//        printf("%d\n",ans);
//    }
//    return 0;
//}

//#include<cstdio>
//
//using namespace std;
//const int N = 1e5 + 10;
//int n,m;
//struct tree{
//    int l,r,lz;
//}t[N << 2];
//void build(int i,int l,int r){
//    t[i].l = l,t[i].r = r;
//    t[i].lz = 1;
//    if(l == r)return;
//    int mid = l + r >> 1;
//    build(i << 1,l ,mid);
//    build(i << 1 | 1,mid + 1,r);
//}
//void push_down(int i){
//    if(t[i].lz){
//        t[i << 1].lz = t[i << 1 | 1].lz = t[i].lz;
//        t[i].lz = 0;
//    }
//}
//void update(int i,int l,int r,int k){
//    if(t[i].l >= l && t[i].r <= r){
//        t[i].lz = k;
//        return;
//    }
//    push_down(i);
//    if(t[i << 1].r >= l) update(i << 1,l,r,k);
//    if(t[i << 1 | 1].l <= r) update(i << 1 | 1,l,r,k);
//}
//int ans ;
//void query(int i,int l,int r){
//    if(t[i].lz){
//        ans += t[i].lz * (t[i].r - t[i].l + 1);
//        return;
//    }
//    push_down(i);
//    if(t[i << 1].r >= l) query(i << 1,l,r);
//    if(t[i << 1 | 1].l <= r) query(i << 1 | 1,l ,r);
//}
//int main(){
//    int tt;scanf("%d",&tt);
//    int kase = 0;
//    while(tt --){
//        ans = 0;
//        scanf("%d%d",&n,&m);
//        build(1,1,n);
//        for(int i = 0;i < m;i ++) {
//            int x,y,z;
//            scanf("%d%d%d",&x,&y,&z);
//            update(1,x,y,z);
//        }
//        query(1,1,n);
//        printf("Case %d: The total value of the hook is %d.\n", ++kase,ans);
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//
//using namespace std;
//const int N = 1e4 + 10;
//struct tree{
//    int l,r,lz;
//}t[N << 2];
//struct node{
//    int l,r,col;
//}ps[N];
//int n;int ans[N];
//void build(int i,int l,int r){
//    t[i].l = l,t[i].r = r;
//    t[i].lz = -1;
//    if(l == r)return;
//    int mid = l + r >> 1;
//    build(i << 1,l,mid);
//    build(i << 1 | 1,mid + 1,r);
//}
//void push_down(int i){
//    if(t[i].lz != -1){
//        t[i << 1].lz = t[i << 1 | 1].lz = t[i].lz;
//        t[i].lz = -1;
//    }
//}
//
//void color(int i,int l,int r,int k){
//    if(t[i].l >= l && t[i].r <= r){
//        t[i].lz = k;
//        return;
//    }
//    push_down(i);
//    if(t[i << 1].r >= l) color(i << 1,l,r,k);
//    if(t[i << 1 | 1].l <= r) color(i << 1 | 1,l,r,k);
//}
//int lz;
//void query(int i,int l,int r){
//    if(t[i].l == t[i].r){
//        if(t[i].lz != -1 && t[i].lz != lz)
//            ans[t[i].lz] ++;
//        lz = t[i].lz;
//        return;
//    }
//    push_down(i);
//    if(t[i << 1].r >= l) query(i << 1,l,r);
//    if(t[i << 1 | 1].l <= r) query(i << 1 | 1,l,r);
//}
//int main(){
//    while(cin >> n){
//        memset(ans,0,sizeof(ans));
//        int L = N,R = 0;
//        for(int i = 0;i < n;i ++){
//            cin >> ps[i].l >> ps[i].r >> ps[i].col;
//            L = min(L,ps[i].l);
//            R = max(R,ps[i].r);
//        }
//        build(1,L + 1,R);
//        for(int i = 0;i < n;i ++){
//            color(1,ps[i].l + 1,ps[i].r,ps[i].col);
//        }
//        lz = -1;
//        query(1,L + 1,R);
//        for(int i = 0;i < N;i ++){
//            if(ans[i]){
//                cout << i << " " << ans[i] << endl;
//            }
//        }
//        cout << endl;
//    }
//    return 0;
//}


//#include<cstdio>
//#include<iostream>
//
//using namespace std;
//const int N = 5e4 + 10;
//int n,m;
//
//struct tree{
//    int l,r;
//    int maxx,minn;
//}t[N << 2];
//
//void build(int i,int l,int r){
//    t[i].l = l;t[i].r = r;
//    if(l == r){
//        scanf("%d",&t[i].maxx);
//        t[i].minn = t[i].maxx;
//        return;
//    }
//    int mid = l + r >> 1;
//    build(i << 1,l ,mid);
//    build(i << 1 | 1,mid + 1,r);
//    t[i].minn = min(t[i << 1].minn,t[i << 1 | 1].minn);
//    t[i].maxx = max(t[i << 1].maxx,t[i << 1 | 1].maxx);
//}
//int maxn,minx;
//void query(int i,int l,int r){
//    if(t[i].l >= l && t[i].r <= r){
//        maxn = max(maxn,t[i].maxx);
//        minx = min(minx,t[i].minn);
//        return;
//    }
//    if(t[i].l > r || t[i].r < l) return;
//    if(t[i << 1].r >= l) query(i << 1,l,r);
//    if(t[i << 1 | 1].l <= r) query(i << 1 | 1,l,r);
//}
//int main(){
//    scanf("%d%d",&n,&m);
//    build(1,1,n);
//    for(int i = 0;i < m;i ++){
//        maxn = 0;
//        minx = 0x3f3f3f3f;
//        int l,r;
//        scanf("%d%d",&l,&r);
//        query(1,l,r);
//        printf("%d\n",maxn - minx);
//    }
//    return 0;
//}

//#include<cstdio>
//#include<iostream>
//#include<cmath>
//
//using namespace std;
//const int N = 1e5 + 10;
//typedef long long ll;
//struct tree{
//    int l,r;
//    ll sum;
//}t[N << 2];
//void build(int i,int l,int r){
//    t[i].l = l,t[i].r = r;
//    if(l == r){
//        scanf("%lld",&t[i].sum);
//        return;
//    }
//    int mid = l + r >> 1;
//    build(i << 1,l,mid);
//    build(i << 1 | 1,mid + 1,r);
//    t[i].sum = t[i << 1].sum + t[i << 1 | 1].sum;
//}
//
//void update(int i,int l,int r){
//    if(t[i].l == t[i].r){
//        t[i].sum = sqrt(t[i].sum);
//        return ;
//    }
//    if(t[i].l >= l && t[i].r <= r && t[i].sum == t[i].r - t[i].l + 1)
//        return;
//    if(t[i << 1].r >= l) update(i << 1,l,r);
//    if(t[i << 1 | 1].l <= r) update(i << 1 | 1,l,r);
//    t[i].sum = t[i << 1].sum + t[i << 1 | 1].sum;
//}
//
//ll query(int i,int l,int r){
//    if(t[i].l >= l && t[i].r <= r){
//        return t[i].sum;
//    }
//    if(t[i].l > r || t[i].r < l) return 0;
//    ll s = 0;
//    if(t[i << 1].r >= l) s += query(i << 1,l,r);
//    if(t[i << 1 | 1].l <= r) s += query(i << 1 | 1,l,r);
//    return s;
//}
//int main(){
//    int n,m;
//    int kase = 0;
//    while(~scanf("%d",&n)){
//        int a,b,c;
//        build(1,1,n);
//        scanf("%d",&m);
//        printf("Case #%d:\n",++kase);
//        while(m --){
//            scanf("%d%d%d",&a,&b,&c);
//            if(b > c) swap(b,c);
//            if(a){
//                printf("%lld\n",query(1,b,c));
//            }
//            else{
//                update(1,b,c);
//            }
//        }
//        printf("\n");
//    }
//
//    return 0;
//}