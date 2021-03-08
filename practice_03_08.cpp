//
// Created by 19116 on 2021/3/8.
//

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//const int N = 5e3 + 10,INF = 0x3f3f3f3f;
//struct edge{
//    int next,to,w;
//}e[N << 1];
//int head[N],cnt;
//int n,m;
//void add(int u,int v,int w){
//    e[++ cnt].next = head[u];
//    e[cnt].to = v;
//    e[cnt].w = w;
//    head[u] = cnt;
//}
//bool vis[N];
//int inq[N],d[N];
//bool spfa(int s){
//    for(int i = 1;i <= n;i ++) d[i] = INF;
//    d[s] = 0;
//    queue<int> q;
//    q.push(s);vis[s] = 1;
//    while(!q.empty()){
//        int u = q.front();q.pop();
//        vis[u] = 0;
//        for(int i = head[u];i;i = e[i].next){
//            int v = e[i].to;
//            if(d[v] > d[u] + e[i].w){
//                d[v] = d[u] + e[i].w;
//                if(!vis[v]){
//                    vis[v] = 1;
//                    q.push(v);
//                    inq[v] ++;
//                    if(inq[v] > n) return true;
//                }
//            }
//        }
//    }
//    return false;
//}
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 0;i < m;i ++){
//        int op,a,b,c;
//        scanf("%d",&op);
//        if(op == 3){
//            scanf("%d%d",&a,&b);
//            add(a,b,0);add(b,a,0);
//        }
//        else {
//            scanf("%d%d%d",&a,&b,&c);
//            if(op == 1){
//                add(a,b,-c);
//            }
//            else {
//                add(b,a,c);
//            }
//        }
//    }
//    for(int i = 1;i <= n;i ++) add(0,i,0);
//    if(spfa(0)) puts("No");
//    else puts("Yes");
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<queue>
//
//using namespace std;
//const int N = 5e3 + 10,INF = 0x3f3f3f3f;
//int n,m;int d[N];
//struct edge{
//    int next,to,w;
//}e[N << 2];
//int head[N],cnt;
//void add(int u,int v,int w){
//    e[++ cnt].next = head[u];
//    e[cnt].to = v;
//    e[cnt].w = w;
//    head[u] = cnt;
//}
//bool vis[N];
//int inq[N];
//bool spfa(int s){
//    queue<int> q;
//    for(int i = 1;i <= n;i ++) d[i] = INF;
//    d[s] = 0;
//    q.push(s);vis[s] = 1;
//    while(!q.empty()){
//        int u = q.front();q.pop();
//        vis[u] = 0;
//        for(int i = head[u];i;i = e[i].next){
//            int v = e[i].to;
//            if(d[v] > d[u] + e[i].w){
//                d[v] = d[u] + e[i].w;
//                if(!vis[v]){
//                    vis[v] = 1;
//                    q.push(v);
//                    inq[v] ++;
//                    if(inq[v] > n) return true;
//                }
//            }
//        }
//    }
//    return false;
//}
//
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 0;i < m;i ++){
//        int a,b,c;
//        scanf("%d%d%d",&a,&b,&c);
//        add(b,a,c);
//    }
//    for(int i = 1;i <= n;i ++) add(0,i,0);
//    if(spfa(0)) puts("NO");
//    else{
//        for(int i = 1;i <= n;i ++) printf("%d ",d[i]);
//    }
//    return 0;
//}

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;
const int N = 1e5 + 10,INF = 0x3f3f3f3f;
int n,m;
struct edge{
    int next,to,w;
}e[N << 2];
int head[N],cnt;

void add(int u,int v,int w){
    e[++ cnt].to = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}
int d[N];
int inq[N];
bool vis[N];
bool spfa(int s){
    queue<int> q;
    for(int i = 1;i <= n;i ++) d[i] = INF;
    d[s] = 0;
    q.push(s);vis[s] = 1;
    while(!q.empty()){
        int u = q.front();q.pop();
        vis[u] = 0;
        for(int i = head[u];i;i = e[i].next){
            int v = e[i].to;
            if(d[v] > d[u] + e[i].w){
                d[v] = d[u] + e[i].w;
                if(!vis[v]){
                    vis[v] = 1;
                    q.push(v);
                    inq[v] ++;
                    if(inq[v] > n) return true;
                }
            }
        }
    }
    return false;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0;i < m;i ++){
        int x,a,b;
        scanf("%d%d%d",&x,&a,&b);

        if(x == 1) add(a,b,0),add(b,a,0);
        else if(x == 2) add(b,a,-1);
        else if(x == 3) add(a,b,0);
        else if(x == 4) add(a,b,-1);
        else add(b,a,0);
    }
    for(int i = 1;i <= n;i ++) add(i,0,-1);
    if(spfa(0)) puts("-1");
    else {
        int ans = 0;
        for(int i = 1;i <= n;i ++) ans -= d[i];
        printf("%d\n",ans);
    }
    return 0;
}
