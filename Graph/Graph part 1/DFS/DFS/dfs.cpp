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
int vis[1000];
vector<int>v[10000];
void dfs(int node)
{
	vis[node]=1;
	cout<<node<<"->";
	for(int child: v[node])
	{
		if(vis[child]==0)
		{
			dfs(child);
		}
	}
}
int main()
{
	int n,m,i;
	cin>>n>>m;
	int x,y;
	while(m--)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			dfs(i);
		}
		cout<<nl;
	}
	return 0;
}
