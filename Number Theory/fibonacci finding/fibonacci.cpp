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

ll ar[3];
ll T[3][3],I[3][3];
int mod = 1000000007;

void mul(ll A[][3],ll B[][3],int n)
{
	ll R[n+1][n+1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			R[i][j]=0;
			for(int k=1;k<=n;k++)
			{
				ll x = (A[i][k]*B[k][j])%mod;
				R[i][j]=(R[i][j]+x)%mod;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			A[i][j]=R[i][j];
		}
	}
}

ll mm(ll p)
{
	I[1][1]=I[2][2]=1;
	I[1][2]=I[2][1]=0;
	T[1][1]=0;
	T[1][2]=T[2][1]=T[2][2]=1;
	if(p<=2)return ar[p];
	p--;
	while(p)
	{
		if(p%2==0)
		{
			mul (T,T,2);
			p/=2;
		}
		else{
			mul(I,T,2);
			p--;
		}
	}
	ll ans = (ar[2]*I[2][1]) + (ar[1]*I[1][1]);
	return ans;
}

int main()
{
	//faster
	ll t;
	//cin>>t;
	t=1;
	while(t--)
	{
		ll i,j,p;
		cin>>ar[1]>>ar[2]>>p;
		//p++;
		ll ans=mm(p);
		//if(ans<0)ans+=mod;
		cout<<ans<<nl;
	}
	return 0;
}
