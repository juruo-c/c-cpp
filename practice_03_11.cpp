//
// Created by 19116 on 2021/3/11.
//

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<map>
//
//using namespace std;
//const int N = 1e5 + 10;
//struct edge{
//    int next,to;
//}e[N << 1];
//int head[N],cnt;
//int dfn[N],low[N],t;
//int stk[N],top;
//bool vis[N];
//int id[N],tot;
//
//void add(int u,int v){
//    e[++ cnt].to = v;
//    e[cnt].next = head[u];
//    head[u] = cnt;
//}
//void tarjan(int u){
//    low[u] = dfn[u] = ++ t;
//    vis[u] = 1;stk[++ top] = u;
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(!dfn[v]){
//            tarjan(v);
//            low[u] = min(low[u],low[v]);
//        }
//        else if(vis[v]){
//            low[u] = min(low[u],dfn[v]);
//        }
//    }
//    if(low[u] == dfn[u]){
//        int v;
//        ++ tot;
//        while(v = stk[top --]){
//            vis[v] = 0;
//            id[v] = tot;
//            if(u == v) break;
//        }
//    }
//}
//int n,m,sum;
//pair <string,string> s[N];
//int main(){
//    map<string,int> ma;
//    cin >> n;
//    for(int i = 1;i <= n;i ++) {
//        string a,b;
//        cin >> a >> b;
//        s[i] = make_pair(a,b);
//        ma[a] = ++ sum;
//        ma[b] = ++ sum;
//        add(ma[a],ma[b]);
//    }
//    cin >> m;
//    for(int i = 1;i <= m;i ++){
//        string a,b;
//        cin >> a >> b;
//        add(ma[b],ma[a]);
//    }
//    for(int i = 1;i <= sum;i ++) if(!dfn[i]) tarjan(i);
//    for(int i = 1;i <= n;i ++){
//        string a = s[i].first,b = s[i].second;
//        if(id[ma[a]] == id[ma[b]])
//            cout << "Unsafe" << endl;
//        else cout << "Safe" << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e3 + 10;
//int n,m,e;
//struct edge{
//    int next,to;
//}ed[N << 2];
//int head[N],cnt;
//void add(int u,int v){
//    ed[++ cnt].to = v;
//    ed[cnt].next = head[u];
//    head[u] = cnt;
//}
//int mch[N];
//bool vis[N];
//bool dfs(int u){
//    if(vis[u]) return false;
//    vis[u] = 1;
//    for(int i = head[u];i;i = ed[i].next){
//        int v = ed[i].to;
//        if(!mch[v] || dfs(mch[v])){
//            mch[v] = u;
//            return true;
//        }
//    }
//    return false;
//}
//int main(){
//    scanf("%d%d%d",&n,&m,&e);
//    for(int i = 1;i <= e;i ++){
//        int u,v;
//        scanf("%d%d",&u,&v);
//        add(u,v);
//    }
//    int ans = 0;
//    for(int i = 1;i <= n;i ++){
//        memset(vis,0,sizeof(vis));
//        if(dfs(i)) ans ++;
//    }
//    printf("%d",ans);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e5 + 10;
//struct edge{
//    int next,to;
//}e[N << 1];
//int head[N],cnt;
//void add(int u,int v){
//    e[++ cnt].next = head[u];
//    e[cnt].to = v;
//    head[u] = cnt;
//}
//int n,m;
//bool vis[N];
//int mch[N],m1[N];
//bool is[N];
//bool dfs(int u){
//    if(vis[u]) return false;
//    vis[u] = 1;
//    for(int i = head[u];i;i = e[i].next){
//        int v = e[i].to;
//        if(!mch[v] || dfs(mch[v])){
//            mch[v] = u;
//            m1[u] = v;
//            return true;
//        }
//    }
//    return false;
//}
//int main(){
//    scanf("%d%d",&m,&n);
//    int a,b;
//    while(scanf("%d%d",&a,&b)){
//        if(a == -1 && b == -1) break;
//        add(a,b);
//    }
//    int ans = 0;
//    for(int i = 1;i <= m;i ++){
//        memset(vis,0,sizeof(vis));
//        if(dfs(i)) is[i] = 1,ans ++;
//    }
//    printf("%d\n",ans);
//    for(int i = 1;i <= m;i ++){
//        if(is[i]) printf("%d %d\n",i,m1[i]);
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e5 + 10;
//struct edge{
//    int next,to;
//}e[N];
//int head[N],cnt;
//
//int main(){
//
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//class S{
//public:
//    void get(){
//        cin >> name >> num >> apartment >> major >> sex >> adress >> tele;
//    }
//    void print(){
//        cout << name << " " << num << " " << apartment << " " << major << " " << sex << " " << adress << " " << tele << endl;
//    }
//private:
//    string name,num,apartment,major,sex,adress,tele;
//};
//int main(){
//    int t;cin >> t;
//    while(t --){
//        S s;
//        s.get();
//        s.print();
//    }
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//class S{
//public:
//    void get(){
//        cin >> name >> sex >> num >> apart >> tele;
//    }
//    string getname(){
//        return name;
//    }
//    bool operator < (const S &b)const{
//        return name < b.name;
//    }
//private:
//    string name,sex,num,apart,tele;
//};
//
//void print(S a[],int n){
//    sort(a + 1,a + 1 + n);
//    for(int i = 1;i <= n;i ++)
//        cout << a[i].getname() << endl;
//}
//int main(){
//    int n;cin >> n;
//    S *p = new S[110];
//    for(int i = 1;i <= n;i ++)
//        p[i].get();
//    print(p,n);
//    delete[] p;
//    p = NULL;
//    return 0;
//}
//
//#include<iostream>
//#include<map>
//
//using namespace std;
//class Base{
//public:
//
//private:
//    string name,apart,sex,adress,tele;
//    void setname(string a){
//        name = a;
//    }
//    string getname(){
//        return name;
//    }
//    void setapart(string a){
//        apart = a;
//    }
//    string getapart(){
//        return apart;
//    }
//    void setsex(string a){
//        sex = a;
//    }
//    string getsex(){
//        return sex;
//    }
//    void setadress(string a){
//        adress = a;
//    }
//    string getadress(){
//        return adress;
//    }
//    void settele(string a){
//        tele = a;
//    }
//    string gettele(){
//        return tele;
//    }
//};
//class Student:public Base{
//public:
//    void setnum(string a){
//        num = a;
//    }
//    string getnum(){
//        return num;
//    }
//    void setmajor(string a){
//        major = a;
//    }
//    string getmajor(){
//        return major;
//    }
//
//    int dohomework(int classname){
//        return classname * classname ;
//    }
//private:
//    string name,num,apart,major,sex,adress,tele;
//};
//
//class Teacher:public Base{
//public:
//    int sethomework(string classname){
//        return ma[classname];
//    }
//    int checkhomework(int ans){
//        if(ans > 60) return 88;
//        else return 44;
//    }
//    void setclass(int n){
//        for(int i = 1;i <= n;i ++){
//            int num;string classname;
//            cin >> num >> classname;
//            ma[classname] = num;
//        }
//    }
//private:
//    string name,apart,sex,adress,tele;
//    map<string,int> ma;
//};
//int main(){
//    Teacher t1;
//    Student s1;
//    int n;cin >> n;
//    t1.setclass(n);
//    int m;cin >> m;
//    for(int i = 1;i <= m;i ++){
//        string classname;
//        cin >> classname;
//        cout << t1.checkhomework(s1.dohomework(t1.sethomework(classname))) << endl;
//    }
//    return 0;
//}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
const int N = 1e5 + 10;
struct edge{
    int next,to;
}e[N << 1];
int head[N],cnt;
void add(int u,int v){
    e[++ cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}
int n;
int in[N];
void topo(){
    queue<int> q;
    for(int i = 1;i <= n;i ++)if(!in[i]) q.push(i);
    while(!q.empty()){
        int u = q.front();q.pop();
        for(int i = 1;i <= n;i ++){
            int v = e[i].to;
            in[v] --;
            if(!in[v]) q.push(v);
        }
    }
}
int main(){

    return 0;
}


