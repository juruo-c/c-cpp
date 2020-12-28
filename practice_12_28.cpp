//#include<iostream>
//
//using namespace std;
//
//void print(string s){
//    for(int i = 0;i < s.length();i ++){
//        cout << s[i] << " ";
//    }
//    cout << endl;
//}
//int main()
//{
//    string s;cin >> s;
//    print(s);
//    return 0;
//}
//#include<iostream>
//
//using namespace std;
//
//string f(string s,string st)
//{
//    return s + st;
//}
//int main()
//{
//    string s,st;
//    cin >> s >> st;
//    cout << f(s,st);
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//string f(string s){
//    string ans = "";
//    for(int i = 0;i < s.length();i ++){
//        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
//            ans += s[i];
//    }
//    return ans;
//}
//int main()
//{
//    string s;cin >> s;
//    cout << f(s);
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<cstdlib>
//
//using namespace std;
//
//bool f(char a[],char b[],int n)
//{
//    if(n >= strlen(a)) return false;
//    int i = n;
//    int j = 0;
//    while(i <= strlen(a)){
//        b[j ++] = a[i ++];
//    }
//    return true;
//}
//
//int main()
//{
//    int t; cin >> t;
//    while(t --){
//        getchar();
//        char a[110],b[110];
//        int n;
//        gets(a);
//        cin >> n;
//        if(f(a,b,n)) cout << b << endl;
//        else cout << "IndexError" << endl;
//    }
//    return 0;
//}
//#include<iostream>
//
//using namespace std;
//const int N = 1 << 17;
//string s;
//int a[N];
//
//void solve(int n)
//{
//    if(a[n]){
//        if(a[n] == a[n + 1])
//    }
//}
//
//int main()
//{
//    while(cin >> s){
//        if(s.find('[') == s.end()){
//            cout << 0 << endl;
//            continue;
//        }
//        k = 1;
//        for(int i = 0;i < s.length();i ++){
//            if(s[i] == '[') k = k << 1;
//            else if(s[i] == ',') k = k + 1;
//            else if(s[i] == ']') k = k - 1 >> 1;
//            else if(isdigit(s[i])){
//                int tmp = i;
//                while(s[i] != ',' || s[i] != ']') i ++;
//                for(int j = i - 1;j >=tmp;j --){
//                    a[k] = a[k] * 10 + (s[i] - '0');
//                }
//                i --;
//            }
//        }
//        ans = 0;
//        solve();
//        cout << ans << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<map>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//typedef long long ll;
//map<ll,int> mp;
//string s;
//int num,sum;
//
//void build(int l,int r,int d){
//    if(s[l] == '['){
//        int flag = 0;
//        for(int i = l + 1;i <= r;i ++){
//            if(s[i] == '[') flag ++;
//            if(s[i] == ']') flag --;
//            if(s[i] == ',' && !flag){
//                build(l + 1,i - 1,d + 1);
//                build(i + 1,r - 1,d + 1);
//            }
//        }
//    }
//    else{
//        sum ++;
//        ll tmp = 0;
//        for(int i = l;i <= r;i ++){
//            tmp = tmp * 10 + s[i] - '0';
//        }
//        int res = ++mp[tmp << d];
//        num = max(num,res);
//    }
//}
//
//int main()
//{
//    int t;cin >> t;
//    while(t -- ){
//        cin >> s;
//        mp.clear();
//        sum = num = 0;
//        build(0,s.size() - 1,0);
//        cout << sum - num << endl;
//    }
//    return 0;
//}
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<vector>
//#include<cmath>
//
//using namespace std;
//const int N = 110;
//int np,nt,kase,nf;
//int p[N],tp[N];int ans;
//struct node
//{
//    vector<int> in,out;
//}tran[N];
//
//int main()
//{
//    while(cin >> np && np){
//        int tmp;
//        for(int i = 1;i <= np;i ++) cin >> p[i];
//        cin >> nt;
//        //Çå¿ÕÈÝÆ÷
//        for(int i = 1;i <= nt;i ++){
//            tran[i].in.clear();tran[i].out.clear();
//        }
//        for(int i = 1;i <= nt;i ++){
//            while(cin >> tmp && tmp){
//                if(tmp < 0)tran[i].in.push_back(abs(tmp));
//                else tran[i].out.push_back(tmp);
//            }
//        }
////        for(int i = 1;i <= nt;i ++){
////            cout << i << ": ";
////            for(auto in : tran[i].in) cout << in << " ";
////            cout << endl;
////        }
//
//        cin >> nf;
//
//        for(ans = 1; ans <= nf;ans ++){
//            bool dead = 1;
//            for(int i = 1;i <= nt;i ++){
//                memset(tp,0,sizeof(tp));
//                for(auto in : tran[i].in){
//                    tp[in] ++;
//                }
//                int flag = 1;
//                for(auto in : tran[i].in){
//                    if(p[in] < tp[in]){
//                        flag = 0;break;
//                    }
//                }
//                if(flag){
//                    dead = 0;
//                    for(auto in : tran[i].in){
//                        p[in] --;
//                    }
//                    for(auto out : tran[i].out){
//                        p[out] ++;
//                    }
//                    break;
//                }
//            }
//            if(dead){
//                printf("Case %d: dead after %d transitions\n",++kase,ans - 1);
//                printf("Places with tokens:");
//                for(int i = 1;i <= np;i ++){
//                    if(p[i] > 0) cout << " " << i << " (" << p[i] << ")";
//                }
//                cout << endl;
//                break;
//            }
//        }
//        if(ans > nf){
//            printf("Case %d: still live after %d transitions\n",++kase,nf);
//            printf("Places with tokens:");
//            for(int i = 1;i <= np;i ++){
//                if(p[i] > 0) cout << " " << i << " (" << p[i] << ")";
//            }
//            cout << endl;
//        }
//        puts("");
//    }
//    return 0;
//}


//#include<iostream>
//#include<cstring>
//#include<cmath>
//#include<set>
//
//using namespace std;
//const int N = 64 + 10;
//int a[N][N];
//int kase,n;
//set<int> black; //´æºÚ¿éÊý×ÖÐòÁÐ
//int dirs[N];
//
//void to_num(int r,int c,int len,int dep,int dir,int num)
//{
//    int new_num = 0;
//    bool wh = 0,bl = 0;
//    for(int i = r;i < r + len;i ++){
//        for(int j = c;j < c + len;j ++){
//            if(a[i][j]) bl = 1;
//            if(!a[i][j]) wh = 1;
//        }
//        if(bl && wh) break;
//    }
//    if(dep > 1) new_num = pow(5,dep - 2) * dir + num;
//    if(wh && bl){
//        to_num(r,c,len / 2,dep + 1,1,new_num);
//        to_num(r,c + len / 2, len / 2, dep + 1,2,new_num);
//        to_num(r + len / 2,c,len / 2, dep + 1, 3, new_num);
//        to_num(r + len / 2, c + len / 2, len / 2, dep + 1, 4, new_num);
//    }
//    else if(bl) black.insert(new_num);
//    return;
//}
//
//void num_to(int r,int c,int len,int dep)
//{
//    if(!dirs[dep]){
//        for(int i = r;i < r + len;i ++){
//            for(int j = c;j < c + len;j ++){
//                a[i][j] = 1;
//            }
//        }
//    }
//    else{
//        switch(dirs[dep])
//        {
//        case 1:
//            num_to(r,c,len / 2,dep + 1);
//            break;
//        case 2:
//            num_to(r, c + len / 2, len / 2, dep + 1);
//            break;
//        case 3:
//            num_to(r + len / 2,c, len / 2, dep + 1);
//            break;
//        case 4:
//            num_to(r + len / 2,c + len / 2, len / 2, dep + 1);
//            break;
//        }
//    }
//}
//
//void get_dir(int num)
//{
//    memset(dirs,0,sizeof(dirs));
//    for(int i = 64;i > 0;i --){
//        int x = num / pow(5,i);
//        if(x > 0){
//            dirs[i + 1] = x;
//            num = num - x * pow(5,i);
//        }
//    }
//    dirs[1] = num;
//}
//
//int main()
//{
//    cin >> n;
//    while(n){
//        cout << "Image " << ++kase << endl;
//        if(n < 0){
//            n = -n;
//            int num;
//            memset(a,0,sizeof(a));
//            while(cin >> num && num != -1){
//                get_dir(num);
//                num_to(0,0,n,1);
//            }
//            for(int i = 0;i < n;i ++){
//                for(int j = 0;j < n;j ++){
//                    if(a[i][j])cout << "*";
//                    else cout << "." ;
//                }
//                cout << endl;
//            }
//        }
//        else{
//            black.clear();
//            getchar();
//            for(int i = 0;i < n;i ++){
//                for(int j = 0;j < n;j ++){
//                    char ch = getchar();
//                    a[i][j] = ch - '0';
//                }
//                getchar();
//            }
//            to_num(0,0,n,1,0,0);
//            int cnt = 0;
//            for(auto x : black){
//                if(cnt % 12 == 0 && cnt) cout << endl;
//                if(cnt % 12 != 0) cout << " ";
//                cout << x;cnt ++;
//            }
//            if(black.size() != 0) cout << endl;
//            cout << "Total number of black nodes = " << black.size() << endl;
//        }
//        cin >> n;
//        if(n) cout << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<unordered_set>
//
//using namespace std;
//int n,num;
//int main()
//{
//    while(cin >> n && n){
//        if(num != 0) puts("");num ++;
//        char buf[100];string s;int cnt = 0;
//        for(int fj = 1234;;fj ++){
//            sprintf(buf,"%05d%05d",fj * n,fj);
//            s = buf;
//            if(s.size()  > 10) break;
//            unordered_set<char> _set(s.begin(),s.end());
//            if(_set.size() == 10){
//                printf("%s / %s = %d\n",s.substr(0,5).c_str(),s.substr(5).c_str(),n);
//                cnt ++;
//            }
//        }
//        if(cnt == 0) cout << "There are no solutions for " << n << ".\n";
//    }
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//const int N = 20;
//long long ans;int n,kase;
//long long a[N];
//int main()
//{
//    while(cin >> n){
//        for(int i = 0;i < n;i ++)cin >> a[i];
//        ans = 0;
//        for(int i = 0;i < n;i ++){
//            for(int len = 0;i + len < n;len ++){
//                long long t = 1;
//                for(int j = i;j <= i + len;j ++){
//                    t *= a[j];
//                }
//                ans = max(ans,t);
//            }
//        }
//        printf("Case #%d: The maximum product is %lld.\n",++kase,ans);
//        puts("");
//    }
//    return 0;
//}

#include<iostream>

using namespace std;

int main()
{
    int k;int cnt;
    while(cin >> k){
        cnt = 0;
        for(int y = k + 1;y <= 2 * k ;y ++){
            if(y * k % (y - k) == 0)
                cnt ++;
        }
        cout << cnt << endl;
        for(int y = k + 1;y <= 2 * k;y ++){
            if(y * k % (y - k) == 0)printf("1/%d = 1/%d + 1/%d\n",k,y * k / (y - k),y);
        }
    }
    return 0;
}






