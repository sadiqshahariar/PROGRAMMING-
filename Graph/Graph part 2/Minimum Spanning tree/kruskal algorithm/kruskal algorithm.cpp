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

struct edge{
	int a,b,w;
};
edge ar[100006];
int par[10006];
bool comp(edge a,edge b)
{
	if(a.w<b.w)return true;
	else return false;
}
void unions(int a,int b)
{
	par[a]=b;
}
int finds(int a)
{
	if(par[a]==-1)return a;
	return finds(par[a]);
}
int main()
{
	faster
	int n,m,a,b,w;
	cin>>n>>m;
	for(int i=1;i<=n;i++)par[i]=-1;
	for(int i=0;i<m;i++)
	{
		cin>>ar[i].a>>ar[i].b>>ar[i].w;
	}
	sort(ar,ar+m,comp);
	int ans=0;
	for(int i=0;i<m;i++)
	{
		a=finds(ar[i].a);
		b=finds(ar[i].b);
		if(a!=b)
		{
			ans+=ar[i].w;
			unions(a,b);
		}
	}
	cout<<ans<<nl;
	return 0;

}
