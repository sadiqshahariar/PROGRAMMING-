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

typedef long long int ll;
typedef unsigned long long int  llu;


int main()
{
       // problem link: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
        int a,b,c;
        cin>>a>>b>>c;
        int i,j;
        int ans=0;
        for(i=0;i<31;i++)
        {
                    int x,y,z;
                    if(a&(1<<i))x=1;
                    else x=0;
                    if(b&(1<<i))y=1;
                    else y=0;
                    if(c&(1<<i))z=1;
                    else z=0;
                    cout<<x<<" "<<y<<" "<<z<<nl;
                    if((x|y)!=z)
                    {
                            if(z==1)ans+=1;
                    else
                    {
                            if(x==1)ans+=1;
                            if(y==1)ans+=1;
                    }
                }
                cout<<x<<" "<<y<<" "<<z<<" "<<ans<<nl;
            }
            cout<<ans<<nl;

}
