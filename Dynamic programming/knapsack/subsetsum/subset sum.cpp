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

bool subsetsum(int ar[],int n,int sum)
{
	if(sum==0)return true;
	if(n==0)return false;
	if(ar[n-1]>sum)return subsetsum(ar,n-1,sum);
	else{
		return subsetsum(ar,n-1,sum)||subsetsum(ar,n-1,sum-ar[n-1]);
	}
}

int main()
{
	faster
	int n;
	cin>>n;
	int ar[n+1],i,j,sum;
	for(i=0;i<n;i++)cin>>ar[i];
	cin>>sum;
	bool x;
	x=subsetsum(ar,n,sum);
	if(x==true)cout<<"Yes"<<nl;
	else cout<<"No"<<nl;
	return 0;

}
