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
int mat[10000];
int fibonacci(int n)
{
	if(n==0)return 0;
	if(n==1)return 1;
	if(mat[n]!=-1)return mat[n];
	mat[n]=fibonacci(n-1)+fibonacci(n-2);
	return mat[n];
}
int main()
{
	faster
	int t;
	cin>>t;
	while(t--)
	{
		memset(mat,-1,sizeof(mat));
		int n;
		cin>>n;
		cout<<fibonacci(n)<<nl;
	}
	return 0;
}
