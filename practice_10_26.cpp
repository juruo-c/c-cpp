//#include<bits/stdc++.h>
//using namespace std;
//int count(int n)
//{
//	int cnt=0;
//	if(n==0)
//	{
//		return 1;
//	}
//	if(n<0)
//	cnt++;
//	while(n)
//	{
//		n/=10;
//		cnt++;
//	}
//	
//	return cnt;
//}
//int main()
//{
//	int i;
//	cin>>i;
//	int n1,n2;
//	char law;
//	while(i--)
//	{
//		if(!(cin>>n1))
//		{
//			cin.clear();
//			cin>>law>>n1;
//		}
//		cin>>n2;
//		switch(law)
//		{
//			case 'a':
//				cout<<n1<<"+"<<n2<<"="<<n1+n2<<endl<<count(n1)+count(n2)+count(n1+n2)+2<<endl;
//				break;
//			case 'b':
//				cout<<n1<<"-"<<n2<<"="<<n1-n2<<endl<<count(n1)+count(n2)+count(n1-n2)+2<<endl;
//				break;
//			case 'c':
//				cout<<n1<<"*"<<n2<<"="<<n1*n2<<endl<<count(n1)+count(n2)+count(n1*n2)+2<<endl;
//				break; 
//		}
//	}
//	return 0;
//}

#include<bits/stdc++.h>
using namespace std;
void print(char init[])
{
	cout<<init<<endl;
}
void cut(char init[],int a,int b)
{
	for(int i=0;i<b;i++)
	{
		init[i]=init[a+i];
	}
	init[b]='\0';
}
void insert(char init[],int a,char str[],int len)
{
	char* p=&init[a];
	int i=a+len;
	while(*p)
	{
		init[i]=*p;
		p++;
		i++;
	}
	init[i]='\0';
	for(i=a;i<a+len;i++)
	{
		init[i]=str[i-a];
	}
}

int main()
{
	int q;
	cin>>q;
	char init[101];
	cin>>init;
	int num;
	char tail[101];
	char dest[101];
	char str[101];
	int a,b;
	while(q--)
	{
		cin>>num;
		switch(num)
		{
			case 1:
				{
					cin>>tail;
					strcat(init,tail);
					print(init);
					break;
				} 
			case 2:
				{
					cin>>a>>b;
					cut(init,a,b);
					print(init); 
					break;
				} 
			case 3:
				{
					cin>>a>>str;
					int len=strlen(str);
					insert(init,a,str,len);
					print(init);
					break;
				} 
			case 4:
				cin>>dest;
				char* ptr=strstr(init,dest);
				if(!ptr)
				cout<<-1<<endl;
				else
				cout<<(int)(ptr-init)<<endl;
				break;
		}
	}
	return 0;
}
