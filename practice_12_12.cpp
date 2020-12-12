//#include<iostream>
//#include<cstdio>
//using namespace std;
//const int inf = 0xffffffff;
//const int maxn = 6e4+10;
//double d[maxn],v[maxn];
//double maxp,minp = inf;
//int n;
//bool check(double m)
//{
//    double l = 0,r = 0;
//
//}
//int main()
//{
//    scanf("%d",&n);
//    for(int i=0;i<n;i++){
//        scanf("%lf",&d[i]);
//        minp = min(minp,d[i]);
//        maxp = max(maxp,d[i]);
//    }
//    for(int i=0;i<n;i++)scanf("%lf",&v[i]);
//    double l = minp,r = maxp;
//    while(l - r >=1e-7){
//        double m = (l + r)/2;
//        if(check(m)) r = m;
//        else l = m;
//        if(l == r) break;
//    }
//    printf("%.12lf",l);
//    return 0;
//}


//#include<iostream>
//using namespace std;
//const int maxn = 50+10;
//char a[maxn][maxn];
//int main()
//{
//    int n,cnt = 0;
//    while(cin>>n&&n){
//        if(cnt++)cout<<endl;
//        cout<<2<<" "<<n<<" "<<n<<endl;
//        for(int i='A';i-'A'<n&&i<='Z';i++){
//            for(int j=0;j<n;j++){
//                a[i-'A'][j]=i;
//            }
//        }
//        for(int i='a';i-'a'<n&&i<='z';i++){
//            for(int j=0;j<n;j++){
//                a[i-'a'+26][j]=i;
//            }
//        }
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
//                cout<<a[i][j];
//            }
//            cout<<endl;
//        }
//        cout<<endl;
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
//                cout<<a[j][i];
//            }
//            cout<<endl;
//        }
//    }
//    return 0;
//}

//#include<iostream>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//const int maxn = 1e6+10;
//int L,D,N,ans;
//struct point
//{
//    int l,r;
//}a[maxn],b[maxn];
//bool cmp(point a,point b)
//{
//    if(a.r==b.r)return a.l>b.l;
//    else return a.r<b.r;
//}
//int main()
//{
//    while(cin>>L>>D>>N){
//        ans = 0;
//        for(int i=0;i<N;i++){
//            cin>>a[i].l>>a[i].r;
//        }
//        for(int i=0;i<N;i++){
//            b[i].l = a[i].l-sqrt(-a[i].r*a[i].r+D*D);
//            b[i].r = a[i].l+sqrt(-a[i].r*a[i].r+D*D);
//        }
//        sort(b,b+N,cmp);
//        int nr = b[0].r;
//        ans++;
//        for(int i=0;i<N;i++){
//            if(b[i].l>nr){
//                ans++;
//                nr = b[i].r;
//            }
//        }
//        cout<<ans<<endl;
//    }
//    return 0;
//}
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int maxn = 5e3+10;
//int n;bool vis1[maxn],vis2[maxn];
//struct node
//{
//    int l,r;
//}a[maxn],b[maxn];
//bool cmp(node a,node b)
//{
//    if(a.l==b.l)return a.r<b.r;
//    else return a.l<b.l;
//}
//int main()
//{
//    while(cin>>n&&n){
//        memset(vis1,0,sizeof(vis1));
//        memset(vis2,0,sizeof(vis2));
//        for(int i=0;i<n;i++){
//            cin>>a[i].l>>b[i].l>>a[i].r>>b[i].r;
//        }
//        sort(a,a+n,cmp);
//        sort(b,b+n,cmp);
//        int row=a[0].l,col=b[0].l;
//        for(int i=0;i<n;i++){
//            if(row>=a[i].l&&row<=a[i].r&&vis1[row]==0){
//                vis1[row]=1;
//                cout<<row++<<" ";
//            }
//            else{
//                cout<<"IMPOSSIBLE"<<endl;
//                continue;
//            }
//            if(col>=b[i].l&&col<=b[i].r&&vis2[col]==0){
//                vis2[col]=1;
//                cout<<col++<<endl;
//            }
//            else{
//                cout<<"IMPOSSIBLE"<<endl;
//            }
//        }
//    }
//    return 0;
//}
//#include<iostream>
//using namespace std;
//const int maxn = 5e3+10;
//struct node
//{
//    int l,r,ans,id;
//}r[maxn],c[maxn];
//bool cmp(node a,node b)
//{
//
//}
//int main()
//{
//    int n;
//    while(cin>>n&&n){
//        int a,b,c,d;
//        for(int i=1;i<=n;i++){
//            cin>>a>>b>>c>>d;
//            r[i].l=b,r[i].r=d;
//            c[i].l=a,c[i].r=c;
//            r[i].id=c[i].id=i;
//        }
//        sort(r+1,r+1+n,cmp);
//        sort(c+1,c+1+n,cmp);
//        set<int> row,col;
//        for(int i=1;i<=n;i++){
//            row.insert(i);
//            col.insert(i);
//        }
//        int i;
//        for(i=1;i<=n;i++){
//            int j;
//            for(j = r[i].r;j>=r[i].l;j--){
//                if(row.find(j)!=row.end()){
//                    r[i]
//                }
//            }
//        }
//    }
//    return 0;
//}
//
//#include<iostream>
//#include<vector>
//using namespace std;
//struct edge
//{
//    int to,next;
//}edge[maxn];
//inline void init()
//{
//    memset(head,-1,sizeof(head));
//    tot = 0;
//}
//inline void add_edge(int u,int v)
//{
//    edge[tot]={v,head[u]};
//    head[u]=tot++;
//}
//
//vector<int> g[maxn];
//inline void add_edge(int u,int v)
//{
//    g[u].push_back(v);
//}
//#include<cstdio>
//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int maxn = 1e5+10;
//struct edge
//{
//    int v,w;
//};
//vector<edge> g[maxn];
//inline void add_edge(int u,int v,int w)
//{
//    g[u].push_back(edge{v,w});
//}
//int main()
//{
//
//    int n,m;
//    scanf("%d%d",&n,&m);
//    int u,v,w;
//    for(int i=0;i<m;i++){
//        scanf("%d%d%d",&u,&v,&w);
//        add_edge(u,v,w);
//        add_edge(v,u,w);
//    }
//    for(int i=0;i<n;i++){
//        for(auto x:g[i]){
//            printf("%d: %d ",x.v,x.w);
//        }
//        cout<<endl;
//    }
//    return 0;
////}
//#include<iostream>
//#include<vector>
//#include<cstring>
//using namespace std;
//const int maxn = 1e5+10;
//struct edge
//{
//    int to,next,w;
//}g[maxn];
//int head[maxn];
//inline void init()
//{
//    tot = 0;
//    memset(head,-1,sizeof(head));
//}
//inline void add_edge(int u,int v)
//{
//    g[tot]={v,w,head[u]};
//    head[u]=tot++;
//}
//int main()
//{
//
//    return 0;
//}
//#include<iostream>
//using namespace std;
//const int maxn = 1e5+10;
//int a[maxn],n,sum;
//bool vis[65535];
//void dfs(int cur)
//{
//    if(cur==1){
//        cout<<1<<" ";
//        return;
//    }
//    sum+=a[cur];
//    if(!vis[1<<sum])
//    {
//        dfs(cur-1);
//        cout<<a[cur]<<" ";
//        sum-=a[cur];
//    }
//}
//int main()
//{
//    for(int i=1;i<=3;i++)a[i]=i;
//    for(int i=1;i<=3;i++){
//        dfs(i);
//    }
//    return 0;
//}

//#include<iostream>
//using namespace std;
//const int maxn = 1e5+10;
//int a[maxn],index,b[maxn];
//void dfs(int start,int pos,int len,int nowlen)
//{
//    if(start>pos){
//        if(nowlen==len){
//            for(int i=1;i<=index;i++){
//                printf("%d ",b[i]);
//            }
//            printf("%d\n",a[pos+1]);
//        }
//        return ;
//    }
//    b[++index]=a[start];
//    dfs(start+1,pos,len,nowlen+1);
//    index--;
//    dfs(start+1,pos,len,nowlen);
//}
//int main()
//{
//    for(int i=1;i<=3;i++)a[i]=i;
//    for(int pos=1;pos<=3;pos++){
//        for(int len=0;len<=pos-1;len++){
//            dfs(1,pos-1,len,0);
//        }
//    }
//    return 0;
//}

//#include<iostream>
//using namespace std;
//int index,a[]={1,2,3},b[3];
//void dfs(int st,int pos,int len,int nlen)
//{
//    if(st>pos){
//        if(nlen==len){
//            for(int i=0;i<index;i++){
//                printf("%d ",b[index]);
//            }
//            printf("%d\n",a[pos]);
//        }
//        return;
//    }
//    b[index++]=a[st-1];
//    dfs(st+1,pos,len,nlen+1);
//    index--;
//    dfs(st+1,pos,len,nlen);
//}
//int main()
//{
//    for(int pos=0;pos<=2;pos++){
//        for(int len=0;len<=pos;len++){
//            dfs(1,pos,len,0);
//        }
//    }
//    return 0;
//}

//#include<iostream>
//using namespace std;
//int cnt,a[10],b[10];
//void dfs(int st,int pos,int len,int nlen)
//{
//    if(st>pos){
//        if(nlen==len){
//            for(int i=1;i<=cnt;i++){
//                printf("%d ",b[i]);
//            }
//            printf("%d\n",a[pos+1]);
//        }
//        return;
//    }
//    b[++cnt]=a[st];
//    dfs(st+1,pos,len,nlen+1);
//    cnt--;
//    dfs(st+1,pos,len,nlen);
//}
//int main()
//{
//    for(int i=1;i<=3;i++)a[i]=i;
//    for(int pos=1;pos<=3;pos++){
//        for(int len=0;len<=pos-1;len++){
//            dfs(1,pos-1,len,0);
//        }
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//int n;
//const int maxn = 5e3+10;
//struct node
//{
//    int l,r,id;
//}a1[maxn],a2[maxn];
//int vis[maxn];
//int b1[maxn],b2[maxn];
//bool cmp(node a,node b)
//{
//    return a.r<b.r;
//}
//int main()
//{
//    while(~scanf("%d",&n)&&n){
//        for(int i=1;i<=n;i++){
//            scanf("%d%d%d%d",&a1[i].l,&a2[i].l,&a1[i].r,&a2[i].r);
//            a1[i].id=a2[i].id=i;
//        }
//        sort(a1+1,a1+1+n,cmp);
//        memset(vis,0,sizeof(vis));
//        bool flag;
//        for(int i=1;i<=n;i++){
//            flag=0;
//            for(int j=1;j<=n;j++){
//                if(!vis[j]&&a1[j].l<=i&&a1[j].r>=i){
//                    vis[j]=1;
//                    b1[a1[j].id]=i;
//                    flag=1;
//                    break;
//                }
//            }
//            if(!flag)break;
//        }
//        if(!flag){
//            printf("IMPOSSIBLE\n");
//            continue;
//        }
//        sort(a2+1,a2+1+n,cmp);
//        memset(vis,0,sizeof(vis));
//        for(int i=1;i<=n;i++){
//            flag=0;
//            for(int j=1;j<=n;j++){
//                if(!vis[j]&&a2[j].l<=i&&a2[j].r>=i){
//                    vis[j]=1;
//                    b2[a2[j].id]=i;
//                    flag=1;
//                    break;
//                }
//            }
//            if(!flag)
//                break;
//        }
//        if(!flag){
//            printf("IMPOSSIBLE\n");
//            continue;
//        }
//        for(int i=1;i<=n;i++){
//            printf("%d %d\n",b1[i],b2[i]);
//        }
//    }
//    return 0;
//}
//


//#include<iostream>
//using namespace std;
//const int maxn = 10;
//char a[maxn][maxn];
//int n,k,ans,num;
//bool vis[maxn];
//void dfs(int cur)
//{
//    if(num==k){
//        ans++;
//        return;
//    }
//    if(cur>n)return;
//    for(int i=1;i<=n;i++){
//        if(!vis[i]&&a[cur][i]=='#'){
//            vis[i]=1;
//            num++;
//            dfs(cur+1);
//            num--;
//            vis[i]=0;
//        }
//    }
//    dfs(cur+1);
//}
//int main()
//{
//    while(cin>>n>>k){
//        if(n==-1&&k==-1)break;
//        for(int i=1;i<=n;i++){
//            for(int j=1;j<=n;j++)
//                cin>>a[i][j];
//        }
//        ans=0,num=0;
//        dfs(1);
//        cout<<ans<<endl;
//    }
//    return 0;
//}

#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 110;
const int inf = (int)1e10;
int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};

char s[maxn][maxn];
int p[maxn][maxn],mark[maxn][maxn][10];
int n,m,ans;
struct mmp
{
    int x,y,t,k,snake;
    bool operator<(const mmp &w)const{
        return t>w.t;
    }
    mmp(int xx,int yy,int tt,int kk,int ss):x(xx),y(yy),t(tt),k(kk),snake(ss){}
};
void bfs(int x,int y)
{
    int i,h;
    priority_queue<mmp> q;
    mmp next = {0,0,0,0,0};
    q.push(mmp(x,y,0,1,0));
    mark[x][y][1]=0;
    while(!q.empty()){
        mmp cur = q.top();
        q.pop();
        if(s[cur.x][cur.y] == 'T'&&cur.k == m+1){
            ans=min(ans,cur.t);
            continue;
        }
        for(i=0;i<4;i++){
            next.x=cur.x + dir[i][0];
            next.y=cur.y+dir[i][1];
            next.t=cur.t+1;
            next.snake=cur.snake;
            next.k=cur.k;
            if(next.x<0||next.x>=n||next.y<0||next.y>=n||s[next.x][next.y]=='#')
            {
                continue;
            }
            if(s[next.x][next.y]=='S'){
                h = p[next.x][next.y];
                if((next.snake&(1<<h))==0){
                    next.snake|=(1<<h);
                    next.t++;
                }
            }
            if(next.k==s[next.x][next.y]-'0'){
                next.k++;
            }
            if(mark[next.x][next.y][next.k]>next.t){
                mark[next.x][next.y][next.k]=next.t;
                q.push(next);
            }
        }
    }
}
int main()
{
    int a,b;
    while(cin>>n>>m&&!(n==0&&m==0))
    {
        memset(p,0,sizeof(p));
        for(int i=0,k=0;i<n;i++){
            cin>>s[i];
            for(int j=0;j<n;j++){
                if(s[i][j]=='k'){
                    a=i,b=j;
                }
                if(s[i][j]=='S'){
                    p[i][j]==k++;
                }
                for(int l=0;l<10;l++){
                    mark[i][j][l]=inf;
                }
            }
        }
        ans=inf;
        bfs(a,b);
        if(ans==inf){
            printf("impossible\n");
        }
        else{
            printf("%d\n",ans);
        }
    }
    return 0;
}













