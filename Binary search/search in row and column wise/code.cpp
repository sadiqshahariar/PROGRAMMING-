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

int n,m;
int ar[1000][1000];

void binsearch(int x)
{
    int l,r;
    l=0,r=m-1;
    while(l>=0&&l<m&&r<m&&r>=0)
    {
        if(ar[l][r]==x)
        {
            cout<<"The position is "<<l<<" "<<r<<nl;
            return;
        }
        else if(ar[l][r]>x)r--;
        else l++;
    }
    cout<<"The number is not found"<<nl;
    return;
}

int main()
{
    cin>>n>>m;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)cin>>ar[i][j];
    }
    int x;
    cin>>x;
    binsearch(x);
}
