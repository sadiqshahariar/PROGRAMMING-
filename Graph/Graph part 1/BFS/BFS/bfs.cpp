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
vector<int>v[10001];
void bfs(int node)
{
	queue<int>q;
	q.push(node);
	vis[node]=1;
	dis[node]=0;
	while(!q.empty())
	{
		int a=q.front();
		q.pop();
		for(int child: v[a])
		{
			if(vis[child]==0)
			{
				dis[child]=dis[a]+1;
				vis[child]=1;
				q.push(child);
			}
		}
	}
}
int main()
{
	int n,m,i,x,y;
	cin>>n>>m;
	while(m--)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfs(1);
	for(i=1;i<=n;i++)
	{
		cout<<"The level of "<<i<<" is: "<<dis[i]<<nl;
	}
	return 0;
}
