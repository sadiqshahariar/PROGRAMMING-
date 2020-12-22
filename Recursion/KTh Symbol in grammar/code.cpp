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

bool solve(int n,int k)
{
    if(n==1&&k==1)
    {
        return false;
    }


    int mid=(pow(2,n-1))/2;
    if(k<=mid)
    {
        return solve(n-1,k);
    }
    else
    {
        return !solve(n-1,k-mid);
    }
}

int main()
{
    while(1)
    {
        int n,k;
        cin>>n>>k;
        bool ans=solve(n,k);
        cout<<ans<<nl;
    }
    return 0;
}
