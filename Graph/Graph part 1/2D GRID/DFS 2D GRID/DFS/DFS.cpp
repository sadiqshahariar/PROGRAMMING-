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
int vis[1001][1001];
bool isvalid(int x,int y)
{
	if(x<1||x>n||y<1||y>m)return false;
	if(vis[x][y]==1)return false;
	return true;
}
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
void dfs(int x,int y)
{
	vis[x][y]=1;
	cout<<x<<" "<<y<<nl;
	for(int i=0;i<4;i++)
	{
		if(isvalid(x+dx[i],y+dy[i]))
		{
			dfs(x+dx[i],y+dy[i]);
		}
	}
}

int main()
{
	cin>>n>>m;
	dfs(1,1);
	return 0;
}
