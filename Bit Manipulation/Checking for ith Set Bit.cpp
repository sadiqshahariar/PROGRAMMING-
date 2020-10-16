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
	int t;
	cin>>t;
	while(t--)
	{
		int i,n,f=1;
		cin>>n>>i;
		i--;
		f=f<<i;
		int ans=f&n;
		if(ans==0)cout<<"false"<<nl;
		else cout<<"true"<<nl;
	}
	return 0;
}
