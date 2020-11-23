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
#define N 101
ll ar[N][N],I[N][N];
ll mod = 1000000007;

void mul(ll A[][N],ll B[][N],ll n)
{
	ll i,j,k;
	ll R[n+1][n+1];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			R[i][j]=0;
			for(k=1;k<=n;k++)
			{
				ll x = (A[i][k]*B[k][j])%mod;
				R[i][j]=(R[i][j]+x)%mod;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			A[i][j]=R[i][j];
		}
	}
}
void power(ll A[][N],ll n,ll p)
{
	ll i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)I[i][j]=1;
			else I[i][j]=0;
		}
	}

	//multiply the matrix
	/*
	for(i=1;i<=p;i++)
	{
		mul(I,A,n);
	}
	*/
	while(p)
	{
		if(p%2==1)
		{
			mul(I,A,n);
			p--;
		}
		else{
			mul(A,A,n);
			p/=2;
		}
	}
	//return value

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			A[i][j]=I[i][j];
		}
	}

}



int main()
{
	faster
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,p,i,j,k;
		cin>>n>>p;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				cin>>ar[i][j];
			}
		}
		power(ar,n,p);
		//cout<<"print the answer"<<nl;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				cout<<ar[i][j]<<" ";
			}
			cout<<nl;
		}
	}
	return 0;
}
