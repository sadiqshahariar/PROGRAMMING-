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

int mincoin(int ar[],int n,int sum)
{
	int i,j,dp[n+1][sum+1];
	for(i=0;i<=sum;i++)dp[0][i]=INT_MAX;
	for(i=1;i<=n;i++)dp[i][0]=0;
	for(i=1;i<=sum;i++)
	{
		if(i%ar[0]==0)dp[1][i]=i/ar[0];
		else dp[1][i]=INT_MAX-1;
	}
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=sum;j++)
		{
			if(j>=ar[i-1])
			{
				dp[i][j]=min(1+dp[i][j-ar[i-1]],dp[i-1][j]);
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	return dp[n][sum];
}

int main()
{
	faster
	int n;
	cin>>n;
	int i,ar[n];
	for(i=0;i<n;i++)cin>>ar[i];
	int sum;
	cin>>sum;
	cout<<mincoin(ar,n,sum)<<nl;
	return 0;
}
