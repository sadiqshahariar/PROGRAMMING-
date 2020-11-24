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
int gcd(int a,int b,int *x,int *y)
{
	if(a==0)
	{
		*x=0;
		*y=1;
		return b;
	}
	int x1,y1;
	int ans=gcd(b%a,a,&x1,&y1);
	*x=y1-(b/a)*x1;
	*y=x1;
	return ans;
}

int main()
{
	faster
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		int ans=__gcd(a,b);
		if(ans>1)cout<<-1<<nl;
		else{
			cout<<(a * b - a - b +1)<<nl;
		}
	}
	return 0;
}


