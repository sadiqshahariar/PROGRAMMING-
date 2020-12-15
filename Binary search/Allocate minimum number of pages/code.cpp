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

bool ispossible(int ar[],int n,int k,int cmin)
{
    int student=1;
    int csum=0;

    for(int i=0;i<n;i++)
    {
        if(ar[i]>cmin)return false;
        if(csum+ar[i]>cmin)
        {
            student++;
            csum=ar[i];
            if(student>k)return false;
        }
        else csum+=ar[i];
    }
    return true;
}

int findpages(int ar[],int n,int k,int sum)
{
    if(n<k)return -1;

    int l=0,r=sum;
    int result=INT_MAX;

    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(ispossible(ar,n,k,mid))
        {
            result=min(result,mid);
            r=mid-1;
        }
        else l=mid+1;
    }
    return result;
}

int main()
{
    int n;
    cin>>n;
    int i,ar[n+3];
    int sum=0;
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
        sum+=ar[i];
    }
    int k;
    cin>>k;
    int ans=findpages(ar,n,k,sum);
    cout<<ans<<nl;
    return 0;
}
