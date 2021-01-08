//
// Created by 19116 on 2021/1/8.
//

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//    int t; cin >> t;
//    while(t --){
//        int n; cin >> n;
//        int a[25];
//        for(int i = 0;i < n;i ++)cin >> a[i];
//        for(int i = 0;i < n - 1;i ++) {
//            int k = i + 1;
//            int minn = a[k];
//            for (int j = k; j < n; j++) {
//                if (minn > a[j]) {
//                    minn = a[j];
//                    k = j;
//                }
//            }
//            if (a[k] < a[i])
//                swap(a[k], a[i]);
//            for (int i = 0; i < n; i++) {
//                if (i) cout << " ";
//                cout << a[i];
//            }
//            cout << endl;
//        }
//    }
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//
//using namespace std;
//const int N = 110;
//pair<string,int> s[N];
//int main()
//{
//    int t;cin >> t;
//    while(t --){
//        int n,m;
//        cin >> n >> m;
//        for(int i = 1;i <= n;i ++){
//            cin >> s[i].first >> s[i].second;
//        }
//        while(m --){
//            string q;cin >> q;
//            if(q[0] == 'C'){
//                int index,tmp;
//                cin >> index >> tmp;
//                s[index].second = tmp;
//            }
//            else if(q == "QUERY_AVERAGE"){
//                double ans = 0;
//                for(int i = 1;i <= n;i ++)
//                    ans += s[i].second;
//                printf("%.1lf\n",ans / n);
//            }
//            else if(q == "QUERY_MAX"){
//                int ans = 0;
//                for(int i = 1;i <= n;i ++)
//                    ans = max(ans,s[i].second);
//                cout << ans << endl;
//            }
//            else if(q == "QUERY_MIN"){
//                int ans = 0x3f3f3f3f;
//                for(int i = 1;i <= n;i ++)
//                    ans = min(ans,s[i].second);
//                cout << ans << endl;
//            }
//        }
//        cout << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//    int t;cin >> t;
//    while(t --){
//        int n;cin >> n;
//        int a[11][11];
//        for(int i = 0;i < n;i ++)
//            for(int j = 0;j < n;j ++)
//                cin >> a[i][j];
//        for(int i = 0;i < n;i ++){
//            int sum = 0;int maxx = a[0][i];
//            for(int j = 0;j < n;j ++){
//                sum += a[j][i];
//                maxx = max(a[j][i],maxx);
//            }
//            cout << maxx << " " << sum << endl;
//        }
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main(){
//    int a[3][3];
//    for(int i = 0;i < 3;i ++)
//        for(int j = 0;j < 3;j ++)
//            cin >> a[i][j];
//        cout << a[0][0] + a[1][1] + a[2][2] << " " << a[2][0] + a[1][1] + a[0][2] << endl;
//}

//#include<iostream>
//
//using namespace std;
//
//int main(){
//    int n,m;
//    cin >> n >> m;
//    int a[11][11];
//    for(int i = 0;i < n;i ++){
//        for(int j = 0;j < m;j ++){
//            cin >> a[i][j];
//        }
//    }
//
//    for(int i = 0;i < m;i ++){
//        for(int j = 0;j < n;j ++){
//            if(j) cout << " ";
//            cout << a[j][i];
//        }
//        cout << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int n;cin >> n;
//        int a[10][10],b[10][10],c[10][10];
//        for(int i = 0;i < n;i ++){
//            for(int j = 0;j < n;j ++){
//                cin >> a[i][j];
//            }
//        }
//
//        for(int i = 0;i < n;i ++){
//            for(int j = 0;j < n;j ++){
//                cin >> b[i][j];
//            }
//        }
//
//        for(int i = 0;i < n;i ++){
//            for(int j = 0;j < n;j ++){
//                if(j) cout << " ";
//                cout << a[i][j] + b[i][j];
//            }
//            cout << endl;
//        }
//
//        for(int i = 0;i < n;i ++){
//            for(int j = 0;j < n;j ++){
//                for(int k = 0;k < n;k ++){
//                    c[i][j] += a[i][k] * b[k][j];
//                }
//                if(j) cout << " ";
//                cout << c[i][j];
//            }
//            cout << endl;
//        }
//
//    }
//}


//#include<iostream>
//
//using namespace std;
//
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int n;cin >> n;
//        int a[110][110];
//        for(int i = 0;i < n;i ++){
//            for(int j = 0;j <= i;j ++){
//                cin >> a[i][j];
//            }
//        }
//
//        for(int i = n - 2;i >= 0;i --){
//            for(int j = 0;j <= i;j ++){
//                a[i][j] += max(a[i + 1][j],a[i + 1][j + 1]);
//            }
//        }
//
//        cout << a[0][0] << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int n;cin >> n;
//        int a[110];
//        for(int i = 0;i < n;i ++)cin >> a[i];
//        int l = 0,r = n - 1;
//        while(l < r){
//            while(a[l] % 2 == 0) l ++;
//            while(a[r] % 2) r --;
//            if(l >= r) break;
//            swap(a[l],a[r]);
//            l ++;
//            r --;
//        }
//        cout << n;
//        for(int i = 0;i < n;i ++) cout << " " << a[i];
//        cout << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//struct peo{
//    int num,flag;
//}p[110];
//int n;
//int check(){
//    int pos = 0;
//    int sum = 0;
//    for(int i = 1;i <= n;i ++){
//        sum += p[i].flag ;
//        if(p[i].flag) pos = p[i].num;
//    }
//    if(sum > 1) return 0;
//    else return pos;
//}
//int main(){
//    cin >> n;
//    for(int i = 1;i <= n;i ++)p[i].num = i,p[i].flag = 1;
//    int cur = 1;int cnt = 0;
//    while(1){
//        int pos;
//        if(pos = check()){
//            cout << endl << p[pos].num << endl;
//            break;
//        }
//        if(p[cur].flag){
//            cnt ++;
//        }
//        if(cnt == 3) {
//            cout << p[cur].num << " ";
//            p[cur].flag = 0;
//            cnt = 0;
//        }
//        cur ++;
//        if(cur > n)cur %= n;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int n,m; cin >> n >> m;
//        int a[110][110];
//        for(int i = 0;i < n;i ++){
//            for(int j = 0;j < m;j ++){
//                cin >> a[i][j];
//            }
//        }
//
//        int flag = 0;
//        for(int i = 0;i < n;i ++){
//            int maxx = a[i][0],col = 0;
//            for(int j = 0;j < m;j ++){
//                if(maxx < a[i][j]){
//                    maxx = a[i][j];
//                    col = j;
//                }
//            }
//            int ok = 1;
//            for(int j = 0;j < n;j ++){
//                if(a[j][col] < a[i][col])ok = 0;
//            }
//            if(ok){
//                cout << i << " " << col << endl;
//                flag = 1;
//            }
//        }
//        if(!flag) cout << -1 << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main(){
//    string s;
//    while(getline(cin,s)){
//        for(int i = 0;i < s.size() - 2;i ++){
//            if(s.substr(i,3) == "you")
//            {
//                s = s.substr(0,i) + "we" + s.substr(i + 3);
//                i ++;
//            }
//
//        }
//        cout << s << endl;
//    }
//
//    return 0;
//}

//#include<bits/stdc++.h>
//
//using namespace std;
//
//const int maxn = 1e3+10;
//
//char a[maxn];
//int main()
//{
//    while(gets(a)){
//        for(int i=0;i<strlen(a);i++){
//            if(a[i]=='y'){
//                int cur = i;
//                if(cur>strlen(a)-3){
//                    cout<<a[i];
//                    continue;
//                }
//                if(a[cur+1]=='o'&&a[cur+2]=='u'){
//                    cout<<'w'<<'e';
//                    i = cur + 2;
//                }
//                else{
//                    cout<<a[cur];
//                }
//            }
//            else{
//                cout<<a[i];
//            }
//        }
//        cout<<endl;
//    }
//
//    return 0;
//}

//#include<bits/stdc++.h>
//
//using namespace std;
//const int N = 1e3 + 10;
//int f[N][N];
//int main(){
//    int t;cin >> t;
//    while(t --){
//        string s;cin >> s;
//        string st = s;
//        reverse(s.begin(),s.end());
//
//        int len = s.length();
//        for(int i = 0;i <= len;i ++)f[i][0] = 0,f[0][i] = 0;
//        for(int i = 1;i <= len;i ++){
//            for(int j = 1;j <= len;j ++){
//                if(s[i - 1] == st[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
//                else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
//            }
//        }
//
//        cout << len - f[len][len] << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<set>
//
//using namespace std;
//
//int main(){
//    int t; cin >> t;
//    while(t --){
//        string s;cin >> s;
//        set<string> _set;
//        int cnt = 0;
//        int str = 0,cur = 0;
//        while(cur < s.length()){
//            if(s[str] != s[cur]){
//                cnt ++;
//                string tmp = s.substr(str,cur - str);
//                if(!_set.count(tmp)){
//                    _set.insert(tmp);
//                    cout << tmp << " ";
//                }
//                str = cur;
//                continue;
//            }
//            cur ++;
//        }
//        string tmp = s.substr(str,cur - str);
//        if(!_set.count(tmp)){
//            cout << tmp << " ";
//            _set.insert(tmp);
//        }
//        cnt ++;
//        printf("%.2lf\n",(double)s.size() / cnt);
//    }
//    return 0;
//}


