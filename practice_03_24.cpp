//
// Created by 19116 on 2021/3/24.
//

//#include<iostream>
//#include<cmath>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 1e9;
//bool prime[N];
//void isprime(){
//    prime[1] = 1;
//    for(int i = 2;i <= N;i ++){
//        if(!prime[i]){
//            for(long long j = 2 * i;j <= N;j += i)
//                prime[j] = 1;
//        }
//    }
//}
//int ans;
//string s;
//int l[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
//void dfs(int cur,int num,int cnt){
////    cout << cur << endl;
//    if(cur < 0) {
//        int y = num / 10000;
//        int m = num % 10000 / 100;
//        int d = num % 10000 % 100;
//        if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0){
//            if(m == 2 && d > 29) return;
//        }
//        else{
//            if(m == 2 && d > 28) return;
//        }
//        if(!prime[num]) ans ++;
//        return;
//    }
//    if(cnt == 2 && (num > 31 || num == 0)) return;
//    if(cnt == 4){
//        int m = num / 100;
//        int d = num % 100;
//        if(m > 12 || m == 0) return;
//        if(d > l[m - 1]) return;
//    }
//    if(num && num % 2 == 0) return;
//    if(prime[num] && num % 5 == 0) return;
//    if(isdigit(s[cur])) dfs(cur - 1,num + (s[cur] - '0') * pow(10,cnt),cnt + 1);
//    else {
//        for(int i = 0;i <= 9;i ++){
//            if(!cur && num < 10000 && !i) continue;
//            dfs(cur - 1,num + i * pow(10,cnt),cnt + 1);
//        }
//    }
//}
//
//int main(){
//    int n;cin >> n;
//
//    isprime();
//    for(int i = 0;i < n;i ++){
//        ans = 0;
//        cin >> s;
////        cout << s << endl;
//        int fl = 0;
//        for(int j = 0;j < s.size();j ++){
//            if(s[j] == '-') {
//                fl = 1;
//                break;
//            }
//        }
//        if(!fl){
//            int tmp = 0;
//            for(int j = 0;j < s.size();j ++)
//                tmp = tmp * 10 + s[i] - '0';
//            if(!prime[tmp]) cout << 1 << endl;
//            else cout << 0 << endl;
//            return 0;
//        }
//
//        dfs(s.size() - 1,0,0);
//        cout << ans << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//int p[] = {0,3,5,7,11,13,17,19,23,29,31,37};
//int d[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
//int T,a[66],ans[66666],t,tot;
//char s[10];
//bool isprime(int x){
//    for(int i = 2;i * i <= x;i ++) if(x % i == 0) return false;
//    return true;
//}
//int main(){
//    for(int i = 1;i <= 12;i ++){
//        for(int j = 1;p[j] <= d[i];j ++){
//            if(isprime(i * 100 + p[j]))
//                a[++ t] = i * 100 + p[j];
//        }
//    }
//
//    for(int i = 4;i <= 9999;i += 4){
//        if((i % 100 || i % 400 == 0) && isprime(i * 10000 + 229)) ans[++ tot] = i * 10000 + 229;
//    }
//    for(int i = 1;i <= 9999;i ++){
//        for(int j = 1;j <= t;j ++){
//            if(isprime(i * 10000 + a[j]))
//                ans[++ tot] = i * 10000 + a[j];
//        }
//    }
//    cin >> T;
//    while(T--){
//        cin >> (s + 1);
//        int cnt = 0;
//        for(int i = 1;i <= tot;i ++){
//            int now = ans[i],fl = 1;
//            for(int j = 8;j >= 1 && fl;j --,now /= 10){
//                if(s[j] != '-' && s[j] - '0' != now % 10)fl = 0;
//            }
//            cnt += fl;
//        }
//        cout << cnt << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<cstdio>
//#include<queue>
//
//using namespace std;
//const int M = 110;
//int c[M][M];
//int m,n;
//int vis[M][M][5010];
//struct node{
//    int st,x,y,fl,c,magic;
//};
//int minn = 0x3f3f3f3f;
//int dir[4][2] = {1,0,-1,0,0,1,0,-1};
//
//void bfs(){
//    queue<node> q;
//    node cur,next;
//    cur.x = 1,cur.y = 1,cur.st = 0,cur.magic = 0,cur.fl = 0,cur.c = c[1][1];
//    vis[cur.x][cur.y][0] = 1;
//    q.push(cur);
//    while(!q.empty()){
////        cout << 2 << endl;
//        cur = q.front();q.pop();
//        cout << cur.x << " " << cur.y << " " << cur.st << endl;
//        if(cur.x == m && cur.y == m) {
//            minn = min(cur.st, minn);
//            continue;
//        }
//        for(int i = 0;i < 4;i ++){
//            int tx = cur.x + dir[i][0];
//            int ty = cur.y + dir[i][1];
//            if(tx <= 0 || tx > m || ty <= 0 || ty > m) continue;
//            if(c[tx][ty] == 2 && cur.fl) continue;
//            if(c[tx][ty] == 2){
//                next.st = cur.st + 2;
//                next.c = cur.c;
//                next.fl = 1;
//                next.x = tx,next.y = ty;
//                next.magic = cur.magic + 1;
//                if(!vis[tx][ty][next.magic]){
//                    vis[tx][ty][next.magic] = 1;
//                    q.push(next);
//                }
//            }
//            else{
//                next.fl = 0;
//                next.x = tx,next.y = ty;
//                next.st = cur.st;
//                if(c[tx][ty] != cur.c) next.st ++;
//                next.c = c[tx][ty];
//                next.magic = cur.magic;
//                if(!vis[tx][ty][next.magic]){
//                    vis[tx][ty][next.magic] = 1;
//                    q.push(next);
//                }
//            }
//        }
//    }
//}
//int main(){
//    scanf("%d%d",&m,&n);
//    for(int i = 1;i <= m;i ++){
//        for(int j = 1;j <= m;j ++){
//            c[i][j] = 2;
//        }
//    }
//    for(int i = 0;i < n;i ++){
//        int x,y;
//        scanf("%d%d",&x,&y);
//        scanf("%d",&c[x][y]);
//    }
//    bfs();
//    if(minn == 0x3f3f3f3f) puts("-1");
//    else printf("%d\n",minn);
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//const int N = 110,INF = 0x3f3f3f3f;
//int dir[4][2] = {1,0,-1,0,0,1,0,-1};
//int f[N][N],mp[N][N];
//
//int m,n,ans = INF;
//void dfs(int x,int y,int sum,bool fl){
//    if(x < 1 || y < 1 || x > m || y > m) return ;
//    if(sum >= f[x][y]) return;
//    f[x][y] = sum;
//    if(x == m && y == m){
//        ans = min(ans,sum);
//        return;
//    }
//    for(int i = 0;i < 4;i ++){
//        int tx = x + dir[i][0];
//        int ty = y + dir[i][1];
//        if(mp[tx][ty]){
//            if(mp[tx][ty] == mp[x][y]) dfs(tx,ty,sum,false);
//            else dfs(tx,ty,sum + 1,false);
//        }
//        else{
//            if(!fl){
//                mp[tx][ty] = mp[x][y];
//                dfs(tx,ty,sum + 2,true);
//                mp[tx][ty] = 0;
//            }
//        }
//    }
//}
//int main(){
//    memset(f,0x3f,sizeof(f));
//    scanf("%d%d",&m,&n);
//    for(int i = 1;i <= n;i ++){
//        int x,y,c;
//        scanf("%d%d%d",&x,&y,&c);
//        mp[x][y] = c + 1;
//    }
//    dfs(1,1,0,false);
//    if(ans == INF) puts("-1");
//    else printf("%d\n",ans);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<queue>
//
//using namespace std;
//const int N = 55;
//int a[N][N];
//int mp[N][N];
//int vis[N][N][5];
//int n,m;
//char d[] = {'E','S','W','N'};
//int dir[][2] = {0,1,1,0,0,-1,-1,0};
//int stx,sty,edx,edy;char stdir;
//int getdir(char ch){
//    for(int i = 0;i < 4;i ++) if(d[i] == ch) return i;
//}
//
//struct node{
//    int x,y,st;
//    char dir;
//};
//int bfs(){
//    queue<node> q;
//    node cur,next;
//    cur.x = stx,cur.y = sty,cur.dir = stdir,cur.st = 0;
//    q.push(cur);
//    vis[cur.x][cur.y][getdir(stdir)] = 1;
//    while(!q.empty()){
//        cur = q.front();q.pop();
//        if(cur.x == edx && cur.y == edy) return cur.st;
//        for(int i = 0;i < 5;i ++){
//            if(i == 0){
//                next.x = cur.x,next.y = cur.y;
//                next.st = cur.st + 1;
//                next.dir = d[(getdir(cur.dir) - 1 + 4) % 4];
//                if(!vis[next.x][next.y][getdir(next.dir)]){
//                    q.push(next);
//                    vis[next.x][next.y][getdir(next.dir)] = 1;
//                }
//            }
//            else if(i == 5){
//                next.x = cur.x,next.y = cur.y;
//                next.st = cur.st + 1;
//                next.dir = d[(getdir(cur.dir) + 1) % 4];
//                if(!vis[next.x][next.y][getdir(next.dir)]){
//                    q.push(next);
//                    vis[next.x][next.y][getdir(next.dir)] = 1;
//                }
//            }
//            else{
//                int di = getdir(cur.dir);
//                int tx = cur.x + i * dir[di][0],ty = cur.y + i * dir[di][1];
//                if(tx < 2 || ty < 2 || tx > n || ty > m || mp[tx][ty]) continue;
//                next.x = tx,next.y = ty;
//                next.dir = cur.dir;
//                next.st = cur.st + 1;
//                if(!vis[tx][ty][getdir(next.dir)]){
//                    q.push(next);
//                    vis[tx][ty][getdir(next.dir)] = 1;
//                }
//            }
//        }
//    }
//    return -1;
//}
//
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i = 1;i <= n;i ++){
//        for(int j = 1;j <= m;j ++){
//            scanf("%d",&a[i][j]);
//            if(a[i][j]){
//                mp[i][j] = 1;
//                mp[i][j + 1] = 1;
//                mp[i + 1][j] = 1;
//                mp[i + 1][j + 1] = 1;
//            }
//        }
//    }
////
////    for(int i = 1;i <= n + 1;i ++){
////        for(int j = 1;j <= m + 1;j ++){
////            cout << mp[i][j] << " ";
////        }
////        cout << endl;
////    }
//
//    scanf("%d%d%d%d %c",&stx,&sty,&edx,&edy,&stdir);
//    stx ++,sty ++,edx ++,edy ++;
//    printf("%d\n",bfs());
//    return 0;
//}
//
