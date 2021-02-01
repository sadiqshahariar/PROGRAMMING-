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

void selectionsort(int ar[], int n)
{
    int i,j,mn;
    for(i=0;i<n;i++)
    {
        mn=i;
        for(j=i+1;j<n;j++)
        {
            if(ar[j]<ar[mn])
            {
                mn=j;
            }
        }
        swap(ar[i],ar[mn]);
    }
}

void print(int ar[], int n)
{
    for(int i=0;i<n;i++)cout<<ar[i]<<" ";

    cout<<nl;
}

int main()
{
    while(1)
    {
        int n;
        cin>>n;
        int i,ar[n+3];
        for(i=0;i<n;i++)cin>>ar[i];
        selectionsort(ar,n);
        print(ar,n);
    }
}
