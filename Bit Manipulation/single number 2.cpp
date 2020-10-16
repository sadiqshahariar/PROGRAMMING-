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


int main()
{
	//problem link: https://leetcode.com/problems/single-number-ii/
	int n;
	cin>>n;
	int ar[n];
	int i;
	map<int,int>m;
        //int i;
        for(i=0;i<n;i++)
        {
        	cin>>ar[i];
            m[ar[i]]++;
        }
        int ans;
        for(auto it: m)
        {
        	//cout<<it.first<<" "<<it.second<<nl;
            if(it.second!=3)ans=it.first;
        }
      cout<<ans<<nl;

}
