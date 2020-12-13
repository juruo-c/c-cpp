//#include<iostream>
//using namespace std;
//const int maxn = 1e5+10;
//int n,a[maxn];
//bool vis[maxn];
//void dfs(int dep)
//{
//    if(dep>n){
//        for(int i=1;i<=n;i++){
//            if(vis[i])printf("%d ",a[i]);
//        }
//        printf("\n");
//        return;
//    }
//    vis[dep]=1;
//    dfs(dep+1);
//    vis[dep]=0;
//    dfs(dep+1);
//}
//int main()
//{
//    cin>>n;
//    for(int i=1;i<=n;i++)cin>>a[i];
//    dfs(1);
//    return 0;
//}
//#include<iostream>
//using namespace std;
//const int maxn = 1e5+10;
//int n,a[maxn],b[maxn],index;
//void dfs(int st,int pos,int len,int nlen)
//{
//    if(st>pos){
//        if(nlen==len){
//            for(int i=0;i<index;i++){
//                printf("%d ",b[i]);
//            }
//            printf("%d\n",a[pos+1]);
//        }
//        return;
//    }
//    b[index++]=a[st];
//    dfs(st+1,pos,len,nlen+1);
//    index--;
//    dfs(st+1,pos,len,nlen);
//}
//
//int main()
//{
//    cin>>n;
//    for(int i=1;i<=n;i++)a[i]=i;
//    for(int pos=1;pos<=n;pos++){
//        for(int len=0;len<=pos-1;len++){
//            dfs(1,pos-1,len,0);
//        }
//    }
//    return 0;
//}

//#include<iostream>
//#include<queue>
//#include<cstring>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//const int maxn = 110;
//const int inf = (int)1e10;
//int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
//char g[maxn][maxn];
//int e[maxn][maxn],vis[maxn][maxn][11];
//int n,m,ans;
//struct node
//{
//    int x,y,t,id,s;
//    friend bool operator<(node a,node b){
//        return a.t>b.t;
//    }
//};
//bool judge(int x,int y)
//{
//    if(x<0||x>=n||y<0||y>=0||g[x][y]=='#')
//    {
//        return true;
//    }
//    return false;
//}
//void bfs(int x,int y)
//{
//    int dx,dy;
//    priority_queue<node> q;
//    node cur,next;
//    cur.x=x,cur.y=y,cur.t=cur.s=0;
//    cur.id=1;
//    q.push(cur);
//    vis[x][y][1]=0;
//    while(!q.empty()){
//        cur=q.top();
//        q.pop();
//        if(g[cur.x][cur.y]=='T'&&cur.id==m+1){
//            ans=min(ans,cur.t);
//            continue;
//        }
//        for(int i=0;i<4;i++){
//            next.x=dx=cur.x+dir[i][0];
//            next.y=dy=cur.y+dir[i][1];
//            next.t=cur.t+1;
//            next.s=cur.s;
//            next.id=cur.id;
//            if(judge(dx,dy))continue;
//            if(g[dx][dy]=='S'){
//                int t = e[dx][dy];
//                if(next.s&(1<<t)==0){
//                    next.s|=(1<<t);
//                    next.t++;
//                }
//            }
//            if(next.id==g[dx][dy]-'0'){
//                next.id++;
//            }
//            int t = next.id;
//            if(vis[dx][dy][t]>next.t){
//                vis[dx][dy][t]=next.t;
//                q.push(next);
//            }
//        }
//    }
//}
//int main()
//{
//    int k,stx,sty;
//    while(cin>>n>>m){
//        k=0;
//        if(!n&&!m)break;
//        memset(e,0,sizeof(e));
//        for(int i=0;i<n;i++){
//            scanf("%s",g[i]);
//            for(int j=0;j<n;j++){
//                if(g[i][j]=='K')
//                {
//                    stx=i;sty=j;
//                }
//                if(g[i][j]=='S'){
//                    e[i][j]=k++;
//                }
//                for(int l=0;l<11;l++){
//                    vis[i][j][l]=inf;
//                }
//            }
//        }
//        ans=inf;
//        bfs(stx,sty);
//        if(ans==inf)printf("impossible\n");
//        else printf("%d\n",ans);
//    }
//    return 0;
//}

//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<queue>
//#include<cstring>
//using namespace std;
//#define N 105
//const int inf=(int)1e10;
//int dir[4][2]={0,1,1,0,0,-1,-1,0};
//char g[N][N];
//int e[N][N];
//int mark[N][N][11];
//int n,m,ans;
//struct node
//{
//    int x,y,t,id,s;   //坐标、时间、钥匙、和杀死的蛇
//    friend bool operator<(node a,node b)
//    {
//        return a.t>b.t;
//    }
//};
//int min(int a,int b)
//{
//    return a<b?a:b;
//}
//bool judge(int x,int y)        //判断该点是否能走，不能走返回真
//{
//    if(x<0||x>=n||y<0||y>=n||g[x][y]=='#')
//        return true;
//    return false;
//}
//void bfs(int x,int y)
//{
//    int i,di,dj;
//    priority_queue<node>q;
//    node cur,next;
//    cur.x=x;cur.y=y;
//    cur.t=cur.s=0;
//    cur.id=1;
//    q.push(cur);
//    mark[x][y][1]=0;
//    while(!q.empty())
//    {
//        cur=q.top();
//        q.pop();
//        if(g[cur.x][cur.y]=='T'&&cur.id==m+1)
//        {
//            ans=min(ans,cur.t);
//            continue;
//        }
//        for(i=0;i<4;i++)
//        {
//            next.x=di=cur.x+dir[i][0];
//            next.y=dj=cur.y+dir[i][1];
//            next.t=cur.t+1;
//            next.s=cur.s;
//            next.id=cur.id;
//            if(judge(di,dj))
//                continue;
//            if(g[di][dj]=='S')
//            {
//                int t=e[di][dj];
//                if((next.s&(1<<t))==0)
//                {
//                    next.s|=(1<<t);
//                    next.t++;
//                }
//                //printf("ss  %d %d\n",t,next.t);
//            }
//            if(next.id==g[di][dj]-'0') //只有前几把钥匙拿到手后才能拿下一把钥匙
//            {
//                next.id++;
//            }
//            int t=next.id;
//            if(mark[di][dj][t]>next.t) //拿过某一把钥匙后的最小时间
//            {
//                mark[di][dj][t]=next.t;
//                q.push(next);
//                //printf("%d %d   时间%d %d\n",next.x,next.y,next.t,next.id);
//            }
//        }
//    }
//}
//int main()
//{
//    int i,j,k,l,si,sj;
//    while(scanf("%d%d",&n,&m),n||m)
//    {
//        k=0;
//        memset(e,0,sizeof(e));
//        for(i=0;i<n;i++)
//        {
//            scanf("%s",g[i]);
//            for(j=0;j<n;j++)
//            {
//                if(g[i][j]=='K')
//                {
//                    si=i;sj=j;
//                }
//                if(g[i][j]=='S')
//                {
//                    e[i][j]=k++;
//                }
//                for(l=0;l<11;l++)
//                {
//                    mark[i][j][l]=inf;
//                }
//            }
//        }
//        ans=inf;
//        bfs(si,sj);
//        if(ans==inf)
//            printf("impossible\n");
//        else
//            printf("%d\n",ans);
//
//    }
//    return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//const int maxn = 110;
//char a[maxn][maxn];
//int n,m,ans;
//bool vis[maxn][maxn];
//int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
//void dfs(int x,int y)
//{
//    if(x<0||y<0||x>=n||y>=m||a[x][y]=='.'||vis[x][y])return;
//    vis[x][y]=1;
//    dfs(x+1,y+1);
//    dfs(x+1,y-1);
//    dfs(x-1,y+1);
//    dfs(x-1,y-1);
//    dfs(x+1,y);
//    dfs(x-1,y);
//    dfs(x,y+1);
//    dfs(x,y-1);
//}
//int main()
//{
//    cin>>n>>m;
//    for(int i=0;i<n;i++){
//        cin>>a[i];
//    }
//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++){
//            if(a[i][j]=='W'&&!vis[i][j]){
//                ans++;
//                dfs(i,j);
//            }
//        }
//    }
//    cout<<ans<<endl;
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//const int maxn = 110;
//int n;
//char a[maxn][maxn],b[maxn][maxn];
//bool vis[maxn][maxn];
//char s[]={'0','y','i','z','h','o','n','g'};
//int fc(char c)
//{
//    for(int i=0;i<7;i++){
//        if(c==s[i])return i;
//    }
//    return 10;
//}
//void dfs(int x,int y,char c)
//{
//    if(x<0||y<0||x>=n||y>=n||b[x][y]||fc(a[x][y])!=fc(c)+1)
//        return;
//    if(a[x][y]=='g'){
//        b[x][y]=a[x][y];
//        return;
//    }
//    b[x][y]=a[x][y];
//    char ch=a[x][y];
//    dfs(x+1,y+1,ch);
//    dfs(x+1,y-1,ch);
//    dfs(x-1,y+1,ch);
//    dfs(x-1,y-1,ch);
//    dfs(x+1,y,ch);
//    dfs(x-1,y,ch);
//    dfs(x,y+1,ch);
//    dfs(x,y-1,ch);
//}
//int main()
//{
//    cin>>n;
//    for(int i=0;i<n;i++)cin>>a[i];
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            if(a[i][j]=='y'&&!vis[i][j]){
//                dfs(i,j,'0');
//            }
//        }
//    }
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            if(b[i][j])cout<<b[i][j];
//            else cout<<'*';
//        }
//        cout<<endl;
//    }
//    return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//const int maxn = 110;
//struct node
//{
//    int x,y;
//}c[maxn];
//char a[maxn][maxn],s[]="yizhong";
//int vis[maxn][maxn];
//int dir[][2]={{-1,-1},{-1,0},{0,1},{0,-1},{1,0},{1,1},{1,-1},{-1,1}};
//void dfs(int x,int y,node c[],int k,int cur)
//{
//    if(cur==7){
//        for(int i=0;i<7;i++){
//            vis[c[i].x][c[i].y]=1;
//        }
//        return;
//    }
//    int dx=x+dir[k][0];
//    int dy=y+dir[k][1];
//    if(cur==6||a[dx][dy]==s[cur+1]){
//        c[cur].x=x;c[cur].y=y;
//        dfs(dx,dy,c,k,cur+1);
//    }
//}
//int main()
//{
//    int n;cin>>n;
//    for(int i=0;i<n;i++)cin>>a[i];
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            if(a[i][j]=='y'){
//                for(int k=0;k<8;k++){
//                    int x=i+dir[k][0];
//                    int y=j+dir[k][1];
//                    if(a[x][y]=='i')
//                        dfs(i,j,c,k,0);
//                }
//            }
//        }
//    }
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            if(vis[i][j])cout<<a[i][j];
//            else cout<<'*';
//        }
//        cout<<endl;
//    }
//    return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//int l,r,minn,ans;
//int s[5],a[5][21];
//void dfs(int cur,int i)
//{
//    if(cur>s[i]){
//        minn=min(minn,max(l,r));
//        return;
//    }
//    l+=a[i][cur];
//    dfs(cur+1,i);
//    l-=a[i][cur];
//    r+=a[i][cur];
//    dfs(cur+1,i);
//    r-=a[i][cur];
//}
//int main()
//{
//    cin>>s[1]>>s[2]>>s[3]>>s[4];
//    for(int i=1;i<=4;i++){
//        l = r =0;
//        minn=0x3f3f3f3f;
//        for(int j=1;j<=s[i];j++)
//            cin>>a[i][j];
//        dfs(1,i);
//        ans+=minn;
//    }
//    cout<<ans<<endl;
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//const int maxn = 410;
//int n,m,x,y,a[maxn][maxn];
//bool vis[maxn][maxn];
//void dfs(int curx,int cury,int step)
//{
//
//}
//int main()
//{
//    memset(a,-1,sizeof(a));
//    cin>>n>>m>>x>>y;
//    a[x][y]=0;
//    dfs(x,y,0);
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int n,k,a[25],ans,sum;
//bool vis[25];
//bool is_prime(int n)
//{
//    if(n<2)return false;
//    if(n==2||n==3)return true;
//    if(n%6!=1&&n%6!=5)return false;
//    for(int i=5;i<=(int)sqrt(n);i+=6){
//        if(n%i==0||n%(i+2)==0)
//            return false;
//    }
//    return true;
//}
//void dfs(int cur,int sum,int st)
//{
//    if(cur==k){
//        if(is_prime(sum))
//            ans++;
//        return;
//    }
//    for(int i=st;i<n;i++){
//        dfs(cur+1,sum+a[i],i+1);
//    }
//}
//int main()
//{
//    cin>>n>>k;
//    for(int i=0;i<n;i++)cin>>a[i];
//    dfs(0,0,0);
//    cout<<ans<<endl;
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//struct node
//{
//    int s,b;
//}a[20];
//const int inf = 0x3f3f3f3f;
//int n,ans=inf,s_all=1,b_all;
//void dfs(int cur,int s,int b)
//{
//    if(cur==n){
//        if(s==1&&b==0)return;
//        ans=min(abs(s-b),ans);
//        return;
//    }
//    dfs(cur+1,s*a[cur].s,b+a[cur].b);
//    dfs(cur+1,s,b);
//}
//int main()
//{
//    cin>>n;
//    for(int i=0;i<n;i++){
//        cin>>a[i].s>>a[i].b;
//    }
//    dfs(0,1,0);
//    cout<<ans<<endl;
//    return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//int n,x,ans;
//priority_queue<int,vector<int>,greater<int> > q;
//int main()
//{
//    cin>>n;
//    for(int i=1;i<=n;i++){
//        cin>>x;q.push(x);
//    }
//    while(q.size()>=2){
//        int a=q.top();q.pop();
//        int b=q.top();q.pop();
//        ans+=(a+b);
//        q.push(a+b);
//    }
//    cout<<ans<<endl;
//    return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//int n,a[255];
//string s;
//int main()
//{
//    cin>>s;scanf("%d",&n);
//    int len = s.length();
//    for(int i=0;i<len;i++){
//        a[i]=s[i]-'0';
//    }
//    for(int i=0;i<n;i++){
//        for(int i=0;i<len;i++){
//            if(a[i]>a[i+1]){
//                for(int j=i;j<len;j++){
//                    a[j]=a[j+1];
//                }
//                len--;
//                break;
//            }
//        }
//    }
//    int i=0,l=0;
//    while(a[i]==0&&l<len-1){
//        l++;
//        i++;
//    }
//    for(int i=l;i<len;i++){
//        cout<<a[i];
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int w,n,ans;
//struct point
//{
//    int flag,v;
//}p[100010];
//bool cmp(point a,point b)
//{
//    return a.v>b.v;
//}
//int main()
//{
//    cin>>w>>n;
//    for(int i=0;i<n;i++)
//    {
//        cin>>p[i].v;
//        p[i].flag=1;
//    }
//    sort(p,p+n,cmp);
//    for(int i=0;i<n;i++)
//        cout<<p[i].v<<" ";
//    cout<<endl;
//    int cnt=0;
//    for(int i=0;i<n;i++)
//    {
//        int k=w-p[i].v;
//        for(int j=i+1;j<n;j++)
//        {
//            if(p[j].v<=k&&p[j].flag)
//            {
//                cnt++;
//                p[j].flag=0;
//                break;
//            }
//        }
//    }
//    cout<<n-cnt<<endl;
//    return 0;
//}
//#include<iostream>
//#include<cstring>
//using namespace std;
//const int maxn = 1e5+10;
//struct edge
//{
//    int to,next;
//}edges[maxn];
//int head[maxn],tot;
//void init()
//{
//    memset(head,-1,sizeof(head));
//    tot=1;
//}
//void add_edge(int u,int v)
//{
//    edges[tot]={v,head[u]};
//    head[u]=tot++;
//}
//bool vis[maxn];
//int a[maxn];
//void dfs(int u)
//{
//    vis[u]=true;
//    for(int i=head[u];i!=-1;i=edges[i].next)
//    {
//        int v = edges[i].to;
//        if(!vis[v]){
//            a[u]=max(a[u],v);
//            dfs(v);
//        }
//    }
//}
//int main()
//{
//    int n,m;
//    cin>>n>>m;
//    init();
//    int u,v;
//    for(int i=0;i<m;i++){
//        cin>>u>>v;
//        add_edge(u,v);
//    }
//    for(int i=0;i<n;i++){
//        memset(vis,0,sizeof(vis));
//        dfs(i);
//        cout<<a[i]<<" ";
//    }
//    return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//const int maxn = 1e5+10;
//int n,m,a[maxn];
//vector<int> g[maxn];
//void dfs(int x,int d)
//{
//    if(a[x])return;
//    a[x]=d;
//    for(int i=0;i<g[x].size();i++){
//        dfs(g[x][i],d);
//    }
//}
//int main()
//{
//    int u,v;
//    cin>>n>>m;
//    for(int i=1;i<=m;i++){
//        cin>>u>>v;
//        g[v].push_back(u);
//    }
//    for(int i=n;i;i--)dfs(i,i);
//    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//    cout<<endl;
//    return 0;
//}

//#include<iostream>
//#include<vector>
//#include<cstring>
//using namespace std;
//const int maxn = 1e5+10;
//vector<int> edges[maxn];
//int n,m;
//bool vis[maxn];
//inline void add_edge(int u,int v)
//{
//    edges[u].push_back(v);
//}
//void dfs()
//{
//    for(int i=1;i<=n;i++){
//        if(!vis[i]){
//            for(int j=i;j<edges[i].size();j++){
//                dfs();
//            }
//        }
//    }
//}
//int main()
//{
//    cin>>n>>m;
//    int u,v;
//    for(int i=0;i<m;i++){
//        cin>>u>>v;
//        add_edge(u,v);
//    }
//    dfs();
//    bfs();
//    return 0;
//}
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int maxn = 1e5+10;
//struct edge
//{
//    int u,v;
//};
//vector<edge> a;
//vector<int> e[maxn];
//int n,m;
//bool vis[maxn];
//bool cmp(edge a,edge b)
//{
//    if(a.v==b.v)return a.u<b.u;
//    return a.v<b.v;
//}
//void dfs(int x)
//{
//    vis[x]=1;
//    cout<<x<<" ";
//    for(int i=0;i<e[x].size();i++){
//        int p = a[e[x][i]].v;
//        if(!vis[p]){
//            dfs(p);
//        }
//    }
//}
//void bfs(int x){
//    queue<int> q;
//    q.push(x);
//    cout<<x<<" ";
//    vis[x]=1;
//    while(!q.empty()){
//        int cur=q.front();
//        q.pop();
//        for(int i=0;i<e[cur].size();i++){
//            int p = a[e[cur][i]].v;
//            if(!vis[p]){
//                q.push(p);
//                cout<<p<<" ";
//                vis[p]=1;
//            }
//        }
//    }
//}
//int main()
//{
//    cin>>n>>m;int u,v;
//    for(int i=0;i<m;i++){
//        cin>>u>>v;
//        a.push_back(edge{u,v});
//    }
//    sort(a.begin(),a.end(),cmp);
//    for(int i=0;i<m;i++){
//        e[a[i].u].push_back(i);
//    }
//    dfs(1);
//    cout<<endl;
//    memset(vis,0,sizeof(vis));
//    bfs(1);
//    return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//const int maxn = 1e5+10;
//vector<int> e[maxn];
//int n,m,ans[maxn],vis[maxn];
//void add_edge(int u,int v)
//{
//    e[u].push_back(v);
//}
//int dfs(int u){
//    vis[u]=1;
//    for(int i=0;i<e[u].size();i++){
//        int t = e[u][i];
//        if(!vis[t])
//            ans[u]=max(ans[u],dfs(t));
//    }
//    return ans[u];
//}
//int main()
//{
//    cin>>n>>m;
//    int u,v;
//    for(int i=0;i<m;i++){
//        cin>>u>>v;
//        add_edge(u,v);
//    }
//    for(int i=1;i<=n;i++){
//        dfs(i);
//    }
//    for(int i=1;i<=n;i++){
//        ans[i]=i;
//    }
//    for(int i=1;i<=n;i++){
//        cout<<ans[i];
//        if(i<n)cout<<" ";
//    }
//    return 0;
//}
//
//#include<bits/stdc++.h>
//using namespace std;
//const int maxn = 1e3+10;
//int n,m,ans[maxn][maxn];
//int main()
//{
//    cin>>n>>m;
//    int a,b,c,d;
//    while(m--){
//        cin>>a>>b>>c>>d;
//        ans[a][b]++;
//        ans[a][d+1]--;
//        ans[c+1][b]--;
//        ans[c+1][d+1]++;
//    }
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            ans[i][j]+=ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1];
//            cout<<ans[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//const int maxn = 5e6+10;
//int n,m,a[maxn],b[maxn];
//void merge_sort(int l,int r)
//{
//    if(l==r)return;
//    int m = (l+r)/2;
//    merge_sort(l,m),merge_sort(m+1,r);
//    int i = l,j = m+1,k = l;
//    while(i<=m&&j<=r){
//        if(a[i]>a[j])
//            b[k++]=a[j++];
//        else b[k++]=a[i++];
//    }
//    while(i<=m)b[k++]=a[i++];
//    while(j<=r)b[k++]=a[j++];
//    for(int t=l;t<=r;t++)a[t]=b[t];
//}
//int main()
//{
//    scanf("%d%d",&n,&m);
//    for(int i=0;i<n;i++){
//        scanf("%d",&a[i]);
//    }
//    merge_sort(0,n-1);
//    printf("%d",a[m]);
//    return 0;
//}

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int n,m,a[maxn];
long long ans;
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l = a[0],r = a[n-1];
    while(l<r){
        int mid = (l+r+1)>>1;
        if(a[mid]<=m/2+1) l = mid;
        else r = mid - 1;
    }
    ans = a[l]*a[l-1];
    printf("%lld",ans);
    return 0;
}







