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
map<int,int>mp;
void primefactor(int a)
{
	for(int i=2;i*i<=a;i+=2)
	{
		int cnt=0;
		while(a%i==0)
		{
			cnt++;
			a/=i;
		}
		mp[i]=cnt;
	}
	if(a>1)mp[a]=1;
}
int comdiv(int a,int b)
{
	mp.clear();
	primefactor(a);
	int res=1;
	for(auto m:mp)
	{
		int cnt=0;
		int x=m.first;
		int y=m.second;
		while(b%x==0)
		{
			cnt++;
			b/=x;
		}
		res*=(min(cnt,y)+1);
	}
	return res;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		cout<<comdiv(a,b)<<nl;
	}
	return 0;
}
