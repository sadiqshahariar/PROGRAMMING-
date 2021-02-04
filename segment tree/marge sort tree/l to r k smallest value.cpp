#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;
#define maxN 1000
vi st[4*maxN];
int ar[maxN];

void build(int si , int ss , int se)
{
	if(ss == se)
	{
		st[si].pb(ar[ss]);
		return;
	}

	int mid = (ss + se) / 2;
	build(2*si , ss , mid);
	build(2*si + 1, mid+1 , se);

	int i=0;
	int j=0;

	while(i < st[2*si].size() && j < st[2*si+1].size())
	{
		if(st[2*si][i] <= st[2*si+1][j])
		st[si].pb(st[2*si][i]) , i++;

		else
		st[si].pb(st[2*si+1][j]) , j++;
	}

	while(i < st[2*si].size())
	st[si].pb(st[2*si][i]) , i++;

	while(j < st[2*si+1].size())
	st[si].pb(st[2*si+1][j]) , j++;

}

int query(int si , int ss ,int se , int qs , int qe , int k)
{
	if(ss > qe || se < qs) return 0;

	if(ss >= qs && se <= qe)
	{
		int res = upper_bound(st[si].begin() , st[si].end() , k-1) - st[si].begin();
		return res;
	}

	int mid = (ss + se) / 2;
	int l = query(2*si , ss , mid , qs , qe , k);
	int r = query(2*si + 1 , mid + 1 , se , qs , qe , k);

	return l + r;
}

int main()
{
	int n , q , l , r , k;

	cin>>n>>q;
	REP(i , n) cin>>ar[i];
	build(1 , 1 , n);

	while(q--)
	{
		cin>>l>>r>>k;
		cout<<query(1 , 1 , n , l , r , k)<<endl;
	}
}


