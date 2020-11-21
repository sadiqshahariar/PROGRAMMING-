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
int par[100001];
int finds(int a)
{
	if(par[a]<0)return a;
	else{
		return par[a]=finds(par[a]);
	}
}
int unions(int a,int b)
{
	par[a]=min(par[a],par[b]);
	par[b]=a;
}
int main()
{
	int n,m,x,y,a,b,i,q;
	cin>>n>>m;
	for(i=1;i<=n;i++)par[i]=-i;
	for(i=1;i<=m;i++)
	{
		cin>>a>>b;
		a=finds(a);
		b=finds(b);
		if(a!=b)unions(a,b);
	}
	cin>>q;
	while(q--)
	{
		cin>>x>>y;
		a=x,b=y;
		a=finds(a);
		b=finds(b);
		if(a==b)cout<<"TIE"<<nl;
		else{
			if(par[a]<par[b])
			{
				cout<<x<<nl;
			}
			else cout<<y<<nl;
		}
	}
	return 0;
}
