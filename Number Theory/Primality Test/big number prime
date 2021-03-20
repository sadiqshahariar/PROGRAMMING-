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
 
 
ll mulmod(ll a, ll b,ll c){
	ll x = 0,y=a%c;
	while(b > 0){
		if(b%2 == 1){
			x = (x+y)%c;
		}
		y = (y*2LL)%c;
		b /= 2;
	}
	return x%c;
}
 
ll binPower(ll a , ll n , ll mo)
{
	ll res = 1;
 
	while(n)
	{
		if(n & 1)
		res = mulmod(res , a , mo);
 
		n >>= 1;
		a = mulmod(a , a , mo);
	}
 
	return res % mo;
}
 
bool isPrime(ll n , int iterations = 5)
{
	if(n <= 4)
	return n == 2 || n == 3;
 
	for(int i=1;i<=iterations;i++)
	{
		ll a = 2 + rand() % (n - 3);
		ll res = binPower(a , n - 1 , n);
 
		if(res != 1) return false;
	}
 
	return true;
}
 
int main()
{
	ll t , n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(isPrime(n)) cout<<"YES"<<endl;
		else  cout<<"NO"<<endl;
	}
}
