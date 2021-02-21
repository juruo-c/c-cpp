//
// Created by Administrator on 2021/2/17.
//

//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//const int N = 5e4 + 10;
//struct Node{
//    int x,y;
//}p[N],ch[N];
//int n,m = 2;
//int dist2(Node a,Node b){
//    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
//}
//int cross(Node p0,Node p1,Node p2){
//    return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
//}
//
//bool cmp(Node a,Node b){
//    int xx  = cross(p[0],a,b);
//    if(xx > 0) return true;
//    if(xx < 0) return false;
//    return dist2(p[0],a) < dist2(p[0],b);
//}
//
//void graham(){
//    sort(p + 1,p + n,cmp);
//    ch[0] = p[0],ch[1] = p[1];
//    for(int i = 2;i < n;i ++){
//        while(m > 0 && cross(ch[m - 1],ch[m],p[i]) <= 0) m --;
//        ch[++ m] = p[i];
//    }
//}
//
//int rotating_calipers(){
//    int j = 1,ans = 0;
//    for(int i = 0;i < m;i ++){
//        while(cross(ch[i],ch[i + 1],ch[j]) < cross(ch[i],ch[i + 1],ch[j + 1]))
//            j = (j + 1) % m;
//        ans = max(ans, max(dist2(ch[i],ch[j]),dist2(ch[i + 1],ch[j])));
//    }
//    return ans;
//}
//int main(){
//    scanf("%d",&n);
//    for(int i = 0;i < n;i ++){
//        scanf("%d%d",&p[i].x,&p[i].y);
//        if(p[i].x < p[0].x || (p[i].x == p[0].x && p[i].y < p[0].y))swap(p[i],p[0]);
//    }
//    graham();
//    printf("%d",rotating_calipers());
//    return 0;
//}
//#include<bits/stdc++.h>//还是放上来吧
//using namespace std;
//const int maxn=5e4+5;
//int n,m=2;
//struct node{
//    int x,y;
//}p[maxn],ch[maxn];
//
//inline int read(){//快读
//    int x=0,f=1;char a=getchar();
//    while(!isdigit(a)) {if(a=='-') f=-1;a=getchar();}
//    while(isdigit(a)) {x=(x<<3)+(x<<1)+a-'0';a=getchar();}
//    return x*f;
//}
//
//int dis(node a,node b){//距离
//    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
//}
//
//int cross(node p0,node p1,node p2){//叉积
//    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
//}
//
//bool cmp(node A,node B)//排序（以右手定则来排序）（核心）PS：叉积，以及其右手定则自行度娘
//{
//    int xx=cross(p[0],A,B);
//    if(xx>0)return true;
//    if(xx<0)return false;
//    return dis(p[0],A)<dis(p[0],B);
//}
//
//void TuBao(){
//    sort(p+1,p+n,cmp);
//    ch[0]=p[0];ch[1]=p[1];
//    for(int i=2;i<n;++i){
//        while(m>0&&cross(ch[m-1],ch[m],p[i])<=0) m--;
//        ch[++m]=p[i];
//    }
//}
//
//int rotating_calipers(){//旋转卡壳（题解中有讲特判的，其实吧，我觉得没必要，毕竟dis中该怼掉的也会怼掉）
//    int j=1,ans=0;
//    for(int i=0;i<m;++i){
//        while(cross(ch[i],ch[i+1],ch[j])<cross(ch[i],ch[i+1],ch[j+1])) j=(j+1)%m;//这就是栗子，会被一条链卡（qia）死
//        ans=max(ans,max(dis(ch[i],ch[j]),dis(ch[i+1],ch[j])));
//    }
//    return ans;
//}
//
//int main(){
//    freopen("a.txt","r",stdin);
//    n=read();
//    for(int i=0;i<n;++i){
//        p[i].x=read(),p[i].y=read();
//        if(p[i].x<p[0].x||(p[i].x==p[0].x && p[i].y<p[0].y)) swap(p[i],p[0]);//找最左下点
//    }
//    TuBao();
//    printf("%d",rotating_calipers());
//    return 0;
//}

//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//const int N = 5e4 + 10;
//int n,m ;
//struct node{
//    int x,y;
//}p[N],ch[N];
//
//int dis(node a,node b){
//    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
//}
//int cross(node p0,node p1,node p2){
//    return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
//}
//int cmp(node a,node b){
//    return (a.x != b.x) ? (a.x < b.x) : (a.y < b.y);
//}
//void Andrew(){
//    sort(p,p + n,cmp);
//    for(int i = 0;i < n;i ++){
//        while(m > 1 && cross(ch[m - 2],ch[m - 1],p[i]) <= 0) m--;
//        ch[m ++] = p[i];
//    }
//    int k = m;
//    for(int i = n - 2;i >= 0;i --){
//        while(m > k && cross(ch[m - 2],ch[m - 1],p[i]) <= 0) m --;
//        ch[m ++] = p[i];
//    }
//    if(n > 1) m --;
//}
//int rotating_calipers(){
//    int cur = 1,ans = 0;
//    for(int i = 0;i < m;i ++){
//        while(cross(ch[i],ch[i + 1],ch[cur]) < cross(ch[i],ch[i + 1],ch[cur + 1]))
//            cur = (cur + 1) % m;
//        ans = max(ans, max(dis(ch[i],ch[cur]),dis(ch[i + 1],ch[cur])));
//    }
//    return ans;
//}
//int main(){
//    scanf("%d",&n);
//    for(int i = 0;i < n;i ++)scanf("%d%d",&p[i].x,&p[i].y);
//    Andrew();
//    printf("%d\n",rotating_calipers());
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cmath>
//
//using namespace std;
//const int N = 1e3 + 10;
//const double eps = 1e-5;
//int t,n;
//typedef struct Point{
//    double x,y;
//    Point(double x = 0,double y = 0){x = x,y = y;}
//}Vector;
//Vector operator - (Point a,Point b){return Vector(b.x - a.x,b.y - a.y);}
//double operator ^ (Vector a,Vector b){return a.x * b.y - a.y * b.x;}
//Point operator * (Point a,double d){return Point(a.x * d,a.y * d);}
//Point operator + (Point a,Point b){return Point(a.x + b.x,a.y + b.y);}
//struct Line{
//    Point s,e;
//    Line(){}
//    Line(Point a,Point b){s = a,e = b;}
//};
//Point p[N];
//Line L[N],q[N];
//
//double getangle(Vector a){
//    return atan2(a.y,a.x);
//}
//double getangle(Line a){
//    return atan2(a.e.y - a.s.y,a.e.x - a.s.x);
//}
//
//bool cmp(Line a,Line b){
//    Vector va = a.e - a.s,vb = b.e - b.s;
//    double A = getangle(va),B = getangle(vb);
//    if(fabs(A - B) < eps) return ((va) ^ (b.e - a.s)) >= 0;
//    return A < B;
//}
//
////Point get_intersection_point(Line a,Line b){
////    Vector v1 = a.e - a.s,v2 = b.e - b.s;
////    Vector u = a.e - b.e;
////    double t1= (v2 ^ u) / (v1 ^ v2);
////    return a.e + v1 * t1;
////}
//
//Point get_intersection_point(Line a,Line b){
//    double a1 = a.s.y - a.e.y,b1 = a.e.x - a.s.x,c1 = a.s ^ a.e;
//    double a2 = b.s.y - b.e.y,b2 = b.e.x - b.s.x,c2 = b.s ^ b.e;
//    return Point((c1 * b2 - c2 * b1) / (a2 * b1 - a1 * b2),(a2 * c1 - a1 * c2) / (a1 * b2 - a2 * b1));
//}
//
//bool onRight(Line a,Line b,Line c){
//    Point o = get_intersection_point(b,c);
//    if(((a.e - a.s) ^ (o - a.s)) < 0) return true;
//    return false;
//}
//
//bool Half_Plane_Intersection(){
//    sort(L,L + n,cmp);
//    int head = 0,tail = 0,cnt = 0;
//    for(int i = 0;i < n - 1;i ++){
//        if(fabs(getangle(L[i]) - getangle(L[i + 1])) < eps) continue;
//        L[cnt ++] = L[i];
//    }
//    L[cnt ++] = L[n - 1];
//
//    for(int i = 0;i < cnt;i ++){
//        while(tail - head > 1 && onRight(L[i],q[tail - 1],q[tail - 2])) tail --;
//        while(tail - head > 1 && onRight(L[i],q[head],q[head + 1]))head ++;
//        q[tail ++] = L[i];
//    }
//
//    while(tail - head > 1 && onRight(q[head],q[tail - 1],q[tail - 2])) tail --;
//    while(tail - head > 1 && onRight(q[tail - 1],q[head],q[head + 1])) head ++;
//    if(tail - head < 3) return false;
//    return true;
//}
//
//bool judge(){
//    double ans = 0;
//    for(int i = 1;i < n - 1;i ++){
//        ans += ((p[i] - p[0]) ^ (p[i + 1] - p[0]));
//    }
//    return ans < 0;
//}
//
//int main(){
//    scanf("%d",&t);
//    while(t --){
//        scanf("%d",&n);
//        for(int i = n - 1;i >= 0;i --){
//            scanf("%lf%lf",&p[i].x,&p[i].y);
//        }
//        if(judge()){
//            for(int i = 0;i < n;i ++){
//                L[i] = Line(p[(i + 1) % n],p[i]);
//            }
//        }
//        else{
//            for(int i = 0;i < n;i ++){
//                L[i] = Line(p[i],p[(i + 1) % n]);
//            }
//        }
//        if(Half_Plane_Intersection()) printf("YES\n");
//        else printf("NO\n");
//    }
//    return 0;
//}

//#include <algorithm>
//#include <cstdio>
//#include <cmath>
//using namespace std;
//const int maxn = 1e3;
//const double EPS = 1e-5;
//int T, n;
//typedef struct Grid {
//    double x, y;
//    Grid(double a = 0, double b = 0) {x = a, y = b;}
//} Point, Vector;
//Vector operator - (Point a, Point b) {return Vector(b.x - a.x, b.y - a.y);}
//double operator ^ (Vector a, Vector b) {return a.x * b.y - a.y * b.x;}//叉乘
//struct Line {
//    Point s, e;
//    Line() {}
//    Line(Point a, Point b) {s = a, e = b;}
//};
//Point p[maxn];
//Line L[maxn], que[maxn];
//
////得到极角角度
//double getAngle(Vector a) {
//    return atan2(a.y, a.x);
//}
//
////得到极角角度
//double getAngle(Line a) {
//    return atan2(a.e.y - a.s.y, a.e.x - a.s.x);
//}
//
////排序：极角小的排前面，极角相同时，最左边的排在最后面，以便去重
//bool cmp(Line a, Line b) {
//    Vector va = a.e - a.s, vb = b.e - b.s;
//    double A =  getAngle(va), B = getAngle(vb);
//    if (fabs(A - B) < EPS) return ((va) ^ (b.e - a.s)) >= 0;
//    return A < B;
//}
//
////Vector operator * (Point a,double d){return {a.x * d,a.y * d};}
////Vector operator + (Vector a,Vector b){return {a.x + b.x,a.y + b.y};}
////Point get_intersection_point(Line a,Line b){
////    Vector v1 = a.e - a.s,v2 = b.e - b.s;
////    Vector u = a.e - b.e;
////    double t1= (v2 ^ u) / (v1 ^ v2);
////    return a.e + v1 * t1;
////}
////得到两直线相交的交点
//Point getIntersectPoint(Line a, Line b) {
//    double a1 = a.s.y - a.e.y, b1 = a.e.x - a.s.x, c1 = a.s.x * a.e.y - a.e.x * a.s.y;
//    double a2 = b.s.y - b.e.y, b2 = b.e.x - b.s.x, c2 = b.s.x * b.e.y - b.e.x * b.s.y;
//    return Point((c1*b2-c2*b1)/(a2*b1-a1*b2), (a2*c1-a1*c2)/(a1*b2-a2*b1));
//}
//
////判断 b,c 的交点是否在 a 的右边
//bool onRight(Line a, Line b, Line c) {
//    Point o = getIntersectPoint(b, c);
//    if (((a.e - a.s) ^ (o - a.s)) < 0) return true;
//    return false;
//}
//
//bool HalfPlaneIntersection() {
//    sort(L, L + n, cmp);//排序
//    int head = 0, tail = 0, cnt = 0;//模拟双端队列
//    //去重，极角相同时取最后一个。
//    for (int i = 0; i < n - 1; i++) {
//        if (fabs(getAngle(L[i]) - getAngle(L[i + 1])) < EPS) {
//            continue;
//        }
//        L[cnt++] = L[i];
//    }
//    L[cnt++] = L[n - 1];
//
//
//    for (int i = 0; i < cnt; i++) {
//        //判断新加入直线产生的影响
//        while(tail - head > 1 && onRight(L[i], que[tail - 1], que[tail - 2])) tail--;
//        while(tail - head > 1 && onRight(L[i], que[head], que[head + 1])) head++;
//        que[tail++] = L[i];
//    }
//    //最后判断最先加入的直线和最后的直线的影响
//    while(tail - head > 1 && onRight(que[head], que[tail - 1], que[tail - 2])) tail--;
//    while(tail - head > 1 && onRight(que[tail - 1], que[head], que[head + 1])) head++;
//    if (tail - head < 3) return false;
//    return true;
//}
//
////判断输入点的顺序，如果面积 < 0，说明输入的点为顺时针，否则为逆时针
//bool judge() {
//    double ans = 0;
//    for (int i = 1; i < n - 1; i++) {
//        ans += ((p[i] - p[0]) ^ (p[i + 1] - p[0]));
//    }
//    return ans < 0;
//}
//
//int main()
//{
//    scanf("%d", &T);
//    while (T--) {
//        scanf("%d", &n);
//        for (int i = n - 1; i >= 0; i--) {
//            scanf("%lf %lf", &p[i].x, &p[i].y);
//        }
//
//        if (judge()) {//判断输入顺序，保证逆时针连边。
//            for (int i = 0; i < n; i++) {
//                L[i] = Line(p[(i + 1)%n], p[i]);
//            }
//        } else {
//            for (int i = 0; i < n; i++) {
//                L[i] = Line(p[i], p[(i + 1)%n]);
//            }
//        }
//
//        if (HalfPlaneIntersection()) printf("YES\n");
//        else printf("NO\n");
//    }
//
//    return 0;
//}

//#include<cstdio>
//#include<cmath>
//
//using namespace std;
//const int N = 5e3 + 10;
//const double eps = 1e-8;
//int n,t;
//struct Point{
//    double x,y;
//    Point(double x = 0,double y = 0) : x(x),y(y){}
//};
//Point q[N],a[N],b[N];
//typedef Point Vector;
//Vector operator + (Point a,Point b){return Vector(a.x + b.x,a.y + b.y);}
//Vector operator - (Point a,Point b){return Vector(a.x - b.x,a.y - b.y);}
//int sgn(double x){return x < - eps ? -1 : x > eps;}
//int dcmp(double x,double y){
//    if(fabs(x - y) < eps) return 0;
//    if(x < y) return -1;
//    return 1;
//}
//double Cross(Vector a,Vector b){return a.x * b.y - a.y * b.x;}
//int relation(Point a,Point b,Point c){
//    int flag = sgn(Cross((b - a),(c - a)));
//    if(flag < 0) return 1;
//    else if(flag > 0) return -1;
//    return 0;
//}
//
//bool check(){
//    for(int i = 0;i < n * 2;i ++){
//        for(int j = i + 1;j < 2 * n;j ++){
//            if(!dcmp(q[i].x,q[j].x) && !dcmp(q[i].y,q[j].y)) continue;
//            bool flag = true;
//            for(int k = 0;k < n;k ++){
//                if(relation(q[i],q[j],a[k]) * relation(q[i],q[j],b[k]) > 0){
//                    flag = false;
//                    break;
//                }
//            }
//            if(flag) return true;
//        }
//    }
//    return false;
//}
//int main(){
//    scanf("%d",&t);
//    while(t --){
//        scanf("%d",&n);
//        int k = 0;
//        for(int i = 0;i < n;i ++){
//            double x,xx,y,yy;
//            scanf("%lf%lf%lf%lf",&x,&y,&xx,&yy);
//            q[k ++] = {x,y},q[k ++] = {xx,yy};
//            a[i] = {x,y};b[i] = {xx,yy};
//        }
//        if(check()) puts("Yes!");
//        else puts("No!");
//    }
//    return 0;
//}

//#include<cstdio>
//#include<algorithm>
//#include<cmath>
//
//using namespace std;
//const int N = 1e3 + 10;
//const double eps = 1e-8;
//int T,n;
//typedef struct Point{
//    double x,y;
//    Point(double a = 0,double b = 0){x = a,y = b;}
//}Point, Vector;
//Vector operator - (Point a,Point b){return Vector(b.x - a.x,b.y - a.y);}
//double operator ^ (Vector a,Vector b){return a.x * b.y - a.y * b.x;}
//struct Line{
//    Point s, e;
//    Line(){}
//    Line(Point a,Point b){s = a,e = b;}
//};
//Point p[N];
//Line L[N],q[N];
//double getangle(Vector a){return atan2(a.y,a.x);}
//double getangle(Line a){return atan2(a.e.y - a.s.y,a.e.x - a.s.x);}
//
//bool cmp(Line a,Line b){
//    Vector va = a.e - a.s,vb = b.e - b.s;
//    double A = getangle(va),B = getangle(vb);
//    if(fabs(A - B) < eps) return ((va) ^ (b.e - a.s)) >= 0;
//    return A < B;
//}
//
//Point get_intersection_point(Line a,Line b){
//    double a1 = a.s.y - a.e.y,b1 = a.e.x - a.s.x,c1 = a.s.x * a.e.y - a.e.x * a.s.y;
//    double a2 = b.s.y - b.e.y,b2 = b.e.x - b.s.x,c2 = b.s.x * b.e.y - b.e.x * b.s.y;
//    return Point((c1 * b2 - c2 * b1) / (a2 * b1 - a1 * b2), (a2 * c1 - a1 * c2) / (a1 * b2 - a2 * b1));
//}
//
//bool onRight(Line a,Line b,Line c){
//    Point o = get_intersection_point(b,c);
//    if(((a.e - a.s) ^ (o - a.s)) < 0) return true;
//    return false;
//}
//
//bool Half_Plane_Intersection(){
//    sort(L,L + n,cmp);
//    int head = 0,tail = 0,cnt = 0;
//
//    for(int i = 0;i < n - 1;i ++){
//        if(fabs(getangle(L[i]) - getangle(L[i + 1])) < eps) continue;
//        L[cnt ++] = L[i];
//    }
//
//    for(int i = 0;i < cnt;i ++){
//        while(tail - head > 1 && onRight(L[i],q[tail - 1],q[tail - 2])) tail --;
//        while(tail - head > 1 && onRight(L[i],q[head],q[head + 1])) head ++;
//        q[tail ++] = L[i];
//    }
//    while(tail - head > 1 && onRight(q[head],q[tail - 1],q[tail - 2])) tail --;
//    while(tail - head > 1 && onRight(q[tail - 1],q[head],q[head + 1])) head ++;
//    if(tail - head < 3) return false;
//    return true;
//}
//
//bool judge(){
//    double ans = 0;
//    for(int i = 1;i < n - 1;i ++){
//        ans += ((p[i] - p[0]) ^ (p[i + 1] - p[0]));
//    }
//    return ans < 0;
//}
//int main(){
//    scanf("%d",&T);
//    while(T --){
//        scanf("%d",&n);
//        for(int i = n - 1;i >= 0;i --){
//            scanf("%lf%lf",&p[i].x,&p[i].y);
//        }
//        if(judge()){
//            for(int i = 0;i < n;i ++){
//                L[i] = Line(p[(i + 1) % n], p[i]);
//            }
//        }
//        else {
//            for(int i = 0;i < n;i ++){
//                L[i] = Line(p[i], p[(i + 1) % n]);
//            }
//        }
//
//        if(Half_Plane_Intersection()) printf("YES\n");
//        else printf("NO\n");
//    }
//    return 0;
//}

//#include<algorithm>
//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<cmath>
//
//using namespace std;
//const int N = 1e3 + 10;
//const double eps = 1e-5;
//int T,n;
//typedef struct P{
//    double x,y;
//    P(double a = 0,double b = 0){x = a,y = b;}
//}Point,Vector;
//Vector operator - (Point a,Point b){return Vector(b.x - a.x,b.y - a.y);}
//double operator ^ (Vector a,Vector b){return a.x * b.y - a.y * b.x;}
//struct Line{
//    Point s,e;
//    Line(){}
//    Line(Point a,Point b){s = a,e = b;}
//};
//Point p[N];
//Line L[N],q[N];
//
//double getangle(Vector a){return atan2(a.y,a.x);}
//double getangle(Line a){return atan2(a.e.y - a.s.y,a.e.x - a.s.x);}
//bool cmp(Line a,Line b){
//    Vector v1 = a.e - a.s,v2 = b.e - b.s;
//    double A = getangle(v1),B = getangle(v2);
//    if(fabs(A - B) < eps) return ((v1) ^ (b.e - a.s)) >= 0;
//    return A < B;
//}
//
//Point get_intersection_point(Line a,Line b){
//    double a1 = a.s.y - a.e.y,b1 = a.e.x - a.s.x,c1 = a.s.x * a.e.y - a.s.y * a.e.x;
//    double a2 = b.s.y - b.e.y,b2 = b.e.x - b.s.x,c2 = b.s.x * b.e.y - b.s.y * b.e.x;
//    return Point((c1 * b2 - c2 * b1) / (a2 * b1 - a1 * b2),(a2 * c1 - a1 * c2) / (a1 * b2 - a2 * b1));
//}
//
//bool onRight(Line a,Line b,Line c){
//    Point o = get_intersection_point(b,c);
//    if(((a.e - a.s) ^ (o - a.s)) < 0) return true;
//    return false;
//}
//bool HPI(){
//    sort(L,L + n,cmp);
//    int head = 0,tail = 0,cnt = 0;
//    for(int i = 0;i < n - 1;i ++){
//        if(fabs(getangle(L[i]) - getangle(L[i + 1])) < eps) continue;
//        L[cnt ++] = L[i];
//    }
//    L[cnt ++] = L[n - 1];
//
//    for(int i = 0;i < cnt;i ++){
//        while(tail - head > 1 && onRight(L[i],q[tail - 1],q[tail - 2])) tail --;
//        while(tail - head > 1 && onRight(L[i],q[head],q[head + 1])) head ++;
//        q[tail ++] = L[i];
//    }
//    while(tail - head > 1 && onRight(q[head],q[tail - 1],q[tail - 2])) tail --;
//    while(tail - head > 1 && onRight(q[tail - 1],q[head],q[head + 1])) head ++;
//    if(tail - head < 3) return false;
//    return true;
//}
//
//bool judge(){
//    double ans = 0;
//    for(int i = 1;i < n - 1;i ++)ans += ((p[i] - p[0]) ^ (p[i + 1] - p[0]));
//    return ans;
//}
//
//int main(){
//    scanf("%d",&T);
//    while(T --){
//        scanf("%d",&n);
//        for(int i = n - 1;i >= 0;i --) scanf("%lf%lf",&p[i].x,&p[i].y);
//        if(judge()){
//            for(int i = 0;i < n;i ++){
//                L[i] = Line(p[(i + 1) % n],p[i]);
//            }
//        }
//        else{
//            for(int i = 0;i < n;i ++){
//                L[i] = Line(p[i],p[(i + 1) / n]);
//            }
//        }
//        if(HPI()) puts("YES");
//        else puts("No");
//    }
//    return 0;
//}


#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double eps = 1e-8;
int T;
int sgn(double x){return x < -eps ? -1 : x > eps;}
struct Point{
    double x,y;
    Point (){}
    Point (double x,double y): x (x),y (y){}
    Point operator + (const Point& b) const{return Point(x + b.x,y + b.y);}
    Point operator - (const Point& b) const{return Point(x - b.x,y - b.y);}
    double operator * (const Point& b)const{return x * b.x + y * b.y;}
    double operator ^ (const Point& b)const{return x * b.y - y * b.x;}
}p[4];

struct Line{
    Point s,e;
    Line(){}
    Line(Point s,Point e): s(s),e(e){}

    //返回pair second 为0重合 为1平行 为2相交且first为交点
    pair<Point,int> operator &(const Line& b)const {
        Point res = s;
        if(sgn((s - e) ^ (b.s - b.e)) == 0){
            if(sgn((b.s - s) ^ (b.e - s)) == 0) return make_pair(res,0);
            return make_pair(res,1);
        }
        double t = ((s - b.s) ^ (b.s - b.e)) / ((s - e) ^ (b.s - b.e));
        res.x += (e.x - s.x) * t;
        res.y += (e.y - s.y) * t;
        return make_pair(res,2);
    }
};

int main(){
    scanf("%d",&T);
    puts("INTERSECTING LINES OUTPUT");
    while(T--){
        for(int i = 0;i < 4;i ++){
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        Line l[2];
        l[0] = Line(p[0],p[1]);
        l[1] = Line(p[2],p[3]);

        pair <Point,int> ans = l[0] & l[1];
        if(ans.second == 0) puts("LINE");
        else if(ans.second == 1) puts("NONE");
        else{
            printf("POINT %.2f %.2f\n",ans.first.x,ans.first.y);
        }
    }
    puts("END OF OUTPUT");
    return 0;
}