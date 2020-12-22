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

void solve(string s,string op)
{
    if(s.length()==0)
    {
        cout<<op<<" ";
        return;
    }
    string op1=op;
    string op2=op;
    op1.push_back(s[0]);
    op2.push_back(toupper(s[0]));
    s.erase(s.begin()+0);
    solve(s,op1);
    solve(s,op2);
}

int main()
{
    while(1)
    {
        string s;
        cin>>s;
        string op;
        solve(s,op);
        cout<<nl;
    }
}
