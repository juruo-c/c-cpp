//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=10000005;
//bool prime[maxn];
//int a,b;
//void Prime()
//{
//    for(int i=0;i<maxn;i++)
//    {
//        prime[i]=1;
//    }
//    prime[0]=0;
//    prime[1]=0;
//    for(int i=2;i<maxn;i++)
//    {
//       if(!prime[i])continue;
//        for(int j=i*2;j<maxn;j+=i)
//        {
//            prime[j]=0;
//        }
//    }
//}
////void Prime()
////{
////    int cnt=0;
////    for(int i=2;i<=b;i++)
////    {
////        if(!vis[i])
////            prime[cnt++]=i;
////        for(int j=0;j<cnt&&i*prime[j]<=b;j++)
////        {
////            vis[i*prime[j]]=i;
////            if(i%prime[j]==0)
////                break;
////        }
////    }
////}
//bool is_mirror(int n)
//{
//    if(n<10)
//        return true;
//    int tmp=n;
//    int sum=0;
//    while(n)
//    {
//        sum=sum*10+n%10;
//        n/=10;
//    }
//    if(sum==tmp)
//        return true;
//    else
//        return false;
//}
//int main()
//{
//    cin>>a>>b;
//    if(b>=10000000)
//    {
//        b=9999999;
//    }
//    Prime();
//    for(int i=a;i<=b;i++)
//    {
//        if(is_mirror(i)&&prime[i])
//            cout<<i<<endl;
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//    int n,x,k;
//    cin>>n;
//    for(k=1;;k++)
//    {
//        for(x=100;x>0;x--)
//        {
//            if((7*x+21*k)*52==n)
//            {
//                cout<<x<<endl<<k<<endl;
//                return 0;
//            }
//        }
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int s[12];
//int main()
//{
//    for(int i=0;i<12;i++)
//    {
//        cin>>s[i];
//    }
//    int left=0;
//    int sum=0;
//    for(int i=0;i<12;i++)
//    {
//        if(i&&left+300-s[i]<0)
//        {
//            cout<<-(i+1)<<endl;
//            return 0;
//        }
//        left+=(300-s[i]);
//        while(1)
//        {
//            if(left<100)
//                break;
//            left-=100;
//            sum+=100;
//        }
//
//    }
//    cout<<sum*1.2+left<<endl;
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int l,m,ans;
//int u[110],v[110],vis[10010];
//int main()
//{
//    cin>>l>>m;
//    for(int i=0;i<=l;i++)
//    {
//        vis[i]=1;
//    }
//    for(int i=0;i<m;i++)
//    {
//        cin>>u[i]>>v[i];
//    }
//    for(int i=0;i<m;i++)
//    {
//        for(int j=u[i];j<=v[i];j++)
//        {
//            vis[j]=0;
//        }
//    }
//    for(int i=0;i<=l;i++)
//    {
//        ans+=vis[i];
//    }
//    cout<<ans<<endl;
//    return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//int w,x,h,q,ans;
//int a1[110],b1[110],c1[110];
//int a2[110],b2[110],c2[110];
//bool vis[25][25][25];
//int main()
//{
//    cin>>w>>x>>h>>q;
//    for(int i=1;i<=w;i++)
//    {
//        for(int j=1;j<=x;j++)
//        {
//            for(int k=1;k<=h;k++)
//            {
//                vis[i][j][k]=1;
//            }
//        }
//    }
//    for(int i=0;i<q;i++)
//    {
//        cin>>a1[i]>>b1[i]>>c1[i]>>a2[i]>>b2[i]>>c2[i];
//    }
//    for(int n=0;n<q;n++)
//    {
//        for(int i=a1[n];i<=a2[n];i++)
//        {
//            for(int j=b1[n];j<=b2[n];j++)
//            {
//                for(int k=c1[n];k<=c2[n];k++)
//                {
//                    vis[i][j][k]=0;
//                }
//            }
//        }
//    }
//    for(int i=1;i<=w;i++)
//    {
//        for(int j=1;j<=x;j++)
//        {
//            for(int k=1;k<=h;k++)
//            {
//                ans+=vis[i][j][k];
//            }
//        }
//    }
//    cout<<ans<<endl;
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=50*50;
//int n,board[maxn][maxn],row,col;
//bool vis[maxn][maxn];
//int main()
//{
//    cin>>n;
//    for(int i=1;i<=n*n;i++)
//    {
//        if(i==1)
//        {
//            row=0;
//            col=n/2;
//            board[0][n/2]=i;
//            vis[row][col]=1;
//            continue;
//        }
//        if(!row&&col!=n-1)
//        {
//            row=n-1;
//            col+=1;
//            board[row][col]=i;
//            vis[row][col]=1;
//            continue;
//        }
//        if(col==n-1&&row)
//        {
//            col=0;
//            row-=1;
//            board[row][col]=i;
//            vis[row][col]=1;
//            continue;
//        }
//        if(!row&&col==n-1)
//        {
//            row+=1;
//            board[row][col]=i;
//            vis[row][col]=1;
//            continue;
//        }
//        if(row&&col!=n-1)
//        {
//            if(!vis[row-1][col+1])
//            {
//                row-=1;
//                col+=1;
//                board[row][col]=i;
//                vis[row][col]=1;
//            }
//            else
//            {
//                row+=1;
//                board[row][col]=i;
//                vis[row][col]=1;
//            }
//        }
//    }
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<n;j++)
//        {
//            cout<<board[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//string s[10][5]={{"XXX","X.X","X.X","X.X","XXX"},{"..X","..X","..X","..X","..X"},{"XXX","..X","XXX","X..","XXX"},{"XXX","..X","XXX","..X","XXX"},{"X.X","X.X","XXX","..X","..X"},{"XXX","X..","XXX","..X","XXX"},{"XXX","X..","XXX","X.X","XXX"},{"XXX","..X","..X","..X","..X"},{"XXX","X.X","XXX","X.X","X.X"},{"XXX","X.X","XXX","..X","X.X"}};
//int main()
//{
//    int n;
//    char a[110];
//    cin>>n;
//    cin>>a;
//    for(int i=0;i<5;i++)
//    {
//        for(int j=0;j<n;j++)
//        {
//            cout<<s[a[j]-'0'][i];
//            if(j<n-1)
//                cout<<".";
//        }
//        cout<<endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//const int maxn=10000010;
//int L,D,N;
//int x[maxn],y[maxn];
//int vis;
//struct point
//{
//    double a,b;
//}p[maxn];
//bool cmp(point a,point b)
//{
//    if(a.b==b.b)
//    {
//
//        if(a.a>b.a)
//            return true;
//        else
//            return false;
//    }
//    else if(a.b>b.b)
//        return false;
//    else
//        return true;
//}
//int main()
//{
//    while(cin>>L>>D>>N)
//    {
//        int ans =0;
//        for(int i=0;i<N;i++)
//    {
//        cin>>x[i]>>y[i];
//    }
//    for(int i=0;i<N;i++)
//    {
//        p[i].a=x[i]-sqrt(-y[i]*y[i]+D*D);
//        p[i].b=x[i]+sqrt(-y[i]*y[i]+D*D);
//    }
//    sort(p,p+N,cmp);
//    for(int i=0;i<N;i++)
//    {
//        if(!i)
//        {
//            vis=p[0].b;
//            ans++;
//            continue;
//        }
//        if(p[i].a>vis)
//        {
//            ans++;
//            vis=p[i].b;
//        }
//    }
//    cout<<ans<<endl;
//    }
//
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=4010;
//int a[maxn],b[maxn],c[maxn],d[maxn];
//int sum1[maxn*maxn],sum2[maxn*maxn];
//int main()
//{
//    int t,n;
//    cin>>t;
//    while(t--)
//    {
//        cin>>n;
//        for(int i=0;i<n;i++)
//        {
//            cin>>a[i]>>b[i]>>c[i]>>d[i];
//        }
//        int cnt=0;
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<n;j++)
//            {
//                sum1[cnt]=a[i]+b[j];
//                sum2[cnt]=c[i]+d[j];
//                cnt++;
//            }
//        }
//        sort(sum1,sum1+cnt);
//        int ans=0;
//        for(int i=0;i<cnt;i++)
//        {
//            ans+=upper_bound(sum1,sum1+cnt,-sum2[i])-lower_bound(sum1,sum1+cnt,-sum2[i]);
//        }
//        cout<<ans<<endl;
//        if(t)
//            cout<<endl;
//    }
//    return 0;
//}

#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int M;
struct point
{
    int l,r;
}p1[maxn],p2[maxn];
bool cmp(point a,point b)
{
    if(a.r<b.r)
        return true;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int cnt=0;
        while(1)
        {
            cin>>p1[cnt].l>>p1[cnt].r;
            if(p1[cnt].l==p1[cnt].r==0)
                break;
            cnt++;
        }
        int cnt_1=0
        for(int j=0;j<=cnt;j++)
        {
            if(p1[j].r<=0||p1[j].l>=M)
            {
                continue;
            }
            p2[cnt_1].l=p1[j].l;
            p2[cnt_1].r=p1[j].r;
            cnt_1++;
        }
        sort(p2,p2+cnt_1,cmp);
    }
    return 0;
}




