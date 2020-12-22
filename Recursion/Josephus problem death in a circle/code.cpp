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

void solve(vector<int>&v,int ind,int k)
{
    if(v.size()==1)
    {
        cout<<v[0]<<nl;
        return;
    }
    ind=(ind+k)%v.size();
    v.erase(v.begin()+ind);
    solve(v,ind,k);
}

int main()
{
    while(1)
    {
        int n,k;
        cin>>n>>k;
        vector<int>v;
        for(int i=1;i<=n;i++)
        {
            v.push_back(i);
        }
        int ind=0;
        k--;
        solve(v,ind,k);


    }
}
