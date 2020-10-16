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

int napsack(int w,int wt[],int val[],int n)
{
	if(n==0||w==0)return 0;
	if(wt[n]>w)return napsack(w,wt,val,n-1);
	else
	{
		return max(val[n]+napsack(w-wt[n],wt,val,n-1),napsack(w,wt,val,n-1));
	}
}

int main()
{
	faster
	int n;
	cin>>n;
	int i,j,wt[n+1],val[n+1],w;
	for(i=0;i<n;i++)cin>>wt[i];
	for(i=0;i<n;i++)cin>>val[i];
	cin>>w;
	cout<<napsack(w,wt,val,n-1)<<nl;
	return 0;
}
