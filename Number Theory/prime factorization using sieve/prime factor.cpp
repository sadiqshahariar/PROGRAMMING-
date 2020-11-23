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
int mx=100000;
int  ar[100001];
void sieve()
{
	for(int i=2;i<=mx;i++)
	{
		if(ar[i]==0)
		{
			for(int j=i;j<=mx;j+=i)
			{
				if(ar[j]==0)ar[j]=i;
			}
		}
	}
}
void factor(int n)
{
	while(n!=1)
	{
		cout<<ar[n]<<" ";
		n=n/ar[n];
	}
	cout<<nl;
}
int main()
{
	int t;
	cin>>t;
	sieve();
	while(t--)
	{
		int n;
		cin>>n;
		factor(n);
	}
	return 0;
}
