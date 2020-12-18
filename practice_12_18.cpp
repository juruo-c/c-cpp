//#include<iostream>
//#include<queue>
//
//using namespace std;
//int n;
//
//int main()
//{
//    while(cin >> n&&n){
//        queue<int> q;
//
//        for(int i = 1;i <= n;i++)q.push(i);
//        cout << "Discarded cards:";
//        if(n != 1)cout << " ";
//        while(q.size() > 1){
//            int cur = q.front();
//            q.pop();
//            cout << cur ;
//            if(q.size() > 1)cout << ", ";
//            if(q.size() == 1)continue;
//            cur = q.front();
//            q.pop();
//            q.push(cur);
//        }
//        cout << endl;
//        cout << "Remaining card: " << q.front() <<endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//const int N = 310;
//
//int n,m;
//int v[N],w[N],s[N];
//int f[N];
//
//int main()
//{
//    cin >> n >> m;
//    for(int i = 1;i <= n;i++)cin >> v[i] >> w[i] >> s[i];
//
//    for(int i = 1;i <= n;i++){
//        for(int j = 1;j <= m;j++){
//            for(int k = 0;k <= s[i];k++){
//                if(j - k * v[i] >= 0){
//                    f[j] = max(f[j - k * v[i]] + k * w[i],f[j]);
//                }
//            }
//        }
//    }
//
//    cout << f[m] << endl;
//
//    return 0;
//}

//#include<iostream>
//#include<string>
//#include<cstring>
//#include<algorithm>
//#include<sstream>
//
//using namespace std;
//
//string s,st;
//int n,ans;
//
//int count_1()
//{
//    int cnt = 0;int tot = 0;
//    int i = 0;
//    while(i < s.length()){
//        if(s[i] == '1'){
//            cnt ++;
//        }
//        else{
//            tot = max(cnt,tot);
//            cnt = 0;
//        }
//        i ++;
//    }
//    if(cnt)tot = max(cnt,tot);
//    return tot;
//}
//int main()
//{
//    cin >> n >> s;
//    int flag = 1;
//    for(int i = 0;i < s.length();i ++){
//        if(s[i] == '0'){
//            flag = 0;
//            break;
//        }
//    }
//    if(flag){
//        cout << n << endl;
//        return 0;
//    }
//    for(int i = 0;i < s.length();i ++ ){
//        if(s[i] == '0'){
//            s[i] = '1';
////            cout << s << endl;
//            ans = max(ans,count_1());
//            s[i] = '0';
////            cout << s << endl;
//        }
//    }
//
//    cout << ans << endl;
//    return 0;
//}
//#include<iostream>
//#include<cmath>
//#include<algorithm>
//
//using namespace std;
//typedef long long ll;
//
//double ans;
//double a,p,q;
//
//double f(double x){
//    return a*x*x*x/3 - a*(2*q+p)*x*x/2 + a*q*(q+p)*x;
//}
//
//double f2(double x){
//    return a*x*x*x/3 - a*p*x*x/2;
//}
//int main()
//{
//    cin >> a >> p >> q;
//    if(q < p){
//        double t = q*(p + q)/(2*q);
//        ans += f2(t);
//        ans += (f(p+q) - f(t));
//    }
//    else{
//        ans += f2(p);
//        ans += (f(p+q) - f(q));
//    }
//    ans *= 123456;
//    ll out;
//    double tmp = ans - (ll)ans ;
//    if(tmp < 0.5)out = (ll)ans;
//    else out = (ll) ans + 1;
//    cout << out <<endl;
//    return 0;
//}
//#include<iostream>
//#include<vector>
//#include<cstring>
//#include<map>
//
//using namespace std;
//typedef long long ll;
//const int N = 2e5+10;
//int n,k;ll ans;ll out;
//ll f[N][N];
//bool vis[N];
//struct edge{
//    int v,w;
//};
//vector<edge> t[N];
//struct node
//{
//    int u,v,w;
//};
//map<int,node> ma;
//map<pair<int,int>,bool> m;
//
//void add_edge(int u,int v,int w)
//{
//    t[u].push_back(edge{v,w});
//}
//void break_edge(int u,int v,int w)
//{
//    for(int i = 0;i < t[u].size();i++){
//        if(t[u][i].v == v) m[{u,v}] = 1;
//    }
//}
//
//void dfs(int u)
//{
//
//    for(auto x:t[u]){
//        int v = x.v,w = x.w;
//        if(!vis[v]&&!m[{u,v}]){
//            ans += w;
//            vis[v] = 1;
//            dfs(v);
//            ans -= w;
//            vis[v] = 0;
//        }
//    }
//    out = max(ans,out);
//}
//int main()
//{
//    cin >> n >> k ;
//    int u,v,w;
//    for(int i = 0;i < n-1;i ++){
//        cin >> u >> v >> w;
//        ma[i+1] = {u,v,w};
//        m[{u,v}] = 0;
//        add_edge(u,v,w);
//    }
//
//    while(k --){
//        int op;cin >> op;
//        node tmp = ma[op];
//        break_edge(tmp.u,tmp.v,tmp.w);
//        memset(vis,0,sizeof(vis));
//        vis[1] = 1;ans = 0;
//        out = 0;
//        dfs(1);
//        cout << out << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e5+10;
//long long f[N];
//int a[N];int n;
//
//int main()
//{
//    cin >> n;
//    for(int i = 1;i <= n;i++)cin >> a[i];
//    sort(a + 1,a + n + 1);
//
//    f[2] = a[2];
//    for(int i = 3;i <= n;i++){
//        f[i] = min(f[i-1] + a[1] + a[i],f[i-2] + a[1] + a[i] + 2*a[2]);
//    }
//
//    cout << f[n] << endl;
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//typedef long long ll;
//const int mod = 1e9+7;
//const int N = 1e6;
//
//int t,n,m;
//ll sum,ans;
//ll f[N];
//
//int main()
//{
//    scanf("%d",&t);
//    while(t--){
//        ans = 0; sum = 0;
//        scanf("%d%d",&n,&m);
//        int tot = 1;
//        while(n != m){
//            if(n % 2 == 0) n /= 2;
//            else{
//                sum += tot;
//                tot <<= 1;
//                n += 1;
//                n >>= 1;
//            }
//        }
//        if(sum < 1e6){
//            f[1] = 1;f[2] = 2;f[3] = 3;
//            int tmp = 0;
//            for(int i = 1;i <= sum;i++){
//                if(i > 3)f[i] = (f[i-2] + f[i-3])%mod;
//                tmp = (tmp + f[i])%mod;
//                ans = (tmp + ans)%mod;
//            }
//            printf("%lld\n",ans);
//        }
//        else
//        printf("zjgqzt\n");
//    }
//    return 0;
//}
#include<iostream>
#include<map>
#include<vector>
#include<sstream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 55;

map<string,int> player;//记录选手id
map<string,int> sum;//记录每个人通过的总题数
map<char,pair<int,int> > cnt[N];//记录每个人每道题提交次数及所需时间
map<char,string> state[N];//记录每个人每道题的状态
map<string,int> time1;//记录每个人总罚时

char alp[] = {'A','B','C','D','E','F','G','H','I','J'};
string p[N];int n,m,k;

bool cmp(string a,string b){
    if(sum[a] == sum[b]){
        return time1[a]<time1[b];
    }
    return sum[a]>sum[b];
}

int main()
{
    cin >> n >> m >> k;

    for(int j = 1;j <= m;j++)
    for(int i = 0;i < n;i++){
        cnt[j][alp[i]].first = 0;
        cnt[j][alp[i]].second = 0;
    }

    for(int i = 1;i <= m;i++){
        getchar();
        cin >> p[i];
        sum[p[i]] = 0;
        player[p[i]] = i;
        time1[p[i]] = 0;
        for(int i = 0;i < n;i++){
            char ch = alp[i];
            state[player[p[i]]][ch] = "";
        }
    }
    for(int i = 1;i <= k;i++){
        string a,d;int b;char c;
        cin >> a;scanf("%d %c",&b,&c);cin >> d;
        if(state[player[a]][c][0] == 'C'){
            string st;
            getline(cin,st);
            continue;
        }
        cnt[player[a]][c].first ++;
        if(d[0] == 'C')
            cnt[player[a]][c].second += ((cnt[player[a]][c].first-1)*20+b),sum[a] ++;
//        cout << cnt[player[a]][c].second << endl;
//        cout << sum[a] << endl;
        state[player[a]][c] = d;
        string st;
        getline(cin,st);
    }

//    for(int i = 1;i <= m;i++){
//        string t = p[i];
//        for(int j = 0;j < n;j++){
//            char ch = alp[i];
////            cout << cnt[player[t]][ch].first << cnt[player[t]][ch].second << " ";
//        }
////        cout << endl ;
//    }

    for(int i = 1;i <= m;i++){
        string t = p[i];
        for(int j = 0;j < n;j++){
            char ch = alp[j];
            if(state[player[t]][ch][0] == 'C')
                time1[t] += cnt[player[t]][ch].second;
        }
    }

    sort(p+1,p+1+m,cmp);

    for(int i = 1;i <= m;i++){
        string t = p[i],out = p[i];
        cout<<"|";
        printf("%-8d",i);
        cout<<"|";
//        printf("%8s",t);
        int tmp = t.size();
        for(int i = 0;i < 8 - tmp;i++) t += ' ';
        cout<< t ;
        cout<<"|";
        printf("%-8d",sum[out]);
        cout<<"|";
        printf("%-8d",time1[out]);
        cout<<"|";
        for(int i = 0;i < n;i++){
            char ch = alp[i];
            if(cnt[player[out]][ch].first == 0){
                cout << "        |";
            }
            else{
                string st = "";
                if(state[player[out]][ch][0] == 'C'){
                    int temp = cnt[player[out]][ch].second;
                    stringstream ss; ss << temp;
                    string stt; ss >> stt;
                    st += stt;
                }
                st +='(';
                string stt;int temp = cnt[player[out]][ch].first;
                stringstream ss;ss << temp;
                ss >> stt;
                st += stt;
                st += ')';
                int tmp = st.length();
                for(int i = 0;i < 8 - tmp;i++){
                    st += " ";
                }
                cout << st << '|';
            }
        }
        cout << endl;
    }
    return 0;
}
















