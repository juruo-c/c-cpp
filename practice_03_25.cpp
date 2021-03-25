//
// Created by 19116 on 2021/3/25.
//

//#include<iostream>
//#include<set>
//#include<vector>
//
//using namespace std;
//
//const int N = 1e5 + 10;
//
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int n;cin >> n;
//        int a[N] = {0};int c[N] = {0};
//        for(int i = 1;i <= n;i ++) {
//            cin >> a[i];
//            c[i] = a[i] - a[i - 1];
//        }
//        set<int> s;
//        int cnt = 0;
//        for(int i = 2;i <= n;i ++){
//            if(!s.count(c[i])){
//                cnt ++;
//                s.insert(c[i]);
//            }
//        }
//        if(cnt > 2) cout << -1 << endl;
//        else if(! cnt) cout << 0 << endl;
//        else{
//            vector<int> v;
//            for(auto x : s) v.push_back(x);
//
//        }
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 1e5 + 10;
//int a[N];
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int n;cin >> n;
//        for(int i = 1;i <= n;i ++) cin >> a[i];
//        int fl = 1;
//        for(int i = 1;i < n;i ++){
//            if(a[i] != a[i + 1]) {
//                fl = 0;
//                break;
//            }
//        }
//        if(fl) {
//            cout << 0 << endl;
//            continue;
//        }
//        fl = 1;
//        int f1 = 0,f2 = 0;
//        int c1,c2;
//        int maxn = a[n];
//        for(int i = 1;i < n;i ++){
//            maxn = max(maxn,a[i]);
//            if(a[i] < a[i + 1]){
//                if(f1 && c1 != a[i + 1] - a[i]){
//                    cout << -1 << endl;
//                    fl = 0;
//                    break;
//                }
//                f1 = 1;
//                c1 = a[i + 1] - a[i];
//            }
//            else{
//                if(f2 && c2 != a[i] - a[i + 1]){
//                    cout << - 1 << endl;
//                    fl = 0;
//                    break;
//                }
//                f2 = 1;
//                c2 = a[i] - a[i + 1];
//            }
//        }
//        if(!fl) continue;
//        if(!f1 || !f2) {
//            cout << 0 << endl;
//            continue;
//        }
//        if(c1 + c2 <= maxn){
//            cout << -1 << endl;
//            continue;
//        }
//        cout << c1 + c2 << " " << c1 << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//const int N = 2e5 + 10;
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int n;cin >> n;
//        int c[N] = {0};
//        for(int i = 1;i <= n;i ++){
//            int a;
//            cin >> a;
//            if(a){
//                c[max(1,i - a + 1)] ++;
//                c[i + 1] --;
//            }
//
//        }
////        for(int i = 1;i <= n;i ++) cout << c[i] << " " ;
////        cout << endl;
//        for(int i = 1;i <= n;i ++){
//            c[i] += c[i - 1];
//        }
//        for(int i = 1;i <= n;i ++) if(c[i]) c[i] = 1;
//        for(int i = 1;i <= n;i ++) cout << c[i] << " ";
//        cout << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdlib>
//#include<ctime>
//
//using namespace std;
//const int MIN_PER_HR = 60;
//bool newcustomer(double x){
//    return (rand() * x / RAND_MAX < 1);
//}
//
//class Customer{
//private:
//    long arrive;
//    int processtime;
//public:
//    Customer(){arrive = processtime = 0;}
//    void set(long when);
//    long when() const{return arrive;}
//    int ptime() const{return processtime;}
//};
//
//typedef Customer Item;
//class Queue{
//private:
//    struct node{Item item;struct node* next;};
//    enum{Q_SIZE = 10};
//    node* front;
//    node* rear;
//    int items;
//    const int qsize;
//    Queue(const Queue& q) : qsize(0){}
//    Queue & operator = (const Queue& q){return *this;}
//
//public:
//    Queue(int qs = Q_SIZE);
//    ~Queue();
//    bool isempty()const;
//    bool isfull() const;
//    int queuecount() const;
//    bool enqueue(const Item &item);
//    bool dequeue(Item &item);
//};
//Queue::Queue(int qs) : qsize(qs){
//    front = rear = NULL;
//    items = 0;
//}
//Queue::~Queue(){
//    node* tmp;
//    while(front != rear){
//         tmp = front;
//         front = front -> next;
//         delete tmp;
//    }
//}
//bool Queue::isempty()const{
//    return items == 0;
//}
//bool Queue::isfull() const{
//    return items == qsize;
//}
//int Queue::queuecount() const{
//    return items;
//}
//bool Queue::enqueue(const Item &item){
//    if(isfull()){
//        return false;
//    }
//    node* add = new node;
//    add->item = item;
//    add->next = NULL;
//    items ++;
//    if(front == NULL) front = add;
//    else rear->next = add;
//    rear = add;
//    return true;
//}
//bool Queue::dequeue(Item &item){
//    if(isempty()){
//        return false;
//    }
//    item = front->item;
//    items --;
//    node* tmp = front;
//    front = front->next;
//    delete tmp;
//    if(items == 0)rear = NULL;
//    return true;
//}
//
//void Customer::set(long when){
//    processtime = rand() % 3 + 1;
//    arrive = when;
//}
//
//int main(){
//    srand(time(0));
//    cout << "Case Study: Bank of Heather Automatic Teller" << endl;
//    cout << "Enter maximum size of queue: ";
//    int qs;
//    cin >> qs;
//    Queue line(qs);
//
//    cout << "Enter the number of simulation hours: ";
//    int hours;
//    cin >> hours;
//    long cyclelimit = MIN_PER_HR * hours;
//
//    cout << "Enter the average number of customers per hour: ";
//    double perhour;
//    cin >> perhour;
//    double min_per_cust;
//    min_per_cust = MIN_PER_HR / perhour;
//
//    Item tmp;
//    long turnaways = 0;
//    long customers = 0;
//    long served = 0;
//    long sum_line = 0;
//    int wait_time = 0;
//    long line_wait = 0;
//
//    for(int cycle = 0;cycle < cyclelimit;cycle ++){
//        if(newcustomer(min_per_cust)){
//            if(line.isfull()) turnaways ++;
//            else {
//                customers ++;
//                tmp.set(cycle);
//                line.enqueue(tmp);
//            }
//        }
//        if(wait_time <= 0 && !line.isempty()){
//            line.dequeue(tmp);
//            wait_time = tmp.ptime();
//            line_wait += cycle - tmp.when();
//            served ++;
//        }
//        if(wait_time > 0) wait_time --;
//        sum_line += line.queuecount();
//    }
//    if(customers > 0){
//        cout << "customers accepted: " << customers << endl;
//        cout << "  customers served: " << served << endl;
//        cout << "         turnaways: " << turnaways << endl;
//        cout << "average queue size: ";
//        cout.precision(2);
//        cout.setf(ios_base::fixed,ios_base::floatfield);
//        cout << (double) sum_line / cyclelimit << endl;
//        cout << " average wait time: " << (double) line_wait / served << " minutes\n";
//    }
//    else{
//        cout << "NO customers!\n";
//    }
//
//    cout << "Done!" << endl;
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//class CAccount{
//    long account;
//    char name[10];
//    float balance;
//public:
//    void getaccount(){cin >> account;}
//    void getname(){cin >> name;}
//    void getbal(){cin >> balance;}
//    void deposit(float num);
//    void withdraw(float num);
//    void check();
//};
//void CAccount::deposit(float num){
//    balance += num;
//    cout << "saving ok!" << endl;
//}
//void CAccount::withdraw(float num){
//    if(num > balance) {
//        cout << "sorry! over limit!" << endl;
//        return;
//    }
//    balance -= num;
//    cout << "withdraw ok!" << endl;
//}
//void CAccount::check(){
//    cout << name << "'s balance is " << (int)balance << endl;
//}
//int main(){
//    CAccount a,b;
//    a.getaccount();a.getname();a.getbal();
//    int n1,n2;
//    cin >> n1 >> n2;
//    a.check();a.deposit(n1);a.check();a.withdraw(n2);a.check();
//    b.getaccount();b.getname();b.getbal();
//    cin >> n1 >> n2;
//    b.check();b.deposit(n1);b.check();b.withdraw(n2);b.check();
//    return 0;
//}



//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//class C{
//public:
//    int a[7];
//}p[110];
//int main(){
//    int n;cin >> n;
//    string name;cin >> name;
//    for(int i = 0;i < n;i ++){
//        for(int j = 0;j < 7;j ++){
//            cin >> p[i].a[j];
//        }
//    }
//    C t;
//    for(int i = 0;i < 7;i ++) cin >> t.a[i];
//    for(int i = 0;i < n;i ++){
//        int cnt = 0;
//        for(int j = 0;j < 7;j ++){
//            if(p[i].a[j] == t.a[j]) cnt ++;
//        }
//        if(cnt == 7) cout << "恭喜" << name << "中了" << i + 1 << "注一等奖！" << endl;
//        else if(cnt == 5 || cnt == 6) cout << "恭喜" << name << "中了" << i + 1 << "注二等奖！" << endl;
//        else if(cnt >= 2 && cnt < 5) cout << "恭喜" << name << "中了" << i + 1 << "注三等奖！" << endl;
//    }
//    return 0;
//}


//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//class Stack{
//public:
//    Stack();
//    Stack(int s);
//    int get(int index);
//    void push(int n);
//    int isempty();
//    int isfull();
//    int pop();
//    ~Stack();
//private:
//    int *a;
//    int size;
//    int top;
//};
//Stack::Stack(){
//    size = 10;
//    a = new int[size];
//    top = 0;
//}
//Stack::Stack(int s){
//    size = s;
//    a = new int[size];
//    top = 0;
//    cout << "Constructor." << endl;
//}
//
//int Stack::get(int index){
//    return a[index - 1];
//}
//void Stack::push(int n){
//    a[top ++] = n;
//}
//int Stack::isempty(){
//    return top == 0;
//}
//int Stack::isfull(){
//    return top == size;
//}
//int Stack::pop(){
//    return a[-- top];
//}
//Stack::~Stack(){
//    delete[] a;
//    a = NULL;
//    cout << "Destructor." << endl;
//}
//
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int n;cin >> n;
//        Stack stk(n);
//        for(int i = 0;i < n;i ++){
//            int a;cin >> a;
//            stk.push(a);
//        }
//        for(int i = 0;i < n;i ++){
//            if(i) cout << " ";
//            cout << stk.pop();
//        }
//        cout << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<iomanip>
//#define db double
//using namespace std;
//class pt{
//    db x,y;
//public:
//    pt();
//    pt(db x,db y);
//    pt(pt& b){x = b.getx(); y = b.gety();}
//    db getx();
//    db gety();
//    void setxy(db x1,db y1);
//    void setx(db x1);
//    void sety(db y1);
//    db getdisto( pt& p) ;
//    ~pt(){cout << "Distructor." << endl;}
//};
//pt::pt(){x = y = 0;cout << "Constructor." << endl;}
//pt::pt(db x,db y) : x(x),y(y){}
//db pt::getx(){return x;}
//db pt::gety(){return y;}
//void pt::setxy(db x1,db y1){x = x1;y = y1;}
//void pt::setx(db x1){x = x1;}
//void pt::sety(db y1){y = y1;}
//db pt::getdisto(pt& p){return sqrt((x - p.getx()) * (x - p.getx()) + (y - p.gety()) * (y - p.gety()));}
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int n;cin >> n;
//        pt* p = new pt[n];
//        for(int i = 0;i < n;i ++){
//            int x,y;cin >> x >> y;
//            p[i].setxy(x,y);
//        }
//        db dis = 0;
//        int id1,id2;
//        for(int i = 0;i < n;i ++){
//            for(int j = i;j < n;j ++){
//                db tmp = p[i].getdisto(p[j]);
//                if(tmp > dis){
//                    dis = tmp;
//                    id1 = i;
//                    id2 = j;
//                }
//            }
//        }
//        cout << "The longeset distance is " << fixed << setprecision(2) << dis ;
//        cout << ",between p[" << id1 << "] and p[" << id2 << "].\n";
//        delete[] p;
//        p = NULL;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//const int N = 110;
//int n,m,t;
//int stx,sty,edx,edy;
//char a[N][N];
//struct node{
//    int x,y,st;
//};
//int vis[N][N][20];
//int dir[4][2] = {1,0,-1,0,0,1,0,-1};
//void bfs(){
//    queue<node> q;
//    node cur,next;
//    cur.x = stx,cur.y = sty,cur.st = 0;
//    q.push(cur);
//    vis[stx][sty][cur.st] = 1;
//    while(!q.empty()){
//        cur = q.front();q.pop();
//        for(int i = 0;i < 4;i ++){
//            int tx = dir[i][0] + cur.x;
//            int ty = dir[i][1] + cur.y;
//            next.st = cur.st + 1;
//            if(vis[tx][ty][next.st]){
//                vis[tx][ty][next.st] += vis[cur.x][cur.y][cur.st];
//                continue;
//            }
//            if(tx < 1 || ty < 1 || tx > n || ty > m || a[tx][ty] == '*' || next.st > t) continue;
//            next.x = tx,next.y = ty;
//            vis[tx][ty][next.st] += vis[cur.x][cur.y][cur.st];
//            q.push(next);
//        }
//    }
//}
//int main(){
//    cin >> n >> m >> t;
//    for(int i = 1;i <= n;i ++){
//        for(int j = 1;j <= m;j ++){
//            cin >> a[i][j];
//        }
//    }
//    cin >> stx >> sty >> edx >> edy;
//    bfs();
//    cout << vis[edx][edy][t] << endl;
//    return 0;
//}


//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 110;
//int n,m;
//int a[N][N];
//int dp[N][N];
//int ans;
//int dir[4][2] = {1,0,-1,0,0,-1,0,1};
//int dfs(int x,int y){
//    if(dp[x][y]) return dp[x][y];
//    dp[x][y] = 1;
//    for(int i = 0;i < 4;i ++){
//        int tx = x + dir[i][0];
//        int ty = y + dir[i][1];
//        if(tx < 1 || tx > n || ty < 1 || ty > m || a[tx][ty] >= a[x][y]) continue;
//        dfs(tx,ty);
//        dp[x][y] = max(dp[x][y],dp[tx][ty] + 1);
//    }
//    return dp[x][y];
//}
//int main(){
//    cin >> n >> m;
//    for(int i = 1;i <= n;i ++){
//        for(int j = 1;j <= m;j ++){
//            cin >> a[i][j];
//        }
//    }
//    for(int i = 1;i <= n;i ++){
//        for(int j = 1;j <= m;j ++){
//            if(!dp[i][j]) dfs(i,j);
//            ans = max(ans,dp[i][j]);
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}


//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 510;
//int n,m;int a[N][N];
//int dp[N][N];
//int dir[4][2] = {1,0,-1,0,0,1,0,-1};
//int dfs(int x,int y){
//    if(dp[x][y]) return dp[x][y];
//    dp[x][y] = x;
//    for(int i = 0;i < 4;i ++){
//        int tx = x + dir[i][0];
//        int ty = y + dir[i][1];
//        if(tx < 1 || tx > n || ty < 1 || ty > m || a[tx][ty] <= a[x][y]) continue;
//        dfs(tx,ty);
//        dp[x][y] = min(dp[x][y],dp[tx][ty]);
//    }
//    return dp[x][y];
//}
//int main(){
//    cin >> n >> m;
//    for(int i = 1;i <= n;i ++){
//        for(int j = 1;j <= m;j ++){
//            cin >> a[i][j];
//        }
//    }
//
//    for(int i = 1;i <= m;i ++){
//        if(!dp[n][i]) dfs(n,i);
//    }
//    int fl = 0;int cnt = 0;
//    for(int i = 1;i <= m;i ++){
//        if(dp[n][i] != 1){
//            fl = 1;
//            cnt ++;
//        }
//    }
//    if(fl){
//        cout << 0 << endl << cnt << endl;
//        return 0;
//    }
//
//
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//
//using namespace std;
//typedef long long ll;
//int main(){
//    int t;cin >> t;
//    while(t --){
//        ll n,m;
//        cin >> n >> m;
//        ll x;cin >> x;
//        if(x == 1ll){
//            cout << 1 << endl;
//            continue;
//        }
//        ll c = x / n;
//        if(x % n) c ++;
//        ll r = x - (c - 1) * n;
//        cout << m * (r - 1) + c << endl;
//    }
//    return 0;
//}
//

#include<iostream>

using namespace std;

int main(){
    int t;cin >> t;
    while(t --){
        int n,m;
        cin >> n >> m;
        string s;cin >> s;
        int cnt = 0;
        for(int i = 0;i < s.size();i ++){
            if(s[i] == '*') cnt ++;
        }
//        cout << cnt << " ";
        if(cnt <= 2) { cout << cnt << endl; continue;}
        int head,rear;
        int len = s.size();
        for(int i = 0;i < len;i ++){
            if(s[i] == '*'){
                s[i] = 'x';
                head = i;
                break;
            }
        }
        for(int i = len - 1;i >= 0;i --){
            if(s[i] == '*'){s[i] = 'x';rear = i;break;}
        }
        cnt = 2;
        if(head - rear <= m){cout << cnt << endl;continue;}

        while(head - rear > m){
            head += m;
            rear -= m;
            while(s[head] != '*') head --;
            while(s[rear] != '*') rear ++;
            if(head >= rear) cnt ++;
            else cnt += 2;
        }
        cout << cnt << endl;
    }
    return 0;
}


