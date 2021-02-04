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
struct node{
	int ar[3];
};
node st[400004];
int lazy[400004];

void build(int si , int ss, int se)
{
	if(ss == se)
	{
		st[si].ar[0] = 1;
		st[si].ar[1] = 0;
		st[si].ar[2] = 0;
		return;
	}

	int mid = (ss + se) / 2;
	build(2*si , ss , mid);
	build(2*si+1 , mid+1 , se);
	st[si].ar[0] = st[2*si].ar[0] + st[2*si+1].ar[0];
	st[si].ar[1] = st[2*si].ar[1] + st[2*si+1].ar[1];
	st[si].ar[2] = st[2*si].ar[2] + st[2*si+1].ar[2];
}

void shift(int si)
{
	int a = st[si].ar[2];
	st[si].ar[2] = st[si].ar[1];
	st[si].ar[1] = st[si].ar[0];
	st[si].ar[0] = a;
}

void update(int si , int ss , int se , int qs , int qe)
{
	if(lazy[si] != 0)
	{
		int add = lazy[si];
		lazy[si] = 0;
		if(ss != se)
		{
			lazy[2*si] += add;
			lazy[2*si+1] += add;
		}
		add %= 3;
		for(int i=0;i<add;i++)
		{
			shift(si);
		}
	}
	if(ss > qe || se < qs) return;

	if(ss >= qs && se <= qe)
	{
		shift(si);
		if(ss != se)
		{
			lazy[2*si]++;
			lazy[2*si+1]++;
		}
		return;
	}

	int mid = (ss + se) / 2;
	update(2*si , ss , mid , qs , qe);
	update(2*si+1 , mid+1 , se , qs , qe);

	st[si].ar[0] = st[2*si].ar[0] + st[2*si+1].ar[0];
	st[si].ar[1] = st[2*si].ar[1] + st[2*si+1].ar[1];
	st[si].ar[2] = st[2*si].ar[2] + st[2*si+1].ar[2];
}

int query(int si , int ss , int se , int qs , int qe)
{
	if(lazy[si] != 0)
	{
		int add = lazy[si];
		lazy[si] = 0;
		if(ss != se)
		{
			lazy[2*si] += add;
			lazy[2*si+1] += add;
		}
		add %= 3;
		for(int i=0;i<add;i++)
		{
			shift(si);
		}
	}

	if(ss > qe || se < qs) {
		return 0;
	}

	if(ss >= qs && se <= qe)
	{
		return st[si].ar[0];
	}

	int mid = (ss + se) / 2;
	int l = query(2*si , ss , mid , qs , qe);
	int r = query(2*si+1 , mid+1 , se , qs , qe);

	return l + r;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , q , A , B , code;
	cin>>n>>q;
	build(1 , 1 , n);

	while(q--)
	{
		cin>>code>>A>>B;
		if(code == 0)
		{
			update(1 , 1 , n , A+1 , B+1);
		}
		else
		{
			cout<<query(1 , 1 , n , A+1 , B+1)<<endl;
		}
	}
}
