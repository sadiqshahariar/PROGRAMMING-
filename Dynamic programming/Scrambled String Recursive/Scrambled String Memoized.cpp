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
unordered_map<string,bool>mp;
bool isscramble(string a,string b)
{
	if(a.length()!=b.length())
	{
		return false;
	}
	int n=a.length();
	if(n==0)return true;
	if(a==b)return true;
	string x=a,y=b;
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	if(x!=y)return false;
	string l=a;
	l.append(b);
	if(mp.find(l)!=mp.end())
	{
		return mp[l];
	}
	for(int i=1;i<n;i++)
	{
		if(isscramble(a.substr(0,i),b.substr(0,i))&&isscramble(a.substr(i,n-i),b.substr(i,n-1)))
		{
			return mp[l]=true;
		}
		if(isscramble(a.substr(0,i),b.substr(n-i,i))&&isscramble(a.substr(i,n-i),b.substr(0,n-i)))
		{
			return mp[l]=true;
		}
	}
	return mp[l]=false;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		mp.clear();
		string a,b;
		cin>>a>>b;
		if(isscramble(a,b))
		{
			cout<<"Yes"<<nl;
		}
		else
		{
			cout<<"No"<<nl;
		}
	}
	return 0;
}

