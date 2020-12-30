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

priority_queue< pair<int,int> >pq;

void closestnumber(int ar[],int n,int k,int z)
{
    for(int i=0;i<n;i++)
    {
        int x=abs(k-ar[i]);
        pq.push({x,ar[i]});
        if(pq.size()>z)pq.pop();
    }
}

void print()
{
    while(!pq.empty())
    {
        cout<<pq.top().second<<" ";
        pq.pop();
    }
    cout<<nl;
}

int main()
{
    int n;
    cin>>n;
    int i,ar[n+3];
    for(i=0;i<n;i++)cin>>ar[i];
    int k;
    cin>>k;
    int z;
    cin>>z;
    closestnumber(ar,n,k,z);
    print();
}
