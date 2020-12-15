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

int binsearch(int ar[],int l,int r,int x)
{
    int ans=-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(ar[mid]==x)
        {
            ans=mid;
            break;
        }
        else if(ar[mid]<x)l=mid+1;
        else r=mid-1;
    }
    return ans;
}

int findpos(int ar[],int x)
{
    int l=0,r=1;
    int val=ar[0];
    while(val<x)
    {
        l=r;
        r=2*r;
        val=ar[r];
    }
    //cout<<l<<" "<<r<<nl;
    int ans = binsearch(ar,l,r,x);
    //cout<<ans<<nl;
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int i,ar[n+4];
    for(i=0;i<n;i++)cin>>ar[i];
    int x;
    cin>>x;
    int ans=findpos(ar,x);
    if(ans==-1)cout<<"Element is not found"<<nl;
    else cout<<"Element found at index "<<ans<<nl;
    return 0;
}
