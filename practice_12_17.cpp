//#include<iostream>
//#include<string>
//#include<algorithm>
//
//using namespace std;
//
//const int maxn = 100+10;
//const int max_col = 60;
//
//string filenames[maxn];
//
//void print(const string& s,int len,char extra){
//    cout<<s;
//    for(int i = 0;i < len - s.length();i++){
//        cout<<extra;
//    }
//}
//
//int main()
//{
//    int n;
//    while(cin>>n){
//        int m = 0;
//        for(int i = 0;i < n;i++){
//            cin >> filenames[i];
//            m = max(m,(int)filenames[i].length());
//        }
//        int cols = (max_col - m)/(m + 2) + 1;
//        int rows = (n - 1)/cols + 1;
//        print("",60,'-');
//        cout<<endl;
//        sort(filenames,filenames+n);
//        for(int i = 0;i < rows;i++){
//            for(int j = 0;j < cols;j++){
//                int idx = j * rows + i;
//                if(idx < n)print(filenames[idx],j == cols - 1?m:m+2,' ');
//            }
//            cout<<endl;
//        }
//    }
//    return 0;
//}
//#include<iostream>
//#include<map>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<sstream>
//#include<vector>
//
//using namespace std;
//map<string,int> ma;
//int n,m;
//int get_id(string s){
//    if(ma.find(s) == ma.end())ma.insert({s,ma.size()});
//    return ma[s];
//}
//
//int main()
//{
//
//    while(cin>>n>>m){
//        ma.clear();vector<int> table[n+1];
//        getchar();string s,st;
//        for(int i=0;i<n;i++){
//            getline(cin,s);stringstream input(s);
//            while(getline(input,st,','))table[i].push_back(get_id(st));
//        }
//        bool flag = 1;
//        for(int i = 0;i < m-1&&flag;i++){
//            for(int j = i+1;j < m&&flag;j++){
//                map<pair<int,int>,int> pos;
//                for(int k = 0;k < n;k++){
//                    if(pos.find({table[k][i],table[k][j]}) == pos.end()){
//                        pos[{table[k][i],table[k][j]}] = k;
//                    }
//                    else{
//                        printf("NO\n%d %d\n%d %d\n",pos[{table[k][i],table[k][j]}]+1,k+1,i+1,j+1);
//                        flag = 0;
//                    }
//                }
//            }
//        }
//        if(flag)cout<<"YES"<<endl;
//    }
//    return 0;
//}
//#include<iostream>
//#include<sstream>
//
//using namespace std;
//
//string s,st;
//
//int main()
//{
//    getline(cin,s);stringstream input(s);
//    while(getline(input,st,',')){
//        cout<<st<<endl;
//    }
//    return 0;
//}
//#include<iostream>
//#include<string>
//#include<vector>
//#include<set>
//#include<map>
//
//using namespace std;
//
//void parse_address(const string& s,string& user,string& mta)
//{
//    int k = s.find('@');
//    user = s.substr(0,k);
//    mta = s.substr(k+1);
//}
//
//int main()
//{
//    int k;
//    string s,t,user1,user2,mta1,mta2;
//    set<string> addr;
//
//    while(cin>>s && s != "*"){
//        cin>>s>>k;
//        while(k--){
//            cin>>t;
//            addr.insert(t+"@"+s);
//        }
//    }
//
//    while(cin>>s&&s!="*"){
//        parse_address(s,user1,mta1);
//    }
//
//    vector<string> mta;
//    map<string,vector<string> > dest;
//    set<string> vis;
//    while(cin>>t&&t != "*"){
//        parse_address(t,user2,mta2);
//        if(vis.count(t))continue;
//        vis.insert(t);
//        if(!dest.count(mta2)){
//            mta.push_back(mta2);
//            dest[mta2] = vector<string>();
//        }
//        dest[mta2].push_back(t);
//    }
//    getline(cin,t);
//
//    string data;
//    while(getline(cin,t)&&t[0]!='*')data+="    "+t+"\n";
//
//    for(int i=0;i<mta.size();i++){
//        string mta2 = mta[i];
//        vector<string> users = dest[mta2];
//        cout<<"Connection between "<<mta1<<" and "<<mta2<<endl;
//        cout<<" HELO "<<mta1<<endl;cout<<" 250"<<endl;
//        cout<<" MALL FROM:<"<<s<<">\n";cout<<" 250"<<endl;
//        bool ok = 0;
//        for(int i = 0;i < users.size();i++){
//            cout<<" RCPT TO:<"<<users[i]<<">\n";
//            if(addr.count(users[i])){
//                ok = true;cout<<" 250\n";
//            }
//            else cout<<" 550\n";
//        }
//        if(ok){
//            cout<<" DATA\n";cout<<" 354\n";
//            cout<<data;
//            cout<<".\n";cout<<" 250\n";
//        }
//        cout<<" QUIT\n";cout<<" 221\n";
//    }
//    return 0;
//}
//#include<iostream>
//#include<cstring>
//#include<string>
//#include<vector>
//
//using namespace std;
//
//bool vis[10];
//vector<int> v;
//
//void dfs(int cur,int tot,int sum)
//{
//    if(cur == sum)return;
//    if(tot == sum){
//        for(int i = 0;i < v.size();i++){
//            if(!i)
//            cout<<v[i];
//            else cout<<"+"<<v[i];
//        }
//        cout<<endl;
//        return;
//    }
//    if(tot > sum) return;
//    for(int i=cur;i<=sum - tot;i++){
//            v.push_back(i);
//            dfs(i,tot+i,sum);
//            v.pop_back();
//    }
//}
//
//int main()
//{
//    int n;
//    cin>>n;
//    dfs(1,0,n);
//    return 0;
//}

//#include<iostream>
//#include<string>
//#include<cstring>
//#include<queue>
//#include<map>
//
//using namespace std;
//
//const int maxn = 15;
//struct node
//{
//    string str;
//    int st;
//};
//
//string a,b;
//string org[maxn],tran[maxn];
//int n,ans;
//map<string,int> ma;
//
//string trans(const string& str,int i,int j){
//    string ans = "";
//    if(i+org[j].length()>str.length())return ans;
//    for(int k = 0;k < org[j].length();k++){
//        if(str[i+k] != org[j][k])return ans;
//    }
//    ans = str.substr(0,i);
//    ans += tran[j];
//    ans += str.substr(i+org[j].length());
//    return ans;
//}
//
//void bfs()
//{
//    queue<node> q;
//    node cur;
//    cur.str = a;
//    cur.st = 0;
//    q.push(cur);
//
//    while(!q.empty()){
//        cur = q.front();
//        q.pop();
//        string tmp;
//
//        if(ma.count(cur.str))continue;
//        if(cur.str == b){
//            ans = cur.st;
//            break;
//        }
//        ma[cur.str] = 1;
//        for(int i = 0;i < cur.str.length();i++){
//            for(int j = 0;j < n;j++){
//                tmp = trans(cur.str,i,j);
//                if(tmp != ""){
//                    node next;
//                    next.str = tmp;
//                    next.st = cur.st + 1;
//                    q.push(next);
//                }
//            }
//        }
//    }
//    if(ans>10||ans== 0)cout<<"NO ANSWER!"<<endl;
//    else cout<<ans<<endl;
//}
//int main()
//{
//    cin>>a>>b;
//    while(cin>>org[n]>>tran[n])n++;
//    bfs();
//    return 0;
//}
//#include<iostream>
//
//using namespace std;
//
//const int N = 110;
//
//int n,m;
//int v[N],w[N],s[N];
//int f[N][N];
//
//int main()
//{
//    cin >> n >> m;
//    for(int i = 1;i <= n;i++)cin >> v[i] >> w[i] >> s[i];
//
//    for(int i = 1;i <= n;i++){
//        for(int j = v[i];j <= m;j++){
//            f[i][j] = max(f[i][j],f[i - 1][j]);
//            for(int k = 1;k <= s[i];k++){
//                f[i][j] = max(f[i][j], f[i - 1][j - k*v[i]] + k*w[i]);
//            }
//        }
//    }
//
//    cout << f[n][m] << endl;
//
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 1e7+10;
//int n,m;
//int v[N],w[N];
//long long f[N];
//
//int main()
//{
//    cin >> m >> n;
//    for(int i = 1;i <= n;i++)cin >> v[i] >> w[i];
//
//    for(int i = 1;i <= n;i++){
//        for(int j = v[i];j <= m;j++){
//            f[j] = max(f[j],f[j-v[i]] + w[i]);
//        }
//    }
//
//    cout << f[m] << endl;
//    return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string>
//#include<sstream>
//#include<cstring>
//
//using namespace std;
//
//const int N =1010;
//
//string s,st;
//vector<string> lines[N];
//int row,maxcol[N];
//
//int main()
//{
//    while(getline(cin,s)){
//        stringstream input(s);
//        while(input>>st){
//            maxcol[lines[row].size()] = max(maxcol[lines[row].size()],(int)st.size());
//            lines[row].push_back(st);
//        }
//        row ++;
//    }
//    for(int i = 0;i < row;i ++ ){
//        for(int j = 0;j < lines[i].size();j ++){
//            st = lines[i][j];
//            if( j != lines[i].size()-1) st += string(maxcol[j]-st.size()+1,' ');
//            printf("%s",st.c_str());
//        }
//        puts("");
//    }
//    return 0;
//}

#include<iostream>
#include<set>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 20;

int a[N];
int n;
string st;
set<string> s;

string f()
{
    string ans = "";
    for(int i = 0;i < n;i++){
        if(a[i] < 10){
            char t = a[i] + '0';
            ans += t;
        }
        else{
            string t = "";
            char c;
            int tmp = a[i];
            while(tmp){
                c = tmp%10 + '0';
                tmp /= 10;
                t += c;
            }
            reverse(t.begin(),t.end());
            ans += t;
        }

    }
    return ans;
}

int main()
{
    int t;cin >> t;
    while(t--){
        s.clear();
        cin >> n;
        string s_zero = "";
        for(int i = 0;i < n;i++)s_zero += '0';
//        cout << s_zero << endl;
        for(int i = 0;i < n;i ++){
            cin >> a[i];
        }
        st = f();
//        cout << st << endl;
        s.insert(st);
        for(int j = 0;j < 1000;j ++){
            int tmp = a[n-1];
            a[n-1] -= a[0];a[n-1] = abs(a[n-1]);
            for(int i = 0;i < n-2;i ++){
                a[i] = abs(a[i] - a[i + 1]);
            }
            a[n-2] = abs(a[n - 2] - tmp);
//            for(int k = 0;k < n; k++)cout << a[k] << " ";
            st = f();
//            cout << st << endl;
            if(st == s_zero){cout << "ZERO" << endl;break;}
            if(s.count(st)){cout << "LOOP" << endl;break;}
            else s.insert(st);
        }
    }
    return 0;
}








