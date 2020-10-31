#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	float a, b, c;
//	scanf("%f%f%f", &a, &b, &c);
//	printf("%.3f", (a + b + c) / 3);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	double f;
//	scanf("%lf", &f);
//	printf("%.3f", 5 * (f - 32) / 9);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("%d", n*(n + 1) / 2);
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//#define PI 3.1415926
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("%f %f", sin(n*PI/180), cos(n*PI/180));
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	double price = 95.0;
//	if (price*n >= 300)
//		printf("%.2f", price*n*0.85);
//	else
//		printf("%.2f", price*n);
//	return 0;
//}

//#include<stdio.h>
//void swap(int &x, int &y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//void sort(int &a,int &b,int &c)
//{
//	if (a > b)
//		swap(a, b);
//	if (a > c)
//		swap(a, c);
//	if (b > c)
//		swap(b, c);
//
//}
//int main()
//{
//	int a, b, c;
//	scanf("%d%d%d", &a, &b, &c);
//	sort(a, b, c);
//	if (a + b <= c)
//		printf("not a triangle");
//	else
//	{
//		if ((a*a + b * b) == c * c)
//			printf("yes");
//		else
//			printf("no");
//	}
//}

//#include<stdio.h>
//int main()
//{
//	int year;
//	scanf("%d", &year);
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//		printf("yes");
//	else
//		printf("no");
//}


//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int n;
//	for(int i=1;i<=9;i++)
//		for (int j = 0; j <= 9; j++)
//		{
//			n = i * 1100 + j * 11;
//			if (sqrt(n) - (int)sqrt(n) == 0)
//				printf("%d ", n);
//		}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	if (n > 25)
//		n = 25;
//	int sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		int func = 1;
//		for (int j = 1; j <= i; j++)
//		{
//			func *= j;
//		}
//		sum += func%1000000;
//	}
//	printf("%d", sum);
//	return 0;
//}

//#include<stdio.h>
//int is_daffodil(int n)
//{
//	int m = n;
//	int a = n / 100;
//	n %= 100;
//	int b = n / 10;
//	n %= 10;
//	int c = n;
//	if (a*a*a + b * b*b + c * c*c == m)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int i;
//	for (i = 100; i <= 999; i++)
//	{
//		if (is_daffodil(i))
//			printf("%d ", i);
//	}
//	return 0;
//}

