//#include<iostream>
//#include<cstdio>
//
//using namespace std;
//
//int main()
//{
//    int t; cin >> t;
//    int D,I;
//    while(t -- ){
//        cin >> D >> I;
//        int k = 1;
//        for(int i = 0;i < D - 1;i ++){
//            if(I % 2) {
//                k = k * 2;
//                I = (I + 1) / 2;
//            }
//            else{
//                k = k * 2 + 1;
//                I /= 2;
//            }
//        }
//        cout << k << endl;
//    }
//    cin >> t;
//    return 0;
//}
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<cmath>
//#include<cstdio>
//#include<stack>
//
//using namespace std;
//typedef long long ll;
//const int mod = 1e9 + 7;
//const int N = 2;
//
//struct Mat
//{
//    ll m[N][N];
//}ans,a;
//
//Mat mul(Mat a,Mat b,int n)
//{
//    Mat c;
//    memset(c.m,0,sizeof(c.m));
//    for(int i = 0;i < n;i ++){
//        for(int j = 0;j < n;j ++){
//            for(int k = 0;k < n;k ++){
//                c.m[i][j] = (c.m[i][j] + (a.m[i][k] * b.m[k][j]) % mod) % mod;
//            }
//        }
//    }
//    return c;
//}
//
//void _power(Mat a,ll b,int n)
//{
//    memset(ans.m,0,sizeof(ans.m));
//    for(int i = 0;i < n;i ++){
//        ans.m[i][i] = 1;
//    }
//    while(b){
//        if(b & 1) ans = mul(ans, a, n);
//        a = mul(a,a,n);
//        b >>= 1;
//    }
//}
//
//ll _pow(ll a,int b)
//{
//    ll ans = 1;
//    while(b){
//        if(b & 1) ans *= a;
//        a = a * a;
//        b >>= 1;
//    }
//    return ans;
//}
//
//int main()
//{
//    int T;scanf("%d",&T);
//    while(T --){
//        ll n; scanf("%lld",&n);
//        stack<int> stk;
//        while(n){
//            stk.push(n%10);
//            n /= 10;
//        }
//        ll t = 0;
//        while(!stk.empty()){
//            t = t * 9 + stk.top();
//            stk.pop();
//        }
//        a.m[0][0] = 0,a.m[0][1] = 1,a.m[1][0] = 1,a.m[1][1] = 1;
//        _power(a,t,N);
//
//        printf("%lld\n",(ans.m[0][0] + ans.m[1][0]) % mod);
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<map>
//#include<vector>
//#include<sstream>
//#include<set>
//
//using namespace std;
//const int N = 1e5 + 10;
//int hp = 6e6;
//int week = 1,boss = 1;
//int flag = 0;
//string peo;
//set<string> tree;
//
//int main()
//{
//    string s;
//    while(getline(cin,s)){
//        stringstream input(s);
//        string name; input >> name;
//        name = name.substr(0,name.length() - 1);
//        string op; input >> op;
//        if(op[0] == 'A' && !tree.count(name)){
//            if(flag){
//                cout << "robot: " << peo << "正在出刀,请勿进场!" << endl;
//            }
//            else{
//                cout << "robot: " << name << "成功申请出刀" << endl;
//                flag = 1;
//                peo = name;
//            }
//        }
//        else if(op[0] == 'T' && !tree.count(name)){
//            if(flag = 1 && peo == name) flag = 0;
//            tree.insert(name);
//        }
//        else if(op[0] == 'R' && !tree.count(name)){
//            int k ; input >> k;
//            hp -= k;
//            if(hp > 0){
//                cout << "robot: " << name << "出刀成功,伤害为" << k << ",当前BOSS血量为" << hp << ".\n";
//            }
//            else{
//                cout << "robot: " << name << "出刀成功,成功斩杀BOSS." << endl;
//                hp = 6e6;
//                boss ++;
//                if(boss > 7) boss = 1,week ++;
//                cout << "robot: 下树提醒: ";
//                for(auto x : tree){
//                    cout << "@" << x;
//                }
//                cout << endl;
//                tree.clear();
//            }
//        }
//        else if(op[0] == 'Q'){
//            printf("robot: 状态: { 当前周目: %d BOSS编号: %d BOSSHp: %d; }\n",week,boss,hp);
//        }
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//
//using namespace std;
//
//struct Node{
//    int val,assigncnt = 0;
//    Node *l = NULL,*r = NULL;
//};
//Node* root = NULL;
//
//void insertNode(string s,Node* root){
//    int i = s.find(',');
//    string ds = s.substr(i + 1,s.size() - i - 1 - 1);
//    for(int j = 0;j < ds.size();j ++){
//        if(ds[j] == 'L'){
//            if(root->l == NULL) root -> l = new Node;
//            root = root -> l;
//        }
//        else if(ds[j] == 'R'){
//            if(root -> r == NULL) root -> r = new Node;
//            root = root -> r;
//        }
//    }
//    root -> val = stoi(s.substr(1,i));
//    root -> assigncnt ++;
//}
//
//void bfs(Node* root){
//    bool islegal = true;
//    vector<int> out;
//    queue<Node*> q;
//    if(root != NULL) q.push(root);
//    while(!q.empty() && islegal){
//        Node* node = q.front();q.pop();
//        if(node -> assigncnt != 1) islegal = false;
//        else{
//            out.push_back(node -> val);
//            if(node -> l != NULL) q.push(node -> l);
//            if(node -> r != NULL) q.push(node -> r);
//        }
//    }
//    if(islegal){
//        for(int i = 0;i < out.size();i ++){
//            printf("%d%s",out[i],i == out.size() - 1 ? "\n" : " ");
//        }
//    }
//    else cout << "not complete" << endl;
//}
//int main()
//{
//    string s;
//    while(cin >> s){
//        if(s == "()"){
//            bfs(root);
//            root = NULL;
//        }
//        else{
//            if(root == NULL) root = new Node;
//            insertNode(s,root);
//        }
//    }
//    return 0;
//}
//

//#include<iostream>
//#include<cstring>
//
//using namespace std;
//const int mod = 1e9 + 7;
//typedef long long ll;
//const int N = 110;
//struct Mat
//{
//    ll m[N][N];
//}ans,a;
//
//Mat mul(Mat a,Mat b,int n)
//{
//    Mat c;
//    memset(c.m,0,sizeof(c.m));
//    for(int i = 0;i < n;i ++)
//        for(int j = 0;j < n;j ++)
//            for(int k = 0;k < n;k ++)
//                c.m[i][j] = (c.m[i][j] + (a.m[i][k] * b.m[k][j]) % mod) % mod;
//    return c;
//}
//
//void _power(Mat a,ll k,int n)
//{
//    memset(ans.m,0,sizeof(ans.m));
//    for(int i = 0;i < n;i ++)
//        ans.m[i][i] = 1;
//    while(k){
//        if(k & 1) ans = mul(ans,a,n);
//        a = mul(a,a,n);
//        k >>= 1;
//    }
//}
//
//int main()
//{
//    ll n,k;
//    cin >> n >> k;
//    for(int i = 0;i < n;i ++){
//        for(int j = 0;j < n;j ++){
//            cin >> a.m[i][j];
//        }
//    }
//    _power(a,k,n);
//
//    for(int i = 0;i < n;i ++){
//        for(int j = 0;j < n;j ++){
//            cout << ans.m[i][j] << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}















