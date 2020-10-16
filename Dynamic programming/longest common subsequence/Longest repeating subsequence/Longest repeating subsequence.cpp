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

int LCM(string a,string b,int n,int m)
{
	int i,j;
	int T[n+1][m+1];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0||j==0)T[i][j]=0;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			//if(i==0||j==0)T[i][j]=0;
			if(a[i-1]==b[j-1] && i!=j)T[i][j]=1+T[i-1][j-1];
			else{
				T[i][j]=max(T[i-1][j],T[i][j-1]);
			}
		}
	}
	return T[n][m];

}

int main()
{
	//faster
	int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a;
		b=a;
		cout<<LCM(a,b,a.length(),b.length())<<nl;
	}
	return 0;
}

