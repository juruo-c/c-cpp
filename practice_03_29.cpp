//
// Created by 19116 on 2021/3/29.
//

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
//typedef ios_base::fmtflags format;
//typedef streamsize precis;
//format setFormat();
//void restore(format f,precis p);
//
//Brass::Brass(const string & s,long an, double bal){
//    fullName = s;
//    acctNum = an;
//    balance = bal;
//}
//void Brass::Deposit(double amt) {
//    if(amt < 0) cout << "Negative deposit not allowed; " << "deposit is cancelled.\n";
//    else balance += amt;
//}
//void Brass::Withdraw(double amt) {
//    format initialState = setFormat();
//    precis prec = cout.precision(2);
//
//    if(amt < 0) cout << "Withdrawal amount must be positiv; " << "withdrawal canceled." << endl;
//    else if(amt <= balance) balance -= amt;
//    else cout << "Withdrawal amount of $" << amt
//    << " exceeds your balance." << endl << "Withdrawal canceled.\n";
//
//    restore(initialState, prec);
//}
//double Brass::Banlance() const{
//    return balance;
//}
//void Brass::ViewAcct() const {
//    format initialState = setFormat();
//    precis prec = cout.precision(2);
//    cout << "Client: " << fullName << endl;
//    cout << "Account Number: " << acctNum << endl;
//    cout << "Balance: $" << balance << endl;
//    restore(initialState, prec);
//}
//
//BrassPlus::BrassPlus(const string & s,long an,double bal,double ml,double r) : Brass(s,an,bal){
//    maxLoan = ml;
//    owesBank = 0.0;
//    rate = r;
//}
//BrassPlus::BrassPlus(const Brass & ba,double m1,double r) : Brass(ba){
//    maxLoan = m1;
//    owesBank = 0.0;
//    rate = r;
//}
//void BrassPlus::ViewAcct() const{
//    format initialState = setFormat();
//    precis prec = cout.precision(2);
//
//    Brass::ViewAcct();
//    cout << "Maximum loan: $" << maxLoan << endl;
//    cout << "Owed to bank: $" << owesBank << endl;
//    cout.precision(3);
//    cout << "Loan Rate: " << 100 * rate << "%\n";
//    restore(initialState, prec);
//}
//void BrassPlus::Withdraw(double amt) {
//    format initialState = setFormat();
//    precis prec = cout.precision(2);
//
//    double bal = Banlance();
//    if(amt <= bal) Brass::Withdraw(amt);
//    else if(amt <= bal + maxLoan - owesBank){
//        double advance = amt - bal;
//        owesBank += advance * (1.0 + rate);
//        cout << "Bank advance: $" << advance << endl;
//        cout << "Finance charge: $" << advance * rate << endl;
//        Deposit(advance);
//        Brass::Withdraw(amt);
//    }
//    else cout << "Credit limit exceeded. Transaction cancelled.\n";
//    restore(initialState, prec);
//}
//
//format setFormat(){
//    return cout.setf(ios_base::fixed,ios_base::floatfield);
//}
//void restore(format f,precis p){
//    cout.setf(f,ios_base::floatfield);
//    cout.precision(p);
//}
//
//void test01(){
//    Brass Piggy("Porcelot Pigg",381299,4000.00);
//    BrassPlus Hoggy("Horatio Hogg",382288,3000.00);
//    Piggy.ViewAcct();
//    cout << endl;
//    Hoggy.ViewAcct();
//    cout << endl;
//    cout << "Depositing $1000 into the Hogg Account: \n";
//    Hoggy.Deposit(1000.00);
//    cout << "New balance: $" << Hoggy.Banlance() << endl;
//    cout << "Withdrawing $4200 from the Pigg Account: \n";
//    Piggy.Withdraw(4200.00);
//    cout << "Pigg account balance: $" << Piggy.Banlance() << endl;
//    cout << "Withdrawing $4200 from the Hogg Account: \n";
//    Hoggy.Withdraw(4200.00);
//    Hoggy.ViewAcct();
//}
//const int CLIENTS = 4;
//void test02(){
//    Brass * p_client[CLIENTS];
//    string tmp;
//    long tmpnum;
//    double tmpbal;
//    char kind;
//
//    for(int i = 0;i < CLIENTS;i ++){
//        cout << "Enter client's name: ";
//        getline(cin,tmp);
//        cout << "Enter client's account number: ";
//        cin >> tmpnum;
//        cout << "Enter opening balance: $";
//        cin >> tmpbal;
//        cout << "Enter 1 for Brass Account or "
//        << "2 for BrassPlus Account: ";
//        while(cin >> kind && (kind != '1' && kind != '2'))
//            cout << "Enter either 1 or 2: ";
//        if(kind == '1')
//            p_client[i] = new Brass(tmp,tmpnum,tmpbal);
//        else{
//            double tmax,trate;
//            cout << "Enter the overdraft limit: $";
//            cin >> tmax;
//            cout << "Enter the interest rate "
//            << "as a decimal fraction: ";
//            cin >> trate;
//            p_client[i] = new BrassPlus(tmp,tmpnum,tmpbal,tmax,trate);
//        }
//        while(cin.get() != '\n') continue;
//    }
//    cout << endl;
//    for(int i = 0;i < CLIENTS; i ++){
//        p_client[i] -> ViewAcct();
//        cout << endl;
//    }
//
//    for(int i = 0;i < CLIENTS;i ++){
//        delete p_client[i];
//    }
//    cout << "Done.\n";
//}
//int main(){
//
//    test02();
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e5 + 10;
//int n,m;
//int d[N][N];
//int fa[N];
//int getf(int x,int dis){
//    if(x == fa[x]) return x;
//    int t = fa[x];
//    fa[x] = getf(fa[x],dis);
//    d[t][fa[x]] = min(d[t][fa[x]],dis);
//}
//int main(){
//
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 1e5 + 10;
//int n,q;int fa[N];
//int num[N];
//int ans[N];
//struct edge{
//    int u,v,w;
//    bool operator < (const edge& b)const{
//        return w > b.w;
//    }
//}e[N];
//struct node{
//    int k,v;
//    int id;
//    bool operator < (const node& b)const{
//        return k > b.k;
//    }
//}ask[N];
//
//int getf(int x){return x == fa[x] ? x : fa[x] = getf(fa[x]);}
//void add(int x,int y){
//    x = getf(x);
//    y = getf(y);
//    if(x != y){
//        fa[x] = y;
//        num[y] += num[x];
//    }
//}
//
//int main(){
//    cin >> n >> q;
//    for(int i = 1;i <= n;i ++){
//        fa[i] = i;
//        num[i] = 1;
//    }
//    for(int i = 1;i < n;i ++)
//        cin >> e[i].u >> e[i].v >> e[i].w;
//    for(int i = 1;i <= q;i ++){
//        cin >> ask[i].k >> ask[i].v;
//        ask[i].id = i;
//    }
//    sort(e + 1,e + n);
//    sort(ask + 1,ask + 1 + q);
//    int j = 1;
//    for(int i = 1;i <= q;i ++){
//        while(j < n && e[j].w >= ask[i].k){
//            add(e[j].u,e[j].v);
//            j ++;
//        }
//        ans[ask[i].id] = num[getf(ask[i].v)];
//    }
//    for(int i = 1;i <= q;i ++) cout << ans[i] - 1 << endl;
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//
//using namespace std;
//typedef long long ll;
//
//ll gcd(ll a,ll b){
//    return ! b ? a : gcd(b,a % b);
//}
//bool solve(ll n){
//    ll t = n;
//    ll ans = 0;
//    while(t){
//        ans += t % 10;
//        t /= 10;
//    }
//    return gcd(n,ans) > 1;
//}
//int main(){
//    int t;cin >> t;
//    while(t --){
//        ll n;scanf("%lld",&n);
//        while(true){
//            if(solve(n)) {
//                printf("%lld\n",n);
//                break;
//            }
//            n ++;
//        }
//    }
//    return 0;
//}

//
//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<queue>
//#include<vector>
//
//using namespace std;
//const int N = 1e5 + 10;
//int n,W;
//int w[N];
//int rest[N];
//int cnt;
//
//bool cmp(int a,int b){return a > b;}
//int main(){
//    int t;cin >> t;
//    while(t --){
//        cin >> n >> W;
//        for(int i = 1;i <= n;i ++) cin >> w[i];
//        sort(w + 1,w + n + 1,cmp);
//        cnt = 1;rest[1] = W;
//        priority_queue<int> q;
//        q.push(rest[1]);
//        for(int i = 1;i <= n;i ++){
//            int tt;
//            if(!q.empty()) {tt = q.top();q.pop();}
//            else tt = 0;
////            cout << tt << endl;
//            if(tt >= w[i]){
//                tt -= w[i];
//                if(tt) q.push(tt);
//            }
//            else{
//                if(tt) q.push(tt);
//                rest[++ cnt] = W - w[i];
//                if(rest[cnt]) q.push(rest[cnt]);
//            }
//        }
//        cout << cnt << endl;
//    }
//    return 0;
//}

