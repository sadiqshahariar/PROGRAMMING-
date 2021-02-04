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
const int maxN = 100001;
int ar[maxN];
int st[4*maxN] , lazy[4*maxN];

void build(int si , int ss , int se)
{
	if(ss == se)
	{
		st[si] = ar[ss];
		return;
	}

	int mid = (ss + se) / 2;

	build(2*si , ss , mid);
	build(2*si+1 , mid+1 , se);

	st[si] = st[2*si] + st[2*si+1];
}

int query(int si , int ss , int se , int qs , int qe)
{
	if(lazy[si] != 0)
	{
		int dx = lazy[si];
		lazy[si] = 0;
		st[si] += dx * (se - ss + 1);

		if(ss != se)
		lazy[2*si] += dx , lazy[2*si+1] += dx;
	}

	if(ss > qe || se < qs) return 0;

	if(ss >= qs && se <= qe)
	return st[si];

	int mid = (ss + se) / 2;
	return query(2*si , ss , mid , qs , qe) + query(2*si+1 , mid+1 , se , qs , qe);
}

void update(int si , int ss , int se , int qs , int qe , int val)
{
	if(lazy[si] != 0)
	{
		int dx = lazy[si];
		lazy[si] = 0;
		st[si] += dx * (se - ss + 1);

		if(ss != se)
		lazy[2*si] += dx , lazy[2*si+1] += dx;
	}

	if(ss > qe || se < qs) return;

	if(ss >= qs && se <= qe)
	{
		int dx = (se - ss + 1) * val;
		st[si] += dx;

		if(ss != se)
		lazy[2*si] += val , lazy[2*si+1] += val;
		return;
	}

	int mid = (ss + se) / 2;
	update(2*si , ss , mid , qs , qe , val);
	update(2*si+1 , mid+1 , se , qs , qe , val);

	st[si] = st[2*si] + st[2*si+1];
}


int main()
{
	int n , q , code , l , r , val;
	cin>>n>>q;
	build(1 , 1 , n);

	while(q--)
	{
		cin>>code;
		if(code == 1)
		{
			cin>>l>>r;
			cout<<query(1 , 1 , n , l , r)<<endl;
		}
		else
		{
			cin>>l>>r>>val;
			update(1 , 1 , n , l , r , val);
		}
	}
}
