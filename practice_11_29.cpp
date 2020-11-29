//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//ll b,p,k,ans=1,t,b1,p1,k1;
//int main()
//{
//    cin>>b>>p>>k;
//    b1=b;p1=p;k1=k;
//    while(p>0)
//    {
//        if(p&1)
//        ans=ans*b%k;
//        b=b*b%k;
//        p>>=1;
//    }
//    cout<<b1<<"^"<<p1<<" mod "<<k1<<"="<<ans%k<<endl;
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN=101;
//int s,n,m,vis[MAXN][MAXN];
//struct node
//{
//    int v[3],step;
//};
//void bfs()
//{
//    queue<node> q;
//    node now,next;
//    now.v[0]=s;
//    now.v[1]=0;
//    now.v[2]=0;
//    now.step=0;
//    vis[now.v[0]][now.v[1]]=1;
//    q.push(now);
//    while(!q.empty())
//    {
//        now=q.front();
//        if((now.v[0]==now.v[1]&&!now.v[2])||(now.v[1]==now.v[2]&&!now.v[0])||(now.v[2]==now.v[0]&&!now.v[1]))
//        {
//            cout<<now.step<<endl;
//            return;
//        }
//        q.pop();
//        for(int i=1;i<=6;i++)
//        {
//            switch(i)
//            {
//            case 1:
//                if(now.v[0]!=0&&now.v[1]!=n)
//                    next.v[0]=now.v[0]-(n-now.v[1]),next.v[1]=n,next.v[2]=now.v[2];
//                break;
//            case 2:
//                if(now.v[0]!=0&&now.v[2]!=m)
//                    next.v[0]=now.v[0]-(m-now.v[2]),next.v[2]=m,next.v[1]=now.v[1];
//                break;
//            case 3:
//                if(now.v[1])
//                    next.v[0]=now.v[0]+now.v[1],next.v[1]=0,next.v[2]=now.v[2];
//                break;
//            case 4:
//                if(now.v[2])
//                    next.v[0]=now.v[0]+now.v[2],next.v[1]=now.v[1],next.v[2]=0;
//                break;
//            case 5:
//                if(now.v[1]!=0&&now.v[2]!=m)
//                {
//                    if(now.v[1]+now.v[2]>m)
//                    {
//                        next.v[0]=now.v[0],next.v[1]=now.v[1]-(m-now.v[2]),next.v[2]=m;
//                    }
//                    else
//                        next.v[0]=now.v[0],next.v[1]=0,next.v[2]=now.v[2]+now.v[1];
//                }
//                break;
//            case 6:
//                if(now.v[2]!=0&&now.v[1]!=n)
//                {
//                    if(now.v[1]+now.v[2]>n)
//                    {
//                        next.v[0]=now.v[0],next.v[2]=now.v[2]-(n-now.v[1]),next.v[1]=n;
//                    }
//                    else
//                        next.v[0]=now.v[0],next.v[2]=0,next.v[1]=now.v[1]+now.v[2];
//                }
//                break;
//            }
//            if(!vis[next.v[0]][next.v[1]])
//            {
//                next.step=now.step+1;
//                q.push(next);
//                vis[next.v[0]][next.v[1]]=1;
//            }
//        }
//
//    }
//    cout<<"NO"<<endl;
//    return;
//}
//int main()
//{
//    while(cin>>s>>n>>m&&s&&n&&m)
//    {
//        memset(vis,0,sizeof(vis));
//        if(s%2)
//        {
//            cout<<"NO"<<endl;
//            continue;
//        }
//        if(n==m)
//        {
//            cout<<1<<endl;
//            continue;
//        }
//        bfs();
//    }
//    return 0;
//}


#include<bits/stdc++.h>
using namespace std;
const int maxx=35;
int l,r,c,strx,stry,strz,endx,endy,endz;
int b[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,-1},{0,0,1}};
char a[maxx][maxx][maxx];
int ans;
struct node
{
    int x,y,z,st;
};
bool check(int dx,int dy,int dz)
{
    if(dx<0||dy<0||dz<0||dx>=r||dy>=c||dz>=l||a[dz][dx][dy]=='#')
        return false;
    return true;
}
void bfs()
{
    queue<node> q;
    node cur,next;
    cur.x=strx,cur.y=stry,cur.z=strz;
    cur.st=0;
    a[cur.z][cur.x][cur.y]='#';
    q.push(cur);
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        if(cur.x==endx&&cur.y==endy&&cur.z==endz)
        {
            cout<<"Escaped in "<<cur.st<<" minute(s)."<<endl;
            return ;
        }
        for(int i=0;i<6;i++)
        {
            next.x=cur.x+b[i][0],next.y=cur.y+b[i][1],next.z=cur.z+b[i][2];
            if(check(next.x,next.y,next.z))
            {
                a[next.z][next.x][next.y]='#';
                next.st=cur.st+1;
                q.push(next);
            }
        }
    }
    cout<<"Trapped!"<<endl;
    return;
}

int main()
{
    while(cin>>l>>r>>c&&l&&r&&c)
    {
        for(int i=0;i<l;i++)
        {
            for(int j=0;j<r;j++)
            {
                scanf("%s",a[i][j]);
                for(int k=0;k<c;k++)
                {
                    if(a[i][j][k]=='S')
                        strx=j,stry=k,strz=i;
                    if(a[i][j][k]=='E')
                        endx=j,endy=k,endz=i;
                }
            }
        }
//        for(int i=1;i<=l;i++)
//        {
//            for(int j=1;j<=r;j++)
//            {
//                cout<<a[i][j]<<endl;
//            }
//
//        }
//        cout<<strx<<" "<<stry<<" "<<strz<<endl;
//        cout<<endx<<" "<<endy<<" "<<endz<<endl;
        bfs();
    }

    return 0;
}
