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
    int n;
    cin>>n;
    int i,ar[n+3];
    for(i=0;i<n;i++)cin>>ar[i];
    cout<<fixed<<setprecision(1);
    vector<int>v;
    int k;
    cin>>k;
    for(i=0;i<k;i++)
    {
        v.push_back(ar[i]);
    }
    sort(v.begin(),v.end());
    if(k%2==0)
    {
        cout<<(v[k/2]+v[k/2-1])*(.5)<<" ";
    }
    else cout<<v[k/2]<<" ";

    for(i=k;i<n;i++)
    {
        v.clear();
        for(int j=i-k+1;j<=i;j++)
        {
            v.push_back(ar[j]);
        }
        sort(v.begin(),v.end());
        if(k%2==0)
        {
            cout<<(v[k/2]+v[k/2-1])*(.5)<<" ";
        }
        else cout<<v[k/2]<<" ";
    }
    return 0;
}
