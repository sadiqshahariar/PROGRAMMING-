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
int mp[10001];
vector<int>v[10001];
vector<int>ans;
void dfs(int n)
{
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		if(mp[i]==0)q.push(i);
	}
	while(!q.empty())
	{
		int cun=q.front();
		q.pop();
		ans.push_back(cun);
		for(int child: v[cun])
		{
			mp[child]--;
			if(mp[child]==0)
			{
				q.push(child);
			}
		}
	}
	cout<<"The topsort is: "<<nl;
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<nl;
}
int main()
{
	int n,m,x,y,i;
	cin>>n>>m;
	while(m--)
	{
		cin>>x>>y;
		v[x].push_back(y);
		mp[y]++;
	}
	dfs(n);
}
