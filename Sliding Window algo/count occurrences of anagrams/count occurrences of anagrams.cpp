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

int cnt=0;
void solve(string s,string a)
{
    int sum=0,sum1=0;
    int i,j;
    for(i=0;i<a.size();i++)
    {
        sum+=a[i]-'a';
    }
    for(i=0;i<a.size();i++)
    {
        sum1+=s[i]-'a';
    }
    if(sum1==sum)cnt++;
    i=0;
    j=a.size();
    while(j<s.size())
    {
        sum1+=s[j]-'a';
        sum1-=s[i]-'a';
        if(sum1==sum)cnt++;
        i++;
        j++;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s,a;
        cin>>s>>a;
        cnt=0;
        solve(s,a);
        cout<<cnt<<nl;
    }
    return 0;
}
