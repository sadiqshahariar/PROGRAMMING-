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

int divmul(int n,int k)
{
	int cnt=0,i;
	for(i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			if(i%k==0)cnt++;
			if((n/i)%k==0)cnt++;
		}
	}
	i--;
	if((i*i==n)&&(i%k==0))cnt++;
	return cnt;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		cout<<divmul(n,k)<<nl;
	}
	return 0;
}
