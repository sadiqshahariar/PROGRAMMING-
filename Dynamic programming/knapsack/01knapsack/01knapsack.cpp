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
int t[100][1000];

int knapsack(int w,int wt[],int val[],int n)
{
	if(n==0||w==0)return 0;
	if(t[n][w]!=-1)return t[n][w];
	if(wt[n]>w)
	{
		return t[n][w]=knapsack(w,wt,val,n-1);
	}
	else
	{
		return t[n][w] = max(val[n]+knapsack(w-wt[n],wt,val,n-1),knapsack(w,wt,val,n-1));
	}
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
	memset(t,-1,sizeof(t));
	cout<<knapsack(w,wt,val,n-1);
	return 0;
}
