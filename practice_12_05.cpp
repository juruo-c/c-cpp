//#include<iostream>
//using namespace std;
//typedef long long ll;
//const int N=1e5+10;
//ll n,m,a[N];
//struct tree
//{
//    ll l,r,lz,sum;
//}t[N<<2];
//void pushup(ll i)
//{
//    t[i].sum=t[i<<1].sum+t[i<<1|1].sum;
//}
//void build(ll i,ll l,ll r)
//{
//    t[i].l=l,t[i].r=r,t[i].lz=0;
//    if(l==r){
//        t[i].sum=a[l];
//        return ;
//    }
//    ll m=l+r>>1;
//    build(i<<1,l,m);
//    build(i<<1|1,m+1,r);
//    pushup(i);
//}
//void pushdown(ll i)
//{
//    if(t[i].lz)
//    {
//        t[i<<1].lz+=t[i].lz;
//        t[i<<1|1].lz+=t[i].lz;
//        t[i<<1].sum+=t[i].lz*(t[i<<1].r-t[i<<1].l+1);
//        t[i<<1|1].sum+=t[i].lz*(t[i<<1|1].r-t[i<<1|1].l+1);
//        t[i].lz=0;
//    }
//}
//void add(ll i,ll l,ll r,ll k)
//{
//    if(t[i].l>=l&&t[i].r<=r){
//        t[i].sum+=k*(t[i].r-t[i].l+1);
//        t[i].lz+=k;
//        return;
//    }
//    pushdown(i);
//    ll m=t[i].l+t[i].r>>1;
//    if(l<=m)add(i<<1,l,r,k);
//    if(r>m)add(i<<1|1,l,r,k);
//    pushup(i);
//}
//ll query(ll i,ll l,ll r)
//{
//    if(t[i].l>=l&&t[i].r<=r){
//        return t[i].sum;
//    }
//    if(t[i].l>r||t[i].r<l)return 0;
//    pushdown(i);
//    ll m=t[i].l+t[i].r>>1;
//    ll s=0;
//    if(l<=m)s+=query(i<<1,l,r);
//    if(r>m)s+=query(i<<1|1,l,r);
//    return s;
//}
//int main()
//{
//    scanf("%lld%lld",&n,&m);
//    for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
//    build(1,1,n);
//    while(m--)
//    {
//        char c;scanf("\n%c",&c);
//        ll x,y,k;
//        if(c=='C'){
//            scanf("%lld%lld%lld",&x,&y,&k);
//            add(1,x,y,k);
//        }
//        if(c=='Q'){
//            scanf("%lld%lld",&x,&y);
//            printf("%lld\n",query(1,x,y));
//        }
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int maxn=1e4+10;
//int n,cnt;
//struct tree
//{
//    int l,r,n;
//}t[maxn<<2];
//struct node
//{
//    int point,pos;
//}s[maxn<<2];
//int mapp[maxn<<1][2],ans,flag[maxn<<1];
//bool cmp(node a,node b)
//{
//    return a.point<b.point;
//}
//void build(int i,int l,int r)
//{
//    t[i].l=l,t[i].r=r,t[i].n=0;
//    if(l==r)return;
//    int m=l+r>>1;
//    build(i<<1,l,r);
//    build(i<<1|1,l,r);
//}
//void put(int i,int l,int r,int k)
//{
//    if(t[i].l==l&&t[i].r==r)
//    {
//        t[i].n=k;
//        return;
//    }
//    int m=t[i].l+t[i].r>>1;
//    if(t[i].n>0)
//    {
//        t[i<<1].n=t[i<<1|1].n=t[i].n;
//        t[i].n=0;
//    }
//    if(l<=m)put(i<<1,l,r,k);
//    if(r>m)put(i<<1|1,l,r,k);
//}
//void solve(int i)
//{
//    if(t[i].n)
//    {
//        if(!flag[t[i].n])
//        {
//            ans++;
//            flag[t[i].n]=1;
//        }
//        return;
//    }
//    solve(i<<1);
//    solve(i<<1|1);
//}
//int main()
//{
//    int t,i,j;
//    scanf("%d",&t);
//    while(t--)
//    {
//        scanf("%d",&n);
//        for(int i=0;i<n;i++)
//        {
//            scanf("%d%d",&mapp[i][0],&mapp[i][1]);
//            s[i<<1].point=mapp[i][0];
//            s[i<<1|1].point=mapp[i][1];
//            s[i<<1].pos=-(i+1);
//            s[i<<1|1].pos=i+1;
//        }
//        sort(s,s+2*n,cmp);
//        int tmp=s[0].point,cnt=1;
//        for(int i=0;i<2*n;i++)
//        {
//            if(tmp!=s[i].point)
//            {
//                cnt++;
//                tmp=s[i].point;
//            }
//            if(s[i].pos<0)
//                mapp[-s[i].pos-1][0]=cnt;
//            else
//                mapp[s[i].pos-1][1]=cnt;
//        }
//        build(1,1,cnt);
//        for(int i=0;i<n;i++)
//            put(1,mapp[i][0],mapp[i][1],i+1);
//        memset(flag,0,sizeof(flag));
//        ans=0;
//        solve(1);
//        printf("%d\n",ans);
//    }
//    return 0;
//}


//#include <stdio.h>
//#include <string.h>
//#include <algorithm>
//using namespace std;
//
//int n,cnt;
//const int maxn = 10000+10;
//
//struct node
//{
//    int l,r,n;//n统计颜色
//} a[maxn<<2];
//
//struct kode
//{
//    int point,num;//point记录区间的边，num记录位置
//} s[maxn<<2];
//
//int map[maxn<<1][2],ans,flag[maxn<<1];
//
//int cmp(kode x,kode y)
//{
//    return x.point<y.point;
//}
//
//void init(int l,int r,int i)//建树
//{
//    a[i].l = l;
//    a[i].r = r;
//    a[i].n = 0;
//    if(l!=r)
//    {
//        int mid = (l+r)>>1;
//        init(l,mid,2*i);
//        init(mid+1,r,2*i+1);
//    }
//}
//
//void insert(int i,int l,int r,int m)
//{
//    if(a[i].l == l && a[i].r == r)//找到了区间，更新这个区间的颜色
//    {
//        a[i].n = m;
//        return;
//    }
//    int mid = (a[i].l+a[i].r)>>1;
//    if(a[i].n>0)//重点注意，如果这个区间被访问了，并且这个区间有颜色，就要将这个区间的颜色更新到其左右孩子的节点，并且要将这个区间的颜色清空，这样才能算是覆盖
//    {
//        a[2*i].n = a[2*i+1].n = a[i].n;
//        a[i].n = 0;
//    }
//    if(l>=a[2*i+1].l)
//        insert(2*i+1,l,r,m);
//    else if(r<=a[2*i].r)
//        insert(2*i,l,r,m);
//    else
//    {
//        insert(2*i,l,mid,m);
//        insert(2*i+1,mid+1,r,m);
//    }
//}
//
//void solve(int i)
//{
//    if(a[i].n)//如果有这个区间有颜色了，马上停止访问并返回，因为下面的无论有没有颜色都是已经被覆盖的了
//    {
//        if(!flag[a[i].n])//如果有颜色且没被统计过的，就统计一次
//        {
//            ans++;
//            flag[a[i].n] = 1;
//        }
//        return;
//    }
//    solve(2*i);
//    solve(2*i+1);
//    return;
//}
//
//int main()
//{
//    int t,i,j;
//    scanf("%d",&t);
//    while(t--)
//    {
//        scanf("%d",&n);
//        for(i = 0; i<n; i++)//离散化
//        {
//            scanf("%d%d",&map[i][0],&map[i][1]);
//            s[2*i].point = map[i][0];
//            s[2*i+1].point = map[i][1];
//            s[2*i].num = -i;
//            s[2*i+1].num = i;
//        }
//        sort(s,s+2*n,cmp);
//        int tmp = s[0].point,cnt = 1;
//        for(i = 0; i<2*n; i++)
//        {
//            if(tmp != s[i].point)//如果和前面的不同，这迭代加1
//            {
//                cnt++;
//                tmp = s[i].point;
//            }
//            if(s[i].num<0)
//                map[-s[i].num][0] = cnt;
//            else
//                map[s[i].num][1] = cnt;
//        }
//        init(1,cnt,1);
//        for(i = 0; i<n; i++)
//            insert(1,map[i][0],map[i][1],i+1);
//        memset(flag,0,sizeof(flag));
//        ans = 0;
//        solve(1);
//        printf("%d\n",ans);
//    }
//
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N=2e4+10;
//int n,ans;
//struct tree
//{
//    int l,r,col;
//}t[N<<2];
//struct node
//{
//    int point,pos;
//}s[N<<2];
//int map[N<<1][2],flag[N<<1];
//bool cmp(node a,node b)
//{
//    return a.point<b.point;
//}
//void build(int i,int l,int r)
//{
//    t[i].l=l,t[i].r=r,t[i].col=0;
//    if(l==r)return;
//    int m=l+r>>1;
//    build(i<<1,l,m);
//    build(i<<1|1,m+1,r);
//    return;
//}
//void insert(int i,int l,int r,int k)
//{
//    if(t[i].l>=l&&t[i].r<=r)
//    {
//        t[i].col=k;
//        return;
//    }
//    int m=t[i].l+t[i].r>>1;
//    if(t[i].col){
//        t[i<<1].col=t[i<<1|1].col=t[i].col;
//        t[i].col=0;
//    }
//    if(l<=m)insert(i<<1,l,r,k);
//    if(r>m)insert(i<<1|1,l,r,k);
//}
//void solve(int i)
//{
//    if(t[i].col){
//        if(!flag[t[i].col]){
//            ans++;
//            flag[t[i].col]=1;
//        }
//        return;
//    }
//    solve(i<<1);
//    solve(i<<1|1);
//}
//int main()
//{
//    int tt;cin>>tt;
//    while(tt--)
//    {
//        scanf("%d",&n);
//        for(int i=0;i<n;i++){
//            scanf("%d%d",&map[i][0],&map[i][1]);
//            s[i<<1].point=map[i][0];
//            s[i<<1|1].point=map[i][1];
//            s[i<<1].pos=-i;
//            s[i<<1|1].pos=i;
//        }
//        sort(s,s+n*2,cmp);
//        int tmp=s[0].point,cnt=1;
//        for(int i=0;i<n*2;i++){
//            if(s[i].point!=tmp){
//                cnt++;
//                tmp=s[i].point;
//            }
//            if(s[i].pos<0)
//                map[-s[i].pos][0]=cnt;
//            else
//                map[s[i].pos][1]=cnt;
//        }
//        build(1,1,n);
//        for(int i=0;i<n;i++)
//            insert(1,map[i][0],map[i][1],i+1);
//        memset(flag,0,sizeof(flag));
//        ans=0;
//        solve(1);
//        printf("%d\n",ans);
//    }
//    return 0;
//}
//
//#include<iostream>
//#include<cstdio>
//using namespace std;
//const int N=1e6+10;
//int n,q;
//struct tree
//{
//    int l,r,sum,lz;
//}t[N<<2];
//void pushup(int i)
//{
//    t[i].sum=t[i<<1].sum+t[i<<1|1].sum;
//}
//void pushdown(int i)
//{
//    if(t[i].lz)
//    {
//        t[i<<1].lz=t[i].lz;
//        t[i<<1|1].lz=t[i].lz;
//        t[i<<1].sum=t[i].lz*(t[i<<1].r-t[i<<1].l+1);
//        t[i<<1|1].sum=t[i].lz*(t[i<<1|1].r-t[i<<1|1].l+1);
//        t[i].lz=0;
//    }
//}
//void build(int i,int l,int r)
//{
//    t[i].l=l,t[i].r=r,t[i].lz=0;
//    if(l==r){
//        t[i].sum=1;
//        return;
//    }
//    int m=l+r>>1;
//    build(i<<1,l,m);
//    build(i<<1|1,m+1,r);
//    pushup(i);
//}
//void modify(int i,int l,int r,int k)
//{
//    if(t[i].l>=l&&t[i].r<=r){
//        t[i].lz+=k;
//        t[i].sum=k*(t[i].r-t[i].l+1);
//        return;
//    }
//    pushdown(i);
//    int m=t[i].l+t[i].r>>1;
//    if(l<=m)modify(i<<1,l,r,k);
//    if(r>m)modify(i<<1|1,l,r,k);
//    pushup(i);
//}
////int ask(int i,int l,int r)
////{
////    if(t[i].l>=l&&t[i].r<=r){
////        return t[i].sum;
////    }
////    if(t[i].l>r||t[i].r<l)return 0;
////    int s=0;
////    int m=t[i].l+t[i].r>>1;
////    if(l<=m)s+=ask(i<<1,l,r);
////    if(r>m)s+=ask(i<<1|1,l,r);
////    return s;
////}
//int main()
//{
//    int tt;cin>>tt;
//    for(int T=1;T<=tt;T++)
//    {
//
//        scanf("%d%d",&n,&q);
//        build(1,1,n);
//        while(q--)
//        {
//            int x,y,z;
//            scanf("%d%d%d",&x,&y,&z);
//            modify(1,x,y,z);
//        }
//        printf("Case %d: The total value of the hook is %d.\n",T,t[1].sum);
//    }
//    return 0;
//}
////
//#include<iostream>
//using namespace std;
//const int N=1010;
//struct computer
//{
//    int x,y;
//}c[N];
//int n,d,pre[N],rank[N];
//void make_rank(int i)
//{
//    rank[i]=1;
//}
//void make_pre(int i)
//{
//    pre[i]=i;
//}
//int Find_pre(int i)
//{
//    if(pre[i]==i)return pre[i];
//    return Find_pre(pre[i]);
//}
//void Union(int i,int j)
//{
//    i=Find_pre(i);
//    j=Find_pre(j);
//    if(i==j)return ;
//    if(rank[i]>rank[j])pre[j]=i;
//    else
//    {
//        if(rank[i]==rank[j])rank[j]++;
//        pre[i]=j;
//    }
//}
//int main()
//{
//    cin>>n>>d;
//    for(int i=1;i<=n;i++)
//    {
//        cin>>c[i].x>>c[i].y;
//    }
//    for(int i=1;i<=n;i++)
//    {
//        make_pre(i);
//        make_rank(i);
//    }
////    for(int i=1;i<=n;i++)
////    {
////        for(int j=1;j<=n;j++)
////        {
////            if(i==j)
////                continue;
////            if(pow(c[i].x-c[j].x,2)+pow(c[i].y-c[j].y,2)<=d*d)
////                Union(i,j);
////        }
////    }
//    char ch;
//    while(cin>>ch)
//    {
//        if(ch=='O'){
//            int x;
//            x
//        }
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=1e5+10;
//int n,m,fa[maxn],siz[maxn];
//void init(int i)
//{
//    fa[i]=i;
//    siz[i]=1;
//}
//int find_fa(int i)
//{
//    if(fa[i]==i)
//        return fa[i];
//    return find_fa(fa[i]);
//}
//void join(int x,int y)
//{
//    x=find_fa(x),y=find_fa(y);
//    if(x==y)return;
//    if(siz[x]>siz[y])fa[y]=x;
//    else
//    {
//        if(siz[x]==siz[y])siz[y]++;
//        fa[x]=y;
//    }
//}
//int main()
//{
//    cin>>n>>m;
//    for(int i=1;i<=n;i++)init(i);
//    int z,x,y;
//    while(m--)
//    {
//        cin>>z>>x>>y;
//        if(z==1)
//        {
//            join(x,y);
//        }
//        else
//        {
//            if(find_fa(x)==find_fa(y))
//                cout<<"Y"<<endl;
//            else
//                cout<<"N"<<endl;
//        }
//    }
//    return 0;
//}
//
//#include<iostream>
//using namespace std;
//const int N=1010;
//int n,m,fa[N],siz[N];
//void init(int i)
//{
//    fa[i]=i;
//    siz[i]=1;
//}
//struct computer
//{
//    int x,y,flag;
//}c[N];
//int Find(int i)
//{
//    if(fa[i]==i)return fa[i];
//    return Find(fa[i]);
//}
//void Union(int x,int y)
//{
//    x=Find(x),y=Find(y);
//    if(x==y)return;
//    if(siz[x]>siz[y])fa[y]=x;
//    else{
//        if(siz[x]==siz[y])siz[y]++;
//        fa[x]=y;
//    }
//}
//int main()
//{
//    cin>>n>>m;
//    for(int i=1;i<=n;i++)init(i);
//    for(int i=1;i<=n;i++)cin>>c[i].x>>c[i].y;
//    char ch;
//    while(cin>>ch)
//    {
//        if(ch=='O')
//        {
//            int p;cin>>p;
//            c[p].flag=1;
//            for(int i=1;i<=n;i++)
//            {
//                if(i==p)continue;
//                if(c[i].flag&&((c[i].x-c[p].x)*(c[i].x-c[p].x)+(c[i].y-c[p].y)*(c[i].y-c[p].y))<=m*m)
//                Union(i,p);
//            }
//        }
//        else
//        {
//            int p,q;cin>>p>>q;
//            if(Find(p)==Find(q))cout<<"SUCCESS"<<endl;
//            else cout<<"FAIL"<<endl;
//        }
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//const int N=5010;
//int n,m,p,fa[N],siz[N];
//void init(int i)
//{
//    fa[i]=i;
//    siz[i]=1;
//}
//int Find(int i)
//{
//    if(fa[i]==i)
//        return fa[i];
//    return Find(fa[i]);
//}
//void Union(int x,int y)
//{
//    x=Find(x),y=Find(y);
//    if(x==y)return;
//    if(siz[x]>siz[y])fa[y]=x;
//    else{
//        if(siz[x]==siz[y])siz[y]++;
//        fa[x]=y;
//    }
//}
//int main()
//{
//    cin>>n>>m>>p;
//    for(int i=1;i<=n;i++)init(i);
//    int mi,mj;
//    while(m--)
//    {
//        cin>>mi>>mj;
//        Union(mi,mj);
//    }
//    while(p--)
//    {
//        cin>>mi>>mj;
//        if(Find(mi)==Find(mj))cout<<"Yes"<<endl;
//        else cout<<"No"<<endl;
//    }
//    return 0;
//}
//

#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m,ans,fa[N],siz[N];

void init(int i)
{
    fa[i]=i;
    siz[i]=1;
}
int Find(int i)
{
    if(fa[i]==i)return fa[i];
    return Find(fa[i]);
}
void Union(int x,int y)
{
    x=Find(x),y=Find(y);
    if(x==y)return;
    if(siz[x]>siz[y])fa[y]=x;
    else{
        if(siz[x]==siz[y])siz[y]++;
        fa[x]=y;
    }
}
struct fi
{
    int x,y,t;
}f[N];
bool cmp(fi a,fi b)
{
    return a.t<b.t;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)init(i);
    for(int i=1;i<=m;i++)cin>>f[i].x>>f[i].y>>f[i].t;
    sort(f+1,f+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        if(Find(f[i].x)==Find(f[i].y))continue;
        Union(f[i].x,f[i].y);
        ans=max(ans,f[i].t);
    }
    int tmp=Find(1);
    for(int i=1;i<=n;i++)if(Find(i)!=tmp)ans=-1;
    cout<<ans<<endl;
    return 0;
}

//#include<bits/stdc++.h>
//using namespace std;
//const int N=1e5+10;
//int n,k;
//long long a[N];
//int main()
//{
//    cin>>n;
//    multiset<long long> s;
//    for(int i=1;i<=n;i++){
//        cin>>a[i];
//        s.insert(a[i]);
//    }
//    cin>>k;
//    long long  x;
//    while(k--)
//    {
//        cin>>x;
//        cout<<s.count(x)<<endl;
//    }
//    return 0;
//}
//

//#include<bits/stdc++.h>
//using namespace std;
//const int N=1e5+10;
//int n,k;
//struct peo
//{
//    string name,n;
//}p[N];
//int main()
//{
//    cin>>n;
//    map<string,string> m;
//    for(int i=1;i<=n;i++){
//        cin>>p[i].name>>p[i].n;
//        m[p[i].name]=p[i].n;
//    }
//    cin>>k;string s;
//    while(k--)
//    {
//        cin>>s;
//        cout<<m[s]<<endl;
//    }
//    return 0;
//}













