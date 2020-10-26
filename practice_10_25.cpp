#define _CRT_SECURE_NO_WARNINGS 1
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


//»¹ÊÇ³¬Ê±
#include<iostream>
#include<cmath>
using namespace std;
bool is_int_1(long n)
{
	if (sqrt(n) - (long)sqrt(n))
		return false;
	else
		return true;
}
double is_int(long a[],int l,int r)
{
	if (l == r)
		return is_int_1(a[l]);
	int m = (l + r) / 2;
	int t1=is_int(a, l, m);
	int t2=is_int(a, m, r);
	return t1 * t2;
}
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
		}
		if (is_int(a,0,n-1))
			cout << "Yes"<<endl;
		else
			cout << "No" << endl;
	}
	return 0;
}