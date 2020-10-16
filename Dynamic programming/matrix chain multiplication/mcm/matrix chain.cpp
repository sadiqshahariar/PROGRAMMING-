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

//int mn=INT_MAX;
int matrixchain(int ar[],int i,int j)
{
	if(i>=j)return 0;
	int k;
	int mn=INT_MAX;
	int cnt;
	for(k=i;k<j;k++)
	{
		cnt=matrixchain(ar,i,k)+matrixchain(ar,k+1,j)+(ar[i-1]*ar[k]*ar[j]);
		if(cnt<mn)mn=cnt;
	}
	return mn;
}

int main()
{
	faster
	int n;
	cin>>n;
	int ar[n+1],i,j;
	for(i=0;i<n;i++)cin>>ar[i];
	cout<<matrixchain(ar,1,n-1)<<nl;
	return 0;
}
