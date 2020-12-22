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

ll cnt;

void towerofhanio(int n,char a,char b,char c)
{
    cnt++;
    if(n==1)
    {
        cout<<"Move disk 1 from rod "<<a<<" to rod "<<b<<nl;
        return ;
    }
    towerofhanio(n-1,a,c,b);
    cout<<"Move disk "<<n<<" from rod "<<a<<" to rod "<<b<<nl;
    towerofhanio(n-1,c,b,c);
}

int main()
{
    while(1)
    {
        cnt=0;
        int n;
        cin>>n;
        int a,b,c;
        towerofhanio(n,'A','B','C');
        cout<<nl;
        cout<<cnt<<nl;
    }
}
