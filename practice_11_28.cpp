//#include<bits/stdc++.h>
//using namespace std;
//int S,N,M;
//int main()
//{
//    while(cin>>S>>N>>M&&S&&N&&M)
//    {
//        int flag=1;
//        if(S%2)
//        {
//            cout<<"NO"<<endl;
//            continue;
//        }
//        int ans=1;
//        int k=S/2;
//        while(k)
//        {
//            ans++;
//            k-=min(N,M);
//            if(k<0)
//            {
//                cout<<"NO"<<endl;
//                flag=0;
//                break;
//            }
//        }
//        if(flag)
//        cout<<ans<<endl;
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=100+5;
//int a[5];
//bool h[maxn][maxn];
//struct node
//{
//    int v[3],step;
//};
//void bfs()
//{
//    node cur,next;
//    cur.v[0]=a[0];
//    cur.v[1]=cur.v[2]=0;
//    cur.step=0;
//    queue<node>q;
//    h[0][0]=1;
//    q.push(cur);
//    while(!q.empty())
//    {
//        cur=q.front();
//        q.pop();
//        if((cur.v[0]==a[0]/2&&cur.v[1]==a[0]/2)||(cur.v[1]==a[0]/2&&cur.v[2]==a[0]/2)||(cur.v[2]==a[0]/2&&cur.v[0]==a[0]/2))
//        {
//            cout<<cur.step<<endl;
//            return;
//        }
//        for(int i=0;i<3;i++)
//        {
//            int j;
//            if(cur.v[i]>0)
//            {
//
//                for(j=0;j<3;j++)
//                {
//                    next=cur;
//                    if(i==j)
//                        continue;
//                    if(next.v[i]+next.v[j]>a[j])
//                    {
//                        next.v[i]-=a[j]-next.v[j];
//                        next.v[j]=a[j];
//                    }
//                }
//            }
//            else
//            {
//                next.v[j]+=next.v[i];
//                next.v[i]=0;
//            }
//        }
//        if(!h[next.v[1]][next.v[2]])
//        {
//            h[next.v[1]][next.v[2]]=1;
//            next.step++;
//            q.push(next);
//        }
//    }
//    cout<<"NO"<<endl;
//}
//int main()
//{
//    while(cin>>a[0]>>a[1]>>a[2]&&a[0]&&a[1]&&a[2])
//    {
//        if(a[0]%2)
//        {
//            cout<<"NO"<<endl;
//            continue;
//        }
//        if(a[1]==a[2])
//        {
//            cout<<1<<endl;
//            continue;
//        }
//        bfs();
//    }
//    return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=1e63+5;
//int a_t[2][2],ans[2][2],f_end[1][1];
//int n;
//void matri(int n)
//{
//    for(int m=0;m<n-3;m++)
//    for(int i=0;i<2;i++)
//    {
//        for(int j=0;j<2;j++)
//        {
//            for(int k=0;k<2;k++)
//            {
//                ans[i][j]+=a[j][k]*a_t[j][k];
//            }
//        }
//    }
//}
//int main()
//{
//    cin>>n;
//    int a[2][2]={0,1,1,1};
//    for(int i=0;i<2;i++)
//    {
//        for(int j=0;j<2;j++)
//        {
//
//            a_t[j][i]=a[i][j];
//        }
//    }
//
//    int f[1][2]={1,1};
//    matri(n);
//
//    cout<<f[0][1]<<endl;
//    return 0;
//}


#include<bits/stdc++.h>
using namespace std;
int n,maxx,sum,k;
int main()
{
    int n;
    cin>>n>>maxx;
    sum=maxx;
    while(--n)
    {
        cin>>k;
        sum=sum>0?sum:0;
        sum+=k;
        maxx=max(sum,maxx);
    }
    cout<<maxx<<endl;
    return 0;
}


