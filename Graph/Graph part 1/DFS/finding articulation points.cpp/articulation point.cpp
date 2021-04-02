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
 
vector<int>v[10001];
int ar[10001],in[10001],low[10001];
set<int>ans;
int timer;
 
void dfs(int node,int par)
{
	ar[node]=1;
	in[node]=low[node]=timer++;
	int cnt=0;
	for(int child: v[node])
	{
		if(child==par)continue;
		if(ar[child]==1)
		{
			low[node]=min(low[node],in[child]);
		}
		else{
			dfs(child,node);
			cnt++;
			low[node]=min(low[node],low[child]);
			if(low[child]>=in[node]  &&  par!=-1)
			{
				ans.insert(node);
			}
		}
	}
	if(par==-1 && cnt>1)ans.insert(node);
}
int main()
{
	int n,m,a,b;
	while(1)
	{
		cin>>n>>m;
		if(n==0&&m==0)break;
		for(int i=1;i<=n;i++)
		{
			v[i].clear();
			ar[i]=0;
		}
		timer=1;
		ans.clear();
		while(m--)
		{
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(int i=1;i<=n;i++)
		{
			if(ar[i]==0)
			{
				dfs(i,-1);
			}
		}
		cout<<ans.size()<<nl;
		for(auto a:ans)
		{
			cout<<a<<" ";
		}
	}
	return 0;
}
