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
unordered_map<string,int>m;
int solve(string s,int i,int j,bool istrue)
{
	if(i>j)return 0;
	if(i==j)
	{
		if(istrue==true)
		{
			if(s[i]=='T')return 1;
			else return 0;
		}
		else
		{
			if(s[i]=='F')return 1;
			else return 0;
		}
	}
	string temp=to_string(i);
	//temp.push_back(" ");
	temp.append(to_string(j));
	//temp.push_back(" ");
	temp.append(to_string(istrue));
	if(m.find(temp)!=m.end())
	{
		return m[temp];
	}
	int lt,lf,rt,rf;
	int ans=0;
	for(int k=i+1;k<j;k+=2)
	{
		lt=solve(s,i,k-1,true);
		lf=solve(s,i,k-1,false);
		rt=solve(s,k+1,j,true);
		rf=solve(s,k+1,j,false);
		if(s[k]=='&')
		{
			if(istrue==true)
			{
				ans+=lt*rt;
			}
			else
			{
				ans+=lt*rf+lf*rt+lf*rf;
			}
		}
		else if(s[k]=='|')
		{
			if(istrue==true)
			{
				ans+=lt*rt+lt*rf+lf*rt;
			}
			else ans+=lf*rf;
		}
		else
		{
			if(istrue==true)
			{
				ans+=lt*rf+rt*lf;
			}
			else
			{
				ans+=lt*rt+lf*rf;
			}
		}
	}
	return m[temp]=ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		m.clear();
		string s;
		cin>>s;
		cout<<solve(s,0,s.size()-1,true)<<nl;
	}
	return 0;
}
