//
// Created by Administrator on 2021/2/3.
//

//#include<iostream>
//
//using namespace std;
//const int N = 5e4 + 10;
//struct tree{
//    int l,r,lz;
//}t[N << 2];
//
//void build(int i,int l,int r){
//    t[i].l = l,t[i].r = r;
//    t[i].lz = 0;
//    if(l == r)return;
//    int mid = l + r >> 1;
//    build(i << 1, l, mid);
//    build(i << 1 | 1,mid + 1,r);
//}
//
//void update(int i,int pos,int k){
//    if(t[i].l == t[i].r){
//        t[i].lz = k;
//        return;
//    }
//    if(t[i << 1].r >= pos) update(i << 1,pos,k);
//    else update(i << 1 | 1,pos,k);
//}
//int ans;
//void query(int i,int x,int l,int r){
//
//}
//int main(){
//    int n,m;
//    cin >> n >> m;
//    build(1,1,n);
//    for(int i = 0;i < m;i ++){
//        char ch;
//        cin >> ch;
//        int x;
//        if(ch == 'D'){
//            cin >> x;
//
//        }
//        else if(ch == 'Q'){
//            cin >> x;
//
//        }
//        else if(ch == 'R'){
//        }
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 5e4 + 10;
//int his[N];
//int n,m;
//struct tree{
//    int l,r,maxx,minn;
//}t[N << 2];
//void push_up(int i){
//    t[i].maxx = max(t[i << 1].maxx,t[i << 1 | 1].maxx);
//    t[i].minn = min(t[i << 1].minn,t[i << 1 | 1].minn);
//}
//void build(int i,int l,int r){
//    t[i].l = l,t[i].r = r;
//    if(l == r){
//        t[i].maxx = 0;
//        t[i].minn = n + 1;
//        return;
//    }
//    int mid = l + r >> 1;
//    build(i << 1,l, mid);
//    build(i << 1 | 1,mid + 1,r);
//    push_up(i);
//}
//void update(int i,int pos,int maxx,int minn){
//    if(t[i].l == t[i].r){
//        t[i].maxx = maxx;
//        t[i].minn = minn;
//        return;
//    }
//    if(t[i << 1].r >= pos) update(i << 1,pos,maxx,minn);
//    else update(i << 1 | 1,pos,maxx,minn);
//    push_up(i);
//}
//
//int query_max(int i,int l,int r){
//    if(t[i].l >= l && t[i].r <= r){
//        return t[i].maxx;
//    }
//    if(t[i].l > r || t[i].r < l) return 0;
//    int s = 0;
//    if(t[i << 1].r >= l) s = max(s,query_max(i << 1,l,r));
//    if(t[i << 1 | 1].l <= r) s = max(s,query_max(i << 1 | 1,l,r));
//    return s;
//}
//
//int query_min(int i,int l,int r){
//    if(t[i].l >= l && t[i].r <= r){
//        return t[i].minn;
//    }
//    if(t[i].l > r || t[i].r < l) return n + 1;
//    int s = n + 1;
//    if(t[i << 1].r >= l) s = min(s,query_min(i << 1,l,r));
//    if(t[i << 1 | 1].l <= r) s = min(s,query_min(i << 1 | 1,l,r));
//    return s;
//}
//
//int main(){
//    int count;
//    while(cin >> n >> m){
//        count = 0;
//        memset(his,0,sizeof(his));
//        build(1,1,n);
//        while(m --){
//            char ch;
//            int x;
//            cin >> ch;
//            if(ch == 'D'){
//                cin >> x;
//                update(1,x,x,x);
//                his[++ count] = x;
//            }
//            else if(ch == 'Q'){
//                int max1,min1;
//                cin >> x;
//                max1 = query_max(1,1,x);
//                min1 = query_min(1,x,n);
//                if(max1 == min1) cout << 0 << endl;
//                else{
//                    cout << min1 - max1 - 1 << endl;
//                }
//            }
//            else{
//                int tmp = his[count --];
//                update(1,tmp,0,n + 1);
//            }
//        }
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<vector>
//#include<cstring>
//
//using namespace std;
//const int N = 5e5 + 10;
//typedef long long ll;
//int n,id;
//bool vis[N];
//int st[N],ed[N];
//vector<int> map[N];
//
//struct tree{
//    int l,r;
//    int lz;
//}t[N << 2];
//
//void dfs(int rt){
//    vis[rt] = 1;
//    st[rt] = ++ id;
//    for(int i = 0;i < map[rt].size();i ++)
//        dfs(map[rt][i]);
//    ed[rt] = id;
//}
//
//void push_down(int i){
//    if(t[i].lz){
//        t[i << 1].lz = t[i << 1 | 1].lz = t[i].lz;
//        t[i].lz = 0;
//    }
//}
//
//void build(int i,int l,int r){
//    t[i].l = l,t[i].r = r;
//    t[i].lz = 0;
//    if(l == r) return;
//    int mid = l + r >> 1;
//    build(i << 1,l,mid);
//    build(i << 1 | 1,mid + 1,r);
//}
//
//void update(int i,int l,int r,int k){
//    if(t[i].l >= l && t[i].r <= r){
//        t[i].lz = k;
//        return;
//    }
//    push_down(i);
//    if(t[i << 1].r >= l) update(i << 1,l,r,k);
//    if(t[i << 1 | 1].l <= r) update(i << 1 | 1,l,r,k);
//}
//
//int query(int i,int x){
//    if(t[i].l == t[i].r) return t[i].lz;
//    push_down(i);
//    if(t[i << 1].r >= x) return query(i << 1,x);
//    else return query(i << 1 | 1,x);
//}
//
//int main(){
//    int tt;scanf("%d",&tt);
//    int kase = 0;
//    while(tt --){
//        printf("Case #%d:\n",++ kase);
//        id = 0;
//        memset(vis,0,sizeof(vis));
//        memset(st,0,sizeof(st));
//        memset(ed,0,sizeof(ed));
//        scanf("%d",&n);
//        for(int i = 0;i <= n;i ++)
//            map[i].clear();
//        for(int i = 1;i < n;i ++){
//            int u,v;
//            scanf("%d%d",&u,&v);
//            map[v].push_back(u);
//            vis[u] = 1;
//        }
//
//        for(int i = 1;i <= n;i ++){
//            if(!vis[i]){
//                dfs(i);
//                break;
//            }
//        }
//
//        build(1,1,n);
//        int q;
//        scanf("%d",&q);
//        while(q --){
//            char ch;int x;int y;
//            scanf("\n%c%d",&ch,&x);
//            if(ch == 'C'){
//                int ans = query(1,st[x]);
//                if(ans == 0) ans = -1;
//                printf("%d\n",ans);
//            }
//            else{
//                scanf("%d",&y);
//                update(1,st[x],ed[x],y);
//            }
//        }
//    }
//    return 0;
//}
//
//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//const int mod = 1e4 + 7;
//const int N = 1e5 + 10;
//int t[N << 2];
//bool lz[N << 2];
//int n,m;
//
//void push_up(int rt){
//    if(!lz[rt << 1] || !lz[rt << 1 | 1])
//        lz[rt] = 0;
//    else if(t[rt << 1] != t[rt << 1 | 1])
//        lz[rt] = 0;
//    else{
//        lz[rt] = 1;
//        t[rt] = t[rt << 1];
//    }
//}
//void push_down(int rt){
//    if(lz[rt]){
//        lz[rt << 1] = lz[rt << 1 | 1] = 1;
//        t[rt << 1] = t[rt << 1 | 1] = t[rt];
//        lz[rt] = 0;
//    }
//}
//
//void update(int rt,int st,int ed,int l,int r,int v,int op){
//    if(lz[rt] && st >= l && ed <= r){
//        if(op == 1){
//            t[rt] = (t[rt] + v) % mod;
//        }
//        else if(op == 2) t[rt] = t[rt] * v % mod;
//        else t[rt] = v % mod;
//        return;
//    }
//    push_down(rt);
//    int mid = st + ed >> 1;
//    if(l <= mid) update(rt << 1,st,mid,l,r,v,op);
//    if(r > mid) update(rt << 1 | 1,mid + 1,ed,l,r,v,op);
//    push_up(rt);
//}
//
//int query(int rt,int st,int ed,int l,int r,int p){
//    if(lz[rt] && st >= l && ed <= r){
//        int ans = 1;
//        for(int i = 1;i <= p;i ++){
//            ans = ans * t[rt] % mod;
//        }
//        ans = ans * (ed - st + 1) % mod;
//        return ans;
//    }
//    push_down(rt);
//    int mid = st + ed >> 1;
//    int ans = 0;
//    if(l <= mid) ans += query(rt << 1,st,mid,l,r,p);
//    if(r > mid) ans += query(rt << 1 | 1,mid + 1,ed,l,r,p);
//    return ans % mod;
//}
//int main(){
//    while(scanf("%d%d",&n,&m) && (n + m)){
//        memset(t,0,sizeof(t));
//        memset(lz,1,sizeof(lz));
//        while(m --){
//            int op,l,r,p;
//            scanf("%d%d%d%d",&op,&l,&r,&p);
//            if(op >= 1 && op <= 3){
//                update(1,1,n,l,r,p,op);
//            }
//            else{
//                printf("%d\n",query(1,1,n,l,r,p));
//            }
//        }
//    }
//    return 0;
//}

//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 5e4 + 10;
//int n,m;
//struct tree{
//    int l,r,lz;
//}t[N << 2];
//void build(int i,int l,int r){
//    t[i].l = l,t[i].r = r;
//    t[i].lz = 0;
//    if(l == r)return;
//    int mid = l + r >> 1;
//    build(i << 1,l,mid);
//    build(i << 1 | 1,mid + 1,r);
//}
//
//void update(int i,int l,int r){
//
//}
//int main(){
//    int tt;scanf("%d",&tt);
//    while(tt --){
//        scanf("%d%d",&n,&m);
//        build(1,1,n);
//        for(int i = 0;i < m;i ++){
//            int k,x,y;
//            scanf("%d%d%d",&k,&x,&y);
//            if(k == 1){
//                update()
//            }
//        }
//    }
//    return 0;
//}
//
//
//#include<iostream>
//#include<fstream>
//
//using namespace std;
//
//int main(){
//    ofstream outfile;
//    ifstream infile;
//    infile.open("a.txt");
//    outfile.open("b.txt");
//    int a;
//    infile >> a;
//    outfile << a << endl;
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 5e5 + 10;
//int t[N << 2],lz[N << 2];
//int n,m;
//void build(int i,int l,int r){
//    if(l == r){
//        t[i] = 1;
//        return;
//    }
//    int mid = l + r >> 1;
//    build(i << 1,l,mid);
//    build(i << 1 | 1,mid + 1,r);
//    t[i] = t[i << 1] + t[i << 1 | 1];
//}
//
//void push_down(int i,int l,int r){
//    if(lz[i] != -1){
//        lz[i << 1] = lz[i << 1 | 1] = lz[i];
//        int mid = l + r - 1;
//        t[i << 1] = lz[i] * (mid - l + 1);
//        t[i << 1 | 1] = lz[i] * (r - m);
//        lz[i] = -1;
//    }
//}
//
//void update(int i,int l,int r,int L,int R,int val){
//    if(l >= L && r <= R){
//        t[i] = val * (r - l + 1);
//        lz[i] = val;
//        return;
//    }
//    push_down(i,l,r);
//    int mid = l + r >> 1;
//    if(mid >= L) update(i << 1,l,mid,L,R,val);
//    if(mid < R) update(i << 1 | 1,mid + 1,r,L,R,val);
//    t[i] = t[i << 1] + t[i << 1 | 1];
//}
//
//int query(int i,int l,int r,int L,int R){
//    if(l >= L && r <= R) return t[i];
//    push_down(i,l,r);
//    int mid = l + r >> 1;
//    int s = 0;
//    if(mid >= L) s += query(i << 1,l,mid,L,R);
//    if(mid < R) s += query(i << 1 | 1,mid + 1,r,L,R);
//    return s;
//}
//int solve(int s,int num){
//    int l = s,r = n;
//    int ans = -1;
//    while(l <= r){
//        int mid = l + r >> 1;
//        int tmp = query(1,1,n,s,mid);
//        if(tmp == num){
//            ans = mid;
//            r = mid - 1;
//        }
//        else{
//            if(tmp < num)
//                l = mid + 1;
//            else
//                r = mid - 1;
//        }
//    }
//    return ans;
//}
//
//int main(){
//    int tt;scanf("%d",&tt);
//    while(tt --){
//        scanf("%d%d",&n,&m);
//        build(1,1,n);
//        memset(lz,-1,sizeof(lz));
//        int a,b,k;
//        for(int i = 0;i < m;i ++){
//            scanf("%d%d%d",&k,&a,&b);
//            if(k == 1){
//                a ++;
//                int st = solve(a,1);
//                if(st == -1){
//                    printf("Can not put any one.\n");
//                }
//                else {
//                    int tmp = query(1,1,n,st,n);
//                    if(tmp <= b) b = tmp;
//                    int ed = solve(st,b);
//                    update(1,1,n,st,ed,0);
//                    printf("%d %d\n",st - 1,ed - 1);
//                }
//            }
//            else{
//                a ++;
//                b ++;
//                int ans = query(1,1,n,a,b);
//                update(1,1,n,a,b,1);
//                printf("%d\n",b - a + 1 - ans);
//            }
//        }
//        printf("\n");
//    }
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//const int N = 5e4 + 10;
//int t[N << 2],lz[N << 2];
//int n,m;
//
//void build(int l,int r,int rt){
//    if(l == r){
//        t[rt] = 1;
//        return;
//    }
//    int mid = (l + r) >> 1;
//    build(l,mid,rt << 1);
//    build(mid + 1,r,rt << 1 | 1);
//    t[rt] = t[rt << 1] + t[rt << 1 | 1];
//}
//
//void push_down(int l,int r,int rt){
//    if(lz[rt] != -1){
//        int mid = (l + r) >> 1;
//        lz[rt << 1] = lz[rt << 1 | 1] = lz[rt];
//        t[rt << 1] = lz[rt] * (m - l + 1);
//        t[rt << 1 | 1] = lz[rt] * (r - m);
//        lz[rt] = -1;
//    }
//}
//
//void update(int L,int R,int val,int l,int r,int rt){
//    if(l >= L && r <= R){
//        t[rt] = val * (r - l + 1);
//        lz[rt] = val;
//        return;
//    }
//    push_down(l,r,rt);
//    int mid = (l + r) >> 1;
//    if(mid >= L) update(L,R,val,l,mid,rt << 1);
//    if(mid < R) update(L,R,val,mid + 1,r,rt << 1 | 1);
//    t[rt] = t[rt << 1] + t[rt << 1 | 1];
//}
//
//int query(int L,int R,int l,int r,int rt){
//    if(l >= L && r <= R) return t[rt];
//    push_down(l,r,rt);
//    int mid = (l + r) >> 1;
//    int s = 0;
//    if(mid >= L) s += query(L,R,l,mid,rt << 1);
//    if(mid < R) s += query(L,R,mid + 1,r,rt << 1 | 1);
//    return s;
//}
//
//int solve(int s,int num){
//    int l = s,r = n;
//    int ans = -1;
//    while(l <= r){
//        int mid = (l + r) >> 1;
//        int tmp = query(s,mid,1,n,1);
//        if(tmp == num){
//            ans = mid;
//            r = mid - 1;
//        }
//        else{
//            if(tmp < num) l = mid + 1;
//            else r = mid - 1;
//        }
//    }
//    return ans ;
//}
//int main(){
//    int tt;scanf("%d",&tt);
//    while(tt --){
//        scanf("%d%d",&n,&m);
//        build(1,n,1);
//        memset(lz,-1,sizeof(lz));
//        int a,b,k;
//        for(int i = 0;i < m;i ++){
//            scanf("%d%d%d",&k,&a,&b);
//            if(k == 1){
//                a ++;
//                int st = solve(a,1);
//                if(st == -1){
//                    printf("Can not put any one.\n");
//                }
//                else{
//                    int tmp = query(st,n,1,n,1);
//                    if(tmp < b) b = tmp;
//                    int ed = solve(st,b);
//                    update(st,ed,0,1,n,1);
//                    printf("%d %d\n",st - 1,ed - 1);
//                }
//            }
//            else{
//                a ++;
//                b ++;
//                int ans = query(a,b,1,n,1);
//                update(a,b,1,1,n,1);
//                printf("%d\n",b - a + 1 - ans);
//            }
//        }
//        printf("\n");
//    }
//    return 0;
//}

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 500020;
int Tree[maxn << 2], lazy[maxn << 2];
int t, n, m, k;

void Build(int l, int r, int rt)
{
    if(l == r)
    {
        Tree[rt] = 1;
        return ;
    }
    int m = (l + r) / 2;
    Build(l, m, rt << 1);
    Build(m + 1, r, rt << 1 | 1);
    Tree[rt] = Tree[rt << 1] + Tree[rt << 1 | 1];
}

void pushdown(int l, int r, int rt)
{
    if(lazy[rt] == -1)
        return ;
    int m = (l + r) / 2;
    lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
    Tree[rt << 1] = lazy[rt] * (m - l + 1);
    Tree[rt << 1 | 1] = lazy[rt] * (r - m);
    lazy[rt] = -1;
}

void update(int L, int R, int val, int l, int r, int rt)
{
    if(l >= L && r <= R)
    {
        Tree[rt] = val * (r - l + 1);
        lazy[rt] = val;
        return ;
    }
    pushdown(l, r, rt);
    int m = (l + r) / 2;
    if(m >= L)
        update(L, R, val, l, m, rt << 1);
    if(m < R)
        update(L, R, val, m + 1, r, rt << 1 | 1);
    Tree[rt] = Tree[rt << 1] + Tree[rt << 1 | 1];
}

int query(int L, int R, int l, int r, int rt)
{
    if(l >= L && r <= R)
        return Tree[rt];
    pushdown(l, r, rt);
    int m = (l + r) / 2;
    int ans = 0;
    if(m >= L)
        ans += query(L, R, l, m, rt << 1);
    if(m < R)
        ans += query(L, R, m + 1, r, rt << 1 | 1);
    return ans;
}

int solve(int s,int num)
{
    int l = s;
    int r = n;
    int ans = -1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        int temp = query(s, m, 1, n, 1);
        if(temp == num)
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            if(temp < num)
                l = m + 1;
            else
                r = m - 1;
        }
    }
    return ans;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    cin >> t;
    while(t--)
    {
        scanf("%d%d", &n, &m);
        Build(1, n, 1);
        memset(lazy, -1, sizeof(lazy));
        int a, b;
        for(int i = 1; i <= m; ++ i)
        {
            scanf("%d%d%d", &k, &a, &b);
            if(k == 1)
            {
                a++;
                int st = solve(a, 1);
                if(st == -1)
                {
                    cout << "Can not put any one." << endl;
                }
                else
                {
                    int temp = query(st, n, 1, n, 1);
                    if(temp <= b)
                        b = temp;
                    int ed = solve(st, b);
                    update(st, ed, 0, 1, n, 1);
                    printf("%d %d\n", st - 1, ed - 1);
                }
            }
            else
            {
                a ++;
                b ++;
                int ans = query(a, b, 1, n, 1);
                update(a, b, 1, 1, n, 1);
                printf("%d\n", b - a + 1 - ans);
            }
        }
        printf("\n");
    }
    return 0;
}