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

ll power(ll a, ll n,ll m)
{
	ll result=1;
	while(n)
	{
		if(n%2==1)
		{
			result=((result%m)*(a%m))%m;
			n--;
		}
		else
		{
			a=((a%m)*(a%m))%m;
			n/=2;
		}
	}
	return result;
}
ll gcd(ll a,ll b,ll n)
{
	if(a==b)
	{
		return (power(a,n,mod)+power(b,n,mod))%mod;
	}
	ll candidate=1;
	ll num=a-b;
	for(ll i=1;i*i<=num;i++)
	{
		if(num%i==0)
		{
			ll temp=(power(a,n,i)+power(b,n,i))%i;
			if(temp==0)candidate=max(candidate,i);
			temp=(power(a,n,num/i)+power(b,n,num/i))%(num/i);
			if(temp==0)candidate=max(candidate,num/i);

		}
	}
	return candidate%mod;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b,n;
		cin>>a>>b>>n;
		cout<<gcd(a,b,n)<<nl;
	}
	return 0;
}
