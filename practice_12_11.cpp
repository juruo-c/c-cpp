//#include<iostream>
//using namespace std;
//const int maxn = 1e5+10;
//int n,m,a[maxn];
//long long sum[maxn],ans;
//struct node
//{
//    int a,b,c;
//}b[maxn];
//int main()
//{
//    cin>>n>>m;
//    for(int i=1;i<=m;i++)cin>>a[i];
//    for(int i=1;i<n;i++){
//        cin>>b[i].a>>b[i].b>>b[i].c;
//    }
//    for(int i=1;i<m;i++){
//        int nl=min(a[i],a[i+1]);
//        int nr=max(a[i],a[i+1]);
//        sum[nl]++;sum[nr]--;
//    }
//    for(int i=1;i<n;i++){
//        sum[i]=sum[i]+sum[i-1];
//    }
//    for(int i=1;i<n;i++){
//        ans+=min(sum[i]*b[i].a,sum[i]*b[i].b+b[i].c);
//    }
//    cout<<ans<<endl;
//    return 0;
//}

//#include<iostream>
//#include<map>
//#include<algorithm>
//using namespace std;
//const int maxn = 2510;
//pair<int,int> cow[maxn];
//int n,m;
//bool cmp(pair<int,int> a,pair<int,int> b)
//{
//    return a.first>b.first;
//}
//int main()
//{
//    cin>>n>>m;
//    for(int i=1;i<=n;i++)cin>>cow[i].first>>cow[i].second;
//    map<int,int>spfs;
//    for(int i=1;i<=m;i++){
//        int spf,cover;
//        cin>>spf>>cover;
//        spfs[spf]+=cover;
//    }
//    sort(cow+1,cow+n+1,cmp);
//    int cnt=0;
//    spfs[0]=spfs[1001]=n;
//    for(int i=1;i<=n;i++){
//        auto spf=spfs.upper_bound(cow[i].second);
//        spf--;
//        if(spf->first>=cow[i].first){
//            cnt++;
//            if(--spf->second==0){
//                spfs.erase(spf);
//            }
//        }
//    }
//    cout<<cnt<<endl;
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//#define pii pair<int,int>
//const int maxn = 1e5+10;
//int m;pii a[maxn],b[maxn];
//bool cmp(pii a,pii b)
//{
//    return a.second>b.second;
//}
//int main()
//{
//    int t;cin>>t;
//    while(t--){
//        cin>>m;
//        int l,r,cnt=0;
//        while(cin>>l>>r){
//            if(!l&&!r)break;
//            a[cnt].first=l,a[cnt++].second=r;
//        }
//        sort(a,a+cnt,cmp);
//        int st=0,endt=m,cur=0;
//        while(st<m){
//            int i;
//            for(i=0;i<cnt;i++){
//                if(a[i].first<=st&&a[i].second>st){
//                    st=a[i].second;
//                    b[cur++]=a[i];
//                    break;
//                }
//            }
//            if(i==cnt)break;
//        }
//        if(st<m){
//            cout<<0<<endl;
//        }
//        else{
//            cout<<cur<<endl;
//            for(int i=0;i<cur;i++){
//                cout<<b[i].first<<" "<<b[i].second<<endl;
//            }
//        }
//        if(t)cout<<endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<cmath>
//#include<vector>
//using namespace std;
//char a[101];vector<int> v;
//int b[101];
//void flip(int n)
//{
//    for(int i=0;i<=n/2;i++){
//        swap(b[i],b[n-i]);
//    }
//}
//int main()
//{
//    while(cin.getline(a,101)){
//        v.clear();
//        int p=0,tot=0;
//        while(p<strlen(a)){
//            int nn=a[p]-'0';
//            if(nn<=100&&nn>=1){
//                b[tot++]=nn;
//                p++;
//                while(a[p]-'0'<=100&&a[p]-'0'>=0){
//                    b[tot-1]*=10;
//                    b[tot-1]+=(a[p]-'0');
//                    p++;
//                }
//            }
//            p++;
//        }
//        for(int i=0;i<tot-1;i++)cout<<b[i]<<" ";
//        cout<<b[tot-1]<<endl;
//        for(int i=tot-1;i>=0;i--){
//            int mx=b[i],id=i;
//            for(int j=i-1;j>=0;j--){
//                if(b[j]>mx){
//                    mx=b[j];
//                    id=j;
//                }
//            }
//            if(id!=i){
//                if(!id){
//                    flip(i);
//                    v.push_back(tot-i);
//                }
//                else{
//                    flip(id);
//                    v.push_back(tot-id);
//                    flip(i);
//                    v.push_back(tot-i);
//                }
//            }
//        }
//        for(int i=0;i<v.size();i++){
//            cout<<v[i]<<" ";
//        }
//        cout<<0<<endl;
//    }
//    return 0;
//}
//

//#include<iostream>
//#include<vector>
//using namespace std;
//const int maxn = 1e6+10;//具体大小由题目而定
//vector<int> prime;
//int main()
//{
//    prime.resize(maxn,1);
//    prime[0]=prime[1]=0;
//    for(int i=2;i*i<=prime.size();i++){
//        if(prime[i]){
//            for(int j=2*i;j<=prime.size();j+=i){
//                prime[j]=0;
//            }
//        }
//    }
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//bool is_prime(int n)
//{
//    if(n<=1)return false;//特判
//    if(n==2||n==3)return true;//特判
//    if(n%6!=1&&n%6!=5)return false;
//    for(int i=5;i<=(int)sqrt(n);i+=6){
//        if(n%i==0||n%(i+2)==0)return false;
//    }
//    return true;
//}

//double f(double x)
//{
//    double ans = 0;
//    for(int i=0;i<=n;i++){
//        ans=ans*x+a[i];
//    }
//    return ans;
//}



