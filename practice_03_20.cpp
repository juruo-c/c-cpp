//
// Created by 19116 on 2021/3/20.
//

//#include<iostream>
//#include<cstdio>
//
//using namespace std;
//const int N = 5e4 + 10;
//int f[7],l[7];
//
//int read(){
//    int x = 0;
//    int f = 1;
//    char c = getchar();
//    while(!isdigit(c)) {
//        if(c == '-') f = -1;
//        c = getchar();
//    }
//    while(isdigit(c)) x = x * 10 + c - '0',c = getchar();
//    return x * f;
//}
//
//int main(){
//    int n;n = read();
//    int a[N];
//    for(int i = 1;i <= n;i ++){
//        a[i] = read();
//        a[i] += a[i - 1];
//        a[i] %= 7;
//    }
//    for(int i = n;i >= 1;i --) f[a[i]] = i;
//    for(int i = 1;i <= n;i ++) l[a[i]] = i;
//
//    int ans = 0;
//
//    for(int i = 0;i <= 6;i ++) ans = max(ans,l[i] - f[i]);
//
//    printf("%d\n",ans);
//    return 0;
//}


//#include<cstdio>
//#include<iostream>
//
//using namespace std;
//int a[110][110],sum[110][110];
//
//int main(){
//    int n,m;
//    scanf("%d%d",&n,&m);
//    for(int i = 1;i <= n;i ++){
//        for(int j = 1;j <= m;j ++){
//            scanf("%d",&a[i][j]);
//        }
//    }
//    for(int i = 1;i <= n;i ++){
//        for(int j = 1;j <= m;j ++){
//            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
//        }
//    }
//    int ans = 0;
//    for(int len = 1;len <= min(n,m);len ++){
//        for(int i = 1;i <= n;i ++){
//            for(int j = 1;j <= m;j ++){
//                if(i + len > n || j + len > m) continue;
//                int t = sum[i + len][j + len] - sum[i][j + len] - sum[i + len][j] + sum[i][j];
//                if(t == len * len) ans = len;
//            }
//        }
//    }
//    printf("%d\n",ans);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//
//using namespace std;
//
//const int N = 5e3 + 7;
//int n,m;
//int a[N][N];
//int x,y,v,ans;
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 1;i <= n;i ++){
//        scanf("%d%d%d",&x,&y,&v);
//        a[x + 1][y + 1] = v;
//    }
//
//    for(int i = 2;i <= 5005;i ++){
//        a[1][i] += a[1][i-1];
//        a[i][1] += a[i-1][1];
//    }
//    for(int i = 2;i <= 5005;i ++){
//        for(int j = 2;j <= 5005;j ++){
//            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + a[i][j];
//        }
//    }
//
//    for(int i = m;i <= 5005;i ++){
//        for(int j = m;j <= 5005;j ++){
//            ans = max(ans,a[i][j] - a[i - m][j] - a[i][j - m] + a[i - m][j - m]);
//        }
//    }
//
//    printf("%d\n",ans);
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//
//using namespace std;
//const int N = 1e5 + 10;
//typedef long long ll;
//ll a[N],c[N];
//int main(){
//    int n; scanf("%d",&n);
//    for(int i = 1;i <= n;i ++){
//        scanf("%d",&a[i]);
//        c[i] = a[i] - a[i - 1];
//    }
//
//    ll sum1 = 0;
//    ll sum2 = 0;
//    for(int i = 1;i <= n;i ++){
//        if(i == 1) continue;
//        if(c[i] > 0) sum1 += c[i];
//        if(c[i] < 0) sum2 += c[i];
//    }
//    cout << max(sum1,-sum2) << endl;
//
//    cout << abs(sum1 + sum2) + 1 << endl;
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//string work(int i){
//    string res;
//    while(i){
//        res += (i % 10 + '0');
//        i /= 10;
//    }
//    string t;
//    for(int k = res.size() - 1;k >= 0;k --) t += res[k];
//    return t;
//}
//
//int main(){
//    string s;
//    for(int i = 1;i <= 1000;i ++)
//        s += work(i);
//    int n;
//    cin >> n;
//    cout << s[n - 1];
//    return 0;
//}

//#include<iostream>
//#include<vector>
//
//using namespace std;
//const int N = 2e5 + 10;
//int main(){
//    string s;
//    cin >> s;
//    int cnt1 = 0,cnt0 = 0;
//    vector<int> stk1,stk0;
//    for(int i = 0;i < s.size();i ++){
//        if(s[i] == '0') cnt0 ++,stk0.push_back(i + 1);
//        else cnt1 ++,stk1.push_back(i + 1);
//    }
//    if(cnt0 < cnt1 + 1) cout << -1 << endl;
//    else{
//        int ans = cnt1 + (cnt0 - cnt1 - 1);
//        cout << ans << endl;
//        cout << cnt1 * 2 + 1 << " ";
//        int cur0 = 0,cur1 = 0;
//        for(int i = 0;i < cnt1;i ++){
//            cout << stk0[cur0 ++] << " " << stk1[cur1 ++] << " ";
//        }
//        cout << stk0[cur0 ++] << endl;
//        for(int i = cur0;i < cnt0;i ++) cout << 1 << " " << stk0[i] << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<vector>
//
//using namespace std;
//const int N = 2e5 + 10;
//int main(){
//    string s;
//    cin >> s;
//    vector<int> v;
//    int cnt = 0;
//    int cnt0 = 0,cnt1 = 0;
//    int c1[N] = {0},c2[N] = {0};
//    int last = -1;
//    for(int i = 0;i < s.size();i ++){
//        if(s[i] == '0') cnt ++,cnt0 ++;
//        if(s[i] == '1'){
//            cnt1 ++;
//            v.push_back(i);
//            c1[i] = cnt;
//            if(last != -1) {
//                c2[last] = cnt;
//            }
//            last = i;
//            cnt = 0;
//        }
//    }
//    c2[last] = cnt;
//
////    for(int i = 0;i < v.size();i ++)
////        cout << c1[v[i]] << " " << c2[v[i]] << endl;
////    for(int i = 0;i < v.size();i ++) cout << v[i] << " " ;
////    cout << endl;
//
//    for(int i = 1;i < v.size();i ++){
//        c1[v[i]] += c1[v[i - 1]];
//    }
//    for(int i = v.size() - 2;i >= 0;i --){
//        c2[v[i]] += c2[v[i + 1]];
//    }
//
////    for(int i = 0;i < v.size();i ++){
////        cout << c1[v[i]] << " " << c2[v[i]] << endl;
////    }
//    int fl = 0;
//    for(int i = 0;i < v.size();i ++){
//        if(!c1[v[i]] || !c2[v[i]]) {
//            fl = 1;
//            break;
//        }
//    }
//    if(fl){
//        cout << -1 << endl;
//        return 0;
//    }
//    int tot = v.size();
//    int num = 0;
//    fl = 0;
//    for(int i = 0;i < tot;i ++){
//        num ++;
//        if(c1[v[i]] < num){fl = 1;break;}
//        if(c2[v[i]] < tot + 1 - num){fl = 1;break;}
//    }
//    if(fl){
//        cout << -1 << endl;
//        return 0;
//    }
//    if(cnt0 == cnt1 + 1){
//        cout << 1 << endl;
//        cout << s.size() << " ";
//        for(int i = 0;i < s.size();i ++){
//            if(i) cout << " ";
//            cout << i + 1;
//        }
//        cout << endl;
//        return 0;
//    }
//    cout << cnt1 + (cnt0 - cnt1 * 2) << endl;
//    int cur1 = 0,cur2 = s.size() - 1;
//    for(int i = 0;i < v.size();i ++){
//        while(s[cur1] != '0') cur1 ++;
//        while(s[cur2] != '0') cur2 --;
//        cout << 3 << " " << cur1 + 1 << " " << v[i] + 1 << " " << cur2 + 1 << endl;
//        cur1 ++ ,cur2 --;
//    }
//    cur1 ++ ;cur2 --;
//    while(cur1 <= cur2){
//        if(cur1 == cur2) cout << 1 << " " << cur1 + 1 << endl;
//        else cout << 1 << " " << cur1 + 1 << endl << 1 << " " << cur2 + 1 << endl;
//        cur1 ++,cur2 --;
//    }
//    return 0;
//}


//#include <bits/stdc++.h>
//
//using namespace std;
//typedef long long ll;
//const int maxn = 2e5 + 5;
//char s[maxn];
//int Next[maxn];
//int len;
//bool vis[maxn];
//int cnt;
//int p[maxn];
//vector<vector<int>>ans;
//queue<int>pos_0;
//queue<int>pos_1;
//bool solve(){
//    for(int i = 1; i <= len; i++){
//        if(s[i] == '1'){
//            if(pos_0.size() == 0) return false;
//            int pos = pos_0.front();
//            pos_0.pop();
//            Next[pos] = i;
//            pos_1.push(i);
//        }
//        else{
//            if(pos_1.size() == 0){
//                pos_0.push(i);
//                continue;
//            }
//            int pos = pos_1.front();
//            pos_1.pop();
//            Next[pos] = i;
//            pos_0.push(i);
//        }
//    }
//    if(pos_1.size() != 0) return false;
//    return true;
//}
//int main(){
//    memset(Next, -1, sizeof(Next));
//    bool ok;
//    scanf("%s", s + 1);
//    len = strlen(s + 1);
//    ok = solve();
//    if(ok){
//        int num = 0;
//        int num_0 = 0;
//        for(int i = 1; i <= len; i++){
//            if(!vis[i]){
//                int j = i;
//                if(Next[j] != -1){
//                    cnt++;
//                    vector<int>tmp;
//                    num++;
//                    while(j != -1){
//                        tmp.push_back(j);
//                        vis[j] = true;
//                        j = Next[j];
//                    }
//                    ans.push_back(tmp);
//                }
//                else{
//                    num++;
//                    vis[i] = true;
//                    p[++num_0] = i;
//                }
//            }
//        }
//        printf("%d\n", num);
//        for(int i = 0; i < cnt; i++){
//            vector<int>tmp;
//            tmp = ans[i];
//            int Size = tmp.size();
//            printf("%d ", Size);
//            for(int j = 0; j < Size; j++){
//                printf("%d%c", tmp[j], j == Size - 1 ? '\n' : ' ');
//            }
//        }
//        for(int i = 1; i <= num_0; i++){
//            printf("1 %d\n", p[i]);
//        }
//    }
//    else{
//        printf("-1\n");
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//vector<int> v[200000+7];
//queue<int> q1;
//queue<int> q0;//q0,q1表示接下去如果遇到0和1 可以放进去的组别
//char s[200000+7];
//int main()
//{
//
//        int cnt=0;
//        scanf("%s",s);
//        for(int i=1;i<=strlen(s);i++)
//        {
//            if(s[i-1]=='0')//只要是0都会把这个组弄到q1去因为0后面一定可以加入1
//            {
//                if(q0.empty()){//如果前面的组都没有1结尾的就重新开一个组
//                    v[++cnt].push_back(i);
//                    q1.push(cnt);
//                }
//                else{//否则继续在1结尾的组加上0
//                    int tmp=q0.front();
//                    q0.pop();
//                    q1.push(tmp);
//                    v[tmp].push_back(i);
//                }
//            }
//            else if(s[i-1]=='1')
//            {
//                if(q1.empty()){
//                    cout<<-1<<endl;
//                    return 0;
//                }
//                else {
//                    int tmp=q1.front();q1.pop();
//                    v[tmp].push_back(i);
//                    q0.push(tmp);
//                }
//            }
//        }
//        if(!q0.empty())//如果还有以1结尾的组就不行了
//        {
//            cout<<-1<<endl;
//            return 0;
//        }
//
//        cout<<cnt<<endl;
//        for(int i=1;i<=cnt;i++){
//            cout<<v[i].size()<<' ';
//            for(int j = 0;j < v[i].size();j ++){
//                cout<< v[i][j] << " ";
//            }
//            cout<<endl;
//
//        }
//
//    return 0;
//
//}

#include<iostream>
#include<vector>


using namespace std;
const int N = 2e5 + 10;
vector<int> v[N];

int main(){
    string s;cin >> s;
    int cnt = 0;
    int mx = 0;
    for(int i = 0;i < s.size();i ++){
        if(s[i] == '0'){
            v[++ cnt].push_back(i + 1);
        }
        else{
            if(! cnt){puts("-1");return 0;}
            v[cnt --].push_back(i + 1);
        }
        mx = max(mx,cnt);
    }
    if(mx != cnt){puts("-1");return 0;}
    cout << mx << endl;
    for(int i = 1;i <= mx;i ++){
        cout << v[i].size();
        for(int j = 0;j < v[i].size();j ++) cout << " " << v[i][j];
        cout << endl;
    }
    return 0;
}