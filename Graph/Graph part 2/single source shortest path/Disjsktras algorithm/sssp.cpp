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

vector< pair<int,int> >v[1001];

int main()
{
	int n,m,a,b,w,i;
	cin>>n>>m;
	while(m--)
	{
		cin>>a>>b>>w;
		v[a].push_back({b,w});
		v[b].push_back({a,w});
	}
	priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> > >pq;
	vector<int>dist(n+1, INT_MAX);
	pq.push({0,1});
	dist[1]=0;
	while(!pq.empty())
	{
		int curr=pq.top().second;
		int curr_d=pq.top().first;
		pq.pop();
		for(pair<int,int>edge: v[curr])
		{
			if(curr_d+edge.second<dist[edge.first])
			{
				dist[edge.first]=curr_d+edge.second;
				pq.push({dist[edge.first],edge.first});
			}
		}
	}
	for(i=1;i<=n;i++)cout<<dist[i]<<" ";
	cout<<nl;
	return 0;
}
