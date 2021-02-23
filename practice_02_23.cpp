//
// Created by 19116 on 2021/2/23.
//

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 5e5 + 10;
//int T;
//int r[N],cnt;
//char s[N];
//int val[30];
//
//void read(){
//    char c = getchar();
//    cnt = 1;
//    s[0] = '~';s[1] = '|';
//    while(c < 'a' || c > 'z') c = getchar();
//    while(c >= 'a' && c <= 'z') s[++ cnt] = c,s[++ cnt] = '|',c = getchar();
//}
//int main(){
//    scanf("%d",&T);
//    while(T --){
//        for(int i = 0;i < 26;i ++) scanf("%d",&val[i]);
//        read();
//        int rb = 0,mid = 0;
//        for(int i = 1;i <= cnt;i ++){
//            if(i <= rb) r[i] = min(r[(mid << 1) - i],rb - i + 1);
//            while(s[i - r[i]] == s[i + r[i]]) r[i] ++;
//            if(r[i] + i > rb) rb = r[i] + i - 1,mid = i;
//        }
//        int maxx = 0;
//        int t;
//        for(int i = 1;i <= cnt;i ++){
//            if(isalpha(s[i]) && r[i] > maxx && (i - r[i] == 1 || i + r[i] == cnt)){
//                t = i;
//                maxx = r[i];
//            }
//        }
//        int ans = 0;
//        for(int i = t - r[t];i <= t + r[t];i ++){
//            if(isalpha(s[i])) ans += val[s[i] - 'a'];
//        }
//        if(t - r[t] == 0){
//            int flag = 0;
//            for(int i = t + r[t] + 1;i <= cnt;i ++){
//                if(r[i] * 2 + 1 == cnt - 2 * r[t] - 1) flag = 1;
//            }
//            if(flag ){
//                for(int i = t + r[t] + 1;i <= cnt;i ++){
//                    if(isalpha(s[i])) ans += val[s[i] - 'a'];
//                }
//            }
//        }
//        else{
//            int flag = 0;
//            for(int i = 1;i <= t - r[t] - 1;i ++){
//                if(r[i] * 2 + 1 == cnt - 2 * r[t] - 1) flag = 1;
//            }
//            if(flag ){
//                for(int i = 1;i <= t - r[t] - 1;i ++){
//                    if(isalpha(s[i])) ans += val[s[i] - 'a'];
//                }
//            }
//        }
//        printf("%d\n",ans);
//    }
//    return 0;
//}
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<cstdio>
//
//using namespace std;
//typedef unsigned long long ull;
//ull base = 131;
//const int N = 1e4 + 10;
//ull a[N];
//char s[N];
//int n,ans = 1;
//int prime = 233317;
//ull mod = 2123704401301379571l;
//
//ull hashe(char s[]){
//    int len = strlen(s);
//    ull ans = 0;
//    for(int i = 0;i < len;i ++)
//        ans = (ans * base + (ull) s[i]) % mod + prime;
//    return ans;
//}
//
//int main(){
//    scanf("%d",&n);
//    for(int i = 1;i <= n;i ++){
//        scanf("%s",s);
//        a[i] = hashe(s);
//    }
//    sort(a + 1,a + n + 1);
//    for(int i = 1;i < n;i ++){
//        if(a[i] != a[i + 1]) ans ++;
//    }
//    printf("%d\n",ans);
//    return 0;
//}

//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//typedef unsigned long long ull;
//ull base = 131;
//const int N = 1e4 + 10;
//struct data{
//    ull x,y;
//}a[N];
//char s[N];
//int n,ans = 1;
//ull mod1 = 19260817;
//ull mod2 = 19660813;
//ull hash1(char s[]){
//    int len = strlen(s);
//    ull ans = 0;
//    for(int i = 0;i < len;i ++)
//        ans = (ans * base + (ull) s[i]) % mod1;
//    return ans ;
//}
//ull hash2(char s[]){
//    int len = strlen(s);
//    ull ans = 0;
//    for(int i = 0;i < len;i ++){
//        ans = (ans * base + (ull)s[i]) % mod2;
//    }
//    return ans;
//}
//bool cmp(data& a,data& b){
//    return a.x < b.x;
//}
//int main(){
//    scanf("%d",&n);
//    for(int i = 1;i <= n;i ++){
//        scanf("%s",s);
//        a[i].x = hash1(s);
//        a[i].y = hash2(s);
//    }
//    sort(a + 1,a + n + 1,cmp);
//    for(int i = 2;i <= n;i ++){
//        if(a[i].x != a[i - 1].x || a[i - 1].y != a[i].y) ans ++;
//    }
//    printf("%d\n",ans);
//    return 0;
//}


//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 1e6 + 10;
//int n;
//char s[N];
//int ne[N];
//void getnext(){
//    int j = 0,k = -1;
//    ne[j] = k;
//    while(j < n){
//        if(k == -1 || s[j] == s[k]) ne[++ j] = ++ k;
//        else k = ne[k];
//    }
//}
//int main(){
//    scanf("%d",&n);
//    scanf("%s",s);
//    getnext();
//    printf("%d\n",n - ne[n]);
//    return 0;
//}

//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e6 + 10;
//int n;
//char s[N];
//int ne[N];
//void getnext(){
//    int j = 0,k = -1;
//    ne[j] = k;
//    while(j < n){
//        if(k == -1 || s[j] == s[k]) ne[++ j] = ++ k;
//        else k = ne[k];
//    }
//}
//int main(){
//    scanf("%d",&n);
//    scanf("%s",s);
//    getnext();
//    int ans = 0;
//    for(int i = 0;i <= n;i ++){
//        if(ne[i] > 0) ans += ne[i];
//    }
//    printf("%d\n",ans);
//    return 0;
//}

//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 1e6 + 10;
//int n;
//char s[N];
//int ne[N];
//void getnext(){
//    int j = 0,k = -1;
//    ne[j] = k;
//    while(j < n){
//        if(k == -1 || s[j] == s[k]) ne[++ j] = ++ k;
//        else k = ne[k];
//    }
//}
//int main(){
//    scanf("%d",&n);
//    scanf("%s",s);
//    getnext();
//    long long ans = 0;
//    for(int i = 2;i <= n;i ++){
//        int t = i;
//        while(ne[t]) t = ne[t];
//        if(ne[i]) ne[i] = t;
//        ans += i - t;
//    }
//    printf("%lld\n",ans);
//    return 0 ;
//}

//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 1e6 + 10;
//int sl,tl;
//int ne[N],f[N];
//char s[N],t[N];
//int stk[N],top;
//void getnext(){
//    for(int i = 2, j = 0;i <= tl;i ++){
//        while(j && t[i] != t[j + 1]) j = ne[j];
//        if(t[i] == t[j + 1]) j ++;
//        ne[i] = j;
//    }
//}
//void KMP(){
//    for(int i = 1,j = 0;i <= sl;i ++){
//        while(j && s[i] != t[j + 1]) j = ne[j];
//        if(s[i] == t[j + 1]) j ++;
//        f[i] = j;
//        stk[++ top] = i;
//        if(j == tl) top -= tl,j = f[stk[top]];
//    }
//}
//int main(){
//    scanf("%s%s",s + 1,t + 1);
//    sl = strlen(s + 1),tl = strlen(t + 1);
//    getnext();
//    KMP();
//    for(int i = 1;i <= top;i++){
//        printf("%c",s[stk[i]]);
//    }
//    return 0;
//}

//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 1e6 + 10;
//typedef long long ll;
//const int mod = 1e9 + 7;
//int n;
//int l;
//int ne[N];
//char s[N];
//void getnext(){
//    int j = 0,k = -1;
//    ne[j] = k;
//    while(j < l){
//        if(k == -1 || s[j] == s[k]) ne[++ j] = ++ k;
//        else k = ne[k];
//    }
//}
//int main(){
//    scanf("%d",&n);
//    for(int i = 0;i < n;i ++){
//        scanf("%s",s);
//        l = strlen(s);
//        getnext();
//        ll ans = 1;
//        for(int j = 2;j <= l;j ++){
//            int cnt = 0;
//            int t = j;
//            while(ne[t]){
//                if(ne[t] * 2 <= j) cnt ++;
//                t = ne[t];
//            }
//            ans = ans * (cnt + 1) % mod;
//        }
//        printf("%lld\n",ans % mod);
//    }
//
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//typedef long long ll;
//const int N = 1e6 + 10;
//const ll mod = 1e9 + 7;
//int n,ne[N],num[N];
//ll ans;
//char s[N];
//int main(){
//    int T;scanf("%d",&T);
//    while(T --){
//        scanf("%s",s);
//        n = strlen(s);
//        memset(ne,0,sizeof(ne));
//        int i,j;
//        j = 0;
//        num[0] = 0,num[1] = 1;
//        for( i = 1;i < n;i ++){
//            while(j && s[i] != s[j]) j =ne[j];
//            if(s[i] == s[j]) j ++;
//            ne[i + 1] = j;
//            num[i + 1] = num[j] + 1;
//        }
//        j = 0,ans = 1;
//        for(i = 1;i <= n;i ++) cout << num[i] << " " ;
//        cout << endl;
//        for(i = 1;i < n;i ++){
//            while(j && s[i] != s[j]) j = ne[j];
//            if(s[i] == s[j]) j ++;
//            while((j << 1) > (i + 1)) j = ne[j];
//            ans = ans * (ll) (num[j] + 1) % mod;
//        }
//        printf("%lld\n",ans % mod);
//    }
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 1e6 + 10;
//int n;
//char s[N];
//int ne[N];
//void getnext1(){
//    int j = 0,k = -1;
//    ne[j] = k;
//    while(j < n){
//        if(k == -1 || s[j] == s[k]) ne[++ j] = ++ k;
//        else k = ne[k];
//    }
//}
//
//void getnext2(){
//    memset(ne,0,sizeof(ne));
//    for(int i = 1,j = 0;i < n;i ++){
//        while(j && s[i] != s[j]) j = ne[j];
//        if(s[i] == s[j]) j ++;
//        ne[i + 1] = j;
//    }
//}
//
//void getnext3(){
//
//}
//int main(){
//    scanf("%d",&n);
//    scanf("%s",s);
//    getnext1();
//    for(int i = 0;i <= n;i ++) printf("%d ",ne[i]);
//    cout << endl;
//    getnext2();
//    for(int i = 0;i <= n;i ++) printf("%d ",ne[i]);
//    return 0;
//}

//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 5e5 + 10,INF = 0x3f3f3f3f;
//char s[N],tmp[N];
//int ne1[N],ne2[N];
//void getnext(char a[],int ne[]){
//    int len = strlen(a);
//    int j = 0,k = -1;
//    ne[j] = k;
//    while(j < len){
//        if(k == -1 || a[j] == a[k]) ne[++ j] = ++ k;
//        else k = ne[k];
//    }
//}
//int pos[N],tot;
//void KMP(char a[],char b[]){
//    int i = 0,j = 0;
//    int la = strlen(a),lb = strlen(b);
//    while(i < la && j < lb){
//        if(j == -1 || a[i] == b[j]) i ++, j ++;
//        else j = ne2[j];
//        if(j == lb){
//            pos[tot ++] = i - lb;
//            j = ne2[j];
//        }
//    }
//}
//int ans = INF;
//int main(){
//    scanf("%s",s);
//    getnext(s,ne1);
//    int n = strlen(s);
//    while(ne1[n]){
//        n = ne1[n];
//        for(int i = 0;i < n;i ++) tmp[i] = s[i];
//        tmp[n] = '\0';
////        cout << strlen(tmp) << endl;
//        getnext(tmp,ne2);
//        tot = 0;
//        KMP(s,tmp);
//        int flag = 1;
//        for(int i = 0;i < tot - 1;i ++){
//            if(pos[i + 1] - pos[i] > n) flag = 0;
//        }
//        if(flag) ans = min(ans,n);
//    }
//    printf("%d\n",ans);
//    return 0;
//}


//#include<cstdio>
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e6 + 10;
//int n;
//char a[N],b[N];
//int la,lb;
//int na[N],nb[N];
//void getna(){
//    na[0] = -1;
//    for(int i = 2,j = 0;i <= la;i ++){
//        while(j != -1 && a[j + 1] != a[i]) j = na[j];
//        na[i] = ++ j;
//    }
//}
//void getnb(){
//    int j = 0,k = -1;
//    nb[j] = k;
//    while(j < lb){
//        if(k == -1 || a[j] == a[k]) nb[++ j] = ++ k;
//        else k = nb[k];
//    }
//}
//
//int main(){
//    scanf("%d",&la);
//    scanf("%s",a + 1);
//    getna();
//
//    for(int i = 1;i <= la;i ++) cout << na[i] << " ";
//    cout << endl;
//
//    return 0;
//}

//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 5e5 + 10;
//int n;int ne[N];
//int f[N],t[N];
//char s[N];
//int main(){
//    scanf("%s",s + 1);
//    n = strlen(s + 1);
//    for(int i = 2,j = 0;i <= n;i ++){
//        while(j && s[i] != s[j + 1]) j = ne[j];
//        if(s[i] == s[j + 1]) j ++;
//        ne[i] = j;
//    }
//    f[1] = 1;
//    for(int i = 2;i <= n;i ++){
//        f[i] = i;
//        if(t[f[ne[i]]] >= i - ne[i]) f[i] = f[ne[i]];
//        t[f[i]] = i;
//    }
//    printf("%d\n",f[n]);
//    return 0;
//}


//typedef unsigned long long ull;
//ull base = 131;
//ull hashe(char s[]){
//    ull ans = 0;
//    int len = strlen(s);
//    for(int i = 0;i < len;i ++)
//        ans = ans * base + (ull) s[i];
//    return ans & 0x7fffffff;
//}

//typedef unsigned long long ull;
//ull base = 131;
//ull mod = 19260817;
//ull hashe(char s[]){
//    int len = strlen(s);
//    ull ans = 0;
//    for(int i = 0;i < len;i ++)
//        ans = (ans * base + (ull) s[i]) % mod;
//    return ans;
//}
typedef unsigned long long ull;
ull base = 131;
ull mod1 = 19260817;
ull mod2 = 19660813;
ull hash1(char s[]){
    int len = strlen(s);
    ull ans = 0;
    for(int i = 0;i < len;i ++)
        ans = (ans * base + (ull) s[i]) % mod1;
    return ans;
}
ull hash2(char s[]){
    int len = strlen(s);
    ull ans = 0;
    for(int i = 0;i < len;i ++)
        ans = (ans * base + (ull) s[i]) % mod2;
    return ans;
}