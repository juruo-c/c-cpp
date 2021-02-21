//
// Created by Administrator on 2021/2/15.
//

#include<bits/stdc++.h>

using namespace std;
const int N = 5e3 + 7,M = 5e4 + 7,INF = 0x3f3f3f3f;
const double DINF = 1e18,eps = 1e-8;
struct Point{
    double x,y;
    Point(double x = 0,double y = 0) : x(x),y(y){}
};
typedef Point Vector;
Vector operator + (Vector a,Vector b){return Vector(a.x + b.x,a.y + b.y);}
Vector operator - (Point a,Point b){return Vector(a.x - b.x,a.y - b.y);}
Vector operator * (Vector a,double p){return Vector(a.x * p,a.y * p);}
Vector operator / (Vector a,double p){return Vector(a.x / p,a.y / p);}
bool operator < (const Point& a,const Point& b){return a.x < b.x ||(a.x == b.x && a.y < b.y);}
int sgn(double x){return x < - eps ? -1 : x > eps;}
bool operator == (const Point& a,const Point& b){return !sgn(a.x - b.x) && !sgn(a.y - b.y);}
double Dot(Vector a,Vector b){return a.x * b.x + a.y * b.y;}
double Cross(Vector a,Vector b){return a.x * b.y - a.y * b.x;}
bool ToLeftTest(Point a,Point b,Point c){
    return Cross(b - a,c - b) > 0;
}
double length(Vector a){return sqrt(Dot(a,a));}
double angle(Vector a,Vector b){acos(Dot(a,b) / length(a) / length(b));}
double Area(Vector a,Vector b,Vector c){return Cross(b - a,c - a);}
Vector Rotate(Vector a,double rad){
    return Vector(a.x * cos(rad) - a.y * sin(rad),a.x * sin(rad) + a.y * cos(rad));
}
struct Line{
    Vector v;
    Point p;
    Line(Vector v,Point p) : v(v),p(p){}
    Point point_in_line(double t){
        return v + (p - v) * t;
    }
};
int relation(Point a,Point b,Point c){
    int t = sgn(Cross(b - a,c - a));
    if(t < 0) return 1;
    else if(t > 0) return -1;
    return 0;
}
Point get_line_intersection(Point p,Vector v,Point q,Vector w){
    Vector u = p - q;
    double t = Cross(w,u) / Cross(v,w);
    return p + v * t;
}
double distance_point_to_line(Point p,Point a,Point b){
    Vector v1 = b - a,v2 = p - a;
    return fabs(Cross(v1,v2) / length(v1));
}
double distance_point_to_segment(Point p,Point a,Point b){
    if(a == b) return length(p - a);
    Vector v1 = b - a,v2 = p - a,v3 = p - b;
    if(sgn(Dot(v1,v2)) < 0) return length(v2);
    if(sgn(Dot(v1,v3)) > 0) return length(v3);
    return fabs(Cross(v1,v2) / length(v1));
}
Point get_line_projection(Point p,Point a,Point b){
    Vector v = b - a;
    return a + v * (Dot(v,p - a) / Dot(v,v));
}
bool OnSegment(Point p,Point a1,Point a2){
    return sgn(Cross(a1 - p,a2 - p)) == 0 && sgn(Dot(a1 - p,a2 - p)) < 0;
}
//bool segment_proper_intersection(Point a1,Point a2,Point b1,Point b2){
//    double c1 = Cross(a2 - a1,b1 - a1),c2 = Cross(a2 - a1,b2 - a1);
//    double c3 = Cross(b2 - b1,a1 - b1),c4 = Cross(b2 - b1,a2 - b1);
//    return sgn(c1) * sgn(c2) < 0 && sgn(c3) * sgn(c4) < 0;
//}
bool segment_proper_intersection(Point a1,Point a2,Point b1,Point b2){
    double c1 = Cross(a2 - a1,b1 - a1),c2 = Cross(a2 - a1,b2 - a1);
    double c3 = Cross(b2 - b1,a1 - b1),c4 = Cross(b2 - b1,a2 - b1);
    return sgn(c1) * sgn(c2) <= 0 && sgn(c3) * sgn(c4) <= 0;
}

double PolygonArea(Point p[],int n){
    double ans = 0;
    for(int i = 0;i < n;i ++)
        ans += Cross(p[i],p[(i + 1) % n]) / 2;
    return fabs(ans);
}
int is_point_in_polygon(Point poly[],Point p,int n){
    int wn = 0;
    for(int i = 0;i < n;i ++){
        if(OnSegment(p,poly[i],poly[(i + 1) % n])) return -1;
        int k = sgn(Cross(poly[(i + 1) % n] - poly[i],p - poly[i]));
        int d1 = sgn(poly[i].y - p.y);
        int d2 = sgn(poly[(i + 1)% n].y - p.y);
        if(k > 0 && d1 <= 0 && d2 > 0) wn ++;
        if(k < 0 && d2 <= 0 && d1 > 0) wn --;
    }
    if(wn != 0) return 1;
    return 0;
}