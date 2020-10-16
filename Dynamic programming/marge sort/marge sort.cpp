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

ll merge(ll arr[], ll temp[], ll left, ll mid, ll right)
{
	ll inv_count = 0;
	ll i = left;
	ll j = mid;
	ll k = left;
	while ((i <= mid - 1) && (j <= right))
	{
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
		{
			temp[k++] = arr[j++];

			inv_count = inv_count + (mid - i);
		}
	}

	while (i <= mid - 1)
		temp[k++] = arr[i++];

	while (j <= right)
		temp[k++] = arr[j++];
	for (i=left; i <= right; i++)
		arr[i] = temp[i];
	return inv_count;
}

ll _mergeSort(ll arr[], ll temp[], ll left, ll right)
{
	ll mid, inv_count = 0;
	if (right > left)
	{
		mid = (right + left)/2;
		inv_count = _mergeSort(arr, temp, left, mid);
		inv_count += _mergeSort(arr, temp, mid+1, right);
		inv_count += merge(arr, temp, left, mid+1, right);
	}
	return inv_count;
}
ll countSwaps(ll arr[], ll n)
{
	ll temp[n];
	return _mergeSort(arr, temp, 0, n - 1);
}
int main()
{
	ll aa;
	cin>>aa;
	while(aa--)
	{
		ll n;
		cin>>n;
		ll ar[n],i;
		for(i=0;i<n;i++)cin>>ar[i];
		ll ans= countSwaps(ar,n);
		for(i=0;i<n;i++)cout<<ar[i]<<" ";
		cout<<nl;
		ll x=n*(n-1) /2 -1;
		//cout<<ans<<" "<<x<<nl;
		if(ans>x)cout<<"NO"<<nl;
		else cout<<"YES"<<nl;
	}
	return 0;
}
