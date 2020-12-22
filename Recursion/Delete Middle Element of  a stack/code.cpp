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

void solve(stack<int>&st,int x)
{
    if(st.size()==x)
    {
        st.pop();
        return ;
    }
    int z=st.top();
    st.pop();
    solve(st,x);
    st.push(z);
}

void print(stack<int>v)
{
    if(v.empty())return;
    int x=v.top();
    v.pop();
    print(v);
    cout<<x<<" ";
}

void deletemid(stack<int>&st, int n)
{
    if(n==0)
    {
        return;
    }
    int x=(n/2)+1;
    //if(n%2==0)x--;
    solve(st,x);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<nl;
}

int main()
{
    while(1)
    {
        int n;
        cin>>n;
        stack<int>st;
        int x,i;
        for(i=0;i<n;i++)
        {
            cin>>x;
            st.push(x);
        }
        deletemid(st,n);
    }
    return 0;
}
