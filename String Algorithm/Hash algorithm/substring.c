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

int main()
{
    string s,t;
    cin>>s>>t;
    ll n=s.size();
    ll m=t.size();

    ll ar[n+4];
    ar[0]=0;
    ll val=0;
    ll prime=7;
    for(ll i=0;i<n;i++)
    {
        ar[i+1]=(((ar[i]*prime)%mod)+s[i])%mod;
    }


    for(ll i=0;i<m;i++)val=(((val*prime)%mod)+t[i])%mod;
    //cout<<val<<endl;


    ll val2=1;
    for(ll i=1;i<=m;i++)val2=(prime*val2)%mod;

    //cout<<"hi "<<val2<<endl;

    ll cnt=0;

    for(ll i=m;i<=n;i++)
    {
        ll ans=ar[i];
        ll ans1=ar[i-m];
        ans1=(ans1*val2)%mod;
        ans=ans-ans1;
        if(ans<0)ans+=mod;
        if(ans==val)cnt++;
        //cout<<ans<<endl;
    }
    cout<<cnt<<endl;

}
