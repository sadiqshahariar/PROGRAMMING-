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

int scs(string a,string b,int x,int y)
{
	int i,j,dp[x+1][y+1];
	for(i=0;i<=x;i++)dp[i][0]=0;
	for(i=1;i<=y;i++)dp[0][i]=0;
	for(i=1;i<=x;i++)
	{
		for(j=1;j<=y;j++)
		{
			if(a[i-1]==b[j-1])dp[i][j]=1+dp[i-1][j-1];
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout<<dp[x][y]<<nl;
	return x+y-dp[x][y];
}

int main()
{
	faster
	string a,b;
	int x,y;
	cin>>a>>b;
	x=a.size();
	y=b.size();
	cout<<scs(a,b,x,y)<<nl;
	return 0;

}
