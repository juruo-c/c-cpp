//#include<iostream>
//using namespace std;
//const int maxn = 2e5+10;
//int fa[maxn],sum[maxn];
//void init(int i)
//{
//    fa[i]=i;
//    sum[i]=0;
//}
//int Find(int i)
//{
//   if(fa[i]!=i){
//        int tmp=fa[i];
//        fa[i]=Find(fa[i]);
//        sum[i]+=sum[tmp];
//   }
//   return fa[i];
//}
//int n,m,ans;
//int main()
//{
//    while(cin>>n>>m)
//    {
//        ans=0;
//        for(int i=0;i<=n;i++)init(i);
//        while(m--){
//            int l,r,v;
//            cin>>l>>r>>v;
//            l--;
//            int fl=Find(l),fr=Find(r);
//            if(fl==fr){
//                if((sum[l]-sum[r])!=v)ans++;
//            }
//            else{
//                fa[fl]=fr;
//                sum[fl]=-sum[l]+sum[r]+v;
//            }
//        }
//        cout<<ans<<endl;
//    }
//    return 0;
//}
//#include<iostream>
//using namespace std;
//int n,m,a[20][20],b[20][20];
//int main()
//{
//    cin>>n>>m;
//    for(int i=1;i<=n;i++)
//        for(int j=1;j<=m;j++)
//        cin>>a[i][j];
//    for(int i=1;i<=n;i++)
//        for(int j=1;j<=m;j++)
//        cin>>b[i][j];
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=m;j++){
//            cout<<a[i][j]+b[i][j];
//            if(j<m)cout<<" ";
//        }
//        cout<<endl;
//    }
//    return 0;
//}

//#include<iostream>
//using namespace std;
//int a[4][4];
//int main()
//{
//    for(int i=1;i<=3;i++){
//        for(int j=1;j<=3;j++){
//            cin>>a[i][j];
//        }
//    }
//    cout<<a[1][1]+a[2][2]+a[3][3]<<" ";
//    cout<<a[1][3]+a[2][2]+a[3][1]<<endl;
//    return 0;
//}

//#include<iostream>
//using namespace std;
//const int maxn = 5e4+10;
//int n,k,ans,fa[maxn],siz[maxn],ap[maxn];
//int main()
//{
//    cin>>n>>k;
//    for(int i=1;i<=n;i++){
//        fa[i]=i;
//        siz[i]=1;
//    }
//    while(k--)
//    {
//        int d;cin>>d;
//        int x,y;cin>>x>>y;
//        if(x>n||y>n){
//            ans++;
//            continue;
//        }
//        if(d==1){
//            if(ap[x]&&ap[y]){
//                if(Find(x)!=Find(y)){
//                    ans++;
//                }
//            }
//            else{
//                ap[x]=ap[y]=1;
//                join(x,y);
//            }
//        }
//        else{
//            if(x==y){
//                ans++;
//                continue;
//            }
//            if(ap[x]&&ap[y]){
//                if(Find(x)==Find(y)){
//                    ans++;
//                }
//                else{
//
//                }
//            }
//            else{
//                int fx=Find(x);
//                int fy=Find(y);
//            }
//        }
//    }
//    return 0;
//}

//#include<iostream>
//#include<stdio.h>
//using namespace std;
//const int maxn = 5e4+10;
//int n,k,d,ans,fa[maxn*3];
//int Find(int i){
//    if(fa[i]==i)return fa[i];
//    fa[i]=Find(fa[i]);
//    return fa[i];
//}
//void Union(int x,int y){
//    x=Find(x),y=Find(y);
//    if(x!=y){
//        fa[x]=y;
//    }
//}
//int main()
//{
//    scanf("%d%d",&n,&k);
//    for(int i=1;i<=3*n;i++)fa[i]=i;
//    while(k--){
//        scanf("%d",&d);
//        int x,y;scanf("%d%d",&x,&y);
//        if(x>n||y>n||(d==2)&&(x==y)){
//            ans++;
//            continue;
//        }
//        if(d==1){
//            if(Find(x)==Find(2*n+y)||Find(y)==Find(2*n+x)){
//                ans++;
//                continue;
//            }
//            Union(x,y);
//            Union(x+n,y+n);
//            Union(x+2*n,y+2*n);
//        }
//        else{
//            if(Find(x)==Find(y)||Find(x)==Find(2*n+y)){
//                ans++;
//                continue;
//            }
//            Union(x,y+n);
//            Union(x+n,y+2*n);
//            Union(x+2*n,y);
//        }
//    }
//    printf("%d\n",ans);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//using namespace std;
//const int maxn = 2e3+10;
//int fa[maxn],r[maxn];
//bool flag;
//int getf(int x){
//    if(x==fa[x])return x;
//    int t=getf(fa[x]);
//    r[x]=(r[x]+r[fa[x]])%2;
//    fa[x]=t;
//    return fa[x];
//}
//void join(int x,int y)
//{
//    int fx=getf(x),fy=getf(y);
//    if(fx==fy){
//        if(r[x]==r[y]){
//            flag = false;
//        }
//        return;
//    }
//    fa[fy]=fx;
//    r[fy]=(r[x]+1-r[y]+2)%2;
//}
//int main()
//{
//    int t;scanf("%d",&t);
//    for(int i=1;i<=t;i++){
//        int n,m;scanf("%d%d",&n,&m);
//        for(int i=1;i<=n;i++){
//            fa[i]=i;r[i]=0;
//        }
//        flag=true;
//        int a,b;
//        for(int i=0;i<m;i++){
//            scanf("%d%d",&a,&b);
//            if(flag)join(a,b);
//        }
//        printf("Scenario #%d:\n",i);
//        if(flag)cout<<"No suspicious bugs found!"<<endl;
//        else cout<<"Suspicious bugs found!"<<endl;
//        cout<<endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//using namespace std;
//const int maxn = 1e5+10;
//int n,m,fa[maxn],r[maxn];
//int getf(int i)
//{
//    if(fa[i]==i)return i;
//    int t=getf(fa[i]);
//    r[i]=(r[i]+r[fa[i]])%2;
//    fa[i]=t;
//    return t;
//}
//void join(int x,int y)
//{
//    int fx=getf(x),fy=getf(y);
//    if(fx!=fy){
//        fa[fy]=fx;
//        r[fy]=(r[x]+1-r[y]+2)%2;
//    }
//}
//int main()
//{
//    int t;cin>>t;
//    while(t--){
//        scanf("%d%d",&n,&m);
//        for(int i=1;i<=n;i++){
//            fa[i]=i;
//            r[i]=0;
//        }
//        while(m--){
//            char op;int a,b;
//            scanf("\n%c%d%d",&op,&a,&b);
//            if(op=='A'){
//                if(getf(a)==getf(b)){
//                    if(r[a]==r[b])cout<<"In the same gang."<<endl;
//                    else cout<<"In different gangs."<<endl;
//                }
//                else{
//                    cout<<"Not sure yet."<<endl;
//                }
//            }
//            else
//                join(a,b);
//        }
//    }
//    return 0;
//}
//#include<iostream>
//#include<cstring>
//using namespace std;
//const int maxn = 1e3+10;
//int n,a,b,fa[maxn],r[maxn];
//int dp[maxn][maxn];
//struct group
//{
//    int head,a,b;
//}group[maxn];
//void init()
//{
//    memset(fa,0,sizeof(fa));
//    memset(r,0,sizeof(r));
//    memset(group,0,sizeof(group));
//    memset(dp,0,sizeof(dp));
//}
//int getf(int x)
//{
//    if(fa[x]==x)return x;
//    int t = getf(fa[x]);
//    r[x]=(r[x]+r[fa[x]])%2;
//    fa[x]=t;
//    return t;
//}
//void join(int x,int y,int w)
//{
//    int fx=getf(x),fy=getf(y);
//    fa[fy]=fx;
//    r[fy]=(r[x]+w-r[y]+2)%2;
//}
//int main()
//{
//    while(cin>>n>>a>>b&&n&&a&&b){
//        init();
//        int x,y;string str;
//        for(int i=0;i<n;i++){
//            cin>>x>>y>>str;
//            int w;
//            if(str.size()==3) w=0;
//            else w=1;
//            int fx=getf(x),fy=getf(y);
//            if(fx!=fy)join(x,y,w)
//        }
//    }
//    return 0;
//}

/* POJ1456 ZOJ1731 UVA1316 UVALive2757 Supermarket */

//#include <iostream>
//#include <algorithm>
//#include <stdio.h>
//#include <string.h>
//
//using namespace std;
//
//const int N = 10000;
//int f[N + 1];
//int Find(int a)
//{
//    if(f[a]==-1)return a;
//    f[a]=Find(f[a]);
//    return f[a];
//}
//
//struct Prod {
//    int p, d;
//} p[N];
//
//bool cmp(Prod a, Prod b)
//{
//    return a.p > b.p;
//}
//
//int main()
//{
//    int n;
//    while(scanf("%d", &n) == 1) {
//        memset(f, -1, sizeof(f));
//
//        for(int i = 0; i < n; i++)
//            scanf("%d%d", &p[i].p, &p[i].d);
//
//        sort(p, p + n, cmp);
//
//        int ans = 0;
//        for(int i = 0; i < n; i++) {
//            int pd = Find(p[i].d);
//            if(pd > 0) {
//                ans += p[i].p;
//                f[pd] = pd - 1;
//            }
//        }
//
//        printf("%d\n", ans);
//    }
//
//    return 0;
//}

#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1e9+10;
long long n,f[maxn],sum[maxn];
int m,ans;
void init(int i)
{
    f[i]=i;
    sum[i]=0;
}
int getf(int i)
{
    if(f[i]==i)return i;
    f[i]=getf(f[i]);
    return f[i];
}
void join(int a,int b,int w)
{
    int fa=getf(fa),fb=getf(fb);
    if(fa==fb)return;
    f[fb]=fa;
    sum[fb]=-sum[a]+sum[b]+w;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)init(i);
    while(m--){
        int a,b;string str;
        cin>>a>>b>>str;
        a--;
        int w;
        if(str.size()==3)w=1;
        else w=2;
        if(getf(a)==getf(b)){
            if((sum[a]-sum[b])%2==w%2)ans++;
            else break;
        }
    }
    cout<<ans<<endl;
    return 0;
}










