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

void merge(int ar[],int l,int mid,int r)
{
    int n1=mid-l+1;
    int n2=r-mid;
    int i,j;

    int a[n1],b[n2];
    for(i=0;i<n1;i++)a[i]=ar[l+i];
    for(i=0;i<n2;i++)b[i]=ar[mid+1+i];
    i=0,j=0;
    int k=l;

    while(i<n1&&j<n2)
    {
        if(a[i]<=b[j])
        {
            ar[k]=a[i];
            i++;
        }
        else{
            ar[k]=b[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        ar[k]=a[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        ar[k]=b[j];
        j++;
        k++;
    }
}

void mergesort(int ar[],int l,int r)
{
    if(l>=r)return;
    int mid=l+(r-l)/2;
    mergesort(ar,l,mid);
    mergesort(ar,mid+1,r);
    merge(ar,l,mid,r);
}

void print(int ar[], int n)
{
    for(int i=0;i<n;i++)cout<<ar[i]<<" ";
    cout<<nl;
}
int main()
{
    while(1)
    {
        int n;
        cin>>n;
        int i,ar[n+3];
        for(i=0;i<n;i++)cin>>ar[i];
        mergesort(ar,0,n-1);
        print(ar,n);
    }
    return 0;
}
