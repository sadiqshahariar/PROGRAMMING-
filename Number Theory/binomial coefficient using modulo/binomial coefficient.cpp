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

int f[1000001];

int power(int a,int n)
{
	int result=1;
	while(n)
	{
		if(n%2==1)
		{
			result=(result* 1LL * a)%mod;
			n--;
		}
		else{
			a=(a*1LL*a)%mod;
			n/=2;
		}
	}
	return result;
}
int C(int n,int k)
{
	if(k>n)return 0;
	int res=f[n];
	res=(res* 1LL * power(f[k], mod-2))%mod;
	res=(res*1LL*power(f[n-k],mod-2))%mod;
	return res;
}
int main()
{
	f[0]=f[1]=1;
	for(int i=2;i<=1000000;i++)
	{
		f[i]=(f[i-1] * 1LL * i)%mod;
	}
	int q;
	int n,k;
	cin>>q;
	while(q--)
	{
		cin>>n>>k;
		cout<<C(n,k)<<nl;
	}
	return 0;
}
