//#include<iostream>
//
//using namespace std;
//const int N = 110;
//int a[N][N];
//
//int main()
//{
//    int t; cin >> t;
//    while(t --){
//        int n, m;
//        cin >> n >> m;
//        for(int i = 1;i <= n;i ++){
//            for(int j = 1;j <= m;j ++){
//                cin >> a[i][j];
//            }
//        }
//
//        for(int i = 1;i <= n;i ++){
//            for(int j = 1;j <= m;j ++){
//                if((i + j) % 2){
//                    if(a[i][j] % 2 == 0)a[i][j] ++;
//                }
//                else{
//                    if(a[i][j] % 2) a[i][j] ++;
//                }
//            }
//        }
//
//        for(int i = 1;i <= n;i ++){
//            for(int j = 1;j <= m;j ++){
//                cout << a[i][j] << " ";
//            }
//            cout << endl;
//        }
//    }
//    return 0;
//}
