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
int dp[1000][1000];
typedef long long int ll;
typedef unsigned long long int  llu;

int solve(int e,int f)
{
	if(f==0||f==1)return f;
	if(e==1)return f;
	if(dp[e][f]!=-1)return dp[e][f];
	int mn=INT_MAX;
	for(int k=1;k<=f;k++)
	{
		int temp=1+max(solve(e-1,k-1),solve(e,f-k));
		mn=min(mn,temp);
	}
	return dp[e][f]=mn;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		int egg,floor;
		cin>>egg>>floor;
		cout<<solve(egg,floor)<<nl;
	}
	return 0;
}
