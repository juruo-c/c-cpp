//
// Created by 19116 on 2021/1/7.
//
//
//#include<iostream>
//
//using namespace std;
//const int N = 110;
//int main()
//{
//    int n;string s[N];
//    while(cin >> n){
//        int ans = 0x3f3f3f3f;
//        for(int i = 0;i < n;i ++)cin >> s[i];
//        int flag = 1;
//        for(int i = 0;i < n;i ++){
//            int cnt = 0;
//            for(int j = 0;j < n;j ++){
//                if(i == j)continue;
//                int tot = 0;
//                string tmp = s[j];
//                while(s[i] != tmp){
//                    tmp = tmp.substr(1) + tmp[0];
//                    tot++;
//                    if(tot > s[j].size()){
//                        flag = 0;
//                        break;
//                    }
//                }
//                if(!flag)break;
//                cnt += tot;
//            }
//            if(!flag)break;
//            ans = min(ans,cnt);
//        }
//        if(flag) cout << ans << endl;
//        else cout << -1 << endl;
//    }
//    return 0;
//}

#include<iostream>
#include<stack>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<cstdio>

using namespace std;

int main(){
    int t;cin >> t;

    while(t --){
        stack<string> stk;
        string s;
        cin >> s;
        for(int i = 0;i < s.length();i ++){
            if(s[i] == '-' && i){
                s = s.substr(0,i) + '+' + s.substr(i);
                i ++;
            }
        }

        int cur = 0;
        while(cur < s.length()){
            if(s[cur] != '.' && !isdigit(s[cur]) && s[cur] != '-'){
                if(s[cur] == '*' || s[cur] == '/'){
                    int flag = 0;
                    if(s[cur] == '/')flag = 1;
                    double a,b,ans;
                    string tmp = stk.top();stk.pop();
//                    cout << "a : " << tmp << endl;
                    int isint = 1;
                    for(int i = 0;i < tmp.size();i ++)
                        if(tmp[i] == '.') isint = 0;
                    if(isint)
                        a = atoi(tmp.c_str());
                    else
                        a = atof(tmp.c_str());
//                    cout << "aa : " << a << endl;
                    int i = ++ cur;
                    while((isdigit(s[i]) || s[i] == '.' || s[i] == '-') && i < s.length()) i ++;
                    string tp = s.substr(cur,i - cur);
                    isint = 1;
                    for(int i = 0;i < tp.size();i ++)
                        if(tp[i] == '.') isint = 0;
                    if(isint) b = atoi(tp.c_str());
                    else b = atof(tp.c_str());
//                    cout << "b: " << tp << endl;

//                    cout << "bb: " << b << endl;

                    if(flag)ans = a / b;
                    else ans = a * b;
//                    cout << "flag : " << flag << endl;
//                    cout << "ans: " << ans << endl;
                    string ss = "";
                    char buf[110];
                    sprintf(buf,"%lf",ans);
                    for(int i = 0;i < strlen(buf);i ++)ss += buf[i];
                    stk.push(ss);

                    cur = i;
                }
                else{
                    string tmp = "";
                    tmp += s[cur];
                    stk.push(tmp);
                    cur ++;
                }
            }
            else{
                int i = cur;
                while((isdigit(s[i]) || s[i] == '.' || s[i] == '-') && i < s.length()) i ++;
                string tmp = s.substr(cur,i - cur);
//                cout << tmp << endl;
                stk.push(tmp);
                cur = i;
//                cout << cur << endl;
            }
        }

//        cout << 1 << endl;

        double ans = 0;
        while(stk.size()){
            string tmp = stk.top();stk.pop();
            if(tmp == "+")continue;
            double num = atof(tmp.c_str());
            ans += num;
        }

        printf("%.2f\n",ans);
    }
    return 0;
}