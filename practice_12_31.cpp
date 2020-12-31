//#include<iostream>
//#include<sstream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//    int t; cin >> t;
//    while(t -- ){
//        string s,st; cin >> s; st = s;
//        for(int i = 0;i < s.size();i ++)
//            if(s[i] == '-' || s[i] == '+')
//                s[i] = ' ';
//        stringstream input(s);
//        vector<double> a;
//        string stt;
//        while(input >> stt){
//            double tmp = 1
//        }
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//    int a[6],b[8];
//    for(int i = 0;i < 6;i ++) cin >> a[i];
//    for(int i = 0;i < 8;i ++) cin >> b[i];
//    for(int i = 0;i < 6;i ++){
//        for(int j = 0;j < 8;j ++){
//            if(a[i] == b[j]) cout << a[i] << endl;
//        }
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//    int n; cin >> n;
//    while(n --){
//        int a[10];int k;
//        for(int i = 0;i < 10;i ++) cin >> a[i];
//        cin >> k;
//        int flag = 0;
//        for(int i = 0;i < 10;i ++){
//            if(k == a[i]){
//                flag = 1;
//                for(int j = i;j < 9;j ++){
//                    a[j] = a[j + 1];
//                }
//                break;
//            }
//        }
//        if(flag){
//            for(int i = 0;i < 9;i ++){
//                if(i) cout << " ";
//                cout << a[i];
//            }
//            cout << endl;
//        }
//        else cout << "Not found" << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int f(int n){
//    if(n == 1 || n == 2) return 1;
//    return f(n - 1) + f(n - 2);
//}
//
//int main()
//{
//    int t; cin >> t;
//    while(t --){
//        int n;
//        cin >> n;
//        cout << f(n) << endl;
//    }
//    return 0;
//}


//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//    string s;
//    while(cin >> s){
//        for(int i = 0;i < s.size() - 2;i ++){
//            if(s.substr(i,3) == "szu"){
//                s = s.substr(0,i) + "SZU" + s.substr(i + 3);
//            }
//        }
//        cout << s << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<map>
//
//using namespace std;
//
//int main()
//{
//    int t; cin >> t;
//    while(t --){
//        int l1,r1,l2,r2,l3,r3;
//        cin >> l1 >> r1 >> l2 >> r2 >> l3 >> r3;
//        int ans = min(r1,r2) - max(l1,l2) + 1;
//        if(ans <= 0){
//            cout << 0 << endl;
//            continue;
//        }
//        int t = min(min(r1,r2),r3) - max(max(l1,l2), l3) + 1;
//        ans -= t;
//        cout << ans << endl;
//    }
//    return 0;
//}

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 110;
int n,cnt;
struct Edge{
    char u,v;
    int w;
    bool operator < (const Edge& b) const{
        return w < b.w;
    }
}e[N];
int fa[27];

int getf(int x)
{
    return x == fa[x] ? x : fa[x] = getf(fa[x]);
}
int kruskal()
{
    int ans = 0;
    for(int i = 0;i < 26;i ++)fa[i] = i;
    sort(e,e + cnt);
    for(int i = 0;i < cnt;i ++){
        int fu = getf(e[i].u - 'A');
        int fv = getf(e[i].v - 'A');
        if(fu != fv){
            fa[fu] = fv;
            ans += e[i].w;
        }
    }

    return ans;
}

int main()
{
    while(cin >> n && n){
        cnt = 0;
        for(int i = 1;i < n;i ++){
            char ch;cin >> ch;
            int k;cin >> k;
            if(!k) continue;
            char c;int w;
            for(int i = 0;i < k;i ++){
                cin >> c >> w;
                e[cnt ++] = Edge{ch,c,w};
            }

        }
        cout << kruskal() << endl;
    }
    return 0;
}












