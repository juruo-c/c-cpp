//
// Created by 19116 on 2021/3/19.
//

//#include<iostream>
//
//using namespace std;
//
//
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int n;cin >> n;
//        int k1,k2;cin >> k1 >> k2;
//        int w,b;cin >> w >> b;
//        int kk1 = n - k1,kk2 = n - k2;
//        int wsum = k1 / 2 + k2 / 2;
//        if(k1 % 2 && k2 % 2) wsum ++;
//        int bsum = kk1 / 2 + kk2 / 2;
//        if(kk1 % 2 && kk2 % 2) bsum ++;
//        if(wsum >= w && bsum >= b) cout << "yes" << endl;
//        else cout << "no" << endl;
//    }
//    return 0;
//}


//#include<iostream>
//#define db double
//
//using namespace std;
//class Stonewt{
//private:
//    enum {Lbs_per_stn = 14};
//    int stone;
//    db pds_left;
//    db pounds;
//public:
//    Stonewt(db lbs);
//    Stonewt(int stn,db lbs);
//    Stonewt();
//    ~Stonewt();
//    void show_lbs() const;
//    void show_stn() const;
//
//    //conversion functions
//
//    operator int() const;
//    operator double() const;
//};
//Stonewt::operator int() const{
//    return int(pounds + 0.5);
//}
//Stonewt::operator double()const{
//    return pounds;
//}
//Stonewt::Stonewt(db lbs){
//    stone = int(lbs) / Lbs_per_stn;
//    pds_left = int(lbs) % Lbs_per_stn + lbs - (int) lbs;
//    pounds = lbs;
//}
//
//Stonewt::Stonewt(int stn,db lbs){
//    stone = stn;
//    pds_left = lbs;
//    pounds = stn * Lbs_per_stn + lbs;
//}
//Stonewt::Stonewt(){stone = pounds = pds_left = 0;}
//Stonewt::~Stonewt(){}
//void Stonewt::show_stn() const{
//    cout << stone << " stone, " << pds_left << " pounds\n";
//}
//
//void Stonewt::show_lbs() const{
//    cout << pounds << " pounds" << endl;
//}
//int main(){
//    Stonewt poppins(9,2.8);
//    double p_wt = poppins;
//    cout << "Convert to double => " ;
//    cout << "poppins: " << p_wt << " pounds.\n";
//    cout << "Convert to int => " ;
//    cout << "poppins: " << int(poppins) << " pounds.\n";
//    return 0;
//}



//#include<iostream>
//#include<cstring>
//
//using namespace std;
//class Stringbad{
//private:
//    char* str;
//    int len;
//    static int num_strings;
//public:
//    Stringbad(const char* s);
//    Stringbad();
//    ~Stringbad();
//    friend ostream& operator << (ostream& os,const Stringbad& b);
//};
//
//int Stringbad::num_strings = 0;
//
//Stringbad::Stringbad(const char* s){
//    len = strlen(s);
//    str = new char[len + 1];
//    strcpy(str,s);
//    num_strings ++;
//    cout << num_strings << ": \"" << str << "\"object created\n";
//}
//Stringbad::Stringbad(){
//    len = 4;
//    str = new char[4];
//    strcpy(str,"C++");
//    num_strings ++;
//    cout << num_strings << ": \"" << str << "\"default object created\n";
//}
//
//Stringbad::~Stringbad(){
//    cout << "\"" << str << "\"object delete, ";
//    -- num_strings;
//    cout << num_strings << " left\n" ;
//    delete[] str;
//}
//
//ostream& operator << (ostream& os,const Stringbad& b){
//    os << b.str;
//    return os;
//}
//
//
//
//int main(){
//
//    return 0;
//}


//#include<iostream>
//
//using namespace std;
//struct Point{
//    int x,y;
//    Point(int x,int y) : x(x),y(y){}
//    Point operator - (const Point& b)const{return Point(x - b.x,y - b.y);}
//};
//struct Line{
//    Point s,e;
//    Line(Point s,Point e) : s(s),e(e){}
//};
//
//int cs(Point a,Point b,Point c){
//    return (b - a).x * (c - a).y - (b - a).y * (c - a).x;
//}
//int direction(const Line& l,const Point& p){
//    return cs(l.s,l.e,p);
//}
//
//int main(){
//    int n;cin >> n;
//    for(int i = 0;i < n;i ++){
//        int a,b,c,d;
//        cin >> a >> b >> c >> d;
//        Line l = Line(Point(a,b),Point(c,d));
//        cin >> a >> b;
//        Point p = Point(a,b);
//        int t = direction(l,p);
//        if(t > 0) cout << "anti clockwise" << endl;
//        else if(t < 0) cout << "clockwise" << endl;
//        else cout << "intersect" << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//struct P{
//    int x,y;
//    P(int x,int y): x(x),y(y) {}
//};
//struct R{
//    P l,r;
//    R(P l,P r):l(l),r(r){}
//};
//
//bool isoverlap(const R &r1, const R &r2){
//    if(r1.l.x > r2.r.x || r1.l.y > r2.r.y || r1.r.x < r2.l.x || r1.r.y < r2.l.y) return false;
//    return true;
//}
//int main(){
//    int n;cin >> n;
//    for(int i = 1;i <= n;i ++){
//        int a,b,c,d;
//        int a1,b1,c1,d1;
//        cin >> a >> b >> c >> d;
//        cin >> a1 >> b1 >> c1 >> d1;
//        if(a > c) swap(a,c);
//        if(a1 > c1) swap(a1,c1);
//        if(b > d) swap(b,d);
//        if(b1 > d1) swap(b1,d1);
//        R r1 = R(P(a1,b1),P(c1,d1));
//        R r2 = R(P(a,b),P(c,d));
//        if(isoverlap(r1,r2)) cout << "overlapped" << endl;
//        else cout << "not overlapped" << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<sstream>
//
//using namespace std;
//
//int gcd(int a,int b){
//    return !b ? a : gcd(b,a % b);
//}
//
//int LCM(int a,int b){
//    if(a < b) swap(a,b);
//    return a * b / gcd(a,b);
//}
//struct F{
//    int s,m;
//    F(int s,int m) : s(s),m(m) {}
//};
//
//F add(const F& a,const F& b){
//    int t = LCM(a.m,b.m);
//    int s1 = t / a.m * a.s;
//    int s2 = t / b.m * b.s;
//    int ss = s1 + s2;
//    int g = gcd(max(t,ss),min(t,ss));
//    if(g < 0) g = -g;
//    t /= g,ss /= g;
//    return F(ss,t);
//}
//
//F sub(const F& a,const F& b){
//    int t = LCM(a.m,b.m);
//    int s1 = t / a.m * a.s;
//    int s2 = t / b.m * b.s;
//    int ss = s1 - s2;
//    int g = gcd(max(t,ss),min(t,ss));
//    if(g < 0) g = -g;
//    t /= g,ss /= g;
//    return F(ss,t);
//}
//
//F mul(const F& a,const F& b){
//    int mm = a.m * b.m;
//    int ss = a.s * b.s;
//    int g = gcd(max(mm,ss),min(mm,ss));
//    if(g < 0) g = -g;
//    return F(ss / g,mm / g);
//}
//
//F div(const F& a,const F& b){
//    int mm = a.m * b.s;
//    int ss = a.s * b.m;
//    int g = gcd(max(mm,ss),min(mm,ss));
//    if(g < 0) g = -g;
//    return F(ss / g,mm / g);
//}
//int main(){
//    int n;cin >> n;
//    for(int i = 0;i < n;i ++){
//        string s1,s2;
//        cin >> s1 >> s2;
//        for(int j = 0;j < s1.size();j ++) if(s1[j] == '/') s1[j] = ' ';
//        for(int j = 0;j < s2.size();j ++) if(s2[j] == '/') s2[j] = ' ';
//        int a,b,c,d;
//        stringstream ss(s1);
//        ss >> a >> b;
//        stringstream sss(s2);
//        sss >> c >> d;
//        if(b < 0) b = -b,a = -a;
//        if(d < 0) d = -d,c = -c;
//        F f1 = F(a,b),f2 = F(c,d);
//        cout << add(f1,f2).s << "/" << add(f1,f2).m << endl;
//        cout << sub(f1,f2).s << "/" << sub(f1,f2).m << endl;
//        cout << mul(f1,f2).s << "/" << mul(f1,f2).m << endl;
//        cout << div(f1,f2).s << "/" << div(f1,f2).m << endl;
//        cout << endl;
//    }
//    return 0;
//}

//#include <iostream>
//#include <algorithm>
//#include<string>
//
//using namespace std;
//
//string l[13] = { "2","3","4","5","6","7","8","9","10","J","Q","K","A" };
//string ll[6] = { "大王","小王","黑桃","红桃","梅花","方块" };
//
//
//struct Poke {
//    string name;
//    int n,fl;
//};
//
//
//int judge_number(string s) {
//    for (int i = 0; i < 13; i++) {
//        if(s.find(l[i]) != string::npos)
//            return i;
//    }
//    return -1;
//}
//
//int judge_flower(string s) {
//    for (int i = 0; i < 6; i++) {
//        if (s.find(ll[i]) != string::npos)
//            return i;
//    }
//    return -1;
//}
//bool cmp(Poke a, Poke b) {
//    if(a.fl == b.fl) return a.n > b.n;
//    return a.fl < b.fl;
//}
//
//int main()
//{
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        cin >> n;
//        Poke A[110];
//        for (int i = 0; i < n; i++) {
//            cin >> A[i].name;
//            A[i].n = judge_number(A[i].name);
//            A[i].fl = judge_flower(A[i].name);
//        }
//        sort(A, A + n, cmp);
//        for (int i = 0; i < n; i++) {
//            if (i != n - 1)
//                cout << A[i].name << " ";
//            else
//                cout << A[i].name << endl;
//        }
//    }
//    return 0;
//}

//Terminal: 00001 operator: 01
//Card Issuers: CCB Validity: 21/06
//CardNumber: 6029********5678
//Traded: 2016/3/13
//Costs: $1000.00
//
//#include<iostream>
//#include<sstream>
//
//using namespace std;
//
//struct S{
//    string name,T,O,CI,V,C,Tr,Co;
//};
//int main(){
//    int n; cin >> n;
//    while(n --){
//        S s;
//        cin >> s.name >> s.T >> s.O >> s.CI >> s.V >> s.C >> s.Tr >> s.Co;
//        s.C = s.C.substr(0,4) + "********" + s.C.substr(12);
//        cout << "Name: " << s.name << endl;
//        cout << "Terminal: " << s.T << " operator: " << s.O << endl;
//        cout << "Card Issuers: " << s.CI << " Validity: " << s.V << endl;
//        cout << "CardNumber: " << s.C << endl;
//        cout << "Traded: " << s.Tr << endl;
//        cout << "Costs: $" << s.Co << endl;
//
//        cout << endl;
//    }
//    return 0;
//}

//#include <iostream>
//#include <algorithm>
//#include <iomanip>
//#include<string>
//
//using namespace std;
//
//string number_rule[13] = { "2","3","4","5","6","7","8","9","10","J","Q","K","A" };
//string flower[6] = { "大王","小王","黑桃","红桃","梅花","方块" };
//
////扑克牌结构体
//struct Poke {
//    string name;
//    int number;
//    int flower;
//};
//
////判断A中的数字对应数字数组number_rule的下标是多少
//int judge_number(string A) {
//    for (int i = 0; i < 13; i++) {
//        //表示A中含有里面的字串
//        if(A.find(number_rule[i]) != string::npos)
//            return i;
//    }
//    return -1;
//}
//
////判断A中的花色对应花色数组flower的下标是多少
//int judge_flower(string A) {
//    for (int i = 0; i < 6; i++) {
//        if (A.find(flower[i]) != string::npos)
//            return i;
//    }
//    return -1;
//}
//
////两张扑克牌的排序比较规则，用于sort函数
//bool cmp(Poke A, Poke B) {
//    if (A.flower != B.flower)
//        return A.flower < B.flower;
//    else
//        return A.number > B.number;
//}
//
//int main()
//{
//    int t;
//    cin >> t;								      //测试案例个数
//    while (t--) {
//        int n;
//        cin >> n;								  //该组案例的扑克牌张数
//        Poke *A = new Poke[n];
//        for (int i = 0; i < n; i++) {
//            cin >> A[i].name;					  //输入该张牌的名字
//            A[i].number = judge_number(A[i].name);//得到该牌的数字对应的下标
//            A[i].flower = judge_flower(A[i].name);//得到该牌的花色对应的下标
//        }
//        sort(A, A + n, cmp);					  //从大到小进行排序
//        for (int i = 0; i < n; i++) {			  //进行该组测试的输出
//            if (i != n - 1)
//                cout << A[i].name << " ";
//            else
//                cout << A[i].name << endl;
//        }
//    }
//    return 0;
//}


