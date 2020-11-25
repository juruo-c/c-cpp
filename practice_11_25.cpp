//#include<bits/stdc++.h>
//using namespace std;
//long long n,t[5010],ans;
//double a[5010];
//bool vis[2000010];
//int main()
//{
//    cin>>n;
//    for(int i=0;i<n;i++)
//    {
//        cin>>a[i]>>t[i];
//    }
//    for(int i=0;i<n;i++)
//    {
//        long long cnt=1;
//        long long j=(long long)(cnt*a[i]);
//        while(j<=(long long)t[i]*a[i])
//        {
//
//            if(vis[j])
//                vis[j]=0;
//            else
//                vis[j]=1;
//            cnt++;
//            j=(long long)(cnt*a[i]);
//        }
//    }
//    for(long long i=0;i<2000010;i++)
//    {
//        if(vis[i])
//            cout<<i<<endl;
//    }
//    return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//int board[110][110];
//int main()
//{
//    int n;
//    cin>>n;
//    int row=1;
//    int col=0;
//    int i=1;
//    while(i<=n*n)
//    {
//        while(col<n&&!board[row][col+1])board[row][++col]=i++;
//        while(row<n&&!board[row+1][col])board[++row][col]=i++;
//        while(col>1&&!board[row][col-1])board[row][--col]=i++;
//        while(row>1&&!board[row-1][col])board[--row][col]=i++;
//    }
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=n;j++)
//        {
//            printf("%3d",board[i][j]);
//        }
//        cout<<endl;
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//void change(char a[15][15],int i,char ans[15][15])
//{
//    if(i==4)
//    switch(i)
//    {
//
//    }
//}
//int main()
//{
//    int n;
//    cin>>n;
//    char a[15][15],ans[15][15],b[15][15];
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<n;j++)
//            cin>>a[i][j];
//    }
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<n;j++)
//            cin>>b[i][j];
//    }
//    for(int i=1;i<=6;i++)
//    {
//        change(a,i,ans);
//        if(check(ans,b))
//        {
//            cout<<i<<endl;
//            break;
//        }
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//    int t,n,a[15][15];
//    cin>>t;
//    while(t--)
//    {
//        cin>>n;
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<n;j++)
//            {
//                cin>>a[i][j];
//            }
//        }
//        for(int i=0;i<n;i++)
//        {
//            int maxn=a[0][i];
//            int sum=0;
//            for(int j=0;j<n;j++)
//            {
//                maxn=max(maxn,a[j][i]);
//                sum+=a[j][i];
//            }
//            cout<<maxn<<" "<<sum<<endl;
//        }
//    }
//    return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//int a[10];
//int main()
//{
//    for(int i=0;i<9;i++)
//    {
//        cin>>a[i];
//    }
//    int k;
//    cin>>k;
//    if(k<a[0])
//    {
//        cout<<k<<endl;
//        for(int i=0;i<9;i++)
//            cout<<a[i]<<endl;
//        return 0;
//    }
//    if(k>a[8])
//    {
//        for(int i=0;i<9;i++)
//            cout<<a[i]<<endl;
//        cout<<k<<endl;
//        return 0;
//    }
//    for(int i=0;i<9;i++)
//    {
//        if(a[i]<=k&&a[i+1]>=k)
//            cout<<a[i]<<endl<<k<<endl;
//        else
//            cout<<a[i]<<endl;
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//    int T,n,a[25];
//    cin>>T;
//    while(T--)
//    {
//        cin>>n;
//        for(int i=0;i<n;i++)
//        {
//            cin>>a[i];
//        }
//        for(int i=0;i<n-1;i++)
//        {
//            int minn=a[i+1];
//            int k=i+1;
//            for(int j=i+1;j<n;j++)
//            {
//                if(minn>a[j])
//                {
//                    minn=a[j];
//                    k=j;
//                }
//            }
//            if(minn<a[i])
//            {
//                int tmp=a[k];
//                a[k]=a[i];
//                a[i]=tmp;
//            }
//            for(int i=0;i<n;i++)
//            {
//                cout<<a[i];
//                if(i<n-1)
//                    cout<<" ";
//            }
//            cout<<endl;
//        }
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//    int t,n,a[110];
//    cin>>t;
//    while(t--)
//    {
//        cin>>n;
//        for(int i=0;i<n;i++)
//        {
//            cin>>a[i];
//        }
//        int l=0;
//        int r=n-1;
//        while(l<r)
//        {
//            while(a[l]%2==0)
//            {
//                l++;
//            }
//            while(a[r]%2)
//            {
//                r--;
//            }
//            if(l>=r)
//                break;
//            int tmp=a[l];
//            a[l]=a[r];
//            a[r]=tmp;
//            r--;
//            l++;
//        }
//        cout<<n<<" ";
//        for(int i=0;i<n;i++)
//        {
//            cout<<a[i];
//            if(i<n-1)
//            {
//                cout<<" ";
//            }
//        }
//        cout<<endl;
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int T,N,M;
//struct student
//{
//    char name[25];
//    double goal;
//}s[110];
//void average(student s[])
//{
//    double sum=0.0;
//    for(int i=0;i<N;i++)
//    {
//        sum+=s[i].goal;
//    }
//    printf("%.1lf\n",sum/N);
//}
//void s_max(student s[])
//{
//    double maxn=s[0].goal;
//    for(int i=1;i<N;i++)
//    {
//        if(s[i].goal>maxn)
//            maxn=s[i].goal;
//    }
//    cout<<maxn<<endl;
//}
//void s_min(student s[])
//{
//    double minn=s[0].goal;
//    for(int i=1;i<N;i++)
//    {
//        if(s[i].goal<minn)
//            minn=s[i].goal;
//    }
//    cout<<minn<<endl;
//}
//int main()
//{
//    char operation[100];
//    cin>>T;
//    while(T--)
//    {
//        cin>>N>>M;
//        for(int i=0;i<N;i++)
//        {
//            cin>>s[i].name>>s[i].goal;
//        }
//        getchar();
//        while(M--)
//        {
//
//            gets(operation);
//            int k=3;
//            for(int i=0;i<3;i++)
//            {
//                if(strcmp(operation,"QUERY_AVERAGE")==0)
//                {
//                    k=0;
//                }
//                if(strcmp(operation,"QUERY_MAX")==0)
//                {
//                    k=1;
//                }
//                if(strcmp(operation,"QUERY_MIN")==0)
//                {
//                    k=2;
//                }
//
//            }
//            if(k<3)
//            {
//                switch(k)
//                {
//                case 0:
//                    average(s);
//                    break;
//                case 1:
//                    s_max(s);
//                    break;
//                case 2:
//                    s_min(s);
//                    break;
//                }
//            }
//            else
//            {
//                int i=0;
//                while(operation[i]!=' ')
//                {
//                    i++;
//                }
//                i++;
//                int index=0;
//                while(operation[i]!=' ')
//                {
//                    index=index*10+operation[i]-'0';
//                    i++;
//                }
//                i++;
//                int change_num=0;
//                while(operation[i]!='\0')
//                {
//                    change_num=change_num*10+operation[i]-'0';
//                    i++;
//                }
//                s[index-1].goal=change_num;
//            }
//        }
//        cout<<endl;
//    }
//    return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//bool cmp(int a,int b)
//{
//    return a>b;
//}
//int circle(int num)
//{
//    int ans=0;
//    int arr[4];
//    while(1)
//    {
//        ans++;
//        int cnt=0;
//        int tmp=num;
//        while(num)
//        {
//            arr[cnt++]=num%10;
//            num/=10;
//        }
//        sort(arr,arr+4,cmp);
//        int a=0;
//        for(int i=0;i<4;i++)
//        {
//            a=a*10+arr[i];
//        }
//        cout<<a<<" ";
//        sort(arr,arr+4);
//        int b=0;
//        for(int i=0;i<4;i++)
//        {
//            b=b*10+arr[i];
//        }
//        cout<<b<<endl;
//        num=a-b;
//        if(num==tmp)
//            break;
//    }
//    return ans;
//}
//int main()
//{
//    int n;
//    cin>>n;
//    int num;
//    while(n--)
//    {
//        cin>>num;
//        cout<<circle(num);
//        if(n)
//            cout<<endl;
//    }
//
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//    int t;
//    cin>>t;
//    char s[110];
//    while(t--)
//    {
//        cin>>s;
//        int len=strlen(s);
//        int str=0,cur=0,cnt1=0,cnt2=0;
//        double sum=0;
//        while(cur<len)
//        {
//            if(s[str]==s[cur])
//            {
//                cnt1++;
//                cur++;
//            }
//            else
//            {
//                sum+=cnt1;
//                cnt1=0;
//                cnt2++;
//                for(int j=str;j<cur;j++)
//                {
//                    cout<<s[j];
//                }
//                cout<<" ";
//                str=cur;
//            }
//        }
//        printf("%.2lf\n",sum/cnt2);
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//char a[110],b[5];
//string c[10];
//int flag=1;
//bool whole_zero(char b[])
//{
//    for(int i=0;i<4;i++)
//    {
//        if(b[i])
//            return false;
//    }
//    return true;
//}
//int main()
//{
//    int n;
//    cin>>n;
//    while(n--)
//    {
//        cin>>a;
//        int i=0;
//        while(a[i]!='\n')
//        {
//            int cnt1=0;
//            int cnt2=0;
//            while(a[i]!=':')
//            {
//                b[cnt1++]=a[i];
//                i++;
//            }
//            strcpy(c[cnt2++],b);
//            i++;
//        }
//    }
//    return 0;
//}


