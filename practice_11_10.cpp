#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<algorithm>
//using namespace std;
//bool cmp(char a, char b)
//{
//	return a < b;
//}
//int main()
//{
//	char s[10];
//	while (cin >> s)
//	{
//		sort(s, s + 3,cmp);
//		for (int i = 0; i < 3; i++)
//		{
//			cout << s[i];
//			if(i<2)
//			cout << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//int main()
//{
//	double x1, y1, x2, y2;
//	while (cin >> x1 >> y1 >> x2 >> y2)
//	{
//		printf("%.2lf\n", sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)));
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//#define PI 3.1415926
//int main()
//{
//	double r;
//	while (cin >> r)
//	{
//		printf("%.3lf\n", 4 * PI*r*r*r / 3);
//	}
//	return 0;
//}

//#include<iostream>
//#include<cstdlib>
//using namespace std;
//int main()
//{
//	double a;
//	while (cin >> a)
//	{
//		printf("%.2lf\n", abs(a));
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int t;
//	while (cin >> t)
//	{
//		if (t >= 90 && t <= 100)
//			cout << "A" << endl;
//		else if (t >= 80 && t < 90)
//			cout << "B" << endl;
//		else if (t >= 70 && t < 80)
//			cout << "C" << endl;
//		else if (t >= 60 && t < 70)
//			cout << "D" << endl;
//		else if (t >= 0 && t < 60)
//			cout << "E" << endl;
//		else
//			cout << "Score is error!" << endl;
//	}
//	return 0;
//}

#include<iostream>
using namespace std;
int s[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int is_leap(int n)
{
	if (n % 4 == 0 && n % 100 != 0 || n % 400 == 0)
		return 1;
	else
		return 0;
}
int main()
{
	int year, month, day;
	while (scanf("%d/%d/%d", &year, &month, &day))
	{
		int sum = 0;
		for (int i = 0; i < month - 1;i++)
		{
			sum += s[i];
		}
		if (is_leap(year))
		{
			sum++;
		}
		sum += day;
		cout << sum << endl;
	}
	return 0;
}