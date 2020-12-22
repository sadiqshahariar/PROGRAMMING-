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

void solve(int o,int z,int n,string op)
{
    if(n==0)
    {
        cout<<op<<" ";
        return;
    }
    if(o==z)
    {
        string op1=op;
        op1+='1';
        o++;
        n--;
        solve(o,z,n,op1);
    }
    else{
        string op1=op;
        string op2=op;
        op1+='1';
        op2+='0';
        solve(o+1,z,n-1,op1);
        solve(o,z+1,n-1,op2);
    }
}

int main()
{
    while(1)
    {
        int n;
        cin>>n;
        int z=0,o=0;
        string op="";
        solve(o,z,n,op);
        cout<<nl;
    }
}
