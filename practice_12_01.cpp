//#include<iostream>
//#include<cstring>
//using namespace std;
//int T,n,m,strx,stry,step=1,ans;
//bool vis[15][15];
//int dir[8][2]={{2,1},{2,-1},{1,2},{1,-2},{-1,2},{-1,-2},{-2,1},{-2,-1}};
//bool check(int x,int y)
//{
//    if(x<0||y<0||x>=n||y>=m||vis[x][y])
//        return false;
//    return true;
//}
//void dfs(int x,int y,int step)
//{
//    if(step>=n*m)
//    {
//        ans++;
//        return;
//    }
//    for(int i=0;i<8;i++)
//    {
//        int tx=x+dir[i][0];
//        int ty=y+dir[i][1];
//        if(check(tx,ty))
//        {
//            vis[tx][ty]=1;
//            dfs(tx,ty,step+1);
//            vis[tx][ty]=0;
//        }
//    }
//}
//int main()
//{
//    cin>>T;
//    while(T--)
//    {
//        ans=0;
//        step=1;
//        memset(vis,0,sizeof(vis));
//        cin>>n>>m>>strx>>stry;
//        vis[strx][stry]=1;
//        dfs(strx,stry,step);
//        cout<<ans<<endl;
//    }
//    return 0;
//}

//
//#include<iostream>
//#include<queue>
//#include<cstring>
//using namespace std;
//int n,a[20][20],ans;
//bool vis[20];
//struct node
//{
//    int x,pos,step;
//};
//void bfs()
//{
//    queue<node> q;
//    node cur,next;
//    cur.x=1,cur.pos=1,
//}
//int main()
//{
//    while(cin>>n&&n)
//    {
//        ans=0;
//        memset(vis,0,sizeof(vis));
//        for(int i=1;i<=n;i++)
//        {
//            for(int j=1;j<=n;j++)
//                cin>>a[i][j];
//        }
//        bfs();
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//int w[20][20],minn=1<<17,ans,vis[20],n,been=0;
//int a[1<<17][20];
//void dfs(int s,int c)
//{
//    if(s==n-1)
//    {
//        minn=min(ans+w[c][n],minn);
//        return;
//    }
//    for(int i=2;i<n;i++)
//    {
//        if(!vis[i])
//        {
//            int q=been+pow(2,i-1);
//            if(ans+w[c][i]>=a[q][i])
//                continue;
//            a[q][i]=ans+w[c][i];
//            vis[i]=1;
//            been+=pow(2,i-1);
//            ans+=w[c][i];
//            dfs(s+1,i);
//            ans-=w[c][i];
//            been-=pow(2,i-1);
//            vis[i]=0;
//        }
//    }
//}
//int main()
//{
//    while(cin>>n&&n)
//    {
//        minn=1<<17;
//        for(int i=0;i<(1<<17);i++)
//            for(int j=0;j<20;j++)
//            a[i][j]=1<<17;
//        for(int i=1;i<=n;i++)
//            for(int j=1;j<=n;j++)
//            cin>>w[i][j];
//        memset(vis,0,sizeof(vis));
//        vis[1]=1;
//        been=1;
//        dfs(been,1);
//        cout<<minn<<endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<queue>
//using namespace std;
//int maze[5][5],endx=4,endy=4;
//bool vis[5][5];
//int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
//struct node
//{
//    int x,y;
//};
//struct path
//{
//    int x,y;
//}path[5][5];
//bool check(int x,int y)
//{
//    if(x<0||x>=5||y<0||y>=5||vis[x][y]||maze[x][y])
//        return false;
//    return true;
//}
//void dfs(int x,int y)
//{
//    if(path[x][y].x==0&&path[x][y].y==0)
//    {
//        cout<<"("<<path[x][y].x<<", "<<path[x][y].y<<")"<<endl;
//        return;
//    }
//    dfs(path[x][y].x,path[x][y].y);
//    cout<<"("<<path[x][y].x<<", "<<path[x][y].y<<")"<<endl;
//}
//void bfs()
//{
//    queue<node> q;
//    node cur,next;
//    cur.x=0,cur.y=0;
//    q.push(cur);
//    while(!q.empty())
//    {
//        cur=q.front();
//        q.pop();
//        if(cur.x==endx&&cur.y==endy)
//        {
//            dfs(cur.x,cur.y);
//            cout<<"("<<cur.x<<", "<<cur.y<<")"<<endl;
//            return;
//        }
//        for(int i=0;i<4;i++)
//        {
//            next.x=cur.x+dir[i][0];
//            next.y=cur.y+dir[i][1];
//            if(check(next.x,next.y))
//            {
//                vis[next.x][next.y]=1;
//                path[next.x][next.y].x=cur.x;
//                path[next.x][next.y].y=cur.y;
//                q.push(next);
//            }
//        }
//    }
//}
//int main()
//{
//    for(int i=0;i<5;i++)
//    {
//        for(int j=0;j<5;j++)
//            cin>>maze[i][j];
//    }
//    bfs();
//    return 0;
//}
//

//#include<iostream>
//#include<queue>
//using namespace std;
//int m,n,t,strx,stry,endx,endy;
//const int maxn=210;
//char a[maxn][maxn];
//bool vis[maxn][maxn][15];
//int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
//struct node
//{
//    int x,y,t,st;
//};
//bool check(int x,int y,int& t)
//{
//    if(x<0||y<0||x>=m||y>=n||vis[x][y][t])
//        return false;
//    if(!t&&a[x][y]=='#')
//        return false;
//    if(t&&a[x][y]=='#')
//        t--;
//    return true;
//}
//void bfs()
//{
//    queue<node> q;
//    node cur,next;
//    cur.x=strx,cur.y=stry,cur.st=0,cur.t=t;
//    vis[cur.x][cur.y][cur.t]=1;
//    q.push(cur);
//    while(!q.empty())
//    {
//        cur=q.front();
//        q.pop();
//        if(cur.x==endx&&cur.y==endy)
//        {
//            cout<<cur.st<<endl;
//            return ;
//        }
//        for(int i=0;i<4;i++)
//        {
//            next.x=cur.x+dir[i][0];
//            next.y=cur.y+dir[i][1];
//            next.t=cur.t;
//            if(check(next.x,next.y,next.t))
//            {
//                next.st=cur.st+1;
//                vis[next.x][next.y][next.t]=1;
//                q.push(next);
//            }
//        }
//    }
//    cout<<-1<<endl;
//}
//int main()
//{
//    cin>>m>>n>>t;
//    for(int i=0;i<m;i++)
//    {
//        cin>>a[i];
//    }
//    for(int i=0;i<m;i++)
//    {
//        for(int j=0;j<n;j++)
//        {
//            if(a[i][j]=='@')
//            {
//                strx=i,stry=j;
//            }
//            if(a[i][j]=='+')
//            {
//                endx=i,endy=j;
//            }
//        }
//    }
//    bfs();
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//using namespace std;
//int n,k,vis[10],ans;
//char a[10][10];
//bool check(int cur,int col)
//{
//    for(int i=0;i<cur-1;i++)
//    {
//        if(vis[i]==col)
//            return false;
//    }
//    return true;
//}
//void dfs(int cur)
//{
//    if(cur==n)
//    {
//        ans++;
//        return;
//    }
//    for(int i=0;i<n;i++)
//    {
//        if(a[cur][i]=='#'&&check(cur,i))
//        {
//            vis[i]=1;
//            dfs(cur+1);
//            vis[i]=0;
//        }
//    }
//}
//int main()
//{
//    while(cin>>n>>k)
//    {
//
//        if(n==-1&&k==-1)
//            break;
//        ans=0;
//        int cnt=0;
//        memset(vis,0,sizeof(vis));
//        for(int i=0;i<n;i++)
//            for(int j=0;j<n;j++)
//            {
//                cin>>a[i][j];
//                if(a[i][j]=='#')
//                    cnt++;
//            }
//        if(k==1)
//        {
//            cout<<cnt<<endl;
//            continue;
//        }
//        dfs(0);
//        cout<<ans<<endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<queue>
//using namespace std;
//int n,m,rx,ry,ax,ay;
//const int maxn=210;
//char a[maxn][maxn];
//bool vis[maxn][maxn];
//int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
//struct node
//{
//    int x,y,t;
//};
//bool check(int x,int y)
//{
//    if(x<0||y<0||x>=n||y>=m||vis[x][y]||a[x][y]=='#')
//        return false;
//    return true;
//}
//void bfs()
//{
//    queue<node> q;
//    node cur,next;
//    cur.x=rx,cur.y=ry,cur.t=0;
//    vis[cur.x][cur.y]=1;
//    q.push(cur);
//    while(!q.empty())
//    {
//        cur=q.front();
//        q.pop();
//        if(cur.x==ax&&cur.y==ay)
//        {
//            cout<<cur.t<<endl;
//            return ;
//        }
//        for(int i=0;i<4;i++)
//        {
//            next.x=cur.x+dir[i][0];
//            next.y=cur.y+dir[i][1];
//            if(check(next.x,next.y))
//            {
//                if(a[next.x][next.y]=='x')
//                    next.t=cur.t+2;
//                else
//                    next.t=cur.t+1;
//                vis[next.x][next.y]=1;
//                q.push(next);
//            }
//        }
//    }
//    cout<<"Impossible"<<endl;
//}
//int main()
//{
//    int s;
//    cin>>s;
//    while(s--)
//    {
//        memset(vis,0,sizeof(vis));
//        cin>>n>>m;
//        for(int i=0;i<n;i++)
//        {
//            cin>>a[i];
//        }
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<m;j++)
//            {
//                if(a[i][j]=='a')
//                    ax=i,ay=j;
//                if(a[i][j]=='r')
//                    rx=i,ry=j;
//            }
//        }
//        bfs();
//    }
//    return 0;
//}


//#include<iostream>
//#include<cstring>
//#include<queue>
//using namespace std;
//int n,m,tx,ty,kx,ky;
//const int maxn=110;
//char a[maxn][maxn];
//bool vis[maxn][maxn];
//int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
//struct node
//{
//    int x,y,k,st;
//};
//void bfs()
//{
//    queue<node> q;
//    node cur,next;
//    cur.x=kx,cur.y=ky,cur.st=0,cur.k=0;
//    q.push(cur);
//    while(!q.empty())
//    {
//        cur=q.front();
//        q.pop();
//        if(cur.x==tx&&cur.y==ty&&cur.k==m)
//        {
//            cout<<cur.st<<endl;
//            return;
//        }
//        for(int i=0;i<4;i++)
//        {
//            next.x=cur.x+dir[i][0];
//            next.y=cur.y+dir[i][1];
//            if(check(next.x,next.y))
//            {
//                if(a[next.x][next.y]>'0'&&a[next.x][next.y]<='9')
//                {
//
//                }
//            }
//        }
//    }
//    cout<<"impossible"<<endl;
//}
//int main()
//{
//    while(cin>>n>>m)
//    {
//        if(!n&&!m)
//            break;
//        memset(vis,0,sizeof(vis));
//        for(int i=0;i<n;i++)
//            cin>>a[i];
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<n;j++)
//            {
//                if(a[i][j]=='K')
//                    kx=i,ky=j;
//                if(a[i][j]=='T')
//                    tx=i,ty=j;
//            }
//        }
//        bfs();
//    }
//    return 0;
//}


//#include<iostream>
//#include<queue>
//#include<cstring>
//using namespace std;
//const int maxn=110;
//int m,n,ans;
//bool vis[maxn][maxn];
//char a[maxn][maxn];
//int dir[8][2]={{-1,1},{-1,-1},{1,1},{1,-1},{1,0},{-1,0},{0,-1},{0,1}};
//struct node
//{
//    int x,y;
//};
//bool check(int x,int y)
//{
//    if(x<0||y<0||x>=m||y>=n||vis[x][y]||a[x][y]=='*')
//        return false;
//    return true;
//}
//void bfs(int x,int y)
//{
//    queue<node> q;
//    node cur,next;
//    cur.x=x,cur.y=y;
//    vis[cur.x][cur.y]=1;
//    q.push(cur);
//    while(!q.empty())
//    {
//        cur=q.front();
//        q.pop();
//        for(int i=0;i<8;i++)
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
//    ans++;
//}
//int main()
//{
//    while(cin>>m>>n&&m&&n)
//    {
//        ans=0;
//        memset(vis,0,sizeof(vis));
//        for(int i=0;i<m;i++)
//            cin>>a[i];
//        for(int i=0;i<m;i++)
//        {
//            for(int j=0;j<n;j++)
//            {
//                if(a[i][j]=='@'&&!vis[i][j])
//                    bfs(i,j);
//            }
//        }
//        cout<<ans<<endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<queue>
//#include<cstring>
//using namespace std;
//const int maxn=25;
//int w,h,stx,sty,ans;
//char a[maxn][maxn];
//bool vis[maxn][maxn];
//int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
//struct node
//{
//    int x,y;
//};
//bool check(int x,int y)
//{
//    if(x<0||y<0||x>=h||y>=w||vis[x][y]||a[x][y]=='#')
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
//                ans++;
//                q.push(next);
//            }
//        }
//    }
//}
//int main()
//{
//    while(cin>>w>>h&&w&&h)
//    {
//        ans=0;
//        memset(vis,0,sizeof(vis));
//        for(int i=0;i<h;i++)
//        cin>>a[i];
//        for(int i=0;i<h;i++)
//        {
//            for(int j=0;j<w;j++)
//            {
//                if(a[i][j]=='@')
//                    stx=i,sty=j;
//            }
//        }
//        bfs();
//        cout<<ans+1<<endl;
//    }
//    return 0;
//}


//#include<iostream>
//#include<queue>
//#include<cstring>
//using namespace std;
//const int maxn=210;
//char a[maxn][maxn];
//int n,m,ans,endx,endy,yx,yy,mx,my;
//bool vis1[maxn][maxn],vis2[maxn][maxn];
//int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
//struct node
//{
//    int x,y,st;
//};
//bool check1(int x,int y)
//{
//    if(x<0||y<0||x>=n||y>=m||vis1[x][y]||a[x][y]=='#')
//        return false;
//    return true;
//}
//bool check2(int x,int y)
//{
//    if(x<0||y<0||x>=n||y>=m||vis2[x][y]||a[x][y]=='#')
//        return false;
//    return true;
//}
//int bfs1()
//{
//    memset(vis1,0,sizeof(vis1));
//    queue<node> q;
//    node cur,next;
//    cur.x=yx,cur.y=yy,cur.st=0;
//    vis1[cur.x][cur.y]=1;
//    q.push(cur);
//    while(!q.empty())
//    {
//        cur=q.front();
//        q.pop();
//        if(cur.x==endx&&cur.y==endy)
//        return cur.st;
//        for(int i=0;i<4;i++)
//        {
//            next.x=cur.x+dir[i][0];
//            next.y=cur.y+dir[i][1];
//            if(check1(next.x,next.y))
//            {
//                vis1[next.x][next.y]=1;
//                next.st=cur.st+11;
//                q.push(next);
//            }
//        }
//    }
//}
//int bfs2()
//{
//    memset(vis2,0,sizeof(vis2));
//    queue<node> q;
//    node cur,next;
//    cur.x=mx,cur.y=my,cur.st=0;
//    vis1[cur.x][cur.y]=1;
//    q.push(cur);
//    while(!q.empty())
//    {
//        cur=q.front();
//        q.pop();
//        if(cur.x==endx&&cur.y==endy)
//        return cur.st;
//        for(int i=0;i<4;i++)
//        {
//            next.x=cur.x+dir[i][0];
//            next.y=cur.y+dir[i][1];
//            if(check2(next.x,next.y))
//            {
//                vis2[next.x][next.y]=1;
//                next.st=cur.st+11;
//                q.push(next);
//            }
//        }
//    }
//}
//int main()
//{
//    while(cin>>n>>m)
//    {
//        ans=0x3f3f3f3f;
//        for(int i=0;i<n;i++)
//        {
//            cin>>a[i];
//        }
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<m;j++)
//            {
//                if(a[i][j]=='Y')
//                    yx=i,yy=j;
//                if(a[i][j]=='M')
//                    mx=i,my=j;
//            }
//        }
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<m;j++)
//            {
//                if(a[i][j]=='@')
//                {
//                    endx=i,endy=j;
//                    ans=min(ans,bfs1()+bfs2());
//                }
//
//            }
//        }
//        cout<<ans<<endl;
//    }
//    return 0;
//}









