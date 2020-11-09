#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int a, b, c;
//	double sum1 = 0.0;
//	double sum2 = 0.0;
//	double sum3 = 0.0;
//	scanf("%d%d%d", &a, &b, &c);
//	for (int i = 1; i <= a; i++)
//	{
//		sum1 += i;
//	}
//	for (int i = 1; i <= b; i++)
//	{
//		sum2 += i * i;
//	}
//	for (double i = 1.0; i <= c; i++)
//	{
//		sum3 += 1 / i;
//	}
//	printf("%.2lf", sum1 + sum2 + sum3);
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//void swap(double& a, double& b)
//{
//	double tmp = a;
//	a = b;
//	b = tmp;
//}
//void sort(double& a, double& b, double& c)
//{
//	if (a > b)
//		swap(a, b);
//	if (b > c)
//		swap(b, c);
//	if (a > c)
//		swap(a, c);
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	double a, b, c;
//	while (n--)
//	{
//		scanf("%lf%lf%lf", &a, &b, &c);
//		double s = (a+b+c)/2;
//		sort(a, b, c);
//		if (a + b < c||fabs(a+b-c)<0.001)
//		{
//			printf("no triangle\n");
//		}
//		else
//		{
//			if (a == b)
//			{
//				if (b == c)
//				{
//					printf("equilateral triangle, %.1lf\n", sqrt(s*(s - a)*(s - b)*(s - c)));
//				}
//				else 
//				{
//					if (fabs(a*a + b * b - c * c) < 0.001)
//						printf("isosceles right triangle, %.1lf\n", sqrt(s*(s - a)*(s - b)*(s - c)));
//					else
//					{
//						printf("isosceles triangle, %.1lf\n", sqrt(s*(s - a)*(s - b)*(s - c)));
//					}
//				}
//			}
//			else
//			{
//				if (fabs(a*a + b * b - c * c) < 0.001)
//					printf("right triangle, %.1lf\n", sqrt(s*(s - a)*(s - b)*(s - c)));
//				else
//					printf("general triangle, %.1lf\n", sqrt(s*(s - a)*(s - b)*(s - c)));
//			}
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//
//	int sum = 1;
//	for (int i = 1; i < n; i++)
//	{
//		sum = (sum + 1) * 2;
//	}
//	printf("%d", sum);
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//int is_mirror(int n)
//{
//	if (n < 10)
//		return 1;
//	int a[10];
//	int cnt = 0;
//	while (n)
//	{
//		
//		a[cnt++] = n % 10;
//		n /= 10;
//	}
//	int i;
//	for (i = 0; i < (cnt) / 2; i++)
//	{
//		if (a[i] != a[cnt - 1 - i])
//			return 0;
//	}
//	return 1;
//}
//int is_prime(int n)
//{
//	if (n < 2)
//		return 0;
//	int i;
//	for (i = 2; i <= (int)sqrt(n); i++)
//	{
//		if (n%i == 0)
//			return 0;
//	}
//	return 1;
//}
//int main()
//{
//	int n,a,b;
//	scanf("%d", &n);
//	while (n--)
//	{
//		int flag = 1;
//		scanf("%d%d", &a, &b);
//		int i;
//		for (i = a; i <= b; i++)
//		{
//			if (is_prime(i)&&is_mirror(i))
//			{
//				printf("%d\n", i);
//				flag = 0;
//			}
//		}
//		if (flag)
//		{
//			printf("Not found\n");
//		}
//	}
//	return 0;
//}