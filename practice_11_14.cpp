#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int a[5];
//	/*scanf("%d", a);*///数组名代表数组首元素地址
//	//下面是数组名不代表首元素地址的特殊情况
//	//1.&a -- 代表整个数组的地址
//	printf("%x\n", a);
//	printf("%x\n", a+1);//加1跳过一个元素
//	printf("%x\n", &a);
//	printf("%x\n", &a+1);//加1跳过一个数组
//	//2.sizeof(a) -- 计算整个数组的大小，单位字节
//
//	//还有这个东西
//	//a[0] == *(a+1) (==)为等价于
////    所以a[i] == *(a+i)
//	 //a[i][j] == *(*(a+i)+j)
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int s[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//int main()
//{
//	int year, month, day;
//	while (scanf("%d/%d/%d", &year, &month, &day))
//	{
//		int sum = 0;
//		for (int i = 0; i < month - 1; i++)
//		{
//			sum += s[i];
//		}
//		if ((year % 4 == 0 && year % 100 != 0 || year % 400 == 0)&&month>2)
//		{
//			sum++;
//		}
//		printf("%d\n", sum + day);
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int n;
//	int a[100001];
//	while (cin >> n)
//	{
//		int sum = 1;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> a[i];
//		}
//		for (int i = 0; i < n; i++)
//		{
//			if (a[i] % 2)
//			{
//				sum*=a[i];
//			}
//		}
//		cout << sum << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	long long m, n;
//	while (cin >> m >> n)
//	{
//		long long sum1 = 0;
//		long long sum2 = 0;
//		for (long long i = m; i <= n; i++)
//		{
//			if (i % 2)
//			{
//				sum2 += pow(i, 3);
//			}
//			else
//				sum1 += pow(i, 2);
//		}
//		cout << sum1 << " " << sum2 << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int n;
//	float a[101];
//	while (cin >> n&&n)
//	{
//		int cnt[3] = { 0 };
//		for (int i = 0; i < n; i++)
//		{
//			cin >> a[i];
//		}
//		for (int i = 0; i < n; i++)
//		{
//			if (!a[i])
//				cnt[1]++;
//			else if (a[i] < 0)
//				cnt[0]++;
//			else
//				cnt[2]++;
//		}
//		for (int i = 0; i < 3; i++)
//		{
//			cout << cnt[i] ;
//			if (i < 2)
//				cout << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	double n;
//	int m;
//	while (cin >> n >> m)
//	{
//		double sum = 0.0;
//		for (int i = 0; i < m; i++)
//		{
//			sum += n;
//			n = sqrt(n);
//		}
//		printf("%.2lf\n", sum);
//	}
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//bool is_num(int n)
//{
//	int sum = 0;
//	int tmp = n;
//	while (n)
//	{
//		sum += pow(n % 10, 3);
//		n /= 10;
//	}
//	if (sum == tmp)
//		return true;
//	else
//		return false;
//}
//int main()
//{
//	int m, n;
//	while (cin >> m >> n)
//	{
//		int flag = 1;
//		for (int i = m; i <= n; i++)
//		{
//			if (is_num(i))
//			{
//				if (!flag)
//					cout << " ";
//				cout << i;
//				flag = 0;
//			}
//		}
//		if (flag)
//			cout << "no" ;
//		cout << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int n,m;
//	cin >> n;
//	while (n--)
//	{
//		int flag = 1;
//		cin >> m;
//		double sum = 0.0;
//		for (double i = 1; i <= m; i++)
//		{
//			sum += flag * 1 / i;
//			flag = -flag;
//		}
//		printf("%.2lf\n", sum);
//	}
//	return 0;
//}

//#include<iostream>
//#include<cmath>
//using namespace std;
//bool is_prime(int n)
//{
//	if (n < 2)
//		return false;
//	for (int i = 2; i <= (int)sqrt(n); i++)
//	{
//		if (n%i == 0)
//			return false;
//	}
//	return true;
//}
//int main()
//{
//	int x, y;
//	while (cin >> x >> y)
//	{
//		if (!x && !y)
//			break;
//		int i;
//		for (i = x; i <= y; i++)
//		{
//			if (!is_prime(i*i + i + 41))
//			{
//				cout << "Sorry" << endl;
//				break;
//			}
//		}
//		if(i>y)
//		cout << "OK" << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int sum = 1;
//		for (int i = 1; i < n; i++)
//		{
//			sum = (sum + 1) * 2;
//		}
//		cout << sum << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int n;
//	int a[101];
//	while (cin >> n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			cin >> a[i];
//		}
//		int min = a[0];
//		int max = a[0];
//		double sum = 0;
//		for (int i = 0; i < n; i++)
//		{
//			sum += a[i];
//			if (a[i] < min)
//				min = a[i];
//			if (a[i] > max)
//				max = a[i];
//		}
//		printf("%.2lf\n", (sum - max - min) / (n-2));
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	char s[100001];
//	int n;
//	cin >> n;
//	while (n--)
//	{
//		cin >> s;
//		int i = 0;
//		int cnt = 0;
//		while (s[i] != '\0')
//		{
//			if (s[i] >= '0'&&s[i] <= '9')
//			{
//				cnt++;
//			}
//			i++;
//		}
//		cout << cnt << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int n, m;
//	int a[101];
//	while (cin >> n >> m)
//	{
//		int flag = 0;
//		for (int i = 0; i < n; i++)
//		{
//			a[i] = 2 * (i + 1);
//		}
//		for (int i = 0; i <= n - m; i+=m)
//		{
//			int sum = 0;
//			for (int j = i; j < i + m; j++)
//			{
//				sum += a[j];
//			}
//			cout << sum / m;
//			if (i < n - m - 1)
//			{
//				cout << " ";
//				flag = 1;
//			}
//		}
//		if (n%m)
//		{
//			if(flag)
//			cout << " ";
//			int sum = 0;
//			int cnt = 0;
//			for (int i = (n / m)*m; i < n; i++)
//			{
//				sum += a[i];
//				cnt++;
//			}
//			cout << sum / cnt;
//		}
//		cout << endl;
//	}
//	return 0;
//}

#include<iostream>
using namespace std;
int main()
{

	return 0;
}