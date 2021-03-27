//
// Created by 19116 on 2021/3/26.
//

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
//    TableTennisPlayer(const string& fn = "none",
//                      const string& ln = "none",bool ht = false);
//    void Name()const;
//    bool HasTable() const{return hasTable;}
//    void ResetTable(bool v){hasTable = v;}
//};
//
//class RatedPlayer : public TableTennisPlayer{
//private:
//    unsigned int rating;
//public:
//    RatedPlayer(unsigned int r = 0,const string& fn = "none",
//            const string& ln = "none",bool ht = false);
//    RatedPlayer(unsigned int r,const TableTennisPlayer& tp);
//    unsigned int Rating() const {return rating;}
//    void ResetRating(unsigned int r){rating = r;}
//};
//
//TableTennisPlayer::TableTennisPlayer(const string& fn ,
//                  const string& ln ,bool ht ) : firstname(fn),lastname(ln),hasTable(ht){}
//
//void TableTennisPlayer::Name()const{
//    cout << lastname << ", " << firstname;
//}
//RatedPlayer::RatedPlayer(unsigned int r,const string& fn ,
//                             const string& ln ,bool ht ):TableTennisPlayer(fn,ln,ht) {rating = r; }
//RatedPlayer::RatedPlayer(unsigned int r,const TableTennisPlayer& tp):TableTennisPlayer(tp) {
//    rating = r;
//}
//
//int main(){
//    TableTennisP
//}


//#include<iostream>
//
//using namespace std;
//class Student{
//    string name,num,appart,major,sex,address,tele;
//public:
//    Student(){}
//    Student(string na,string n,string app,string maj,string se,string add,string tel);
//    void print();
//}s;
//
//Student::Student(string na,string n,string app,string maj,string se,string add,string tel){
//    name = na;num = n;appart = app;
//    major = maj;sex = se;address = add;tele = tel;
//}
//void Student::print() {
//    cout << name << " " << num << " " << appart << " " << major << " " << sex << " " << address << " " << tele << endl;
//}
//
//int main(){
//    int n;cin >> n;
//    for(int i = 0;i < n;i ++){
//        string name,app,maj,se,add,tel,num;
//        cin >> name >> num >> app >> maj >> se >> add >> tel;
//        s = Student(name,num,app,maj,se,add,tel);
//        s.print();
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//class Teacher{
//    string name,appart,sex,address,tele,zc,zw,xl;
//public:
//    Teacher(){}
//    Teacher(string na,string app,string se,string add,string tel,string z1,string z2,string xl);
//    void print();
//}t;
//
//Teacher::Teacher(string na,string app,string se,string add,string tel,string z1,string z2,string x){
//    name = na;appart = app;
//    sex = se;address = add;tele = tel;
//    zc = z1,zw = z2,xl = x;
//}
//void Teacher::print() {
//    cout << name << " " << sex << " " << appart << " " << zc << " " << zw << " " << xl << " " << address << " " << tele << endl;
//}
//
//int main(){
//    int n;cin >> n;
//    for(int i = 0;i < n;i ++){
//        string name,app,se,add,tel,zc,zw,xl;
//        cin >> name >> se >> app >> zc >> zw >> xl >> add >> tel ;
//        t = Teacher(name,app,se,add,tel,zc,zw,xl);
//        t.print();
//    }
//    return 0;
//}


//#include<iostream>
//#include<map>
//
//using namespace std;
//map<string,int> ma;
//class base{
//    string name,app,sex,add,tele;
//public:
//    void setname(string t) { name = t; }
//    void setapp(string t) { app = t; }
//    void setsex(string t) { sex = t; }
//    void setadd(string t){add = t;}
//    void settele(string t) { tele = t; }
//    string getname(){return name;}
//    string getapp(){return app;}
//    string getsex(){return sex;}
//    string getadd(){return add;}
//    string gettele(){return tele;}
//};
//
//class Student : public base{
//    string num,maj;
//public:
//    void setnum(string t){num = t;}
//    void setmaj(string t){maj = t;}
//    string getmaj(){return maj;}
//    string getnum(){return num;}
//
//    int dohomework(int n);
//};
//int Student::dohomework(int n) {
//    return n * n;
//}
//class Teacher : public base{
//    string zc,zw,xl;
//public:
//    void setzc(string t){zc = t;}
//    void setzw(string t){zw = t;}
//    void setxl(string t){xl = t;}
//    string getzc(){return zc;}
//    string getzw(){return zw;}
//    string getxl(){return xl;}
//
//    int homework(string name);
//    int review(int ans);
//};
//int Teacher::homework(string name) {
//    return ma[name];
//}
//int Teacher::review(int ans) {
//    return ans > 60 ? 88 : 44;
//}
//int main(){
//    Student st;Teacher th;
//    int t;cin >> t;
//    for(int i = 0;i < t;i ++){
//        int a;string s;
//        cin >> a >> s;
//        ma[s] = a;
//    }
//    int n; cin >> n;
//    for(int i = 0;i < n;i ++){
//        string s;
//        cin >> s;
//        cout << th.review(st.dohomework(th.homework(s))) << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cmath>
//#include<iomanip>
//
//using namespace std;
//
////类定义-----------------
//class Point{
//    int x,y;
//public:
//    void set(int xx,int yy);
//    int getx();
//    int gety();
//};
//
//class Circle{
//    int x,y,r;
//public:
//    void setcen(int xx,int yy);
//    void setr(int rr);
//    double getarea();
//    double getlength();
//    bool contain(Point& p);
//};
//
////类实现----------------
//void Point::set(int xx,int yy){
//    x = xx;y = yy;
//}
//int Point::getx() { return x; }
//int Point::gety() { return y; }
//
//void Circle::setcen(int xx,int yy) { x = xx,y = yy; }
//void Circle::setr(int rr) { r = rr; }
//double Circle::getarea() { return 3.14 * r * r; }
//double Circle::getlength() { return 2 * 3.14 * r; }
//bool Circle::contain(Point& p) {
//    int xx = p.getx(),yy = p.gety();
//    double dis = sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
//    return dis <= r;
//}
//
////主函数----------------
//int main(){
//    int px,py,x,y,r;
//    Circle c;
//    Point p;
//    cin >> x >> y >> r >> px >> py;
//    c.setcen(x,y);
//    c.setr(r);
//    p.set(px,py);
//    cout << fixed << setprecision(2) << c.getarea() << " " << c.getlength() << endl;
//    if(c.contain(p)) cout << "yes" << endl;
//    else cout << "no" << endl;
//    return 0;
//}
//
//#include<iostream>
//
//using namespace std;
//class Student{
//    string name,num,appart,major,sex,address,tele;
//public:
//    Student(){}
//    Student(string na,string n,string app,string se,string tel);
//    void print();
//}s[110];
//
//Student::Student(string na,string n,string app,string se,string tel){
//    name = na;num = n;appart = app;
//    sex = se;tele = tel;
//}
//void Student::print() {
//    cout << name << endl;
//}
//
//int main(){
//    int n;cin >> n;
//    for(int i = 0;i < n;i ++){
//        string name,app,se,tel,num;
//        cin >> name >> num >> se >> app >> tel;
//        s[i] = Student(name,num,app,se,tel);
//    }
//
//    for(int i = 0;i < n;i ++){
//        s[i].print();
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 510;
//int l[N][N],r[N][N];
//int a[N][N];
//int n,m;
//bool vis[N][N];
//int dir[4][2] = {1,0,-1,0,0,1,0,-1};
//
//void dfs(int x,int y){
//    vis[x][y] = 1;
//    for(int i = 0;i < 4;i ++){
//        int tx = x + dir[i][0],ty = y + dir[i][1];
//        if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
//        if(a[tx][ty] >= a[x][y]) continue;
//        if(!vis[tx][ty]) dfs(tx,ty);
//        l[x][y] = min(l[tx][ty],l[x][y]);
//        r[x][y] = max(r[x][y],r[tx][ty]);
//    }
//}
//
//
//
//int main(){
//    scanf("%d%d",&n,&m);
//    memset(l,0x3f,sizeof(l));
//    for(int i = 1;i <= m;i ++) l[n][i] = r[n][i] = i;
//    for(int i = 1;i <= n;i ++){
//        for(int j = 1;j <= m;j ++){
//            scanf("%d",&a[i][j]);
//        }
//    }
//
//    for(int i = 1;i <= m;i ++){
//        if(!vis[1][i]) dfs(1,i);
//    }
//
//    bool fl = 0;
//    int cnt = 0;
//    for(int i = 1;i <= m;i ++){
//        if(!vis[n][i]){
//            fl = 1;
//            cnt ++;
//        }
//    }
//    if(fl){
//        puts("0");
//        printf("%d\n",cnt);
//        return 0;
//    }
//
//    int left = 1;
//    while(left <= m){
//        int mxr = 0;
//        for(int i = 1;i <= m;i ++){
//            if(l[1][i] <= left){
//                mxr = max(mxr,r[1][i]);
//            }
//        }
//        cnt ++;
//        left = mxr + 1;
//    }
//    puts("1");
//    printf("%d\n",cnt);
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<cstdio>
//
//using namespace std;
//int n,m,a[66],ne[66],cnt,len;
//bool vis[66],ok;
//bool cmp(int a,int b){return a > b;}
//void dfs(int k,int last,int rest){
//    int i;
//    if(!rest){
//        if(k == m){ok = 1;return;}
//
//        for(i = 1;i <= cnt;i ++){
//            if(!vis[i]) break;
//        }
//        vis[i] = 1;
//        dfs(k + 1,i,len - a[i]);
//        vis[i] = 0;
//        if(ok) return;
//    }
//    int l = last + 1,r = cnt,mid;
//    while(l < r){
//        mid = (l + r) >> 1;
//        if(a[mid] <= rest) r = mid;
//        else l = mid + 1;
//    }
//
//    for(i = l;i <= cnt;i ++){
//        if(!vis[i]){
//            vis[i] = 1;
//            dfs(k,i,rest - a[i]);
//            vis[i] = 0;
//            if(ok) return;
//
//            if(rest == a[i] || rest == len) return;
//            i = ne[i];
//            if(i == cnt) return;
//        }
//    }
//}
//int main(){
//    scanf("%d",&n);
//    int sum = 0;
//    for(int i = 0;i < n;i ++){
//        int t;cin >> t;
//        if(t > 50) continue;
//        a[++ cnt] = t;
//        sum += t;
//    }
//    sort(a + 1,a + cnt + 1,cmp);//从大到小排序优化
//
//    //预处理next数组
//    ne[cnt] = cnt;
//    for(int i = cnt - 1;i > 0;i --){
//        if(a[i] == a[i + 1]) ne[i] = ne[i + 1];
//        else ne[i] = i;
//    }
//
//    for(len = a[1];len <= sum / 2;len ++){
//        if(sum % len != 0) continue; //不能拼出一整根木棍
//        m = sum / len;
//        ok = 0;
//        vis[1] = 1;
//        dfs(1,1,len - a[1]);
//        vis[1] = 0;
//        if(ok) {
//            printf("%d\n",len);
//            return 0;
//        }
//    }
//    printf("%d\n",sum);
//    return 0;
//}