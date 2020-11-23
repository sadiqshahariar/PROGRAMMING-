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

ll power(ll x,llu y,ll p)
{
	ll res=1;
	x=x%p;
	while(y>0)
	{
		if(y&1)res=(res*x)%p;
		y=y>>1;
		x=(x*x)%p;
	}
	return res;
}
bool millertest(ll d,ll n)
{
	ll a=2+rand()%(n-4);
	ll x=power(a,d,n);
	if(x==1||x==n-1)return true;
	while(d!=n-1)
	{
		x=(x*x)%n;
		d*=2;
		if(x==1)return false;
		if(x==n-1)return true;
	}
	return false;
}
bool isprime(ll n,ll k)
{
	if(n<=1||n==4)return false;
	if(n<=3)return true;
	ll d=n-1;
	while(d%2==0)
	{
		d/=2;
	}
	for(ll i=0;i<k;i++)
	{
		if(!millertest(d,n))return false;

	}
	return true;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		if(isprime(n,4))cout<<"YES"<<nl;
		else cout<<"NO"<<nl;
	}
	return 0;
}
