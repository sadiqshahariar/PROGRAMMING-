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

string s,x;
bool match(int i,int n)
{
    string p;
    for(int j=i;j<n;j++)
    {
        p+=s[j];
    }
    if(p==x)return true;
    return false;
}
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        //string s;
        getline(cin,s);
        //string x;
        cin>>x;
        //cout<<s<<nl<<x<<nl;
        for(int i=0;i<s.size()-x.size()+1;i++)
        {
            //string ss="";
            bool ss=match(i,i+x.size());
            if(ss)cout<<i<<" ";
        }
        cout<<nl;
    }
    return 0;
}
