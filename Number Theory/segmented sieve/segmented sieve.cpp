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
vector<int> v;
void sieve(int n)
{
	int prime[100001];
	memset(prime,0,sizeof(prime));
	for(int i=2;i*i<=n;i++)
	{
		if(prime[i]==0)
		{
			for(int j=i*i;j<=n;j+=i)
			{
				prime[j]=1;
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(prime[i]==0)v.push_back(i);
	}
}
void init(int l,int r)
{
	if(l==1)l++;
	int mx=r-l+1;
	int ar[mx+1];
	for(int i=0;i<=mx;i++)ar[i]=0;
	for(int p:v)
	{
		if(p*p<=r)
		{
			int i=(l/p)*p;
			if(i<l)i+=p;
			for(;i<=r;i+=p)
			{
				if(i!=p)
				{
					ar[i-l]=1;
				}
			}
		}
	}
	for(int i=0;i<mx;i++)
	{
		if(ar[i]==0)
		{
			cout<<l+i<<nl;
		}
	}
}
int main()
{
	sieve(100000);
	int t,L,R;
	cin>>t;
	while(t--)
	{
		cin>>L>>R;
		init(L,R);
		cout<<nl;
	}
	return 0;
}
