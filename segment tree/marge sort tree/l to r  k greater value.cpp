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
#define endl '\n'
using namespace std;
int val[30001];
vi st[4*30001];

void merge(vi &a , vi &b , vi &c)
{
	int i = 0 , j = 0;

	while(i < a.size() && j < b.size())
	{
		if(a[i] < b[j]) c.push_back(a[i]) , i++;
		else			c.push_back(b[j]) , j++;
	}

	while(i < a.size()) c.push_back(a[i]) , i++;
	while(j < b.size()) c.push_back(b[j]) , j++;
}

void build(int si , int ss , int se)
{
	if(ss == se)
	{
		st[si].push_back(val[ss]);
		return;
	}

	int mid = (ss + se) / 2;
	build(2*si , ss , mid);
	build(2*si+1 , mid+1 , se);
	merge(st[2*si] , st[2*si+1] , st[si]);
}


int query(int si ,int ss , int se , int qs , int qe , int k)
{
	if(ss > qe || se < qs) return 0;

	if(ss >= qs && se <= qe)
	{
		return st[si].end() - upper_bound(st[si].begin() , st[si].end() , k);
	}

	int mid = (ss + se) / 2;
	return query(2*si , ss , mid , qs , qe , k) + query(2*si + 1 , mid + 1 , se , qs , qe , k);
}

int main()
{
	int n , l , r , k , q;
	cin>>n;
	REP(i , n) cin>>val[i];
	build(1 , 1 , n);

	cin>>q;
	while(q--)
	{
		cin>>l>>r>>k;
		cout<<query(1 , 1 , n , l , r , k)<<endl;
	}
}
