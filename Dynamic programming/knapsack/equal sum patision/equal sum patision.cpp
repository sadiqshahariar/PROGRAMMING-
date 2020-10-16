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

bool subsetsum(int ar[],int n,int sum)
{
	int i,j;
	bool subset[n+1][sum+1];
	for(i=0;i<=n;i++)
	{
		subset[i][0]=true;
	}
	for(i=1;i<=sum;i++)subset[0][i]=false;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=sum;j++)
		{
			if(j<ar[i-1])subset[i][j]=subset[i-1][j];
			if(j>=ar[i-1])subset[i][j]=subset[i-1][j]||subset[i-1][j-ar[i-1]];
		}
	}
	return subset[n][sum];
}

int main()
{
	faster
	int n;
	cin>>n;
	int i,ar[n+1],sum=0;
	for(i=0;i<n;i++)
	{
		cin>>ar[i];
		sum+=ar[i];
	}
	//cout<<sum<<nl;
	if(sum%2==1)cout<<"No"<<nl;
	else
	{
		bool x;
		x=subsetsum(ar,n,sum/2);
		if(x==true)cout<<"Yes"<<nl;
		else cout<<"No"<<nl;
	}
	return 0;
}
