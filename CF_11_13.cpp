#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<ctime>
//#include<cstdlib>
//using namespace std;
//int t,n,a[105];
//bool is_same_ele(int a[], int i)
//{
//	for (int j = 1; j < i; j++)
//	{
//		if (a[j] == a[i])
//			return true;
//	}
//	return false;
//}
//bool check(int a[],int sz)
//{
//	for (int i = 2; i <= sz; i++)
//	{
//		for (int j = 1; j <= sz-i+1; j++)
//		{
//			int sum = 0;
//			int cnt = i ;
//			int cnt_j = j;
//			while (cnt--)
//			{
//				sum += a[cnt_j];
//				cnt_j++;
//			}
//			if (sum%i)
//				return false;
//		}
//	}
//	return true;
//}
//int main()
//{
//	srand((unsigned int)time(0));
//	cin >> t;
//	while (t--)
//	{
//		cin >> n;
//		if (n == 1)
//		{
//			cout << rand() % 100 + 1;
//		}
//		else
//		{
//			for (int i = 1; i <= n; i++)
//			{
//				while (1)
//				{
//					a[i] = rand() % 100 + 1;
//					if (check(a,i)&&!is_same_ele(a,i))
//					{
//						break;
//					}
//				}
//				cout << a[i];
//				if (i < n)
//					cout << " ";
//				
//			}
//		}
//		
//		cout << endl;
//	}
//	return 0;
//}

#include<iostream>
#include<algorithm>
using namespace std;
int t,n;
long long b[1005],a[1005];
int main()
{
	
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
		}
		for (int i = 0; i < n; i++)
		{
			a[i] = pow(2, b[i]);
		}

	}
	return 0;
}