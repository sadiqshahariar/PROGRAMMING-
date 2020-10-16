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
int vis[10001];
vector<int>v[10001];

bool dfs(int node,int par)
{
	vis[node]=1;
	for(int child: v[node])
	{
		if(vis[child]==0)
		{
			if(dfs(child,node)==true)
			{
				return true;
			}
		}
		else
		{
			if(child!=par)return true;
		}
	}
	return false;
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
	bool ans=dfs(1,-1);
	if(ans==true)cout<<"The graph has a cycle"<<nl;
	else cout<<"The graph has no cycle"<<nl;
	return 0;
}
