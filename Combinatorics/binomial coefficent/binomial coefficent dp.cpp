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

ll C(ll n,ll k)
{
	ll ar[k+3],i,j;
	memset(ar,0,sizeof(ar));
	ar[0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=min(i,k);j>0;j--)
		{
			ar[j]=(ar[j]+ar[j-1])%mod;
		}
	}
	return ar[k];
}

int main()
{
	int t;
	cin>>t;
	//t=1;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		cout<<C(n,k)<<nl;
	}
	return 0;
}


