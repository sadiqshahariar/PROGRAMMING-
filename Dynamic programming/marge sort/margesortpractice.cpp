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
int marge(int ar[],int i,int mid,int j)
{
	int k=mid;
	int arr[j+1];
	int o=i;
	int ls=i;
	int rs=j;
	int x=0;
	while((i<=mid-1)&&(k<=j))
	{
		if(ar[i]<=ar[k])
		{
			arr[o]=ar[i];
			o++;
			i++;
		}
		else{
			arr[o]=ar[k];
			x+=mid-i;
			o++;
			k++;
		}
	}
	while(i<=mid)
	{
		arr[o]=ar[i];
		o++;
		i++;
	}
	while(k<=j)
	{
		arr[o]=ar[k];
		o++;
		k++;
	}
	for(int l=ls;l<=rs;l++)
	{
		ar[l]=arr[l];
		//cout<<arr[l]<<" ";
	}
	//cout<<nl;
	return x;
}
int margesort(int ar[],int i,int j)
{
	int x=0;
	if(j>i)
	{
		int mid=(i+j)/2;
		x+=margesort(ar,i,mid);
		x+=margesort(ar,mid+1,j);
		x+=marge(ar,i,mid+1,j);
	}
	return x;
}

int main()
{
	//faster
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,ar[n];
		for(i=0;i<n;i++)cin>>ar[i];
		int x =margesort(ar,0,n-1);
		cout<<x<<nl;
		for(i=0;i<n;i++)cout<<ar[i]<<" ";
		cout<<nl;
	}
	return 0;
}
