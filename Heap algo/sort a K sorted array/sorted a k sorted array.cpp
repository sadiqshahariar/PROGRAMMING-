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

priority_queue<int,vector<int>,greater<int> >pq;
vector<int>v;

void largestelement(int ar[],int n,int k)
{
    int i;
    for(i=0;i<n;i++)
    {
        pq.push(ar[i]);
        if(pq.size()>k)
        {
            v.push_back(pq.top());
            pq.pop();
        }
    }
    while(!pq.empty())
    {
        v.push_back(pq.top());
        pq.pop();
    }
}

void print()
{
    for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
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
    largestelement(ar,n,k);
    print();
    return 0;
}
