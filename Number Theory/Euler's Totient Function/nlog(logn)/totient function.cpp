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
int phi[1000001];
void init(int mx)
{
	for(int i=1;i<=mx;i++)
	{
		phi[i]=i;
	}
	for(int i=2;i<=mx;i++)
	{
		if(phi[i]==i)
		{
			for(int j=i;j<=mx;j+=i)
			{
				phi[j]/=i;
				phi[j]*=(i-1);
			}
		}
	}
}

int main()
{
	init(1000000);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<phi[n]<<nl;
	}
	return 0;
}
