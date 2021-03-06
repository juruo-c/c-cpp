//
// Created by 19116 on 2021/3/6.
//

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<cmath>
//#define vc pt
//#define db double
//#define rep(i,a,b) for(int (i) = (a);(i) <= (b);(i) ++)
//#define _rep(i,a,b) for(int (i) = (a);(i) >= (b);(i) --)
//using namespace std;
//const int N = 1e5 + 10;
//const db eps = 1e-8;
//struct pt{
//    db x,y;
//    pt(){}
//    pt(db x,db y):x(x),y(y){}
//};
//pt operator + (pt a,pt b){return pt(a.x + b.x,a.y + b.y);}
//pt operator - (pt a,pt b){return pt(a.x - b.x,a.y - b.y);}
//pt operator * (pt a,db d){return pt(a.x * d,a.y * d);}
//db operator * (pt a,pt b){return a.x * b.y - a.y * b.x;}
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
//const int N = 1e5 + 10;
//ll a[N];ll ans[N];
//int main(){
//    int t;scanf("%d",&t);
//    while(t --){
//        ll n,m;
//        scanf("%lld%lld",&n,&m);
//        for(int i = 1;i <= n;i ++) {
//            scanf("%lld",&a[i]);
//            a[i] += a[i - 1];
//        }
//        for(int i = 1;i <= m;i ++){
//            ll l,r;
//            scanf("%lld%lld",&l,&r);
//            ans[i] = a[r] - a[l - 1];
//        }
//        sort(ans + 1,ans + m + 1);
//        ll res = 0;
//        for(int i = 1;i <= m;i ++) res += ans[i] * i;
//        printf("%lld\n",res);
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e5 + 10,M = 5e5 + 10;
//struct T{
//    int l,r,lz;
//}t[M << 2];
//void build(int i,int l,int r){
//    t[i].l = l,t[i].r = r;
//    t[i].lz = 0;
//    if(l == r) return;
//    int m = l + r >> 1;
//    build(i << 1,l,m);
//    build(i << 1 | 1,m + 1,r);
//}
//
//void push_down(int i){
//    if(t[i].lz){
//        t[i << 1].lz = t[i << 1 | 1].lz = t[i].lz;
//        t[i].lz = 0;
//    }
//}
//void add(int i,int l,int r,int x){
//    if(t[i].l >= l && t[i].r <= r){
//        t[i].lz = x;
//        return;
//    }
//    push_down(i);
//    if(t[i << 1].r >= l) add(i << 1,l,r,x);
//    if(t[i << 1 | 1].l <= r) add(i << 1 | 1,l,r,x);
//}
//int fl,ans;
//void query(int i,int l,int r){
//    if(t[i].l >= l && t[i].r <= r){
//        if(t[i].lz) ans ++;
//        else fl = 1;
//        return ;
//    }
//    push_down(i);
//    if(t[i << 1].r >= l) query(i << 1,l,r);
//    if(t[i << 1 | 1].l <= r) query(i << 1 | 1,l,r);
//}
//int main(){
//    int n,m;
//    scanf("%d%d",&n,&m);
//    build(1,0,M);
//    for(int i = 1;i <= n;i ++){
//        int l,r;scanf("%d%d",&l,&r);
//        add(1,l,r,i);
//    }
//    for(int i = 1;i <= m;i ++){
//        ans = 0,fl = 0;
//        int x,y;
//        scanf("%d%d",&x,&y);
//        query(1,x,y);
////        for(int j = 1;j <= cnt;j ++) cout << ans[j] << " ";
//
//
//        if(fl){
//            puts("-1");
//            continue;
//        }
//
//        printf("%d\n",ans);
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//typedef long long ll;
//const int N = 1e5 + 10;
//ll a[N];
//int main(){
//    int n;scanf("%d",&n);
//    for(int i = 0;i < n;i ++){
//        scanf("%d",&a[i]);
//    }
//    int fl = 0;
//    for(int i = 0;i < n;i ++){
//        if(a[i] >= a[(i + 1) % n] + a[(i - 1 + n) % n])fl = 1;
//    }
//    if(!fl){
//        printf("YES\n");
//        for(int i = 0;i < n;i ++){
//            if(i) printf(" ");
//            printf("%d",a[i]);
//        }
//        printf("\n");
//        return 0;
//    }
//    else printf("NO\n");
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e3 + 10;
//int main(){
//    int tt;cin >> tt;
//    while(tt --){
//        int n,k;cin >> n >> k;
//        int ans = n - k;
//        if(k % 2) ans += (k - 1) / 2;
//        else ans += k / 2;
//        cout << ans << endl;
//        for(int i = (k + 1) / 2;i <= n;i ++) if(i != k)cout << i << " ";
//        cout << endl;
//    }
//    return 0;
//}


//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e5 + 10;
//typedef long long ll;
//ll a[N];
//int main(){
//    int n;cin >> n;
//    for(int i = 0;i < n;i ++){
//        cin >> a[i];
//    }
//    sort(a, a + n);
//    swap(a[n - 1],a[n - 2]);
//    if(a[n - 2] < a[n - 1] + a[n - 3]){
//        cout << "YES" << endl;
//        for(int i = 0;i < n;i ++){
//            if(i) cout << " " ;
//            cout << a[i];
//        }
//        cout << endl;
//    }
//    else cout << "NO" << endl;
//    return 0;
//}


