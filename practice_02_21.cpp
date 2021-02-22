//
// Created by 19116 on 2021/2/21.
//

//#include<cstdio>
//
//using namespace std;
//const int N = 1e6 + 10;
//char s[N];
//int n;
//int ne[N];
//
//void getnext(){
//    int j = 0,k = -1;
//    ne[0] = -1;
//    while(j < n){
//        if(k == -1 || s[j] == s[k]) ne[++ j] = ++ k;
//        else k = ne[k];
//    }
//}
//
//int main(){
//    int kase = 0;
//    while(~scanf("%d",&n) && n){
//        scanf("\n%s",s);
//        printf("Test case #%d\n",++kase);
//        getnext();
//
//        for(int i = 1;i <= n;i ++){
//            if(ne[i] && i % (i - ne[i]) == 0)
//            printf("%d %d\n",i,i / (i - ne[i]));
//        }
//        puts("");
//    }
//    return 0;
//}

//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//const int N = 1e6 + 10;
//int l;
//int ne[N];
//char s[N];
//void getnext(){
//    int j = 0,k = -1;
//    ne[0] = -1;
//    while(j < l){
//        if(k == -1 || s[j] == s[k]) ne[++ j] = ++ k;
//        else k = ne[k];
//    }
//}
//int main(){
//    while(~scanf("%s",s)){
//        l = strlen(s);
//        getnext();
//        printf("%d\n",l - ne[l]);
//    }
//
//    return 0;
//}

//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e6 + 10;
//int n;
//int ne[N];
//char s[N];
//
//void getnext(){
//    int j = 0,k = -1;
//    ne[j] = k;
//    while(j < n){
//        if(k == -1 || s[j] == s[k]) ne[++ j] = ++ k;
//        else k = ne[k];
//    }
//}
//int main(){
//    while(~scanf("%s",s) && s[0] != '.'){
//        n = strlen(s);
//        getnext();
//        if(n % (n - ne[n])) puts("1");
//        else printf("%d\n",n / (n - ne[n]));
//    }
//    return 0;
//}


//#include<cstdio>
//#include<cstring>
//#include<iostream>
//#include<set>
//using namespace std;
//const int N = 4e5 + 10;
//int n;
//int ne[N];
//char s[N];
//set<int> ans;
//void getnext(){
//    ne[0] = n;
//    int now = 0;
//    while(s[now] == s[now + 1] && now + 1 < n) now ++;
//    ne[1] = now;
//    int p0 = 1;
//    for(int i = 2;i < n;i ++){
//        if(i + ne[i - p0] < ne[p0] + p0) ne[i] = ne[i - p0];
//        else{
//            int now = ne[p0] + p0 - i;
//            now = max(0,now);
//            while(s[now] == s[i + now] && i + now < n) now ++;
//            ne[i] = now;
//            p0 = i;
//        }
//    }
//}
//
//int main(){
//    while(~scanf("%s",s)){
//        n = strlen(s);
//        ans.clear();
//        getnext();
//        for(int i = 0;i < n;i ++){
//            if(ne[i] == n - i) ans.insert(n - i);
//        }
//        for(set<int>::iterator i = ans.begin();i != ans.end();i ++) printf("%d ",*i);
//        printf("\n");
//    }
//    return 0;
//}

//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//const int N = 4e5 + 10;
//char s[N];
//int ne[N],ans[N];
//int l;
//
//void getnext(){
//    int j = 0,k = -1;
//    ne[j] = k;
//    while(j < l){
//        if(k == -1 || s[j] == s[k]) ne[++ j] = ++ k;
//        else k = ne[k];
//    }
//}
//int main(){
//    while(~scanf("%s",s)){
//        int cnt = 0;
//        l = strlen(s);
//        getnext();
//        for(int i = l;ne[i] != -1;i = ne[i]){
//            ans[cnt ++] = i;
//        }
//
//        for(int i = cnt - 1;i >= 0;i --) printf("%d ",ans[i]);
//        printf("\n");
//    }
//    return 0;
//}

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int n;
int main(){
    int tt;scanf("%d",&tt);
    while(tt --){
        char
    }
    return 0;
}