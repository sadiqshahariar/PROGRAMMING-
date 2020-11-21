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

#define mx 500
int multiply(int x,int res[],int sz);

void factorial(int n)
{
	int res[mx];
	res[0]=1;
	int sz=1;
	for(int i=2;i<=n;i++)
	{
		sz=multiply(i,res,sz);
	}
	for(int i=sz-1;i>=0;i--)
	{
		cout<<res[i];
	}
	cout<<nl;
}
int multiply(int x,int res[],int sz)
{
	int carry=0;
	for(int i=0;i<sz;i++)
	{
		int prod=res[i]*x+carry;
		res[i]=prod%10;
		carry=prod/10;
	}
	while(carry)
	{
		res[sz]=carry%10;
		carry=carry/10;
		sz++;
	}
	return sz;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		factorial(n);
	}
	return 0;
}
