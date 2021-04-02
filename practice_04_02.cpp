//
// Created by 19116 on 2021/4/2.
//

//#include<iostream>
//
//using namespace std;
//
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int n;cin >> n;
//        cout << 9;
//        if(n > 1){
//            for(int i = 1;i < n;i ++){
//                cout << (i + 7) % 10;
//            }
//        }
//
//        cout << endl;
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//struct node{
//    int y;int re;int sum;
//}peo[100007];
//int tmp[100007];
//bool cmp(node a,node b)
//{
//    if(a.y==b.y)return a.re<b.re;
//    return a.y<b.y;
//
//}
//int main()
//{
//
//    int n;
//    cin>>n;
//    for(int i=1;i<=n;i++)
//        cin>>peo[i].y>>peo[i].re;
//    sort(peo+1,peo+1+n,cmp);//按y大小排序
//    for(int i=1;i<=n;i++)
//        peo[i].sum+=peo[i-1].sum+peo[i].re;
//    int ans,maxx=-1,pos=1;
////    for(int i = 1;i <= n;i ++){
////        cout << peo[i].y << " " << peo[i].re << endl;
////    }
////    for(int i = 1;i <= n;i ++){
////        cout << peo[i].sum << " ";
////    }
////    cout << endl;
//    for(int i=1;i<=n;i++)
//    {
//        tmp[i]=peo[i].y;
//    }
//    for(int i=1;i<=n;i++)
//    {
//        int tmp1=(int)(lower_bound(tmp+1,tmp+1+n,peo[i].y)-tmp);//寻找和当前阈值相同的排在最前面的位置
////        cout << tmp1 << " ";
//        ans=tmp1-1-peo[tmp1-1].sum+peo[n].sum-peo[tmp1-1].sum;//阈值之前的正确数是之前的全部数目减掉前缀和，阈值之后的就直接是前缀和了
////        cout << ans << endl;
//        if(ans>=maxx){
//            maxx=ans;
//            pos=i;
//        }
//    }
//    cout<<peo[pos].y<<endl;
//
//    return 0;
//}


//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//const int N = 1e5 + 10;
//int n,m;
//int f[N][20];
//int lg[N];
//
//int query(int l,int r){
//    int k = lg[r - l + 1];
//    return min(f[l][k],f[r - (1 << k) + 1][k]);
//}
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 1;i <= n;i ++){
//        scanf("%d",&f[i][0]);
//    }
//    for(int i = 2;i <= n;i ++) lg[i] = lg[i / 2] + 1;
//    for(int j = 1;(1 << j) <= n;j ++){
//        for(int i = 1;i + (1 << j) - 1 <= n;i ++){
//            f[i][j] = min(f[i][j - 1],f[i + (1 << (j - 1))][j - 1]);
//        }
//    }
//    for(int i = 1;i <= n - m + 1;i ++){
//        printf("%d\n",query(i,i + m - 1));
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//typedef long long ll;
//int m;ll d;
//int main(){
//    ll t = 0;
//    scanf("%d%lld",&m,&d);
//    for(int i = 1;i <= m;i ++){
//        char c;
//        scanf("\n%c",&c);
//        if(c == 'A'){
//
//        }
//        else if(c == 'Q'){
//
//        }
//    }
//    return 0;
//}


//#include<iostream>
//
//using namespace std;
//struct SNode{
//    int data;
//    SNode* next;
//};
//class CList{
//    SNode *head;
//public:
//    CList();
//    void createList(int *value,int n);
//    void printList();
//    bool insertNode(int pos,int value);
//    bool removeNode(int pos);
//    ~CList();
//};
//
//CList::CList(){
//    head = new SNode;
//    head -> next = NULL;
//    head -> data = 0;
//}
//void CList::createList(int *value,int n){
//    SNode *t = head;
//    for(int i = 0;i < n;i ++){
//        SNode *node = new SNode;
//        node -> next = NULL;
//        t -> next = node;
//        node -> data = value[i];
//        t = node;
//    }
//}
//void CList::printList(){
//    SNode *t = head -> next;
//    while(t){
//        cout << t -> data;
//        if(t -> next) cout << " ";
//        t = t -> next;
//    }
//    cout << endl;
//}
//bool CList::insertNode(int pos,int value){
//    SNode *t = head -> next;
//    int fl = 0;
//    while(t){
//        pos --;
//        if(pos == 0) {
//            fl = 1;break;
//        }
//        t = t -> next;
//    }
//    if(!fl) return false;
//    SNode *node = new SNode;
//    node -> data = value;
//    node -> next = t -> next;
//    t -> next = node;
//    return true;
//}
//bool CList::removeNode(int pos){
//    SNode *t = head -> next;
//    SNode *tt = head;
//    int fl = 0;
//    while(t){
//        pos --;
//        if(!pos){
//            fl = 1;
//            break;
//        }
//        tt = t;
//        t = t -> next;
//    }
//    if(!fl) return false;
//    tt -> next = t -> next;
//    delete t;
//    return true;
//}
//CList::~CList(){
//    SNode *t = head;
//    SNode *tt;
//    while(t){
//        tt = t -> next;
//        delete t;
//        t = tt;
//    }
//
//}
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int n;cin >> n;
//        int *v = new int[n];
//        for(int i = 0;i < n;i ++) cin >> v[i];
//        CList list;
//        list.createList(v,n);
//        list.printList();
//
//        int m;cin >> m;
//        for(int i = 0;i < m;i ++){
//            int pos,val;
//            cin >> pos >> val;
//            if(list.insertNode(pos,val)) list.printList();
//            else cout << "error\n";
//        }
//        cin >> m;
//        for(int i = 0;i < m;i ++){
//            int pos;cin >> pos;
//            if(list.removeNode(pos)) list.printList();
//            else cout << "error\n";
//        }
//        delete []v;
//    }
//    return 0;
//}
//#include<iostream>
//#include<cmath>
//#include<iomanip>
//#define db double
//using namespace std;
//
//class Equation{
//    db a,b,c;
//    db x1,x2;
//    db af1,bt1,af2,bt2;
//public:
//    Equation();
//    Equation(db a,db b,db c);
//    void _set(db a1,db b1,db c1);
//    void getRoot();
//    int is_root_exist();
//    db getx1(){return x1;}
//    db getx2(){return x2;}
//    db getaf1(){return af1;}
//    db getbt1(){return bt1;}
//    db getaf2(){return af2;}
//    db getbt2(){return bt2;}
//};
//
//Equation::Equation(){a = 1;b = 1;c = 0;}
//Equation::Equation(db a1,db b1,db c1){
//    a = a1;b = b1;c = c1;
//}
//void Equation::_set(db a1,db b1,db c1){
//    a = a1,b = b1,c = c1;
//}
//void Equation::getRoot(){
//    int t = is_root_exist();
//    db data = b * b - 4 * a * c;
//    if(t == 1){
//        x1 = (-b + sqrt(data)) / 2 / a;
//        x2 = (-b - sqrt(data)) / 2 / a;
//    }
//    else if(t == 0) {
//        x1 = x2 = (-b) / 2 / a;
//    }
//    else {
//        af1 = af2 = (- b) / 2 / a;
//        bt1 = sqrt(-data) / 2 / a;
//        bt2 = - bt1;
//    }
//}
//int Equation::is_root_exist(){
//    db data = b * b - 4 * a * c;
//    if(data < 0) return -1;
//    else if(data > 0) return 1;
//    else return 0;
//}
//int main(){
//    int n;cin >> n;
//    Equation e;
//    for(int i = 0;i < n;i ++){
//        db a,b,c;cin >> a >> b >> c;
//        e._set(a,b,c);
//        e.getRoot();
//        if(e.is_root_exist() == 1){
//            cout << "x1=" << fixed << setprecision(2) << e.getx1() << " " << "x2=" << e.getx2() << endl;
//        }
//        else if(e.is_root_exist() == 0){
//            cout << "x1=x2=" << fixed << setprecision(2) << e.getx1() << endl;
//        }
//        else{
//            cout << "x1=" << fixed << setprecision(2) << e.getaf1() << "+" << e.getbt1() << "i "
//                 << "x2=" << e.getaf2() << "-" << e.getbt1() << "i" << endl;
//        }
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//class FS{
//    int af,bt;
//public:
//    FS(){}
//    FS(int a,int b){af = a,bt = b;}
//    FS operator + (const FS& b) const{
//        return FS(af + b.af,bt + b.bt);
//    }
//    FS operator - (const FS& b) const{
//        return FS(af - b.af,bt - b.bt);
//    }
//    void print(){
//        int fl = 0;
//        if(af) {
//            cout << af;
//            fl = 1;
//        }
//        if(bt){
//            if(bt > 0 && fl) cout << "+";
//            if(bt != 1)cout << bt;
//            cout << "i";
//            fl = 1;
//        }
//        if(!fl) cout << 0 ;
//    }
//};
//int main(){
//    int n;cin >> n;
//    for(int i = 0;i < n;i ++){
//        int a,b,c,d;
//        cin >> a >> b >> c >> d;
//        FS f1(a,b),f2(c,d);
//        cout << "sum:" ;(f1 + f2).print();cout << endl;
//        cout << "remainder:"; (f1 - f2).print();cout << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//string s[8] = {"", "Monday","Tuesday", "Wednesday","Thursday","Friday","Saturday", "Sunday"};
//class Cdata{
//    int m,d,y,w;
//public:
//    Cdata(int m,int d,int y,int w = 0) : m(m),d(d),y(y),w(w) {}
//    void print();
//    void getWeekofDay();
//};
//void Cdata::print() {
//    cout << m << "/" << d << "/" << y << ", " << s[w] << endl;
//}
//void Cdata::getWeekofDay(){
//    int tm = m,ty = y;
//    if(m == 1 || m == 2) tm += 12,ty --;
//    w = (d + 2 * tm + 3 * (tm + 1) / 5 + ty + ty / 4 - ty / 100 + ty / 400) % 7 + 1;
//}
//int main(){
//    int n;cin >> n;
//    for(int i = 1;i <= n;i ++){
//        int m,d,y;cin >> y >> m >> d;
//        Cdata a(m,d,y);
//        a.getWeekofDay();
//        a.print();
//    }
//    return 0;
//}

//#include<iostream>
//#include<cmath>
//#include<iomanip>
//
//using namespace std;
//class Point{
//    double x,y;
//public:
//    Point();
//    Point(double x_v,double y_v);
//    double getx();
//    double gety();
//    void setx(double x_v);
//    void sety(double y_v);
//    double distoanotherpoint(Point& p);
//};
//Point::Point(){
//    x = 0,y = 0;
//}
//Point::Point(double x_v,double y_v){x = x_v;y = y_v;}
//double Point::getx() { return x; }
//double Point::gety() { return y; }
//void Point::setx(double x_v) { x = x_v; }
//void Point::sety(double y_v) { y = y_v; }
//double Point::distoanotherpoint(Point& p) { return sqrt((x - p.getx()) * (x - p.getx()) + (y - p.gety()) * (y - p.gety())); }
//int main(){
//    int n;cin >> n;
//    for(int i = 1;i <= n;i ++){
//        double a,b,c,d;
//        cin >> a >> b >> c >> d;
//        Point p1(a,b),p2(c,d);
//        cout << "Distance of Point(" << fixed << setprecision(2) << a << "," << b << ") "
//        << "to Point(" << c << "," << d << ") is " << p1.distoanotherpoint(p2) << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//typedef long long ll;
//ll m,d,t;
//const int N = 2e5 + 10;
//vector<ll> v;
//ll f[N][20];
//ll lg[N];
//void work(){
//    for(int i = 0;i < v.size();i ++) f[i + 1][0] = v[i];
//    int n = v.size();
//    for(int j = 1;(1 << j) <= n;j ++){
//        for(int i = 1;i + (1 << j) - 1 <= n;i ++){
//            f[i][j] = max(f[i][j - 1],f[i + (1 << (j - 1))][j - 1]);
//        }
//    }
//}
//
//ll query(ll l,ll r){
//    ll k = lg[r - l + 1];
//    return max(f[l][k],f[r - (1 << k) + 1][k]);
//}
//
//int main(){
//    scanf("%lld%lld",&m,&d);
//    for(int i = 2;i <= N;i ++) lg[i] = lg[i / 2] + 1;
//    for(int i = 0;i < m;i ++){
//        char c;ll a;
//        scanf("\n%c %lld",&c,&a);
////        cout << c << a << endl;
//        if(c == 'A'){
////            cout << (a + t) % d << endl;
//            v.push_back((a + t) % d);
//            work();
//        }
//        else{
//            printf("%lld\n",t = query(v.size() - a + 1,v.size()));
//        }
//    }
//    return 0;
//}


//#include<iostream>
//
//using namespace std;
//typedef long long ll;
//const int N = 2e5 + 10;
//ll a[N];int cnt;
//ll m,d,t;
//ll f[N][20];
//ll lg[N];
//void add(int n){
//    f[n][0] = a[n];
//    for(int i = 1;(1 << i) <= n;i ++){
//        f[n][i] = max(f[n][i - 1],f[n - (1 << (i - 1))][i - 1]);
//    }
//}
//
//ll query(int l,int r){
//    int k = lg[r - l + 1];
//    return max(f[r][k],f[l + (1 << k) - 1][k]);
//}
//int main(){
//    scanf("%lld%lld",&m,&d);
//    for(int i = 2;i <= N;i ++) lg[i] = lg[i / 2] + 1;
//    for(int i = 0;i < m;i ++){
//        char c;ll n;
//        scanf("\n%c %lld",&c,&n);
//        if(c == 'A'){
//            a[++ cnt] = (n + t) % d;
//            add(cnt);
//        }
//        else {
//            printf("%lld\n",t = query(cnt - n + 1,cnt));
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
//const int N = 5e5 + 10;
//int n,m;
//int a[N],c[N];
//int lowbit(int x){return x & (-x);}
//void insert(int x,int k){
//    while(x <= n){
//        c[x] += k;
//        x += lowbit(x);
//    }
//}
//
//int query(int x){
//    int ans = 0;
//    while(x){
//        ans += c[x];
//        x -= lowbit(x);
//    }
//    return ans;
//}
//
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 1;i <= n;i ++) {
//        scanf("%d",&a[i]);
//        insert(i,a[i]);
//    }
//
//    for(int i = 0;i < m;i ++){
//        int op,x,y;
//        scanf("%d%d%d",&op,&x,&y);
//        if(op == 1) insert(x,y);
//        else printf("%d\n",query(y) - query(x - 1));
//    }
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//const int N = 5e5 + 10;
//int n,m;
//int a[N],b[N],c[N];
//int lowbit(int x){return x & (-x);}
//void insert(int x,int k){
//    while(x <= n){
//        c[x] += k;
//        x += lowbit(x);
//    }
//}
//
//int query(int x){
//    int ans = 0;
//    while(x){
//        ans += c[x];
//        x -= lowbit(x);
//    }
//    return ans;
//}
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 1;i <= n;i ++){
//        scanf("%d",&a[i]);
//        b[i] = a[i] - a[i - 1];
//    }
//    for(int i = 1;i <= n;i ++) insert(i,b[i]);
//
//    for(int i = 0;i < m;i ++){
//        int op;
//        scanf("%d",&op);
//        if(op ==  1){
//            int x,y,k;
//            scanf("%d%d%d",&x,&y,&k);
//            insert(x,k);
//            insert(y + 1,- k);
//        }
//        else{
//            int x;scanf("%d",&x);
//            printf("%d\n",query(x));
//        }
//    }
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//const int N = 5e5 + 10;
//int a[N],b[N];
//int c[N];
//int n;
//int mx;
//int lowbit(int x){return x & (-x);}
//void insert(int x,int k){
//    while(x <= mx){
//        c[x] += k;
//        x += lowbit(x);
//    }
//}
//
//int query(int x){
//    int ans = 0;
//    while(x){
//        ans += c[x];
//        x -= lowbit(x);
//    }
//    return ans ;
//}
//int main(){
//    scanf("%d",&n);
//    for(int i = 1;i <= n;i ++){
//        scanf("%d",&a[i]);
//        b[i] = a[i];
//    }
//    sort(b + 1,b + n + 1);
//    int len = unique(b + 1,b + n + 1) - b - 1;
//
//    for(int i = 1;i <= n;i ++){
//        a[i] = lower_bound(b + 1,b + len + 1,a[i]) - b ;
//        mx = max(a[i],mx);
//    }
//    long long ans = 0;
//    for(int i = 1;i <= n;i ++){
//        insert(a[i],1);
//        ans += i - query(a[i]);
//    }
//
//    printf("%lld\n",ans);
//    return 0;
//}

