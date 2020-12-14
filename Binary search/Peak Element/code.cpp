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


int peakelement(int ar[],int l,int r,int n)
{
    int ans=-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(mid>0&&mid<n-1)
        {
            if(ar[mid]>ar[mid-1] && ar[mid]>ar[mid+1])
            {
                ans=mid;
                break;
            }
            else if(ar[mid-1]>ar[mid])
            {
                r=mid-1;
            }
            else l=mid+1;
        }
        else if(mid==0)
        {
            if(ar[0]>ar[1])
            {
                ans=0;
                break;
            }
            else
            {
                ans=1;
                break;
            }
        }
        else
        {
            if(ar[n-1]>ar[n-2])
            {
                ans=n-1;
                break;
            }
            else
            {
                ans=n-2;
                break;
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int ar[n+2];
    for(int i=0;i<n;i++)cin>>ar[i];
    cout<<peakelement(ar,0,n-1,n)<<nl;
    return 0;
}
