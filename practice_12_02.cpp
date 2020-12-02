//#include<iostream>
//#include<cstring>
//#include<queue>
//using namespace std;
//int r,c,stx,sty,fx,fy;
//const int maxn=1010;
//char a[maxn][maxn];
//bool vis[maxn][manx];
//struct node
//{
//    int x,y,t;
//};
//struct fire
//{
//    int x,y;
//};
//void bfs()
//{
//    queue<node> q1;
//    queue<fire> q2;
//    node curj,nextj;
//    fire curf,nextf;
//    curj.x=stx,curj.y=sty,curj.t=0;
//    curf.x=fx,curf.y=fy;
//    vis1[curj.x][curj.y]=1;
//    vis2[curf.x][curf.y]=1;
//    q1.push(curj),q2.push(curf);
//    while(!q1.empty())
//    {
//
//    }
//}
//int main()
//{
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        cin>>r>>c;
//        for(int i=0;i<r;i++)
//        {
//            cin>>a[i];
//        }
//        for(int i=0;i<r;i++)
//        {
//            for(int j=0;j<c;j++)
//            {
//                if(a[i][j]=='J')
//                    stx=i,sty=j;
//                if(a[i][j]=='F')
//                    fx=i,fy=j;
//            }
//        }
//        bfs();
//    }
//    return 0;
//}
//
//#include<iostream>
//#include<queue>
//#include<cstring>
//using namespace std;
//const int maxn=1010;
//int r,c,stx,sty,fx,fy,time1[maxn][maxn];
//char a[maxn][maxn];
//bool vis[maxn][maxn];
//int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
//struct node
//{
//    int x,y,t;
//};
//bool check1(int x,int y)
//{
//    if(x<0||y<0||x>=r||y>=c||vis[x][y]||a[x][y]=='#')
//        return false;
//    return true;
//}
//bool check(int x,int y,int t)
//{
//    if(x<0||y<0||x>=r||y>=c||vis[x][y]||a[x][y]=='#'||a[x][y]=='F'||(time1[x][y]&&t+1>=time1[x][y]))
//        return false;
//    return true;
//}
//void bfs()
//{
//    memset(vis,0,sizeof(vis));
//    queue<node> q;
//    node cur,next;
//    cur.x=stx,cur.y=sty,cur.t=0;
//    vis[cur.x][cur.y]=1;
//    q.push(cur);
//    while(!q.empty())
//    {
//        cur=q.front();
//        q.pop();
//        if(cur.x==0||cur.y==0||cur.x==r-1||cur.y==c-1)
//        {
//            cout<<cur.t+1<<endl;
//            return ;
//        }
//        for(int i=0;i<4;i++)
//        {
//            next.x=cur.x+dir[i][0];
//            next.y=cur.y+dir[i][1];
//            if(check(next.x,next.y,cur.t))
//            {
//                vis[next.x][next.y]=1;
//                next.t=cur.t+1;
//                q.push(next);
//            }
//        }
//    }
//    cout<<"IMPOSSIBLE"<<endl;
//}
//int main()
//{
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        cin>>r>>c;
//        for(int i=0;i<r;i++)
//            cin>>a[i];
//        for(int i=0;i<r;i++)
//        {
//            for(int j=0;j<c;j++)
//            {
//                if(a[i][j]=='J')
//                    stx=i,sty=j;
//                if(a[i][j]=='F')
//                    fx=i,fy=j;
//            }
//        }
//            memset(time1,0,sizeof(time1));
//            memset(vis,0,sizeof(vis));
//            queue<node> t;
//            node cur,next;
//            cur.x=fx,cur.y=fy,cur.t=0;
//            vis[cur.x][cur.y]=1;
//            time1[cur.x][cur.y]=cur.t;
//            t.push(cur);
//            while(!t.empty())
//            {
//                cur=t.front();
//                t.pop();
//                for(int k=0;k<4;k++)
//                {
//                    next.x=cur.x+dir[k][0];
//                    next.y=cur.y+dir[k][1];
//                    if(check1(next.x,next.y))
//                    {
//                        vis[next.x][next.y]=1;
//                        next.t=cur.t+1;
//                        time1[next.x][next.y]=next.t;
//                        t.push(next);
//                    }
//                }
//            }
//        bfs();
//    }
//    return 0;
//}

//#include<iostream>
//#include<queue>
//#include<cstring>
//using namespace std;
//const int maxn=110;
//int n,k,stx,sty,tx,ty;
//char a[maxn][maxn];
//bool vis[maxn][maxn][10];
//int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
//struct node
//{
//    int x,y,k,t;
//};
//bool check(int x,int y)
//{
//    if(x<0||y<0||x>=n||y>=n||a[x][y]=='#')
//        return false;
//    return true;
//}
//void bfs()
//{
//    queue<node> q;
//    node cur,next;
//    cur.x=stx,cur.y=sty,cur.k=0,cur.t=0;
//    vis[cur.x][cur.y][cur.k]=1;
//    q.push(cur);
//    while(!q.empty())
//    {
//        cur=q.front();
//        q.pop();
//        if(cur.x==tx&&cur.y==ty&&cur.k==k)
//        {
//            cout<<cur.t<<endl;
//            return;
//        }
//        for(int i=0;i<4;i++)
//        {
//            next.x=cur.x+dir[i][0];
//            next.y=cur.y+dir[i][1];
//            if(check(next.x,next.y))
//            {
//                if(a[next.x][next.y]=='S')
//                {
//                    next.t=cur.t+2;
//                    a[next.x][next.y]=='.';
//                    next.k=cur.k;
//                    vis[next.x][next.y][next.k]=1;
//                    q.push(next);
//                }
//                else if((a[next.x][next.y]>'0'&&a[next.x][next.y]<='9'))
//                {
//                    if((a[next.x][next.y]-'0')==cur.k+1)
//                        next.k=cur.k+1;
//                    else
//                        next.k=cur.k;
//                    if(vis[next.x][next.y][next.k])
//                        continue;
//                    vis[next.x][next.y][next.k]=1;
//                    next.t=cur.t+1;
//                    q.push(next);
//                }
//                else
//                {
//                    next.k=cur.k;
//                    if(vis[next.x][next.y][next.k])
//                        continue;
//                    next.t=cur.t+1;
//                    vis[next.x][next.y][next.k]=1;
//                    q.push(next);
//                }
//            }
//        }
//    }
//    cout<<"impossible"<<endl;
//}
//int main()
//{
//    while(cin>>n>>k&&n&&k)
//    {
//        for(int i=0;i<n;i++)
//            cin>>a[i];
//    }
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<n;j++)
//        {
//            if(a[i][j]=='K')
//                stx=i,sty=j;
//            if(a[i][j]=='T')
//                tx=i,ty=j;
//        }
//    }
//    bfs();
//    return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//int n,c0,c1,h,ans;
//char s[1010];
//int main()
//{
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        ans=0;
//        cin>>n>>c0>>c1>>h>>s;
//        if(h+min(c1,c0)<max(c1,c0))
//        {
//            if(c1>c0)
//            {
//                for(int i=0;i<n;i++)
//                {
//                    if(s[i]=='1')
//                        ans+=(c0+h);
//                    else
//                        ans+=c0;
//                }
//            }
//            else
//            {
//                for(int i=0;i<n;i++)
//                {
//                    if(s[i]=='0')
//                    {
//                        ans+=(c1+h);
//                    }
//                    else
//                        ans+=c1;
//                }
//            }
//        }
//        else
//        {
//            for(int i=0;i<n;i++)
//            {
//                if(s[i]=='0')
//                    ans+=c0;
//                else
//                    ans+=c1;
//            }
//        }
//        cout<<ans<<endl;
//    }
//    return 0;
//}

//
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int n,k,a[200010];
//long long ans;
//int main()
//{
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        ans=0;
//        cin>>n>>k;
//        for(int i=1;i<=n*k;i++)
//        {
//            cin>>a[i];
//        }
//        int tmp;
//        if(n%2)
//        {
//            tmp=n/2+1;
//        }
//        else
//            tmp=n/2;
//        tmp=n-tmp+1;
//        int cur=n*k+1;
//        while(k--)
//        {
//            cur-=tmp;
//            ans+=a[cur];
//        }
//        cout<<ans<<endl;
//    }
//    return 0;
//}

//#include<iostream>
//using namespace std;
//const int maxn=110;
//int n,m,ans;
//char a[maxn][maxn];
//struct anss
//{
//    int x1,y1,x2,y2,x3,y3;
//}b[3*maxn*maxn];
//int main()
//{
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        ans=0;
//        cin>>n>>m;
//        for(int i=1;i<=n;i++)
//        {
//            for(int j=1;j<=m;j++)
//            {
//                a[i][j]=getchar();
//            }
//            getchar();
//        }
//        for(int i=1;i<=n;i++)
//        {
//            for(int j=1;j<=m;j++)
//            {
//                if(a[i][j]=='1')
//                {
//                    ans++;
//                    b[ans].x1=i,b[ans].y1=j;
//                    b[ans].x2=i,b[ans].y2=j+1;
//                    b[ans].x3=i+1,b[ans].y3=j;
//                    ans++;
//                    b[ans].x1=i,b[ans].y1=j;
//                    b[ans].x2=i,b[ans].y2=j+1;
//                    b[ans].x3=i+1,b[ans].y3=j+1;
//                    ans++;
//                    b[ans].x1=i,b[ans].y1=j;
//                    b[ans].x2=i+1,b[ans].y2=j;
//                    b[ans].x3=i+1,b[ans].y3=j+1;
//                }
//            }
//        }
//        cout<<ans<<endl;
//        for(int i=1;i<=ans;i++)
//        {
//            cout<<b[ans].x1<<" "<<b[ans].y1<<" "
//            <<b[ans].x2<<" "<<b[ans].y2<<" "<<
//            b[ans].x3<<" "<<b[ans].y3<<endl;
//        }
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//bool cmp(int a,int b)
//{
//    return a>b;
//}
//int circle(int num)
//{
//    int ans=0,a[4];
//    while(1)
//    {
//        ans++;
//        int tmp=num;
//            a[0]=num%10;
//            a[1]=num/10%10;
//            a[2]=num/100%10;
//            a[3]=num/1000;
//            int b=0,c=0;
//            sort(a,a+4);
//            for(int i=0;i<4;i++)
//            {
//                b=b*10+a[i];
//            }
//            sort(a,a+4,cmp);
//            for(int i=0;i<4;i++)
//            {
//                c=c*10+a[i];
//            }
//            num=c-b;
//            if(num==tmp)
//            break;
//    }
//    return ans;
//}
//int main()
//{
//    int n,a;
//    cin>>n;
//    while(n--)
//    {
//        cin>>a;
//        cout<<circle(a)<<endl;
//    }
//    return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//int n,m,a[110][110],ans,stx,sty;
//bool vis[110][110];
//int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
//struct node
//{
//    int x,y;
//};
//bool check(int x,int y)
//{
//    if(x<0||y<0||x>=n||y>=m||vis[x][y]||!a[x][y])
//        return false;
//    return true;
//}
//void bfs()
//{
//    queue<node> q;
//    node cur,next;
//    cur.x=stx,cur.y=sty;
//    vis[cur.x][cur.y]=1;
//    q.push(cur);
//    while(!q.empty())
//    {
//        cur=q.front();
//        q.pop();
//        for(int i=0;i<4;i++)
//        {
//            next.x=cur.x+dir[i][0];
//            next.y=cur.y+dir[i][1];
//            if(check(next.x,next.y))
//            {
//                vis[next.x][next.y]=1;
//                q.push(next);
//            }
//        }
//    }
//}
//int main()
//{
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        ans=0;
//        memset(vis,0,sizeof(vis));
//        cin>>n>>m;
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<m;j++)
//            {
//                cin>>a[i][j];
//            }
//        }
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<m;j++)
//            {
//                if(a[i][j]&&!vis[i][j])
//                {
//                    stx=i,sty=j;
//                    ans++;
//                    bfs();
//                }
//            }
//        }
//        cout<<ans<<endl;
//    }
//    return 0;
//}

#include<bits/stdc++.h>
using namespace std;
int t,n;
double ans;
double a[6];
int main()
{
    cin>>t;
    while(t--)
    {
        ans=0.0;
        cin>>n;
        for(int i=0;i<6;i++)
            cin>>a[i];
        cout<<"Case #"<<t+1<<": ";
        for(int i=0;i<6;i++)
        ans+=(i+1)*a[i];
        printf("%.4lf\n",ans*n);
    }
    return 0;
}










