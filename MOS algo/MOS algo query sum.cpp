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

const int mx = 200002;
int K,ans[mx],a[mx],sum;

struct query
{
    int index,L,R;
     bool operator < (const query &other) const {
		int block_own = L/K;
		int block_other = other.L/K;
		if(block_own == block_other)
            return R < other.R;
		return block_own < block_other;
	}

}query[mx];


void add(int index)
{
    sum+=a[index];
}

void remove(int index)
{
    sum-=a[index];
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    int q;
    K=sqrt(n);
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>query[i].L>>query[i].R;
        query[i].index=i;
    }
    sort(query,query+q);
    //for(int i=0;i<q;i++)cout<<query[i].L<<" "<<query[i].R<<nl;
    int L=0,R=-1;
    for(int i=0;i<q;i++)
    {
        while(R<query[i].R)add(++R);
        while(L<query[i].L)remove(L++);
        while(R>query[i].R)remove(R--);
        while(L>query[i].L)add(--L);
        ans[query[i].index]=sum;
    }
    for(int i=0;i<q;i++)cout<<ans[i]<<nl;
    return 0;
}

