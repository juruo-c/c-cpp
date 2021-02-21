//
// Created by Administrator on 2021/2/18.
//

//#include<cstdio>
//#include<cmath>
//#include<cstring>
//#include<iostream>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//const int INF = 0x3f3f3f3f;
//const int N = 110;
//const double eps = 1e-8;
//int n,tot,cnt;
//double G[N][N];
//bool vis[N];
//int sgn(double x){x < -eps ? -1 : x > eps;}
//struct Point{
//    double x,y;
//    int num;
//    Point (double x = 0,double y = 0) : x(x),y(y) {}
//}P[N];
//typedef Point Vector;
//struct Line{
//    Point s,e;
//    Line(){}
//    Line (Point s,Point e) : s(s),e(e) {}
//    double length(){
//        return sqrt((s.x - e.x) * (s.x - e.x) + (s.y - e.y) * (s.y - e.y));
//    }
//}L[20];
//double operator ^ (const Vector& a,const Vector& b) {
//    return a.x * b.y - a.y * b.x;
//}
//Vector operator - (const Point& a,const Point& b) {
//    return Vector(a.x - b.x,a.y - b.y);
//}
//bool segment_intersection(Line a,Line b){
//    double c1 = (a.e - a.s) ^ (b.e - a.s),c2 = (a.e - a.s) ^ (b.s - a.s);
//    double c3 = (b.e - b.s) ^ (a.e - b.s),c4 = (b.e - b.s) ^ (a.s - b.s);
//    return (sgn(c1) * sgn(c2) < 0 && sgn(c3) * sgn(c4) < 0);
//}
//struct node{
//    double d;
//    int s;
//    bool operator < (const node& b) const{
//        return d > b.d;
//    }
//};
//double d[N];
//void dijkstra(int s){
//    for(int i = 1;i <= cnt;i ++) d[i] = INF;
//    priority_queue<node> q;
//    d[s] = 0;
//    q.push((node){0,s});
//    while(!q.empty()){
//        int u = q.top().s;q.pop();
//        if(vis[u]) continue;
//        vis[u] = true;
//        for(int i = 1;i <= cnt;i ++){
//            if(!vis[i] && sgn(G[u][i]) && sgn(d[i] - (d[u] + G[u][i])) > 0){
//                d[i] = d[u] + G[u][i];
//                q.push((node){d[i],i});
//            }
//        }
//    }
//}
//int main(){
//    while(~scanf("%d",&n) && n != -1){
//        tot = 0;//有效线段个数
//        memset(vis,0,sizeof(vis));
//        memset(G,0,sizeof(G));
//        for(int i = 0;i < n;i ++){
//            double x;
//            scanf("%lf",&x);
//            double a,b,c,d;
//            scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
//            if(a > 5) L[++ tot] = Line(Point(x,0),Point(x,a));
//            if(b < 5 && c > 5) L[++ tot] = Line(Point(x,b),Point(x,c));
//            if(d < 5) L[++ tot] = Line(Point(x,d),Point(x,10));
//        }
////        for(int i = 1;i <= tot;i ++) cout << L[i].s.x << " " << L[i].s.y << " " << L[i].e.x << " " << L[i].e.y << endl;
//        cnt = 1;//图中节点个数
//        P[cnt] = Point(0,5);
//        P[cnt].num = 0;
//        for(int i = 1;i <= tot;i ++){
//            Point e = L[i].e,s = L[i].s;
//            P[++cnt] = e;P[cnt].num = i;
//            P[++cnt] = s;P[cnt].num = i;
//        }
//        P[++cnt] = Point(10,5);
//        P[cnt].num = tot + 1;
//
//        for(int i = 1;i <= cnt;i ++){
//            cout << P[i].x << " " <<P[i].y << " " << P[i].num << endl;
//        }
//
//        for(int i = 1;i <= cnt;i ++){//建图
//            for(int j = i + 1;j <= cnt;j ++){
//                Line tt = Line(P[i],P[j]);
//                bool flag = true;
//                for(int k = P[i].num + 1;k < P[j].num ;k ++){//判断该边是否合法（判线段相交
//                    if(segment_intersection(tt,L[k])){
//                        flag = false;
//                        break;
//                    }
//                }
//                if(flag) G[i][j] = tt.length();
//            }
//        }
//        for(int i = 1; i <= cnt;i ++){
//            for(int j = 1;j <= cnt;j ++){
//                cout << G[i][j] << " ";
//            }
//            cout << endl;
//        }
//        dijkstra(1);
//        printf("%.2f\n",d[cnt]);
//    }
//    return 0;
//}

//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<cmath>
//#include<iostream>
//#include<queue>
//
//using namespace std;
//const int N = 300;
//const double eps = 1e-8;
//struct Point{
//    double x,y;
//    Point (){}
//    Point(double x,double y) : x(x),y(y){}
//    Point operator - (const Point& p) const{return Point(x - p.x,y - p.y);}
//    double operator ^ (const Point& p) const{return x * p.y - y * p.x;}
//}P[N];
//double dis(const Point& a,const Point& b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}
//int sgn(double x){return x < -eps ? -1 : x > eps;}
//struct Line{
//    Point s,e;
//    Line(){}
//    Line(Point s,Point e) : s(s),e(e) {}
//}L[N];
//
//bool segment_intersection(const Line& a,const Line& b){
//    double c1 = (b.s - a.s) ^ (b.e - a.s),c2 = (b.s - a.e) ^ (b.e - a.e);
//    double c3 = (a.s - b.s) ^ (a.e - b.s),c4 = (a.s - b.e) ^ (a.e - b.e);
//    bool f1 = sgn(c1 * c2) < 0;
//    bool f2 = sgn(c3 * c4) < 0;
//    return f1 && f2;
//}
//
//int n,cnt1,cnt2;
//int tot,head[N],net[N * N],to[N * N],q[N],inq[N];
//double d[N],val[N];
//void add(int u,int v,double w){
//    to[++ tot] = v;
//    net[tot] = head[u];
//    val[tot] = w;
//    head[u] = tot;
//}
//
//void addedge(int u,int v){
//    Line tt = Line(P[u],P[v]);
//    for(int i = 1;i <= cnt2;i ++){
//        if(segment_intersection(tt,L[i])) return;
//    }
//    add(u,v,dis(P[u],P[v]));add(v,u,dis(P[u],P[v]));
//}
//
//void spfa(){
//    for(int i = 1;i <= cnt1;i ++) d[i] = 1e9,inq[i] = 0;
//    int l = 1,r = 1;d[1] = 0;q[1] = 1;inq[1] = 1;
//    while(l <= r){
//        int x = q[l ++];
//        for(int i = head[x];i;i = net[i]){
//            int u = to[i];
//            if(d[x] + val[i] < d[u]){
//                d[u] = d[x] + val[i];
//                if(!inq[u]){
//                    inq[u] = 1;
//                    q[++ r] = u;
//                }
//            }
//        }
//        inq[x] = 0;
//    }
//}
////bool vis[N];
////void spfa(){
////    for(int i = 1;i <= cnt1;i ++) d[i] = 1e9;
////    memset(vis,0,sizeof(vis));
////    queue<int> q;
////    d[1] = 0;
////    q.push(1);
////    vis[1] = 1;
////    while(!q.empty()){
////        int u = q.front();q.pop();
////        vis[u] = 0;
////        for(int i = head[u];i;i = net[i]){
////            int v = to[i];
////            if(d[v] > d[u] + val[i]){
////                d[v] = d[u] + val[i];
////                if(!vis[v]){
////                    q.push(v);
////                    vis[v] = 1;
////                }
////            }
////        }
////    }
////}
//int main(){
//    while(~scanf("%d",&n) && n != -1){
//        memset(head,0,sizeof(head));
//        cnt2 = 0,tot = 0;
//        cnt1 = 1;P[1].x = 0;P[1].y = 5;
//        for(int i = 1;i <= n;i ++){
//            double x;scanf("%lf",&x);
//            int lim = cnt1;
//            for(int j = 1;j <= 4;j ++){
//                double y;scanf("%lf",&y);
//                P[++ cnt1] = Point(x,y);
//                for(int k = 1;k <= lim;k ++) addedge(k,cnt1);
//            }
//            L[++ cnt2] = Line(P[cnt1],Point(x,10));
//            L[++ cnt2] = Line(P[cnt1 - 2],P[cnt1 - 1]);
//            L[++ cnt2] = Line(Point(x,0),P[cnt1 - 3]);
//        }
//        P[++ cnt1].x = 10;P[cnt1].y = 5;
//        for(int i = 1;i < cnt1;i ++) addedge(i,cnt1);
//        spfa();
//        printf("%.2f\n",d[cnt1]);
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e5 + 10;
//const double eps = 1e-8;
//int sgn(double x){return x < -eps ? -1 : x > eps;}
//struct Point{
//    double x,y;
//    Point(){}
//    Point (double x,double y) : x(x),y(y) {}
//    Point operator - (const Point& b)const{return Point(x - b.x,y - b.y);}
//    double operator ^ (const Point& b)const{return x * b.y - y * b.x;}
//};
//struct Line{
//    Point s,e;
//    Line(){}
//    Line (Point s,Point e) : s(s),e(e){}
//}L[N];
//int n,flag[N];
//int ans[N],tot;
//bool segment_intersection(Line a,Line b){
//    double c1 = (a.e - a.s) ^ (b.e - a.s),c2 = (a.e - a.s) ^ (b.s - a.s);
//    double c3 = (b.e - b.s) ^ (a.e - b.s),c4 = (b.e - b.s) ^ (a.s - b.s);
//    bool f1 = sgn(c1 * c2) < 0,f2 = sgn(c3 * c4) < 0;
//    return f1 && f2;
//}
//int main(){
//    while(~scanf("%d",&n) && n){
//        memset(flag,0,sizeof(flag));
//        for(int i = 1;i <= n;i ++){
//            scanf("%lf%lf%lf%lf",&L[i].s.x,&L[i].s.y,&L[i].e.x,&L[i].e.y);
//        }
//        printf("Top sticks:");
//        tot = 0;
//        for(int i = 1;i <= n;i ++){
//            int j;
//            for(j = i + 1;j <= n;j ++){
//                if(segment_intersection(L[i],L[j]))
//                    break;
//            }
//            if(j > n) ans[++ tot] = i;
//        }
//        for(int i = 1;i < tot;i ++) printf(" %d,",ans[i]);
//        printf(" %d.\n",n);
//    }
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<cstdio>
//
//using namespace std;
//const int N = 50;
//const double eps = 1e-8;
//int sgn(double x){return x < -eps ? -1 : x > eps;}
//
//struct Point{
//    double x,y;
//    Point(){}
//    Point(double x,double y) : x(x) ,y(y) {}
//    Point operator - (const Point& b)const {return Point(x - b.x,y - b.y);}
//    double operator ^ (const Point& b)const {return x * b.y - y * b.x;}
//}P[N << 1];
//struct Line{
//    Point s,e;
//    Line(){}
//    Line(Point s,Point e) : s(s),e(e) {}
//}L[N];
//int n,cnt,ans;
//bool segment_intersection(Line a,Line b){
//    double c1 = (a.e - a.s) ^ (b.s - a.s),c2 = (a.e - a.s) ^ (b.e - a.s);
//    double c3 = (b.e - b.s) ^ (a.s - b.s),c4 = (b.e - b.s) ^ (a.e - b.s);
//    bool f1 = sgn(c1 * c2) < 0,f2 = sgn(c3 * c4) < 0;
//    return f1 && f2;
//}
//
//int main(){
//    scanf("%d",&n);
//    for(int i = 1;i <= n;i ++){
//        scanf("%lf%lf%lf%lf",&L[i].s.x,&L[i].s.y,&L[i].e.x,&L[i].e.y);
//        P[++ cnt] = L[i].s;
//        P[++ cnt] = L[i].e;
//    }
//
//    Point ed;
//    scanf("%lf%lf",&ed.x,&ed.y);
//
//    ans = 1e8;
//    for(int i = 1;i <= cnt;i ++){
//        Line tt = Line(P[i],ed);
//        int res = 0;
//        for(int j = 1;j <= n;j ++){
//            if(segment_intersection(tt,L[j])) res ++;
//        }
//        ans = min(ans,res);
//    }
//    printf("Number of doors = %d\n",n ? ans + 1 : 1);
//    return 0;
//}

#include<cstdio>
#include<iostream>

using namespace std;
const double eps = 1e-8;
int sgn(double x){return x < -eps ? -1 : x > eps;}
struct Point{
    double x,y;
    Point(){}
    Point(double x,double y) : x(x),y(y){}
    Point operator - (const Point& b)const{return Point(x - b.x,y - b.y);}
    double operator ^ (const Point& b)const {return x * b.y - y * b.x;}
};

struct Line{
    Point s,e;
    Line(){}
    Line(Point s,Point e) : s(s),e(e){}
}L[10];

bool segment_intersection(Line a,Line b){
    double c1 = (a.e - a.s) ^ (b.e - a.s),c2 = (a.e - a.s) ^ (b.s - a.s);
    double c3 = (b.e - b.s) ^ (a.e - b.s),c4 = (b.e - b.s) ^ (a.s - b.s);
    bool f1 = sgn(c1 * c2) <= 0,f2 = sgn(c3 * c4) <= 0;
    return f1 && f2;
}

int main(){
    int n;
    scanf("%d",&n);
    while(n --){
        Point A,B;
        scanf("%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y);
        L[1] = Line(A,B);
        Point lt,rb,lb,rt;
        scanf("%lf%lf%lf%lf",&lt.x,&lt.y,&rb.x,&rb.y);
        if(lt.x > rb.x) swap(lt.x,rb.x);
        if(lt.y < rb.y) swap(lt.y,rb.y);
        lb.x = lt.x,lb.y = rb.y;
        rt.x = rb.x,rt.y = lt.y;
        L[2] = Line(lt,rt);
        L[3] = Line(rt,rb);
        L[4] = Line(rb,lb);
        L[5] = Line(lb,lt);
        bool flag = false;
        for(int i = 2;i <= 5;i ++){
            if(segment_intersection(L[1],L[i])){
                flag = true;
                break;
            }
        }
        if(min(A.x,B.x) >= lt.x && max(A.x,B.x) <= rb.x && min(A.y,B.y) >= rb.y && max(A.y,B.y) <= lt.y) flag = true;
        if(flag) puts("T");
        else puts("F");
    }
    return 0;
}