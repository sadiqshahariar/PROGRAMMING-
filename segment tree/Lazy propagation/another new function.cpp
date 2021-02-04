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
ll phi[2000010];
ll dp[2000003];
void init(ll mx)
{
	for(ll i=1;i<=mx;i++)
	{
		phi[i]=i;
	}
	for(ll i=2;i<=mx;i++)
	{
		if(phi[i]==i)
		{
			for(ll j=i;j<=mx;j+=i)
			{
				phi[j]/=i;
				phi[j]*=(i-1);
			}
		}
	}
}

ll solve(ll n)
{
    if(n==1)
    {
        return 0;
    }
    if(dp[n]!=0)
    {
        return dp[n];
    }
    return dp[n]=solve(phi[n])+1;
}

int main()
{
	init(2000000);
	ll t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		ll sum=0;
		for(ll i=m;i<=n;i++)
        {
            sum+=solve(i);
        }
        cout<<sum<<nl;
	}
	return 0;
}
