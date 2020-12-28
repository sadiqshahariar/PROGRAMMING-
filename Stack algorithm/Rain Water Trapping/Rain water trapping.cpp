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
vector<int>v;
vector<int>v1;

void solve(int ar[],int n)
{
    int i,j;
    int mx=0;
    for(i=0;i<n;i++)
    {
        mx=max(mx,ar[i]);
        v.push_back(mx);
    }
    mx=0;
    for(i=n-1;i>=0;i--)
    {
        mx=max(mx,ar[i]);
        v1.push_back(mx);
    }
    ll ans=0;
    for(i=0,j=n-1;i<n;i++,j--)
    {
        ans+=min(v[i],v1[j])-ar[i];
    }
    cout<<ans<<nl;
}

int main()
{
    int n;
    cin>>n;
    int i,ar[n+3];
    for(i=0;i<n;i++)cin>>ar[i];
    solve(ar,n);
}
