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

// PRIME NUMBER TEST//
bool prime(int n)
{
    if(n<2)return false;
    if(n<=3)return true;
    if(n%2==0)return false;
    for(int i=3;i*i<=n;i+=2)
    {
        if(n%i==0)return false;
    }
    return true;
}

// Graph Grid //
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

ll dp[1000005];
ll inv[1000005];

ll power(ll a,ll n)
{
    ll r=1;
    while(n)
    {
        if(n&1)r=(r*a)%mod;
        n>>=1;
        a=(a*a)%mod;
    }
    return r;
}

void solve(string s)
{
    ll p=31;
    ll pow=1;
    dp[0]=s[0]-'a' + 1;
    inv[0]=1;
    for(int i=1;i<s.size();i++)
    {
        char ch=s[i];
        pow=(pow*p)%mod;
        inv[i]=power(pow,mod-2);
        dp[i]=(dp[i-1] + (ch-'a' + 1)*pow)%mod;
    }
}

ll substringhash(ll l,ll r)
{
    ll result = dp[r];
    if(l>0)result-=dp[l-1];
    result = (result*inv[l])%mod;
    return result;
}

int main()
{
    string s;
    cin>>s;
    ll q,l,r;
    solve(s);
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        cout<<substringhash(l,r)<<endl;
    }
}
