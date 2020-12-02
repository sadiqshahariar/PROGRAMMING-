#include<bits/stdc++.h>
using  namespace  std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null _type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define sq(x)   (x)*(x)
#define PI      acos(-1.0)
#define all (x) x.begin(),x.end()
#define nl      '\n'
 #define mod 1000000007
typedef long long int ll ;
typedef unsigned long long int  llu;

ll countDivisors(ll n)
{
    ll cnt = 0;
    for (ll i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // If divisors are equal,
            // count only one
            if (n / i == i)
                cnt++;

            else // Otherwise count both
                cnt = cnt + 2;
        }
    }
    return cnt;
}

int main()
{
	ll  t;
	cin>>t;
	while(t--)
	{
		ll  a,b,ans,div,mx=0;
		cin>>a>>b;
		for(ll  i=a;i<=b;i++)
		{
            ll  x=countDivisors(i);
            //cout<<i<<" "<<x<<nl;
            if(x>mx)
            {
                ans=i;
                //div=x;
                mx=max(x,mx);
            }
		}
		cout<<"Between "<<a<<" and "<<b<<", "<<ans<<" has a maximum of "<<mx<<" divisors."<<nl;
	}
	return 0;
}
