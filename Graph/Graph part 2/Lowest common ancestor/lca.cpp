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

vector<int>v[1001];
const int maxn=10;
int level[1001],LCA[1001][maxn+1];

void dfs(int node,int lev,int par)
{
	level[node]=lev;
	LCA[node][0]=par;
	for(int child:v[node])
	{
		if(child!=par)
		{
			dfs(child,lev+1,node);
		}
	}
}
void init(int n)
{
	dfs(1,0,-1);
	for(int i=1;i<=maxn;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(LCA[j][i-1]!=-1)
			{
				int par=LCA[j][i-1];
				LCA[j][i]=LCA[par][i-1];
			}
		}
	}
}
int getLCA(int a,int b)
{
	if(level[b]<level[a])swap(a,b);
	int d=level[b]-level[a];
	while(d>0)
	{
		int i=log2(d);
		b=LCA[b][i];
		d-=1<<i;
	}
	if(a==b)return a;
	for(int i=maxn;i>=0;i--)
	{
		if(LCA[a][i]!=-1&&(LCA[a][i]!=LCA[b][i]))
		{
			a=LCA[a][i],b=LCA[b][i];
		}
	}
	return LCA[a][0];
}
int main()
{
	int n,a,b,q,i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=maxn;j++)
		{
			LCA[i][j]=-1;
		}
	}
	for(i=1;i<n;i++)

	{
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	init(n);
	//int q;
	cin>>q;
	while(q--)
	{
		cin>>a>>b;
		cout<<getLCA(a,b)<<nl;
	}
	return 0;
}
