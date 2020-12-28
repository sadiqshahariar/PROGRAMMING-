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

stack<int>s;
stack<int>ss;

int getmin()
{
    if(ss.size()==0)return -1;
    return ss.top();
}
void push(int a)
{
    s.push(a);
    if(ss.size()==0)ss.push(a);
    else{
        if(ss.top()>=a)ss.push(a);
    }
}
int pop()
{
    if(s.size()==0)return -1;
    int ans=s.top();
    if(ss.top()==ans)ss.pop();
    return getmin();
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        push(x);
    }
    int q;
    cin>>q;
    while(q--)
    {
        ll ans=pop();
        cout<<ans<<nl;
    }
    return 0;
}
