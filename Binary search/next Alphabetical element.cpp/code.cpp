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

char nextalpha(string s,int l,int r,char ch)
{
    char ans='N';
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(s[mid]<=ch)
        {
            l=mid+1;
        }
        else
        {
            ans=s[mid];
            r=mid-1;
        }
    }
    return ans;
}
int main()
{
    string s;
    cin>>s;
    while(1)
    {
        char ch;
        cin>>ch;
        cout<<nextalpha(s,0,s.size()-1,ch)<<nl;
    }
    return 0;
}
