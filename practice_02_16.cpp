//
// Created by Administrator on 2021/2/16.
//

//#include<cstdio>
//#include<cmath>
//
//using namespace std;
//int gcd(int a,int b){return !b ? a : gcd(b,a % b);}
//int main(){
//    int n,m,p;
//    scanf("%d%d%d",&n,&m,&p);
//    double s = p * m / 2.0;
//    double b = gcd(n,m) + gcd(abs(n - p),m) + p;
//    printf("%d\n",(int)(s + 1 - b / 2.0));
//    return 0;
//}

//#include<cstdio>
//#include<cmath>
//#include<algorithm>
//
//using namespace std;
//struct Point;
//typedef Point Vector;
//const double esp = 1e-8;
//const int N = 1e5 + 10;
//int sgn(double x){
//    return x < -esp ? -1 : x > esp;
//}
//bool cmp(double a,double b){
//    return !sgn(fabs(a - b));
//}
//struct Point{
//    double x,y;
//    Point(){}
//    Point(double x,double y):x(x),y(y){}
//    double length(){return sqrt(x * x + y * y);}
//    void read(){scanf("%lf%lf",&x,&y);}
//    Point operator + (Point v){return {x + v.x,y + v.y};}
//    Vector operator - (Point p){return {x - p.x,y - p.y};}
//    double operator ^ (Vector v){return x * v.y - y * v.x;}
//    double operator * (Vector v){return x * v.x + y * v.y;}
//    Vector operator * (double d){return {x * d,y * d};}
//    Vector operator / (double d){return {x / d,y / d};}
//    bool operator == (Point p){return !cmp(x,p.x) && !cmp(y,p.y);}
//    bool operator < (Point p){if(cmp(x,p.x) == 0) return y < p.y;return x < p.x;}
//};
//Point base;
//bool grahamcmp(Point& p1,Point& p2){
//    if(sgn((p1 - base) ^ (p2 - base)) == 0)
//        return (p1 - base).length() < (p2 - base).length();
//    return ((p1 - base) ^ (p2 - base)) > 0;
//}
//Point p[N];
//Point stk[N];
//int n;
//int graham(){
//    for(int i = 2;i <= n;i ++){
//        if(p[i] < p[1]) swap(p[i],p[1]);
//    }
//    base = p[1];
//    sort(p + 2,p + 1 + n,grahamcmp);
//    int k = 0;
//    stk[++ k] = p[1];stk[++ k] = p[2];
//    for(int i = 3;i <= n;i ++){
//        while(k > 1 && sgn((stk[k] - stk[k - 1]) ^ (p[i] - stk[k - 1])) < 0) k--;
//        stk[++ k] = p[i];
//    }
//    return k;
//}
//int main(){
//    scanf("%d",&n);
//    for(int i = 1;i <= n;i ++){
//        scanf("%lf%lf",&p[i].x,&p[i].y);
//    }
//    int k = graham();
//    double len = 0;
//    for(int i = 1;i < k;i ++){
//        len += (stk[i + 1] - stk[i]).length();
//    }
//    len += (stk[1] - stk[k]).length();
//    printf("%.2lf\n",len);
//    return 0;
//}
//#include<cstdio>
//#include<cmath>
//#include<algorithm>
//
//using namespace std;
//const double esp = 1e-8;
//const int N = 110;
//struct Point;
//typedef Point Vector;
//int sgn(double x){return x < -esp ? -1 : x > esp;}
//int cmp(double a,double b){return sgn(fabs(a - b));}
//struct Point{
//    double x,y;
//    Point (){}
//    Point (double x,double y) : x(x),y(y){}
//    double length(){return sqrt(x * x + y * y);}
//    void read(){scanf("%lf%lf",&x,&y);}
//    Point operator + (Vector v){return {x + v.x,y + v.y};}
//    Vector operator - (Point p){return {x - p.x,y - p.y};}
//    double operator ^ (Vector v){return x * v.y - y * v.x;}
//    double operator * (Vector v){return x * v.x + y * v.y;}
//    Vector operator * (double d){return {x * d,y * d};}
//    Vector operator / (double d){return {x / d,y / d};}
//    bool operator == (Point p){return !cmp(x,p.x) && !cmp(y,p.y);}
//    bool operator < (Point p){if(cmp(x,p.x) == 0) return y < p.y;return x < p.x;}
//}p[N],stk[N];
//int n;
//int Andrew(){
//    sort(p + 1,p + 1 + n);
//    int len = 0;
//    for(int i = 1;i <= n;i ++){
//        while(len > 1 && sgn((stk[len] - stk[len - 1]) ^ (p[i] - stk[len - 1])) < 0) len --;
//        stk[++ len] = p[i];
//    }
//    int k = len;
//    for(int i = n - 1;i >= 1;i --){
//        while(len > k && sgn((stk[len] - stk[len - 1]) ^ (p[i] - stk[len - 1])) < 0) len --;
//        stk[++ len] = p[i];
//    }
//    len --;
//    return len;
//}
//int main(){
//    while(~scanf("%d",&n) && n){
//        for(int i = 1;i <= n;i ++) p[i].read();
//        if(n < 2){
//            printf("0.00\n");
//            continue;
//        }
//        if(n == 2){
//            printf("%.2lf\n",(p[2] - p[1]).length());
//            continue;
//        }
//        int k = Andrew();
//        double ans = 0;
//        for(int i = 1;i < k;i ++){
//            ans += (stk[i + 1] - stk[i]).length();
//        }
//        ans += (stk[1] - stk[k]).length();
//        printf("%.2lf\n",ans);
//    }
//    return 0;
//}

//#include<cstdio>
//#include<cmath>
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//const int N = 5e4 + 10;
//const double esp = 1e-8;
//int n;
//struct Point;
//typedef Point Vector;
//typedef long long ll;
//int sgn(double x){return x < -esp ? -1 : x > esp;}
//int cmp(double a,double b){return sgn(fabs(a - b));}
//struct Point{
//    double x,y;
//    Point(){}
//    Point(double x,double y) : x(x), y(y) {}
//    double length(){return sqrt(x * x + y * y);}
//    void read(){scanf("%lf%lf",&x,&y);}
//    Point operator + (Vector v){return {x + v.x,y + v.y};}
//    Vector operator - (Point p){return {x - p.x,y - p.y};}
//    double operator ^ (Vector v){return x * v.y - y * v.x;}
//    double operator * (Vector v){return x * v.x + y * v.y;}
//    Vector operator * (double d){return {x * d,y * d};}
//    Vector operator / (double d){return {x / d,y / d};}
//    bool operator == (Point p){return !cmp(x,p.x) && !cmp(y,p.y);}
//    bool operator < (Point p){if(!cmp(x,p.x)) return y < p.y;return x < p.x;}
//}p[N],stk[N << 1];
//int Andrew(){
//    sort(p + 1,p + n + 1);
//    int len = 0;
//    for(int i = 1;i <= n;i ++){
//        while(len > 1 && sgn((stk[len] - stk[len - 1]) ^ (p[i] - stk[len - 1])) < 0) len --;
//        stk[++ len] = p[i];
//    }
//    int k = len;
//    for(int i = n - 1;i >= 1;i --){
//        while(len > k && sgn((stk[len] - stk[len - 1]) ^ (p[i] - stk[len - 1])) < 0) len --;
//        stk[++ len] = p[i];
//    }
//    len --;
//    return len;
//}
//bool insameline(Point a,Point b,Point c){
//    Vector v1 = b - a,v2 = c - a;
//    double t = v1 * v2 / v1.length() / v2.length();
//    if(!sgn(fabs(t) - 1)) return true;
//    return false;
//}
//ll dist2(Point a,Point b){return (a - b) * (a - b);}
//ll rotating_calipers(int len){
//    if(len == 2){return dist2(stk[1],stk[2]);}
//    ll ans = 0;
//    int cur = 1;
//    bool flag = 1;
//    for(int i = 0;i < len;i ++){
//        if(!insameline(stk[i],stk[(i + 1) % len],stk[(i + 2) % len])) flag = 0;
//    }
//    if(flag){
//        sort(stk,stk + len);
//        return dist2(stk[0],stk[len - 1]);
//    }
//    for(int i = 0;i < len;i ++) stk[i] = stk[i + 1];
//    stk[len] = stk[0];
//    for(int i = 0;i < len;i ++){
//        while(((stk[cur] - stk[i + 1]) ^ (stk[i] - stk[i + 1])) < ((stk[cur + 1] - stk[i + 1]) ^ (stk[i] - stk[i + 1])))
//            cur = (cur + 1) % len;
//
//        ans = max(ans,max(dist2(stk[i],stk[cur]),dist2(stk[i + 1],stk[cur])));
//    }
//    return ans;
//}
//int main(){
//    scanf("%d",&n);
//    for(int i = 1;i <= n;i ++) p[i].read();
//    int len = Andrew();
//    printf("%lld\n",rotating_calipers(len));
//    return 0;
//}

//#include<cstdio>
//#include<cmath>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e3 + 10;
//const double eps = 1e-8;
//int t,n;
//struct Point;
//typedef Point Vector;
//struct Point{
//    double x,y;
//    Point(){}
//    Point (double x,double y) : x(x),y(y){}
//    Vector operator - (Point p){return {x - p.x,y - p.y};}
//    double operator ^ (Vector v){return x * v.y - y * v.x;}
//};
//struct Line{
//    Point s,e;
//    Line(){}
//    Line(Point a,Point b):s(a),e(b){}
//};
//Point p[N];
//Line L[N],que[N];
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
//Point getintersectPoint(Line a,Line b){
//    double a1 = a.s.y - a.e.y,b1 = a.e.x - a.s.x,c1 = a.s ^ a.e;
//    double a2 = b.s.y - b.e.y,b2 = b.e.x - b.s.x,c2 = b.s ^ b.e;
//    return (Point){(c1 * b2 - c2 * b1) / (a2 * b1 - a1 * b2),(a2 * c1 - a2 * c2) / (a1 * b2 - a2 * b1)};
//}
//
//bool onRight(Line a,Line b,Line c){
//    Point o = getintersectPoint(b,c);
//    if(((a.e - a.s) ^ (o - a.s)) < 0) return true;
//    return false;
//}
//
//bool halfPlaneIntersection(){
//    sort(L,L + n,cmp);
//    int head = 0,tail = 0,cnt = 0;
//    for(int i = 0;i < n - 1;i ++){
//        if(fabs(getangle(L[i]) - getangle(L[i + 1])) < eps)continue;
//        L[cnt ++] = L[i];
//    }
//    L[cnt ++] = L[n - 1];
//
//    for(int i = 0;i < cnt;i ++){
//        while(tail - head > 1 && onRight(L[i],que[tail - 1],que[tail - 2])) tail --;
//        while(tail - head > 1 && onRight(L[i],que[head],que[head + 1])) head ++;
//        que[tail ++] = L[i];
//    }
//
//    while(tail - head > 1 && onRight(que[head],que[tail - 1],que[tail - 2])) tail --;
//    while(tail - head > 1 && onRight(que[tail - 1],que[head],que[head + 1])) head ++;
//    if(tail - head < 3) return false;
//    return true;
//}
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
//        if(halfPlaneIntersection()) printf("YES\n");
//        else printf("NO\n");
//    }
//    return 0;
//}

//#include<cstdio>
//#include<iostream>
//using namespace std;
//
//const int N = 2e7 + 10;
//char s[N];
//int r[N];
//int cnt = 1;
//void read(){//预处理字符串，处理成2n+1长度
//    s[0] = '~';
//    s[1] = '|';
//    char c = getchar();
//    while(c < 'a' || c > 'z') c = getchar();
//    while(c >= 'a' && c <= 'z'){
//        s[++ cnt] = c;
//        s[++ cnt] = '|';
//        c = getchar();
//    }
//}
//int main(){
//    read();
//    int mid = 0,rb = 0;
//    for(int i = 1;i <= cnt;i ++){//对处理后的字符串计算回文半径r[]
//        if(i < rb) r[i] = min(r[(mid << 1) - i],rb - i);
//        else r[i] = 1;
//        while(s[i - r[i]] == s[i + r[i]]) r[i] ++;
//        if(r[i] + i > rb) rb = r[i] + i,mid = i;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//using namespace std;
//const int N = 11000002;
//char s[N << 1];
//int r[N << 1],cnt;
//void read(){//预处理字符串，将字符串长度处理成2n + 1
//    char c = getchar();
//    cnt = 1;
//    s[0] = '~';s[1] = '|';
//    while(c < 'a' || c > 'z') c= getchar();
//    while(c >= 'a' && c <= 'z') s[++ cnt] = c,s[++ cnt] = '|',c = getchar();
//}
//int main(){
//    read();
//    int rb = 0,mid = 0;
//    for(int i = 1;i <= cnt;i++){//计算回文半径r[],答案是r[](max) - 1
//        if(i <= rb) r[i] = min(r[(mid << 1) - i],rb - i + 1);
//        while(s[i - r[i]] == s[i + r[i]]) r[i] ++;
//        if(r[i] + i > rb) rb = r[i] + i - 1,mid = i;
//    }
//    return 0;
//}

//#include<cstdio>
//#include<cmath>
//#include<algorithm>
//
//using namespace std;
//const double eps = 1e-8;
//const int N = 5e4 + 10;
//struct Point;
//typedef Point Vector;
//int sgn(double x){return x < -eps ? -1 : x > eps;}
//struct Point{
//    double x,y;
//    Point(double x,double y) : x(x),y(y){}
//    Point(){}
//    Vector operator - (Point p){return {x - p.x,y - p.y};}
//    double operator ^ (Vector v){return x * v.y - y * v.x;}
//    double operator * (Point p){return x * p.x + y * p.y;}
//    bool operator < (Point a){if(!sgn(fabs(x - a.x))) return y < a.y;return x < a.x;}
//}p[N],stk[N << 1];
//int n;
//int Andrew(){
//    sort(p,p + n);
//    int len = 0;
//    for(int i = 0;i < n;i ++){
//        while(len > 1 && sgn((stk[len - 1] - stk[len - 2]) ^ (p[i] - stk[len - 2])) <= 0) len --;
//        stk[len ++] = p[i];
//    }
//    int k = len;
//    for(int i = n - 2;i >= 0;i --){
//        while(len > k && sgn((stk[len - 1] - stk[len - 2]) ^ (p[i] - stk[len - 2])) <= 0) len --;
//        stk[len ++] = p[i];
//    }
//    if(n > 1) len --;
//    return len;
//}
//int dist2(Point a,Point b){return (a - b) * (a - b);}
//double rotating_calipers(int len){
//    int cur = 1,ans = 0;
//    stk[len] = stk[0];
//    for(int i = 0;i < len;i ++){
//        while(((stk[cur] - stk[i]) ^ (stk[i + 1] - stk[i])) < ((stk[cur + 1] - stk[i]) ^ (stk[i + 1] - stk[i])))
//            cur = (cur + 1) % len;
//        ans = max(ans,max(dist2(stk[i],stk[cur]),dist2(stk[i + 1],stk[cur])));
//    }
//    return (double)ans;
//}
//int main(){
//    scanf("%d",&n);
//    for(int i = 0;i < n;i ++){
//        scanf("%d%d",&p[i].x,&p[i].y);
//    }
//    int len = Andrew();
//    printf("%d\n",(int)rotating_calipers(len));
//    return 0;
//}

