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
int in[101],low[101],vis[101];
vector<int>v[101];
set<int>s;
int timer;
int xx=0;
void dfs(int node,int par)
{
	vis[node]=1;
	in[node]=low[node]=timer++;
	int cnt=0;
	for(int child: v[node])
	{
		if(child==par)continue;
		if(vis[child]==1)
		{
			low[node]=min(low[node],in[child]);
		}
		else{
			if(node==1)xx++;
			dfs(child,node);
			low[node]=min(low[node],low[child]);
			if(low[child]>=in[node]&&par!=-1)
			{
				//cout<<node<<" -> "<<child<<"  is a bridge"<<nl;
				s.insert(node);
				cnt++;
			}
		}
	}
	if(par==-1&&cnt>1)s.insert(node);
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
	dfs(1,-1);
	if(xx>1)s.insert(1);
	for(int a: s)
	{
		cout<<a<<" ";
	}
	cout<<nl;
	return 0;
}
