//#include<iostream>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//int n,x,y;
//struct node
//{
//    int x,y,cur;
//}a[210];
//bool cmp(node a,node b)
//{
//    if(((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y))==((b.x-x)*(b.x-x)+(b.y-y)*(b.y-y)))
//        return a.cur<b.cur;
//    return ((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y))<((b.x-x)*(b.x-x)+(b.y-y)*(b.y-y));
//}
//int main()
//{
//    cin>>n>>x>>y;
//    for(int i=1;i<=n;i++)
//    {
//        cin>>a[i].x>>a[i].y;
//        a[i].cur=i;
//    }
//    sort(a+1,a+n+1,cmp);
//    for(int i=1;i<=3;i++)
//    {
//        cout<<a[i].cur<<endl;
//    }
//    return 0;
//}

//#include<iostream>
//using namespace std;
//int n,k,t,xl,yl,xr,yr,ans1,ans2;
//struct peo
//{
//    int x,y;
//}a[25][1010];
//bool check(int x,int y)
//{
//    if((x>=xl&&x<=xr)&&(y>=yl&&y<=yr))
//        return true;
//    return false;
//}
//int main()
//{
//    cin>>n>>k>>t>>xl>>yl>>xr>>yr;
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=t;j++)
//        {
//            cin>>a[i][j].x>>a[i][j].y;
//        }
//    }
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=t;j++)
//        {
//            if(check(a[i][j].x,a[i][j].y))
//            {
//                ans1++;
//                break;
//            }
//        }
//    }
//    for(int i=1;i<=n;i++)
//    {
//        int cnt=0;
//        for(int j=1;j<=n;j++)
//        {
//            if(check(a[i][j].x,a[i][j].y))
//            {
//                cnt++;
//                if(cnt>=k)
//                {
//                    ans2++;
//                    break;
//                }
//            }
//            else
//                cnt=0;
//        }
//    }
//    cout<<ans1<<endl<<ans2<<endl;
//    return 0;
//}

//#include<iostream>
//using namespace std;
//const int maxn=1e6+10;
//typedef long long ll;
//ll n,m,op,a[maxn],x,y,k;
//struct t
//{
//    ll l,r,sum;
//}tree[maxn];
//void build(ll i,ll l,ll r)
//{
//    tree[i].l=l;
//    tree[i].r=r;
//    if(l==r)
//    {
//        tree[i].sum=a[l];
//        return;
//    }
//    ll mid=(l+r)/2;
//    build(i*2,l,mid);
//    build(i*2+1,mid+1,r);
//    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
//}
////void change(int i,int l,int r,int k)
////{
////    if(tree[i].l>=l&&tree[i].r<=r)
////    {
////        tree[i].sum+=k;
////        return ;
////    }
////    if(tree[i*2].r>=l)change(i*2,l,r,k);
////    if(tree[i*2+1].l<=r)change(i*2+1,l,r,k);
////}
//void add(ll i,ll des,ll k)
//{
//    if(tree[i].l==tree[i].r)
//     {
//         tree[i].sum+=k;
//         return;
//     }
//
//    if(tree[i*2].r>=des)add(i*2,des,k);
//    else add(i*2+1,des,k);
//    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
//}
//ll sum_all(ll i,ll l,ll r)
//{
//    if(tree[i].l>=l&&tree[i].r<=r)
//        return tree[i].sum;
//    if(tree[i].l>r||tree[i].r<l)return 0;
//    ll s=0;
//    if(tree[i*2].r>=l) s+=sum_all(i*2,l,r);
//    if(tree[i*2+1].l<=r) s+=sum_all(i*2+1,l,r);
//    return s;
//}
//int main()
//{
//    cin>>n>>m;
//    for(int i=1;i<=n;i++)
//    {
//        cin>>a[i];
//    }
//    build(1,1,n);
//    while(m--)
//    {
//        cin>>op;
//        if(op==1)
//        {
//            cin>>x>>y>>k;
//            for(int i=x;i<=y;i++)
//            {
//                add(1,i,k);
//            }
//        }
//        else
//        {
//            cin>>x>>y;
//            cout<<sum_all(1,x,y)<<endl;
//        }
//    }
//    return 0;
//}

//#include<iostream>
//using namespace std;
//typedef long long ll;
//const int maxn=1e6+10;
//ll n,m,x,y,k,a[maxn];
//struct tree
//{
//    ll l,r,sum;
//}t[maxn];
//void build(ll i,ll l,ll r)
//{
//    t[i].l=l,t[i].r=r;
//    if(t[i].l==t[i].r)
//    {
//        t[i].sum=a[l];
//        return;
//    }
//    ll m=(l+r)/2;
//    build(i*2,l,m);
//    build(i*2+1,m+1,r);
//    t[i].sum=t[i*2].sum+t[i*2+1].sum;
//}
//void add(ll i,ll dis,ll k)
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
//int search_area(ll i,ll l,ll r)
//{
//   if(t[i].l>=l&&t[i].r<=r)
//        return t[i].sum;
//   if(t[i].l>r||t[i].r<l)return 0;
//   ll s=0;
//   if(t[i*2].r>=l)s+=search_area(i*2,l,r);
//   if(t[i*2+1].l<=r)s+=search_area(i*2+1,l,r);
//   return s;
//}
//int main()
//{
//    int op;
//    cin>>n>>m;
//    for(int i=1;i<=n;i++)
//    {
//        cin>>a[i];
//    }
//    build(1,1,n);
//    while(m--)
//    {
//        cin>>op;
//        if(op==1)
//        {
//            cin>>x>>k;
//            add(1,x,k);
//        }
//        else
//        {
//            cin>>x>>y;
//            cout<<search_area(1,x,y)<<endl;
//        }
//    }
//    return 0;
//}


//#include<iostream>
//using namespace std;
//const int maxn=1e9+10;
//typedef long long ll;
//ll a[maxn],b[maxn],n,m,x,y,k;
//struct tree
//{
//    ll l,r,sum;
//}t[maxn];
//void build(ll i,ll l,ll r)
//{
//    t[i].l=l;
//    t[i].r=r;
//    if(t[i].l==t[i].r)
//    {
//        t[i].sum=b[l];
//        return;
//    }
//    ll m=(l+r)/2;
//    build(i*2,l,m);
//    build(i*2+1,m+1,r);
//    t[i].sum=t[i*2].sum+t[i*2+1].sum;
//}
//void add(ll i,ll dis,ll k)
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
//ll search_area(ll i,ll l,ll r)
//{
//    if(t[i].l>=l&&t[i].r<=r)
//    {
//        return t[i].sum;
//    }
//    if(t[i].l>r||t[i].r<l)return 0;
//    ll s=0;
//    if(t[i*2].r>=l)s+=search_area(i*2,l,r);
//    if(t[i*2+1].l<=r)s+=search_area(i*2+1,l,r);
//    return s;
//}
//int main()
//{
//    int op;
//    cin>>n>>m;
//    for(ll i=1;i<=n;i++)
//    {
//        cin>>a[i];
//        b[i]=a[i]-a[i-1];
//    }
//    build(1,1,n);
//    while(m--)
//    {
//        cin>>op;
//        if(op==1)
//        {
//            cin>>x>>y>>k;
//            add(1,x,k);
//            add(1,y+1,-k);
//        }
//        else
//        {
//            cin>>x;
//            cout<<search_area(1,1,x)<<endl;
//        }
//    }
//    return 0;
//}










