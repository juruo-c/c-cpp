//
// Created by 19116 on 2021/3/31.
//

//#include<iostream>
//
//using namespace std;
//
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int n;
//        cin >> n;
//        int cnt[110] = {0};
//        int maxx = 0;
//        int ans = 0;
//        for(int i = 1;i <= n;i ++){
//            int tt;
//            cin >> tt;
//            cnt[tt] ++;
//            maxx = max(maxx,tt);
//        }
//        for(int i = 1;i <= maxx;i ++){
//            ans = max(ans,cnt[i]);
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

//#include<iostream>
//
//using namespace std;
//int d;
//void solve(int a){
//    if(a >= 10 * d){
//        cout << "YES" << endl;
//        return;
//    }
//    for(int i = 1;i <= 9;i ++){
//        if(a - d * i >= 0 && (a - d * i) % 10 == 0) {
//            cout << "YES" << endl;
//            return;
//        }
//    }
//    cout << "NO" << endl;
//}
//
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int n;
//        cin >> n >> d;
//        for(int i = 0;i < n;i ++){
//            int a;cin >> a;
//            solve(a);
//        }
//    }
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 3e4 + 10;
//int T;
//int fa[N];
//int r[N];
//int getf(int x){return x == fa[x] ? x : fa[x] = getf(fa[x]);}
//
//int main(){
//    scanf("%d",&T);
//    for(int i = 1;i <= N;i ++){
//        fa[i] = i;
//        r[i] = 1;
//    }
//    for(int i = 1;i <= T;i++){
//        char op;int a,b;
//        scanf("\n%c%d%d",&op,&a,&b);
//        if(op == 'M'){
//            int f1 = getf(a);
//            int f2 = getf(b);
//            fa[f2] = f1;
//            r[f1] += r[f2];
//        }
//        else if(op == 'C'){
//            int f1 = getf(a),f2 = getf(b);
//            if(f1 == f2) puts("-1");
//            else printf("%d\n",r[a] - r[b] - 1);
//        }
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 3e4 + 10;
//int fa[N];
//int front[N],num[N];
//int T;
//int getf(int x){
//    if(x == fa[x]) return x;
//    int fx = getf(fa[x]);
//    front[x] += front[fa[x]];
//    return fa[x] = fx;
//}
//int main(){
//    cin >> T;
////    cout << T << endl;
//    for(int i = 1;i <= N;i ++){
//        fa[i] = i;
//        front[i] = 0;
//        num[i] = 1;
//    }
//    while(T --){
//        char op;int x,y;
//        cin >> op >> x >> y;
////        cout << op << x << y << endl;
//        int fx = getf(x);
//        int fy = getf(y);
//        if(op == 'M'){
//            front[fx] += num[fy];
//            fa[fx] = fy;
//            num[fy] += num[fx];
//            num[fx] = 0;
//        }
//        else if(op == 'C'){
//            if(fx != fy) cout << "-1" << endl;
//            else cout << abs(front[x] - front[y]) - 1 << endl;
//        }
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//
//using namespace std;
//const int N = 3e4 + 10;
//int fa[N],front[N],num[N];
//int T;char op;int x,y;
//
//int getf(int x){
//    if(fa[x] == x) return fa[x];
//    int fx = getf(fa[x]);
//    front[x] += front[fa[x]];
//    return fa[x] = fx;
//}
//int main(){
//    cin >> T;
//    for(int i = 1;i <= N;i ++){
//        fa[i] = i;
//        front[i] = 0;
//        num[i] = 1;
//    }
//    while(T --){
//
//        cin >> op >> x >> y;
//        int fx = getf(x);
//        int fy = getf(y);
//        if(op == 'M'){
//            front[fx] += num[fy];
//            fa[fx] = fy;
//            num[fy] += num[fx];
//            num[fx] = 0;
//        }
//        if(op == 'C'){
//            if(fx != fy) cout << "-1" << endl;
//            else cout << abs(front[x] - front[y]) - 1 << endl;
//        }
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int fa[30001],front[30001],num[30001],x,y,i,j,n,T,ans;    //fa[i]表示飞船i的祖先
////front[i]表示飞船i与其所在列队头的距离
////num[i]表示第i列的飞船数量
//char ins;
//int find(int n){                                        //查找祖先的函数
//    if(fa[n]==n)return fa[n];
//    int fn=find(fa[n]);                                    //先递归找到祖先
//    front[n]+=front[fa[n]];    //在回溯的时候更新front（因为更新时要用到正确的front[祖先]，
//    //所以只能在回溯的时候更新）
//    return fa[n]=fn;
//}
//int main(){
//    cin>>T;
//    for(i=1;i<=30000;++i){                                //定初值
//        fa[i]=i;
//        front[i]=0;
//        num[i]=1;
//    }
//    while(T--){
//        cin>>ins>>x>>y;
//        int fx=find(x);                                    //fx为x所在列的队头
//        int fy=find(y);                                    //fy同上
//        if(ins=='M'){
//            front[fx]+=num[fy];        //更新front[x所在列队头(现在在y所在队列后面)]
////即加上y所在队列的长度
//            fa[fx]=fy;                                    //将fy设为fx的祖先
//            num[fy]+=num[fx];                            //更新以fy为队头队列的长度
//            num[fx]=0;                        //以fx为队头的队列已不存在，更新
//        }
//        if(ins=='C'){
//            if(fx!=fy)cout<<"-1"<<endl;            //若x和y的祖先不相同，则不在同一列
//            else cout<<abs(front[x]-front[y])-1<<endl;    //否则利用x和y离队头的距离算
////出它们的距离
//        }
//    }
//    return 0;
//}

#include<bits/stdc++.h>

using namespace std;
const int N = 3e4 + 10;
int fa[N],front[N],num[N];
int x,y,T;
char op;
int getf(int n){
    if(fa[n] == n) return fa[n];
    int fn = getf(fa[n]);
    front[n] += front[fa[n]];
    return fa[n] = fn;
}
int main(){
    cin >> T;
    for(int i = 1;i <= N;i ++){
        fa[i] = i;
        front[i] = 0;
        num[i] = 1;
    }
    while(T --){
        cin >> op >> x >> y;
        int fx = getf(x);
        int fy = getf(y);
        if(op == 'M'){
            front[fx] += num[fy];
            fa[fx] = fy;
            num[fy] += num[fx];
            num[fx] = 0;
        }
        if(op == 'C'){
            if(fx != fy) cout << "-1" << endl;
            else cout << abs(front[x] - front[y]) - 1 << endl;
        }
    }
    return 0;
}
