//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=1e5+10;
//int n,k;
//bool vis[maxn];
//struct node
//{
//    int x,st;
//};
//void bfs()
//{
//    memset(vis,0,sizeof(vis));
//    queue<node> q;
//    node cur,next;
//    cur.x=n,cur.st=0;
//    q.push(cur);
//    while(!q.empty())
//    {
//        cur=q.front();
//        q.pop();
//        if(cur.x==k)
//        {
//            cout<<cur.st<<endl;
//            return ;
//        }
//        for(int i=1;i<=3;i++)
//        {
//            if(i==1)
//            {
//                next.x=cur.x+1;
//            }
//            if(i==2)
//            {
//                next.x=cur.x-1;
//            }
//            if(i==3)
//            {
//                next.x=cur.x*2;
//            }
//            if(next.x>=0&&next.x<=1e5&&!vis[next.x])
//            {
//                vis[next.x]=1;
//                next.st=cur.st+1;
//                q.push(next);
//            }
//        }
//    }
//}
//int main()
//{
//    cin>>n>>k;
//    if(n>=k)
//    {
//        cout<<n-k<<endl;
//        return 0;
//    }
//    bfs();
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int a[10],ans;
//double sum;
//int main()
//{
//    for(int i=0;i<10;i++)
//    {
//        cin>>a[i];
//        sum+=a[i];
//    }
//    sum/=10;
//    for(int i=0;i<10;i++)
//    {
//        if(a[i]>sum)
//            ans++;
//    }
//    cout<<ans<<endl;1 2 3 4 5 6 7 8 9 10
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int a[55],ans,b[55];
//bool check(int n)
//{
//    while(n)
//    {
//        if(n%10%2)
//            return false;
//        n/=10;
//    }
//    return true;
//}
//int main()
//{
//    int i=0;
//    while(cin>>a[i]&&(a[i]!=-1))
//    {
//        if(check(a[i]))
//            b[ans++]=a[i];
//        i++;
//    }
//    sort(b,b+ans);
//    cout<<ans<<endl;
//    for(int i=0;i<ans;i++)
//    {
//        printf("%04d\n",b[i]);
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int a[3][3];
//int main()
//{
//    for(int i=0;i<3;i++)
//    {
//        for(int j=0;j<3;j++)
//        {
//            cin>>a[i][j];
//        }
//    }
//    cout<<a[0][0]+a[1][1]+a[2][2]<<" "<<a[0][2]+a[1][1]+a[2][0]<<endl;
//    return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//int a[110],n;
//void bubble_sort(int a[],int sz)
//{
//    int cnt=0;
//    while(1)
//    {
//        cnt++;
//        int flag=1;
//        for(int i=0;i<sz-1;i++)
//        {
//            if(a[i]>a[i+1])
//            {
//                flag=0;
//                int tmp=a[i];
//                a[i]=a[i+1];
//                a[i+1]=tmp;
//            }
//        }
//
//        if(cnt==1)
//        {
//            for(int i=0;i<sz;i++)
//            {
//                cout<<a[i];
//                if(i<sz-1)
//                    cout<<" ";
//            }
//            cout<<endl;
//        }
//        if(flag)
//            break;
//    }
//}
//int main()
//{
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        cin>>n;
//        for(int i=0;i<n;i++)
//        {
//            cin>>a[i];
//        }
//        bubble_sort(a,n);
//        for(int i=0;i<n;i++)
//        {
//            cout<<a[i];
//            if(i<n-1)
//                cout<<" ";
//        }
//        cout<<endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//using namespace std;
//const int maxx=20;
//int n,m,a[maxx][maxx],cal[maxx][maxx];
//int out[maxx][maxx];
//int dir[5][2]={{1,0},{0,-1},{0,1},{0,0},{-1,0}};
//int f(int x,int y)
//{
//    int tmp=a[x][y];
//    for(int i=0;i<5;i++)
//    {
//        int xi=x+dir[i][0];
//        int yi=y+dir[i][1];
//        if(xi<1||xi>n||yi<1||yi>m)
//        {
//            continue;
//        }
//        tmp+=cal[xi][yi];
//    }
//    return tmp%2;
//}
//int dfs()
//{
//    for(int i=2;i<=n;i++)
//    {
//        for(int j=1;j<=m;j++)
//        {
//            if(f(i-1,j))
//            {
//                cal[i][j]=1;
//            }
//        }
//    }
//    for(int i=1;i<=m;i++)
//    {
//        if(f(n,i))
//        {
//            return -1;
//        }
//    }
//    int res=0;
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=m;j++)
//        {
//            res+=cal[i][j];
//        }
//    }
//    return res;
//}
//int main()
//{
//    while(cin>>n>>m)
//    {
//    int ans=0x3f3f3f3f;
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=m;j++)
//        {
//            cin>>a[i][j];
//        }
//    }
//    int flag=0;
//    for(int s=0;s<(1<<m);s++)
//    {
//        memset(cal,0,sizeof(cal));
//        for(int j=1;j<=m;j++)
//        {
//            cal[1][m-j+1]=s>>(j-1)&1;
//        }
//        int cnt=dfs();
//        if(cnt>=0&&cnt<ans)
//        {
//            flag=1;
//            ans=cnt;
//            memcpy(out,cal,sizeof(cal));
//        }
//    }
//    if(!flag)
//        cout<<"IMPOSSIBLE"<<endl;
//    else
//    {
//        for(int i=1;i<=n;i++)
//        {
//            for(int j=1;j<=m;j++)
//            {
//                cout<<out[i][j];
//                if(j<m)
//                    cout<<" ";
//            }
//            cout<<endl;
//        }
//    }
//    }
//    return 0;
//}

//#include<iostream>
//using namespace std;
//int n;
//bool vis;
//void dfs(long long x,int n,int k)
//{
//    if(vis)return;
//    if(x%n==0)
//    {
//        printf("%lld\n",x);
//        vis=1;
//        return;
//    }
//    if(k==19)return;
//    dfs(x*10,n,k+1);
//    dfs(x*10+1,n,k+1);
//}
//int main()
//{
//    while(cin>>n&&n)
//    {
//        vis=0;
//        dfs(1,n,1);
//    }
//    return 0;
//}
//

//#include<iostream>
//#include<queue>
//#include<cmath>
//#include<cstring>
//using namespace std;
//bool vis[10000];
//int n,m;
//struct node
//{
//    int x,st;
//};
//int f1(int x,int j)
//{
//    int a=x%10;
//    int b=x/10%10;
//    int c=x/100%10;
//    int d=x/1000;
//    d=j;
//    return d*1000+c*100+b*10+a;
//}
//int f2(int x,int j)
//{
//    int a=x%10;
//    int b=x/10%10;
//    int c=x/100%10;
//    int d=x/1000;
//    c=j;
//    return d*1000+c*100+b*10+a;
//}
//int f3(int x,int j)
//{
//    int a=x%10;
//    int b=x/10%10;
//    int c=x/100%10;
//    int d=x/1000;
//    b=j;
//    return d*1000+c*100+b*10+a;
//}
//int f4(int x,int j)
//{
//    int a=x%10;
//    int b=x/10%10;
//    int c=x/100%10;
//    int d=x/1000;
//    a=j;
//    return d*1000+c*100+b*10+a;
//}
//bool is_prime(int n)
//{
//    if(n<2)
//        return false;
//    for(int i=2;i<=(int)sqrt(n);i++)
//    {
//        if(n%i==0)
//            return false;
//    }
//    return true;
//}
//void bfs()
//{
//    node cur,next;
//    queue<node> q;
//    cur.x=n,cur.st=0;
//    q.push(cur);
//    while(!q.empty())
//    {
//        cur=q.front();
//        q.pop();
//        if(cur.x==m)
//        {
//            cout<<cur.st<<endl;
//            return;
//        }
//        for(int i=1;i<=4;i++)
//        {
//            switch(i)
//            {
//            case 1:
//                for(int j=1;j<=9;j++)
//                {
//                    next.x=f1(cur.x,j);
//                    if(is_prime(next.x)&&!vis[next.x])
//                    {
//                        vis[next.x]=1;
//                        next.st=cur.st+1;
//                        q.push(next);
//                    }
//                }
//                break;
//            case 2:
//                for(int j=0;j<=9;j++)
//                {
//                    next.x=f2(cur.x,j);
//                    if(is_prime(next.x)&&!vis[next.x])
//                    {
//                        vis[next.x]=1;
//                        next.st=cur.st+1;
//                        q.push(next);
//                    }
//                }
//                break;
//            case 3:
//                for(int j=0;j<=9;j++)
//                {
//                    next.x=f3(cur.x,j);
//                    if(is_prime(next.x)&&!vis[next.x])
//                    {
//                        vis[next.x]=1;
//                        next.st=cur.st+1;
//                        q.push(next);
//                    }
//                }
//                break;
//            case 4:
//                for(int j=0;j<=9;j++)
//                {
//                    next.x=f4(cur.x,j);
//                    if(is_prime(next.x)&&!vis[next.x])
//                    {
//                        vis[next.x]=1;
//                        next.st=cur.st+1;
//                        q.push(next);
//                    }
//                }
//                break;
//            }
//
//        }
//    }
//    cout<<"Impossible"<<endl;
//    return;
//}
//int main()
//{
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        memset(vis,0,sizeof(vis));
//        cin>>n>>m;
//        bfs();
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//using namespace std;
//const int maxn=110;
//int n,c;
//char s1[maxn],s2[maxn],tmp1[maxn],tmp2[maxn],s12[2*maxn],s[2*maxn];
//int main()
//{
//    cin>>n;int cnt=1;
//    while(n--)
//    {
//        int ans=0;
//        cin>>c;
//        cin>>s1>>s2>>s;
//        strcpy(tmp1,s1);
//        strcpy(tmp2,s2);
//        cout<<cnt++<<" ";
//        while(1)
//        {
//            ans++;
//            int j1=0,j2=0;
//            int flag=1;
//            int i;
//            for(i=0;i<2*c;i++)
//            {
//                if(flag)
//                {
//                    s12[i]=s2[j1++];
//                    flag=0;
//                }
//                else
//                {
//                    s12[i]=s1[j2++];
//                    flag=1;
//                }
//            }
//            s12[i]='\0';
//            for(int i=0;i<c;i++)
//            {
//                s1[i]=s12[i];
//                s2[i]=s12[i+c];
//            }
//            s1[i]='\0';
//            s2[i]='\0';
//            if(!strcmp(s,s12))
//                break;
//            if(!strcmp(s1,tmp1)&&!strcmp(s2,tmp2))
//            {
//                ans=0;
//                break;
//            }
//        }
//        if(ans)
//        cout<<ans<<endl;
//        else
//            cout<<-1<<endl;
//    }
//    return 0;
//}


//#include<iostream>
//#include<queue>
//using namespace std;
//int a,b,c,ans;
//bool vis[105][105];
//struct node
//{
//    int v[2],st;
//};
//void bfs()
//{
//    node cur,next;
//    queue<node> q;
//    cur.v[0]=0,cur.v[1]=0,cur.st=0;
//    q.push(cur);
//    while(!q.empty())
//    {
//        cur=q.front();
//        q.pop();
//        if(cur.v[0]==c||cur.v[1]==c)
//        {
//            cout<<cur.st<<endl;
//            return;
//        }
//        for(int i=0;i<3;i++)
//        {
//            if(i==0)
//            {
//                for(int j=0;j<2;j++)
//                {
//                    if(j)
//                    {
//                        next.v[0]=cur.v[0],next.v[1]=b;
//                        if(!vis[next.v[0]][next.v[1]])
//                        {
//                            vis[next.v[0]][next.v[1]]=1;
//                            next.st=cur.st+1;
//                            cout<<"FILL(2)"<<endl;
//                            q.push(next);
//                        }
//                    }
//                    else
//                    {
//                        next.v[0]=a,next.v[1]=cur.v[1];
//                        if(!vis[next.v[0]][next.v[1]])
//                        {
//                            vis[next.v[0]][next.v[1]]=1;
//                            next.st=cur.st+1;
//                            cout<<"FILL(1)"<<endl;
//                            q.push(next);
//                        }
//                    }
//                }
//            }
//            if(i==1)
//            {
//                for(int j=0;j<2;j++)
//                {
//                    if(j)
//                    {
//                        next.v[0]=0,next.v[1]=cur.v[1];
//                        if(!vis[next.v[0]][next.v[1]])
//                        {
//                            vis[next.v[0]][next.v[1]]=1;
//                            next.st=cur.st+1;
//                            cout<<"DROP(1)"<<endl;
//                            q.push(next);
//                        }
//                    }
//                    else
//                    {
//                        next.v[0]=cur.v[0],next.v[1]=0;
//                        if(!vis[next.v[0]][next.v[1]])
//                        {
//                            vis[next.v[0]][next.v[1]]=1;
//                            next.st=cur.st+1;
//                            cout<<"DROP(2)"<<endl;
//                            q.push(next);
//                        }
//                    }
//                }
//            }
//            if(i==2)
//            {
//                for(int j=0;j<2;j++)
//                {
//                    if(j)
//                    {
//                        if(cur.v[0]+cur.v[1]>b)
//                            next.v[0]=cur.v[0]-(b-cur.v[1]),next.v[1]=b;
//                        else
//                            next.v[0]=0,next.v[1]=cur.v[0]+cur.v[1];
//                        if(!vis[next.v[0]][next.v[1]])
//                        {
//                            vis[next.v[0]][next.v[1]]=1;
//                            next.st=cur.st+1;
//                            cout<<"POUR(1,2)"<<endl;
//                            q.push(next);
//                        }
//                    }
//                    else
//                    {
//                        if(cur.v[0]+cur.v[1]>a)
//                            next.v[0]=a,next.v[1]=cur.v[1]-(a-cur.v[0]);
//                        else
//                            next.v[0]=cur.v[0]+cur.v[1],next.v[1]=0;
//                        if(!vis[next.v[0]][next.v[1]])
//                        {
//                            vis[next.v[0]][next.v[1]]=1;
//                            next.st=cur.st+1;
//                            cout<<"POUR(2,1)"<<endl;
//                            q.push(next);
//                        }
//                    }
//                }
//            }
//        }
//    }
//    cout<<"impossible"<<endl;
//}
//int main()
//{
//    cin>>a>>b>>c;
//    bfs();
//    return 0;
//}

//#include<iostream>
//#include<queue>
//#include<cstring>
//using namespace std;
//const int maxn=110;
//struct pot
//{
//    int k1,k2,op;
//};
//struct path
//{
//    int x,y,op,step;
//}path[maxn][maxn];
//string str[]={"FILL(1)","FILL(2)","DROP(1)","DROP(2)","POUR(2,1)","POUR(1,2)"};
//int A,B,C;
//bool vis[maxn][maxn];
//void my_clear()
//{
//    struct path h={0,0,0,0};
//    memset(vis,0,sizeof(vis));
//    for(int i=0;i<maxn;i++)
//        for(int j=0;j<maxn;j++)
//            path[i][j]=h;
//}
//void dfs(int x,int y)
//{
//    int a=path[x][y].x;
//    int b=path[x][y].y;
//    if(!path[x][y].step)
//    {
//        if(a==A)
//            cout<<str[0]<<endl;
//        if(b==B)
//            cout<<str[1]<<endl;
//        return ;
//    }
//    dfs(a,b);
//    cout<<str[path[x][y].op]<<endl;
//}
//void bfs()
//{
//    queue<pot> q;
//    pot cur,next;
//    cur.k1=cur.k2=cur.op=0;
//    vis[0][0]=1;
//    q.push(cur);
//    while(!q.empty())
//    {
//        cur=q.front();
//        q.pop();
//        if(cur.k1==C||cur.k2==C)
//        {
//            cout<<path[cur.k1][cur.k2].step<<endl;
//            dfs(cur.k1,cur.k2);
//            return ;
//        }
//        for(int i=0;i<6;i++)
//        {
//            switch(i)
//            {
//                case 0:next.k1=A,next.k2=cur.k2;break;
//                case 1:next.k1=cur.k1,next.k2=B;break;
//                case 2:next.k1=0,next.k2=cur.k2;break;
//                case 3:next.k2=0,next.k1=cur.k1;break;
//                case 5:
//                    if(cur.k1+cur.k2>B)
//                        next.k1=cur.k1+cur.k2-B,next.k2=B;
//                    else
//                        next.k1=0,next.k2=cur.k1+cur.k2;
//                    break;
//                case 4:
//                    if(cur.k1+cur.k2>A)
//                        next.k1=A,next.k2=cur.k2+cur.k1-A;
//                    else
//                        next.k1=cur.k1+cur.k2,next.k2=0;
//                    break;
//            }
//            if(!vis[next.k1][next.k2])
//            {
//                path[next.k1][next.k2].x=cur.k1;
//                path[next.k1][next.k2].y=cur.k2;
//                path[next.k1][next.k2].op=i;
//                path[next.k1][next.k2].step=path[cur.k1][cur.k2].step+1;
//                vis[next.k1][next.k2]=1;
//                q.push(next);
//            }
//        }
//    }
//    cout<<"impossible"<<endl;
//}
//int main()
//{
//    while(cin>>A>>B>>C)
//    {
//        bfs();
//        my_clear();
//    }
//    return 0;
//}









