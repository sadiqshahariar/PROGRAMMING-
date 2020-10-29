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
int n,m;
int vis[10001];
vector<int>v[10001];
vector<int>tr[10001];
vector<int>ans,ans2;
int dfs(int node)
{
	vis[node]=1;
	for(int child: v[node])
	{
		if(vis[child]==0)
		{
			dfs(child);
		}
	}
	ans.push_back(node);
}
int dfs2(int node)
{
	vis[node]=1;
	for(int child: tr[node])
	{
		if(vis[child]==0)
		{
			dfs2(child);
		}
	}
	ans2.push_back(node);
}
int main()
{
	int a,b,t,i;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(i=1;i<=n;i++)
		{
			vis[i]=0;
			v[i].clear();
			tr[i].clear();
		}
		ans.clear();
		while(m--)
		{
			cin>>a>>b;
			v[a].push_back(b);
			tr[b].push_back(a);
		}
		for(i=1;i<=n;i++)
		{
			if(vis[i]==0)
			{
				dfs(i);
			}
		}
		for(i=1;i<=n;i++)vis[i]=0;
		for(i=1;i<=n;i++)
		{
			if(vis[ans[n-i]]==0)
			{
				ans2.clear();
				dfs2(ans[n-i]);
				cout<<"Ans"<<nl;
				for(int child: ans2)
				{
					cout<<child<<" ";
				}
				cout<<nl;
			}
		}
	}
}
