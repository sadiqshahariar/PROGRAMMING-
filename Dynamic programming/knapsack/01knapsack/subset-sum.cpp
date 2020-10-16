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

bool subset(int ar[],int n,int sum)
{
	bool sub[n+1][sum+1];
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0)sub[i][j]=false;
			if(j==0)sub[i][j]=true;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=sum;j++)
		{
			if(ar[i-1]<=j)
			{
				//cout<<sub[i-1][j]<<" "<<sub[i-1][j-ar[i-1]]<<nl;
				sub[i][j]=sub[i-1][j] || sub[i-1][j-ar[i-1]];
			}
			else sub[i][j]=sub[i-1][j];
			cout<<sub[i][j]<<" ";
		}
		cout<<nl;
	}
	return sub[n][sum];
}

int main()
{
	faster
	int n;
	cin>>n;
	int i,ar[n+1];
	for(i=0;i<n;i++)cin>>ar[i];
	int sum;
	cin>>sum;
	bool x = subset(ar,n,sum);
	if(x==true)cout<<"i am here"<<nl;
	else cout<<"the subset is not here"<<nl;
	return 0;
}
