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

const long long infinity = 1e18;
ll dp[100][100001];
ll knapsack(ll wt[],ll val[],ll w,ll n)
{

        for(int i=0;i<100;i++)
        {
                for(int j=0;j<=100000;j++)dp[i][j]=infinity;
        }

        dp[0][0]=0;
        dp[0][val[0]]=wt[0];

        for(int i=1;i<n;i++)
        {
                dp[i][0]=0;
                for(int j=1;j<=100000;j++)
                {
                        dp[i][j]=dp[i-1][j];
                        if(j>=val[i])
                        {
                                dp[i][j]=min(dp[i][j],wt[i]+dp[i-1][j-val[i]]);
                        }
                }

        }
        for(int i=100000;i>=0;i--)
        {
                if(dp[n-1][i]<=w)return i;
        }
}

int main()
{
    ll s,n;
    cin>>n>>s;
    ll wt[n+3],val[n+3];
    ll sum=0;
    for(int i=0;i<n;i++)
    {
            ll x,y;
            cin>>x>>y;
            wt[i]=x;
            val[i]=y;
            sum+=y;
    }
    ll ans=knapsack(wt,val,s,n);
    cout<<ans<<endl;
}

