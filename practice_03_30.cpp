//
// Created by 19116 on 2021/3/30.
//

//#include<iostream>
//
//using namespace std;
//
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int x,y;
//        cin >> x >> y;
//        string s;cin >> s;
//        int cnt[4] = {0};
//        for(int i = 0;s[i];i ++){
//            if(s[i] == 'R') cnt[0] ++;
//            else if(s[i] == 'L') cnt[1] ++;
//            else if(s[i] == 'U') cnt[2] ++;
//            else if(s[i] == 'D') cnt[3] ++;
//        }
//        if(x < 0 && y < 0){
//            if(cnt[1] >= abs(x) && cnt[3] >= abs(y)) cout << "YES" << endl;
//            else cout << "NO" << endl;
//        }
//        else if(x >= 0 && y < 0){
//            if(cnt[0] >= x && cnt[3] >= abs(y)) cout << "YES" << endl;
//            else cout << "NO" << endl;
//        }
//        else if(x < 0 && y >= 0){
//            if(cnt[1] >= abs(x) && cnt[2] >= y) cout << "YES" << endl;
//            else cout << "NO" << endl;
//        }
//        else if(x >= 0 && y >= 0){
//            if(cnt[0] >= x && cnt[2] >= y) cout << "YES" << endl;
//            else cout << "NO" << endl;
//        }
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<stack>
//
//using namespace std;
//const int N = 4e5 + 10;
//struct edge{
//    int u,v,next;
//}e[N];
//int cnt,head[N];
//int n,m;
//int broken[N];
//int bo[N];
//int fa[N];
//
//void add(int u,int v){
//    e[++ cnt].u = u;
//    e[cnt].next = head[u];
//    e[cnt].v = v;
//    head[u] = cnt;
//}
//int getf(int x){return x == fa[x] ? x : fa[x] = getf(fa[x]);}
//
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 0;i < m;i ++){
//        int u,v;
//        scanf("%d%d",&u,&v);
//        add(u,v);
//        add(v,u);
//    }
//    int k;scanf("%d",&k);
//    for(int i = 0;i < k;i ++){
//        int t;scanf("%d",&t);
//        broken[i] = t;
//        bo[t] = 1;
//    }
//    for(int i = 0;i < n;i ++) fa[i] = i;
//    int tot = n - k;
//    for(int i = 1;i <= cnt;i ++){
//        if(!bo[e[i].u] && !bo[e[i].v] && getf(e[i].u) != getf(e[i].v)){
//            tot --;
//            fa[getf(e[i].v)] = getf(e[i].u);
//        }
//    }
//    stack<int> ans;
//    ans.push(tot);
//
//    for(int i = k - 1;i >= 0;i --){
//        tot ++;
//        bo[broken[i]] = 0;
//        for(int j = head[broken[i]];j;j = e[j].next){
//            if(!bo[e[j].u] && !bo[e[j].v] && getf(e[j].u) != getf(e[j].v)){
//                tot --;
//                fa[getf(e[j].v)] = getf(e[j].u);
//            }
//        }
//        ans.push(tot);
//    }
//
//    while(!ans.empty()){
//        printf("%d\n",ans.top());
//        ans.pop();
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 5e4 + 10;
//int n,k;
//int fa[3 * N];
//int getf(int x){return x == fa[x] ? x : fa[x] = getf(fa[x]);}
//
//int main(){
//    scanf("%d%d",&n,&k);
//    for(int i = 1;i <= 3 * n;i ++) fa[i] = i;
//    int ans = 0;
//    for(int i = 1;i <= k;i ++){
//        int op,u,v;
//        scanf("%d%d%d",&op,&u,&v);
//        if(v > n || u > n){ans ++;continue;}
//        if(op == 1){
//            if(getf(u) == getf(v + n) || getf(v) == getf(u + n)){ans ++;}
//            else{
//                fa[getf(u)] = getf(v);
//                fa[getf(u + n)] = getf(v + n);
//                fa[getf(u + 2 * n)] = getf(v + 2 * n);
//            }
//        }
//        else{
//            if(getf(u) == getf(v) || getf(v) == getf(u + n)){ans ++;}
//            else{
//                fa[getf(u)] = getf(v + n);
//                fa[getf(u + n)] = getf(v + 2 * n);
//                fa[getf(u + 2 * n)] = getf(v);
//            }
//        }
//    }
//    printf("%d\n",ans);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//
//int main(){
//    int t;cin >> t;
//    while(t --){
//        int n,k;
//        cin >> n >> k;
//        int a[110] = {0};
//        for(int i = 1;i <= n;i ++) cin >> a[i];
//        int c[110] = {0};
//        for(int i = 1;i <= n;i ++) c[i] = a[i] - a[i - 1];
//        int sum[110] = {0};
//        int last = 0;
//        for(int i = 2;i <= n;i ++){
//            if(c[i] > 0){
//                sum[i] = last + (i - 2) * c[i];
//                last = sum[i];
//            }
//        }
//        int fl = 0;
//        last = 0;
//        for(int i = 2;i <= n;i ++){
//            if(sum[i] >= k){
//                k -= last;
//                if(k % (i - 2) == 0) cout << 1 << endl;
//                else cout << (i - 2) - k % (i - 2) + 1 << endl;
//                fl = 1;
//            }
//            if(c[i] > 0) last = sum[i];
//        }
//        if(!fl) cout << -1 << endl;
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
//        int n,k;cin >> n >> k;
//        int a[110] = {0};
//        for(int i = 1;i <= n;i ++) cin >> a[i];
//        int fl = 0;int ans = 0;
//        for(int i = 1;i <= k;i ++){
//            for(int j = 1;j <= n;j ++){
//                if(a[j] < a[j + 1]){
//                    a[j] ++;
//                    ans = j;
//                    break;
//                }
//                if(j == n){fl = 1;}
//            }
//            if(fl){cout << -1 << endl;break;}
//            if(i == k){cout << ans << endl;}
//        }
//    }
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//const int N = 5e8 + 10;
//int fa[N];
//int getf(int x){return x == fa[x] ? x : fa[x] = getf(fa[x]);}
//
//int main(){
//    int t;scanf("%d",&t);
//    while(t --){
//        int n;scanf("%d",&n);
//        for(int i = 1;i <= )
//    }
//    return 0;
//}
//
//离散化+并查集
//排序：1的放前面，便于用并查集判断是否矛盾
//
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 1e6 + 10;
struct node{
    int x,y,e;
    bool operator < (const node & b) const{
        return e > b.e;
    }
}a[N];
int b[N << 2],cnt;//离散化数组
int fa[N];
int getf(int x){return x == fa[x] ? x : fa[x] = getf(fa[x]);}

int main(){
    int t;scanf("%d",&t);
    while(t --){
        int n;scanf("%d",&n);
        cnt = 0;
        memset(b,0,sizeof(b));
        memset(fa,0,sizeof(fa));
        for(int i = 1;i <= n;i ++){
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].e);
            b[++ cnt] = a[i].x;
            b[++ cnt] = a[i].y;
        }
        sort(b + 1,b + 1 + cnt);
        int len = unique(b + 1,b + 1 + cnt) - b - 1;
        for(int i = 1;i <= len;i ++) fa[i] = i;
        for(int i = 1;i <= n;i ++){
            a[i].x = lower_bound(b + 1,b + len + 1,a[i].x) - b - 1;
            a[i].y = lower_bound(b + 1,b + len + 1,a[i].y) - b - 1;

        }
        sort(a + 1,a + 1 + n);
        int fl = 0;
        for(int i = 1;i <= n;i ++){
            int fx = getf(a[i].x);
            int fy = getf(a[i].y);
            if(a[i].e && fx != fy) fa[fx] = fy;
            else if(a[i].e == 0 && fx == fy){
                puts("NO");
                fl = 1;
                break;
            }
        }
        if(!fl) puts("YES");
    }
    return 0;
}