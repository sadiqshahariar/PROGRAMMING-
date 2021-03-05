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

// PRIME NUMBER TEST//
bool prime(int n)
{
    if(n<2)return false;
    if(n<=3)return true;
    if(n%2==0)return false;
    for(int i=3;i*i<=n;i+=2)
    {
        if(n%i==0)return false;
    }
    return true;
}

string solve(string a,string b)
{
    if(a.length()>b.length())
    {
        swap(a,b);
    }
    string ans="";
    int n1=a.length(),n2=b.length();
    int dif=n2-n1;
    int carry = 0;
    for(int i=n1-1;i>=0;i--)
    {
        int sum=((a[i]-'0')+(b[i+dif]-'0')+carry);
        ans.push_back(sum%10+'0');
        carry =sum/10;
    }
    for(int i=n2-n1-1;i>=0;i--)
    {
        int sum=((b[i]-'0')+carry);
        ans.push_back(sum%10 + '0');
        carry =sum/10;
    }
    if(carry)
    {
        ans.push_back(carry+'0');
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    string a,b;
    while(cin>>a>>b)
    {
        cout<<solve(a,b)<<nl;
    }
    return 0;
}
