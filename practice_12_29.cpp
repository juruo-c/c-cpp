//#include<iostream>
//
//using namespace std;
//
//void print_permutation(int n,int* a,int cur)
//{
//    if(cur == n){
//        for(int i = 0;i < n;i ++) printf("%d ",a[i]);
//        printf("\n");
//    }
//    else{
//        for(int i = 1;i <= n;i ++){
//            int ok = 1;
//            for(int j = 0;j < cur;j ++)
//                if(a[j] == i) ok = 0;
//            if(ok){
//                a[cur] = i;
//                print_permutation(n,a,cur + 1);
//            }
//
//        }
//    }
//}
//
//int main()
//{
//    int a[110];
//    int n;
//    cin >> n;
//    print_permutation(n,a,0);
//    return 0;
//}
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int main()
//{
//    int n, p[10];
//    cin >> n;
//    for(int i = 0;i < n;i ++) cin >> p[i];
//    sort(p, p + n);
//    do{
//        for(int i = 0;i < n;i ++)cout << p[i];
//        cout << endl;
//    }while(next_permutation(p, p + n));
//    return 0;
//}
//

//#include<iostream>
//
//using namespace std;
//
//void print_subset(int n, int* a,int cur)
//{
//    for(int i = 0;i < cur;i ++) cout << a[i];
//    cout << endl;
//    int s = cur ? a[cur - 1] + 1 : 0;
//    for(int i = s;i < n;i ++){
//        a[cur] = i;
//        print_subset(n, a, cur + 1);
//    }
//}
//
//int main()
//{
//    int n;
//    cin >> n;int a[110];
//    print_subset(n, a, 0);
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//int n,a[20];
//
//bool is_prime(int n)
//{
//    if(n < 2) return false;
//    for(int i = 2;i * i <= n;i ++){
//        if(n % i == 0) return false;
//    }
//    return true;
//}
//
//bool vis[20];
//
//void dfs(int cur){
//    if(cur == n && is_prime(a[0] + a[n - 1])){
//        for(int i = 0;i < n;i ++){
//            printf("%d",a[i]);
//            if(i < n - 1) cout << " ";
//        }
//        cout << endl;
//        return ;
//    }
//    for(int i = 2;i <= n;i ++){
//        if(!vis[i] && is_prime(i + a[cur - 1])){
//            a[cur] = i;
//            vis[i] = 1;
//            dfs(cur + 1);
//            vis[i] = 0;
//        }
//    }
//}
//int main()
//{
//    int kase = 0;
//    while(cin >> n){
//        if(kase) cout << endl;
//        printf("Case %d:\n",++kase);
//
//        for(int i = 1;i <= n;i ++){
//            memset(vis,0,sizeof(vis));
//            memset(a,0,sizeof(a));
//            a[0] = i;
//            vis[i] = 1;
//            dfs(1);
//        }
//    }
//    return 0;
//}

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;
vector<int> ans;
int n,L;

bool isHard(int v){
    ans.push_back(v);
    for(int len = 1;len <= ans.size() / 2;len ++){
        bool flag = 1;
        for(int j = 0;j < len;j ++){
            if(ans[ans.size() - len + j] != ans[ans.size() - 2 * len + j]){
                flag = 0;
                break;
            }
        }
        if(flag){
            ans.pop_back();
            return false;
        }
    }
    return true;
}

void dfs(int& cur){
    if(cur == n){
        for(int i = 0;i < ans.size();i ++){
            printf("%c",ans[i] - 1 + 'A');
            if((i + 1) % 64 == 0 || i + 1 == ans.size()) puts("");
            else if((i + 1) % 4 == 0) cout << " " ;
        }
        cout << ans.size() << endl;
        return;
    }
    for(int i = 1;i <= L && cur < n;i ++){
        if(isHard(i)){
            dfs(++cur);
            ans.pop_back();
        }
    }
}

int main()
{
    while(cin >> n >> L && n && L){
        ans.clear();
        int num = 0;
        dfs(num);
    }
    return 0;
}

















