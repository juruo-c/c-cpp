//
// Created by Administrator on 2021/2/13.
//

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//const int N = 11000005;
//char s[N << 1];
//int p[N << 1],cnt,ans;
//void read(){
//    char c = getchar();
//    cnt = 1;
//    s[0] = '~',s[1] = '|';
//    while(c < 'a' || c > 'z') c = getchar();
//    while(c >= 'a' && c <= 'z') s[++cnt] = c,s[++cnt] = '|',c = getchar();
//}
//int main(){
//    read();
//    for(int i = 1,r = 0,mid = 0;i <= cnt;i ++){
//        if(i <= r) p[i] = min(p[mid * 2 - i],r - i + 1);
//        while(s[i - p[i]] == s[i + p[i]]) ++p[i];
//        if(p[i] + i > r) r = p[i] + i - 1,mid = i;
//        if(p[i] > ans) ans = p[i];
//    }
//    printf("%d\n",ans - 1);
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e6 + 10;
//string s1,s2;
//int* getnext(string s){
//    int next[N];
//    int i = 0,j = -1,len = s.length();
//    next[0] = 1;
//    while(i < len){
//        if(j == -1 || s[i] == s[j]){
//            next[++ i] = ++ j;
//        }
//        else j = next[j];
//    }
//}
//int KMP(string ts,string ps){
//    int i = 0;
//    int j = 0;
//
//}
//int main(){
//    cin >> s1 >> s2;
//
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//using namespace std;
//const int N = 1e6 + 10;
//int kmp[N];
//char a[N],b[N];
//
//void getnext(char s[]){
//    int i = 0,j = -1,len = strlen(s);
//    kmp[0] = -1;
//    while(i < len - 1){
//        if(j == -1 || s[i] == s[j]){
//            kmp[++ i] = ++ j;
//        }
//        else j = kmp[j];
//    }
//}
//void KMP(char ts[],char ps[]){
//    getnext(ps);
//    int i = 0,j = 0;
//    int lt = strlen(ts),lp = strlen(ps);
//    while(i < lt && j < lp){
//        if(j == -1 || ts[i] == ps[j]){
//            i ++;
//            j ++;
//        }
//        else{
//            j = kmp[j];
//        }
//        if(j == lp - 1){
//            printf("%d\n",i - lp + 2);
//            j = 0;
//            i ++;
//        }
//        if(i >= lt - 1) return;
//    }
//
//}
//int main(){
//    cin >> a >> b;
//    KMP(a,b);
//    for(int i = 0;i < strlen(b);i ++) printf("%d ",kmp[i]);
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//
//using namespace std;
//const int N = 1e6 + 10;
//char a[N],b[N];
//void getnext(int next[],string t){
//    int j = 0,k = -1;
//    next[0] = -1;
//    while(j < t.length() - 1){
//        if(k == -1 || t[j] == t[k]){
//            if(t[++ j] == t[++ k])
//                next[j] = next[k];
//            else next[j] = k;
//        }
//        else k = next[k];
//    }
//}
//void KMP(string s,string t){
//    int next[N],i = 0,j = 0;
//    getnext(next,t);
//    for(int k = 0;k < t.length();k ++) cout << next[k] << " " ;
//    while(i < s.length() && j < t.length()){
//        if(j == -1 || s[i] == t[j]){
//            i ++;
//            j ++;
//        }
//        else j = next[j];
//        if(j == t.length()){
//            printf("%d\n",i - t.length());
//            j = 0;
//        }
//    }
//}
//int main(){
//    cin >> a >> b;
//    KMP(a,b);
//    return 0;
//}

//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//const int N = 1e6 + 10;
//int ne[N];
//int lt,lp;
//char a[N],b[N];
//void getnext(){
//    int j = 0,k = -1;
//    ne[0] = -1;
//    while(j < lp){
//        if(k == -1 || b[j] == b[k]){
//            ne[++ j] = ++k;
//        }
//        else k = ne[k];
//    }
//}
//void KMP(){
//    int i = 0,j = 0;
//    while(i < lt){
//        if(j == -1 || a[i] == b[j]) i ++,j ++;
//        else j = ne[j];
//        if(j == lp){
//            printf("%d\n",i - lp + 1);
//            j = ne[j];
//        }
//    }
//}
//int main(){
//    scanf("%s",a);
//    scanf("%s",b);
//    lt = strlen(a),lp = strlen(b);
//    getnext();
//    KMP();
//    for(int i = 1;i <= lp;i ++){
//        printf("%d ",ne[i]);
//    }
//    return 0;
//}

//#include<cstdio>
//
//const int N = 5e5 + 10;
//char s[60];
//int n,m,ch[N][26],vis[N],tot = 1;
//int main(){
//    scanf("%d",&n);
//    for(int i = 1;i     <= n;i ++){
//        scanf("%s",s + 1);
//        int u = 1;
//        for(int j = 1;s[j];j ++){
//            int c = s[j] - 'a';
//            if(!ch[u][c]) ch[u][c] = ++tot;
//            u = ch[u][c];
//        }
//        vis[u] = 1;
//    }
//    scanf("%d",&m);
//    for(int i = 0;i < m;i ++){
//        scanf("%s",s + 1);
//        int u = 1;
//        for(int j = 1;s[j];j ++){
//            int c = s[j] - 'a';
//            u = ch[u][c];
//            if(!u) break;
//        }
//        if(vis[u] == 1){
//            vis[u] = 2;
//            puts("OK");
//        }
//        else if(vis[u] == 2){
//            puts("REPEAT");
//        }
//        else puts("WRONG");
//    }
//    return 0;
//}
//#include<cstdio>
//const int N = 1e6 + 10;
//int ch[N][26],cnt,vis[N];
//void insert(char s[],int len){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        int c = s[i] - 'a';
//        if(!ch[u][c]) ch[u][c] = ++ cnt;
//        u = ch[u][c];
//    }
//    vis[u] = 1;
//}
//bool find(char s[],int len){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        int c = s[i] - 'a';
//        if(!ch[u][c]) return 0;
//        u = ch[u][c];
//    }
//    return vis[u];
//}
//
//void insert(char s[]){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        int c = s[i] - 'a';
//        if(!ch[u][c]) ch[u][c] = ++ cnt;
//        u = ch[u][c];
//    }
//    vis[u] = 1;
//}
//bool find(char s[]){
//    int u = 0;
//    for(int i = 0;s[i];i ++){
//        int c = s[i] - 'a';
//        if(!ch[u][c]) return 0;
//        u = ch[u][c];
//    }
//    return vis[u];
//}
//int main(){
//    return 0;
//}
//#include<cstdio>
//#include<iostream>
//#include<cstring>
//
//using namespace std;
//const int N = 2e7 + 10;
//int nxt[N],ext[N];
//int slen,tlen;
//char s[N],t[N];
//void getnext(){
//    nxt[0] = tlen;
//    int now = 0;
//    while(t[now] == t[now + 1] && now + 1 < tlen) now ++;
//    nxt[1] = now;
//    int p0 = 1;
//    for(int i = 2;i < tlen;i ++){
//        if(i + nxt[i - p0] < nxt[p0] + p0) nxt[i] = nxt[i - p0];
//        else{
//            int now = nxt[p0] + p0 - i;
//            now = max(0,now);
//            while(t[now] == t[i + now] && i + now < tlen) now ++;
//            nxt[i] = now;
//            p0 = i;
//        }
//    }
//}
//void exkmp(){
//    getnext();
//    int now = 0;
//    while(s[now] == t[now] && now < min(slen,tlen)) now ++;
//    ext[0] = now;
//    int p0 = 0;
//    for(int i = 1;i < slen;i ++){
//        if(i + nxt[i - p0] < ext[p0] + p0) ext[i] = nxt[i - p0];
//        else{
//            int now = ext[p0] + p0 - i;
//            now = max(now,0);
//            while(t[now] == s[i + now] && now < tlen && now + i < slen) now ++;
//            ext[i] = now;
//            p0 = i;
//        }
//    }
//}
//int main(){
//    scanf("%s%s",s,t);
//    slen = strlen(s),tlen = strlen(t);
//    exkmp();
//    long long z = 0,p = 0;
//    for(int i = 0;i < tlen;i ++) z ^= 1LL * (i + 1) * (nxt[i] + 1);
//    for(int i = 0;i < slen;i ++) p ^= 1LL * (i + 1) * (ext[i] + 1);
//    printf("%lld\n%lld\n",z,p);
//    return 0;
//}