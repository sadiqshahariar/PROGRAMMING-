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
    map<int,int>mp;
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
        mp[ar[i]]++;
    }
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
    vector<int>v;
    for(pair<int,int>p:mp)
    {
        pq.push({p.second,p.first});
    }
    while(!pq.empty())
    {
        for(i=1;i<=pq.top().first;i++)
        {
            v.push_back(pq.top().second);
        }
        pq.pop();
    }
    for(i=v.size()-1;i>=0;i--)cout<<v[i]<<" ";
    cout<<nl;
    return 0;
}
