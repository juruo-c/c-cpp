//#include<iostream>
//#include<cmath>
//#include<cstring>
//#include<vector>
//using namespace std;
//const int N = 8;
//const int inf = 0x3f3f3f3f;
//static const int M = 1 << (N-1);
//int g[N][N] = {{0,1,inf,inf,5,6,inf,inf},
//               {1,0,2,inf,3,inf,inf,inf},
//               {inf,2,0,3,4,inf,inf,inf},
//               {inf,inf,3,0,1,inf,inf,2},
//               {5,3,4,1,0,4,2,5},
//               {6,inf,inf,inf,4,0,2,inf},
//               {inf,inf,inf,inf,2,2,0,4},
//               {inf,inf,inf,2,5,inf,4,0}};
//int dp[N][M];
//vector<int> path;
//void TSP(){
//    for(int i=0;i<N;i++){
//        dp[i][0]=g[i][0];
//    }
//    for(int j=1;j<M;j++){
//        for(int i=0;i<N;i++){
//            dp[i][j]=inf;
//            if(((j>>(i-1))&1)==1){
//                continue;
//            }
//            for(int k=1;k<N;k++){
//                if((j>>(k-1)&1)==0) continue;
//                if(dp[i][j]>g[i][k]+dp[k][j^(1<<(k-1))])
//                   dp[i][j]=g[i][k]+dp[k][j^(1<<(k-1))];
//            }
//
//        }
//    }
//}
//bool vis[N];
//bool is_visited()
//{
//    for(int i=1;i<N;i++){
//        if(!vis[i])return false;
//    }
//    return true;
//}
//void getpath()
//{
//    int pre=0,minn = inf,s = M - 1,t;
//    path.push_back(1);
//    while(!is_visited()){
//        for(int i=1;i<N;i++){
//            if(vis[i]==0&&(s&(1<<(i-1)))!=0){
//                if(minn>g[i][pre]+dp[i][(s^(1<<(i-1)))]){
//                    minn = g[i][pre]+dp[i][(s^(1<<(i-1)))];
//                    t = i;
//                }
//            }
//        }
//        pre = t;
//        path.push_back(pre+1);
//        vis[pre]=1;
//        s = s^(1<<(pre-1));
//        minn = inf;
//    }
//}
//void print()
//{
//    cout<<"最小路径为：";
//    for(auto x:path){
//        cout<<x<<"--->";
//    }
//    cout<<1;
//}
//int main()
//{
//    //建图
//    TSP();
//    cout<<"最小值为："<<dp[0][M-1]<<endl;
//    getpath();
//    print();
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<queue>
//#include<vector>
//using namespace std;
//typedef pair<int,int> PII;
//const int maxn = 5e4+10;
//int n,id[maxn];
//pair<PII,int> cows[maxn];
//int main()
//{
//    cin>>n;
//    for(int i=0;i<n;i++){
//        cin>>cows[i].first.first>>cows[i].first.second;
//        cows[i].second = i;
//    }
//
//    sort(cows,cows+n);
//
//    priority_queue<PII, vector<PII>,greater<PII> > h;
//    for(int i=0;i<n;i++){
//        if(h.empty()||h.top().first>=cows[i].first.first){
//            PII stall = {cows[i].first.second,h.size()};
//            id[cows[i].second]=stall.second;
//            h.push(stall);
//        }
//        else{
//            auto stall = h.top();
//            h.pop();
//            stall.first = cows[i].first.second;
//            id[cows[i].second] = stall.second;
//            h.push(stall);
//        }
//    }
//    cout<<h.size()<<endl;
//    for(int i = 0;i<n;i++){
//        cout<<id[i]+1<<endl;
//    }
//    return 0;
//}
//
//#include<iostream>
//#include<queue>
//using namespace std;
//const int maxn = 210;
//int n,a,b,k[maxn];
//bool vis[maxn];
//struct node
//{
//    int pos,st;
//};
//int bfs()
//{
//    queue<node> q;
//    node cur,next;
//    cur.pos = a,cur.st = 0;
//    vis[cur.pos] = 1;
//    q.push(cur);
//    while(!q.empty()){
//        cur = q.front();
//        q.pop();
//        if(cur.pos == b){
//            return cur.st;
//        }
//        for(int i = 0;i<2;i++){
//            if(i){
//                next.pos = cur.pos+k[cur.pos];
//            }
//            else{
//                next.pos = cur.pos-k[cur.pos];
//            }
//            if(next.pos>=1&&next.pos<=n&&!vis[next.pos]){
//                next.st = cur.st + 1;
//                q.push(next);
//                vis[next.pos]=1;
//            }
//        }
//    }
//    return -1;
//}
//int main()
//{
//    cin>>n>>a>>b;
//    for(int i=1;i<=n;i++){
//        cin>>k[i];
//    }
//    cout<<bfs()<<endl;
//    return 0;
//}
//#include<iostream>
//using namespace std;
//pair<double,double> a[20];
//int n;
//int main()
//{
//    cin>>n;
//    for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
//
//    return 0;
//}
//#include<iostream>
//#include<vector>
//using namespace std;
//const int maxn = 25;
//int n;
//int g[maxn][maxn],f[1<<20][20];
//int main()
//{
//    cin>>n;
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            cin>>g[i][j];
//        }
//    }
//
//    return 0;
//}
//#include<iostream>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//const int maxn = 1e3+10;
//struct hole
//{
//    int x,y,z,id;
//}h[maxn];
//int fa[maxn];
//int find_f(int i){
//    if(fa[i]==i)return i ;
//    return find_f(fa[i]);
//}
//int main()
//{
//    int t;
//    while(cin>>t&&t){
//        while(t--){
//            int n,h,r;
//            cin>>n>>h>>r;
//            for(int i=0;i<n;i++){
//                cin>>h[i].x>>h[i].y>>h[i].z;
//                h[i].id=i;
//            }
//            for(int i=0;i<n;i++){
//                fa[h[i].id]=h[i].id;
//            }
//        }
//    }
//    return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//const int maxn = 1e3+10;
//int f[maxn];
//int find_f(int x)
//{
//    if(x == f[x])return x;
//    f[x]=find_f(f[x]);
//    return f[x];
//}
//typedef long long ll;
//ll dis(ll x,ll y,ll z,ll a,ll b,ll c)
//{
//    return (x-a)*(x-a)+(y-b)*(y-b)+(z-c)*(z-c);
//}
//const int maxx = 1e5+10;
//ll x[maxx],y[maxx],z[maxx];
//int f1[maxx],f2[maxx];
//int main()
//{
//    int t, n,h;ll r;
//    cin>>t;
//    while(t--){
//        cin>>n>>h>>r;
//        int tot1=0,tot2=0;
//        for(int i=1;i<=n;i++){
//            f[i]=i;
//        }
//        for(int j=1;j<=n;j++){
//            cin>>x[j]>>y[j]>>z[j];
//            if(z[j]+r>=h){
//                f1[++tot1]=j;
//            }
//            if(z[j]-r<=0){
//                f2[++tot2]=j;
//            }
//            for(int k=1;k<=j;k++){
//                if((x[j]-x[k])*(x[j]-x[k])+(y[j]-y[k])*(y[j]-y[k])>4*r*r)continue;
//                if(dis(x[j],y[j],z[j],x[k],y[k],z[k])<=4*r*r){
//                    int fa = find_f(j);
//                    int fb = find_f(k);
//                    if(fa!=fb)f[fa]=fb;
//                }
//
//            }
//        }
//        int s=0;
//        for(int j=1;j<=tot1;j++){
//            for(int k=1;k<=tot2;k++){
//                if(find_f(f1[j])==find_f(f2[k])){
//                    s=1;
//                    break;
//                }
//            }
//            if(s)break;
//        }
//        if(s)cout<<"Yes"<<endl;
//        else cout<<"No"<<endl;
//    }
//}
//

//#include<iostream>
//using namespace std;
//const int maxn = 310;
//int n,a[maxn];
//int main()
//{
//    int t;cin>>t;
//    while(t--){
//        cin>>n;
//        for(int i=0;i<n;i++){
//            cin>>a[i];
//        }
//        int cur=0,tot=n-1;
//        while(cur<tot){
//            cout<<a[cur]<<" "<<a[tot]<<" ";
//            cur++,tot--;
//        }
//        if(cur==tot)cout<<a[tot]<<" "<<endl;
//        else cout<<endl;
//    }
//    return 0;
//}
//#include<iostream>
//using namespace std;
//const int maxn = 210;
//char a[maxn];int n;
//int main()
//{
//    int t;cin>>t;
//    while(t--){
//        cin>>n;
//        for(int i=0;i<n;i++){
//            cin>>a[i];
//        }
//        int cnt1,cnt2;
//        for(int i=0;i<n;i++){
//            if(a[i]=='0')cnt1++;
//            if(a[i]=='2')cnt2++;
//        }
//        if(cnt1<2||cnt2<2){
//            cout<<"NO"<<endl;
//            continue;
//        }
//        int f1=0,f2=0,f3=0,f4=0;
//        for(int i=0;i<n;i++){
//            if(a[i]=='2'&&!f1)f1=1;
//            if(a[i]=='0'&&f1)f2=1;
//            if(a[i]=='2'&&f1&&f2)f3=1;
//            if(a[i]=='0'&&f1&&f2&&f3)f4=1;
//        }
//        if(!f1||!f2||!f3||!f4){
//            cout<<"NO"<<endl;
//            continue;
//        }
//        char b[]="2020";
//        int st = 0,cnt = 0,flag = 0,cur = 0,t = 0;
//        while(1){
//            while(a[st]!=2){
//                st++;
//                cur++;
//            }
//            while(a[cur]==b[cur]){
//                cur++;
//            }
//            if(cur>=4){
//                flag=1;
//                break;
//            }
//            t = cur-1;
//            cnt++;
//
//        }
//        if(flag)cout<<"YES"<<endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//using namespace std;
//const int inf = 0x3f3f3f3f;
//int n,t,a[50],tot,ans = inf;
//int dp[50];bool vis[10];
//int dfs(int sum,int pos)
//{
//    if(sum == n){
//        int t = 0;
//        for(int i=tot-1;i>=0;i--){
//            t = t*10 + a[i];
//        }
//        ans = min(ans,t);
//        return ans;
//    }
//    for(int i=9;i>=0;i--){
//        if(!vis[i]){
//            if(dp[pos]<=i)continue;
//            dp[pos]=i;
//            vis[i]=1;
//            a[tot++]=i;
//            dfs(sum+i,pos+1);
//            tot--;
//            vis[i]=0;
//        }
//    }
//    if(ans==inf)return -1;
//    else return ans;
//}
//int main()
//{
//    cin>>t;
//    while(t--){
//        memset(vis,0,sizeof(vis));
//        memset(dp,0x3f,sizeof(dp));
//        ans=inf;tot=0;
//        cin>>n;
//        cout<<dfs(0,0)<<endl;
//    }
//    return 0;
//}





