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
int vis[10001][10002];
int dis[10001][10001];
vector<int>v[10001];
int n,m;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool isvalid(int x,int y)
{
	if(x<1||x>n||y<1||y>m)return false;
	if(vis[x][y]==1)return false;
	return true;
}
void bfs(int x,int y)
{
	queue< pair<int,int> >q;
	q.push({x,y});
	dis[x][y]=0;
	vis[x][y]=1;
	while(!q.empty())
	{
		int a=q.front().first;
		int b=q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			if(isvalid(a+dx[i],b+dy[i]))
			{
				int c=a+dx[i];
				int d=b+dy[i];
				dis[c][d]=dis[a][b]+1;
				vis[c][d]=1;
				q.push({c,d});
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	bfs(1,1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<dis[i][j]<<" ";
		}
		cout<<nl;
	}
	return 0;
}
