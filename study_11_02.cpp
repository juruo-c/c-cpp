#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	long long n, m,count=0;
//	while (scanf("%lld%lld", &n, &m) && n&&m)
//	{
//		count++;
//		double sum = 0.0;
//		for (long long i = n; i <= m; i++)
//		{
//			sum += 1/ (double)(i * i);
//		}
//		printf("Case %lld: %.5lf\n",count, sum);
//	}
//	return 0;
//}

//#include<iostream>
//#include<cstdio>
//using namespace std;
//int main()
//{
//	int c;
//	int a, b;
//	int count = 0;
//	while (cin >> a >> b >> c)
//	{
//		count++;
//		if (!a&&!b&&!c)
//			return 0;
//		else
//		printf("Case %d: %.*lf\n", count, c, (double)a / b);
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//void Judge(int arr[], int num)
//{
//	int a = num / 100;
//	int b = num % 100/10;
//	int c = num % 10;
//	arr[a]++;
//	arr[b]++;
//	arr[c]++;
//}
//int main()
//{
//	for (int i = 100; i <= 333; i++)
//	{
//		int a[10] = { 0 };
//		int abc = i * 1, def = i * 2, ghi = i * 3;
//		int j;
//		Judge(a, abc);
//		Judge(a, def);
//		Judge(a, ghi);
//		for (j = 1; j < 10; j++)
//		{
//			if (a[j] != 1 || a[0] != 0)
//				break;
//		}
//		if (j == 10)
//			cout << abc << " " << def << " " << ghi << endl;
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	double i;
//	for (i = 0; i != 10; i += 0.1)
//		printf("%.1f\n", i);
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#define MAXN 20
//int a[MAXN][MAXN];
//int main()
//{
//	int n, x, y, tot = 0;
//	scanf("%d", &n);
//	memset(a, 0, sizeof(a));
//	tot = a[x = 0][y = n - 1] = 1;
//	while (tot < n*n)
//	{
//		while (x + 1 < n && !a[x + 1][y])
//			a[++x][y] = ++tot;
//		while (y - 1 >= 0 && !a[x][y - 1])
//			a[x][--y] = ++tot;
//		while (x - 1 >= 0 && !a[x - 1][y])
//			a[--x][y] = ++tot;
//		while (y + 1 < n && !a[x][y + 1])
//			a[x][++y] = ++tot;
//	}
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		int j;
//		for (j = 0; j < n; j++)
//		{
//			printf("%3d", a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int count = 0;
//	char s[20], buf[99];
//	scanf("%s", s);
//	for (int abc = 111; abc <= 999; abc++)
//	{
//		for (int de = 11; de <= 99; de++)
//		{
//			int x = abc * (de % 10), y = abc * (de / 10), z = abc * de;
//			sprintf(buf, "%d%d%d%d%d", abc, de, x, y, z);
//			int ok = 1;
//			for (int i = 0; i < strlen(buf); i++)
//			{
//				if (strchr(s, buf[i]) == NULL)
//					ok = 0;
//			}
//			if (ok)
//			{
//				printf("<%d>\n", ++count);
//				printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n", abc, de, x, y, z);
//
//			}
//		}
//	}
//	printf("The number of solutions = %d\n", count);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int c, q = 1;
//	while ((c = getchar()) != EOF)
//	{
//		if (c == '"')
//		{
//			printf("%s", q ? "''" : "\"");
//			q = !q;
//		}
//		else
//			printf("%c", c);
//	}
//	return 0;
//}

//#include<stdio.h>
//char s[] = "`1234567890-=QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./";
//int main()
//{
//	int i, c;
//	while ((c = getchar()) != EOF)
//	{
//		for (i = 1; s[i] && s[i] != c; i++);
//		if (s[i])
//			putchar(s[i - 1]);
//		else
//			putchar(c);
//	}
//	return 0;
//}

#include<stdio.h>
#include<string.h>
#include<ctype.h>
const char* rev = "A   3  HIL JM O   2TUVWX51SE Z  8 ";
const char* msg[] = { "not a palindrome","a regular palindrome","a mirrored string","a mirrored palindrome" };
char r(char c)
{
	if (isalpha(c))
		return rev[c - 'A'];
	else
		return rev[c - '0' + 25];
}
int main()
{
	char s[30];
	while (scanf("%s", s) == 1)
	{
		int len = strlen(s);
		int p = 1, m = 1;
		int i;
		for (i = 0; i < (len+1)/2; i++)
		{
			if (s[i] != s[len - 1 - i])
				p = 0;
			if (r(s[i]) != s[len - 1 - i])
				m = 0;
		}
		printf("%s -- is %s.\n\n", s, msg[m * 2 + p]);
	}
	return 0;
}