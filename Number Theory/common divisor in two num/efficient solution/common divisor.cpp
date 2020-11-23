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

int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
int comdiv(int a,int b)
{
	int n=gcd(a,b);
	int result=0;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			if(n/i==i)result++;
			else result+=2;
		}
	}
	return result;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		cout<<comdiv(a,b)<<nl;
	}
	return 0;
}
