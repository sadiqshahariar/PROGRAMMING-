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

ll solve(int ar[],int n,int k)
{
    ll i=0,j=0;
    ll sum=ar[0];
    ll ans=0;
    while(j<n)
    {
        //cout<<sum<<" "<<j<<nl;
        if(sum<k)
        {
            j++;
            sum+=ar[j];
        }
        else if(sum==k)
        {
             ll z=j-i+1;
            ans=max(z,ans);
            j++;
            cout<<z<<nl;
            sum+=ar[j];
        }
        else{
            sum-=ar[i];
            i++;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ar[n+4],i,k;
        for(i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        cin>>k;
        ll ans=solve(ar,n,k);
        cout<<ans<<nl;
    }
}
