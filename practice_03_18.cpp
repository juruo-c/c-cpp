//
// Created by 19116 on 2021/3/18.
//

//#include<iostream>
//#include<set>
//#include<vector>
//
//using namespace std;
//
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int n;cin >> n;
//        set<int> s;vector<int> v;
//        for(int i = 0;i < n;i ++){
//            int a;cin >> a;
//            if(s.count(a)) v.push_back(a);
//            else s.insert(a);
//        }
//        for(auto x : s) cout << x << " ";
//        for(auto x : v) cout << x << " ";
//        cout << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<set>
//
//using namespace std;
//
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int n,m;
//        cin >> n >> m;
//        multiset<int> s;
//        for(int i = 0;i < n;i ++){
//            int a;cin >> a;
//            s.insert(a % m);
//        }
////        for(auto x : s) cout << x << " ";
////        cout << endl;
//        int ans = 0;
//        for(int i = 0;i <= m / 2;i ++){
//            if(!s.count(i)){
//                if(s.count(m - i)) ans += s.count(m - i);
//                continue;
//            }
//            if((!i) && s.count(i)){
//                ans ++;
//                continue;
//            }
//            if(s.count(i) && m % 2 == 0 && i == m / 2){
//                ans ++;
//                continue;
//            }
//            if(s.count(m - i)){
//                int mx = max(s.count(i),s.count(m - i));
//                int mn = min(s.count(i),s.count(m - i));
//                if(mx <= mn + 1) ans ++;
//                else ans += mx - mn;
//            }
//            else ans += s.count(i);
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//class Stonewt{
//private:
//    enum {Lbs_per_stn = 14};
//    int stone;
//    double pds_left;
//    double pounds;
//public:
//    Stonewt(double lbs);
//    Stonewt(int stn,double lbs);
//    Stonewt();
//    ~Stonewt();
//    void show_lbs()const;
//    void show_stn()const;
//};
//
//Stonewt::Stonewt(double lbs){
//    stone = int(lbs) / Lbs_per_stn;
//    pds_left = int(lbs) % Lbs_per_stn - int(lbs);
//    pounds = lbs;
//}
//
//Stonewt::Stonewt(int stn,double lbs){
//    stone = stn;
//    pds_left = lbs;
//    pounds = stn * Lbs_per_stn + lbs;
//}
//Stonewt::Stonewt(){
//    stone = pounds = pds_left = 0;
//}
//Stonewt::~Stonewt(){
//
//}
//void Stonewt::show_lbs()const{
//    cout << stone << " stone," << pds_left << " pounds\n";
//}
//void Stonewt::show_stn()const{
//    cout << pounds << " pounds\n";
//}
//
//int main(){
//
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//class Process{
//private:
//    string name;
//    int time_wait;
//    int time_run;
//    int level;
//
//public:
//    Process(string n,int t1,int t2);
//    void display();
//    void getlevel(Process& a,Process& b);
//};
//
//Process::Process(string n,int t1,int t2){
//    name = n;time_wait = t1;
//    time_run = t2;
//    level = time_wait / time_run;
//}
//
//void Process::display(){
//    cout << name << " " << time_wait << " " << time_run << " " << level << endl;
//}
//
//void Process::getlevel(Process& a,Process& b){
//    if(a.level > level) swap(a,*this);
//    if(b.level > level) swap(b,*this);
//}
//
//int main(){
//    string a;int b,c;
//    string a1;int b1,c1;
//    string a2;int b2,c2;
//    cin >> a >> b >> c >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 ;
//
//    Process t = Process(a,b,c);
//    Process t1 = Process(a1,b1,c1);
//    Process t2 = Process(a2,b2,c2);
//    t.getlevel(t1,t2);
//    t.display();
//
//
//    return 0;
//}


//#include<iostream>
//
//
//using namespace std;
//
//class Bank{
//private:
//    int num,tele,pass,left;
//public:
//    Bank(){};
//    Bank(int n,int t,int p,int l);
//    int getnum();
//    int gettele();
//    int getpass();
//    int getleft();
//    bool is_pass_right(int p);
//    bool put_out(int sum);
//};
//
//Bank P[110];
//
//Bank::Bank(int n,int t,int p,int l){num = n;tele = t;pass = p;left = l;}
//int Bank::getnum(){
//    return num;
//}
//int Bank::gettele(){return tele;}
//int Bank::getpass(){return pass;}
//int Bank::getleft(){return left;}
//bool Bank::is_pass_right(int p){return p == pass;}
//bool Bank::put_out(int sum){
//    if(left >= sum){
//        left -= sum;
//        return true;
//    }
//    return false;
//}
//int n;
//int search_tele(int tele){
//    for(int i = 1;i <= n;i ++) if(tele == P[i].gettele()) return i;
//    return false;
//}
//int main(){
//    cin >> n;
//    for(int i = 1;i <= n;i ++){
//        int a,b,c,d;
//        cin >> a >> b >> c >> d;
//        P[i] = Bank(a,b,c,d);
//    }
//    int k;cin >> k;
//    for(int i = 1;i <= k;i ++){
//        int tele,pass,sum;
//        cin >> tele >> pass >> sum ;
//        int t;
//        if(t = search_tele(tele)){
//            if(P[t].is_pass_right(pass)){
//                if(P[t].put_out(sum))
//                    cout << "����" << P[t].getnum() << "--" << "���" << P[t].getleft() << endl;
//                else cout << "����" << P[t].getnum() << "--" << "����" << endl;
//            }
//            else{
//                cout << "�������" << endl;
//            }
//        }
//        else{
//            cout << "�ֻ��Ų�����" << endl;
//        }
//    }
//    return 0;
//}


//#include<iostream>
//#include<cmath>
//#define db double
//
//using namespace std;
//const db PI = acos(-1);
//class Point{
//    db x,y;
//public:
//    Point();
//    Point(db x_v,db y_v);
//    db getx();
//    db gety();
//    void setxy(db x1,db y1);
//    void setx(db x_v);
//    void sety(db y_v);
//    db gd(Point& b);
//    ~Point();
//}P[110];
//Point::Point(){x = 0,y = 0;}
//Point::Point(db x_v,db y_v){x = x_v,y = y_v;}
//db Point::getx(){return x;}
//db Point::gety(){return y;}
//void Point::setxy(db x1,db y1){x = x1,y = y1;}
//void Point::setx(db x_v){x = x_v;}
//void Point::sety(db y_v){y = y_v;}
//db Point::gd(Point& b){return sqrt((x - b.getx()) * (x - b.getx()) + (y - b.gety()) * (y - b.gety()));}
//Point::~Point(){}
//
//class Circle{
//    Point center;
//    db radius;
//public:
//    Circle();
//    Circle(db x,db y,db r);
//    db ga();
//    void moveCentreto(db x1,db y1);
//    int contain(Point& p);
//};
//
//Circle::Circle(){center = Point(0,0);radius = 1;}
//Circle::Circle(db x,db y,db r){
//    center = Point(x,y);
//    radius = r;
//}
//db Circle::ga(){
//    return 2 * PI * radius;
//}
//void Circle::moveCentreto(db x1,db y1){
//    center.setx(x1);center.sety(y1);
//}
//int Circle::contain(Point& p){
//    if((p.getx() - center.getx()) * (p.getx() - center.getx()) + (p.gety() - center.gety()) * (p.gety() - center.gety()) <= radius * radius)
//        return 1;
//    return 0;
//}
//
//int main(){
//    int x,y,r;
//    cin >> x >> y >> r;
//    Circle circle(x,y,r);
//    int n;cin >> n;
//    for(int i = 1;i <= n;i ++){
//        int x,y;cin >> x >> y;
//        P[i] = Point(x,y);
//    }
//    for(int i = 1;i <= n;i ++){
//        if(circle.contain(P[i])) cout << "inside" << endl;
//        else cout << "outside" << endl;
//    }
//    cout << "after move the centre of circle:" << endl;
//    cin >> x >> y;
//    circle.moveCentreto(x,y);
//    for(int i = 1;i <= n;i ++){
//        if(circle.contain(P[i])) cout << "inside" << endl;
//        else cout << "outside" << endl;
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
//            << "x2=" << e.getaf2() << "-" << e.getbt1() << "i" << endl;
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

#include<iostream>

using namespace std;

long long n,num,i;
string s;
int main(){
    cin >> s >> n;
    num = s.length();
    while(num < n){
        i = num;
        while(n > i) i *= 2;
        i = i / 2;
        n -= (i + 1);
        if(n == 0) n = i;
    }
    cout << s[n - 1] << endl;
    return 0;
}
