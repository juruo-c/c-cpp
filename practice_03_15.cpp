//
// Created by 19116 on 2021/3/15.
//

//#include<iostream>
//
//using namespace std;
//
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int n;cin >> n;
//        int a[110] = {0},b[110] = {0},tim[110] = {0};
//        for(int i = 1;i <= n;i ++) cin >> a[i] >> b[i];
//        for(int i = 1;i <= n;i ++) cin >> tim[i];
//        int ans = 0;
//        for(int i = 1;i <= n;i ++){
//            ans += a[i] - b[i - 1] + tim[i];
//            if(i < n) {
//                int tt = (b[i] - a[i] + 1) / 2;
//                ans += tt;
//                ans = max(ans, b[i]);
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<string>
//#include<algorithm>
//#include<stack>
//using namespace std;
//const int N = 110;
//
//int t,l,w;
//string s;string code[N];
//
//int rd(int &x,string c){
//    int res = 0;
//    while(c[x] < '0' || c[x] > '9' && x < c.size()){
//        if(c[x] == 'n'){
//            x ++;
//            return 1000000;
//        }
//        x ++;
//    }
//    while(c[x] >= '0' && c[x] <= '9'){
//        res *= 10;res += c[x] - '0';
//        x ++;
//    }
//    return res;
//}
//
//int geto(){
//    int res ,x = 3;
//    if(s[2] == 'n') res = rd(x,s);
//    else res = 0;
//    return res;
//}
//
//int check(){
//    int res = 0,now = 0;
//    int a,b,x;
//    stack<int> stk;
//    int flag = 1;
//    bool in[26] = {0};
//    bool ef[26] = {0};
//    for(int i = 1;i <= l;i ++){
//        if(code[i][0] == 'F'){
//            int k = code[i][2] - 'a';
//            if(in[k]) return -1;
//            stk.push(k);in[k] = 1;
//            x = 4;
//            a = rd(x,code[i]);b = rd(x,code[i]);
//            if(b - a > 1000) {
//                if(flag == - 1){
//                    now ++;
//                    res = max(res,now);
//                    ef[k] = 1;
//                }
//            }
//            if(a > b){
//                if(flag == -1) flag = k;
//            }
//        }
//        if(code[i][0] == 'E'){
//            if(stk.empty()) return -1;
//            int k = stk.top();
//            stk.pop();in[k] = 0;
//            if(flag == k) flag = -1;
//            if(ef[k]){
//                ef[k] = 0;
//                now --;
//            }
//        }
//    }
//    if(stk.size()) return -1;
//    return res;
//}
//
//int main(){
//    scanf("%d",&t);
//    while(t --){
//        int ww;
//        scanf("%d ",&l);getline(cin,s);
//        w = geto();
//        for(int i = 1;i <= l;i ++) getline(cin,code[i]);
//        ww = check();
//        if(ww == -1) puts("ERR");
//        else{
//            if(ww == w) puts("Yes");
//            else puts("No");
//        }
//    }
//    return 0;
//}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;
const int N = 110;
int t,l,w;
string o,code[N];

int rd(int &x,string c){
    int res = 0;
    while(c[x] < '0' || c[x] > '9' && x < c.size()){
        if(c[x] == 'n'){
            x ++;
            return 1000000;
        }
        x ++;
    }
    while(c[x] >= '0' && c[x] <= '9'){
        res *= 10;res += c[x] - '0';
        x ++;
    }
    return res;
}

int geto(){
    int res ,x = 3;
    if(o[2] == 'n') res = rd(x,o);
    else res = 0;
    return res;
}

int check(){
    int res = 0,now = 0;
    int a,b,x;
    stack<int> s;
    int flag = -1;
    bool in[26] = {0};
    bool ef[26] = {0};
    for(int i = 1;i <= l;i ++){
        if(code[i][0] == 'F'){
            int k = code[i][2] - 'a';
            if(in[k]) return -1;
            s.push(k);in[k] = 1;
            x = 4;
            a = rd(x,code[i]);b = rd(x,code[i]);
            if(b - a > 1000){
                if(flag == -1){
                    now ++;
                    res = max(res,now);
                    ef[k] = 1;
                }
            }
            if(a > b){
                if(flag == -1) flag = k;
            }
        }
        if(code[i][0] == 'E'){
            if(s.empty()) return -1;
            int k = s.top();
            s.pop();
            in[k] = 0;
            if(flag == k) flag = -1;
            if(ef[k]){
                ef[k] = false;
                now --;
            }
        }
    }
    if(s.size()) return -1;
    return res;
}
int main(){
    scanf("%d",&t);
    while(t --){
        int ww;
        scanf("%d ",&l);getline(cin,o);
        w = geto();
        for(int i = 1;i <= l;i ++) getline(cin,code[i]);
        ww = check();
        if(ww == -1) puts("ERR");
        else{
            if(ww == w) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}