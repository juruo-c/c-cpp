#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	printf("####\n");
//	printf(" ####\n");
//	printf("  ####\n");
//	printf("   ####\n");
//	return 0;
//}

#include<stdio.h>
int main()
{
	int n,num,a[1000];
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &num);
		int i;
		int cnt = 0;
		for (i = 1; i < num; i++)
		{
			if (num%i == 0)
			{
				a[cnt] = i;
				cnt++;
			}
		}
		int sum = 0;
		for (i = 0; i < cnt; i++)
		{
			sum += a[i];
		}
		if (sum == num)
			printf("yes,");
		else
			printf("no,");
		for (i = 0; i < cnt; i++)
		{
			printf("%d", a[i]);
			if (i < cnt - 1)
				printf(",");
		}
		printf("\n");
	}
	return 0;
}

//#include<stdio.h>
//int is_num(int n)
//{	
//	int a = n / 100;
//	int b = n % 100 / 10;
//	int c = n % 10;
//	if (a*a*a + b * b*b + c * c*c == n)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int a, b;
//	scanf("%d%d", &a, &b);
//	int i;
//	for (i = a; i <= b; i++)
//	{
//		if (is_num(i))
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}

#include<stdio.h>

int main()
{
	double M, N;
	scanf("%lf%lf", &M, &N);
	double s = M;
	int i = 0;
	for (i = 1; i < N; i++)
	{
		M = (int)(((M/2) * 1000 + 5) / 10) / 100.0;
		s += (int)((2*M * 1000 + 5) / 10) / 100.0;
	}
	printf("%.2lf\n%.2lf", s, (int)(((M/2) * 1000 + 5) / 10) / 100.0);
	return 0;
}