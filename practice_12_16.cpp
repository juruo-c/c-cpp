//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 20;
//const int M = 1<<20;
//
//int f[M][N];
//int w[N][N];
//int n;
//
//int main()
//{
//    cin>>n;
//    for(int i=0;i<n;i++)
//        for(int j=0;j<n;j++)
//            cin>>w[i][j];
//
//    memset(f,0x3f,sizeof f);
//    f[1][0] = 0;
//
//    for(int i = 0;i < (1<<n);i++){
//        for(int j = 0;j < n;j++){
//            if((i>>j)&1){
//                for(int k = 0;k < n;k++){
//                    if((i-(1<<j)>>k)&1){
//                        f[i][j] = min(f[i][j],f[i-(1<<j)][k]+w[k][j]);
//                    }
//                }
//            }
//        }
//    }
//
//    cout<<f[(1<<n)-1][n-1]<<endl;
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<cmath>
//
//using namespace std;
//
//const int N = 16;
//const int M = 1<<16;
//
//double w[N][N];
//double f[M][N];
//pair<double,double> p[N];
//
//double dis(double a,double b,double c,double d)
//{
//    double t;
//    t = (a-c)*(a-c)+(b-d)*(b-d);
//    return sqrt(t);
//}
//
//int main()
//{
//    int n;cin>>n;
//    p[0].first = 0,p[0].second = 0;
//    for(int i=1;i<=n;i++){
//        cin>>p[i].first>>p[i].second;
//    }
//    for(int i=0;i<=n;i++){
//        for(int j=0;j<=n;j++){
//            w[i][j] = dis(p[i].first,p[i].second,p[j].first,p[j].second);
//        }
//    }
////    for(int i=0;i<=n;i++){
////        for(int j=0;j<=n;j++){
////            printf("%.2lf ",w[i][j]);
////        }
////        cout<<endl;
////    }
//
//    double ans = 0x3f3f3f3f;
//
//    memset(f,127,sizeof(f));
//    f[1][0] = 0;
//
//    for(int i=0;i<(1<<n+1);i++){
//        for(int j=0;j<=n;j++){
//            if(i>>j&1){
//                for(int k=0;k<=n;k++){
//                    if((i-(1<<j))>>k&1){
//                        f[i][j] = min(f[i][j],f[i-(1<<j)][k]+w[k][j]);
//                    }
//                }
//            }
//        }
//    }
//
//    for(int i=1;i<=n;i++){
//        ans = min(ans,f[(1<<n+1)-1][i]);
//    }
//
//    printf("%.2lf",ans);
//    return 0;
//}
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 35;
//
//int a[N][N],n;
//bool vis[N][N];
//int dir[][2]={{1,0},{-1,0},{0,1},{0,-1}};
//
//void dfs(int x,int y){
//    if(vis[x][y]||a[x][y])return;
//    vis[x][y]=1;
//    for(int i=0;i<4;i++){
//        int tx = x+dir[i][0];
//        int ty = y+dir[i][1];
//        if(tx>=0&&tx<=n+1&&ty>=0&&ty<=n+1){
//            dfs(tx,ty);
//        }
//    }
//}
//
//int main()
//{
//    cin>>n;
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            cin>>a[i][j];
//        }
//    }
//
//    dfs(0,0);
//
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            if(vis[i][j])cout<<a[i][j]<<" ";
//            else{
//                if(a[i][j])cout<<a[i][j]<<" ";
//                else cout<<2<<" ";
//            }
//        }
//        cout<<endl;
//    }
//    return 0;
//}
//#include<iostream>
//#include<cmath>
//using namespace std;
//int n;
//bool is_prime(int x)
//{
//    if(x<2)return false;
//    for(int i=2;i<=(int)sqrt(x);i++){
//        if(x%i==0)return false;
//    }
//    return true;
//}
//int main()
//{
//    int t;cin>>t;
//    while(t--){
//        cin>>n;
//        if(is_prime(n)){
//            cout<<"prime"<<endl;
//        }
//        else cout<<"not prime"<<endl;
//    }
//    return 0;
//
//}
//#include<iostream>
//
//using namespace std;
//
//float fact(float n){
//    float t = 1;
//    for(float i=2;i<=n;i++){
//        t*=i;
//    }
//    return t;
//}
//int main()
//{
//    float m,n;
//    cin>>m>>n;
//    cout<<(int)fact(m)/(fact(n)*fact(m-n));
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//const int maxn = 201;
//
//int a[maxn][maxn];
//int n,m;
//
//bool is_col(int row,int col){
//    int minn = a[row][col];
//    for(int i=0;i<n;i++){
//        if(minn>a[i][col]){
//            return false;
//        }
//    }
//    return true;
//}
//int main()
//{
//    int t;cin>>t;
//    while(t--){
//        cin>>n>>m;
//        for(int i=0;i<n;i++){
//            for(int j=0;j<m;j++){
//                cin>>a[i][j];
//            }
//        }
//        int flag = 0;
//        for(int i=0;i<n;i++){
//            int maxx = a[i][0];
//            int col = 0;
//            for(int j=0;j<m;j++){
//                if(maxx<a[i][j]){
//                    maxx = a[i][j];
//                    col = j;
//                }
//            }
//            if(is_col(i,col)){
//                cout<<i<<" "<<col<<endl;
//                flag = 1;
//            }
//        }
//        if(flag==0)cout<<-1<<endl;
//    }
//    return 0;
//}
//#include<bits/stdc++.h>
//
//using namespace std;
//
//const int maxn = 1e3+10;
//
//char a[maxn];
//int main()
//{
//    while(gets(a)){
//        for(int i=0;i<strlen(a);i++){
//        if(a[i]=='y'){
//            int cur = i;
//            if(cur>strlen(a)-3){
//                cout<<a[i];
//                continue;
//            }
//            if(a[cur+1]=='o'&&a[cur+2]=='u'){
//                cout<<'w'<<'e';
//                i = cur + 2;
//            }
//            else{
//                cout<<a[cur];
//            }
//        }
//        else{
//            cout<<a[i];
//        }
//    }
//    cout<<endl;
//    }
//
//    return 0;
//}
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<set>
//
//using namespace std;
//double ans;
//char a[2020];
//
//set<int> s[2020];
//
//int main()
//{
//    int t;cin>>t;
//    while(t--){
//        for(int i=0;i<101;i++){
//            s[i].clear();
//        }
//        cin>>a;int cnt = 0;
//        ans = 0;int st = 0,cur = 0;
//        char t = a[cur];int tot = 0;
//        while(cur<strlen(a)){
//            if(a[cur]==a[st]){
//                tot++;cur++;
//            }
//            else{
//                if(!s[a[st]].count(tot)){
//                    s[a[st]].insert(tot);
//                    for(int i=st;i<cur;i++){
//                        cout<<a[i];
//                    }
//                    cout<<" ";
//                    ans+=tot;
//                    cnt++;
//                    st = cur;
//                    tot = 0;
//                }
//                else{
//                    st = cur;
//                    ans+=tot;
//                    tot=0;
//                    cnt++;
//                }
//            }
//        }
//        if(st<strlen(a)){
//            if(!s[a[st]].count(tot)){
//            s[a[st]].insert(tot);
//            for(int i=st;i<cur;i++){
//                cout<<a[i];
//            }
//            cout<<" ";
//            ans+=tot;
//            cnt++;
//            st = cur;
//            tot = 0;
//        }
//        }
//        printf("%.2lf\n",ans/cnt);
//    }
//    return 0;
//}
//

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int maxn = 1010;
//
//string a;
//char l[maxn],r[maxn];
//int dp[maxn][maxn];
//
//int main()
//{
//    int t;cin>>t;
//    while(t--){
//        cin>>a;
//    int len = a.length();
//    int len1=0,len2=0;
//    if(len%2){
//        for(int i = 0;i<=len/2;i++){
//        l[len1++]=a[i];
//    }
//    for(int i=len-1;i>=len/2+1;i--){
//        r[len2++] = a[i];
//
//    }
//    }
//    else{
//        for(int i=0;i<len/2;i++){
//            l[len1++]=a[i];
//        }
//        for(int i=len-1;i>=len/2;i--){
//            r[len2++]=a[i];
//        }
//    }
//
//    memset(dp,0,sizeof(dp));
//    for(int i=1;i<=len1;i++){
//        for(int j=1;j<=len2;j++){
//            if(l[i-1] == r[j-1])dp[i][j] = dp[i-1][j-1]+1;
//            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//        }
//    }
//    cout<<(len1-dp[len1][len2])+(len2-dp[len1][len2])<<endl;
//    }
//    return 0;
//}
//
//

//#include<bits/stdc++.h>
//using namespace std;
//
//const int maxn = 1e3+10;
//char s1[maxn],s2[maxn];
//int dp[maxn][maxn];
//
//int main()
//{
//    int t;cin>>t;
//    while(t--){
//        cin>>s1;
//        int len = strlen(s1);
//        strcpy(s2,s1);
//        reverse(s2,s2+len);
////        for(int i=0;i<len;i++){
////            cout<<s2[i];
////        }
////        cout<<endl;
//        memset(dp,0,sizeof(dp));
//        for(int i=1;i<=len;i++){
//            for(int j=1;j<=len;j++){
//                if(s1[i-1]==s2[j-1])dp[i][j] = dp[i-1][j-1]+1;
//                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//            }
//        }
//        cout<<len-dp[len][len]<<endl;
//    }
//    return 0;
//}
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//const int maxn = 1e4+10;
//int n,q,x,a[maxn],cas = 0;
//
//int main()
//{
//    while(cin>>n>>q&&n){
//        cout<<"CASE# "<<++cas<<":"<<endl;
//        for(int i=0;i<n;i++)cin>>a[i];
//        sort(a,a+n);
//        while(q--){
//            cin>>x;
//            int p = lower_bound(a,a+n,x)-a;
//            if(a[p] == x)cout<<x<<" found at "<<p+1<<endl;
//            else cout<<x<<" not found"<<endl;
//        }
//    }
//    return 0;
//}
//#include<iostream>
//#include<string>
//#include<vector>
//#include<cstdio>
//
//using namespace std;
//
//const int maxn = 30;
//int n;
//vector<int> pile[maxn];
//
//void find_block(int a,int& p,int& h){
//    for(p = 0;p < n;p++){
//        for(h = 0;h < pile[p].size();h++){
//            if(pile[p][h] == a)return;
//        }
//    }
//}
//
//void clear_above(int p,int h)
//{
//    for(int i = h+1;i < pile[p].size();i++){
//        int b = pile[p][i];
//        pile[b].push_back(b);
//    }
//    pile[p].resize(h+1);
//}
//
//void pile_onto(int p,int h,int p2){
//    for(int i = h;i<pile[p].size();i++){
//        pile[p2].push_back(pile[p][i]);
//    }
//    pile[p].resize(h);
//}
//
//void print(){
//    for(int i=0;i<n;i++){
//        printf("%d:",i);
//        for(auto x:pile[i]){
//            printf(" %d",x);
//        }
//        printf("\n");
//    }
//}
//
//int main()
//{
//    int a,b;
//    cin>>n;
//    string s1,s2;
//    for(int i=0;i<n;i++)pile[i].push_back(i);
//    while(cin>>s1&&s1!="quit"){
//        cin>>a>>s2>>b;
//        int pa,pb,ha,hb;
//        find_block(a,pa,ha);
//        find_block(b,pb,hb);
//        if(pa==pb)continue;
//        if(s2 == "onto")clear_above(pb,hb);
//        if(s1 == "move")clear_above(pa,ha);
//        pile_onto(pa,ha,pb);
//    }
//    print();
//    return 0;
//}
//#include<iostream>
//#include<set>
//#include<string>
//#include<sstream>
//
//using namespace std;
//
//set<string> dict;
//
//int main()
//{
//    string s,buf;
//    while(cin>>s){
//        for(int i=0;i<s.length();i++)
//            if(isalpha(s[i])) s[i] = tolower(s[i]);
//            else s[i] = ' ';
//        stringstream ss(s);
//        while(ss>>buf) dict.insert(buf);
//
//    }
//    for(auto x:dict){
//        cout<<x<<endl;
//    }
//    return 0;
//}
//#include<iostream>
//#include<string>
//#include<map>
//#include<cctype>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//map<string,int> cnt;
//vector<string> words;
//
//string repr(const string& s){
//    string ans = s;
//    for(int i=0;i<ans.length();i++){
//        ans[i] = tolower(ans[i]);
//    }
//    sort(ans.begin(),ans.end());
//    return ans;
//}
//
//int main()
//{
//    int n = 0;
//    string s;
//    while(cin>>s){
//        if(s[0] == '#')break;
//        words.push_back(s);
//        string r = repr(s);
//        if(!cnt.count(r)) cnt[r] = 0;
//        cnt[r]++;
//    }
//    vector<string> ans;
//    for(int i=0;i<words.size();i++)
//    if(cnt[repr(words[i])] == 1)ans.push_back(words[i]);
//    sort(ans.begin(),ans.end());
//    for(int i = 0;i<ans.size();i++){
//        cout<<ans[i]<<endl;
//    }
//    return 0;
//}
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<set>
//#include<vector>
//#include<map>
//#include<stack>
//
//using namespace std;
//#define ALL(x) x.begin(),x.end()
//#define INS(x) inserter(x,x.begin())
//
//typedef set<int> Set;
//map<Set,int> id;
//vector<Set> Setcache;
//
//int ID(Set x){
//    if(id.count(x)) return id[x];
//    Setcache.push_back(x);
//    return id[x] = Setcache.size()-1;
//}
//
//
//
//int main()
//{
//    stack<int> s;
//    int t;cin>>t;
//    while(t--){
//        int n;cin>>n;
//        while(n--){
//            string op;cin>>op;
//            if(op[0] == 'P')s.push(ID(Set()));
//            else if(op[0] == 'D')s.push(s.top());
//            else {
//                Set x1 = Setcache[s.top()];s.pop();
//                Set x2 = Setcache[s.top()];s.pop();
//                Set x;
//                if(op[0] == 'U') set_union (ALL(x1),ALL(x2),INS(x));
//                if(op[0] == 'I') set_intersection (ALL(x1),ALL(x2),INS(x));
//                if(op[0] == 'A'){
//                    x = x2;
//                    x.insert(ID(x1));
//                }
//                s.push(ID(x));
//            }
//            cout<<Setcache[s.top()].size()<<endl;
//
//        }cout<<"***"<<endl;
//    }
//    return 0;
//}
//

//#include<cstdio>
//#include<iostream>
//#include<queue>
//#include<map>
//
//using namespace std;
//
//const int maxn = 1e3+10;
//
//int main()
//{
//    int t,kase = 0;
//    while(scanf("%d",&t) == 1&& t){
//        printf("Scenario #%d\n",++kase);
//
//        map<int,int> team;
//        for(int i=0;i<t;i++){
//            int n,x;
//            scanf("%d",&n);
//            while(n--){
//                scanf("%d",&x);
//                team[x] = i;
//            }
//        }
//
//        queue<int> q,q2[maxn];
//        while(1){
//            int x;
//            char cmd[10];
//            scanf("%s",cmd);
//            if(cmd[0] == 'S')break;
//            else if(cmd[0] == 'D'){
//                int t = q.front();
//                printf("%d\n",q2[t].front());
//                q2[t].pop();
//                if(q2[t].empty()) q.pop();
//            }
//            else if(cmd[0] == 'E'){
//                scanf("%d",&x);
//                int t = team[x];
//                if(q2[t].empty())q.push(t);
//                q2[t].push(x);
//            }
//        }
//        cout<<endl;
//    }
//    return 0;
//}
#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;
typedef long long ll;

const int coeff[3] = {2,3,5};

int main()
{
    priority_queue<ll,vector<ll>,greater<ll> > q;
    set<ll> s;
    q.push(1);
    s.insert(1);
    for(int i=1;;i++){
        ll x = q.top();q.pop();
        if(i == 1500){
            cout<<"The 1500'th ugly number is "<<x<<endl;
            break;
        }
        for(int j=0;j<3;j++){
            ll x2 = x*coeff[j];
            if(!s.count(x2)){
                s.insert(x2);
                q.push(x2);
            }
        }
    }
    return 0;
}








