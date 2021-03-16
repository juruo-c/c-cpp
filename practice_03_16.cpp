//
// Created by 19116 on 2021/3/16.
//


//#include<iostream>
//
//using namespace std;
//const int N = 1e5 + 10;
//int n,a[N];
//void qsort(int l,int r){
//    int m = a[(l + r) / 2];
//    int i = l,j = r;
//    do{
//        while(a[i] < m) i ++;
//        while(a[j] > m) j --;
//        if(i <= j) {
//            swap(a[i],a[j]);
//            i ++;
//            j --;
//        }
//    }while(i <= j);
//    if(l < j) qsort(l,j);
//    if(i < r) qsort(i,r);
//}
//int main(){
//    cin >> n;
//    for(int i = 1;i <= n;i ++) cin >> a[i];
//    qsort(1,n);
//    for(int i = 1;i <= n;i ++) cout << a[i] << " ";
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int main(){
//    int n;int a[110];
//    cin >> n;
//    for(int i = 0;i < n;i ++) cin >> a[i];
//    sort(a,a + n);
//    int len = unique(a,a + n) - a;
//    for(int i = 0;i < len;i ++) cout << a[i] << ' ';
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//const int N = 5e3 + 10;
//struct p{
//    int num,s;
//    bool operator <(const p& a)const{
//        if(s == a.s) return num < a.num;
//        return s > a.s;
//    }
//}a[N];
//int main(){
//    int n,m;
//    cin >> n >> m;
//    for(int i = 0;i < n;i ++) cin >> a[i].num >> a[i].s;
//    sort(a ,a + n);
//    int t = a[m * 3 / 2 - 1].s;
//    int sum = 0;
//    for(int i = 0;i < n;i ++){
//        if(a[i].s >= t) sum ++;
//    }
//    cout << t << " " << sum << endl;
//    for(int i = 0;i < sum;i ++) cout << a[i].num << " " << a[i].s << endl;
//    return 0;
//}

//#include<iostream>
//#include<cmath>
//
//using namespace std;
//
//class Vector{
//public:
//    enum Mode{RECT,POL};
//private:
//    double x,y,mag,ang;
//    Mode mode;
//    void set_mag();
//    void set_ang();
//    void set_x();
//    void set_y();
//public:
//    Vector();
//    Vector(double n1,double n2,Mode form = RECT);
//    void reset(double n1,double n2,Mode form = RECT);
//    ~Vector();
//    double xval()const{return x;}
//    double yval()const{return y;}
//    double magval()const{return mag;}
//    double angval()const{return ang;}
//    void polar_mode();
//    void rect_mode();
//    Vector operator + (const Vector &b) const;
//    Vector operator - (const Vector &b) const;
//    Vector operator - ()const;
//    Vector operator * (double n) const;
//
//    friend Vector operator * (double n,const Vector &a);
//    friend ostream& operator << (ostream& os,const Vector &v);
//};
//
//const double Rad_to_deg = 45.0 / atan(1.0);
//void Vector::set_mag(){
//    mag = sqrt(x * x + y * y);
//}
//void Vector::set_ang(){
//    if(x == 0.0 && y == 0.0) ang = 0.0;
//    else ang = atan2(y,x);
//}
//void Vector::set_x(){
//    x = mag * cos(ang);
//}
//void Vector::set_y(){
//    x = mag * sin(ang);
//}
//Vector::Vector(){
//    x = y = mag = ang = 0.0;
//    mode = RECT;
//}
//Vector::Vector(double n1,double n2,Mode form){
//    mode = form;
//    if(form == RECT){
//        x = n1,y = n2;
//        set_ang();
//        set_mag();
//    }
//    else if(form == POL){
//        mag = n1,ang = n2;
//        set_x();
//        set_y();
//    }
//    else{
//        cout << "Incorrect 3rd argument to Vector() -- ";
//        cout << "vector set to\n";
//        x = y = mag = ang = 0.0;
//        mode = RECT;
//    }
//}
//
//void Vector::reset(double n1,double n2,Mode form){
//    mode = form;
//    if(form == RECT){
//        x = n1,y = n2;
//        set_mag();set_ang();
//    }
//    else if(form == POL){
//        mag = n1,ang = n2;
//        set_x();
//        set_y();
//    }
//    else{
//        cout << "Incorrect 3rd argument to Vector() -- ";
//        cout << "vector set to\n";
//        x = y = mag = ang = 0.0;
//        mode = RECT;
//    }
//}
//Vector::~Vector(){}
//void Vector::polar_mode() {mode = POL;}
//void Vector::rect_mode() {mode = RECT;}
//
//Vector Vector::operator + (const Vector &b) const{
//    return Vector(x + b.x,y + b.y);
//}
//Vector Vector::operator - (const Vector &b) const{
//    return Vector(x - b.x,y - b.y);
//}
//
//Vector Vector::operator - () const{
//    return Vector(-x,-y);
//}
//Vector Vector::operator * (double n) const{
//    return Vector(n * x,n * y);
//}
//Vector operator * (double n,const Vector& b){
//    return b * n;
//}
//ostream& operator <<(ostream &os,const Vector &b){
//    if(b.mode == Vector::RECT) os << "(x,y) = (" << b.x << ", " << b.y << ")";
//    else if(b.mode == Vector::POL){
//        os << "(m,a) = (" << b.mag << ", " << b.ang * Rad_to_deg << ")" ;
//    }
//    else os << "Vector object mode is invalid" << endl;
//    return os;
//}
//int main(){
//
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 110;
//int ans;
//struct S{
//    int pos;
//    string name;
//    int f1,f2;
//    int sum;
//    int paper;
//    char fl1,fl2;
//    bool operator < (const S& b)const{
//        if(sum == b.sum) return pos < b.pos;
//        return sum > b.sum;
//    }
//}a[N];
//
//int main(){
//    int n;cin >> n;
//    for(int i = 1;i <= n;i ++){
//        cin >> a[i].name >> a[i].f1 >> a[i].f2 >> a[i].fl1 >> a[i].fl2 >> a[i].paper;
//        a[i].sum = 0;
//        a[i].pos = i;
//        if(a[i].f1 > 80 && a[i].paper >= 1) a[i].sum += 8000,ans += 8000;
//        if(a[i].f1 > 85 && a[i].f2 > 80) a[i].sum += 4000,ans += 4000;
//        if(a[i].f1 > 90 ) a[i].sum += 2000,ans += 2000;
//        if(a[i].f1 > 85 && a[i].fl2 == 'Y') a[i].sum += 1000,ans += 1000;
//        if(a[i].f2 > 80 && a[i].fl1 == 'Y') a[i].sum += 850,ans += 850;
//    }
//    sort(a + 1,a + n + 1);
//    cout << a[1].name << endl << a[1].sum << endl;
//    cout << ans << endl;
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//
//using namespace std;
//const int N = 2e5 + 10;
//int n,r,q;
//struct P{
//    int pos,w;long long sum;
//    bool operator < (const P& b)const{
//        if(sum == b.sum) return pos < b.pos;
//        return sum > b.sum;
//    }
//}a[N],b[N];
//
//void merge_sort(int l,int r){
//    if(l == r) return;
//    int mid = (l + r) / 2 ;
//    merge_sort(l,mid);merge_sort(mid + 1,r);
//    int i = l,k = l,j = mid + 1;
//    while(i <= mid && j <= r){
//        if(a[i] < a[j]) b[k ++] = a[i ++];
//        else b[k ++] = a[j ++];
//    }
//    while(i <= mid) b[k ++] = a[i ++];
//    while(j <= r) b[k ++] = a[j ++];
//    for(int m = l;m <= r;m ++) a[m] = b[m];
//}
//int main(){
//    cin >> n >> r >> q;
//    for(int i = 1;i <= 2 * n;i ++){
//        cin >> a[i].sum;
//        a[i].pos = i;
//    }
//    for(int i = 1;i <= 2 * n;i ++) cin >> a[i].w;
//    for(int i = 0;i < r;i ++){
//        merge_sort(1,2 * n);
//        for(int j = 1;j <= 2 * n - 1;j += 2){
//            if(a[j].w < a[j + 1].w) a[j + 1].sum ++;
//            else a[j].sum ++;
//        }
//    }
//    merge_sort(1,2 * n);
////    for(int i = 1;i <= 2 * n;i ++) cout << a[i].sum << " ";
////    cout << endl;
//    cout << a[q].pos << endl;
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//int a[110],b[110];
//void merge_sort(int l,int r){
//    if(l == r) return;
//    int mid = (l + r) / 2 ;
//    merge_sort(l,mid);merge_sort(mid + 1,r);
//    int i = l,k = l,j = mid + 1;
//    while(i <= mid && j <= r){
//        if(a[i] < a[j]) b[k ++] = a[j ++];
//        else b[k ++] = a[i ++];
//    }
//    while(i <= mid) b[k ++] = a[i ++];
//    while(j <= r) b[k ++] = a[j ++];
//    for(int m = l;m <= r;m ++) a[m] = b[m];
//}
//
//int main(){
//    int n;cin >> n;
//    for(int i = 1;i <= n;i ++) cin >> a[i];
//    merge_sort(1,n);
//    for(int i = 1;i <= n;i ++) cout << a[i] << " ";
//    return 0;
//}


//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//const int N = 2e5 + 10;
//int n,r,q;
//int a[N],win[N],lost[N],s[N],w[N];
//bool cmp(int x,int y){
//    if(s[x] == s[y]) return x < y;
//    return s[x] > s[y];
//}
//void merge(){
//    int i = 1,j = 1;
//    a[0] = 0;
//    while(i <= win[0] && j <= lost[0]){
//        if(cmp(win[i],lost[j])) a[++ a[0]] = win[i ++];
//        else a[++ a[0]] = lost[j ++];
//    }
//    while(i <= win[0]) a[++ a[0]] = win[i ++];
//    while(j <= lost[0]) a[++ a[0]] = lost[j ++];
//}
//
//int main(){
//    cin >> n >> r >> q;
//    n *= 2;
//    for(int i = 1;i <= n;i ++) a[i] = i;
//    for(int i = 1;i <= n;i ++) cin >> s[i];
//    for(int i = 1;i <= n;i ++) cin >> w[i];
//    sort(a + 1,a + n + 1,cmp);
//    for(int i = 1;i <= r;i ++){
//        win[0] = lost[0] = 0;
//        for(int j = 1;j <= n;j += 2){
//            if(w[a[j]] > w[a[j + 1]]){
//                s[a[j]] ++;
//                win[++ win[0]] = a[j];
//                lost[++ lost[0]] = a[j + 1];
//            }
//            else{
//                s[a[j + 1]] ++;
//                win[++ win[0]] = a[j + 1];
//                lost[++ lost[0]] = a[j];
//            }
//        }
//        merge();
//    }
//    cout << a[q] << endl;
//    return 0;
//}

#include<cstdio>

using namespace std;
double a,b,c,d;

double fc(double x){
    return a * x * x * x + b * x * x + c * x + d;
}

int main(){
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    int cnt = 0;
    for(int i = -100;i < 100;i ++){
        double l = i;
        double r = i + 1;
        double f1 = fc(l),f2 = fc(r);
        if(!f1){
            printf("%.2lf ",l);
            cnt ++;
        }
        if(f1 * f2 < 0){
            while(r - l >= 0.001){
                double m = (l + r) / 2;
                if(fc(m) * fc(r) <= 0) l = m;
                else r = m;
            }
            printf("%.2lf ",r);
            cnt ++;
        }
        if(cnt == 3) break;
    }
    return 0;
}