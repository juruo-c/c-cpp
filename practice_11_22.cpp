//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=100010;
//struct point
//{
//    int l,r;
//}p1[maxn],p2[maxn],ans[maxn];
//int M,now_l,now_r;
//bool cmp(point a,point b)
//{
//    if(a.l<b.l)
//        return true;
//    else if(a.l>b.l)
//        return false;
//    else
//    {
//        if(a.r>b.r)
//            return true;
//        else
//            return false;
//    }
//}
//int main()
//{
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        int cnt1=0;
//        cin>>M;
//        while(1)
//        {
//            cin>>p1[cnt1].l>>p1[cnt1].r;
//            if(!p1[cnt1].l&&!p1[cnt1].r)
//                break;
//            cnt1++;
//        }
//        int cnt2=0;
//        for(int i=0;i<cnt1;i++)
//        {
//            if(p1[i].r<=0||p1[i].l>=M)
//                continue;
//            p2[cnt2]=p1[i];
//            cnt2++;
//        }
//        sort(p2,p2+cnt2,cmp);
//        int ans_cnt=0;
//        if(p2[0].l>0)
//        {
//            ;
//        }
//        else
//        {
//            now_r=p2[0].r;
//            now_l=p2[0].l;
//            ans[ans_cnt]=p2[0];
//            ans_cnt++;
//            for(int i=1;i<cnt2;i++)
//            {
//                if(p2[i].r>now_r)
//                {
//
//                    if(p2[i].l>now_r)
//                    {
//                        ans_cnt=0;
//                        break;
//                    }
//                    if(now_l<0&&p2[i].l<=0)
//                    {
//                        now_l=p2[i].l;
//                        ans[ans_cnt]=p2[i];
//                        continue;
//                    }
//                    now_r=p2[i].r;
//                    ans[ans_cnt]=p2[i];
//                    ans_cnt++;
//                }
//            }
//            if(ans[ans_cnt-1].r<M)
//                ans_cnt=0;
//        }
//        if(!ans_cnt)
//        {
//            cout<<0<<endl;
//            if(t)
//                cout<<endl;
//        }
//        else
//        {
//            cout<<ans_cnt<<endl;
//            for(int i=0;i<ans_cnt;i++)
//            {
//                cout<<ans[i].l<<" "<<ans[i].r<<endl;
//            }
//            if(t)
//            {
//                cout<<endl;
//            }
//        }
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=5000;
//int n;
//struct point
//{
//    int x,y;
//}l[maxn],r[maxn];
//int main()
//{
//    while(cin>>n&&n)
//    {
//        for(int i=0;i<n;i++)
//        {
//            cin>>l[i].x>>l[i].y>>r[i].x>>r[i].y;
//        }
//
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int n,a;
//int main()
//{
//    while(cin>>n&&n)
//    {
//        long long ans=0;
//        long long last=0;
//        for(int i=0;i<n;i++)
//        {
//            cin>>a;
//            ans+=abs(last);
//            last+=a;
//        }
//        printf("%lld\n",ans);
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=1e5+10;
//int n,a[maxn];
//int main()
//{
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        cin>>n;
//        for(int i=0;i<n;i++)
//        {
//            scanf("%d",&a[i]);
//        }
//
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=1e6+10;
//struct region
//{
//    int l,r;
//}reg[maxn];
//bool cmp(region a,region b)
//{
//    if(a.r<b.r)
//        return true;
//    else if(a.r>b.r)
//        return false;
//    else
//    {
//        if(a.l>b.l)
//            return true;
//        else
//            return false;
//    }
//}
//int n,now,ans;
//int main()
//{
//    cin>>n;
//    for(int i=0;i<n;i++)
//    {
//        cin>>reg[i].l>>reg[i].r;
//    }
//    sort(reg,reg+n,cmp);
//    now=reg[0].r;
//    ans++;
//    for(int i=1;i<n;i++)
//    {
//        if(reg[i].l>=now)
//        {
//            ans++;
//            now=reg[i].r;
//        }
//    }
//    cout<<ans<<endl;
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int N,T;
//double ans;
//struct coin
//{
//    double m,v;
//}c[110];
//bool cmp(coin a,coin b)
//{
//    return (a.v/a.m)>(b.v/b.m);
//}
//int main()
//{
//    cin>>N>>T;
//    for(int i=0;i<N;i++)
//    {
//        cin>>c[i].m>>c[i].v;
//    }
//    sort(c,c+N,cmp);
//    for(int i=0;i<N;i++)
//    {
//        if(T>c[i].m)
//        {
//            ans+=c[i].v;
//            T-=c[i].m;
//        }
//        else
//        {
//            ans+=(c[i].v/c[i].m)*T;
//            break;
//        }
//    }
//    printf("%.2lf",ans);
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int n,x,a[100010],vis;
//long long ans;
//int main()
//{
//    cin>>n>>x;
//    for(int i=0;i<n;i++)
//    {
//        cin>>a[i];
//    }
//    for(int i=0;i<n-1;i++)
//    {
//        vis=(a[i]+a[i+1]-x);
//        if(vis<=0)
//            continue;
//        ans+=vis;
//        a[i+1]-=vis;
//        if(a[i+1]<0)
//            a[i+1]=0;
//    }
//    cout<<ans<<endl;
//    return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//int ans,n,s,a,b;
//struct apple
//{
//    int x,y;
//}app1[5010],app2[5010];
//bool cmp(apple a,apple b)
//{
//    return a.y<b.y;
//}
//int main()
//{
//    cin>>n>>s>>a>>b;
//    for(int i=0;i<n;i++)
//    {
//        cin>>app1[i].x>>app1[i].y;
//    }
//    int cnt=0;
//    for(int i=0;i<n;i++)
//    {
//        if(app1[i].x>(a+b))
//            continue;
//        app2[cnt]=app1[i];
//        cnt++;
//    }
//    sort(app2,app2+cnt,cmp);
//    for(int i=0;i<cnt;i++)
//    {
//        if(s-app2[i].y>=0)
//        {
//            ans++;
//            s-=app2[i].y;
//        }
//    }
//    cout<<ans<<endl;
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int n,d[100010];
//long long ans;
//int main()
//{
//    cin>>n;
//    for(int i=1;i<=n;i++)
//    {
//        cin>>d[i];
//    }
//    for(int i=2;i<=n;i++)
//    {
//        if(d[i]>d[i-1])
//            ans+=d[i]-d[i-1];
//    }
//    cout<<ans+d[1];
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int n,m;
//long long ans;
//struct people
//{
//    int a,b;
//}p[5010];
//bool cmp(people a,people b)
//{
//    return a.a<b.a;
//}
//int main()
//{
//    cin>>n>>m;
//    for(int i=0;i<m;i++)
//    {
//        cin>>p[i].a>>p[i].b;
//    }
//    sort(p,p+m,cmp);
//    for(int i=0;i<m;i++)
//    {
//        if(n-p[i].b>0)
//        {
//            ans+=p[i].a*p[i].b;
//            n-=p[i].b;
//        }
//        else
//        {
//            ans+=p[i].a*n;
//            break;
//        }
//    }
//    cout<<ans<<endl;
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=1e6+10;
//int n,a[maxn],b[maxn],c[maxn],vis[maxn];
//struct point
//{
//    int num,pos;
//}p[maxn];
//bool cmp(point a,point b)
//{
//    return a.num<b.num;
//}
//int main()
//{
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        for(int i=1;i<=maxn;i++)
//        {
//            vis[i]=0;
//        }
//        int ans=0;
//        cin>>n;
//        for(int i=1;i<=n;i++)
//        {
//            scanf("%d",&a[i]);
//        }
//        for(int i=1;i<=n;i++)
//        {
//            p[i].num=a[i];
//            p[i].pos=i;
//        }
//        sort(p+1,p+n+1,cmp);
////        for(int i=1;i<=n;i++)
////        {
////            cout<<p[i].pos<<" ";
////        }
////        cout<<endl;
//        int cnt=1;
//        for(int i=1;i<=n;i++)
//        {
//            b[i]=cnt;
//            if(i<n&&p[i].num!=p[i+1].num)
//                cnt++;
//        }
////        for(int i=1;i<=n;i++)
////        {
////
////            cout<<b[i]<<" ";
////        }
////        cout<<endl;
//        for(int i=1;i<=n;i++)
//        {
//            c[p[i].pos]=b[i];
//        }
////        for(int i=1;i<=n;i++)
////        {
////            cout<<c[i]<<" ";
////        }
////        cout<<endl;
//        int l=1;
//        int r=1;
//        vis[c[r]]=1;
//        while(r<n)
//        {
//            if(vis[c[r+1]]<l)
//            {
//               r++;
//               vis[c[r]]=r;
////               cout<<"r: "<<r;
//            }
//            else
//            {
//                l=vis[c[r+1]]+1;
//                vis[c[r+1]]=0;
////              cout<<"l: "<<l;
//            }
//            ans=max(ans,r-l+1);
//        }
//        cout<<ans<<endl;
//    }
//    return 0;
//}

#include<bits/stdc++.h>
using namespace std;
int w,n,ans;
struct point
{
    int flag,v;
}p[100010];
bool cmp(point a,point b)
{
    return a.v>b.v;
}
int main()
{
    cin>>w>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p[i].v;
        p[i].flag=1;
    }
    sort(p,p+n,cmp);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int k=w-p[i].v;
        for(int j=i+1;j<n;j++)
        {
            if(p[j].v<=k&&p[j].flag)
            {
                cnt++;
                p[j].flag=0;
                break;
            }
        }
    }
    cout<<n-cnt<<endl;
    return 0;
}
