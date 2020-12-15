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

int bitsearch(int ar[],int l,int r)
{
        int pos=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(ar[mid]>ar[mid-1]&&ar[mid]>ar[mid+1])
            {
                pos=mid;
                break;
            }
            else if(ar[mid]>ar[mid-1])l=mid+1;
            else r=mid-1;
        }
        return pos;
}

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
        else if(ar[mid]>x)
        {
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}

int rbinsearch(int ar[],int l,int r,int x)
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
        else if(ar[mid]>x)
        {
            l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
}
int main()
{
        int n;
        cin>>n;
        int i,ar[n+3];
        for(i=0;i<n;i++)cin>>ar[i];
        int pos=bitsearch(ar,0,n-1);

        int x;
        cin>>x;

        int ans1=binsearch(ar,0,pos,x);
        int ans2=rbinsearch(ar,pos+1,n-1,x);
        cout<<max(ans1,ans2)<<nl;
        return 0;
}

