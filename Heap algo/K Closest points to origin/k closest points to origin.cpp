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
    int i,ar[n+3][4];
    for(i=0;i<n;i++)
    {
        cin>>ar[i][0]>>ar[i][1];
    }
    int k;
    cin>>k;
    priority_queue<pair<int,pair<int,int> > >pq;
    for(i=0;i<n;i++)
    {
        int x=ar[i][0]*ar[i][0] + ar[i][1]*ar[i][1];
        pq.push({x,{ar[i][0],ar[i][1]}});
        if(pq.size()>k)pq.pop();
    }
    while(!pq.empty())
    {
        pair<int,int>p=pq.top().second;
        cout<<p.first<<" "<<p.second<<nl;
        pq.pop();
    }
    return 0;
}
