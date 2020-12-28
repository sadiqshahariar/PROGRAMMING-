#include<bits/stdc++.h>
using  namespace  std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define sq(x)   (x)*(x)
#define PI      acos(-1.0)
#define all(x) x.begin(),x.end()
#define nl      '\n'
 #define mod 1000000007
typedef long long int ll;
typedef unsigned long long int  llu;

int arr[10001][10001];
vector<int>v;
vector<int>v1;

void leftsmaller(int ar[],int n)
{
    int i;
    stack< pair<int,int> >st;
    for(i=0;i<=n;i++)
    {
       int ans=-1;
       while(!st.empty())
       {
           int x=st.top().first;
           int y=st.top().second;
           if(x<ar[i])
           {
               ans=y;
               break;
           }
           st.pop();
       }
       v.push_back(ans);
       st.push({ar[i],i});
    }
}

void rightsmaller(int ar[],int n)
{
    int i;
    stack< pair<int,int> >st;
    for(i=n;i>=0;i--)
    {
       int ans=n+1;
       while(!st.empty())
       {
           int x=st.top().first;
           int y=st.top().second;
           if(x<ar[i])
           {
               ans=y;
               break;
           }
           st.pop();
       }
       v1.push_back(ans);
       st.push({ar[i],i});
    }
}

ll print(int ar[])
{
    ll mx=0,i,j;
    for(i=0,j=v1.size()-1;i<v.size();i++,j--)
    {
        ll ans=v1[j]-v[i]-1;
        cout<<v1[j]<<" "<<v[i]<<" ";
        ans*=ar[i];
        mx=max(mx,ans);
        cout<<ans<<" "<<mx<<nl;
    }
    return mx;
}

void rectangle(int n,int m)
{
    int ar[m+4];
    int i,j;
    for(j=0;j<m;j++)ar[j]=arr[0][j];
    leftsmaller(ar,m-1);
    rightsmaller(ar,m-1);
    ll ans=print(ar);
    for(i=1;i<n;i++)
    {
        v.clear();
        v1.clear();
        for(j=0;j<m;j++)
        {
            if(arr[i][j]==0)ar[j]=0;
            else ar[j]+=arr[i][j];
        }
        leftsmaller(ar,m-1);
        rightsmaller(ar,m-1);
        ans=max(ans,print(ar));
    }
    cout<<ans<<nl;
}

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)cin>>arr[i][j];
    }
    rectangle(n,m);
    /*
    int n;
    cin>>n;
    int i,ar[n+4];
    for(i=0;i<n;i++)cin>>ar[i];
    leftsmaller(ar,n-1);
    rightsmaller(ar,n-1);
    ll mx = print(ar);
    cout<<mx<<nl;
    return 0;
    */
}
