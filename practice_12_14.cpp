//#include<iostream>
//using namespace std;
//int main()
//{
//    int t;cin>>t;
//    char a[50];
//    while(t--){
//        cin>>a;
//        int i=0;
//        while(a[i++]);
//        cout<<i-1<<endl;
//    }
//    return 0;
//}
//#include<iostream>
//using namespace std;
//int f(int x,int y){
//    if(x>=1&&x<=5&&y>=1&&y<=5)return 1;
//    return -1;
//}
//int main()
//{
//    int t;cin>>t;
//    int x,y;
//    while(t--){
//        cin>>x>>y;
//        if(f(x,y)==1)cout<<"in"<<endl;
//        else cout<<"out"<<endl;
//    }
//    return 0;
//}
//
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//    string a,b;
//    int t;cin>>t;
//    while(t--){
//        cin>>a>>b;
//        for(int i=0;i<3;i++)cout<<a[i];
//        for(int i=b.length()-3;i<=b.length()-1;i++)cout<<b[i];
//        cout<<endl;
//    }
//    return 0;
//}

//#include<stdio.h>
//#include<assert.h>
//char* my_strcpy(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(src != NULL);
//	assert(dest != NULL);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[50],arr2[50];
//	int t;scanf("%d",&t);
//	while(t--){
//        scanf("%s%s",arr1,arr2);
//        printf("%s\n", my_strcpy(arr1, arr2));
//	}
//
//	return 0;
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
//    int cnt=0;
//    for(int i=0;i<n;i++)
//    {
//        if(!p[i].flag)continue;
//        cnt++;
//        p[i].flag=0;
//        int k=w-p[i].v;
//        for(int j=i+1;j<n;j++)
//        {
//            if(p[j].v<=k&&p[j].flag)
//            {
//                p[j].flag=0;
//                break;
//            }
//        }
//    }
//    cout<<cnt<<endl;
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<map>
//using namespace std;
//const int maxn = 1e5+10;
//map<int,int> m;
//typedef map<int,int>::iterator it;
//int n,ans=0x3f3f3f3f;
//int main()
//{
//    cin>>n;int t;
//    for(int i=0;i<n;i++){
//        scanf("%d",&t);
//        m[t]++;
//    }
//    while(!m.empty()){
//        it i = m.begin(),j = m.begin();
//        (*i).second--;
//        int t = 1;
//        for(++j;j!=m.end()&&(*j).first==(*i).first+1&&(*j).second>(*i).second;i++,j++){
//            t++;
//            (*j).second--;
//        }
//        i = m.begin();
//        while(i!=m.end()&&(*i).second==0){
//            m.erase((*i++).first);
//        }
//        ans = min(ans,t);
//
//    }
//    printf("%d\n",ans);
//    return 0;
//}
//#include<iostream>
//#include<stack>
//#include<algorithm>
//using namespace std;
//const int maxn = 1e5+10;
//stack<int> st[maxn];
//int a[maxn],n,top;
//int main()
//{
//    scanf("%d",&n);
//    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
//    sort(a+1,a+n+1);
//    int flag = 0;
//    for(int i=1;i<=n;i++){
//        for(int j=top;j>0;j--){
//            if(st[j].top()+1==a[i]){
//                st[j].push(a[i]);
//                flag=1;
//                break;
//            }
//            flag=0;
//        }
//        if(!flag){
//            st[++top].push(a[i]);
//        }
//    }
//    int minn = 0x3f3f3f3f;
//    for(int i=1;i<=top;i++){
//        int t = st[i].size();
//        minn = min(minn,t);
//    }
//    printf("%d\n",minn);
//    return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//const int maxn = 201;
//int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
//int n,m,a[maxn][maxn],s[maxn][maxn],ans;
//int dfs(int x,int y)
//{
//    if(s[x][y])return s[x][y];
//    s[x][y]=1;
//    for(int i=0;i<4;i++){
//        int tx = x+d[i][0];
//        int ty = y + d[i][1];
//        if(tx>0&&ty>0&&tx<=n&&ty<=m&&a[x][y]>a[tx][ty]){
//            dfs(tx,ty);
//            s[x][y]=max(s[x][y],s[tx][ty]+1);
//        }
//    }
//    return s[x][y];
//}
//int main()
//{
//    scanf("%d%d",&n,&m);
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            scanf("%d",&a[i][j]);
//        }
//    }
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            ans = max(ans,dfs(i,j));
//        }
//    }
//    printf("%d",ans);
//    return 0;
//}
//
//#include<bits/stdc++.h>
//using namespace std;
//const int maxn = 25;
//bool f[maxn][maxn];
//int a[maxn],p[maxn],ans[maxn],cnt;
//bool b[maxn];
//int n,maxx;
//bool check(int x){
//    for(int i=x+1;i<=n;i++){
//        if(f[x][i]&&!b[i])return false;
//    }
//    return true;
//}
//void dfs(int x,int stp,int sum){
//    if(check(x)){
//        if(maxx<sum){
//            maxx=sum;
//            cnt=stp;
//            for(int i=1;i<=stp;i++){
//                ans[i]=p[i];
//            }
//        }
//        return;
//    }
//    for(int i=1;i<=n;i++){
//        if(f[x][i]&&!b[i]){
//            b[i]=1;
//            p[stp+1]=i;
//            dfs(i,stp+1,sum+a[i]);
//            b[i]=0;//»ØËÝ
//        }
//    }
//}
//int main()
//{
//    cin>>n;
//    for(int i=1;i<=n;i++)cin>>a[i];
//    for(int i=1;i<n;i++){
//        for(int j=i+1;j<=n;j++){
//            cin>>f[i][j];
//        }
//    }
//    for(int i=1;i<=n;i++){
//        b[i]=1;p[1]=i;
//        dfs(i,1,a[i]);
//        b[i]=0;
//    }
//    for(int i=1;i<=cnt;i++){
//        cout<<ans[i]<<" ";
//    }
//    cout<<endl<<maxx<<endl;
//    return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//const int maxn = 25;
//int n,a[maxn],pos;
//bool f[maxn][maxn];
//int m[maxn],p[maxn],dp[maxn],ans;
//void dfs(int i){
//    if(p[i]==0){
//        cout<<i;
//        return;
//    }
//    dfs(p[i]);
//    cout<<" "<<i;
//}
//int main()
//{
//    cin>>n;
//    for(int i=1;i<=n;i++)
//        cin>>m[i];
//    for(int i=1;i<n;i++)
//        for(int j=i+1;j<=n;j++)
//        cin>>f[i][j];
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            if(f[j][i]){
//                dp[i]=max(dp[j],dp[i]);
//                if(dp[i]==dp[j])p[i]=j;
//            }
//        }
//        dp[i]+=m[i];
//        ans=max(ans,dp[i]);
//        if(ans==dp[i])pos=i;
//    }
//    dfs(pos);
//    cout<<endl<<ans<<endl;
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//const int mod = 80112002;
//const int maxn = 5e3+10;
//bool f[maxn][maxn];
//int n,m,dp[maxn],ans;
//int main()
//{
//    scanf("%d%d",&n,&m);
//    int a,b;
//    for(int i=0;i<m;i++){
//        scanf("%d%d",&a,&b);
//        f[a][b]=1;
//    }
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            if(f[j][i]){
//                dp[i]=max(dp[i],(dp[j]+1)%mod);
//            }
//        }
//        ans=max(ans,dp[i]);
//    }
//    printf("%d",(ans+1)%mod);
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//const int maxn = 410;
//const int inf = 0x3f3f3f3f;
//int n,m,stx,sty,a[maxn][maxn];
//bool vis[maxn][maxn];
//int dir[][2]={{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};
//void dfs(int x,int y,int step,int dx,int dy)
//{
//    if(x==dx&&y==dy){
//        a[dx][dy]=min(step,a[dx][dy]);
//        return ;
//    }
//    for(int i=0;i<8;i++){
//        int tx = x+dir[i][0];
//        int ty = y+dir[i][1];
//        if(tx>n||ty>m||tx<=0||ty<=0||vis[tx][ty])continue;
//        vis[tx][ty]=1;
//        dfs(tx,ty,step+1,dx,dy);
//        vis[tx][ty]=0;
//    }
//}
//int main()
//{
//    cin>>n>>m>>stx>>sty;
//    memset(a,inf,sizeof(a));
//    a[stx][sty]=0;
//    vis[stx][sty]=1;
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=m;j++){
//            if(i==stx&&j==sty)continue;
//            dfs(stx,sty,0,i,j);
//        }
//    }
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=m;j++){
//            if(a[i][j]==inf)cout<<-1;
//            else cout<<a[i][j];
//            if(j<=m-1)cout<<' ';
//        }
//        cout<<endl;
//    }
//    return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//const int maxn = 410;
//int stx,sty,n,m,a[maxn][maxn];
//bool vis[maxn][maxn];
//struct node
//{
//    int x,y,st;
//};
//int dir[][2]={{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};
//bool check(int x,int y)
//{
//    if(x<=0||y<=0||x>n||y>m||vis[x][y]){
//        return false;
//    }
//    return true;
//}
//int bfs(int dx,int dy)
//{
//    queue<node> q;
//    node cur,next;
//    cur.x = stx,cur.y = sty;
//    cur.st = 0;
//    q.push(cur);
//    vis[cur.x][cur.y]=1;
//    while(!q.empty()){
//        cur = q.front();
//        q.pop();
//        if(cur.x == dx&&cur.y == dy)return cur.st;
//        for(int i = 0;i < 8;i++){
//            next.x = cur.x + dir[i][0];
//            next.y = cur.y + dir[i][1];
//            if(check(next.x,next.y)){
//                vis[next.x][next.y]=1;
//                next.st = cur.st + 1;
//                q.push(next);
//            }
//        }
//    }
//    return -1;
//}
//int main()
//{
//    scanf("%d%d%d%d",&n,&m,&stx,&sty);
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=m;j++){
//            memset(vis,0,sizeof(vis));
//            a[i][j]=bfs(i,j);
//        }
//    }
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=m;j++){
//            printf("%-5d",a[i][j]);
//        }
//        puts("");
//    }
//    return 0;
//}
//#include<iostream>
//#include<cstring>
//using namespace std;
//const int maxm = 2e3+10;
//const int maxn = 510;
//int f[maxn],r[maxn];int n,m;
//int find_f(int i){
//    if(f[i]==i)return i;
//    int t = f[i];
//    f[i]=find_f(f[i]);
//    r[i]=(r[i]+r[t])%3;
//    return f[i];
//}
//void join(int a,int b,int t){
//    int fa = find_f(a);
//    int fb = find_f(b);
//    if(fa!=fb){
//        f[fb]=fa;
//        r[fb]=(3*3-r[b]+r[a]-t)%3;
//    }
//}
//void init(){
//    for(int i=0;i<n;i++){
//        f[i]=i,r[i]=0;
//    }
//}
//struct cmmand
//{
//    int a,t,b;
//}coms[maxm];
//bool judge[maxn];
//int pos[maxn];
//int main()
//{
//
//    while(cin>>n>>m){
//        for(int i=0;i<m;i++){
//            char c;
//            cin>>coms[i].a>>c>>coms[i].b;
//            if(c=='=')coms[i].t=0;
//            else if(c=='>')coms[i].t=1;
//            else if(c=='<')coms[i].t=2;
//        }
//        memset(pos,-1,sizeof(pos));
//        memset(judge,1,sizeof(judge));
//        for(int i=0;i<n;i++){
//            init();
//            for(int j=0;j<m;j++){
//                int a,b,t;
//                a=coms[j].a,b=coms[j].b;
//                t = coms[j].t;
//                if((a==i||b==i))continue;
//                else{
//                    int fa = find_f(a);
//                    int fb = find_f(b);
//                    if(fa==fb){
//                        if((r[b]+t)%3!=r[a]){
//                            judge[i]=false;
//                            pos[i]=j+1;
//                            break;
//                        }
//                    }
//                    else{
//                        join(a,b,t);
//                    }
//                }
//            }
//        }
//        int tot=0,judge_i,max_p=0;
//        for(int i=0;i<n;i++){
//            if(judge[i]){
//                tot++;
//                judge_i=i;
//            }
//            else max_p=max(max_p,pos[i]);
//        }
//        if(tot==0)printf("Impossible\n");
//        else if(tot==1)printf("Player %d can be determined to be the judge after %d lines\n",judge_i,max_p);
//        else printf("Can not determine\n");
//    }
//    return 0;
//}
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int n,m,k;string s;char ans[maxn];
long long mid;
int main()
{
    cin>>n>>s>>m;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]>='0'&&s[i]<='9') mid=mid*n+s[i]-'0';
        else if(s[i]>='A'&&s[i]<='Z') mid=mid*n+s[i]-'A'+10;
    }
    while(mid){
        if(mid%m<10)
        ans[k++]=mid%m+'0';
        else ans[k++]=mid%m-10+'A';
        mid/=m;
    }
    for(int i=k-1;i>=0;i--){
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}








