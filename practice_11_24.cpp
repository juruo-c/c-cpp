#include<bits/stdc++.h>
using namespace std;
int n,h[310],ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
    }
    sort(h+1,h+n+1);
    int q=0,p=n;
    while(q<p)
    {
        ans+=pow((h[p]-h[q]),2);
        q++;
        ans+=pow((h[p]-h[q]),2);
        p--;
    }
    cout<<ans<<endl;
    return 0;
}
