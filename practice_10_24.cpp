#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cmath>
//using namespace std;
//
//long double solve(long double n)
//{
//	return sqrt(n) - (long long)sqrt(n);
//}
//int main()
//{
//	long double n;
//	cin >> n;
//	if (!solve(n))
//	{
//		cout << "yes";
//	}
//	else
//		cout << "no";
//	
//	return 0;
//}

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	long a[100001];
	while (1)
	{
		cin >> n;
		if (!n)
			break;
		int i;
		for (i = 0; i < n; i++)
		{
			cin >> a[i];
			if (sqrt(a[i]) - (int)sqrt(a[i]) != 0)
			{
				cout << "No"<<endl;
				break;
			}
		}
		if (i >= n)
			cout << "Yes"<<endl;
	}
	return 0;
}