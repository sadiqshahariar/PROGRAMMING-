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

int totaldivisor(int n)
{
	int total=1;
	int cnt=0;
	while(n%2==0)
	{
		n/=2;
		cnt++;
	}
	total=total*(cnt+1);
	for(int i=3;i<=n;i+=2)
	{
		if(n%i==0)
		{
			cnt=0;
			while(n%i==0)
			{
				n/=i;
				cnt++;
			}
			total=total*(cnt+1);
		}
	}
	return total;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<totaldivisor(n)<<nl;
	}
	return 0;
}
