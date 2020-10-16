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
int dp[1000][1000];
bool ispalindrome(string s,int i, int j)
{
	while(i<j)
	{
		if(s[i]!=s[j])
		{
			return false;
		}
		i++,j--;
	}
	return true;
}

int pp(string s,int i,int j)
{
	if(i>=j)return 0;
	if(ispalindrome(s,i,j)==true)return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	int k,mn=INT_MAX;
	for(k=i;k<j;k++)
	{
		int left,right;
		if(dp[i][k]!=-1)
		{
			left=dp[i][k];
		}
		else{
			left=pp(s,i,k);
			dp[i][k]=left;
		}
		if(dp[k+1][j]!=-1)
		{
			right=dp[k+1][j];
		}
		else{
			right=pp(s,k+1,j);
			dp[k+1][j]=right;
		}
		int temp=right+left+1;
		if(temp<mn)mn=temp;
	}
	//return mn;
	return dp[i][j]=mn;
}

int main()
{
	faster
	string a;
	cin>>a;
	int i,j;
	i=0,j=a.size()-1;
	memset(dp,-1,sizeof(dp));
	cout<<pp(a,i,j)<<nl;
	return 0;
}
