//
// Created by Administrator on 2021/2/4.
//

//#include<iostream>
//#include<cstdio>
//
//using namespace std;
//const int N = 1e6 + 10;
//int n,a;
//
//int main(){
//    int t;
//    scanf("%d",&t);
//    while(t --){
//        scanf("%d",&n);
//        long long sum = 0;
//        int maxx = 0;
//        for(int i = 1;i <= n;i ++){
//            scanf("%d",&a);
//            maxx = max(a,maxx);
//            sum += a;
//        }
//
//        sum -= maxx;
//        if(sum + 1 >= maxx) printf("Yes\n");
//        else printf("No\n");
//    }
//    return 0;
//}

//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//const int N = 1e6 + 10;
//typedef long long ll;
//ll a[N],drawer[N];
//ll s[N];
//int c,n;
//int main(){
//    while(~scanf("%d%d",&c,&n) && c && n){
//        memset(drawer,-1,sizeof(drawer));
//        drawer[0] = 0;
//        for(int i = 1;i <= n;i ++){
//            scanf("%lld",&a[i]);
//            a[i] += a[i - 1];
//        }
//
//        for(int i = 1;i <= n;i ++){
//            if(drawer[a[i] % c] != -1){
//                for(int j = drawer[a[i] % c] + 1;j < i;j ++){
//                    printf("%d ",j);
//                }
//                printf("%d\n",i);
//                break;
//            }
//            drawer[a[i] % c] = i;
//        }
//    }
//    return 0;
//}

//#include<cstdio>
//#include<cstring>
//using namespace std;
//const int N = 1e4 + 10;
//
//int a[N],d[N];
//int s[N];
//int main(){
//    int n;
//    scanf("%d",&n);
//    for(int i = 1;i <= n;i ++){
//        scanf("%d",&a[i]);
//        s[i] = s[i - 1] + a[i];
//    }
//
//    memset(d,-1,sizeof(d));
//    d[0] = 0;
//    for(int i = 1;i <= n;i ++){
//        if(d[s[i] % n] != -1){
//            printf("%d\n",i - d[s[i] % n]);
//            for(int j = d[s[i] % n] + 1;j <= i;j ++){
//                printf("%d\n",a[j]);
//            }
//            break;
//        }
//        d[s[i] % n] = i;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//typedef long long ll;
//const int N = 1e5 + 10;
//bool bprime[N];
//ll prime[N],cnt,factor[N],num;
//
//void isprime(){
//    cnt = 0;
//    memset(bprime,0,sizeof(bprime));
//    for(ll i = 2;i < N;i ++){
//        if(!bprime[i]){
//            prime[cnt ++] = i;
//            for(ll j = i * i;j < N;j += i)
//                bprime[j] = true;
//        }
//    }
//}
//
//void getfactor(int n){
//    num = 0;
//    for(ll i = 0;prime[i] * prime[i] <= n && i < cnt;i ++){
//        if(n % prime[i] == 0){
//            factor[num ++] = prime[i];
//            while(n % prime[i] == 0)
//                n /= prime[i];
//        }
//    }
//}
//
//ll cal(ll m){
//    ll res = 0;
//    for(ll i = 1;i < (1 << num);i ++){
//        ll sum = 0;
//        ll tmp = 1;
//        for(ll j = 0;j < num;j ++){
//            if(i & (1 << j)){
//                sum ++;
//                tmp *= factor[j];
//            }
//        }
//        if(sum % 2) res += m / tmp;
//        else res -= m / tmp;
//    }
//    return res;
//}
//int main(){
//    isprime();
//    ll a,b,n;
//    scanf("%d%d%d",&a,&b,&n);
//    getfactor(n);
//    printf("%lld\n",b - (a - 1) - cal(b) + cal(a - 1));
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//typedef long long ll;
//struct node{
//    ll x,y;
//}a1,a2,b1,b2,c1,c2;
//
//int main(){
//    scanf("%lld%lld%lld%lld",&a1.x,&a1.y,&a2.x,&a2.y);
//    scanf("%lld%lld%lld%lld",&b1.x,&b1.y,&b2.x,&b2.y);
//    c1.x = max(min(a1.x,a2.x),min(b1.x,b2.x));
//    c1.y = max(min(a1.y,a2.y),min(b1.y,b2.y));
//    c2.x = min(max(a1.x,a2.x),max(b1.x,b2.x));
//    c2.y = min(max(a1.y,a2.y),max(b1.y,b2.y));
//
//    ll s1 = (a2.x - a1.x) * (a2.y - a1.y);
//    ll s2 = (b2.x - b1.x) * (b2.y - b1.y);
//    ll s3 = (c2.x - c1.x) * (c2.y - c1.y);
//
//    if(c2.x > c1.x && c2.y > c1.y) printf("%lld\n",s1 + s2 - s3);
//    else printf("%lld\n",s1 + s2);
//    return 0;
//}

//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//const int N = 2e6 + 10;
//typedef long long ll;
//ll prime[N],factor[N];
//ll cnt;
//bool bprime[N];
//
//void isprime(){
//    cnt = 0;
//    memset(bprime,0,sizeof(bprime));
//    for(ll i = 2;i < N;i ++){
//        if(!bprime[i]){
//            prime[cnt ++] = i;
//            for(ll j = i * i;j < N;j += i)
//                bprime[j] = 1;
//        }
//    }
//}
//
//ll cal(ll m,ll num){
//    ll res = 0;
//    for(ll i = 1;i < (1 << num);i ++){
//        ll sum = 0;
//        ll tmp = 1;
//        for(ll j = 0;j < num;j ++){
//            if(i & (1 << j)){
//                sum ++;
//                tmp *= factor[j];
//            }
//        }
//        if(sum % 2) res += m / tmp;
//        else res -= m / tmp;
//    }
//    return res;
//}
//int main(){
//    isprime();
//
//    int t;scanf("%d",&t);
//    int kase = 0;
//    while(t --){
//        ll a,b,n;
//        scanf("%lld%lld%lld",&a,&b,&n);
//
//        ll num = 0;
//        for(ll i = 0;prime[i] * prime[i] <= n && i < cnt;i ++){
//            if(n % prime[i] == 0){
//                factor[num ++] = prime[i];
//                while(n % prime[i] == 0)
//                    n /= prime[i];
//            }
//        }
//
//        if(n != 1) factor[num ++] = n;
//        ll res = b - (a - 1) - cal(b,num) + cal(a - 1,num);
//        printf("Case #%d: %lld\n",++kase,res);
//    }
//    return 0;
//}

//#include<cstdio>
//
//using namespace std;
//const int N = 20;
//typedef long long ll;
//ll a[N];
//ll gcd(ll a,ll b){
//    return !b ? a : gcd(b,a % b);
//}
//
//ll Lcm(ll a,ll b){
//    return a / gcd(a,b) * b;
//}
//int main(){
//    ll n,m;
//    while(~scanf("%lld%lld",&n,&m) && n && m){
//        int tot = 0;
//        for(int i = 0;i < m;i ++){
//            int v;scanf("%d",&v);
//            if(v > 0 && v < n) a[tot ++] = v;
//        }
//        ll sum = 0;
//        for(ll i = 1;i < (1 << tot);i ++){
//            ll lcm = 1;
//            ll cnt = 0;
//            for(ll j = 0;j < tot;j ++){
//                if(i & (1 << j)){
//                    lcm = Lcm(lcm,a[j]);
//                    cnt ++;
//
//                }
//            }
//            if(cnt != 0){
//                if(cnt % 2) sum += (n - 1) / lcm;
//                else sum -= (n - 1) / lcm;
//            }
//        }
//        if(sum < 0) sum = 0;
//        printf("%lld\n",sum);
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//const int N = 1e5 + 10;
//typedef long long ll;
//struct tree{
//    int l,r;
//    ll sum,lz;
//}t[N << 2];
//void push_up(int i){
//    t[i].sum = t[i << 1].sum + t[i << 1 | 1].sum;
//}
//
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
//        scanf("%lld",&t[i].sum);
//        return;
//    }
//    int m = l + r >> 1;
//    build(i << 1,l,m);
//    build(i << 1 | 1,m + 1,r);
//    push_up(i);
//}
//
//void modify(int i,int l,int r,int k){
//    if(t[i].l >= l && t[i].r <= r){
//        t[i].lz += k;
//        t[i].sum += k * (t[i].r - t[i].l + 1);
//        return;
//    }
//    push_down(i);
//    if(t[i << 1].r >= l) modify(i << 1,l,r,k);
//    if(t[i << 1 | 1].l <= r) modify(i << 1 | 1,l,r,k);
//    push_up(i);
//}
//
//ll query(int i,int l,int r){
//    if(t[i].l >= l && t[i].r <= r){
//        return t[i].sum;
//    }
//    push_down(i);
//    ll s = 0;
//    if(t[i << 1].r >= l) s += query(i << 1,l,r);
//    if(t[i << 1 | 1].l <= r) s += query(i << 1 | 1,l,r);
//    return s;
//}
//int main(){
//
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//typedef long long ll;
//const int N = 1e5 + 10;
//int n,m,mod;
//
//struct tree{
//    int l,r;
//    int sum;
//    int mlz,alz;
//}t[N << 2];
//
//void push_up(int i){
//    t[i].sum = t[i << 1].sum + t[i << 1 | 1].sum;
//}
//
//void push_down(int i){
//    int alz = t[i].alz,mlz = t[i].mlz;
//    t[i << 1].sum = (mlz * t[i << 1].sum + (t[i << 1].r - t[i << 1].l + 1) * alz % mod) % mod;
//    t[i << 1 | 1].sum = (mlz * t[i << 1 | 1].sum + (t[i << 1 | 1].r - t[i << 1 | 1].l + 1) * alz % mod ) % mod;
//    t[i << 1].alz = (t[i << 1].alz * mlz + alz) % mod;
//    t[i << 1 | 1].alz = (t[i << 1 | 1].alz * mlz + alz) % mod;
//    t[i << 1].mlz = t[i << 1].mlz * mlz % mod;
//    t[i << 1 | 1].mlz = t[i << 1 | 1].mlz * mlz % mod;
//    t[i].alz = 0;
//    t[i].mlz = 1;
//}
//
//void build(int i,int l,int r){
//    t[i].l = l,t[i].r = r;
//    t[i].alz = 0,t[i].mlz = 1;
//    if(l == r){
//        int tmp;
//        scanf("%d",tmp);
//        t[i].sum = tmp % mod;
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
//        t[i].alz = (t[i].alz + k) % mod;
//        t[i].sum = (t[i].sum + k * (t[i].r - t[i].l + 1)) % mod;
//        return;
//    }
//    push_down(i);
//    if(t[i << 1].r >= l) add(i << 1,l,r,k);
//    if(t[i << 1 | 1].l <= r) add(i << 1 | 1,l,r,k);
//    push_up(i);
//}
//
//void mul(int i,int l,int r,int k){
//    if(t[i].l >= l && t[i].r <= r){
//        t[i].alz = t[i].alz * k % mod;
//        t[i].mlz = t[i].mlz * k % mod;
//        t[i].sum = t[i].sum * k % mod;
//        return;
//    }
//    push_down(i);
//    if(t[i << 1].r >= l) mul(i << 1,l,r,k);
//    if(t[i << 1 | 1].l <= r) mul(i << 1 | 1,l,r,k);
//    push_up(i);
//}
//
//int query(int i,int l,int r){
//    if(t[i].l >= l && t[i].r <= r){
//        return t[i].sum;
//    }
//    push_down(i);
//    int s = 0;
//    if(t[i << 1].r >= l) s = (s + query(i << 1,l,r)) % mod;
//    if(t[i << 1 | 1].l <= r) s = (s + query(i << 1 | 1,l,r)) % mod;
//    return s;
//}
//
//int main(){
//    scanf("%d%d%d",&n,&m,&mod);
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//const int N = 1e5 + 10;
//int fa[N][23],dep[N],lg[N];
//struct edge{
//    int to,next;
//}e[N << 1];
//int head[N],tot;
//void dfs(int now,int fath){
//    fa[now][0] = fath;dep[now] = dep[fath] + 1;
//    for(int i = 1;i <= lg[dep[now]];i ++){
//        fa[now][i] = fa[fa[now][i - 1]][i - 1];
//    }
//    for(int i = head[now];i;i = e[i].next){
//        if(e[i].to != fath) dfs(e[i].to,now);
//    }
//}
//
//int LCA(int x,int y){
//    if(dep[x] < dep[y]) swap(x,y);
//    while(dep[x] > dep[y]) x = fa[x][lg[dep[x] - dep[y]] - 1];
//    if(x == y) return x;
//    for(int k = lg[dep[x]] - 1;k >= 0;k --){
//        if(fa[x][k] != fa[y][k]){
//            x = fa[x][k];
//            y = fa[y][k];
//        }
//    }
//    return fa[x][0];
//}
//int main(){
//
//    return 0;
//}
//
//for(int j = 1;(1 << j) <= n;j ++){
//    for(int i = 1;i + (1 << j) - 1 <= n;i ++){
//        f[i][j] = max(f[i][j - 1],f[i + (1 << (j - 1))][j - 1]);
//    }
//}
//
//int query(int l,int r){
//    int k = log2(r - l + 1);
//    return max(f[l][k],f[r - (1 << k) + 1][k]);
//}