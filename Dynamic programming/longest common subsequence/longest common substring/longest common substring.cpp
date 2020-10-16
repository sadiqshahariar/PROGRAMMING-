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

int lcs(string a,string b,int n,int m)
{
	int i,j,dp[n+1][m+1];
	for(i=0;i<=n;i++)dp[i][0]=0;
	for(i=0;i<=m;i++)dp[0][i]=0;
	int result=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i-1]==b[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
				result=max(result,dp[i][j]);
			}
			else dp[i][j]=0;
		}
	}
	return result;
}

int main()
{
	//faster
	int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		cout<<lcs(a,b,a.length(),b.length())<<nl;
	}
	return 0;
}
