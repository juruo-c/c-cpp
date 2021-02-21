//
// Created by Administrator on 2021/2/19.
//

//#include<cstdio>
//
//using namespace std;
//const int N = 1e6 + 10;
//int ne[N];
//int lt,lp;
//int a[N],b[N];
//
//void getnext(){
//    int j = 0,k = -1;
//    ne[0] = -1;
//    while(j < lp){
//        if(k == -1 || b[j] == b[k]) ne[++ j] = ++k;
//        else k = ne[k];
//    }
//}
//int KMP(){
//    int i = 0,j = 0;
//    while(i < lt){
//        if(j == -1 || a[i] == b[j]) i ++,j ++;
//        else j = ne[j];
//        if(j == lp){
//            return i - lp + 1;
//        }
//    }
//    return -1;
//}
//int main(){
//    int t;scanf("%d",&t);
//    while(t --){
//        scanf("%d%d",&lt,&lp);
//        for(int i = 0;i < lt;i ++) scanf("%d",&a[i]);
//        for(int i = 0;i < lp;i ++) scanf("%d",&b[i]);
////        for(int i = 0;i < lt;i ++) cout << a[i] << " ";
////        cout << endl;
////        for(int i = 0;i < lp;i ++) cout << b[i] << " ";
////        cout << endl;
//        getnext();
//        printf("%d\n",KMP());
//    }
//    return 0;
//}


//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//const int N = 1e6 + 10;
//int lt,lp;
//char a[N],b[N];
//int ne[N];
//
//void getnext(){
//    int j = 0,k = -1;
//    ne[0] = -1;
//    while(j < lp){
//        if(k == -1 || b[j] == b[k]) ne[++j] = ++ k;
//        else k = ne[k];
//    }
//}
//
//int KMP(){
//    int ans = 0;
//    int i = 0,j = 0;
//    while(i < lt){
//        if(j == -1 || a[i] == b[j]) i ++,j ++;
//        else j = ne[j];
//        if(j == lp){
//            ans ++;
//            j = ne[j];
//        }
//    }
//    return ans;
//}
//int main(){
//    int t;scanf("%d",&t);
//    while(t --){
//        scanf("%s",b);
//        scanf("%s",a);
//        lt = strlen(a);
//        lp = strlen(b);
//        getnext();
//        printf("%d\n",KMP());
//    }
//    return 0;
//}

//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//const int N = 1e3 + 10;
//int ne[N];
//int lt,lp;
//char a[N],b[N];
//
//void getnext(){
//    int j = 0,k = -1;
//    ne[0] = -1;
//    while(j < lp){
//        if(k == -1 || b[j] == b[k]) ne[++ j] = ++ k;
//        else k = ne[k];
//    }
//}
//
//int KMP(){
//    int ans = 0;
//    int i = 0,j = 0;
//    while(i < lt){
//        if(j == -1 || a[i] == b[j]) j ++,i ++;
//        else j = ne[j];
//        if(j == lp){ans ++;j = 0;}
//    }
//    return ans;
//}
//
//int main(){
//    while(~scanf("%s",a) && a[0] != '#'){
//        scanf("%s",b);
//        lt = strlen(a),lp = strlen(b);
//        getnext();
////        for(int i = 0;i <= lp;i ++) printf("%d ",ne[i]);
//        printf("%d\n",KMP());
//    }
//    return 0;
//}

//#include<cstdio>
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e5 + 10;
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
//
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
//            while(t[now] == s[now] && now < tlen && now + i < slen) now ++;
//            ext[i] = now;
//            p0 = i;
//        }
//    }
//}
//int main(){
//    int tt;scanf("%d",&tt);
//    while(tt --){
//        scanf("%s",s);
//        bool flag = true;
//        slen = tlen = strlen(s);
//        for(int i = 0;i < slen;i ++){
//            if(s[i] != s[0]) flag = false;
//        }
//        if(flag){
//            puts("0");
//            continue;
//        }
//        for(int i = 0;i < strlen(s);i ++) t[i] = s[i];
//        t[tlen] = '\0';
//        getnext();
//        exkmp();
//        int cnt = 0;
//        for(int i = 1;i < slen;i ++) cnt = max(cnt,ext[i]);
//        printf("%d\n",slen - 2 * cnt);
//    }
//    return 0;
//}

//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//const int N = 1e5 + 10;
//int slen;
//int nxt[N];
//char s[N];
//
//void getnext(){
//    int j = 0,k = -1;
//    nxt[0] = -1;
//    while(j < slen){
//        if(k == -1 || s[j] == s[k]){
//            nxt[++ j] = ++ k;
//        }
//        else k = nxt[k];
//    }
//}
//int main(){
//    int T;
//    scanf("%d",&T);
//    while(T --){
//        scanf("%s",s);
//        slen = strlen(s);
//        getnext();
//        int z = slen - nxt[slen];
//        if((slen % z == 0) && (z != slen)) printf("0\n");
//        else if(z == slen) printf("%d\n",slen);
//        else{
//            printf("%d\n",z - slen % z);
//        }
//    }
//    return 0;
//}


//#include<iostream>
//
//using namespace std;
//
//class Student{
//public:
//    string name,num;
//
//    void show(){
//        cout << "name: " << name << "   " << "num: " << num << endl;
//    }
//};
//
//int main(){
//    Student s1;
//    cin >> s1.name >> s1.num;
//    s1.show();
//
//    return 0;
//}