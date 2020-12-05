//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=1e7+10;
//struct tree
//{
//    int l,r,sum,lz;
//}t[maxn];
//void add(int i,int l,int r,int k)
//{
//    if(t[i].r<=r&&t[i].l>=l)
//    {
//        t[i].sum+=k*(t[i].r-t[i].l+1);
//        t[i].lz+=k;
//        return ;
//    }
//    push_down(i);
//    if(t[i*2].r>=l)
//        add(i*2,l,r,k);
//    if(t[i*2+1].l<=r)
//        add(i*2+1,l,r,k);
//    t[i].sum=t[i*2].sum+t[i*2+1].sum;
//}
//void push_down(int i)
//{
//    if(t[i].lz)
//    {
//        t[i*2].lz+=t[i].lz;
//        t[i*2+1].lz+=t[i].lz;
//        int m=(t[i].l+t[i].r)/2;
//        t[i*2].sum+=t[i].lz*(mid-t[i*2].l+1);
//        t[i*2+1].sum+=t[i].lz*(t[i*2+1].r-mid);
//        t[i].lz=0;
//    }
//}
//int main()
//{
//
//    return 0;
//}

//#include<iostream>
//using namespace std;
//const int maxn=1e7+10;
//int n,m,ans,a[maxn];
//struct tree
//{
//    int l,r,num;
//}t[maxn];
//void build(int i,int l,int r)
//{
//    t[i].num=0;
//    t[i].l=l;
//    t[i].r=r;
//    if(t[i].l==t[i].r)return;
//    int m=(l+r)/2;
//    build(i*2,l,m);
//    build(i*2+1,m+1,r);
//}
//void pls(int i,int l,int r,int k)
//{
//    if(t[i].l>=l&&t[i].r<=r)
//    {
//        t[i].num+=k;
//        return;
//    }
//    if(t[i*2].r>=l)pls(i*2,l,r,k);
//    if(t[i*2+1].l<=r)pls(i*2+1,l,r,k);
//}
//void search_point(int i,int dis)
//{
//    ans+=t[i].num;
//    if(t[i].l==t[i].r)
//        return ;
//    if(t[i*2].r>=dis)search_point(i*2,dis);
//    else search_point(i*2+1,dis);
//}
//int main()
//{
//    cin>>n>>m;
//    build(1,1,n);
//    for(int i=1;i<=n;i++)
//    {
//        cin>>a[i];
//    }
//    while(m--)
//    {
//        int op;
//        cin>>op;
//        if(op==1)
//        {
//            int x,y,k;
//            cin>>x>>y>>k;
//            pls(1,x,y,k);
//        }
//        else
//        {
//            ans=0;
//            int x;
//            cin>>x;
//            search_point(1,x);
//            cout<<ans+a[x]<<endl;
//        }
//    }
//    return 0;
//}

//#include<iostream>
//using namespace std;
//typedef long long ll;
//const int maxn=1e7+10;
//int n,m,x,y,k;
//ll a[maxn];
//struct tree
//{
//    int l,r,lz;
//    ll sum;
//}t[maxn];
//void build(int i,int l,int r)
//{
//    t[i].l=l;
//    t[i].r=r;
//    t[i].lz=0;
//    if(t[i].l==t[i].r)
//    {
//        t[i].sum=a[l];
//        return ;
//    }
//    int m=(l+r)/2;
//    build(i*2,l,m);
//    build(i*2+1,m+1,r);
//    t[i].sum=t[i*2].sum+t[i*2+1].sum;
//}
//void push_down(int i)
//{
//    if(t[i].lz)
//    {
//        t[i*2].lz+=t[i].lz;
//        t[i*2+1].lz+=t[i].lz;
//        int m=(t[i].l+t[i].r)/2;
//        t[i*2].sum+=t[i].lz*(m-t[i*2].l+1);
//        t[i*2+1].sum+=t[i].lz*(t[i*2+1].r-m);
//        t[i].lz=0;
//    }
//}
//void add(int i,int l,int r,int k)
//{
//    if(t[i].l>=l&&t[i].r<=r)
//    {
//        t[i].sum+=k*(t[i].r-t[i].l+1);
//        t[i].lz+=k;
//        return;
//    }
//    push_down(i);
//    if(t[i*2].r>=l)add(i*2,l,r,k);
//    if(t[i*2+1].l<=r)add(i*2+1,l,r,k);
//    t[i].sum=t[i*2].sum+t[i*2+1].sum;
//}
//ll search_ar(int i,int l,int r)
//{
//    if(t[i].l>=l&&t[i].r<=r)
//    return t[i].sum;
//    if(t[i].l>r||t[i].r<l)
//        return 0;
//    push_down(i);
//    ll s=0;
//    if(t[i*2].r>=l)s+=search_ar(i*2,l,r);
//    if(t[i*2+1].l<=r)s+=search_ar(i*2+1,l,r);
//    return s;
//}
//int main()
//{
//    cin>>n>>m;
//    for(int i=1;i<=n;i++)
//    cin>>a[i];
//    build(1,1,n);
//    while(m--)
//    {
//        int op;
//        cin>>op;
//        if(op==1)
//        {
//            int x,y,k;
//            cin>>x>>y>>k;
//            add(1,x,y,k);
//        }
//        if(op==2)
//        {
//            int x,y;
//            cin>>x>>y;
//            cout<<search_ar(1,x,y)<<endl;
//        }
//    }
//    return 0;
//}

//#include<iostream>
//using namespace std;
//typedef long long ll;
//const ll maxn=1e6+10;
////template<typename T>void read(T &x)
////{
////    x=0;
////    char ch=getchar();
////    ll f=1;
////    while(!isdigit(ch))
////    {
////        if(ch=='-')
////            f=-1;
////        ch=getchar();
////    }
////    while(isdigit(ch))
////    {
////        x=(x<<1)+(x<<3)+(ch^48);
////        ch=getchar();
////    }
////    x*=f;
////}
//ll n,m,a[maxn],mod,flag,cn,cm,cw;
//struct tree
//{
//    ll l,r,sum,mlz,alz;
//}t[maxn];
//inline void build(int i,int l,int r)
//{
//    t[i].l=l;t[i].r=r;t[i].mlz=1;t[i].alz=0;
//    if(t[i].l==t[i].r)
//    {
//        t[i].sum=a[l]%mod;
//        return;
//    }
//    ll m=(l+r)/2;
//    build(i*2,l,m);
//    build(i*2+1,m+1,r);
//    t[i].sum=t[i*2].sum+t[i*2+1].sum;
//}
//inline void push_down(ll i)
//{
//    ll mlz=t[i].mlz,alz=t[i].alz;
//    t[i<<1].sum=(mlz*t[i<<1].sum+(alz*(t[i<<1].r-t[i<<1].l+1))%mod)%mod;
//    t[i<<1|1].sum=(mlz*t[i<<1|1].sum+(alz*(t[i<<1|1].r-t[i<<1|1].l+1))%mod)%mod;
//    t[i<<1].mlz=(t[i<<1].mlz*t[i].mlz)%mod;
//    t[i<<1].alz=(t[i<<1].alz*t[i].mlz+t[i].alz)%mod;
//    t[i<<1|1].mlz=(t[i<<1|1].mlz*t[i].mlz)%mod;
//    t[i<<1|1].alz=(t[i<<1|1].alz*t[i].mlz+t[i].alz)%mod;
//    t[i].alz=0,t[i].mlz=1;
//}
//inline void add(ll i,ll l,ll r,ll k)
//{
//    if(t[i].l>=l&&t[i].r<=r)
//    {
//        t[i].alz=(t[i].alz+k)%mod;
//        t[i].sum=(t[i].sum+k*(t[i].r-t[i].l+1))%mod;
//        return;
//    }
//    push_down(i);
//    t[i].sum=(t[i*2].sum+t[i*2+1].sum)%mod;//??
//    if(t[i*2].r>=l)
//        add(i*2,l,r,k);
//    if(t[i*2+1].l<=r)
//        add(i*2+1,l,r,k);
//    t[i].sum=(t[i*2].sum+t[i*2+1].sum)%mod;
//
//}
//inline void mul(ll i,ll l,ll r,ll k)
//{
//    if(t[i].l>=l&&t[i].r<=r)
//    {
//        t[i].mlz=(t[i].mlz*k)%mod;
//        t[i].alz=(t[i].alz*k)%mod;
//        t[i].sum=(t[i].sum*k)%mod;
//        return;
//    }
//    push_down(i);
//    t[i].sum=(t[i*2].sum+t[i*2+1].sum)%mod;
//    if(t[i*2].r>=l)
//        mul(i*2,l,r,k);
//    if(t[i*2+1].l<=r)
//        mul(i*2+1,l,r,k);
//    t[i].sum=(t[i*2].sum+t[i*2+1].sum)%mod;
//}
//inline ll query(ll i,ll l,ll r)
//{
//    if(t[i].l>=l&&t[i].r<=r)
//        return t[i].sum;
//    push_down(i);
//    ll s=0;
//    if(t[i*2].r>=l)
//        s=(s+query(i*2,l,r))%mod;
//    if(t[i*2+1].l<=r)
//        s=(s+query(i*2+1,l,r))%mod;
//    return s;
//}
//int main()
//{
//    cin>>n>>m>>mod;
//    for(int i=1;i<=n;i++)
//    {
//        cin>>a[i];
//    }
//    build(1,1,n);
//    while(m--)
//    {
//        cin>>flag;
//        if(flag==1)
//        {
//            cin>>cn>>cm>>cw;
//            mul(1,cn,cm,cw);
//        }
//        else if(flag==2)
//        {
//            cin>>cn>>cm>>cw;
//            add(1,cn,cm,cw);
//        }
//        else
//        {
//            cin>>cn>>cm;
//            cout<<query(1,cn,cm)<<endl;
//        }
//    }
//    return 0;
//}


//#include<iostream>
//#include<cstring>
//using namespace std;
//const int maxn=1e5+10;
//int n,a[maxn];
//struct tree
//{
//    int l,r,sum;
//}t[maxn];
//void build(int i,int l,int r)
//{
//    t[i].l=l;
//    t[i].r=r;
//    if(l==r)
//    {
//        t[i].sum=a[l];
//        return;
//    }
//    int m=(l+r)/2;
//    build(i*2,l,m);
//    build(i*2+1,m+1,r);
//    t[i].sum=t[i*2].sum+t[i*2+1].sum;
//}
//void add(int i,int dis,int k)
//{
//    if(t[i].l==t[i].r)
//    {
//        t[i].sum+=k;
//        return;
//    }
//    if(t[i*2].r>=dis)add(i*2,dis,k);
//    else add(i*2+1,dis,k);
//    t[i].sum=t[i*2].sum+t[i*2+1].sum;
//}
//int query(int i,int l,int r)
//{
//    if(t[i].l>=l&&t[i].r<=r)
//        return t[i].sum;
//    if(t[i].l>r||t[i].r<l)return 0;
//    int s=0;
//    if(t[i*2].r>=l)s+=query(i*2,l,r);
//    if(t[i*2+1].l<=r)s+=query(i*2+1,l,r);
//    return s;
//}
//int main()
//{
//    int T;
//    cin>>T;
//    while(T--)
//    {
//        cout<<"Case "<<T+1<<":"<<endl;
//        cin>>n;
//        for(int i=1;i<=n;i++)
//        {
//            cin>>a[i];
//        }
////        for(int i=1;i<=n;i++)
////        {
////            cout<<a[i];
////        }
//        build(1,1,n);
//        for(int i=1;i<=n;i++)
//        {
//            cout<<t[i].sum<<" ";
//        }
//        char s[10],x,y;
//        getchar();
//        while(~scanf("%s",s))
//        {
//            if(s[0]=='E')
//                break;
//            if(s[0]=='A')
//            {
//                int x,y;
//                cin>>x>>y;
//                add(1,x,y);
//            }
//            else if(s[0]=='S')
//            {
//                cin>>x>>y;
//                add(1,x,-y);
//            }
//            else if(s[0]=='Q')
//            {
//                cin>>x>>y;
//                cout<<query(1,x,y)<<endl;
//            }
//        }
//        }
//
//    return 0;
//}

//#include<iostream>
//using namespace std;
//typedef long long ll;
//const int N=5e4+10;
//int a[N],n;
//struct tree
//{
//    int l,r,sum;
//}t[N<<2];
//void pushup(int i)
//{
//    t[i].sum=t[i<<1].sum+t[i<<1|1].sum;
//}
//void build(int i,int l,int r)
//{
//    t[i].l=l,t[i].r=r,t[i].sum=a[l];
//    if(l==r){
//        return;
//    }
//    int m=l+r>>1;
//    build(i<<1,l,m),build(i<<1|1,m+1,r);
//    pushup(i);
//}
//void modify(int i,int dis,int k)
//{
//    if(t[i].l==dis&&dis==t[i].r){
//        t[i].sum+=k;
//        return;
//    }
//    int mid=t[i].l+t[i].r>>1;
//    modify(i<<1|(dis>mid),dis,k);
//    pushup(i);
//}
//int ask(int i,int l,int r)
//{
//    if(t[i].l>=l&&t[i].r<=r)return t[i].sum;
//    int mid=t[i].l+t[i].r>>1;
//    int s=0;
//    if(l<=mid)s+=ask(i<<1,l,r);
//    if(r>mid)s+=ask(i<<1|1,l,r);
//    return s;
//}
//int main()
//{
//    int tt,T=0;
//    cin>>tt;
//    while(tt--){
//        printf("Case %d:\n",++T);
//        int n;scanf("%d",&n);
//        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
//        build(1,1,n);
//        while(true)
//        {
//            char s[10];scanf("%s",s);
//            if(s[0]=='E')break;
//            int x,y;scanf("%d%d",&x,&y);
//            if(s[0]=='A')modify(1,x,y);
//            else if(s[0]=='S')modify(1,x,-y);
//            else if(s[0]=='Q')printf("%d\n",ask(1,x,y));
//        }
//    }
//    return 0;
//}

//#include<iostream>
//using namespace std;
//typedef long long ll;
//const int N=2e5+10;
//int n,m,a[N];
//struct tree
//{
//    int l,r,maxn;
//}t[N<<2];
//void pushup(int i)
//{
//    t[i].maxn=max(t[i<<1].maxn,t[i<<1|1].maxn);
//}
//void build(int i,int l,int r)
//{
//    t[i].l=l,t[i].r=r;
//    if(l==r)
//    {
//        t[i].maxn=a[l];
//        return;
//    }
//    int m=l+r>>1;
//    build(i<<1,l,m);
//    build(i<<1|1,m+1,r);
//    pushup(i);
//}
//void modify(int i,int dis,int k)
//{
//    if(t[i].l==dis&&t[i].r==dis){
//        t[i].maxn=k;
//        return;
//    }
//    int m=(t[i].l+t[i].r)>>1;
//    modify(i<<1|(dis>m),dis,k);
//    pushup(i);
//}
//int ask(int i,int l,int r)
//{
//    if(t[i].l>=l&&t[i].r<=r)return t[i].maxn;
//    int m=(t[i].l+t[i].r)>>1;
//    int s=0;
//    if(l<=m)s=max(ask(i<<1,l,r),s);
//    if(r>m)s=max(ask(i<<1|1,l,r),s);
//    return s;
//}
//int main()
//{
//    while(scanf("%d%d",&n,&m)!=EOF){
//        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
//        build(1,1,n);
//        while(m--)
//        {
//            char c;scanf("\n%c",&c);
//            int x,y;scanf("%d%d",&x,&y);
//            if(c=='Q'){
//                printf("%d\n",ask(1,x,y));
//            }
//            else if(c=='U')modify(1,x,y);
//        }
//    }
//    return 0;
//}

//#include<iostream>
//using namespace std;
//typedef long long ll;
//const int N=1e5+10;
//ll n,m,a[N];
//struct tree{
//    ll l,r,lz,sum;
//}t[N<<2];
//void pushup(int i)
//{
//    t[i].sum=t[i<<1].sum+t[i<<1|1].sum;
//}
//void build(ll i,ll l,ll r)
//{
//    t[i].l=l,t[i].r=r,t[i].lz=0;
//    if(l==r){
//        t[i].sum=a[l];
//        return;
//    }
//    ll m=t[i].l+t[i].r>>1;
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
//    if(t[i].l>=l&&t[i].r<=r)
//    {
//        t[i].sum+=k*(t[i].r-t[i].l+1);
//        t[i].lz+=k;
//        return;
//    }
//    pushdown(i);
//    if(t[i<<1].r>=l)add(i<<1,l,r,k);
//    if(t[i<<1|1].l<=r)add(i<<1|1,l,r,k);
//    pushup(i);
//}
//ll query(ll i,ll l,ll r)
//{
//    if(t[i].l>=l&&t[i].r<=r)
//    {
//        return t[i].sum;
//    }
//    if(t[i].l>r||t[i].r<l)return 0;
//    pushdown(i);
//    ll s=0;
//    if(t[i<<1].r>=l)s+=query(i<<1,l,r);
//    if(t[i<<1|1].l<=r)s+=query(i<<1|1,l,r);
//    return s;
//}
//int main()
//{
//    scanf("%lld%lld",&n,&m);
//    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
//    while(m--)
//    {
//        char c;scanf("\n%c",&c);
//        ll x,y,k;
//        if(c=='C')
//        {
//            scanf("%lld%lld%lld",&x,&y,&k);
//            add(1,x,y,k);
//        }
//        else
//        {
//            scanf("%lld%lld",&x,&y);
//            printf("%lld\n",query(1,x,y));
//        }
//    }
//    return 0;
//}
//
//
//#include<iostream>
//using namespace std;
//const int N=110;
//int n,m,a[N],b[N],ans;
//int main()
//{
//    int t;cin>>t;
//    while(t--)
//    {
//        ans=0;
//        cin>>n>>m;
//        for(int i=1;i<=n;i++)cin>>a[i];
//        for(int i=1;i<=m;i++)cin>>b[i];
//        for(int i=1;i<=n;i++)
//        {
//            for(int j=1;j<=m;j++)
//            {
//                if(a[i]==b[j])ans++;
//            }
//        }
//        cout<<ans<<endl;
//    }
//    return 0;
//}

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=2e5+10;
int a[N],b[N],c[N],n;

int main()
{
    int t;cin>>t;
    while(t--)
    {
        long long ans=1e11;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=a[i]-a[i-1];
        }
        long long sum=0;
        for(int i=2;i<=n-1;i++)
        {
            c[i]=abs(b[i]+b[i+1]);
        }
        for(int i=2;i<=n;i++)
        {

        }
        sum=0;
        for(int i=2;i<=n-1;i++)
        {
            sum+=abs(b[i]);
        }
        ans=min(sum,ans);
        sum=0;
        for(int i=3;i<=n;i++)
        {
            sum+=abs(b[i]);
        }
        ans=min(sum,ans);
        cout<<ans<<endl;
    }
    return 0;
}







