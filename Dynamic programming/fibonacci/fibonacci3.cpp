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

typedef long long int ll;
typedef unsigned long long int  llu;
#define mod 1000000007
ll fibonacci(ll a,ll b,ll n)
{
	ll mat[n+1];
	ll i;
	mat[0]=a%mod;
	mat[1]=b%mod;
	for(i=2;i<=n;i++)
	{
		mat[i]=mat[i-1]%mod+mat[i-2]%mod;
	}
	return mat[n]%mod;
}

int main()
{
	//faster
	ll t;
	cin>>t;
	while(t--)
	{
		ll a,b;
		ll n;
		cin>>a>>b>>n;
		cout<<fibonacci(a,b,n)<<nl;
	}
	return 0;
}
