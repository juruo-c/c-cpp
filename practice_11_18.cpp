//#include<bits/stdc++.h>
//using namespace std;
//char a[110];
//int main()
//{
//    while(gets(a))
//    {
//        int i=0;
//        int flag = 1;
//        while(a[i]!='\0')
//        {
//
//            if(a[i]==' ')
//            {
//
//                flag=1;
//            }
//            else
//            {
//                if(flag)
//                {
//                    a[i]-=32;
//                }
//                flag=0;
//            }
//            i++;
//        }
//        for(int i=0;a[i]!='\0';i++)
//        {
//            cout<<a[i];
//        }
//        cout<<endl;
//    }
//    return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//int n,m,a[10000010];
//int main()
//{
//    cin>>n>>m;
//    for(int i=0;i<m;i++)
//    {
//        cin>>a[i];
//    }
//    sort(a,a+m);
//    for(int i=0;i<m;i++)
//    {
//        cout<<a[i];
//        if(i<m-1)
//            cout<<" ";
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int n,a[100001];
//void qsort(int l,int r)
//{
//    int mid=a[(l+r)/2];
//    int i=l;
//    int j=r;
//    do
//    {
//        while(a[i]<mid)
//            i++;
//        while(a[j]>mid)
//            j--;
//        if(i<=j)
//        {
//            swap(a[i],a[j]);
//            i++;
//            j--;
//        }
//    }while(i<=j);
//    if(l<j)
//        qsort(l,j);
//    if(i<r)
//        qsort(i,r);
//}
//int main()
//{
//    cin>>n;
//    for(int i=1;i<=n;i++)
//    {
//        cin>>a[i];
//    }
//    qsort(1,n);
//    for(int i=1;i<=n;i++)
//    {
//        cout<<a[i]<<" ";
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//#define maxn 10000010
//int n,k,a[maxn];
//void Merge(int a[],int l,int mid,int r)
//{
//    int n1=mid-l+1;
//    int n2=r-mid;
//    int a1[maxn/2];
//    int a2[maxn/2];
//    for(int i=1;i<=n1;i++)
//        a1[i]=a[l+i-1];
//    for(int j=1;j<=n2;j++)
//        a2[j]=a[mid+j];
//    int i=1;
//    int j=1;
//    int k;
//    for(k=l;k<=r;k++)
//    {
//        if(a1[i]<=a2[i])
//        {
//            a[k]=a1[i];
//            i++;
//        }
//        else
//        {
//            a[k]=a2[j];
//            j++;
//        }
//        if(i==n1||j==n2)
//            break;
//    }
//    if(i==n1)
//    {
//        for(int m=k;m<=r;m++)
//        {
//            a[m]=a2[j];
//            j++;
//        }
//    }
//    else
//    {
//        for(int m=k;m<=r;m++)
//        {
//            a[m]=a1[i];
//            i++;
//        }
//    }
//}
//void merge_sort(int a[],int l,int r)
//{
//    if(l<r)
//    {
//        int mid=(l+r)/2;
//        merge_sort(a,l,mid);
//        merge_sort(a,mid+1,r);
//        Merge(a,l,mid,r);
//    }
//    else return;
//
//}
//int main()
//{
//    cin>>n>>k;
//    for(int i=1;i<=n;i++)
//    {
//        cin>>a[i];
//    }
//    merge_sort(a,1,n);
//    cout<<a[k+1];
//    return 0;
//}

//#include<stdio.h>
//int main()
//{
//    int n;
//    scanf("%d",&n);
//    int a[10];
//    while(n--)
//    {
//        int cnt=0;
//        for(int i=0;i<10;i++)
//        {
//            scanf("%d",&a[i]);
//        }
//        for(int i=0;i<10;i++)
//        {
//            if(a[i]<0)
//            {
//                cnt++;
//            }
//        }
//        printf("%d\n",cnt);
//    }
//    return 0;
//}

//#include<stdio.h>
//int main()
//{
//    int a[20];
//    for(int i=0;i<20;i++)
//    {
//        scanf("%d",&a[i]);
//    }
//    for(int i=0;i<20;i++)
//    {
//        int flag=0;
//        for(int j=0;j<20;j++)
//        {
//            if(j==i)
//                continue;
//            if(a[i]%a[j]==0)
//            {
//                flag=1;
//                break;
//            }
//        }
//        if(flag)
//            printf("%d\n",a[i]);
//    }
//    return 0;
//}


//#include<stdio.h>
//int main()
//{
//    int a[6];
//    int b[8];
//    for(int i=0;i<6;i++)
//    {
//        scanf("%d",&a[i]);
//    }
//    for(int i=0;i<8;i++)
//    {
//        scanf("%d",&b[i]);
//    }
//    for(int i=0;i<6;i++)
//    {
//        for(int j=0;j<8;j++)
//        {
//            if(a[i]==b[j])
//                printf("%d\n",a[i]);
//        }
//
//    }
//    return 0;
//}


//#include<stdio.h>
//int main()
//{
//    int a[10],n,k;
//    scanf("%d",&n);
//    while(n--)
//    {
//        for(int i=0;i<10;i++)
//        {
//            scanf("%d",&a[i]);
//        }
//        scanf("%d",&k);
//        int cur;
//        int flag=0;
//        for(int i=0;i<10;i++)
//        {
//            if(a[i]==k)
//            {
//                cur=i;
//                flag=1;
//                break;
//            }
//        }
//        if(flag)
//        {
//            int cnt=0;
//            for(int i=0;i<10;i++)
//            {
//                if(i==cur)
//                    continue;
//                printf("%d",a[i]);
//                cnt++;
//                if(cnt<9)
//                    printf(" ");
//            }
//            printf("\n");
//        }
//        else
//            printf("Not found\n");
//    }
//    return 0;
//}

//#include<stdio.h>
//int s[12]={31,28,31,30,31,30,31,31,30,31,30,31};
//int main()
//{
//    int n,y,m,d;
//    scanf("%d",&n);
//    while(n--)
//    {
//        int ans=0;
//        scanf("%d/%d/%d",&y,&m,&d);
//        for(int i=0;i<m-1;i++)
//        {
//            ans+=s[i];
//        }
//        if((y%4==0&&y%100!=0||y%400==0)&&m>2)
//            ans++;
//        printf("%d\n",ans+d);
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//    int a,s[5];
//    scanf("%d",&a);
//    int flag1=0;
//    int flag2=0;
//    if(a%2==0)
//        flag1=1;
//    if(a>4&&a<=12)
//        flag2=1;
//    if(flag1&&flag2)
//        s[1]=1;
//    else
//        s[1]=0;
//    if(flag1||flag2)
//        s[2]=1;
//    else
//        s[2]=0;
//    if((flag1&&!flag2)||(!flag1&&flag2))
//        s[3]=1;
//    else
//        s[3]=0;
//    if(!flag1&&!flag2)
//        s[4]=1;
//    else
//        s[4]=0;
//    for(int i=1;i<=4;i++)
//    {
//        cout<<s[i]<<" ";
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//    int a[3];
//    char s[3];
//    for(int i=0;i<3;i++)
//        cin>>a[i];
//    cin>>s;
//    sort(a,a+3);
//    for(int i=0;i<3;i++)
//    {
//        cout<<a[s[i]-'A'];
//        if(i<2)
//            cout<<" ";
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//void collatz(int n)
//{
//    if(n==1)
//    {
//        return;
//    }
//    if(n%2)
//    {
//        cout<<3*n+1<<endl;
//        collatz(3*n+1);
//    }
//    else
//    {
//        cout<<n/2<<endl;
//        collatz(n/2);
//    }
//}
//int main()
//{
//    int n;
//    cin>>n;
//    collatz(n);
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//bool is_prime(int n)
//{
//    if(n<2){
//        return false;
//    }
//    for(int i=2;i<=(int)sqrt(n);i++)
//    {
//        if(n%i==0)
//            return false;
//    }
//    return true;
//}
//int main()
//{
//    int L;
//    cin>>L;
//    if(L<2)
//        cout<<0<<endl;
//    else
//    {
//        int sum=0;
//    int cnt=0;
//    int i;
//    for( i=2;i<1200;i++)
//    {
//        if(is_prime(i))
//        {
//            if(sum+i>L)
//            break;
//            cout<<i<<endl;
//            cnt++;
//            sum+=i;
//        }
//
//    }
//    cout<<cnt<<endl;
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//bool is_prime(int n)
//{
//    if(n==2||n==3)
//        return true;
//    if(n%6!=1&&n%6!=5)
//        return false;
//    int tmp = (int)sqrt(n);
//    for(int i=5;i<=tmp;i+=6)
//    {
//        if(n%i==0||n%(i+2)==0)
//        {
//            return false;
//        }
//    }
//    return true;
//}
//bool is_mirror(int num)
//{
//    if(num<10)
//        return true;
//    int tmp=num;
//    int c=0;
//    while(num)
//    {
//        c=c*10+num%10;
//        num/=10;
//    }
//    if(c==tmp)
//        return true;
//    else
//        return false;
//}
//int main()
//{
//    int a,b;
//    cin>>a>>b;
//    for(int i=a;i<=b;i++)
//    {
//        if(is_prime(i)&&is_mirror(i))
//        {
//            cout<<i<<endl;
//        }
//    }
//    return 0;
//}
