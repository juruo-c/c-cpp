//
// Created by 19116 on 2021/4/1.
//

//#include<iostream>
//
//using namespace std;
//
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int n;cin >> n;
//        string s;
//        cin >> s;
//        for(int i = 0;i < s.size();i ++){
//            if(i){
//                if(s[i] + 1 == s[i - 1]) cout << 0;
//                else {
//                    cout << 1;
//                    s[i] = s[i] + 1;
//                }
//            }
//            else {
//                s[i] = s[i] + 1;
//                cout << 1;
//            }
//        }
//        cout << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//typedef long long ll;
//const int N = 1e5 + 10;
//int prime[N],cnt = 0;
//int bo[N];
//void isprime(){
//    bo[1] = 1;
//    for(int i = 2;i <= N;i ++){
//        if(!bo[i]){
//            prime[++ cnt] = i;
//            for(int j = i * 2;j <= N;j += i){
//                bo[j] = 1;
//            }
//        }
//    }
//}
//int main(){
//    int t;cin >> t;
//    isprime();
//    while(t --){
//        int d;cin >> d;
//        ll a = 0,b = 0;
//        for(int i = 1;i <= cnt;i ++){
//            if(prime[i] >= 1 + d && !a) a = prime[i];
//            if(prime[i] >= a + d && a) {
//                b = prime[i];
//                break;
//            }
//        }
//        cout << a * b << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<queue>
//#include<vector>
//
//using namespace std;
//typedef long long ll;
//int main(){
//    int n;cin >> n;
//    priority_queue<ll,vector<ll>,greater<ll> > q;
//    for(int i = 0;i < n;i ++){
//        int op;cin >> op;
//        if(op == 1){
//            int x;cin >> x;
//            q.push(x);
//        }
//        if(op == 2) cout << q.top() << endl;
//        if(op == 3) q.pop();
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//#include<vector>
//
//using namespace std;
//
//int main(){
//    priority_queue<int> q1;
//    priority_queue<int,vector<int>,greater<int> > q2;
//    int n;cin >> n;
//    int a;cin >> a;
//    q1.push(a);
//    cout << a << endl;
//    for(int i = 2;i <= n;i ++){
//        cin >> a;
//        if(a > q1.top()) q2.push(a);
//        else q1.push(a);
//        while(abs(int(q1.size() - q2.size())) > 1){
//            if(q1.size() > q2.size()){
//                q2.push(q1.top());
//                q1.pop();
//            }
//            else{
//                q1.push(q2.top());
//                q2.pop();
//            }
//        }
//        if(i % 2){
//            cout << (q1.size() > q2.size() ? q1.top() : q2.top()) << endl;
//        }
//    }
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//#include<vector>
//
//using namespace std;
//typedef long long ll;
//const int N = 5e4 + 10;
//bool vis[N];
//struct Cow{
//    ll p,c,no;
//}cow[N];
//struct cmpc{
//    bool operator()(const Cow& a,const Cow& b){
//        return a.c > b.c;
//    }
//};
//struct cmpp{
//    bool operator()(const Cow& a,const Cow& b){
//        return a.p > b.p;
//    }
//};
//struct cmppc{
//    bool operator()(const Cow& a,const Cow& b){
//        return a.p - a.c > b.p - b.c;
//    }
//};
//int main(){
//    priority_queue<Cow,vector<Cow>,cmpc> qc;
//    priority_queue<Cow,vector<Cow>,cmpp> qp;
//    priority_queue<Cow,vector<Cow>,cmppc> qpc;
//    ll n,k,m,ans = 0;
//    scanf("%lld%lld%lld",&n,&k,&m);
//    for(ll i = 1;i <= n;i ++){
//        scanf("%lld%lld",&cow[i].p,&cow[i].c);
//        cow[i].no = i;
//        qc.push(cow[i]);
//        qp.push(cow[i]);
//    }
//    for(ll i = 1;i <= min(n,k);i ++){
//        m -= qc.top().c;
//        if(m < 0){
//            printf("%lld",ans);
//            return 0;
//        }
//        vis[qc.top().no] = 1;
//        ans ++;
//        qpc.push(qc.top());
//        qc.pop();
//    }
//    for(ll i = k + 1;i <= n;i ++){
//        while(vis[qp.top().no]) qp.pop();
//        while(vis[qc.top().no]) qc.pop();
//        if(qp.top().p < qc.top().c + qpc.top().p - qpc.top().c){
//            m -= qp.top().p;
//            qpc.push(qp.top());
//            vis[qp.top().no] = 1;
//            qp.pop();
//        }
//        else{
//            m -= qc.top().c + qpc.top().p - qpc.top().c;
//            vis[qc.top().no] = 1;
//            qpc.pop();qc.pop();
//        }
//        if(m < 0) break;
//        ans ++;
//    }
//    cout << ans << endl;
//    return 0;
//}

//#include<algorithm>
//#include<cstdio>
//#include<cstring>
//#include<queue>
//
//using namespace std;
//const int N = 1e5 + 10;
//struct node{
//    int pos,val;
//    bool operator < (const node& b) const{
//        return val > b.val;
//    }
//}a;
//int A[N],B[N],C[N];
//int F[N];
//int n,m;
//
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 1;i <= n;i ++){
//        scanf("%d%d%d",&A[i],&B[i],&C[i]);
//        F[i] = 1;
//    }
//    priority_queue<node> q;
//    for(int i = 1;i <= n;i ++){
//        a.val = A[i] * F[i] * F[i] + B[i] * F[i] + C[i];
//        a.pos = i;
//        q.push(a);
//    }
//    for(int i = 1;i <= m;i ++){
//        cout << q.top().val << " ";
//        int t = q.top().pos;
//        q.pop();
//        F[t] ++;
//        node tt;
//        tt.pos = t;
//        tt.val = A[t] * F[t] * F[t] + B[t] * F[t] + C[t];
//        q.push(tt);
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<queue>
//
//using namespace std;
//const int N = 7e6 + 10;
//bool cmp(int a,int b){return a > b;}
//
//priority_queue<int> ans;
//int cut1[N],now[N],cut2[N];
//int n,m,q,u,v,t;
//int s;
//double p;
//int h0,h1,h2;
//int t0,t1,t2;
//
//int main(){
//    scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
//    p = (double) u / v;
//    for(t0 = 1;t0 <= n;t0 ++) scanf("%d",&now[t0]);
//    t0 --;t1 = t2 = 0;h0 = h1 = h2 = 1;
//    sort(now + 1,now + t0 + 1,cmp);
//    int top;
//    for(int i = 1;i <= m;i ++){
//        if(h0 > t0) top = (cut1[h1] > cut2[h2] ? cut1[h1 ++] : cut2[h2 ++]);
//        else if(now[h0] >= cut1[h1] && now[h0] >= cut2[h2]) top = now[h0 ++];
//        else if(cut1[h1] >= now[h0] && cut1[h1] >= cut2[h2]) top = cut1[h1 ++];
//        else top = cut2[h2 ++];
//        top += s;
//        int a1 = floor(p * (double) top),a2 = top - a1;
//        s += q;
//        a1 -= s,a2 -= s;
//        cut1[++ t1] = a1,cut2[++ t2] = a2;
//        if(i % t == 0) printf("%d ",top);
//    }
//    puts("");
//    for(int i = h0;i <= t0;i ++) ans.push(now[i]);
//    for(int i = h1;i <= t1;i ++) ans.push(cut1[i]);
//    for(int i = h2;i <= t2;i ++) ans.push(cut2[i]);
//
//    for(int i = 1;ans.size();i ++){
//        if(i % t == 0) printf("%d ",ans.top() + s);
//        ans.pop();
//    }
//    return 0;
//}
//

//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//#include<cstring>
//#include<queue>
//#include<vector>
//
//using namespace std;
//typedef long long ll;
//const int N = 5e4 + 10;
//int n,k;ll m;
//int p[N];
//struct node{
//    int val,pos;
//    bool operator < (const node& b) const{
//        return val < b.val;
//    }
//}c[N];
//int bo[N];
//
//int main(){
//    scanf("%d%d%lld",&n,&k,&m);
//    for(int i = 1;i <= n;i ++){
//        scanf("%d%d",&p[i],&c[i].val);
//        c[i].pos = i;
//    }
//    int ans = 0;
//    sort(c + 1,c + 1 + n);
//    sort(p + 1,p + 1 + n);
//    for(int i = 1;i <= k;i ++){
//        if(c[i].val <= m){
//            bo[c[i].pos] = 1;
//            ans ++;
//            m -= c[i].val;
//        }
//        else break;
//    }
//    if(!m) cout << ans << endl;
//    else{
//        for(int i = 1;i <= n;i ++){
//            if(!bo[i] && p[i] <= m){
//                ans ++;
//                m -= p[i];
//            }
//            else break;
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

//#include<string>
//
//using namespace std;
//class AcctABC{
//private:
//    string fullName;
//    long acctNum;
//    double balance;
//protected:
//    struct Formatting{
//        ios_base::fmtflags flag;
//        streamsize pr;
//    };
//    const string& FullName()const{return fullName;}
//    long AcctNum() const{return acctNum;}
//    Formatting SetFormat() const;
//    void Restore(Formatting & f) const;
//public:
//    AcctABC(const string& s = "Nullbody",long an = -1,double bal = 0.0);
//    void Deposit(double amt);
//    virtual void Withdraw(double amt) = 0;
//    double Balance() const{ return balance;}
//    virtual void ViewAcct() const = 0;
//    virtual ~AcctABC() {}
//};
//
//AcctABC::AcctABC(const string& s,long an,double bal){
//    fullName = s;
//    acctNum = an;
//    balance = bal;
//
//}
//void AcctABC::Deposit(double amt){
//    if(amt < 0){
//        cout << "Nagative deposit not allowed; "
//        << "deposit is cancelled." << endl;
//    }
//    else balance += amt;
//}
//void AcctABC::Withdraw(double amt) {
//    balance -= amt;
//}
//AcctABC::Formatting AcctABC::SetFormat() const{
//    Formatting f;
//    f.flag = cout.setf(ios_base::fixed,ios_base::floatfield);
//    f.pr = cout.precision(2);
//    return f;
//}
//void AcctABC::Restore(Formatting & f) const{
//    cout.setf(f.flag,ios_base::floatfield);
//    cout.precision(f.pr);
//}
//
////Brass Account Class
//class Brass : public AcctABC{
//public:
//    Brass(const string & s = "Nullbody",long an = -1,double bal = 0.0) : AcctABC(s,an,bal) {}
//    virtual void Withdraw(double amt);
//    virtual void ViewAcct() const;
//    virtual ~Brass(){}
//};
//
//void Brass::Withdraw(double amt){
//    if(amt < 0) cout << "Withdrawal amount must be positive; withdrawal canceled." << endl;
//    else if(amt <= Balance()) AcctABC::Withdraw(amt);
//    else cout << "Withdrawal amount of $" << amt <<" exceeds your balance" << endl << "Withdrawal canceled." << endl;
//}
//void Brass::ViewAcct() const{
//    Formatting f = SetFormat();
//    cout << "Brass Client: " << FullName() << endl;
//    cout << "Account Number: " << AcctNum() << endl;
//    cout << "Balance: $" << Balance() << endl;
//    Restore(f);
//}
//
////Brass Plus Account Class
//class BrassPlus : public AcctABC{
//private:
//    double maxLoan;
//    double rate;
//    double owesBank;
//public:
//    BrassPlus(const string & s = "Nullbody",long an = -1,double bal = 0.0,double ml = 500,double r = 0.10);
//    BrassPlus(const Brass & ba,double ml = 500,double r = 0.1);
//    virtual void ViewAcct () const;
//    virtual void Withdraw(double amt);
//    void ResetMax(double m){maxLoan = m;}
//    void ResetRate(double r){rate = r;}
//    void ResetOwes(){owesBank = 0;}
//};
//
//BrassPlus::BrassPlus(const string & s ,long an ,double bal ,double ml ,double r){
//    maxLoan = ml;
//    owesBank = 0.0;
//    rate = r;
//}
//BrassPlus::BrassPlus(const Brass & ba,double ml ,double r):AcctABC(ba){
//    maxLoan = ml;
//    owesBank = 0.0;
//    rate = r;
//}
//void BrassPlus::ViewAcct () const{
//    Formatting f = SetFormat();
//    cout << "BrassPlus Client: " << FullName() << endl;
//    cout << "Account Number: " << AcctNum() << endl;
//    cout << "Balance: $" << Balance() << endl;
//    cout << "Maximum loan: $" << maxLoan << endl;
//    cout << "Owed to bank: $" << owesBank << endl;
//    cout.precision(3);
//    cout << "Loan Rate: " << 100 * rate << endl;
//    Restore(f);
//}
//void BrassPlus::Withdraw(double amt){
//    Formatting f = SetFormat();
//    double bal = Balance();
//    if(amt <= bal) AcctABC::Withdraw(amt);
//    else if(amt <= bal + maxLoan - owesBank){
//        double advance = amt - bal;
//        owesBank += advance * (1.0 + rate);
//        cout << "Bank advance: $" << advance << endl;
//        cout << "Finance charge: $" << advance * rate << endl;
//        Deposit(advance);
//        AcctABC::Withdraw(amt);
//    }
//    else cout << "Credit limit exceeded. Transaction canceled." << endl;
//    Restore(f);
//}
//
//int main(){
//
//    return 0;
//}


//
//#include<iostream>
//#include<cstring>
//
//using namespace std;
//
//class baseDMA{
//private:
//    char * label;
//    int rating;
//
//public:
//    baseDMA(const char* l = "null", int r = 0);
//    baseDMA(const baseDMA & rs);
//    virtual ~baseDMA();
//    baseDMA& operator = (const baseDMA & rs);
//    friend ostream& operator << (ostream & os,const baseDMA& rs);
//};
//
//baseDMA::baseDMA(const char* l, int r){
//    label = new char[strlen(l) + 1];
//    strcpy(label,l);
//    rating = r;
//}
//baseDMA::baseDMA(const baseDMA & rs){
//    label = new char[strlen(rs.label) + 1];
//    strcpy(label,rs.label);
//    rating = rs.rating;
//}
//baseDMA::~baseDMA(){
//    delete [] label;
//}
//baseDMA& baseDMA:: operator = (const baseDMA & rs){
//    if(this == &rs) return *this;
//    delete [] label;
//    label = new char[strlen(rs.label) + 1];
//    strcpy(label, rs.label);
//    rating = rs.rating;
//    return *this;
//}
//ostream& operator << (ostream & os,const baseDMA& rs){
//    os << "Label: " << rs.label << endl;
//    os << "Rating: " << rs.rating << endl;
//    return os;
//}
//
//class lacksDMA : public baseDMA{
//private:
//    enum{COL_LEN = 40};
//    char color[COL_LEN];
//public:
//    lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
//    lacksDMA(const char * c, const baseDMA & rs);
//    friend ostream & operator << (ostream & os,const lacksDMA & rs);
//};
//
//lacksDMA::lacksDMA(const char * c, const char * l, int r) : baseDMA(l,r){
//    strncpy(color,c,39);
//    color[39] = '\0';
//}
//lacksDMA::lacksDMA(const char * c, const baseDMA & rs) : baseDMA(rs){
//    strncpy(color,c,COL_LEN - 1);
//    color[COL_LEN - 1] = '\0';
//}
//ostream & operator << (ostream & os,const lacksDMA & rs){
//    os << (const baseDMA &) rs;
//    os << "Color: " << rs.color << endl;
//    return os;
//}
//
//class hasDMA : public baseDMA{
//private:
//    char * style;
//public:
//     hasDMA(const char * s = "none", const char * l = "null", int r = 0);
//     hasDMA(const char * s, const baseDMA & rs);
//     hasDMA(const hasDMA & hs);
//     ~hasDMA();
//     hasDMA& operator = (const hasDMA & rs);
//     friend ostream & operator << (ostream & os,const hasDMA & rs);
//};
//
//hasDMA::hasDMA(const char * s , const char * l, int r ):baseDMA(l,r){
//    style = new char[strlen(s) + 1];
//    strcpy(style, s);
//}
//hasDMA::hasDMA(const char * s, const baseDMA & rs) : baseDMA(rs){
//    style = new char[strlen(s) + 1];
//    strcpy(style, s);
//}
//hasDMA::hasDMA(const hasDMA & hs) : baseDMA(hs){
//    style = new char[strlen(hs.style) + 1];
//    strcpy(style, hs.style);
//}
//hasDMA::~hasDMA(){
//    delete [] style;
//}
//hasDMA& hasDMA::operator = (const hasDMA & rs){
//    if(this == &rs) return *this;
//    baseDMA::operator = (rs);
//    delete[] style;
//    style = new char[strlen(rs.style) + 1];
//    strcpy(style, rs.style);
//    return *this;
//}
//ostream & operator << (ostream & os,const hasDMA & rs){
//    os << (const baseDMA &) rs;
//    os << "Style: " << rs.style << endl;
//    return os;
//}
//
//int main(){
//    baseDMA shirt("Portabelly", 8);
//    lacksDMA balloon("red", "Blimpo", 4);
//    hasDMA map("Mercator", "Buffalo Keys", 5);
//    cout << "Displaying baseDMA object:" << endl;
//    cout << shirt << endl;
//    cout << "Displaying lacksDMA object:" << endl;
//    cout << balloon << endl;
//    cout << "Displaying hasDMA object:" << endl;
//    cout << map << endl;
//    lacksDMA balloon2(balloon);
//    cout << "Result of lacksDMA copy: " << endl;
//    cout << balloon2 << endl;
//    hasDMA map2;
//    map2 = map;
//    cout << "Result of hasDMA assignment:" << endl;
//    cout << map2 << endl;
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//#include<cstring>
//#include<queue>
//#include<vector>
//
//using namespace std;
//typedef long long ll;
//const int N = 5e4 + 10;
//int n,k;ll m;
//struct node{
//    int val,pos;
//    bool operator < (const node& b) const{
//        return val < b.val;
//    }
//}p[N],c[N];
//int bo[N];
//
//int main(){
//    scanf("%d%d%lld",&n,&k,&m);
//    for(int i = 1;i <= n;i ++){
//        scanf("%d%d",&p[i].val,&c[i].val);
//        p[i].pos = c[i].pos = i;
//    }
//    int ans = 0;
//    sort(c + 1,c + 1 + n);
//    sort(p + 1,p + 1 + n);
//    for(int i = 1;i <= k;i ++){
//        if(c[i].val <= m){
//            bo[c[i].pos] = 1;
//            ans ++;
//            m -= c[i].val;
//        }
//        else break;
//    }
//    if(!m) cout << ans << endl;
//    else{
//        for(int i = 1;i <= n;i ++){
//            if(!bo[p[i].pos] && p[i].val <= m){
//                ans ++;
//                m -= p[i].val;
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main(){
//    string s;
//    while(getline(cin,s)){
//        cout << "NO" << endl;
//        cout.flush();
//    }
//    return 0;
//}

//#include<iostream>
//#include<cmath>
//
//using namespace std;
//int main(){
//    int n;cin >> n;
//    cout << (int)sqrt(n) << endl;
//    return 0;
//}

#include<iostream>

using namespace std;
int f[30];
bool bo[100000];
int main(){
    string s;
    f[1] = f[2] = 1;
    bo[1] = 1;
    for(int i = 3;i <= 25;i ++){
        f[i] = f[i - 1] + f[i - 2];
        bo[f[i]] = 1;
    }
    while(cin >> s){
        int ans = 0;
        for(int i = 0;i < s.size();i ++){
            ans += s[i];
        }
        cout << ans << endl;
        if(bo[ans]) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}