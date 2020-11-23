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

int power(int a,int n,int m)
{
	int result=1;
	while(n)
	{
		if(n%2==1)
		{
			result=(result*a)%m;
			n--;
		}
		else{
			a=(a*a)%m;
			n/=2;
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
		int a,m;
		cin>>a>>m;
		cout<<"a^-1 = "<<power(a,m-2,m)<<nl;
	}
	return 0;
}
