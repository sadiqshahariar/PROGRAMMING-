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

vector<int>v;
void solve(int ar[],int n,int sz)
{
    priority_queue<pair<int,int> >pq;
    int i,j;
    for(i=0;i<sz;i++)
    {
        pq.push({ar[i],i});
    }
    i=0,j=sz;
    while(j<=n)
    {
        v.push_back(pq.top().first);
        pq.push({ar[j],j});
        i++;
        j++;
        while(pq.top().second<i)
        {
            pq.pop();
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int ar[n+3],i,sz;
    for(i=0;i<n;i++)cin>>ar[i];
    cin>>sz;
    solve(ar,n,sz);
    cout<<v.size()<<nl;
    for(i=0;i<v.size();i++)cout<<v[i]<<" ";
    cout<<nl;
    return 0;
}
