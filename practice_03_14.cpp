//
// Created by littlething on 2021/3/14.
//

//#include<iostream>
//
//using namespace std;
//class Music{
//public:
//    Music(int type,string name,int rent,bool sta) : type(type),name(name),rent(rent),sta(sta) {}
//    void Print(){
//        switch(type){
//            case 1:
//                cout << "黑胶片" ;
//                break;
//            case 2:
//                cout << "CD";
//                break;
//            case 3:
//                cout << "VCD" ;
//                break;
//            case 4:
//                cout << "DVD";
//                break;
//        }
//        cout << "[" << name << "]" ;
//        if(sta) cout << "已出租" << endl;
//        else cout << "未出租" << endl;
//    }
//    void Fee(int op){
//        if(!op) return;
//        if(!sta) cout << "未产生租金" << endl;
//        else cout << "当前租金为" << rent * op << endl;
//    }
//private:
//    int type;
//    string name;
//    int rent;
//    bool sta;
//};
//int main(){
//    int n;cin >> n;
//    int type,rent;
//    bool sta;string name;
//    int op;
//    for(int i = 0;i < n;i ++){
//        cin >> type >> name >> rent >> sta;
//        Music mu(type,name,rent,sta);
//        cin >> op;
//        mu.Print();
//        mu.Fee(op);
//    }
//    return 0;
//}

//#include<iostream>
//#include<cmath>
//#include<iomanip>
//#define db double
//using namespace std;
//class CT{
//public:
//    CT(db a,db b,db c) : a(a),b(b),c(c){
//        if(a > c) swap(a,c);
//        if(b > c) swap(b,c);
//        if(a + b <= c) type = "no triangle";
//        else{
//            if(a == b){
//                if(b == c) type = "equilateral triangle";
//                else if(fabs(c * c - a * a - b * b) < 0.01) type = "isosceles right triangle";
//                else type = "isosceles triangle";
//            }
//            else if(a * a + b * b == c * c) type = "right triangle";
//            else type = "general triangle" ;
//        }
//    }
//    string gettype(){
//        return type;
//    }
//    db cal_area(){
//        db p = (a + b + c) / 2;
//        return sqrt(p * (p - a) * (p - b) * (p - c));
//    }
//    ~CT(){a = 0,b = 0,c = 0,type = "none";}
//
//private :
//    db a,b,c;string type;
//};
//int main(){
//    int n;cin >> n;
//    db a,b,c;
//    for(int i = 1;i <= n;i ++){
//        cin >> a >> b >> c;
//        CT tt(a,b,c);
//        cout << tt.gettype() ;
//        if(tt.gettype() != "no triangle") cout << ", " << fixed << setprecision(1) << tt.cal_area() << endl;
//        else cout << endl;
//    }
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e4 + 10;
//int main(){
//    int n;cin >> n;
//    pair<pair<int,int>,pair<int,int> > a[N];
//    for(int i = 1;i <= n;i ++){
//        int x,y;
//        cin >> a[i].first.first >> a[i].first.second >> x >> y;
//        a[i].second.first = a[i].first.first + x;
//        a[i].second.second = a[i].first.second + y;
//    }
//    int x,y;cin >> x >> y;
//    int fl = 0;
//    for(int i = n;i >= 1;i --){
//        if(x >= a[i].first.first && x <= a[i].second.first && y >= a[i].first.second && y <= a[i].second.second){
//            cout << i << endl;
//            fl = 1;
//            break;
//        }
//    }
//    if(!fl) cout << - 1 << endl;
//    return 0;
//}


//#include<iostream>
//
//using namespace std;
//
//int main(){
//    int n;cin >> n;
//    int a[110];
//    for(int i = n;i >= 0;i --){
//        cin >> a[i];
//    }
//    for(int i = n;i >= 0;i --){
//        if(i < n && a[i] > 0) cout << "+";
//        else if(i < n && a[i] < 0){
//            a[i] = -a[i];
//            cout << "-";
//        }
//        if(a[i] && a[i] != 1 ) cout << a[i];
//        if(a[i] == 1 && !i) cout << a[i];
//        if(i > 1 && a[i]) cout << "x^" << i;
//        else if(i > 0 && a[i]) cout << "x";
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main(){
//    int n;cin >> n;
//    int a[110];
//    for(int i = n;i >= 0;i --) cin >> a[i];
//    for(int i = n;i >= 0;i --){
//        if(!a[i]) continue;
//        if(a[i] > 0 && i != n) cout << "+";
//        else if(a[i] < 0){
//            a[i] = - a[i];
//            cout << "-";
//        }
//        if(a[i] != 1) cout << a[i];
//        else if(a[i] == 1 && !i) cout << 1;
//        if(i > 1) cout << "x^" << i;
//        else if(i) cout << "x";
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main(){
//    int n,na,nb;
//    cin >> n >> na >> nb;
//    int a[220],b[220];
//    for(int i = 0;i < na;i ++) cin >> a[i];
//    for(int i = 0;i < nb;i ++) cin >> b[i];
//    int ca = 0,cb = 0;
//    int cura = 0,curb = 0;
//    for(int i = 1;i <= n;i ++){
//        int nowa = a[cura],nowb = b[curb];
//        if(nowa == nowb){
//            cura = (cura + 1) % na;
//            curb = (curb + 1) % nb;
//            continue;
//        }
//        cout << nowa << " " << nowb << endl;
//        if(nowa == 0 && (nowb == 2 || nowb == 3)) ca ++;
//        else if(nowa == 0 && (nowb == 1 || nowb == 4)) cb ++;
//        if(nowa == 1 && (nowb == 3 || nowb == 0)) ca ++;
//        else if(nowa == 1 && (nowb == 2 || nowb == 4)) cb ++;
//        if(nowa == 2 && (nowb == 1 || nowb == 4)) ca ++;
//        else if(nowa == 2 && (nowb == 0 || nowb == 3)) cb ++;
//        if(nowa == 3 && (nowb == 2 || nowb == 4)) ca ++;
//        else if(nowa == 3 && nowb == 1 || nowb == 0) cb ++;
//        if(nowa == 4 && (nowb == 2 || nowb == 3)) cb ++;
//        else if(nowa == 4 && (nowb == 1 || nowb == 0)) ca ++;
//        cout << "       " << ca << " " << cb << endl;
//        cura = (cura + 1) % na;
//        curb = (curb + 1) % nb;
//    }
//    cout << ca << " " << cb << endl;
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main(){
//    int l,r;
//    cin >> l >> r;
//    int cnt = 0;
//    for(int i = l;i <= r;i ++){
//        int t = i;
//        while(t){
//            if(t % 10 == 2) cnt ++;
//            t /= 10;
//        }
//    }
//    cout << cnt << endl;
//    return 0;
//}


#include<iostream>
#include<sstream>
#include<stack>

using namespace std;

int main(){
    int t;cin >> t;
    while(t --){
        int cf = 0;
        int l;string tim;
        cin >> l >> tim;
        int fl = 0,n ;
        for(int i = 0;i < tim.size();i ++){
            if(tim[i] == 'n') fl = 1;
            if(!isdigit(tim[i])) tim[i] = ' ';
        }
        stringstream ss(tim);
        ss >> n;if(!fl) n = 0;
        cout << n << endl;
        string s;int confli[110] = {0};
        int conf[110] = {0};
        int error = 0;
        char ch[200];int top = 0;
        int ans = 0;
        getchar();
        int last = 0;
        for(int i = 0;i < l;i ++){
            getline(cin,s);
            if(s[0] == 'F') cf ++;
            if(s[0] == 'E'){
                if(cf == 0){
                    error = 1;
                    break;
                }
                cf --;
                top --;int confl = 0;
                if(cf == 0){
                    for(int j = i - (i - last + 1) / 2;j >= last;j --){
                        if(conf[j]) confl = 0;
                        else confl += confli[j];
                    }
                    last = i + 1;
                    ans = max(ans,confl);
                }
                continue;
            }
            int flag = 0;
            for(int j = 0;j < top;j ++){
                if(ch[j] == s[2]){
                    flag = 1;
                    error = 1;
                    break;
                }
            }
            if(!flag) ch[top ++] = s[2];
            if(isdigit(s[4]) && !isdigit(s[6])) confli[i] = 1;
            if(!isdigit(s[4] && isdigit(s[6]))) conf[i] = 1;
        }
        if(cf) error = 1;
        if(error) {
            cout << "ERR" << endl;
            continue;
        }
//        for(int i = 0;i < tot;i ++){
//            if(!confli[i]) ans = 0;
//            else ans += confli[i];
//        }
        cout << ans << endl;
        if(ans == n) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}