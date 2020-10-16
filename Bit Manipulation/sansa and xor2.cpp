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


int main()
{
	//problem link https: www.hackerrank.com/challenges/sansa-and-xor/problem
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,i,ans=0;
		cin>>n;
		ll ar[n];
		for(i=0;i<n;i++)
		{
			cin>>ar[i];
			if(((i+1)*(n-i))%2==1)ans=ans^ar[i];
		}
		cout<<ans<<nl;
	}
	return 0;
}
