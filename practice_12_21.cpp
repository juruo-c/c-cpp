////#include<iostream>
////#include<string>
////#include<algorithm>
////
////using namespace std;
////
////int main()
////{
////    int t; cin >> t;
////    while(t --){
////        string s;
////        cin >> s;
////        if(s.length() == 1){
////            cout << 1 << endl;
////            continue;
////        }
////        while(1){
////            if(s.length() % 2){
////                int len = s.length();
////                string st,stt;
////                st = s.substr(0,len/2);
////                stt = s.substr(len/2 + 1);
////                reverse(stt.begin(),stt.end());
////                if(st == stt) s = st;
////                else{
////                    cout << s.length() << endl;
////                    break;
////                }
////            }
////            else{
////                int len = s.length();
////                string st,stt;
////                st = s.substr(0, len/2);
////                stt = s.substr(len/2);
////                reverse(stt.begin(),stt.end());
////                if(st == stt) s = st;
////                else{
////                    cout << s.length() << endl;
////                    break;
////                }
////            }
////        }
////    }
////    return 0;
////}
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 1010;
//
//
//
//int main(){
//    int t; cin >> t;
//    while(t --){
//        char a[N];
//        cin >> a;
//        while(1){
//            int len = strlen(a);
//            if(len % 2){
//                cout << len << endl;
//                break;
//            }
//            int flag = 1;
//            for(int i = 0;i < len / 2; i ++){
//                if(a[i] != a[len - 1 - i]){
//                    flag = 0 ;
//                    break;
//                }
//            }
//            if(flag){
//                a[len / 2] = '\0';
//            }
//            else{
//                cout << len << endl;
//                break;
//            }
//        }
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<cmath>
//
//using namespace std;
//long long ans;
//int dep;
//
//int main()
//{
//    int t ; cin >> t;
//    while(t --){
//        ans = 0;
//        dep = 0;
//        int m; cin >> m;
//        while(m -- ){
//            string s; cin >> s;
//            if(s[0] == 'I'){
//                dep ++;
//            }
//            else if(s[0] == 'O'){
//                dep --;
//            }
//            else if(s[0] == 'S'){
//                int stay; cin >> stay;
//                ans += stay * 60 / pow(20,dep);
//            }
//        }
//        cout <<  ans << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<set>
//
//using namespace std;
//set<string> s;
//string b[18] = {"133","153","180","181","189","130","131","132","155","156","134","135","136","137","138","182","183","184"};
//bool is_legal(char a[],char c[])
//{
//    if(strlen(a) < 11) return false;
//    char tmp[4];
//    for(int i = 0;i < 3;i ++)tmp[i] = a[i];
//    tmp[3] = '\0' ;
//    if(s.count(tmp)){
//        for(int i = 1;i <= 6;i ++){
//            c[i] = a[i+5];
//        }
//        return true;
//    }
//    else return false;
//}
//
//int main()
//{
//    int t; cin >> t;
//    for(int i = 0 ;i < 18 ;i ++) s.insert(b[i]);
//    while(t -- ){
//        char a[20]; cin >> a;
//        char c[10]; c[0] = '6';
//        int flag = is_legal(a,c);
//        if(flag){
//            cout << c << endl;
//        }
//        else cout << "error" << endl;
//    }
//    return 0;
//}
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//const int N = 1e5 + 10;
//int last, cur, nest[N];
//char s[N];
//
//int main()
//{
//    while(scanf("%s",s + 1) == 1){
//        int n = strlen(s + 1);
//        last = cur = 0;
//        nest[0] = 0;
//
//        for(int i = 1;i <= n;i ++){
//            char ch = s[i];
//            if(ch == '[') cur = 0;
//            else if(ch == ']') cur = last;
//            else{
//                nest[i] = nest[cur];
//                nest[cur] = i;
//                if(cur == last) last = i;
//                cur = i;
//            }
//        }
//
//        for(int i = nest[0];i != 0;i = nest[i]){
//            printf("%c",s[i]);
//        }
//        cout << endl;
//    }
//    return 0;
//}
//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e5 + 10;
//int n,r[N],l[N];
//
//void link(int L,int R)
//{
//    r[L] = R;
//    l[R] = L;
//}
//
//int main()
//{
//    int m, kase = 0;
//    while(cin >> n >> m){
//        for(int i = 1;i <= n;i ++){
//            l[i] = i - 1;
//            r[i] = (i + 1) % (n + 1);
//        }
//        r[0] = 1;l[0] = n;
//        int op, x, y, inv = 0;
//
//        while(m -- ){
//            cin >> op;
//            if(op == 4) inv = !inv;
//            else{
//                cin >> x >> y;
//                if(op == 3 && r[y] == x) swap(x,y);
//                if(op != 3 && inv) op = 3 - op;
//                if(op == 1 && x == l[y]) continue;
//                if(op == 2 && x == r[y]) continue;
//
//                int lx = l[x], rx = r[x], ly = l[y], ry = r[y];
//                if(op == 1){
//                    link(lx, rx);link(ly, x);link(x, y);
//                }
//                else if(op == 2){
//                    link(lx, rx);link(y, x);link(x, ry);
//                }
//                else if(op == 3){
//                    if(r[x] == y){
//                        link(lx, y);link(y,x);link(x,ry);
//                    }
//                    else{
//                        link(lx, y);link(y, rx);link(ly, x);link(x, ry);
//                    }
//                }
//            }
//        }
//
//        int b = 0;
//        long long ans = 0;
//        for(int i = 1;i <= n;i ++){
//            b = r[b];
//            if(i % 2 == 1) ans +=b;
//        }
//        if(inv && n % 2 == 0) ans = (long long ) n * (n + 1) / 2 - ans;
//        printf("Case %d: %lld\n",++kase, ans);
//    }
//    return 0;
//}
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;
const int N = 20;
int s[1 << N];

int main()
{
    int d, I;
    int t;cin >> t;
    while(t --){
        cin >> d >> I;
        memset(s, 0 ,sizeof(s));
        int k, n = (1 << d) - 1;
        for(int i = 0;i < I;i ++){
            k = 1;
            for(;;){
                s[k] = !s[k];
                k = s[k] ? k * 2 : k * 2 + 1;
                if(k > n) break;
            }
        }
        cout << k / 2 << endl;
    }
    cin >> t;
    return 0;
}










