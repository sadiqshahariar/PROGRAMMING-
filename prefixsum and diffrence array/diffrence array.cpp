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
vector<ll> initializeDiffArray(vector<ll>& A)
{
	ll n = A.size();
	vector<ll> D(n + 1);

	D[0] = A[0], D[n] = 0;
	for (ll i = 1; i < n; i++)
	D[i] = A[i] - A[i - 1];
	return D;
}


void update(vector<ll>& D, ll l, ll r, ll x)
{
	D[l] += x;
	D[r + 1] -= x;
}


ll prllArray(vector<ll>& A, vector<ll>& D)
{
	ll sum=0;
	for (ll i = 0; i < A.size(); i++) {
	if (i == 0)
	{
		A[i]=D[i];
		sum+=A[i];
	}
	else
	{
		A[i] = D[i] + A[i - 1];
		sum+=A[i];
	}

	 cout << A[i] << " ";
	}
	cout << endl;
	cout<<sum<<nl;
}

// Driver Code
int main()
{
	faster
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll i,x;
		vector<ll>v;
		for(i=0;i<n;i++)
		{
			cin>>x;
			v.push_back(x);
		}
		vector<ll> D = initializeDiffArray(v);
		ll q,a,b,c;
		cin>>q;
		while(q--)
		{
			cin>>a>>b>>c;
			update(D,a-1,b-1,c);
		}
		prllArray(v,D);
	}
	return 0;
}

