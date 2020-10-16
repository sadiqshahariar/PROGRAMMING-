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

int knapsack(int w,int wt[],int val[],int n)
{
	int i,j;
	int k[n+1][w+1];
	for(i=0;i<=n;i++)k[i][0]=0;
	for(i=1;i<=w;i++)k[0][i]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=w;j++)
		{
			if(wt[i-1]<=j)
			{
				k[i][j]=max((val[i-1]+k[i][j-wt[i-1]]),(k[i-1][j]));
			}
			else{
				k[i][j]=k[i-1][j];
			}
		}
	}
	return k[n][w];
}

int main()
{
	faster
	int n;
	cin>>n;
	int wt[n+1],val[n+1],i,j,w;
	for(i=0;i<n;i++)cin>>wt[i];
	for(i=0;i<n;i++)cin>>val[i];
	cin>>w;
	cout<<knapsack(w,wt,val,n)<<nl;
	return 0;
}
