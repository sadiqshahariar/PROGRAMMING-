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

void inserts(vector<int>&v,int temp)
{
    if(v.size()==0||v[v.size()-1]<=temp)
    {
        v.push_back(temp);
        return;
    }
    int val=v[v.size()-1];
    v.pop_back();
    inserts(v,temp);
    v.push_back(val);
    cout<<val<<" ";
}

void sorts(vector<int>&v)
{
    if(v.size()==1)
    {
        return;
    }
    int temp=v[v.size()-1];
    v.pop_back();
    sorts(v);
    inserts(v,temp);
    cout<<nl;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    sorts(v);
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<nl;
    return 0;
}
