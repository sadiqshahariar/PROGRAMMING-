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
 #define mod 1000000007
typedef long long int ll;
typedef unsigned long long int  llu;
int P[100001],R[100001];

int finds(int a)
{
	if(P[a]==-1)return a;
	return P[a]=finds(P[a]);
}
void marge(int a,int b)
{
	a=finds(a);
	b=finds(b);
	if(a==b)return;

	if(R[a]>R[b])
	{
		P[b]=a;
		R[a]+=R[b];
	}
	else{
		P[a]=b;
		R[b]+=R[a];
	}
}
int main()
{
	int n,m,u,v;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		P[i]=-1;
		R[i]=1;
	}
	while(m--)
	{
		cin>>u>>v;
		marge(u,v);
	}
	for(int i=1;i<=n;i++)
	{
		int x=finds(i);
		cout<<R[x]-1<<" ";
	}
	cout<<nl;
	return 0;
}
