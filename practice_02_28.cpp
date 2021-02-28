//
// Created by 19116 on 2021/2/28.
//
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<cmath>
//
//using namespace std;
//const int N = 510;
//const double eps = 1e-9;
//int sgn(double x){return x < -eps ? -1 : x > eps;}
//struct Point{
//    double x,y;
//    Point(){}
//    Point(double x,double y) : x(x),y(y){}
//    Point operator - (const Point& a)const{return Point(x - a.x, y - a.y);}
//    Point operator + (const Point& b)const{return Point(x + b.x,y + b.y);}
//    Point operator * (const double d)const{return Point(x * d,y * d);}
//    double operator * (const Point& b)const{return x * b.x + y * b.y;}
//};
//typedef Point Vector;
//struct Line{
//    Point s,e;
//    Line(){}
//    Line(Point s,Point e) : s(s),e(e) {}
//};
//double cross(Point& a,Point& b,Point& c){
//    return (b - a).x * (c - a).y - (b - a).y * (c - a).x;
//}
//double cross(Vector& a,Vector& b){
//    return a.x * b.y - a.y * b.x;
//}
//double getangle(Vector a){
//    return atan2(a.y,a.x);
//}
//bool cmp(Line a,Line b){
//    Vector va = a.e - a.s,vb = b.e - b.s;
//    double A = getangle(va),B = getangle(vb);
//    if(fabs(A - B) < eps) return sgn(cross(a.s,a.e,b.e)) >= 0;
//    return A < B;
//}
//Point getIntersectionPoint(Line a,Line b){
//    Vector u = a.s - b.s;
//    double t = cross(b.e - b.s,u) / cross(a.e - a.s,b.e - b.s);
//    return a.s + a.v * t;
//}
//int main(){
//
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cmath>
//#include<algorithm>
//
//using namespace std;
//const int N = 510;
//const double eps = 1e-9,PI = acos(-1);
//int dcmp(double x){return x < -eps ? -1 : x > eps;}
//struct Point{
//    double x,y;
//    Point(){}
//    Point(double x,double y) : x(x),y(y) {}
//    void read(){scanf("%lf%lf",&x,&y);}
//};
//typedef Point Vector;
//Vector operator + (Vector a,Vector b){return Vector(a.x + b.x,a.y + b.y);}
//Vector operator - (Point a,Point b){return Vector(a.x - b.x,a.y - b.y);}
//Vector operator * (Vector a,double d){return Vector(a.x * d,a.y * d);}
//double operator * (Vector a,Vector& b){return a.x * b.x + a.y * b.y;}
//bool operator < (const Point& a,const Point& b){
//    return a.x < b.x || (a.x == b.x && a.y < b.y);
//}
//
//bool operator == (const Point& a,const Point& b){return !dcmp(a.x - b.x) && !dcmp(a.y - b.y);}
//double getangle(Vector a){return atan2(a.y,a.x);}
//double length(Vector a){return sqrt(a * a);}
//double cross(Vector a,Vector b){return a.x * b.y - a.y * b.x;}
//Vector rotate(Vector a,double rad){//向量旋转
//    return Vector(a.x * cos(rad) - a.y * sin(rad),a.x * sin(rad) + a.y * cos(rad));
//}
//Point getlineintersectionPoint(Point p,Vector v,Point q,Vector w){
//    Vector u = p - q;
//    double t = cross(w,u) / cross(v,u);
//    return p + v * t;
//}
//double convex_area(Point p[],int n){
//    double area = 0;
//    for(int i = 1;i < n - 1;i ++) area += cross(p[i] - p[0],p[i - 1] - p[0]);
//    return area / 2.0;
//}
//struct Line{
//    Point p;
//    Vector v;
//    double deg;
//    Line(){}
//    Line(Point p,Vector v) : p(p),v(v) {}
//    bool operator < (const Line& L) const{
//        return deg < L.deg;
//    }
//};
//bool onleft(Line L,Point o){
//    return cross(L.v,o - L.p) > 0;
//}
//Point get_intersection(Line a,Line b){
//    Vector u = a.p - b.p;
//    double t = cross(b.v,u) / cross(a.v,b.v);
//    return a.p + a.v * t;
//}
//int half_plane_intersection(Line L[],int n,Point ans[]){
//    sort(L,L + n);
//    int first,last;
//    Point *p = new Point[n];
//    Line *q = new Line[n];
//    q[first = last = 0] = L[0];
//    for(int i = 1;i < n;i ++){
//        while(first < last && !onleft(L[i],p[last - 1])) last --;
//        while(first < last && !onleft(L[i],p[first])) first ++;
//        q[++ last] = L[i];
//        if(fabs(cross(q[last].v,q[last - 1].v)) < eps){
//            last --;
//            if(onleft(q[last],L[i].p)) q[last] = L[i];
//        }
//    }
//    while(first < last && !onleft(q[first],p[last - 1])) last --;
//    if(last - first <= 1) return 0;
//    p[last] = get_intersection(q[last],q[first]);
//    int m = 0;
//    for(int i = first;i <= last;i ++) ans[m ++] = p[i];
//    return m;
//}
//int n;Point p[N];
//Line l[N];int tot;
//int main(){
//    scanf("%d",&n);
//    for(int i = 0;i < n;i ++){
//        int m;scanf("%d",&m);
//        for(int j = 0;j < m;j ++) p[j].read();
//        for(int j = 0;j < m - 1;j ++) l[tot ++] = Line(p[j],p[j + 1] - p[j]);
//        l[tot++] = Line(p[m - 1],p[0] - p[m - 1]);
//    }
//    for(int i = 0;i < tot;i ++){
//        cout << l[i].p.x << " " << l[i].p.y << " "
//        << l[i].v.x << " " << l[i].v.y << endl;
//    }
//    Point ans[N];
//    int num = half_plane_intersection(l,tot,ans);
//    printf("%.3f\n",convex_area(ans,num));
//    return 0;
//}

//
//#include<cstdio>
//#include<cmath>
//#include<algorithm>
//
//using namespace std;
//const int N = 510;
//int n,m;
//struct pt{
//    double x,y;
//    pt(){}
//    pt(double x,double y) : x(x),y(y) {}
//    void rd(){scanf("%lf%lf",&x,&y);}
//};
//typedef pt vc;
//vc operator + (pt a,pt b){return pt(a.x + b.x,a.y + b.y);}
//vc operator - (pt a,pt b){return pt(a.x - b.x,a.y - b.y);}
//pt operator * (pt a,double d){return pt(a.x * d,a.y * d);}
//pt operator / (pt a,double d){return pt(a.x / d,a.y / d);}
//double operator * (vc a,vc b){return a.x * b.x + a.y * b.y;}
//double cross(vc a,vc b){return a.x * b.y - a.y * b.x;}
//double len(vc x){return x * x;}
//double dis(pt a,pt b){return len(b - a);}
//double area(pt a,pt b,pt z){return cross(b - a,z - a);}
//
//struct Line{
//    pt p;
//    vc v;
//    Line(){}
//    Line(pt p, vc v) : p(p),v(v) {}
//};
//
//pt getlip(Line a,Line b){
//    pt u = a.p - b.p;
//    double t = cross(u,b.v) / cross(b.v,a.v);
//    return a.p + a.v * t;
//}
//bool parallel(Line x,Line y){return cross(x.v,y.v) == 0;}//平行
//bool lineleft(Line x,Line y){
//    double t = cross(x.v,y.v);
//    return ((t > 0) || (t == 0) && cross(x.v,y.p - x.p) > 0);
//}
//bool ptright(pt x,Line y){return cross(y.v,x - y.p) <= 0;}//<=
//bool cmp(Line x,Line y){
//    if(x.v.y == 0 && y.v.y == 0) return x.v.x < y.v.x;
//    if(x.v.y <= 0 && y.v.y <= 0) return lineleft(x,y);
//    if(x.v.y > 0 && y.v.y > 0) return lineleft(x,y);
//    return x.v.y < y.v.y;
//}
//pt a[N],p[N];Line l[N],s[N];
//void hpi(){//half_plane_intersection
//    sort(l + 1,l + m + 1,cmp);
//    int tp = 0;
//    for(int i = 1;i <= m;i ++){
//        if(i == 1 || !parallel(l[i],l[i - 1])) tp ++;
//        l[tp] = l[i];
//    }
//    m = tp;
//    int L = 1,R = 2;
//    s[1] = l[1],s[2] = l[2];
//    for(int i = 3;i <= m;i ++){
//        while(L < R && ptright(getlip(s[R],s[R - 1]),l[i])) R --;
//        while(L < R && ptright(getlip(s[L],s[L + 1]),l[i])) L ++;
//        s[++ R] = l[i];
//    }
//    while(L < R && ptright(getlip(s[R],s[R - 1]),s[L])) R --;
//    if(R - L <= 1){
//        puts("0.000");
//        return ;
//    }
//    tp = 0;
//    s[L - 1] = s[R];
//    for(int i = L;i <= R;i ++) a[++ tp] = getlip(s[i],s[i - 1]);
//    double ans = 0;
//    for(int i = 3;i <= tp;i ++) ans += area(a[1],a[i - 1],a[i]) / 2;
//    printf("%.3f\n",ans);
//}
//int main(){
//    scanf("%d",&n);
//    for(int i = 0;i < n;i ++){
//        int t;scanf("%d",&t);
//        for(int j = 0;j < n;j ++) p[i].rd();
//        for(int j = 0;j < n - 1;j ++){
//            l[++ m] = Line(p[j],p[j + 1] - p[j]);
//        }
//        l[++ m] = Line(p[n - 1],p[1] - p[n - 1]);
//    }
//    hpi();
//    return 0;
//}

/////半平面交
//#include<iostream>
//#include<cstdio>
//#include<cmath>
//#include<algorithm>
//
//using namespace std;
//typedef double db;
//const int N = 1e3 + 10;
//const double eps = 1e-10;
//int n,m,sum;
//struct pt{
//    db x,y;
//    pt () {}
//    pt(db x,db y) : x(x),y(y) {}
//    void rd(){scanf("%lf%lf",&x,&y);}
//}p[N],q[N];
//typedef pt vc;
//vc operator + (pt a,pt b){return vc(a.x + b.x,a.y + b.y);}
//vc operator - (pt a,pt b){return vc(a.x - b.x,a.y - b.y);}
//vc operator * (vc a,db d){return vc(a.x * d,a.y * d);}
//db operator * (vc a,vc b){return a.x * b.x + a.y * b.y;}
//db cross(vc a,vc b){return a.x * b.y - a.y * b.x;}
//struct line{
//    pt p;vc v;
//    db deg;
//    line(){}
//    line(pt p,vc v) : p(p),v(v){deg = atan2(v.y,v.x);}
//    bool operator < (const line& b)const{return deg < b.deg;}
//}l[N],s[N];
//pt lip(line a,line b){//line_intersection_point
//    vc u = a.p - b.p;
//    db t = cross(u,b.v) / cross(b.v,a.v);
//    return a.p + a.v * t;
//}
//int hd,tl;
//void hpi(){//half_plane_intersection
//    sort(l + 1,l + sum + 1);
//    hd = 1,tl = 1;
//    s[hd] = l[1];
//    for(int i = 2;i <= sum;i ++){
//        //若交点在新加入线的右侧，踢出队尾或对首
//        while(hd < tl && cross(l[i].v,q[tl - 1] - l[i].p) <= eps) tl --;
//        while(hd < tl && cross(l[i].v,q[hd] - l[i].p) <= eps) hd ++;
//        s[++ tl] = l[i];//线入队尾
//
//        //如果线段平行，左边的线段入队
//        if(fabs(cross(s[tl].v,s[tl - 1].v)) <= eps){
//            tl --;
//            if(cross(s[tl].v,l[i].p - s[tl].p) > eps) s[tl] = l[i];
//        }
//
//        if(hd < tl){//队中线段超过一段时有交点，记录交点
//            q[tl - 1] = lip(s[tl - 1],s[tl]);
//        }
//    }
//    //判断加入队首时队尾的线是否有效
//    while(hd < tl && cross(s[hd].v,q[tl - 1] - s[hd].p) <= eps) tl --;
//    if(tl - hd <= 1)return;
//    q[tl] = lip(s[hd],s[tl]);
//}
//void solve(){
//    db ans = 0;
//    for(int i = hd;i <= tl;i ++){
//        int tt = i + 1;
//        if(i == tl) tt = hd;
//        ans += cross(q[i],q[tt]);
//    }
//    printf("%.3f\n",ans / 2);
//}
//
//int main(){
//    scanf("%d",&n);
//    for(int i = 1;i <= n;i ++){
//        scanf("%d",&m);
//        for(int j = 1;j <= m;j ++) p[j].rd();
//        for(int j = 1;j <= m;j ++){
//            int tt = j + 1;
//            if(j == m) tt = 1;
//            l[++ sum] = line(p[j],p[tt] - p[j]);
//        }
//    }
//    hpi();
//    solve();
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cmath>
//
//using namespace std;
//typedef long double db;
//typedef long long ll;
//const int N = 1e5 + 10;
//const ll lim = 1e18 + 10;
//const db eps = 1e-18;
//int n,m,sum;
//int dcmp(db x){return x < - eps ? -1 : x > eps;}
//struct pt{
//    db x,y;
//    pt(){}
//    pt(db x,db y) : x(x),y(y) {}
//}p[N];
//typedef pt vc;
//vc operator + (pt a,pt b){return vc(a.x + b.x,a.y + b.y);}
//vc operator - (pt a,pt b){return vc(a.x - b.x,a.y - b.y);}
//vc operator * (vc a,db d){return vc(a.x * d,a.y * d);}
//db operator * (vc a,vc b){return a.x * b.x + a.y * b.y;}
//db cross(vc a,vc b){return a.x * b.y - a.y * b.x;}
//struct line{
//    pt p;vc v;int id;
//    db deg;
//    line(){}
//    line(pt p,vc v,int id) : p(p),v(v),id(id){deg = atan2(v.y,v.x);}
//    bool operator < (const line& b)const{return deg < b.deg;}
//}l[N],q[N];
//pt lip(line a,line b){//line_intersection_point
//    vc u = a.p - b.p;
//    db t = cross(u,b.v) / cross(b.v,a.v);
//    return a.p + a.v * t;
//}
//bool oR(pt p,line a){return dcmp(cross(p - a.p,a.v)) >= 0;}
//bool comp(line a,line b){
//    if(dcmp(a.deg - b.deg) == 0) return oR(b.p,a);
//    return a.deg < b.deg;
//}
//int hd,tl;
//void hpi(){
//    sort(l + 1,l + sum + 1,comp);
//    hd = tl = 1;
//    q[1] = l[1];
//    for(int i = 2;i <= sum;i ++){
//        if(dcmp(l[i].deg - l[i - 1].deg) == 0) continue;
//        while(hd < tl && oR(p[tl - 1],l[i])) tl --;
//        while(hd < tl && oR(p[hd],l[i])) hd ++;
//        q[++ tl] = l[i];
//        if(hd < tl) p[tl - 1] = lip(q[tl],q[tl - 1]);
//    }
//    while(hd < tl && oR(p[tl - 1],q[hd])) tl --;
//    while(hd < tl && oR(p[hd],q[tl])) hd ++;
//    p[tl] = lip(q[hd],q[tl]);
//}
//db w[N],k[N];
//int ans[N],num;
//void solve(){
//    for(int i = hd;i <= tl;i ++){
//        for(int j = 1;j <= n;j ++){
//            if(w[j] == w[q[i].id] && k[j] == k[q[i].id])
//                ans[++ num] = j;
//        }
//    }
//    sort(ans + 1,ans + 1 + num);
//    cout << num << endl;
//    for(int i = 1;i <= num;i ++) cout << ans[i] << " ";
//    cout << endl;
//}
//int main(){
//    cin >> n;
//    for(int i = 1;i <= n;i ++) cin >> w[i];
//    for(int i = 1;i <= n;i ++) cin >> k[i];
//    pt a = pt(0,0),b = pt(lim,0);
//    pt c = pt(lim,lim),d = pt(0,lim);
//    l[++ sum] = line(a,b - a,0);l[++ sum] = line(b,c - b,0);
//    l[++ sum] = line(c,d - c,0);l[++ sum] = line(d,a - d,0);
//    for(int i = 1;i <= n;i ++){
//        pt a = pt(0,w[i]);pt b = pt(1,k[i] + w[i]);
//        l[++ sum] = line(a,b - a,i);
//    }
//    hpi();
//    solve();
//    return 0;
//}
//
//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cmath>
//#define db long double
//#define vc pt
//using namespace std;
//const int N = 1e5 + 10;
//const long long lim = 1e18 + 10;
//const db eps = 1e-18;
//int n,m,cnt,num,l,r,ans[N];
//db k[N],w[N];
//int dcmp(db x){return x < -eps ? -1 : x > eps;}
//struct pt{
//    db x,y;
//    pt(){}
//    pt(db x,db y) : x(x),y(y){}
//}sta[N];
//vc operator + (pt a,pt b){return vc(a.x + b.x,a.y + b.y);}
//vc operator - (pt a,pt b){return vc(a.x - b.x,a.y - b.y);}
//vc operator * (vc a,db d){return vc(a.x * d,a.y * d);}
//db operator * (vc a,vc b){return a.x * b.x + a.y * b.y;}
//db cs(vc a,vc b){return a.x * b.y - a.y * b.x;}
//struct line{
//    pt x,y;int id;
//    double deg;
//    line(){}
//    line(pt x,pt y,int id) : x(x),y(y),id(id) {deg = atan2((y - x).y,(y - x).x);}
//}L[N],q[N];
//bool oR(pt p,line a){return dcmp(cs(p - a.x,a.y - a.x) - eps) > 0;}
//pt lip(line a,line b){//line_intersecton_point
//    vc v = a.y - a.x, u = b.y - b.x,w = a.x - b.x;
//    db t = cs(w,u) / cs(u,v);
//    return a.x + v * t;
//}
//bool HPIcmp(line a,line b){
//    if(dcmp(a.deg - b.deg) == 0) return oR(b.x,a);
//    return a.deg < b.deg;
//}
//int HPI(){//half_plane_intersection
//    sort(L + 1,L + cnt + 1,HPIcmp);
//    l = 1,r = 1;q[1] = L[1];
//    for(int i = 2;i <= cnt;i ++){
//        if(!dcmp(L[i].deg - L[i - 1].deg)) continue;
//        while(l < r && oR(sta[r - 1],L[i])) r --;
//        while(l < r && oR(sta[l],L[i])) l ++;
//        q[++ r] = L[i];
//        if(l < r) sta[r - 1] = lip(q[r],q[r - 1]);
//    }
//    while(l < r && oR(sta[r - 1],q[l])) r --;
//    while(l < r && oR(sta[l],q[r])) l ++;
//    sta[r] = lip(q[l],q[r]);
//    if(r - l + 1 <= 1) return 0;
//    return r - l + 1;
//}
//
//void solve(){
//    for(int i = l;i <= r;i ++){
//        for(int j = 1;j <= n;j ++){
//            if(w[j] == w[q[i].id] && k[j] == k[q[i].id])
//                ans[++ num] = j;
//        }
//    }
//    sort(ans + 1, ans + num + 1);
//    cout << num << endl;
//    for(int i = 1;i <= num;i ++) cout << ans[i] << " ";
//    cout << endl;
//}
//int main(){
//    cin >> n;
//    for(int i = 1;i <= n;i ++) cin >> w[i];
//    for(int i = 1;i <= n;i ++) cin >> k[i];
//    pt a = pt(0,0),b = pt(lim,0);
//    pt c = pt(lim,lim),d = pt(0,lim);
//    L[++ cnt] = line(a,b,0),L[++ cnt] = line(b,c,0);
//    L[++ cnt] = line(c,d,0),L[++ cnt] = line(d,a,0);
//    for(int i = 1;i <= n;i ++){
//        pt a = pt(0,w[i]),b = pt(1,w[i] + k[i]);
//        L[++ cnt] = line(a,b,i);
//    }
//    m = HPI();
//    solve();
//    return 0;
//}


//#include<cstdio>
//#include<cstring>
//#include<iostream>
//#include<cmath>
//#include<algorithm>
//#define db double
//#define vc pt
//using namespace std;
//const int N = 5e4 + 10;
//const db eps = 1e-8;
//int dcmp(double x){return x < -eps ? -1 : x > eps;}
//struct pt{
//    db x,y;
//    pt(){}
//    pt(db x,db y): x(x),y(y){}
//    bool operator < (const pt& b)const{return !dcmp(y - b.y) ? x < b.x : y < b.y;}
//}p[N],s[N],t[5];
//typedef pt vc;
//vc operator + (vc a,vc b){return vc(a.x + b.x,a.y + b.y);}
//vc operator - (pt a,pt b){return vc(a.x - b.x,a.y - b.y);}
//vc operator * (vc a,db d){return vc(a.x * d,a.y * d);}
//db operator * (vc a,vc b){return a.x * b.x + a.y * b.y;}
//db cs(vc a,vc b){return a.x * b.y - a.y * b.x;}
//db cs(pt a,pt b,pt c){return (b - a).x * (c - a).y - (b - a).y * (c - a).x;}
//db len(vc a){return sqrt(a * a);}
//
//int n,m;
//bool Gcmp(pt a,pt b){
//    db k = cs(a - p[1],b - p[1]);
//    if(fabs(k) < eps) return len(p[1] - a) < len(p[1] - b);
//    return k > 0;
//}
//void Graham(){
//    for(int i = 2;i <= n;i ++) if(p[i] < p[1]) swap(p[i],p[1]);
//    sort(p + 2,p + n + 1,Gcmp);
//    s[++ m] = p[1];
//    for(int i = 2;i <= n;i ++){
//        while(m > 1 && cs(s[m] - s[m - 1],p[i] - s[m]) < eps) m --;
//        s[++ m] = p[i];
//    }
//    s[0] = s[m];
//}
//db ans = 1e60;
//void solve(){
//    int l = 1,r = 1,p = 1;
//    db L,R,D,H;
//    for(int i = 0;i < m;i ++){
//        D = len(s[i] - s[i + 1]);
//        while(cs(s[i],s[i + 1],s[p + 1]) - cs(s[i],s[i + 1],s[p]) > - eps) p = (p + 1) % m;
//        while((s[i + 1] - s[i]) * (s[r + 1] - s[i]) - (s[i + 1] - s[i]) * (s[r] - s[i]) > -eps) r = (r + 1) % m;
//        if(i == 0) l = r;
//        while((s[i + 1] - s[i]) * (s[l + 1] - s[i]) - (s[i + 1] - s[i]) * (s[l] - s[i]) < eps) l = (l + 1) % m;
//        L = (s[i + 1] - s[i]) * (s[l] - s[i]) / D;
//        R = (s[i + 1] - s[i]) * (s[r] - s[i]) / D;
//        H = cs(s[i],s[i + 1],s[p]) / D;
//        if(H < 0) H = -H;
//        db tmp = (R - L) * H;
//        if(tmp < ans){
//            ans = tmp;
//            t[0] = s[i] + (s[i + 1] - s[i]) * (R / D);
//            t[1] = t[0] + (s[r] - t[0]) * (H / len(t[0] - s[r]));
//            t[2] = t[1] - (t[0] - s[i]) * ((R - L) / len(s[i] - t[0]));
//            t[3] = t[2] - (t[1] - t[0]);
//        }
//    }
//}
//int main(){
//    scanf("%d",&n);
//    for(int i = 1;i <= n;i ++) scanf("%lf%lf",&p[i].x,&p[i].y);
//    Graham();
//    solve();
//    printf("%.5lf\n",ans);
//    int fir = 0;
//    for(int i = 1;i <= 3;i ++) if(t[i] < t[fir]) fir = i;
//    for(int i = 0;i <= 3;i ++)
//        printf("%.5lf %.5lf\n",fabs(t[(i + fir) % 4].x) > 1e-12?t[(i + fir) % 4].x : 0.00000,fabs(t[(i + fir) % 4].y) > 1e-12 ? t[(i + fir) % 4].y : 0.00000);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cmath>
//#define vc pt
//#define db double
//
//using namespace std;
//const int N = 1e5 + 10;
//const db eps = 1e-8,PI = acos(-1);
//int n,m;
//int dcmp(db x){return x < - eps ? -1 : x > eps;}
//struct pt{
//    db x,y;
//    pt(){}
//    pt(db x,db y) : x(x),y(y) {}
//    bool operator < (const pt& b) const{return !dcmp(y - b.y) ? x < b.x : y < b.y;}
//}p[N],s[N];
//vc operator + (pt a,pt b){return vc(a.x + b.x,a.y + b.y);}
//vc operator - (pt a,pt b){return vc(a.x - b.x,a.y + b.y);}
//vc operator * (vc a,db d){return vc(a.x * d,a.y * d);}
//db operator * (vc a,vc b){return a.x * b.x + a.y * b.y;}
//db cs(vc a,vc b){return a.x * b.y - a.y * b.x;}
//db cs(pt a,pt b,pt c){return (b - a).x * (c - a).y - (b - a).y * (c - a).x;}
//db len(vc a){return sqrt(a * a);}
//vc rt(pt a,db r){
//    db c = cos(r),s = sin(r);
//    return vc(a.x * c - a.y * s,a.x * s + a.y * c);
//}
//bool Gcmp(pt a,pt b){
//    db k = cs(a - p[1],b - p[1]);
//    if(fabs(k) < eps) return len(p[1] - a) < len(p[1] - b);
//    return k >= 0;
//}
//void Graham(){
//    for(int i = 2;i <= n;i ++) if(p[i] < p[1]) swap(p[i],p[1]);
//    for(int i = 1;i <= n;i ++) cout << p[i].x << " " << p[i].y << endl;
//    sort(p + 2,p + n + 1,Gcmp);
//    for(int i = 1;i <= n;i ++)
//        cout << p[i].x << " " << p[i].y << endl;
//    s[++ m] = p[1];
//    for(int i = 2;i <= n;i ++){
//        while(m > 1 && cs(s[m] - s[m - 1],p[i] - s[m]) < eps) m --;
//        s[++ m] = p[i];
//    }
//    s[0] = s[m];
//}
//void solve(db r){
//    db ans = 2 * PI * r;
//    for(int i = 0;i < m;i ++){
//        ans += len(s[i] - s[i + 1]);
//    }
//    printf("%.2f",ans);
//}
//int main(){
//    int tt;
//    scanf("%d",&tt);
//    db a,b,r;
//    scanf("%lf%lf%lf",&a,&b,&r);
//    a /= 2,b /= 2;
//    for(int i = 1;i <= tt;i ++){
//        db x,y,t;
//        scanf("%lf%lf%lf",&x,&y,&t);
//        pt cen = pt(x,y);
//        p[++ n] = rt(pt(b - r,a - r),t) + cen;
//        p[++ n] = rt(pt(b - r,r - a),t) + cen;
//        p[++ n] = rt(pt(r - b,a - r),t) + cen;
//        p[++ n] = rt(pt(r - b,r - a),t) + cen;
//    }
////    for(int i = 1;i <= n;i ++)
////        cout << p[i].x << " " << p[i].y << endl;
//    Graham();
//    cout << m << endl;
//    for(int i = 1;i <= m;i ++) cout << s[i].x << " " << s[i].y << endl;
//    solve(r);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cmath>
//#include<algorithm>
//#define db double
//
//using namespace std;
//const int N = 1e6 + 10;
//const db PI = acos(-1),eps = 1e-10;
//struct pt{
//    db x,y;
//    pt(){}
//    pt(db x,db y) : x(x),y(y){}
//}p[N],q[N];
//pt operator + (pt a,pt b){return pt(a.x + b.x,a.y + b.y);}
//pt operator - (pt a,pt b){return pt(a.x - b.x,a.y - b.y);}
//pt operator * (pt a,db d){return pt(a.x * d,a.y * d);}
//db operator * (pt a,pt b){return a.x * b.x + a.y * b.y;}
//bool operator < (const pt& a,const pt& b){
//    return a.x == b.x ? a.y < b.y : a.x < b.x;
//}
//db cs(pt a,pt b){return a.x * b.y - a.y * b.x;}
//db cs(pt a,pt b,pt c){return (b - a).x * (c - a).y - (b - a).y * (c - a).x;}
//db len(pt a){return sqrt(a * a);}
//pt rt(pt a,db t){
//    db c = cos(t),s = sin(t);
//    return pt(a.x * c - a.y * s, a.x * s + a.y * c);
//}
//
//int main(){
//    int n,cnt = 0;
//    db a,b,r,x,y,t;
//    scanf("%d%lf%lf%lf",&n,&a,&b,&r);
//    a /= 2,b /= 2;
//    for(int i = 1;i <= n;i ++){
//        scanf("%lf%lf%lf",&x,&y,&t);
//        pt cen = pt(x,y);
//        p[++ cnt] = rt(pt(b - r,a - r),t) + cen;
//        p[++ cnt] = rt(pt(b - r,r - a),t) + cen;
//        p[++ cnt] = rt(pt(r - b,r - a),t) + cen;
//        p[++ cnt] = rt(pt(r - b,a - r),t) + cen;
//    }
//    sort(p + 1, p + cnt + 1);
//    int m = 0;
//    for(int i = 1;i <= cnt;i ++){
//        while(m > 1 && cs(q[m - 1],q[m],p[i]) <= 0) m --;
//        q[++ m] = p[i];
//    }
//    int k = m;
//    for(int i = cnt - 1;i >= 1;i --){
//        while(m > k && cs(q[m - 1],q[m],p[i]) <= 0) m --;
//        q[++ m] = p[i];
//    }
//    db ans = 2 * PI * r;
//    for(int i = 1;i < m;i ++) ans += len(q[i] - q[i + 1]);
//    printf("%.2f\n",ans);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<cmath>
//#include<algorithm>
//#define db double
//using namespace std;
//const int N = 1e5 + 10;
//const db eps = 1e-8,PI = acos(-1);
//int dcmp(db x){if(fabs(x) < eps) return 0;return x > 0 ? 1 : -1;}
//struct pt{
//    db x,y;
//    pt(){}
//    pt(db x,db y): x(x),y(y){}
//};
//pt operator - (pt a,pt b){return pt(a.x - b.x,a.y - b.y);}
//pt operator + (pt a,pt b){return pt(a.x + b.x,a.y + a.y);}
//pt operator * (pt a,db d){return pt(a.x * d,a.y * d);}
//db operator * (pt a,pt b){return a.x * b.x + a.y * b.y;}
//db cs(pt a,pt b){return a.x * b.y - a.y * b.x;}
//db cs(pt a,pt b,pt c){return (b - a).x * (c - a).y - (b - a).y * (c - a).x;}
////vector_rotate
//pt vrt(pt a,db t){return pt(a.x * cos(t) - a.y * sin(t),a.x * sin(t) + a.y * cos(t));}
//struct line{
//    pt x,y;
//    db deg;
//    line(){}
//    line(pt x,pt y) : x(x),y(y){deg = atan2((y - x).y,(y - x).x);}
//};
////is_on_Right
//bool oR(pt p,line a){return dcmp(cs(p - a.x,a.y - a.x)) >= 0;}
//pt lip(line a,line b){//line_intersection_point
//    pt v = a.y - a.x,u = b.y - b.x,w = a.x - b.x;
//    db t = cs(w,u) / cs(u,v);
//    return a.x + v * t;
//}
//db cpa(pt p[],int n){//convex_polygon_area
//    db ans = 0;
//    for(int i = 1;i <= n - 2;i ++){
//        ans += cs(p[0],p[i],p[i + 1]);
//    }
//    return ans / 2.0;
//}
//
////凸包
//bool Acmp(pt a,pt b){return a.x == b.x ? a.y < b.y : a.x < b.x;}
//int Andrew(pt p[],int n,pt s[],int m){
//    sort(p + 1,p + 1 + n,Acmp);
//    m = 0;
//    for(int i = 1;i <= n;i ++){
//        while(m > 1 && cs(s[m - 2],s[m - 1],p[i]) < 0) m --;
//        s[m ++] = p[i];
//    }
//    int k = m;
//    for(int i = n - 1;i >= 1;i --){
//        while(m > k && cs(s[m - 2],s[m - 1],p[i]) < 0) m --;
//        s[m ++] = p[i];
//    }
//    if(n > 1) m --;
//    return m;
//}
//
////旋转卡壳
////get_distance
//int gd(pt a){return a.x * a.x + a.y * a.y;}
//int Rc(pt s[],int m){//Rotating_calipers
//    int cur = 1,ans = 0;
//    for(int i = 0;i < m;i ++){
//        while(cs(s[i],s[cur],s[i + 1]) < cs(s[i],s[cur + 1],s[i + 1])) cur = (cur + 1) % m;
//        ans = max(ans ,max(gd(s[cur] - s[i]),gd(s[cur] - s[i + 1])));
//    }
//    return ans;
//}
//
////半平面交
//bool HPIcmp(line a,line b){
//    if(dcmp(a.deg - b.deg) == 0) return oR(b.x,a);
//    return a.deg < b.deg;
//}
//int HPI(line L[],line q[],pt s[],int cnt){//half_plane_intersection
//    sort(L + 1,L + cnt + 1,HPIcmp);
//    int l = 1,r = 1;
//    q[1] = L[1];
//    for(int i = 2;i <= cnt;i ++){
//        if(!dcmp(L[i].deg - L[i - 1].deg)) continue;
//        while(l < r && oR(s[r - 1],L[i])) r --;
//        while(l < r && oR(s[l],L[i])) l ++;
//        q[++ r] = L[i];
//        if(l < r) s[r - 1] = lip(q[r],q[r - 1]);
//    }
//    while(l < r && oR(s[r - 1],q[l])) r --;
//    while(l < r && oR(s[l],q[r])) l ++;
//    s[r] = lip(q[l],q[r]);
//    if(r - l + 1 <= 1) return 0;
//    return r - l + 1;
//}




