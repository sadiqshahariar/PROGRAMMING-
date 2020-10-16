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
int T[1000][1000];

int LCM(string a,string b,int n,int m)
{
	if(n==0||m==0)return 0;
	if(T[n][m]!=-1)return T[n][m];
	if(a[n-1]==b[m-1])
	{
		return T[n][m]=1+LCM(a,b,n-1,m-1);
	}
	else{
		return T[n][m]=max(LCM(a,b,n-1,m),LCM(a,b,n,m-1));
	}
}

int main()
{
	//faster
	int t;
	cin>>t;
	while(t--)
	{
		memset(T,-1,sizeof(T));
		string a,b;
		cin>>a>>b;
		cout<<LCM(a,b,a.length(),b.length())<<nl;
	}
	return 0;
}
