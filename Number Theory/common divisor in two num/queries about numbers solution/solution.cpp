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
//typedef long long int ll;
#define ll long long int
typedef unsigned long long int  llu;
map<ll,ll>mp;
ll total;
void factorize(ll n)
{
	total=1;
	for(ll i=2;i*i<=n;i++)
	{
		int cnt=0;
		while(n%i==0)
		{
			cnt++;
			n/=i;
		}
		mp[i]=cnt;
		total*=(cnt+1);
	}
	if(n>1){
		mp[n]=1;
		total*=2;
	}
}

int main()
{
	faster
	ll t,n,q,k;
	cin>>n>>q;
	factorize(n);
	while(q--)
	{
		cin>>t>>k;
		if(t==1)
		{
			// divisible of t and k ......
			ll result=1;
			for(pair<ll,ll> p : mp)
			{
				ll cnt=0;
				while(k%p.first==0)
				{
					cnt++;
					k/=p.first;
				}
				result*=min(cnt,p.second)+1;
			}
			cout<<result<<nl;
		}
		else if(t==2)
		{
			//divisor of n and divisible by k
			ll result=1;
			for(pair<ll,ll>p:mp)
			{
				ll cnt=0;
				while(k%p.first==0)
				{
					cnt++;
					k/=p.first;
				}
				if(cnt>p.second)
				{
					result=0;
					break;
				}
				result*=(p.second-cnt+1);
			}
			if(k>1)result=0;
			cout<<result<<nl;
		}
		else{
			ll result=1;
			for(pair<ll,ll> p:mp)
			{
				ll cnt=0;
				while(k%p.first==0)
				{
					cnt++;
					k/=p.first;
				}
				if(cnt>p.second)
				{
					result=0;
					break;
				}
				result*=(p.second-cnt+1);
			}
			if(k>1)result=0;
			cout<<(total-result)<<nl;
		}
	}
	return 0;
}
