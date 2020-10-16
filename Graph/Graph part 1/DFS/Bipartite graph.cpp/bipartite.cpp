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

int vis[1000],col[1000];
vector<int>v[1000];

bool dfs(int node,int c)
{
	vis[node]=1;
	col[node]=c;
	for(int child: v[node])
	{
		if(vis[child]==0)
		{
			if(dfs(child,c^1)==false)
			{
				return false;
			}
		}
		else
		{
			if(col[node]==col[child])
			{
				return false;
			}
		}
	}
	return true;
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
	bool ans=dfs(1,1);
	if(ans==true)cout<<"the graph is bipartite"<<nl;
	else cout<<"This graph is not bipartite graph"<<nl;
	return 0;
}
