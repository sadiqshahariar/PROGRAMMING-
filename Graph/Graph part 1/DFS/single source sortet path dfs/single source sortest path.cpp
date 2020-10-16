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

int vis[10001],dis[10001];
vector<int>v[1000];

void dfs(int node,int d)
{
	vis[node]=1;
	dis[node]=d;
	for(int child: v[node])
	{
		if(vis[child]==0)
		{
			dfs(child,dis[node]+1);
		}
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	int i,x,y;
	while(m--)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int a;
	cin>>a;
	dfs(a,0);
	int q;
	cin>>q;
	while(q--)
	{
		int b;
		cin>>b;
		cout<<dis[b]<<nl;
	}
	return 0;
}
