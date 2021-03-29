//
// Created by 19116 on 2021/3/28.
//

//#include<iostream>
//#include<vector>
//#include<set>
//
//using namespace std;
//const int N = 1e5 + 10,inf = 1e5 + 10;
//int a[N];
//int main(){
//    int n;cin >> n;
//    a[0] = a[n + 1] = inf;
//    for(int i = 1;i <= n;i ++) cin >> a[i];
//    set<int> s;vector<int> ans;
//    for(int i = 1;i <= n;i ++){
//        if(a[i] < min(a[i - 1],a[i + 1])){
//            s.insert(i);
//            s.insert(i - 1);
//            s.insert(i + 1);
//            ans.push_back(i);
//        }
//    }
//    for(auto x : s){
//        if(x != 0 || x != n) {
//            cout << "? " << x << endl;
//            cout.flush();
//        }
//    }
//    for(auto x : ans){
//        cout << "! " << x << endl;
//        cout.flush();
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main(){
//    int t;cin >> t;
//    while(t --){
//        string s;
//        cin >> s;
//        int fl = 0;
//        int bo[55] = {0};
//        int len = s.size();
//        while(len --){
//            if(!fl){
//                int id = -1;
//                for(int i = 0;i < s.size();i ++){
//                    if(!bo[i]) {
//                        id = i;
//                        break;
//                    }
//                }
//                if(s[id] == 'a') s[id] = 'b';
//                else s[id] = 'a';
//                bo[id] = 1;
//                fl = 1;
//            }
//            else {
//                int id = -1;
//                for(int i = 0;i < s.size();i ++){
//                    if(!bo[i]) {
//                        id = i;
//                        break;
//                    }
//                }
//                if(s[id] == 'z') s[id] = 'y';
//                else s[id] = 'z';
//                bo[id] = 1;
//                fl = 0;
//            }
//        }
//        cout << s << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e5 + 10;
//typedef long long ll;
//struct node{
//    ll a,b;
//    bool operator < (const node& n) const {
//        return a < n.a;
//    }
//}no[N];
//int main(){
//    int t;cin >> t;
//    while(t --){
//        ll A,B,n;
//        cin >> A >> B >> n;
//        for(int i = 1;i <= n;i ++) cin >> no[i].a;
//        for(int i = 1;i <= n;i ++) cin >> no[i].b;
//        sort(no + 1,no + n + 1);
//        int dead = 0;
//        for(int i = 1;i <= n;i ++){
//            ll t1 = no[i].b / A;
//            if(no[i].b % A) t1 ++;
//            B -= t1 * no[i].a;
//            if((B < 0 && abs(B) >= no[i].a) || (B < 0 && i < n)){
//                dead = 1;
//                break;
//            }
//        }
//        if(dead) cout << "NO" << endl;
//        else cout << "YES" << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<string>
//
//using namespace std;
//class TableTennisPlayer{
//private:
//    string firstname;
//    string lastname;
//    bool hasTable;
//public:
//    TableTennisPlayer(const string & fn = "none",
//                      const string & ln = "none", bool ht = false);
//    void Name() const;
//    bool HasTable() const{return hasTable;}
//    void RestTable(bool v){hasTable = v;}
//};
//
//TableTennisPlayer::TableTennisPlayer(const string & fn ,
//                  const string & ln , bool ht ) : firstname(fn),lastname(ln),hasTable(ht){}
//void TableTennisPlayer::Name() const{
//    cout << lastname << ", " << firstname;
//}
//
//class RatedPlayer:public TableTennisPlayer{
//private:
//    unsigned int rating;
//public:
//    RatedPlayer(unsigned int r = 0, const string & fn = "none",
//                const string & ln = "none", bool ht = false);
//    RatedPlayer(unsigned int r, const TableTennisPlayer & tp);
//    unsigned int Rating() const {return rating;}
//    void ResetRating(unsigned int r){rating = r;}
//};
//
//
//
//RatedPlayer::RatedPlayer(unsigned int r , const string & fn ,
//                         const string & ln , bool ht ):TableTennisPlayer(fn,ln,ht){
//    rating = r;
//}
//RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp):TableTennisPlayer(tp),rating(r){}
//int main(){
//    TableTennisPlayer p1("Tara", "Boomdea",false);
//    RatedPlayer rp1(1140,"Mallory","Duck",true);
//    rp1.Name();
//    if(rp1.HasTable()) cout << ": has a table.\n" ;
//    else cout << ": hasn't a table." << endl;
//
//    p1.Name();
//    if(p1.HasTable()) cout << ": has a table.\n" ;
//    else cout << ": hasn't a table." << endl;
//
//    cout << "Name: ";
//    rp1.Name();
//    cout << "; Rating: " << rp1.Rating() << endl;
//    RatedPlayer rp2(1212,p1);
//    cout << "Name: ";
//    rp2.Name();
//    cout << "; Rating: " << rp2.Rating() << endl;
//
//    return 0;
//}


//#include<iostream>
//#include<stack>
//
//using namespace std;
//typedef long long ll;
//stack<char> st1,st2;
//int level(char n){
//    if(n == '+' || n == '-') return 1;
//    else if(n == '*' || n == '/') return 2;
//    else if(n == '^') return 3;
//    return 0;
//}
//
//int main(){
//    string s;
//    cin >> s;
//    for(int i = 0;i < s.size();i ++){
//        if(isdigit(s[i])) st2.push(s[i]);
//        else{
//            if(s[i] == '('){
//                st1.push(s[i]);
//                continue;
//            }
//            if(st1.top() == '(' || st1.empty()){
//                st1.push(s[i]);
//                continue;
//            }
//            if(level(st1.top()) >= level(s[i]) && s[i] != ')'){
//                st2.push(st1.top());
//                st1.pop();
//                while(level(st1.top()) >= level(s[i])){
//                    st2.push(st1.top());
//                    st1.pop();
//                }
//                st1.push(s[i]);
//                continue;
//            }
//            if(level(st1.top()) < level(s[i]) && s[i] != ')'){
//                st1.push(s[i]);
//                continue;
//            }
//            if(s[i] == ')'){
//                while(st1.top() != '('){
//                    st2.push(st1.top());
//                    st1.pop();
//                }
//                st1.pop();
//                continue;
//            }
//        }
//    }
//    while(!st1.empty()){
//        st2.push(st1.top());
//        st1.pop();
//    }
//    int i = st2.size() - 1;
//    int len = i;
//    cout << 1 << endl;
//    while(!st2.empty()){
//        s[i --] = st2.top();
//        st2.pop();
//    }
//
//    for(i = 0;i < len;i ++){
//        cout << s[i] << " ";
//    }
//    cout << endl;
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cmath>
//#include<cstring>
//
//using namespace std;
//const int N = 110;
//char s1[N],s2[N],a[N];
//int top1,top2,top3;
//int p;int s3[N];
//
//
//int level(char n){
//    if(n == '+' || n == '-') return 1;
//    if(n == '*' || n == '/') return 2;
//    if(n == '^') return 3;
//    return 0;
//}
//
//void print(){
//    for(int i = 1;i <= top3;i ++){
//        cout << s3[i] << " ";
//    }
//    for(int i = p + 1;i <= top2;i ++){
//        if(i != p + 1) cout << " ";
//        cout << s2[i];
//    }
//    cout << endl;
//}
//int main(){
//    int n;
//    scanf("%s",a);
//    n = strlen(a);
//    for(int i = 0;i < n;i ++){
//        if(isdigit(a[i])) s2[++ top2] = a[i];
//        else{
//            if(a[i] == '('){
//                s1[++ top1] = a[i];
//                continue;
//            }
//            if(s1[top1] == '(' || top1 == 0){
//                s1[++ top1] = a[i];
//                continue;
//            }
//            if(level(s1[top1]) >= level(a[i]) && a[i] != ')'){
//                s2[++ top2] = s1[top1 --];
//                while(level(s1[top1]) >= level(a[i])){
//                    s2[++ top2] = s1[top1 --];
//                }
//                s1[++ top1] = a[i];
//                continue;
//            }
//            if(level(s1[top1]) < level(a[i]) && a[i] != ')'){
//                s1[++ top1] = a[i];
//                continue;
//            }
//            if(a[i] == ')'){
//                while(s1[top1] != '('){
//                    s2[++ top2] = s1[top1 --];
//                }
//                top1 --;
//                continue;
//            }
//        }
//    }
//
//    while(top1){
//        s2[++ top2] = s1[top1 --];
//    }
//    for(int i = 1;i <= top2;i ++){
//        cout << s2[i] << " ";
//    }
//    cout << endl;
//
//    for(int i = 1;i <= top2;i ++){
//        p = i;
//        if(isdigit(s2[i])) s3[++ top3] = s2[i] - '0';
//        else{
//            if(s2[i] == '+'){
//                int t1 = s3[top3 --];
//                int t2 = s3[top3];
//                s3[top3] = t1 + t2;
//            }
//            else if(s2[i] == '-'){
//                int t1 = s3[top3 --];
//                int t2 = s3[top3];
//                s3[top3] = t2 - t1;
//            }
//            else if(s2[i] == '*'){
//                int t1 = s3[top3 --];
//                int t2 = s3[top3];
//                s3[top3] = t2 * t1;
//            }
//            else if(s2[i] == '/'){
//                int t1 = s3[top3 --];
//                int t2 = s3[top3];
//                s3[top3] = t2 / t1;
//            }
//            else if(s2[i] == '^'){
//                int t1 = s3[top3 --];
//                int t2 = s3[top3];
//                s3[top3] = pow(t2,t1);
//            }
//            print();
//        }
//    }
//    return 0;
//}


//#include<iostream>
//#include<queue>
//#include<set>
//
//using namespace std;
//const int N = 1010;
//int a[N];
//int main(){
//    int m,n;
//    cin >> m >> n;
//    queue<int> q;
//    set<int> s;
//    for(int i = 1;i <= n;i ++) cin >> a[i];
//    int ans = 0;
//    for(int i = 1;i <= n;i ++){
//        if(q.empty()){
//            s.insert(a[i]);
//            q.push(a[i]);
//            ans ++;
//            continue;
//        }
//        if(!s.count(a[i])){
//            ans ++;
//            if(q.size() == m){
//                s.erase(q.front());
//                q.pop();
//                q.push(a[i]);
//                s.insert(a[i]);
//            }
//            else{
//                s.insert(a[i]);
//                q.push(a[i]);
//            }
//        }
//    }
//
//    cout << ans << endl;
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<cstdio>
//
//using namespace std;
//const int N = 1010,M = 1e5 + 10;
//int n,m;
//struct edge{
//    int u,v,w;
//    bool operator < (const edge& b) const{
//        return w < b.w;
//    }
//}e[M];
//int fa[N];
//int getf(int x){return x == fa[x] ? x : fa[x] = getf(fa[x]);}
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 1;i <= n;i ++) fa[i] = i;
//    for(int i = 1;i <= m;i ++){
//        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
//    }
//    sort(e + 1,e + 1 + m);
//    int ans = 0;int cnt = 0;
//    for(int i = 1;i <= m;i ++){
//        int fu = getf(e[i].u);
//        int fv = getf(e[i].v);
//        if(fu != fv){
//            fa[fu] = fv;
//            cnt ++;
//            ans = max(ans,e[i].w);
//        }
//    }
//
//    if(cnt != n - 1) puts("-1");
//    else printf("%d\n",ans);
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<algorithm>
//
//using namespace std;
//const int N = 2e4 + 10,M = 1e5 + 10;
//int n,m;
//struct edge{
//    int u,v,w;
//    bool operator < (const edge& b) const{
//        return w > b.w;
//    }
//}e[M];
//int fa[N];int b[N];
//int getf(int x){return x == fa[x] ? x : fa[x] = getf(fa[x]);}
//void add(int x,int y){
//    x = getf(x);
//    y = getf(y);
//    fa[x] = y;
//}
//bool check(int x,int y){
//    x = getf(x);
//    y = getf(y);
//    if(x == y) return true;
//    return false;
//}
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 1;i <= n;i ++) fa[i] = i;
//    for(int i = 1;i <= m;i ++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
//    sort(e + 1,e + 1 + m);
//    for(int i = 1;i <= m + 1;i ++){
//        if(check(e[i].u,e[i].v)){printf("%d",e[i].w);break;}
//        else{
//            if(!b[e[i].u]) b[e[i].u] = e[i].v;
//            else add(b[e[i].u],e[i].v);
//            if(!b[e[i].v]) b[e[i].v] = e[i].u;
//            else add(b[e[i].v],e[i].u);
//        }
//    }
//    return 0;
//}


//#include<string>
//#include<iostream>
//
//using namespace std;
////Brass Account Class
//class Brass{
//    string fullName;
//    long acctNum;
//    double balance;
//public:
//    Brass(const string & s = "Nullbody",long an = -1, double bal = 0.0);
//    void Deposit(double amt);
//    virtual void Withdraw(double amt);
//    double Banlance() const;
//    virtual void ViewAcct() const;
//    virtual ~Brass(){}
//};
//
////Brass Plua Account Class
//class BrassPlus:public Brass{
//private:
//    double maxLoan;
//    double rate;
//    double owesBank;
//public:
//    BrassPlus(const string & s = "Nullbody",long an = -1,double bal = 0.0,double ml = 500,double r = 0.11125);
//    BrassPlus(const Brass & ba,double m1 = 500,double r = 0.11125);
//    virtual void ViewAcct() const;
//    virtual void Withdraw(double amt);
//    void ResetMax(double m){maxLoan = m;}
//    void ResetRate(double r){rate = r;}
//    void ResetOwes(){owesBank = 0;}
//};
//
//int main(){
//
//    return 0;
//}

