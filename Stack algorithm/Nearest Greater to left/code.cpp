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

void solve(int ar[],int n)
{
    int i;
    stack<int>st;
    for(i=0;i<=n;i++)
    {
       int ans=-1;
       while(!st.empty())
       {
           int x=st.top();
           if(x>ar[i])
           {
               ans=x;
               break;
           }
           st.pop();
       }
       v.push_back(ans);
       st.push(ar[i]);
    }
}

void print()
{
    int i;
    for(i=0;i<v.size();i++)cout<<v[i]<<" ";
    cout<<nl;
}

int main()
{
    int n;
    cin>>n;
    int ar[n+2],i;
    for(i=0;i<n;i++)cin>>ar[i];
    solve(ar,n-1);
    print();
    return 0;
}
