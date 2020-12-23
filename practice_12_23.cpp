//#include<iostream>
//#include<string>
//#include<sstream>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e5 + 10;
//int in_order[N], post_order[N], lch[N], rch[N];
//int n;
//
//bool read_list(int* a){
//    string line;
//    if(!getline(cin, line)) return false;
//    stringstream ss(line);
//    n = 0;
//    int x;
//    while(ss >> x) a[n ++] = x;
//    return n > 0;
//}
//
//int build(int l1,int r1,int l2,int r2)
//{
//    if(l1 > r1) return 0;
//    int root = post_order[r2];
//    int p = l1;
//    while(in_order[p] != root) p ++;
//    int cnt = p - l1;
//    lch[root] = build(l1,p - 1,l2,l2 + cnt - 1);
//    rch[root] = build(p + 1,r1,l2 + cnt,r2 - 1);
//    return root;
//}
//
//int best, best_sum;
//
//void dfs(int u,int sum)
//{
//    sum += u;
//    if(!lch[u] && !rch[u]){
//        if(sum < best_sum || (sum == best_sum && u < best)){
//            best = u;
//            best_sum = sum;
//        }
//    }
//    if(lch[u]) dfs(lch[u],sum);
//    if(rch[u]) dfs(rch[u],sum);
//}
//
//int main()
//{
//    while(read_list(in_order)){
//        read_list(post_order);
//        build(0,n - 1,0,n - 1);
//        best_sum = 0x3f3f3f3f;
//        dfs(post_order[n - 1],0);
//        cout << best << endl;
//    }
//    return 0;
//}
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<map>
//#include<vector>
//#include<sstream>
//#include<set>
//
//using namespace std;
//int hp = 6e6;
//int week = 1,boss = 1;
//int flag = 0;
//string peo;
//set<string> tree;
//
//int main()
//{
//    string s;
//    while(getline(cin,s)){
//        stringstream input(s);
//        string name; input >> name;
//        name = name.substr(0,name.length() - 1);
//        if(name == "robot") continue;
//        string op; input >> op;
//        if(op[0] == 'A' && !tree.count(name)){
//            if(flag){
//                cout << "robot: " << peo << "正在出刀,请勿进场!" << endl;
//            }
//            else{
//                cout << "robot: " << name << "成功申请出刀" << endl;
//                flag = 1;
//                peo = name;
//            }
//        }
//        else if(op[0] == 'T' && !tree.count(name)){
//            if(flag = 1 && peo == name) flag = 0;
//            tree.insert(name);
//        }
//        else if(op[0] == 'R' && !tree.count(name)){
//            if(name == peo) flag = 0;
//            int k ; input >> k;
//            hp -= k;
//            if(hp > 0){
//                cout << "robot: " << name << "出刀成功,伤害为" << k << ",当前BOSS血量为" << hp << ".\n";
//            }
//            else{
//                cout << "robot: " << name << "出刀成功,成功斩杀BOSS." << endl;
//                hp = 6e6;
//                boss ++;
//                if(boss > 7) boss = 1,week ++;
//                cout << "robot: 下树提醒: ";
//                for(auto x : tree){
//                    cout << "@" << x;
//                }
//                cout << endl;
//                tree.clear();
//                flag = 0;
//                peo = "";
//            }
//        }
//        else if(op[0] == 'Q'){
//            printf("robot: 状态: { 当前周目: %d BOSS编号: %d BOSSHp: %d; }\n",week,boss,hp);
//        }
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<sstream>
//#include<algorithm>
//#include<vector>
//#include<map>
//
//using namespace std;
//string titl,auth;
//struct book
//{
//    string til,aut;
//};
//vector<book> shel;
//vector<book> retu;
//map<string,string> name;//书名映射到作者名
//
//bool cmp(book a,book b)
//{
//    if(a.aut == b.aut)return a.til < b.til;
//    return a.aut < b.aut;
//}
//
//int main()
//{
//    string line;
//    while(getline(cin,line)){
//        if(line == "END")break;
//        stringstream input(line);
//        input >> titl;
//        titl = titl.substr(1,titl.length() - 2);
//        string st;
//        input >> st;
//        getline(input,auth);
//        name[titl] = auth;
//        shel.push_back(book{titl,auth});
//    }
//    sort(shel.begin(),shel.end(),cmp);
//    while(getline(cin,line)){
//        if(line == "END")break;
//        stringstream input(line);
//        string op;input >> op;
//        string bok;input >> bok;
//        bok = bok.substr(1,bok.length() - 2);
//        if(op[0] == 'B'){
//            book t = {bok,name[bok]};
//            int it;
//            for(int i = 0;i < shel.size();i ++){
//                if(shel[i] == t)
//                    it = i;
//            }
//            shel.erase(shel[it]);
//        }
//        else if(op[0] == 'R'){
//            retu.push_back(book{bok,name[bok]});
//            sort(retu.begin(),retu.end(),cmp);
//        }
//        else if(op[0] == 'S'){
//            for(auto x : retu){
//                shel.push_back(x);
//                sort(shel.begin(),shel.end(),cmp);
//                int it;
//                for(int i = 0;i < shel.size();i ++){
//
//                }
//                if(it == shel.begin()){
//                    cout << "Put \"" << (*it).til << "\"" << " first\n";
//                }
//                else{
//                    book pre = *(it - 1);
//                    cout << "Put \"" << (*it).til << "\"" << " after \"" << pre.til << "\"\n";
//                }
//            }
//            cout << "END" << endl;
//        }
//    }
//    return 0;
//}
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//int a[10];
//void Cin()
//{
//    for(int i = 0;i < 10;i ++) cin >> a[i];
//}
//
//void Swap()
//{
//    int maxx = a[0],minn = a[0];
//    int tm = 0,tn = 0;
//    for(int i = 0;i < 10;i ++){
//        if(maxx < a[i]){
//            maxx = a[i];
//            tm = i;
//        }
//    }
//    swap(a[tm],a[9]);
//    for(int i = 0;i < 10;i ++){
//        if(minn > a[i]){
//            minn = a[i];
//            tn = i;
//        }
//    }
//    swap(a[tn],a[0]);
//}
//
//void Cout()
//{
//    for(int i = 0;i < 10;i ++) cout << a[i] << " ";
//}
//
//int main()
//{
//    Cin();
//    Swap();
//    Cout();
//    return 0;
//}
//#include<iostream>
//#include<vector>
//
//using namespace std;
//vector<int> v1,v2;
//
//bool check(int a,int b)
//{
//    if(a == b)return false;
//    for(int i = 1;i < a;i ++){
//        if(a % i == 0) v1.push_back(i);
//    }
//    for(int i = 1;i < b;i ++){
//        if(b % i == 0) v2.push_back(i);
//    }
//    int sum1 = 0;
//    for(int i = 0;i < v1.size();i ++){
//        sum1 += v1[i];
//    }
//    if(sum1 != b) return false;
//    int sum2 = 0;
//    for(int i = 0;i < v2.size();i ++){
//        sum2 += v2[i];
//    }
//    if(sum2 != a) return false;
//    return true;
//}
//
//int main()
//{
//    int t;cin >> t;
//    while(t --){
//        v1.clear(),v2.clear();
//        int a,b;
//        cin >> a >> b;
//        if(check(a,b)) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}
//#include<iostream>
//
//using namespace std;
//int a[110],b[110];
//void merge_sort(int l,int r)
//{
//    if(l == r) return;
//    int m = (l + r) / 2;
//    merge_sort(l,m),merge_sort(m + 1,r);
//    int i = l,k = l,j = m + 1;
//    while(i <= m && j <= r){
//        if(a[i] > a[j]) b[k++] = a[j++];
//        else b[k++] = a[i++];
//    }
//    while(i <= m) b[k++] = a[i++];
//    while(j <= m) b[k++] = a[j++];
//    for(int t = l;t <= r;t ++) a[t] = b[t];
//}
//
//int main()
//{
//    int n;cin >> n;
//    for(int i = 0;i < n;i ++){
//        cin >> a[i];
//    }
//    merge_sort(0,n-1);
//    for(int i = 0;i < n;i ++){
//        cout << a[i];
//        if(i < n - 1) cout << " ";
//    }
//    cout << endl;
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//const int N = 1e3 + 10;
//int a[N],b[N];
//long long ans;int n;
//
//long long f()
//{
//    long long t = 0;
//    for(int i = 0;i < n;i ++){
//        t += a[i] * b[i];
//    }
//    return t;
//}
//
//int main()
//{
//    cin >> n;
//    for(int i = 0;i < n;i ++)cin >> a[i];
//    for(int i = 0;i < n;i ++) cin >> b[i];
//    ans = f();
//    cout << ans << endl;
//    return 0;
//}
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//string f(string s,int m)
//{
//    return s.substr(m - 1);
//}
//
//int main()
//{
//    int n,m;
//    string s;
//    cin >> n >> s >> m;
//    string ans = f(s,m);
//    cout << ans << endl;
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//
//using namespace std;
//
//void del_char(char a[],char ch)
//{
//    int i = 0;
//    while(i < strlen(a))
//    {
//        if(a[i] == ch){
//            for(int j = i;j < strlen(a);j ++){
//                a[j] = a[j + 1];
//            }
//        }
//        if(a[i] != ch)i ++;
//    }
//}
//
//int main()
//{
//    char ch;
//    char a[110];
//    cin >> ch >> a;
//    del_char(a,ch);
//    cout << a << endl;
//    return 0;
//}


//#include<iostream>
//#include<map>
//#include<set>
//#include<vector>
//#include<cstring>
//#include<algorithm>
//#include<sstream>
//
//using namespace std;
//struct Book
//{
//    string aut,tit;
//    bool operator < (const Book& b){
//        if(aut == b.aut) return tit < b.tit;
//        return aut < b.aut;
//    }
//}book;
//string s,st;
//vector<Book> bk;
//map<string,int> mp;
//
//int main()
//{
//    while(getline(cin,s) && s[0] != 'E'){
//        int i = s.find('"',1);
//        book.tit = s.substr(1,i - 1);
//        book.aut = s.substr(i + 5);
//        bk.push_back(book);
//    }
//    sort(bk.begin(),bk.end());
//    set<int> lib,ret;
//    for(int i = 0;i < bk.size();i ++){
//        mp[bk[i].tit] = i;
//        lib.insert(i);
//    }
//    while(getline(cin,s) && s[0] != 'E'){
//        if(s[0] == 'S'){
//            for(auto r : ret){
//                auto p = lib.find(r);
//                printf("Put \"%s\" ",bk[r].tit.c_str());
//                printf("%s\n", p == lib.begin() ? "first" : ("after \"" + bk[*(--p)].tit + "\"").c_str());
//            }
//            cout << "END" << endl;
//            ret.clear();
//            continue;
//        }
//        string op,tit;
//        op = s.substr(0,6);
//        tit = s.substr(8, s.size() - 8 - 1);
//        if(op[0] == 'B') lib.erase(mp[tit]);
//        else if(op[0] == 'R'){
//            ret.insert(mp[tit]);
//            lib.insert(mp[tit]);
//        }
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<sstream>
//
//using namespace std;
//
//const int N = 1e5 + 10;
//int in[N],post[N],lch[N],rch[N];
//int n,best,best_sum;
//
//bool read_list(int* a)
//{
//    string s;
//    if(!getline(cin,s)) return false;
//    stringstream ss(s);
//    n = 0;
//    int x;
//    while(ss >> x){
//        a[n ++] = x;
//    }
//    return n > 0;
//}
//
////把in[l1 ... r1] 和 post[l2 ... r2] 建成一颗二叉树
//int build(int l1,int r1,int l2,int r2)
//{
//    if(l1 > r1) return 0;
//    int root = post[r2];
//    int p = l1;
//    while(in[p] != root) p ++;
//    int cnt = p - l1;
//    lch[root] = build(l1,p - 1, l2, l2 + cnt - 1);
//    rch[root] = build(p + 1, r1,l2 + cnt, r2 - 1);
//    return root;
//}
//
//void dfs(int u,int sum)
//{
//    sum += u;
//    if(!lch[u] && !rch[u]){
//        if(sum < best_sum || (sum == best_sum && best > u))
//        {
//            best_sum = sum;
//            best = u;
//        }
//    }
//    if(lch[u]) dfs(lch[u], sum);
//    if(rch[u]) dfs(rch[u], sum);
//}
//int main()
//{
//    while(read_list(in)){
//        read_list(post);
//        build(0, n - 1,0 , n - 1);
//        best_sum = 0x3f3f3f3f;
//        dfs(post[n-1] , 0);
//        cout << best << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//bool solve(int& w)
//{
//    int w1,d1,w2,d2;
//    bool b1 = true,b2 = true;
//    cin >> w1 >> d1 >> w2 >> d2;
//    if(!w1) b1 = solve(w1);
//    if(!w2) b2 = solve(w2);
//    w = w1 + w2;
//    return b1 && b2 && (w1 * d1 == w2 * d2);
//}
//
//int main()
//{
//    int t,w;cin >> t;
//    while(t --){
//        if(solve(w)) cout << "YES\n";
//        else cout << "NO" << endl;
//        if(t) cout << endl;
//    }
//    return 0;
//}
//

//#include<iostream>
//#include<cstring>
//
//using namespace std;
//const int N = 210;
//int sum[N];
//
//void build(int p){
//    int v; cin >> v;
//    if(v == -1)return ;
//    sum[p] += v;
//    build(p - 1);build(p + 1);
//}
//
//bool init(){
//    int v;cin >> v;
//    if(v == -1) return false ;
//    memset(sum,0,sizeof(sum));
//    int pos = N / 2;
//    sum[pos] = v;
//    build(pos - 1);build(pos + 1);
//    return true;
//}
//
//int main()
//{
//    int kase = 0;
//    while(init()){
//        int p = 0;
//        while(sum[p] == 0) p ++;
//        cout << "Case " << ++kase << ":\n" << sum[p ++];
//        while(sum[p] != 0) cout << " " << sum[p ++];
//        cout << endl << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<cstdio>
//
//using namespace std;
//
//const int len = 32;
//const int N = 1024 + 10;
//char s[N];
//int buf[len][len], cnt;
//
//void draw(const char* s, int& p,int r,int c,int w)
//{
//    char ch = s[p ++];
//    if(ch == 'p'){
//        draw(s,p,r, c + w / 2, w / 2);
//        draw(s,p,r, c, w / 2);
//        draw(s,p,r + w / 2, c, w / 2);
//        draw(s,p,r + w / 2,c + w / 2,w / 2);
//    }
//    else if(ch == 'f'){
//        for(int i = r;i < r + w;i ++){
//            for(int j = c;j < c + w;j ++){
//                if(buf[i][j] == 0){
//                    buf[i][j] = 1;
//                    cnt ++;
//                }
//            }
//        }
//    }
//}
//
//int main()
//{
//    int t;cin >> t;
//    while(t -- ){
//        memset(buf,0,sizeof(buf));
//        cnt = 0;
//        for(int i = 0;i < 2;i ++){
//            cin >> s;
//            int p = 0;
//            draw(s,p,0,0,len);
//        }
//        printf("There are %d black pixels.\n",cnt);
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int H = 210;
//const int W = 60;
//char a[H][W];
//int b[H][W * 4];
//int n,m;
//bool vis[H][W * 4];
//
//int main()
//{
//    int kase = 0;
//    while(cin >> n >> m){
//        for(int i = 1;i <= n;i ++){
//            for(int j = 1;j <= m;j ++){
//                cin >> a[i][j];
//            }
//        }
//
//        for(int i = 1;i <= n;i ++){
//            for(int j = 1;j <= m;j ++){
//                if(a[i][j]){
//                    int t = a[i][j];
//                    int k = j * 4 + 3;
//                    while(t){
//                        b[i][k--] = t % 2;
//                        t /= 2;
//                    }
//                    while(k >= j * 4) b[i][k--] = 0;
//                }
//                else{
//                    for(int k = j * 4;k < j * 4 + 4;k ++)
//                        b[i][k] = 0;
//                }
//            }
//        }
//
//        dfs();
//    }
//    return 0;
//}

#include<bits/stdc++.h>

using namespace std;
int n,m;
string s,st,t1,t2;
map<string,vector<pair<int,int> > > mp;// 单词 -> （文章id，行号）
vector<string> doc[110];//文章

int main()
{
    cin >> n;getchar();
    for(int i = 0;i < n;i ++){
        int line = 0;
        while(getline(cin, s) && s[0] != '*'){
            doc[i].push_back(s);
            for(auto& ch : s){
                if(!isalpha(ch)) ch = ' ';//非字母转空格
                else ch = tolower(ch); //字母转小写
            }
            stringstream input(s);
            while(input >> s) mp[s].push_back({i,line});
            line ++;
        }
    }
    cin >> m;getchar();
    while(m -- ){
        getline(cin, s);
        int i = s.find(' '),j = s.rfind(' ');
        set<pair<int,int> > out;//输出集合
        if(i == string::npos) out.insert(mp[s].begin(),mp[s].end());
        else{
            if(s[0] == 'N'){
                t1 = s.substr(i + 1);
                set<int> _set;
                for(int i = 0;i < n;i ++) _set.insert(i);
                for(auto p : mp[t1]) _set.erase(p.first);
                for(auto p : _set){
                    for(auto line : doc[p]) cout << line << endl;
                    if(p != *_set.rbegin()) cout << "----------" << endl;
                }
                if(_set.empty())cout << "Sorry, I found nothing.\n";
            }
            else{
                t1 = s.substr(0, i);
                t2 = s.substr(j + 1);
                out.insert(mp[t1].begin(),mp[t1].end());
                out.insert(mp[t2].begin(),mp[t2].end());
                if(j - 1 - i == 3){
                    set<int> set1,set2;
                    for(auto p : mp[t1]) set1.insert(p.first);
                    for(auto p : mp[t2])
                        if(set1.find(p.first) != set1.end())
                        set2.insert(p.first);
                    auto tmp = out;
                    for(auto p : tmp)
                    if(set2.find(p.first) == set2.end()){
                        out.erase(p);
                    }
                }
            }
        }
        int pre = -1;
        if(s[0] != 'N'){
            for(auto p : out){
                if(pre != -1 && pre != p.first) cout << "----------" << endl;
                pre = p.first;
                cout << doc[p.first][p.second] << endl;
            }
            if(out.empty()) cout << "Sorry, I found nothing.\n";
        }
        cout << "===========" << endl;
    }
    return 0;
}









