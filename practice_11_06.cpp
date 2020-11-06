//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//typedef struct
//{
//	long long L, R;
//	long long w;
//}space;
//space a[10000000];
//int main()
//{
//	
//	int n;
//	cin >> n;
//	cin >> a[0].L >> a[0].R >> a[0].w;
//	for (int i = 1; i < n; i++)
//	{
//		/*Li = (Li−1 · Ri−1 + wi−1) mod 107 + 1
//		Ri = (Li + wi−1 · wi−1) mod(107 − Li + 1) + Li
//		wi = (Li + Ri) mod 104 + 1*///		
//		a[i].L = (a[i - 1].L*a[i - 1].R + a[i - 1].w) % ((int)1e7) + 1;
//		a[i].R = (a[i].L + a[i - 1].w*a[i - 1].w) % (int)(1e7 - a[i].L + 1) + a[i].L;
//		a[i].w = (a[i].L + a[i].R) % (int)1e4 + 1;
//	}
//	long long L_sum = a[0].L;
//	long long R_sum = a[0].R;
//	long long cnt = 1;
//	long long w_sum = a[0].w;
//	for(int i=1;i<n;i++)
//	{
//		if (a[i].L > L_sum || a[i].R < R_sum)
//			continue;
//		
//	}
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	char c[100];
//	int a[100];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> c[i];
//	}
//	int cnt_c = 0;
//	int cnt_a=0;
//	for (int i = 0; i < n; i++)
//	{
//		if (c[i] == '1')
//			cnt_c++;
//		if (c[i] == '0')
//		{
//			
//			a[cnt_a] = cnt_c;
//			cnt_c = 0;
//			cnt_a++;
//		}
//	}
//	if (!cnt_a)
//	{
//		cout << cnt_c;
//		return 0;
//	}
//	int max = 0;
//	int sum;
//	for (int i = 0; i < cnt_a; i++)
//	{
//		if (a[i + 1])
//			sum = a[i] + a[i + 1] + 1;
//		else
//		{
//			sum = a[i]+ 1;
//		}
//		if (sum > max)
//			max = sum;
//	}
//	cout << max;
//	return 0;
//}

