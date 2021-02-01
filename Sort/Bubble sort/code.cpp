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

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubblesort(int ar[], int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(ar[j]>ar[j+1]);
            {
                swap(ar[j],ar[j+1]);
            }
        }
        for(int k=0;k<n;k++)cout<<ar[k]<<" ";
        cout<<nl;
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
        bubblesort(ar,n);
        print(ar,n);
    }
}
