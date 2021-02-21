//
// Created by Administrator on 2021/2/14.
//
//
//#include<iostream>
//#include<queue>
//using namespace std;
//
//const int N = 2e6 + 10;
//int trie[N][26],cnt[N],fail[N],tot;
//
//void insert(string s){
//    int u = 0;
//    for(int i = 0;i < s.size();i ++){
//        int c = s[i] - 'a';
//        if(!trie[u][c]) trie[u][c] = ++ tot;
//        u = trie[u][c];
//    }
//    cnt[u] ++;
//}
//void getfail(){
//    queue<int> q;
//    for(int i = 0;i < 26;i ++){
//        if(trie[0][i]){
//            fail[trie[0][i]] = 0;
//            q.push(trie[0][i]);
//        }
//    }
//    while(!q.empty()){
//        int now = q.front();
//        q.pop();
//        for(int i = 0;i < 26;i ++){
//            if(trie[now][i]){
//                fail[trie[now][i]] = trie[now][i];
//                q.push(trie[now][i]);
//            }
//            else
//                trie[now][i] = trie[fail[now]][i];
//        }
//    }
//}
//int query(string s){
//    int now = 0,ans = 0;
//    for(int i = 0;i < s.size();i ++){
//        now = trie[now][s[i] - 'a'];
//        for(int j = now;j && cnt[j] != -1;j = fail[j]){
//            ans += cnt[j];
//            cnt[j] = -1;
//        }
//    }
//    return ans;
//}
//
//int main(){
//    int n;string s;
//    cin >> n;
//    for(int i = 0;i < n;i ++){
//        cin >> s;
//        insert(s);
//    }
//    fail[0] = 0;
//    getfail();
//    cin >> s;
//    cout << query(s) << endl;
//    return 0;
//}

//#include<cstdio>
//#include<queue>
//#include<cstring>
//
//using namespace std;
//
//const int N = 5e5 + 10;
//int ch[N][26],cnt[N],fail[N],tot;
//queue<int> q;
//
//void insert(char s[]){
//    int u = 0;
//    for(int i = 0;i < strlen(s);i ++){
//        int c = s[i] - 'a';
//        if(!ch[u][c]) ch[u][c] = ++ tot;
//        u = ch[u][c];
//    }
//    cnt[u] ++;
//}
//
//void getfail(){
//    for(int i = 0;i < 26;i ++){
//        if(ch[0][i]) fail[ch[0][i]] = 0,q.push(ch[0][i]);
//    }
//    while(!q.empty()){
//        int u = q.front();q.pop();
//        for(int i = 0;i < 26;i ++){
//            if(ch[u][i]){
//                fail[ch[u][i]] = ch[fail[u]][i];
//                q.push(ch[u][i]);
//            }
//            else{
//                ch[u][i] = ch[fail[u]][i];
//            }
//        }
//    }
//}
//
//int query(char s[]){
//    int len = strlen(s);int now = 0,ans = 0;
//    for(int i = 0;i < len;i ++){
//        now = ch[now][s[i] - 'a'];
//        for(int j = now;j && cnt[j] != -1;j = fail[j]){
//            ans += cnt[j],cnt[j] = -1;
//        }
//    }
//    return ans;
//}
//int n;char s[N];
//int main(){
//    scanf("%d",&n);
//    for(int i = 0;i < n;i ++){
//        scanf("%s",s);
//        insert(s);
//    }
//    getfail();
//    scanf("%s",s);
//    printf("%d\n",query(s));
//    return 0;
//}

//#include<cstdio>
//#include<cstring>
//#include<queue>
//
//using namespace std;
//const int N = 5e5 + 10;
//queue<int> q;
//struct A{
//    int ch[N][26],val[N],fail[N],cnt;
//    void insert(char s[]){
//        int len = strlen(s);
//        int u = 0;
//        for(int i = 0;i < len;i ++){
//            int c = s[i] - 'a';
//            if(!ch[u][c]) ch[u][c] = ++ cnt;
//            u = ch[u][c];
//        }
//        val[u] ++;
//    }
//    void getfail(){
//        for(int i = 0;i < 26;i ++){
//            if(ch[0][i]) fail[ch[0][i]] = 0,q.push(ch[0][i]);
//        }
//        while(!q.empty()){
//            int u = q.front();q.pop();
//            for(int i = 0;i < 26;i ++){
//                if(ch[u][i]) fail[ch[u][i]] = ch[fail[u]][i],q.push(ch[u][i]);
//                else ch[u][i] = ch[fail[u]][i];
//            }
//        }
//    }
//    int query(char s[]){
//        int len = strlen(s);int now = 0,ans = 0;
//        for(int i = 0;i < len;i ++){
//            now = ch[now][s[i] - 'a'];
//            for(int j = now;j && val[j] != -1;j = fail[j]){
//                ans += val[j],val[j] = -1;
//            }
//        }
//        return ans;
//    }
//}AC;
//int main(){
//    int n;char s[N];
//    scanf("%d",&n);
//    for(int i = 1;i <= n;i ++) scanf("%s",s),AC.insert(s);
//    AC.getfail();
//    scanf("%s",s);
//    printf("%d\n",AC.query(s));
//    return 0;
//}

#include<cstdio>
#include<cmath>

using namespace std;
const double EPS = 1e-9;
const double PI = acos(-1);
inline int sgn(double a){return a < - EPS ? -1 : a > EPS;}
inline int cmp(double a,double b){return sgn(a - b);}
