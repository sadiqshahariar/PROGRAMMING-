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

int vis[10001],in[100001],out[10001];
int timer=1;
vector<int>v[10001];
void dfs(int node)
{
	vis[node]=1;
	in[node]=timer++;
	for(int child: v[node])
	{
		if(vis[child]==0)
		{
			dfs(child);
		}
	}
	out[node]=timer++;
}
int main()
{
	int n,m,x,y,i;
	cin>>n>>m;
	while(m--)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	for(i=1;i<=n;i++)
	{
		cout<<"The In and Out time of: "<<i<<" -> "<<in[i]<<" "<<out[i]<<nl;
	}
	return 0;
}
