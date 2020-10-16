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
			if(a[i-1]==b[j-1])T[i][j]=1+T[i-1][j-1];
			else{
				T[i][j]=max(T[i-1][j],T[i][j-1]);
			}
		}
	}
	string s="";
	while(n!=0&&m!=0)
	{
		if(a[n-1]==b[m-1])
		{
			s+=a[n-1];
			n-=1;
			m-=1;
		}
		else{
			if(T[n-1][m]>T[n][m-1])
			{
				n-=1;
			}
			else{
				m-=1;
			}
		}
	}
	reverse(s.begin(),s.end());
	cout<<s<<nl;
}

int main()
{
	//faster
	int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		LCM(a,b,a.length(),b.length());
	}
	return 0;
}

