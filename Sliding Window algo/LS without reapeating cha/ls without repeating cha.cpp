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

ll solve(string s)
{
    ll ans=0;
    int i=0,j=0;
    map<char,int>mp;
    while(j<s.size())
    {
        mp[s[j]]++;
        if(mp.size()==(j-i+1))
        {
            ll z=j-i+1;
            ans=max(ans,z);
            j++;
        }
        else{
            while(mp.size()<(j-i+1))
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int k;
        ll ans=solve(s);
        cout<<ans<<nl;
    }
    return 0;
}

