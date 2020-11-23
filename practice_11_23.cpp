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
//int n,a[100];
//int main()
//{
//    int T;
//    cin>>T;
//    while(T--)
//    {
//        cin>>n;
//        for(int i=0;i<n;i++)
//        {
//            cin>>a[i];
//        }
//        double sum=0.0;
//        for(int i=0;i<n;i++)
//        {
//            sum+=a[i];
//        }
//        double average=sum/n;
//        printf("%.2lf ",average);
//        int sum_b=0;
//        int sum_s=0;
//        int sum_z=0;
//        int sum_f=0;
//        for(int i=0;i<n;i++)
//        {
//            if(a[i]>average)
//                sum_b++;
//            if(a[i]<average)
//                sum_s++;
//            if(a[i]>0)
//                sum_z++;
//            if(a[i]<0)
//                sum_f++;
//        }
//        cout<<sum_b<<" "<<sum_s<<endl<<sum_z<<" "<<sum_f<<endl;
//        int maxn=a[0];
//        int minn=a[0];
//        for(int i=0;i<n;i++)
//        {
//            if(a[i]>maxn)
//                maxn=a[i];
//            if(a[i]<minn)
//                minn=a[i];
//        }
//        cout<<"max="<<maxn<<" "<<"min="<<minn<<endl<<endl;
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//struct iron
//{
//    int l,d,num;
//}g[10010];
//int n,m;
//bool cmp(iron a,iron b)
//{
//    if(a.l==b.l)
//    {
//        if(a.d==b.d)
//        {
//            return a.num>b.num;
//        }
//        return a.d<b.d;
//    }
//    return a.l>b.l;
//}
//int main()
//{
//    cin>>n;
//    while(n--)
//    {
//        cin>>m;
//        for(int i=0;i<m;i++)
//        {
//            cin>>g[i].l>>g[i].d>>g[i].num;
//        }
//        sort(g,g+m,cmp);
//        cout<<g[0].num<<endl;
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int l,n;
//const int maxn=1e6+10;
//struct ant
//{
//    int flag,pos;
//}a[maxn];
//bool check(ant a[])
//{
//    for(int i=1;i<=n;i++)
//    {
//        if(a[i].pos>0&&a[i].pos<l)
//            return false;
//    }
//    return true;
//}
//void change_flag(int& a)
//{
//    a=-a;
//}
//void check_flag(ant a[])
//{
//    for(int i=1;i<=n;i++)
//    {
//        if(i==1)
//        {
//            if(a[i].pos==a[i+1].pos)
//            {
//                change_flag(a[i].flag);
//                change_flag(a[i+1].flag);
//            }
//        }
//        else if(i==n)
//        {
//            if(a[i].pos==a[i-1].pos)
//            {
//                change_flag(a[i-1].flag);
//                change_flag(a[i].flag);
//            }
//        }
//        else
//        {
//            if(a[i].pos==a[i+1].pos)
//            {
//                change_flag(a[i].flag);
//                change_flag(a[i+1].flag);
//            }
//            if(a[i].pos==a[i-1].pos)
//            {
//                change_flag(a[i].flag);
//                change_flag(a[i-1].flag);
//            }
//        }
//    }
//}
//void move_ant(ant a[])
//{
//    for(int i=1;i<=n;i++)
//    {
//        a[i].pos+=a[i].flag;
//    }
//}
//int main()
//{
//    while(cin>>l>>n)
//    {
//        for(int i=1;i<=n;i++)
//        {
//            cin>>a[i].pos;
//        }
//        for(int i=1;i<=n;i++)
//        {
//            if(a[i].pos<=l/2)
//                a[i].flag=1;
//            else
//                a[i].flag=-1;
//        }
//        int maxn1=0;
//        for(int i=1;i<=n;i++)
//        {
//            if(a[i].pos<=l/2)
//            {
//                if(maxn1<a[i].pos)
//                    maxn1=a[i].pos;
//            }
//            else
//            {
//                if(maxn1<(l-a[i].pos))
//                    maxn1=l-a[i].pos;
//            }
//        }
//        cout<<maxn1<<" ";
//        int ans=0;
//        while(1)
//        {
//            if(check(a))
//                break;
//            ans++;
//            check_flag(a);
//            move_ant(a);
//        }
//        cout<<ans<<endl;
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=1e6+10;
//int l,n,a[maxn];
//int main()
//{
//    while(cin>>l>>n)
//    {
//        for(int i=1;i<=n;i++)
//        {
//            cin>>a[i];
//        }
//        int mint=a[1];
//        for(int i=1;i<=n;i++)
//        {
//            mint=max(mint,min(a[i],l-a[i]));
//        }
//        sort(a+1,a+n+1);
//        int maxt=max((l-a[1]),a[n]);
//        cout<<mint<<" "<<maxt<<endl;
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=1e5+10;
//int m,l,r,now_r,now_l;
//struct point
//{
//    int l,r;
//}p[maxn],a[maxn];
//bool cmp(point a,point b)
//{
//    if(a.r==b.r)
//    {
//        return a.l<b.l;
//    }
//    return a.r<b.r;
//}
//bool cmp_left(point a,point b)
//{
//    return a.l<b.l;
//}
//int main()
//{
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        cin>>m;
//        int cnt=0;
//        while(cin>>l>>r)
//        {
//            if(!l&&!r)
//                break;
//            if(r<=0||l>=m)
//                continue;
//            p[cnt].l=l;
//            p[cnt].r=r;
//        }
//        sort(p,p+cnt,cmp);
//        int ans=0;
//        a[ans].l=p[0].l;
//        a[ans].r=p[0].r;
//        now_r=p[0].r;
//        now_l=p[0].l;
//        for(int i=1;i<cnt;i++)
//        {
//            if(p[i].r>now_r)
//            {
//                if(p[i].l<=now_r)
//                {
//                    if(p[i].l<now_l||(p[i].l<=0&&p[i].l>=now_l))
//                    {
//                        a[ans].l=p[i].l;
//                        a[ans].r=p[i].r;
//                        now_r=p[i].r;
//                        now_l=p[i].l;
//                    }
//                    else
//                    {
//                        ans++;
//                        now_l=p[i].l;
//                        now_r=p[i].r;
//                        a[ans].l=p[i].l;
//                        a[ans].r=p[i].r;
//                    }
//                }
//            }
//            if(now_r>=m)
//                break;
//        }
//        if(now_r<m)
//        {
//            cout<<0<<endl<<endl;
//            continue;
//        }
//        int flag=0;
//        for(int i=0;i<=ans;i++)
//        {
//            if(a[i].l<=0)
//            {
//                flag=1;
//                break;
//            }
//        }
//        if(!flag)
//        {
//            cout<<0<<endl;
//        }
//        else
//        {
//            cout<<ans+1<<endl;
//            sort(a,a+ans+1,cmp_left);
//            for(int i=0;i<=ans;i++)
//            {
//                cout<<a[i].l<<" "<<a[i].r<<endl;
//            }
//        }
//        if(t)
//        cout<<endl;
//    }
//    return 0;
//}






















