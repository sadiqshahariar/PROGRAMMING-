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
	faster
	int n;
	cin>>n;
	int i,ar[n+1];
	for(i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	int j,ans=0;
	for(i=0;i<31;i++)
	{
		int one=0,zero=0;
		for(j=0;j<n;j++)
		{
			if(ar[j]&(1<<i))one++;
			else zero++;
		}
		int p = one*zero;
		ans+=(1<<i)*p;
	}
	cout<<ans<<nl;
}
