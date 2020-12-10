//#include<iostream>
//#include<cstdio>
//using namespace std;
//const int maxn = 5e4+10;
//long long L,ans;
//int n,m,d[maxn];
//bool judge(long long mid)
//{
//    long long cur=0;
//    int cnt=0;
//    int next=0;
//    while(next<n+1){
//        next++;
//        if(d[next]-d[cur]<mid){
//            cnt++;
//        }
//        else{
//            cur=next;
//        }
//    }
//    if(cnt>m)return false;
//    else return true;
//}
//int main()
//{
//    scanf("%d%d%d",&L,&n,&m);
//    for(int i=1;i<=n;i++){
//        scanf("%d",&d[i]);
//    }
//    d[n+1]=L;
//    long long l=1,r=L;
//    while(l<=r){
//        long long mid=(l+r)>>1;
//        if(judge(mid)){
//            ans=mid;
//            l=mid+1;
//        }
//        else{
//            r=mid-1;
//        }
//    }
//    printf("%lld",ans);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//using namespace std;
//const int maxn = 1e5+10;
//int n,m,a[maxn],maxp;
//int main()
//{
//    scanf("%d%d",&n,&m);
//    long long s=0;
//    for(int i=1;i<=n;i++){
//        scanf("%d",&a[i]);
//        s+=a[i];
//        maxp=max(maxp,a[i]);
//    }
//    long long l=maxp,r=s;
//    while(l<=r){
//        long long mid = (l+r)/2;
//        int cnt=0;int cur=1;
//        long long sum=0;
//        for(int i=1;i<=n;i++){
//            if(a[i]+sum<=mid){
//                sum+=a[i];
//            }
//            else{
//                sum=a[i];
//                cnt++;
//            }
//        }
//        if(cnt>=m){
//            l=mid+1;
//        }
//        else r=mid-1;
//    }
//    printf("%lld",l);
//    return 0;
//}

//#include<iostream>
//using namespace std;
//const int maxn = 1e5+10;
//int L,n,ans,m,a[maxn],maxp,minp=0xffffffff;
//bool judge(int mid)
//{
//    int cnt=0;
//    for(int i=1;i<=n+1;i++){
//        if(a[i]-a[i-1]>mid){
//            cnt+=(a[i]-a[i-1])/mid;
//            if((a[i]-a[i-1])%mid==0)
//                cnt--;
//        }
//    }
//    if(cnt>m)return true;
//    return false;
//}
//int main()
//{
//    scanf("%d%d%d",&L,&n,&m);
//    for(int i=1;i<=n;i++){
//        scanf("%d",&a[i]);
//        minp=min(minp,a[i]-a[i-1]);
//        maxp=max(maxp,a[i]-a[i-1]);
//    }
//    a[n+1]=L;
//    minp=min(minp,L-a[n]);
//    maxp=max(maxp,L-a[n]);
//    int l = minp,r = maxp;
//    while(l<=r){
//        int mid = (r+l)>>1;
//        if(judge(mid)) l = mid + 1;
//        else r = mid - 1;
//    }
//    printf("%d",l);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//using namespace std;
//const int maxn = 1e5+10;
//int ans,n,a[maxn],b[maxn];
//void merge_sort(int l,int r)
//{
//    if(l==r)return;
//    int mid = (r+l)>>1;int i=l,j=mid+1,k=l;
//    merge_sort(l,mid),merge_sort(mid+1,r);
//
//    while(i<=mid&&j<=r){
//        if(a[i]>a[j]){
//            ans+=(mid-i+1);
//            b[k++]=a[j++];
//        }
//        else b[k++]=a[i++];
//    }
//    while(i<=mid)b[k++]=a[i++];
//    while(j<=r)b[k++]=a[j++];
//    for(int m=l;m<=r;m++){
//        a[m]=b[m];
//    }
//}
//int main()
//{
//    cin>>n;
//    for(int i=0;i<n;i++)cin>>a[i];
//    merge_sort(0,n-1);
//    cout<<ans<<endl;
//    return 0;
//}

//#include<iostream>
//using namespace std;
//const int maxn = 1e5+10;
//int n,a[maxn],b[maxn];
//void merge_sort(int l,int r)
//{
//    if(l==r)return ;
//    int mid = (l+r)>>1;
//    merge_sort(l,mid),merge_sort(mid+1,r);
//    int i=l,j=mid+1,k=l;
//    while(i<=mid&&j<=r){
//        if(a[i]>a[j]) b[k++]=a[j++];
//        else b[k++]=a[i++];
//    }
//    while(i<=mid)b[k++]=a[i++];
//    while(j<=r)b[k++]=a[j++];
//    for(int m=l;m<=r;m++)a[m]=b[m];
//}
//int main()
//{
//    cin>>n;
//    for(int i=1;i<=n;i++)cin>>a[i];
//    merge_sort(1,n);
//    for(int i=1;i<=n;i++){
//        cout<<a[i];
//        if(i<n)cout<<" ";
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//using namespace std;
//const int maxn = 1e6+10;
//long long n,ans;bool a[maxn];
//int main()
//{
//    while(cin>>n&&n){
//        ans=0;
//        memset(a,0,sizeof(a));
//        for(int i=1;i<=n;i++){
//            for(int j=i;j<=n;j+=i){
//                if(a[j])a[j]=0;
//                else a[j]=1;
//            }
//        }
//        for(int i=1;i<=n;i++){
//            ans+=a[i];
//        }
//        cout<<ans<<endl;
//    }
//    return 0;
//}
//
//#include<iostream>
//#include<cmath>
//using namespace std;
//long long n,ans;
//void mysearch(long long l,long long r)
//{
//    if(l==r){
//        if(sqrt(l)-(int)sqrt(l)==0)ans++;
//        return;
//    }
//    long long m = (l+r)>>1;
//    mysearch(l,m);
//    mysearch(m+1,r);
//}
//int main()
//{
//    while(cin>>n&&n){
//        ans=0;
//        mysearch(1,n);
//        cout<<ans<<endl;
//    }
//    return 0;
//}
//

//#include<iostream>
//using namespace std;
//long long n;
//int main()
//{
//    while(cin>>n&&n){
//        cout<<(int)sqrt(n)<<endl;
//    }
//    return 0;
//}
//
//#include<iostream>
//#include<map>
//#include<cstdio>
//using namespace std;
//int n,a[2010];
//map<int,int> ma;
//int main()
//{
//    cin>>n;
//    for(int i=0;i<n;i++)cin>>a[i];
//    int ans=-1;
//    for(int i=-1;i<n;i++){
//        ma.clear();
//        int num=0;
//        for(int j=0;j<=i;j++){
//            if(!ma[a[j]])ma[a[j]]=1,num++;
//            else break;
//        }
//        for(int j=n-1;j>i;j--){
//            if(!ma[a[j]])ma[a[j]]=1,num++;
//            else break;
//        }
//        ans=max(ans,num);
//    }
//    cout<<n-ans<<endl;
//    return 0;
//}

//#include<iostream>
//using namespace std;
//const int maxn = 1e4+10;
//int n,m,a[maxn][maxn];
//int main()
//{
//    cin>>n>>m;int x,y,v;
//    for(int i=1;i<=n;i++){
//        cin>>x>>y>>v;
//        a[x][y]=v;
//    }
//
//    return 0;
////}
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int maxn = 1e5+10;
//int a[maxn],n,ans;
//int main()
//{
//    cin>>n;
//    for(int i=1;i<=n;i++){
//        cin>>a[i];
//    }
//    sort(a,a+n);
//    for(int i=1;i<=n;i++){
//        ans+=(a[n]-a[i]);
//    }
//    cout<<ans<<endl;
//    return 0;
//}

//#include<iostream>
//using namespace std;
//const int maxn = 5e3+10;
//int n,m,x,y,v,ans,a[maxn][maxn];
//int main()
//{
//    cin>>n>>m;
//    for(int i=1;i<=n;i++){
//        cin>>x>>y>>v;
//        a[x+1][y+1]=v;
//    }
//    for(int i=1;i<=5001;i++){
//        for(int j=1;j<=5001;j++){
//            a[i][j]=a[i][j-1]+a[i-1][j]-a[i-1][j-1]+a[i][j];
//        }
//    }
//    for(int i=0;i<=5000-m;i++){
//        for(int j=0;j<=5000-m;j++)
//        ans=max(ans,a[i+m][j+m]-a[i+m][j]-a[i][j+m]+a[i][j]);
//    }
//    cout<<ans<<endl;
//    return 0;
//}












