//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//const int maxn = 5e4+10;
//int fa[maxn],r[maxn],b[maxn];
//int n,m,N,cnt;
//struct node
//{
//    int x,y,va;
//}a[maxn];
//int getf(int x)
//{
//    if(x!=fa[x]){
//        int t = fa[x];
//        fa[x]=getf(fa[x]);
//        r[x]=(r[x]+r[t])%2;
//    }
//    return fa[x];
//}
//int mysearch(int k)
//{
//    int l=0,r=N-1;
//    while(l<=r){
//        int m = (l+r)>>1;
//        if(b[m]==k) return m;
//        else if(b[m]<k) l = m + 1;
//        else if(b[m]>k) r = m - 1;
//    }
//}
//int main()
//{
//    scanf("%d%d",&n,&m);
//    char str[20];
//    cnt = 0;
//    for(int i=0;i<m;i++){
//        scanf("%d%d%s",&a[i].x,&a[i].y,str);
//        a[i].x--;
//        if(str[0]=='o')a[i].va=1;
//        else a[i].va=0;
//        b[cnt++]=a[i].x;b[cnt++]=a[i].y;
//    }
//        for(int i=0;i<=cnt;i++){
//            fa[i]=i;r[i]=0;
//        }
//        sort(b,b+cnt);
//        N=unique(b,b+cnt)-b;
//        int i;
//        for(i=0;i<m;i++){
//            int nx=mysearch(a[i].x);
//            int ny=mysearch(a[i].y);
//            int fx=getf(nx),fy=getf(ny);
//            if(fx==fy){
//                if((r[nx]+r[ny]+2)%2!=a[i].va){
//                    printf("%d\n",i);
//                    break;
//                }
//            }
//            else{
//                fa[fy]=fx;
//                r[fy]=(r[nx]-r[ny]+2+a[i].va)%2;
//            }
//        }
//        if(i>=m){
//            printf("%d\n",m);
//        }
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//using namespace std;
//const int maxn=3e4+10;
//int p;
//int fa[maxn],gp[maxn],a[maxn];
//inline void init()
//{
//    for(int i=0;i<maxn;i++){
//        fa[i]=i;
//        gp[i]=0;
//        a[i]=1;
//    }
//}
//int getf(int x)
//{
//    if(x!=fa[x]){
//        int t = fa[x];
//        fa[x]=getf(fa[x]);
//        gp[x]=gp[t]+gp[x];
//    }
//    return fa[x];
//}
//void join(int x,int y)
//{
//    int fx=getf(x),fy=getf(y);
//    if(fx==fy)return;
//    fa[fx]=fy;
//    gp[fx]=a[fy];
//    a[fy]+=a[fx];
//
//}
//int main()
//{
//    scanf("%d",&p);
//    init();
//    while(p--){
//        int x,y;char c;
//        scanf("\n%c",&c);
//        if(c=='M'){
//            scanf("%d%d",&x,&y);
//            join(x,y);
//        }
//        else{
//            scanf("%d",&x);
//            getf(x);
//            printf("%d\n",gp[x]);
//        }
//    }
//    return 0;
//}

//#include<iostream>
//#include<ctime>
//#include<cmath>
//using namespace std;
//const int maxn = 1e6;
//int main()
//{
//    int sum = 1;
//    int flag = 0;
//    for(int i=3;i<=maxn;i++){
//        if(i==3)sum++;
//        if(i%6!=1&&i%6!=5)continue;
//        for(int j = 5;j<=(int)sqrt(i);j+=6){
//            if(i%j==0||i%(j+2)==0){
//                flag=1;
//                break;
//            }
//        }
//        if(flag){
//            flag=0;
//            continue;
//        }
//        sum++;
//    }
//    cout<<"time used = ";
//    printf("%0.2f\n",(double)clock()/CLOCKS_PER_SEC);
//    cout<<sum<<endl;
//    return 0;
//}

//
//#include<iostream>
//#include<cstdio>
//#include<ctime>
//#include<vector>
//using namespace std;
//const int maxn = 1e6;
//int sum;
//vector<bool> prime;
//int main()
//{
//    prime.resize(maxn,1);
//    prime[0]=prime[1]=0;
//    for(int i=2;i*i<=prime.size();i++)
//    {
//        if(prime[i]==1){
//            for(int j=i*2;j<=prime.size();j+=i){
//                prime[j]=0;
//            }
//        }
//    }
//    for(int i=0;i<=prime.size();i++){
//        if(prime[i])sum++;
//    }
//    cout<<sum<<endl;
//    cout<<"t: ";
//    printf("%0.2f\n",clock()/CLOCKS_PER_SEC);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<vector>
//using namespace std;
//const int maxn = 1e8+10;
//long long n;
//vector<bool> prime;
//int ans;
//int main()
//{
//    scanf("%d",&n);ans=n-1;
//    prime.resize(n,1);
//    prime[1]=prime[0]=0;
//    for(int i=2;i*i<=n;i++){
//        if(prime[i]){
//            for(int j=i*2;j<=n;j+=i){
//                prime[j]=0;
//            }
//        }
//    }
//    cout<<ans<<endl;
//    return 0;
//}

















