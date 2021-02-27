//
// Created by 19116 on 2021/2/27.
//

//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//void count_sort(vector<int> &p,vector<int> &c){
//    int n = p.size();
//    vector<int> cnt(n);
//    for(auto x : c){
//        cnt[x] ++;
//    }
//    vector<int> p_new(n);
//    vector<int> pos(n);
//    pos[0] = 0;
//    for(int i = 1;i < n;i ++) pos[i] = pos[i - 1] + cnt[i - 1];
//    for(auto x : p){
//        int i = c[x];
//        p_new[pos[i]] = x;
//        pos[i] ++;
//    }
//    p = p_new;
//}
//
//int main(){
//    string s;
//    cin >> s;
//    s += "$";
//    int n = s.size();
//    vector<int> p(n),c(n);
//
//    vector<pair<char,int> > a(n);
//    for(int i = 0;i < n;i ++) a[i] = {s[i],i};
//    sort(a.begin(),a.end());
//
//    for(int i = 0;i < n;i ++) p[i] = a[i].second;
//    c[p[0]] = 0;
//    for(int i = 1;i < n;i ++){
//        if(a[i].first == a[i - 1].first){
//            c[p[i]] = c[p[i - 1]];
//        }
//        else{
//            c[p[i]] = c[p[i - 1]] + 1;
//        }
//    }
//
//    int k = 0;
//    while((1 << k) < n){
//        for(int i = 0;i < n;i ++) p[i] = (p[i] - (1 << k) + n) % n;
//
//        count_sort(p,c);
//
//        vector<int> c_new(n);
//        c_new[p[0]] = 0;
//        for(int i = 1;i < n;i ++){
//            pair<int,int> prev = {c[p[i - 1]],c[(p[i - 1] + (1 << k)) % n]};
//            pair<int,int> now = {c[p[i]],c[(p[i] + (1 << k)) % n]};
//            if(now == prev){
//                c_new[p[i]] = c_new[p[i -  1]];
//            }
//            else{
//                c_new[p[i]] = c_new[p[i - 1]] + 1;
//            }
//        }
//        c = c_new;
//        k ++;
//    }
//
//    for(int i = 1;i < n;i ++) cout << p[i] + 1 << " ";
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//int main(){
//    string s;
//    cin >> s;
//    s += "$";
//    int n = s.size();
//    vector<int> p(n),c(n);
//
//    vector<pair<char,int> > a(n);
//    for(int i = 0 ;i < n;i ++) a[i] = {s[i],i};
//    sort(a.begin(),a.end());
//
//    for(int i = 0;i < n;i ++) p[i] = a[i].second;
//    c[p[0]] = 0;
//    for(int i = 1;i < n;i ++){
//        if(a[i].first == a[i - 1].first) c[p[i]] = c[p[i - 1]];
//        else c[p[i]] = c[p[i - 1]] + 1;
//    }
//
//    int k = 0;
//    while((1 << k) < n){
//        vector<pair<pair<int,int>,int> > a(n);
//        for(int i = 0;i < n;i ++)
//            a[i] = {{c[i],c[(i + (1 << k)) % n]}, i};
//        sort(a.begin(),a.end());
//
//        for(int i = 0;i < n;i ++) p[i] = a[i].second;
//        c[p[0]] = 0;
//        for(int i = 1;i < n;i ++){
//            if(a[i].first == a[i - 1].first) c[p[i]] = c[p[i - 1]];
//            else c[p[i]] = c[p[i - 1]] + 1;
//        }
//
//        k ++;
//    }
//
//    for(int i = 0;i < n;i ++) cout << p[i] << " " << s.substr(p[i]) << endl;
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//void radix_sort(vector<pair<pair<int,int>,int> >& a) {
//    int n = a.size();
//    {
//        vector<int> cnt(n);
//        for (auto x : a) {
//            cnt[x.first.second]++;
//        }
//        vector<pair<pair<int, int>, int> > a_new(n);
//        vector<int> pos(n);
//        pos[0] = 0;
//        for (int i = 1; i < n; i++) {
//            pos[i] = pos[i - 1] + cnt[i - 1];
//        }
//        for (auto x : a) {
//            int i = x.first.second;
//            a_new[pos[i]] = x;
//            pos[i]++;
//        }
//        a = a_new;
//    }
//    {
//        vector<int> cnt(n);
//        for (auto x : a) {
//            cnt[x.first.first]++;
//        }
//        vector<pair<pair<int, int>, int> > a_new(n);
//        vector<int> pos(n);
//        pos[0] = 0;
//        for (int i = 1; i < n; i++) {
//            pos[i] = pos[i - 1] + cnt[i - 1];
//        }
//        for (auto x : a) {
//            int i = x.first.first;
//            a_new[pos[i]] = x;
//            pos[i]++;
//        }
//        a = a_new;
//    }
//}
//
//int main(){
//    string s;
//    cin >> s;
//    s += "$";
//    int n = s.size();
//    vector<int> p(n),c(n);
//
//    vector<pair<char,int> > a(n);
//    for(int i = 0 ;i < n;i ++) a[i] = {s[i],i};
//    sort(a.begin(),a.end());
//
//    for(int i = 0;i < n;i ++) p[i] = a[i].second;
//    c[p[0]] = 0;
//    for(int i = 1;i < n;i ++){
//        if(a[i].first == a[i - 1].first) c[p[i]] = c[p[i - 1]];
//        else c[p[i]] = c[p[i - 1]] + 1;
//    }
//
//    int k = 0;
//    while((1 << k) < n){
//        vector<pair<pair<int,int>,int> > a(n);
//        for(int i = 0;i < n;i ++)
//            a[i] = {{c[i],c[(i + (1 << k)) % n]}, i};
//
//        radix_sort(a);
//
//        for(int i = 0;i < n;i ++) p[i] = a[i].second;
//        c[p[0]] = 0;
//        for(int i = 1;i < n;i ++){
//            if(a[i].first == a[i - 1].first) c[p[i]] = c[p[i - 1]];
//            else c[p[i]] = c[p[i - 1]] + 1;
//        }
//
//        k ++;
//    }
//
//    for(int i = 1;i < n;i ++) cout << p[i] + 1 << " " ;
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//void counting_sort(vector<int> &p,vector<int> &c) {
//    int n = p.size();
//    vector<int> cnt(n);
//    for (auto x : c) {
//        cnt[x]++;
//    }
//    vector<int> p_new(n);
//    vector<int> pos(n);
//    pos[0] = 0;
//    for (int i = 1; i < n; i++) {
//        pos[i] = pos[i - 1] + cnt[i - 1];
//    }
//    for (auto x : p) {
//        int i = x;
//        p_new[pos[i]] = x;
//        pos[i]++;
//    }
//    p = p_new;
//}
//
//int main(){
//    string s;
//    cin >> s;
//    s += "$";
//    int n = s.size();
//    vector<int> p(n),c(n);
//
//    vector<pair<char,int> > a(n);
//    for(int i = 0 ;i < n;i ++) a[i] = {s[i],i};
//    sort(a.begin(),a.end());
//
//    for(int i = 0;i < n;i ++) p[i] = a[i].second;
//    c[p[0]] = 0;
//    for(int i = 1;i < n;i ++){
//        if(a[i].first == a[i - 1].first) c[p[i]] = c[p[i - 1]];
//        else c[p[i]] = c[p[i - 1]] + 1;
//    }
//
//    int k = 0;
//    while((1 << k) < n){
//
//        for(int i = 0;i < n;i ++) p[i] = (p[i] - (1 << k) + n) % n;
//
//        counting_sort(p,c);
//
//        vector<int> c_new(n);
//        c_new[p[0]] = 0;
//        for(int i = 1;i < n;i ++){
//            pair<int,int> prev = {c[p[i - 1]],c[(p[i - 1] + (1 << k)) % n]};
//            pair<int,int> now = {c[p[i]] ,c[(p[i] + (1 << k)) % n]};
//            if(now == prev) c_new[p[i]] = c_new[p[i - 1]];
//            else c_new[p[i]] = c_new[p[i - 1]] + 1;
//        }
//        c = c_new;
//        k ++;
//    }
//
//    for(int i = 1;i < n;i ++) cout << p[i] + 1 << " " ;
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//void counting_sort(vector<int>& p,vector<int>& c){
//    int n = p.size();
//    vector<int> cnt(n);
//    for(auto x : c){
//        cnt[x] ++;
//    }
//    vector<int> p_new(n);
//    vector<int> pos;
//    pos[0] = 0;
//    for(int i = 1;i < n;i ++) pos[i] = pos[i - 1] + cnt[i - 1];
//    for(auto x : p){
//        int i = c[x];
//        p_new[pos[i]] = x;
//        pos[i] ++;
//    }
//    p = p_new;
//}
//int main(){
//    string s;
//    cin >> s;
//    s += "$";
//    int n = s.size();
//
//    vector<int> p(n),c(n);
//    vector<pair<char,int> > a(n);
//    for(int i = 0;i < n;i ++) a[i] = {s[i],i};
//    sort(a.begin(),a.end());
//    for(int i = 0;i < n;i ++) p[i] = a[i].second;
//    c[p[0]] = 0;
//    for(int i = 1;i < n;i ++){
//        if(a[i].first == a[i - 1].first) c[p[i]] = c[p[i - 1]];
//        else c[p[i]] = c[p[i - 1]] + 1;
//    }
//
//    int k = 0;
//    while((1 << k) < n){
//        for(int i = 0;i < n;i ++) p[i] = (p[i] - (1 << k) + n) % n;
//
//        counting_sort(p,c);
//
//        vector<int> c_new(n);
//        c_new[p[0]] = 0;
//        for(int i = 1;i < n;i ++){
//            pair<int,int> pre = {c[p[i - 1]],c[(p[i - 1] + (1 << k)) % n]};
//            pair<int,int> now = {c[p[i]],c[(p[i] + (1 << k)) % n]};
//            if(pre == now) c_new[p[i]] = c_new[p[i - 1]];
//            else c_new[p[i]] = c_new[p[i - 1]] + 1;
//        }
//        c = c_new;
//        k ++;
//    }
//    for(int i = 1;i < n;i ++) cout << p[i] + 1 << " ";
//    return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//void counting_sort(vector<int> &p,vector<int> &c){
//    int n = p.size();
//    vector<int> cnt(n);
//    for(auto x : c){
//        cnt[x] ++;
//    }
//    vector<int> p_new(n);
//    vector<int> pos(n);
//    pos[0] = 0;
//    for(int i = 1;i < n;i ++) pos[i] = pos[i - 1] + cnt[i - 1];
//    for(auto x : p){
//        int i = c[x];
//        p_new[pos[i]] = x;
//        pos[i] ++;
//    }
//    p = p_new;
//}
//
//int main(){
//    string s;
//    cin >> s;
//    s += "$";
//    int n = s.size();
//
//    vector<int> p(n),c(n);
//    vector<pair<char,int> > a(n);
//    for(int i = 0;i < n;i ++) a[i] = {s[i], i};
//    sort(a.begin(),a.end());
//    for(int i = 0;i < n;i ++) p[i] = a[i].second;
//    c[p[0]] = 0;
//    for(int i = 1;i < n;i ++){
//        if(a[i].first == a[i - 1].first)
//            c[p[i]] = c[p[i - 1]];
//        else c[p[i]] = c[p[i - 1]] + 1;
//    }
//
//    int k = 0;
//    while((1 << k) < n){
//        for(int i = 0;i < n;i ++) p[i] = (p[i] - (1 << k) + n) % n;
//
//        counting_sort(p,c);
//
//        vector<int> c_new(n);
//        c_new[p[0]] = 0;
//        for(int i = 1;i < n;i ++){
//            pair<int,int> pre = {c[p[i - 1]],c[(p[i - 1] + (1 << k)) % n]};
//            pair<int,int> now = {c[p[i]],c[(p[i] + (1 << k)) % n]};
//            if(pre == now) c_new[p[i]] = c_new[p[i - 1]];
//            else c_new[p[i]] = c_new[p[i - 1]] + 1;
//        }
//        c = c_new;
//
//        k ++;
//    }
//    for(int i = 1;i < n;i ++) cout << p[i] + 1 << " " ;
//    return 0;
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//void counting_sort(vector<int> &p,vector<int> &c){
//    int n = p.size();
//    vector<int> cnt(n);
//    for(auto x : c){
//        cnt[x] ++;
//    }
//    vector<int> pos(n);
//    vector<int> p_new(n);
//    pos[0] = 0;
//    for(int i = 1;i < n;i ++) pos[i] = pos[i - 1] + cnt[i - 1];
//    for(auto x : p){
//        int i = c[x];
//        p_new[pos[i]] = x;
//        pos[i] ++;
//    }
//    p = p_new;
//}
//
//int main(){
//    string s;
//    cin >> s;
//    s += "$";
//    int n = s.size();
//
//    vector<int> p(n),c(n);
//    vector<pair<int,int> > a(n);
//    for(int i = 0;i < n;i ++) a[i] = {s[i],i};
//    sort(a.begin(),a.end());
//
//    for(int i = 0;i < n;i ++) p[i] = a[i].second;
//    c[p[0]] = 0;
//    for(int i = 1;i < n;i ++){
//        if(a[i].first == a[i - 1].first)
//            c[p[i]] = c[p[i - 1]];
//        else c[p[i]] = c[p[i - 1]] + 1;
//    }
//
//    int k = 0;
//    while((1 << k) < n){
//        for(int i = 0;i < n;i ++) p[i] = (p[i] - (1 << k) + n) % n;
//
//        counting_sort(p,c);
//
//        vector<int> c_new(n);
//        c_new[p[0]] = 0;
//        for(int i = 1;i < n;i ++){
//            pair<int,int> pre = {c[p[i - 1]],c[(p[i - 1] + (1 << k)) % n]};
//            pair<int,int> now = {c[p[i]],c[(p[i] + (1 << k)) % n]};
//            if(pre == now) c_new[p[i]] = c_new[p[i - 1]];
//            else c_new[p[i]] = c_new[p[i - 1]] + 1;
//        }
//        c = c_new;
//        k ++;
//    }
//    for(int i = 1;i < n;i ++) cout << p[i] + 1 << " " ;
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//const int N = 1e6 + 10;
//char s[N];
//int y[N],x[N],c[N],sa[N],rk[N];
//int n,m;
//
//void getsa(){
//    for(int i = 1;i <= n;i ++) c[x[i] = s[i]] ++;
//    for(int i = 2;i <= n;i ++) c[i] += c[i - 1];
//    for(int i = n;i >= 1;i --) sa[c[x[i]] --] = i;
//    for(int k = 1;k <= n;k <<= 1){
//        int num = 0;
//        for(int i = n - k + 1;i <= n;i ++) y[++ num] = i;
//        //y[i]第二关键字排名为i的数，第一关键字的位置
//        //第n - k + 1到第n位是没有第二关键字的所以排名在最前面
//        for(int i = 1;i <= n;i ++) if(sa[i] > k) y[++ num] = sa[i] - k;
//        //如果满足(sa[i] > k)那么它可以作为别人的第二关键字
//
//        for(int i = 1;i <= m;i ++) c[i] = 0;
//        for(int i = 1;i <= n;i ++) c[x[i]] ++;
//        for(int i = 2;i <= m;i ++) c[i] += c[i - 1];
//        for(int i = n;i >= 1;i --) sa[c[x[y[i]]] --] = y[i],y[i] = 0;
//
//        swap(x,y);
//
//        x[sa[1]] = 1;num = 1;
//        for(int i = 2;i <= n;i ++)
//            x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? num : ++ num;
//        if(num == n) break;
//        m = num;
//    }
//    for(int i = 1;i <= n;i ++) printf("%d ",sa[i]);
//}
//
//int main(){
//    scanf("%s",s + 1);
//    n = strlen(s + 1);m = 122;
//    getsa();
//    return 0;
//}

//
//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//const int N = 1e6 + 10;
//char s[N];
//int x[N],y[N],c[N],sa[N],rk[N];
//int n,m;
//void get_SA()
//{
//    for (int i=1;i<=n;++i) ++c[x[i]=s[i]];
//    //c数组是桶
//    //x[i]是第i个元素的第一关键字
//    for (int i=2;i<=m;++i) c[i]+=c[i-1];
//    //做c的前缀和，我们就可以得出每个关键字最多是在第几名
//    for (int i=n;i>=1;--i) sa[c[x[i]]--]=i;
//    for (int k=1;k<=n;k<<=1)
//    {
//        int num=0;
//        for (int i=n-k+1;i<=n;++i) y[++num]=i;
//        //y[i]表示第二关键字排名为i的数，第一关键字的位置
//        //第n-k+1到第n位是没有第二关键字的 所以排名在最前面
//        for (int i=1;i<=n;++i) if (sa[i]>k) y[++num]=sa[i]-k;
//        //排名为i的数 在数组中是否在第k位以后
//        //如果满足(sa[i]>k) 那么它可以作为别人的第二关键字，就把它的第一关键字的位置添加进y就行了
//        //所以i枚举的是第二关键字的排名，第二关键字靠前的先入队
//        for (int i=1;i<=m;++i) c[i]=0;
//        //初始化c桶
//        for (int i=1;i<=n;++i) ++c[x[i]];
//        //因为上一次循环已经算出了这次的第一关键字 所以直接加就行了
//        for (int i=2;i<=m;++i) c[i]+=c[i-1];//第一关键字排名为1~i的数有多少个
//        for (int i=n;i>=1;--i) sa[c[x[y[i]]]--]=y[i],y[i]=0;
//        //因为y的顺序是按照第二关键字的顺序来排的
//        //第二关键字靠后的，在同一个第一关键字桶中排名越靠后
//        //基数排序
//        swap(x,y);
//        //这里不用想太多，因为要生成新的x时要用到旧的，就把旧的复制下来，没别的意思
//        x[sa[1]]=1;num=1;
//        for (int i=2;i<=n;++i)
//            x[sa[i]]=(y[sa[i]]==y[sa[i-1]] && y[sa[i]+k]==y[sa[i-1]+k]) ? num : ++num;
//        //因为sa[i]已经排好序了，所以可以按排名枚举，生成下一次的第一关键字
//        if (num==n) break;
//        m=num;
//        //这里就不用那个122了，因为都有新的编号了
//    }
//    for (int i=1;i<=n;++i) printf("%d ",sa[i]);
//}
////void getsa(){
////    for(int i = 1;i <= n;i ++) c[x[i] = s[i]] ++;
////    for(int i = 2;i <= n;i ++) c[i] += c[i - 1];
////    for(int i = n;i >= 1;i --) sa[c[x[i]] --] = i;
////
////    for(int k = 1;k <= n;k <<= 1){
////        int num = 0;
////        for(int i = n - k + 1;i <= n;i ++) y[++ num] = i;
////        for(int i = 1;i <= n;i ++) if(sa[i] > k) y[++ num] = sa[i] - k;
////
////        for(int i = 1;i <= m;i ++) c[i] = 0;
////        for(int i = 1;i <= n;i ++) c[x[i]] ++;
////        for(int i = 2;i <= m;i ++) c[i] += c[i - 1];
////        for(int i = n;i >= 1;i --) sa[c[x[y[i]]] --] = y[i],y[i] = 0;
////
////        swap(x,y);
////
////        x[sa[1]] = 1;num = 1;
////        for(int i = 2;i <= n;i ++)
////            x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? num : ++ num;
////
////        if(num == n) break;
////        m = num;
////    }
////    for(int i = 1;i <= n;i ++) printf("%d ",sa[i]);
////}
//int main(){
//    scanf("%s",s + 1);
//    n = strlen(s + 1),m = 122;
////    getsa();
//    get_SA();
//    return 0;
//}


//#include<iostream>
//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//const int N = 1e6 + 10;
//char s[N];
//int y[N],x[N],c[N],sa[N];
//int n,m;
//void getsa(){
//    for(int i = 1;i <= n;i ++) c[x[i] = s[i]] ++;
//    for(int i = 2;i <= m;i ++) c[i] += c[i - 1];
//    for(int i = n;i >= 1;i --) sa[c[x[i]]--] = i;
//
//    for(int k = 1;k <= n;k <<= 1){
//        int num = 0;
//        for(int i = n - k + 1;i <= n;i ++) y[++ num] = i;
//        for(int i = 1;i <= n;i ++) if(sa[i] > k) y[++ num] = sa[i] - k;
//        for(int i = 1;i <= m;i ++) c[i] = 0;
//        for(int i = 1;i <= n;i ++) c[x[i]] ++;
//        for(int i = 2;i <= m;i ++) c[i] += c[i - 1];
//        for(int i = n;i >= 1;i --) sa[c[x[y[i]]] --] = y[i],y[i] = 0;
//
//        swap(x,y);
//
//        x[sa[1]] = 1;num = 1;
//        for(int i = 2;i <= n;i ++)
//            x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? num : ++ num;
//        if(num == n) break;
//        m = num;
//    }
//    for(int i = 1;i <= n;i ++) printf("%d ",sa[i]);
//}
//
//int main(){
//    scanf("%s",s + 1);
//    n = strlen(s + 1);
//    m = 122;
//    getsa();
//    return 0;
//}

////
////凸包Graham
////
//#include<iostream>
//#include<cstdio>
//#include<cmath>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e5 + 10;const double eps = 1e-8;
//int sgn(double x){return x < -eps ? -1 : x > eps;}
//bool cmp(double a,double b){return !sgn(fabs(a - b));}
//struct Point;
//typedef Point Vector;
//
//struct Point{
//    double x,y;
//    Point(){}
//    Point(double x,double y) : x(x),y(y) {}
//    void read(){scanf("%lf%lf",&x,&y);}
//    double length(){return sqrt(x * x + y * y);}
//    Point operator+ (const Point& p)const{return Point(x + p.x,y + p.y);}
//    Vector operator- (const Point& p)const{return Vector(x - p.x,y - p.y);}
//    Vector operator* (const double d)const{return Vector(x * d,y * d);}
//    Vector operator/ (const double d)const{return Vector(x / d,y / d);}
//    double operator* (const Vector& v)const{return x * v.x + y * v.y;}
//    double operator^ (const Vector& v)const{return x * v.y - y * v.x;}
//    bool operator < (const Point& p){
//        if(cmp(y,p.y) == 0) return x < p.x;
//        return y < p.y;
//    }
//};
//Point base;
//bool grahamcmp(Point& p1,Point& p2){
//    if(sgn((p1 - base) ^ (p2 - base)) == 0)
//        return (p1 - base).length() < (p2 - base).length();
//    return sgn((p1 - base) ^ (p2 - base)) > 0;
//}
//Point p[N];
//Point stk[N];
//int n;
//int graham(){
//    for(int i = 2;i <= n;i ++){
//        if(p[i] < p[1]) swap(p[i],p[1]);
//    }
//    base = p[1];
//    sort(p + 2,p + 1 + n,grahamcmp);
//    int k = 0;
//    stk[++ k] = p[1],stk[++ k] = p[2];
//    for(int i = 3;i <= n;i ++){
//        while(k > 1 && sgn((stk[k] - stk[k - 1]) ^ (p[i] - stk[k - 1])) < 0) k --;
//        stk[++ k] = p[i];
//    }
//    return k;
//}
//
//int main(){
//    scanf("%d",&n);
//    for(int i = 1;i <= n;i ++)
//        p[i].read();
//    int k = graham();
//    double len = 0;
//    for(int i = 1;i < k;i ++){
//        len += (stk[i + 1] - stk[i]).length();
//    }
//    len += (stk[1] - stk[k]).length();
//    printf("%.2f\n",len);
//    return 0;
//}


////凸包Andrew
//
//#include<iostream>
//#include<cstdio>
//#include<cmath>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e5 + 10;const double eps = 1e-8;
//int sgn(double x){return x < -eps ? -1 : x > eps;}
//bool cmp(double a,double b){return !sgn(fabs(a - b));}
//struct Point;
//typedef Point Vector;
//
//struct Point{
//    double x,y;
//    Point(){}
//    Point(double x,double y) : x(x),y(y) {}
//    void read(){scanf("%lf%lf",&x,&y);}
//    double length(){return sqrt(x * x + y * y);}
//    Point operator+ (const Point& p)const{return Point(x + p.x,y + p.y);}
//    Vector operator- (const Point& p)const{return Vector(x - p.x,y - p.y);}
//    Vector operator* (const double d)const{return Vector(x * d,y * d);}
//    Vector operator/ (const double d)const{return Vector(x / d,y / d);}
//    double operator* (const Vector& v)const{return x * v.x + y * v.y;}
//    double operator^ (const Vector& v)const{return x * v.y - y * v.x;}
//    bool operator < (const Point& p){
//        if(cmp(y,p.y) == 0) return x < p.x;
//        return y < p.y;
//    }
//};
//int n;
//Point p[N];
//Point stk[N];
//bool Andrewcmp(Point& a,Point& b){
//    return a.x < b.x;
//}
//int Andrew(){
//    sort(p,p + n,Andrewcmp);
//    int m = 0;
//    for(int i = 0;i < n;i ++){
//        while(m > 1 && sgn((stk[m - 1] - stk[m - 2]) ^ (p[i] - stk[m - 2])) < 0) m --;
//        stk[m ++] = p[i];
//    }
//    int k = m;
//    for(int i = n - 2;i >= 0;i --){
//        while(m > k && sgn((stk[m - 1] - stk[m - 2]) ^ (p[i] - stk[m - 2])) < 0) m --;
//        stk[m ++] = p[i];
//    }
//    if(n > 1) m --;
//    return m;
//}
//
//int main(){
//    scanf("%d",&n);
//    for(int i = 0;i < n;i ++) p[i].read();
//    int k = Andrew();
//    double len = 0;
//    for(int i = 0;i < k - 1;i ++){
//        len += (stk[i + 1] - stk[i]).length();
//    }
//    len += (stk[0] - stk[k - 1]).length();
//    printf("%.2f",len);
//    return 0;
//}

////三维凸包
//
//#include<iostream>
//#include<cstdio>
//#include<cmath>
//#include<algorithm>
//
//using namespace std;
//const int N = 2010;const double eps = 1e-8;
//int n,cnt,vis[N][N];
//double ans;
//int sgn(double x){return x < -eps ? -1 : x > eps;}
//bool cmp(double a,double b){return !sgn(fabs(a - b));}
//struct Point;
//typedef Point Vector;
//
//struct Point{
//    double x,y;
//    Point(){}
//    Point(double x,double y) : x(x),y(y) {}
//    void read(){scanf("%lf%lf",&x,&y);}
//    Point operator+ (const Point& p)const{return Point(x + p.x,y + p.y);}
//    Vector operator- (const Point& p)const{return Vector(x - p.x,y - p.y);}
//    Vector operator* (const double d)const{return Vector(x * d,y * d);}
//    Vector operator/ (const double d)const{return Vector(x / d,y / d);}
//    double operator* (const Vector& v)const{return x * v.x + y * v.y;}
//    double operator^ (const Vector& v)const{return x * v.y - y * v.x;}
//};//二维点
//
////平面扰动
//double Rand(){return rand() / (double)RAND_MAX;}
//double reps(){return (Rand() - 0.5) * eps;}
//struct Node{
//    double x,y,z;
//    Node(){}
//    Node(double x,double y,double z) : x(x),y(y),z(z) {}
//    void read(){scanf("%lf%lf%lf",&x,&y,&z);}
//    void shake(){x += reps();y += reps();z += reps();}
//    double length(){return sqrt(x * x + y * y + z * z);}
//    Node operator - (const Node& a){return Node(x - a.x,y - a.y,z - a.z);}
//    Node operator ^ (const Node& a){return Node(y * a.z - z * a.y,z * a.x - x * a.z,x * a.y - y * a.x);}
//    double operator * (const Node& a){return x * a.x + y * a.y + z * a.z;}
//};
//
//Node a[N];
//struct Face{
//    int v[3];
//    Node Normal(){return (a[v[1]] - a[v[0]]) ^ (a[v[2]] - a[v[0]]);}
//    double area(){return Normal().length() / 2.0;}
//};
//
//Face f[N],c[N];
//
//int see(Face x,Node b){return ((b - a[x.v[0]]) * x.Normal()) > 0;}
//void Convex_3D(){
//    f[++ cnt] = (Face) {1,2,3};
//    f[++ cnt] = (Face) {3,2,1};
//    for(int i = 4,cc = 0;i <= n;i ++){
//        for(int j = 1,v;j <= cnt;j ++){
//            if(!(v = see(f[j],a[i]))) c[++ cc] = f[j];
//            for(int k = 0;k < 3;k ++) vis[f[j].v[k]][f[j].v[(k + 1) % 3]] = v;
//        }
//        for(int j = 1;j <= cnt;j ++){
//            for(int k = 0;k < 3;k ++){
//                int x = f[j].v[k],y = f[j].v[(k + 1) % 3];
//                if(vis[x][y] && !vis[y][x]) c[++ cc] = (Face){x,y,i};
//            }
//        }
//        for(int j = 1;j <= cc;j ++) f[j] = c[j];
//        cnt = cc;cc = 0;
//    }
//}
//int main(){
//    scanf("%d",&n);
//    for(int i = 1;i <= n;i ++) a[i].read();
//    Convex_3D();
//    for(int i = 1;i <= cnt;i ++) ans += f[i].area();
//    printf("%.6f",ans);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cmath>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e5 + 10;const double eps = 1e-8;
//int sgn(double x){return x < -eps ? -1 : x > eps;}
//bool cmp(double a,double b){return !sgn(fabs(a - b));}
//struct Point;
//typedef Point Vector;
//
//struct Point{
//    int x,y;
//    Point(){}
//    Point(int x,int y) : x(x),y(y) {}
//    void read(){scanf("%d%d",&x,&y);}
//    double length(){return sqrt(x * x + y * y);}
//    Point operator+ (const Point& p)const{return Point(x + p.x,y + p.y);}
//    Vector operator- (const Point& p)const{return Vector(x - p.x,y - p.y);}
//    Vector operator* (const double d)const{return Vector(x * d,y * d);}
//    Vector operator/ (const double d)const{return Vector(x / d,y / d);}
//    double operator* (const Vector& v)const{return x * v.x + y * v.y;}
//    int operator^ (const Vector& v)const{return x * v.y - y * v.x;}
//    bool operator < (const Point& p)const{
//        if(cmp(y,p.y) == 0) return x < p.x;
//        return y < p.y;
//    }
//};
//int n;
//Point p[N];
//Point stk[N];
//bool Andrewcmp(Point& a,Point& b){
//    return a.x < b.x;
//}
//int Andrew(){
//    sort(p,p + n,Andrewcmp);
//    int m = 0;
//    for(int i = 0;i < n;i ++){
//        while(m > 1 && ((stk[m - 1] - stk[m - 2]) ^ (p[i] - stk[m - 2])) < 0) m --;
//        stk[m ++] = p[i];
//    }
//    int k = m;
//    for(int i = n - 2;i >= 0;i --){
//        while(m > k && ((stk[m - 1] - stk[m - 2]) ^ (p[i] - stk[m - 2])) < 0) m --;
//        stk[m ++] = p[i];
//    }
//    if(n > 1) m --;
//    return m;
//}
//int get_dist(const Point& a){return a.x * a.x + a.y * a.y;}
//int con_num;
//int Rotating_calipers(){
//    int op = 1,ans = 0;
//    for(int i = 0;i < con_num;i ++){
//        while(((stk[op] - stk[i]) ^ (stk[i + 1] - stk[i])) < ((stk[op + 1] - stk[i]) ^ (stk[i + 1] - stk[i])))
//            op = (op + 1) % con_num;
//        ans = max(ans,max(get_dist(stk[i] - stk[op]) , get_dist(stk[i + 1] - stk[op])));
//    }
//    return ans;
//}
//
//int main(){
//    scanf("%d",&n);
//    for(int i = 0;i < n;i ++) p[i].read();
//    con_num = Andrew();
//    printf("%d\n",Rotating_calipers());
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cmath>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e6 + 10;
//const double eps = 1e-9;
//int sgn(double x){return x < -eps ? -1 : x > eps;}
//struct Point{
//    double x,y;
//    Point(){}
//    Point(double x,double y) : x(x),y(y) {}
//    void read(){scanf("%lf%lf",&x,&y);}
//    double length(){return sqrt(x * x + y * y);}
//    Point operator - (const Point& b)const{return Point(x - b.x,y - b.y);}
//    Point operator + (const Point& b)const{return Point(x + b.x,y + b.y);}
//    double operator * (const Point& b)const{return x * b.x + y * b.y;}
//    bool operator < (const Point& b)const{
//        if(!sgn(fabs(x - b.x))) return y < b.y;
//        return x < b.x;
//    }
//    bool operator == (const Point& b)const{
//        return !sgn(fabs(x - b.x)) && !sgn(fabs(y - b.y));
//    }
//};
//double cross(Point& a,Point& b,Point& c){//ab ^ ac
//    return (b - a).x * (c - a).y - (b - a).y * (c - a).x;
//}
//Point p[N];
//Point stk[N];
//int n,m,ans;
//void Andrew(){
//    sort(p, p + n);
//    for(int i = 0;i < n;i ++){
//        while(m > 1 && cross(stk[m - 2],stk[m - 1],p[i]) <= 0) m --;
//        stk[m ++] = p[i];
//    }
//    int k = m;
//    for(int i = n - 2;i >= 0;i --){
//        while(m > k && cross(stk[m - 2],stk[m - 1],p[i]) <= 0) m --;
//        stk[m ++] = p[i];
//    }
//    if(n > 1) m --;
//}
//int get_dis(Point& a,Point& b){return (b - a).x * (b - a).x + (b - a).y + (b - a).y;}
//void Rotating_calipers(){
//    int op = 1;
//    for(int i = 0;i < m;i ++){
//        if(cross(stk[i],stk[i + 1],stk[op]) < cross(stk[i],stk[i + 1],stk[op + 1]))
//            op = (op + 1) % m;
//        ans = max(ans,max(get_dis(stk[op],stk[i]),get_dis(stk[op],stk[i + 1])));
//    }
//    printf("%d\n",ans);
//}
//int main(){
//    scanf("%d",&n);
//    for(int i = 0; i < n;i ++) p[i].read();
//    Andrew();
//    Rotating_calipers();
//    return 0;
//}
//
//#include<iostream>
//#include<cstdio>
//#include<cmath>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e6 + 10;
//const double eps = 1e-9;
//int sgn(double x){return x < -eps ? -1 : x > eps;}
//struct Point{
//    int x,y;
//    Point(){}
//    Point(int x,int y) : x(x),y(y) {}
//    void read(){scanf("%lf%lf",&x,&y);}
//    int length(){return sqrt(x * x + y * y);}
//    Point operator - (const Point& b)const{return Point(x - b.x,y - b.y);}
//    Point operator + (const Point& b)const{return Point(x + b.x,y + b.y);}
//    double operator * (const Point& b)const{return x * b.x + y * b.y;}
//    bool operator < (const Point& b)const{
//        if(x == b.x) return y < b.y;
//        return x < b.x;
//    }
//    bool operator == (const Point& b)const{
//        return !sgn(fabs(x - b.x)) && !sgn(fabs(y - b.y));
//    }
//};
//int cross(Point& a,Point& b,Point& c){//ab ^ ac
//    return (b - a).x * (c - a).y - (b - a).y * (c - a).x;
//}
//Point p[N];
//Point stk[N];
//int n,m,ans;
//void Andrew(){
//    sort(p, p + n);
//    for(int i = 0;i < n;i ++){
//        while(m > 1 && cross(stk[m - 2],stk[m - 1],p[i]) < 0) m --;
//        stk[m ++] = p[i];
//    }
//    int k = m;
//    for(int i = n - 2;i >= 0;i --){
//        while(m > k && cross(stk[m - 2],stk[m - 1],p[i]) < 0) m --;
//        stk[m ++] = p[i];
//    }
//    if(n > 1) m --;
//}
//int get_dis(Point& a,Point& b){return (b - a).x * (b - a).x + (b - a).y + (b - a).y;}
//void Rotating_calipers(){
//    int op = 1;
//    for(int i = 0;i < m;i ++){
//        if(cross(stk[i],stk[i + 1],stk[op]) < cross(stk[i],stk[i + 1],stk[op + 1]))
//            op = (op + 1) % m;
//        ans = max(ans,max(get_dis(stk[op],stk[i]),get_dis(stk[op],stk[i + 1])));
//    }
//    printf("%d\n",ans);
//}
//int main(){
//    scanf("%d",&n);
//    for(int i = 0; i < n;i ++) p[i].read();
//    Andrew();
//    Rotating_calipers();
//    return 0;
//}


//#include<cstdio>
//#include<algorithm>
//#include<cmath>
//
//using namespace std;
//const int N = 5e4 + 10;
//int n,m;
//struct Point{
//    int x,y;
//    Point(){}
//    Point(int x,int y) : x(x),y(y){}
//    int length(){
//        return x * x + y * y;
//    }
//    Point operator - (const Point& b)const{return Point(x - b.x,y - b.y);}
//    bool operator < (const Point& b){
//        if(x == b.x) return y < b.y;
//        return x < b.x;
//    }
//};
//
//int dis(Point& a,Point& b){
//    return (b - a).length();
//}
//
//int cross(Point& a,Point& b,Point& c){
//    return (b - a).x * (c - a).y - (b - a).y * (c - a).x;
//}
//Point p[N],st[N];
//void Andrew(){
//    sort(p,p + n);
//    for(int i = 0;i < n;i ++){
//        while(m > 1 && cross(st[m - 2],st[m - 1],p[i]) <= 0) m --;
//        st[m ++] = p[i];
//    }
//    int k = m;
//    for(int i = n - 2;i >= 0;i --){
//        while(m > k && cross(st[m - 2],st[m - 1],p[i]) <= 0) m --;
//        st[m ++] = p[i];
//    }
//    if(n > 1) m --;
//}
//void Rotating_Calipers(){
//    int cur = 1;int ans = 0;
//    for(int i = 0;i < m;i ++){
//        while(cross(st[i],st[i + 1],st[cur]) < cross(st[i],st[i + 1],st[cur + 1]))
//            cur = (cur + 1) % m;
//        ans = max(ans,max(dis(st[i],st[cur]),dis(st[i + 1],st[cur])));
//    }
//    printf("%d\n",ans);
//}
//
//int main(){
//    scanf("%d",&n);
//    for(int i = 0;i < n;i ++) scanf("%d%d",&p[i].x,&p[i].y);
//    Andrew();
//    Rotating_Calipers();
//}