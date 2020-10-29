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
char ar[31][31];
int vis[31][31];
int n,m;
int dis[31][31];
//int x1,y1;
bool isvalid(int x,int y)
{
	if(x<1||x>8||y<1||y>8)
	{
		return false;
	}
	if(vis[x][y]==1)return false;
	return true;
}
int da[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int db[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int  bfs(int x,int y,int x1,int y1)
{
	queue< pair<int,int> >q;
	vis[x][y]=1;
	dis[x][y]=0;
	q.push({x,y});
	if(x==x1&&y==y1)return dis[x1][y1];
	while(!q.empty())
	{
		int a=q.front().first;
		int b=q.front().second;
		q.pop();
		for(int i=0;i<8;i++)
		{
			if(isvalid(a+da[i],b+db[i]))
			{
				int c=a+da[i];
				int d=b+db[i];
				dis[c][d]=dis[a][b]+1;
				vis[c][d]=1;
				q.push({c,d});
				if(c==x1&&d==y1)return dis[x1][y1];
			}
		}
	}
}
int main()
{
	cin>>n;
	while(n--)
	{
		string a,b;
		cin>>a>>b;
		int x,y,i,j,x1,y1;
		for(i=0;i<=8;i++)
		{
			for(j=0;j<=8;j++)vis[i][j]=0;
		}
		x=a[0]-'a'+1;
		y=a[1]-'0';
		x1=b[0]-'a'+1;
		y1=b[1]-'0';
		//cout<<x<<" "<<y<<" "<<x1<<" "<<y1<<nl;
		cout<<bfs(x,y,x1,y1)<<nl;
	}
	return 0;
}

