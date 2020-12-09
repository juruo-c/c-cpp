//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int maxn = 1e5+10;
//int n,q,m,a[maxn];
//int mysearch(int k)
//{
//    int l = 0, r = n-1;
//    while(l<=r){
//        int m = (l+r)>>1;
//        if(a[m]<=k) l = m+1 ;
//        else if(a[m]>k) r = m-1;
//    }
//    return l;
//}
//int main()
//{
//    scanf("%d",&n);
//    for(int i=0;i<n;i++)scanf("%d",&a[i]);
//    sort(a,a+n);
//    scanf("%d",&q);
//    while(q--){
//        scanf("%d",&m);
//        printf("%d\n",mysearch(m));
//    }
//    return 0;
//}
//#include<iostream>
//using namespace std;
//const int inf = 0xffffffff;
//const int maxn = 6e4+10;
//double p[maxn],v[maxn];
//double high,low,m,l,r;
//double maxp,minp=inf;
//int n;
//int main()
//{
//    scanf("%d",&n);
//    for(int i=0;i<n;i++){
//        scanf("%lf",&p[i]);
//        maxp=max(p[i],maxp);
//        minp=min(p[i],minp);
//    }
//    for(int i=0;i<n;i++)scanf("%lf",&v[i]);
//    high=maxp,low=minp;
//    while(high-low>=1e-7){
//        m=(high+low)/2;
//        l = r = 0;
//        for(int i=0;i<n;i++){
//            if(p[i]<m){
//                l=max((m-p[i])/v[i],l);
//            }
//            else{
//                r=max((p[i]-m)/v[i],r);
//            }
//        }
//        if(l==r)break;
//        else if(l>r) high = m;
//        else if(l<r) low = m;
//    }
//    printf("%.12lf",(l+r)/2);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//const int maxn = 1e6+10;
//int a[maxn],n,m;
//int main()
//{
//    scanf("%d%d",&n,&m);
//    for(int i=0;i<n;i++)scanf("%d",&a[i]);
//    while(m--){
//        int k;scanf("%d",&k);
//        int* ans = lower_bound(a,a+n,k);
//        if(*ans != k)printf("-1");
//        else printf("%d",ans-a+1);
//        if(m)cout<<" ";
//    }
//    return 0;
//}
//
//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//const int maxn = 2e5+10;
//int n,c,a[maxn];
//long long ans;
//int main()
//{
//    scanf("%d%d",&n,&c);
//    for(int i=0;i<n;i++)scanf("%d",&a[i]);
//    sort(a,a+n);
//    for(int i=0;i<n;i++){
//        ans+=(upper_bound(a,a+n,a[i]+abs(c))-lower_bound(a,a+n,a[i]+abs(c)));
//    }
//    printf("%lld",ans);
//    return 0;
//}
//
//#include<iostream>
//#include<cstdio>
//using namespace std;
//const int maxn = 1e6+10;
//typedef long long ll;
//ll n,ans,m,a[maxn];
//ll maxp=0;
//int main()
//{
//    scanf("%lld%lld",&n,&m);
//    for(int i=0;i<n;i++){
//        scanf("%lld",&a[i]);
//        maxp=max(maxp,a[i]);
//    }
//    ll l = 0,r = maxp;
//    while(l<=r){
//        ll mid = (l+r)>>1;
//        ll sum = 0;
//        for(int i=0;i<n;i++){
//            if(a[i]-mid>0)sum+=(a[i]-mid);
//        }
//        if(sum >= m) l = mid+1;
//        else if(sum < m) r = mid-1;
//    }
//    printf("%lld\n",l-1);
//    return 0;
//}
//#include<iostream>
//using namespace std;
//int n;
//struct node
//{
//    int va;
//    bool flag;
//}a[110];
//bool check()
//{
//    int sum=0;
//    for(int i=1;i<=n;i++){
//        sum+=a[i].flag;
//    }
//    if(sum==1)return true;
//    else return false;
//}
//int main()
//{
//    cin>>n;
//    for(int i=1;i<=n;i++){
//        a[i].flag=1;
//        a[i].va=i;
//    }
//    int cnt=0,cur=1;
//    while(1){
//        if(a[cur].flag)cnt++;
//        if(cnt==3){
//            cnt=0;
//            cout<<a[cur].va<<" ";
//            a[cur].flag=0;
//        }
//        if(check())break;
//        cur++;
//        if(cur>n)cur%=n;
//    }
//    for(int i=1;i<=n;i++){
//        if(a[i].flag)
//            cout<<endl<<a[i].va<<endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//const int maxn = 1e5+10;
//int m,n,ans,a[maxn],b[maxn];
//int mysearch(int k)
//{
//    int l = 0, r = m;
//    while(l<r){
//        int m = (l+r)>>1;
//        if(a[m]>k)r=m;
//        else l=m+1;
//    }
//    return l;
//}
//int main()
//{
//    cin>>m>>n;
//    for(int i=0;i<m;i++){
//        cin>>a[i];
//    }
//    for(int i=0;i<n;i++){
//        cin>>b[i];
//    }
//    sort(a,a+m);
//    for(int i=0;i<n;i++){
//        int pos=mysearch(b[i]);
//        if(b[i]<=a[0]){
//            ans+=(a[0]-b[i]);
//        }
//        else
//        ans+=min(abs(a[pos]-b[i]),abs(a[pos-1]-b[i]));
//    }
//    cout<<ans<<endl;
//    return 0;
//}
//#include<iostream>
//using namespace std;
//const int maxn = 1e5+10;
//int n,k,a[maxn],maxp;
//int main()
//{
//    cin>>n>>k;
//    long long sum=0;
//    for(int i=0;i<n;i++){
//        cin>>a[i];
//        sum+=a[i];
//        maxp=max(a[i],maxp);
//    }
//    if(!(sum/k)){
//        cout<<0<<endl;
//        return 0;
//    }
//    int l = 1,r = maxp;
//    while(l<r){
//        int m = (l+r)>>1;
//        int sum=0;
//        for(int i=0;i<n;i++){
//            sum+=(a[i]/m);
//        }
//        if(sum>=k) l = m+1;
//        else r = m;
//    }
//    cout<<l-1<<endl;
//    return 0;
//}
//
//#include<iostream>
//using namespace std;
//int main()
//{
//    int a,b,c;
//    cin>>a>>b>>c;
//    int maxn=a;
//    maxn=max(maxn,b);
//    maxn=max(maxn,c);
//    cout<<maxn<<endl;
//    return 0;
//}

//#include<iostream>
//#include<cmath>
//using namespace std;
//bool is_prime(int n){
//    for(int i=2;i<=(int)sqrt(n);i++){
//        if(n%i==0)return false;
//    }
//    return true;
//}
//int main()
//{
//    for(int i=50;i<=100;i++){
//        if(is_prime(i)){
//            cout<<i<<" ";
//        }
//    }
//    return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//    long long sum=0;long long tmp=1;
//    for(int i=1;i<=20;i++){
//        tmp*=i;
//        sum+=tmp;
//    }
//    cout<<sum<<endl;
//    return 0;
//}

//#include<iostream>
//using namespace std;
//typedef long long ll;
//const int maxn = 5e4+10;
//int n,m;
//ll L,a[maxn],b[maxn];
//int main()
//{
//    cin>>L>>n>>m;
//    for(int i=1;i<=n;i++)cin>>a[i];
//    ll l = 0,r = L;
//    while(l<r){
//        ll mid =(l+r)>>1;
//        int cnt=0;
//        for(int i=1;i<=n;i++){
//            b[i]=a[i]-a[i-1];
//            if(b[i]<mid)cnt++;
//        }
//        if(cnt>=m) r = m;
//        else l = m+1;
//    }
//    cout<<r<<endl;
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//using namespace std;
//const int maxn = 5e5+10;
//int n,a[maxn],c[maxn];
//long long ans;
//void merge_sort(int l,int r)
//{
//    if(l==r)return;
//    int mid = (l+r)>>1;
//    int i=l,k=l,j=mid+1;
//    merge_sort(l,mid),merge_sort(mid+1,r);
//    while(i<=mid&&j<=r){
//        if(a[i]<=a[j])c[k++]=a[i++];
//        else c[k++]=a[j++],ans+=(mid-i+1);
//    }
//    while(i<=mid)c[k++]=a[i++];
//    while(j<=r)c[k++]=a[j++];
//    for(int m=l;m<=r;m++) a[m]=c[m];
//}
//int main()
//{
//    scanf("%d",&n);
//    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
//    merge_sort(1,n);
//    printf("%lld",ans);
//    return 0;
//}


//#include<iostream>
//using namespace std;
//const int maxn = 1e3+10;
//int n,a[maxn][maxn],dp[maxn][maxn];
//int main()
//{
//    cin>>n;
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=i;j++){
//            cin>>a[i][j];
//        }
//    }
//    for(int i=n-1;i>=1;i--){
//        for(int j=1;j<=i;j++){
//            a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
//        }
//    }
//    cout<<a[1][1]<<endl;
//    return 0;
//}

//#include<iostream>
//using namespace std;
//const int maxn = 1e8+10;
//bool prime[maxn];
//int main()
//{
//    int n;scanf("%d",&n);
//    int s=n;s--;
//    for(int i=2;i<=n;i++){
//        if(prime[i]==0){
//            for(int j=i*2;j<=n;j+=i){
//                if(!prime[j]){
//                    prime[j]=1;
//                    s--;
//                }
//            }
//        }
//    }
//    printf("%d",s);
//    return 0;
//}

#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1e3+10;
int n,m,a[maxn][maxn],b[maxn][maxn];
int main()
{
    cin>>n>>m;
    while(m--){
        int lx,ly,rx,ry;
        cin>>lx>>ly>>rx>>ry;
        b[lx][ly]++,b[lx][ry+1]--;
        b[rx+1][ly]--,b[rx+1][ry+1]++;
    }
    int tmp=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            tmp+=b[i][j];
            cout<<tmp;
            if(j<n)cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}










