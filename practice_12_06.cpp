//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=1e4+10;
//const int inf=0x3f3f3f3f;
//int dis[maxn],g[maxn][maxn];
//int n,m,s;
//void floyd()
//{
//    for(int k=1;k<=n;k++)
//        for(int i=1;i<=n;i++)
//            for(int j=1;j<=n;j++)
//            g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
//}
//void init()
//{
//    for(int i=1;i<=n;i++)
//        for(int j=1;j<=n;j++)
//        {
//            if(i==j)g[i][j]=0;
//            else g[i][j]=inf;
//        }
//}
//int main()
//{
//    cin>>n>>m>>s;
//    init();
//    int u,v,w;
//    for(int i=1;i<=m;i++)
//    {
//        cin>>u>>v>>w;
//        g[u][v]=g[v][u]=w;
//    }
//    floyd();
//    for(int i=1;i<=n;i++)
//    {
//        cout<<g[s][i]<<" ";
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<queue>
//#include<vector>
//#include<algorithm>
//using namespace std;
//#define ll long long
//#define pii pair<int,int>
//const int maxn=5e5+10;
//const int inf=0x3f3f3f3f;
//struct node
//{
//    int to,w,next;
//}edge[maxn];
//int head[maxn],cnt,dis[maxn],vis[maxn];
//int n,m,s,t;
//struct Dijkstra
//{
//    void init()
//    {
//        memset(head,-1,sizeof(head));
//        memset(dis,inf,sizeof(dis));
//        memset(vis,0,sizeof(vis));
//        cnt=0;
//    }
//    void add(int u,int v,int w)
//    {
//        edge[cnt].to=v;
//        edge[cnt].w=w;
//        edge[cnt].next=head[u];
//        head[u]=cnt++;
//    }
//    void dijkstra()
//    {
//        priority_queue<pii,vector<pii>,greater<pii>> q;
//        dis[s]=0;q.push({dis[s],s});
//        while(!q.empty())
//        {
//            int cur=q.top().second;
//            q.pop();
//            if(vis[cur])continue;
//            vis[cur]=1;
//            for(int i=head[cur];i!=-1;i=edge[i].next)
//            {
//                int v=edge[i].to;
//                if(!vis[v]&&dis[v]>dis[cur]+edge[i].w)
//                {
//                    dis[v]=dis[cur]+edge[i].w;
//                    q.push({dis[v],v});
//                }
//            }
//        }
//    }
//}dj;
//int main()
//{
//    cin>>n>>m>>s;
//    dj.init();
//    for(int i=1;i<=m;i++)
//    {
//        int u,v,w;
//        cin>>u>>v>>w;
//        dj.add(u,v,w);
//        dj.add(v,u,w);
//    }
//    t=n;
//    dj.dijkstra();
//    for(int i=1;i<=n;i++)
//    {
//        if(dis[i]==inf)
//        {
//            cout<<(1<<32-1)<<" ";
//        }
//        else cout<<dis[i]<<" ";
//    }
//    return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//const int maxn=1e4+10;
//const int maxm=5e5+10;
//const int inf=2147483647;
//int n,m,s,num_edge=0;
//int dis[maxn],vis[maxn],head[maxm];
//struct Edge
//{
//    int next,to,dis;
//}edge[maxm];
//void add(int from,int to,int dis)
//{
//    edge[++num_edge].next=head[from];
//    edge[num_edge].to=to;
//    edge[num_edge].dis=dis;
//    head[from]=num_edge;
//}
//void spfa()
//{
//    queue<int> q;
//    for(int i=1;i<=n;i++)
//    {
//        dis[i]=inf;
//        vis[i]=0;
//    }
//    q.push(s);dis[s]=0;vis[s]=1;
//    while(!q.empty())
//    {
//        int cur=q.front();
//        q.pop();
//        vis[cur]=0;
//        for(int i=head[cur];i;i=edge[i].next)
//        {
//            int next=edge[i].to;
//            if(dis[next]>dis[cur]+edge[i].dis)
//            {
//                dis[next]=dis[cur]+edge[i].dis;
//                if(!vis[next])
//                {
//                    vis[next]=1;
//                    q.push(next);
//                }
//            }
//        }
//    }
//}
//int main()
//{
//    cin>>n>>m>>s;
//    for(int i=1;i<=m;i++)
//    {
//        int f,g,w;
//        cin>>f>>g>>w;
//        add(f,g,w);
//    }
//    spfa();
//    for(int i=1;i<=n;i++)
//    {
//        if(s==i)cout<<0<<" ";
//        else cout<<dis[i]<<" ";
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define pii pair<int,int>
//const int maxn=1e5+10;
//const int maxm=2e5+10;
//const int inf=2147483647;
//struct Edge
//{
//    int next,to;
//    ll dis;
//}edge[maxm];
//int n,m,s,cnt,dis[maxn],head[maxm];
//bool vis[maxn];
//void add(int f,int t,int dis)
//{
//    edge[++cnt].next=head[f];
//    edge[cnt].to=t;
//    edge[cnt].dis=dis;
//    head[f]=cnt;
//}
//void spfa()
//{
//    priority_queue<pii,vector<pii>,greater<pii> > q;
//    memset(dis,inf,sizeof(dis));
//    memset(vis,0,sizeof(vis));
//    dis[s]=0;vis[s]=1;q.push({dis[s],s});
//    while(!q.empty())
//    {
//        int cur=q.top().second;
//        q.pop();
//        vis[cur]=0;
//        for(int i=head[cur];i;i=edge[i].next)
//        {
//            int next=edge[i].to;
//            if(dis[next]>dis[cur]+edge[i].dis)
//            {
//                dis[next]=dis[cur]+edge[i].dis;
//                if(!vis[next]){
//                    vis[next]=1;
//                    q.push({dis[next],next});
//                }
//            }
//        }
//
//    }
//}
//int main()
//{
//    cin>>n>>m>>s;
//    for(int i=1;i<=m;i++)
//    {
//        int f,g,w;
//        cin>>f>>g>>w;
//        add(f,g,w);
//    }
//    spfa();
//    for(int i=1;i<=n;i++)
//    {
//        if(s==i)cout<<0<<" ";
//        else cout<<dis[i]<<" ";
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//char c,s[25*2500+10];
//int ans1,ans2,cnt;
//int main()
//{
//    while(cin>>c)
//    {
//        if(c=='E')break;
//        else s[cnt++]=c;
//    }
//    cnt=0;
//    while(1)
//    {
//        if(s[cnt++]=='W'){
//            ans1++;
//        }
//        else if(s[cnt]=='L')
//            ans2++;
//        if((ans1==11||ans2==11)&&abs(ans1-ans2)>=2)
//            {
//                cout<<ans1<<":"<<ans2<<endl;
//                ans1=0,ans2=0;
//            }
//    }
//    cout<<ans1<<":"<<ans2<<endl<<endl;
//    cnt=0,ans1=0,ans2=0;
//    while(1)
//    {
//        if(s[cnt++]=='W')
//        {
//            ans1++;
//        }
//        else if(s[cnt]=='L'){
//            ans2++;
//        }
//        if((ans1==21||ans2==21)&&abs(ans1-ans2)>=2)
//            {
//                cout<<ans1<<":"<<ans2<<endl;
//                ans1=0,ans2=0;
//            }
//    }
//    cout<<ans1<<":"<<ans2<<endl;
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=1e5+10;
//struct peo
//{
//    int dir;
//    char name[15];
//}a[maxn];
//int n,m,ans=1,b,s;
//int main()
//{
//    cin>>n>>m;
//    for(int i=1;i<=n;i++)cin>>a[i].dir>>a[i].name;
//    for(int i=1;i<=m;i++){
//        cin>>b>>s;
//        if(a[ans].dir^b){
//            if((ans+s)%n==0)ans=n;
//            else ans=(ans+s)%n;
//        }
//        else{
//            if(ans-s==0)ans=n;
//            else ans=(ans-s+n)%n;
//        }
//    }
//    cout<<a[ans].name<<endl;
//    return 0;
//}
//
//
//#include<bits/stdc++.h>
//using namespace std;
//int a[550],b[550],len;
//int main()
//{
//    string str1,str2;
//    memset(a,0,sizeof(a));
//    memset(b,0,sizeof(b));
//    cin>>str1>>str2;
//    a[0]=str1.length();
//    for(int i=1;i<=a[0];i++)
//    {
//        a[i]=str1[a[0]-i]-'0';
//    }
//    b[0]=str2.length();
//    for(int i=1;i<=b[0];i++)
//        b[i]=str2[b[0]-i]-'0';
//    len=max(b[0],a[0]);
//    for(int i=1;i<=len;i++)
//    {
//        a[i]+=b[i];
//        a[i+1]+=a[i]/10;
//        a[i]%=10;
//    }
//    len++;
//    while((a[len]==0)&&(len>1))len--;
//    for(int i=len;i>=1;i--)
//        cout<<a[i];
//    return 0;
//}
//


//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=2010;
//int len,flag1,flag2,a[maxn],b[maxn],c[maxn<<1];
//int main()
//{
//    string str1,str2;
//    cin>>str1>>str2;
//    a[0]=str1.length();
//    b[0]=str2.length();
//    if(str1[0]=='-'){
//        flag1=-1;
//        for(int i=1;i<a[0];i++)
//        a[i]=str1[a[0]-i]-'0';
//        a[0]--;
//    }
//    else{
//        for(int i=1;i<=a[0];i++)
//        a[i]=str1[a[0]-i]-'0';
//        flag1=1;
//    }
//    if(str2[0]=='-'){
//        flag2=-1;
//        for(int i=1;i<b[0];i++)
//        b[i]=str2[b[0]-i]-'0';
//        b[0]--;
//    }
//    else{
//        flag2=1;
//        for(int i=1;i<=b[0];i++)
//        b[i]=str2[b[0]-i]-'0';
//    }
//    for(int i=1;i<=a[0];i++)
//    {
//        for(int j=1;j<=b[0];j++)
//        {
//            c[i+j-1]+=a[i]*b[j];
//            c[i+j]+=c[i+j-1]/10;
//            c[i+j-1]%=10;
//        }
//    }
//        len=a[0]+b[0]+1;
//        while((c[len]==0)&&(len>1))len--;
//        if(flag1*flag2==-1)
//            cout<<"-";
//        for(int i=len;i>=1;i--)
//        {
//            cout<<c[i];
//        }
//        return 0;
//    }
//

//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=2010;
//string str1,str2;
//int N,len,a[maxn],b[maxn],c[maxn<<1];
//string ans="0";
//string add(string s1,string s2)
//{
//    string e;
//    memset(a,0,sizeof(a));
//    memset(b,0,sizeof(a));
//    a[0]=s1.length();
//    b[0]=s2.length();
//    for(int i=1;i<=a[0];i++)
//        a[i]=str1[a[0]-i]-'0';
//    for(int i=1;i<=b[0];i++)
//        b[i]=str2[b[0]-i]-'0';
//    len=max(a[0],b[0]);
//    for(int i=1;i<=len;i++)
//    {
//        a[i]+=b[i];
//        a[i+1]+=a[i]/10;
//        a[i]%=10;
//    }
//    len++;
//    while(a[len]==0&&len>1)len--;
//    for(int i=len;i>=1;i--)
//        e[len-i]=a[i];
//    return e;
//}
//string sub(string s1)
//{
//    string e;
//    memset(a,0,sizeof(a));
//    memset(b,0,sizeof(b));
//    a[0]=s1.length();
//    for(int i=1;i<=a[0];i++)
//        a[i]=s1[a[0]-i]-'0';
//    int i=1;
//    while(1)
//    {
//        if(a[i]-1<0)
//        {
//            a[i]=9;
//            a[i+1]--;
//            i++;
//        }
//        else
//        {
//            a[i]--;
//            break;
//        }
//    }
//    len=a[0];
//    while(a[len]==0&&len>1)len--;
//    for(int i=len;i>=1;i--)
//        e[len-i]=a[i];
//    return e;
//}
//string mul(string s1,string s2)
//{
//    string e;
//    memset(a,0,sizeof(a));
//    memset(b,0,sizeof(b));
//    memset(c,0,sizeof(c));
//    a[0]=s1.length();
//    b[0]=s2.length();
//    for(int i=1;i<=a[0];i++)
//        a[i]=s1[a[0]-i]-'0';
//    for(int i=1;i<=b[0];i++)
//        b[i]=s2[b[0]-i]-'0';
//    for(int i=1;i<=a[0];i++)
//    {
//        for(int j=1;j<=b[0];j++)
//        {
//            c[i+j-1]+=a[i]*b[j];
//            c[i+j]+=c[i+j-1]/10;
//            c[i+j-1]%=10;
//        }
//    }
//    len=a[0]+b[0]+1;
//    while(a[len]==0&&len>1)len--;
//    for(int i=len;i>=1;i--)
//        e[len-i]=c[i];
//    return e;
//}
//string fun(string s)
//{
//    if(!s.compare("1"))
//        return s;
//    return mul(s,fun(sub(s)));
//}
//int main()
//{
//    cin>>N;
//    for(int i=1;i<=N;i++)
//    {
//        string tmp;int cnt=0;
//        while(i)
//        {
//            tmp[cnt++]=i%10+'0';
//            i/=10;
//        }
//        for(int i=0;i<tmp.length()/2;i++)swap(tmp[i],tmp[tmp.length()-i-1]);
//        add(ans,fun(tmp));
//    }
//    for(int i=ans.length();i>=1;i++)
//        cout<<ans[i];
//    return 0;
//}
//
//
//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=2010;
//int a[maxn],b[maxn],n;
//bool flag;
//void mul(int* a,int b)
//{
//    int jw=0;
//    for(int i=1;i<=1000;i++)
//    {
//        a[i]=a[i]*b+jw;
//        jw=a[i]/10;
//        a[i]%=10;
//    }
//
//}
//void add(int* b,int* a)
//{
//    int jw=0;
//    for(int i=1;i<=1000;i++)
//    {
//        b[i]=b[i]+a[i]+jw;
//        jw=b[i]/10;
//        b[i]%=10;
//    }
//}
//int main()
//{
//    cin>>n;
//    a[1]=1;
//    for(int i=1;i<=n;i++)
//    {
//        mul(a,i);
//        add(b,a);
//    }
//    for(int i=1000;i>=1;i--)
//    {
//        if(b[i])flag=1;
//        if(flag)cout<<b[i];
//    }
//    return 0;
//}
//
//#include<iostream>
//#include<set>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int maxn=5e4+10;
//int num,a[maxn],cnt,n,m,fa[maxn],siz[maxn];
//
//void init(int i)
//{
//    fa[i]=i;
//    siz[i]=1;
//}
//int Find(int i)
//{
//    if(fa[i]==i)return fa[i];
//    return Find(fa[i]);
//}
//void join(int x,int y)
//{
//    x=Find(x),y=Find(y);
//    if(x==y)return;
//    if(siz[x]>siz[y])fa[y]=x;
//    else{
//        if(siz[x]==siz[y])siz[y]++;
//        fa[x]=y;
//    }
//}
//bool fun(int k,int a[])
//{
//    for(int i=0;i<cnt;i++)
//    {
//        if(a[i]==k)
//            return false;
//    }
//    return true;
//}
//int main()
//{
//    while(cin>>n>>m&&n&&m){
//        num++;
//        for(int i=1;i<=n;i++)init(i);
//        while(m--){
//            int x,y;
//            cin>>x>>y;
//            join(x,y);
//        }
//        cnt=0;memset(a,0,sizeof(a));
//        for(int i=1;i<=n;i++){
//            if(fun(Find(i),a)){
//                a[cnt++]=Find(i);
//            }
//        }
//        printf("Case %d: %d\n",num,cnt);
//    }
//    return 0;
//}

//#include<iostream>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//const int maxn=1010;
//int n,m,fa[maxn],siz[maxn];
//struct computer
//{
//    int flag,x,y;
//}c[maxn];
//void init(int i)
//{
//    fa[i]=i;
//    siz[i]=1;
//    c[i].flag=0;
//}
//int  Find(int i)
//{
//    if(fa[i]==i)return i;
//    return Find(fa[i]);
//}
//void join(int x,int y)
//{
//    x=Find(x),y=Find(y);
//    if(x==y)return ;
//    if(siz[x]>siz[y])fa[y]=x;
//    else{
//        if(siz[x]==siz[y])siz[y]++;
//        fa[x]=y;
//    }
//}
//int main()
//{
//    cin>>n>>m;
//    for(int i=1;i<=n;i++){
//        cin>>c[i].x>>c[i].y;
//    }
//    for(int i=1;i<=n;i++)init(i);
//    char ch;
//    while(cin>>ch)
//    {
//        if(ch=='0'){
//            int x;cin>>x;
//            c[x].flag=1;
//            for(int i=1;i<=n;i++)
//            {
//                if(i==x)continue;
//                if(c[i].flag&&(pow(c[i].x-c[x].x,2)+pow(c[i].y-c[x].y,2)<=m*m))
//                    join(x,i);
//            }
//        }
//        else{
//            int x,y;
//            cin>>x>>y;
//            if(Find(x)==Find(y))cout<<"SUCCESS"<<endl;
//            else cout<<"FAIL"<<endl;
//        }
//    }
//    return 0;
//}
//#include<iostream>
//using namespace std;
//const int maxn=3e4+10;
//int n,m,ans,k,fa[maxn],siz[maxn];
//void init(int i)
//{
//    fa[i]=i;
//    siz[i]=1;
//}
//int Find(int i)
//{
//    if(fa[i]==i)return fa[i];
//    return Find(fa[i]);
//}
//void join(int x,int y)
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
//    while(cin>>n>>m&&(!n&&!m)){
//        ans=0;
//        for(int i=0;i<n;i++)init(i);
//        while(m--)
//        {
//            cin>>k;
//            int x,y;
//            cin>>x;k--;
//            while(k--)
//            {
//                cin>>y;
//                join(x,y);
//            }
//        }
//        for(int i=0;i<n;i++){
//            if(Find(i)==Find(0))ans++;
//        }
//        cout<<ans<<endl;
//    }
//    return 0;
//}


//#include<iostream>
//using namespace std;
//const int maxn=2e3+10;
//int fa[maxn],num=0,siz[maxn];
//struct node
//{
//    int x,y;
//}a[maxn];
//void init(int i)
//{
//    fa[i]=i;
//    siz[i]=1;
//}
//int Find(int i)
//{
//    if(fa[i]==i)return fa[i];
//    return Find(fa[i]);
//}
//int main()
//{
//    for(int i=1;i<=maxn;i++)init(i);
//    int x,y;
//    int cnt=1;
//    while(1){
//        cin>>x>>y;
//        if(x==-1&&y==-1)break;
//        if(x&&y)
//        a[num++].x=x,a[num].y=y;
//        else{
//            int flag=1;
//            while(num--){
//                if(fa[a[num].y]!=a[num].y&&a[num].y!=a[num].x){
//                    cout<<"Case "<<cnt++<<" is not a tree."<<endl;
//                    flag=0;
//                    for(int i=1;i<=maxn;i++)init(i);
//                    num=0;break;
//                }
//                fa[a[num].y]=a[num].x;
//            }
//            if(flag){
//                cout<<"Case "<<cnt++<<" is a tree."<<endl;
//                for(int i=1;i<=maxn;i++)init(i);
//            }
//        }
//    }
//    return 0;
//}
//
//#include<iostream>
//using namespace std;
//const int maxn=2e3+10;
//int fa[maxn],siz[maxn];
//bool ap[maxn];
//int main()
//{
//    int x,y,cas=0;
//    while(1){
//        cas++;
//        for(int i=1;i<=maxn;i++){
//            fa[i]=i;siz[i]=1;ap[i]=0;
//        }
//        int x,y;
//        bool flag=0;
//        bool vis=1;
//        while(cin>>x>>y){
//            if(x==-1&&y==-1){
//                break;
//            }
//            if(!x&&!y){
//                flag=1;
//                break;
//            }
//            ap[x]=ap[y]=1;
//            if(fa[y]!=y)vis=0;
//            else fa[y]=x;
//        }
//        if(!flag)break;
//        int rt=0;
//        for(int i=1;i<=maxn;i++){
//            if(ap[i]&&fa[i]==i)rt++;
//        }
//        if(rt>1||(!vis))cout<<"Case "<<cas<<" is not a tree."<<endl;
//        else cout<<"Case "<<cas<<" is a tree."<<endl;
//    }
//    return 0;
//}

#include<iostream>
using namespace std;
const int maxn = 2e5+10;
int n,m,fa[maxn],siz[maxn];
int main()
{

    return 0;
}









