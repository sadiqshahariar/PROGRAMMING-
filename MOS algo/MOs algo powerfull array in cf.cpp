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

ll power(ll base,ll n)
{
	ll result=1;
	while(n)
	{
		if(n%2==1)
		{
			result*=base;
			n--;
		}
		else {
			base*=base;
			n/=2;
		}
	}
	return result;
}

const ll mx = 2000002;
ll K,ans[mx],a[mx],sum,mp[mx];

struct query
{
    ll index,L,R;

    // uses for sort the query
     bool operator < (const query &other) const {
		ll block_own = L/K;
		ll block_other = other.L/K;
		if(block_own == block_other)
            return R < other.R;
		return block_own < block_other;
	}

}query[mx];


void add(ll index)
{
    ll cnt=mp[a[index]];
    mp[a[index]]++;
    sum-=(cnt*cnt)*a[index];
    cnt++;
    sum+=(cnt*cnt)*a[index];
}

void remove(ll index)
{
    ll cnt=mp[a[index]];
    mp[a[index]]--;
    sum-=(cnt*cnt)*a[index];
    cnt--;
    sum+=(cnt*cnt)*a[index];
}

int main()
{
    faster
    ll n,q;
    cin>>n>>q;
    for(ll i=0;i<n;i++)cin>>a[i];
    K=sqrt(n);

    //cin>>q;
    for(ll i=0;i<q;i++)
    {
        cin>>query[i].L>>query[i].R;
        --query[i].L;
        --query[i].R;
        query[i].index=i;
    }

    sort(query,query+q);

    ll L=0,R=-1;

    for(ll i=0;i<q;i++)
    {
        while(R<query[i].R)add(++R);
        while(L<query[i].L)remove(L++);
        while(R>query[i].R)remove(R--);
        while(L>query[i].L)add(--L);
        ans[query[i].index]=sum;
        //cout<<sum<<nl;
    }
    for(ll i=0;i<q;i++)cout<<ans[i]<<nl;
    return 0;
}
