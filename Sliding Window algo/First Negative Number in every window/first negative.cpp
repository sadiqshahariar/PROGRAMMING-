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
    queue<int>q;
    for(int i=0;i<sz;i++)
    {
        if(ar[i]<0)q.push(ar[i]);
    }
    int i=0,j=sz;
    while(j<=n)
    {
        if(q.empty())
        {
            v.push_back(0);
        }
        else{
            v.push_back(q.front());
            if(q.front()==ar[i])q.pop();
        }
        if(ar[j]<0)q.push(ar[j]);
        i++;
        j++;
    }
}

int main()
{
    int n;
    cin>>n;
    int i,ar[n+3];
    for(i=0;i<n;i++)cin>>ar[i];
    int sz;
    cin>>sz;
    solve(ar,n,sz);
    for(i=0;i<v.size();i++)cout<<v[i]<<" ";
    cout<<nl;
    return 0;
}
