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

ll dp[1000001];
ll inv[1000001];

ll power(ll a,ll n)
{
    cout<<"power"<<nl;
    ll result=1;
    while(n)
    {
        if(n&1)result=(result*a)%mod;
        n>>=1;
        a=(a*a)%mod;
    }
    return result;
}

void gethash(string s)
{
    cout<<"gethash"<<nl;
    //ll ans=1;
    ll p=31;
    ll po=1;
    inv[0]=1;
    dp[0]=(s[0]-'a'+1);
    for(int i=1;i<s.size();i++)
    {
        char ch=s[i];
        po=(po*p)%mod;
        inv[i]=power(po,mod-2);
        dp[i]=(dp[i-1] + (ch-'a'+1)*po)%mod;
    }
}

ll subhash(int L,int R)
{
    cout<<"subhash"<<nl;
    int result=dp[R];
    if(L>0)result-=dp[L-1];
    result=(result*inv[L])%mod;
    return result;
}

int main()
{
    string s;
    cin>>s;
    int q,L,R;
    gethash(s);
    cin>>q;
    while(q--)
    {
        cin>>L>>R;
        cout<<subhash(L,R)<<nl;
    }
    return 0;
}

