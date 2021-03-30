#include<bits/stdc++.h>
using namespace std;
#define ff               first
#define ss               second
#define nl              << '\n'
#define gf              << ' ' <<
#define pb              push_back
#define pi              2*acos(0.0)
#define sz(x)           (int)x.size()
#define fillVec(a, v)   fill(all(a), v)
#define btz(a)          __builtin_ctz(a)
#define all(v)          v.begin(),v.end()
#define parity(a)       __builtin_parity(a)
#define countone(a)     __builtin_popcount(a)
#define mem(a,v)        memset(a, v, sizeof(a))
#define rsort(a)        sort(a), reverse(all(a))
#define precision(x)    cout << setprecision(x) << fixed
#define un(a)           sort(a), (a).erase(unique(all(a)),a.end())
#define faster          ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long     int        ll;
typedef unsigned long long    ull;
typedef double                db;
typedef long double           ldb;
typedef pair<int, int>        pii;
typedef pair<ll, ll>          pll;
typedef pair<int, pii>        iii;
typedef vector<int>           vi;
typedef vector<ll>            vl;
typedef vector<pii>           vii;
typedef vector<iii>           viii;
typedef vector<vi>            vvi;
typedef map<int, int>         mapii;
typedef map<int, bool>        mapib;
typedef map<int, string>      mapis;
typedef map<ll, ll>           mapll;
typedef map<ll, bool>         maplb;
typedef map<ll, string>       mapls;
typedef set<int>              seti;

const int mod = 1e9 + 7;
const int mx  = 200+5;

#define left(p)  (p<<1)
#define right(p) (p<<1)+1
#define mid(l,r) (l+(r-l)/2)

int n, q, a[mx];
int tree[mx*4];
int lazy[mx*4];

void build(int p, int l, int r){
    lazy[p] = 0;
    if(l == r) tree[p] = a[l];
    else{
    	build(left(p), l, mid(l,r));
    	build(right(p), mid(l,r)+1, r);
    	tree[p] = tree[left(p)] + tree[right(p)];
    }
}

void updateLazy(int p, int l, int r){
	tree[p] = lazy[p];
	if(l != r){
		lazy[left(p)] = lazy[p];
		lazy[right(p)] = lazy[p];
	}
	lazy[p] = 0;
}

void update(int p, int l, int r, int i, int j, int v){
	if(lazy[p]) updateLazy(p, l, r);
	if(l>r || l>j || r<i) return;
	if(l>=i && r<=j){
		lazy[p] = v;
		updateLazy(p, l, r);
		return;
	}
	update(left(p), l, mid(l,r), i, j, v);
	update(right(p), mid(l,r)+1, r, i, j, v);
	tree[p] = tree[left(p)] + tree[right(p)];
}

int query(int p, int l, int r, int i, int j){
	if(lazy[p]) updateLazy(p, l, r);
	if(l>r || l>j || r<i) return 0;
	if(l>=i && r<=j) return tree[p];
	int u = query(left(p), l, mid(l,r), i, j);
	int v = query(right(p), mid(l,r)+1, r, i, j);
	tree[p] = tree[left(p)] + tree[right(p)];
	return u + v;
}

int main(){
	int t;
	cin>>t;
	int c=0;
	while(t--){
        int n,q;
        cin>>n>>q;
        vector<iii>v;
        for(int i=1;i<=4*n;i++){
            tree[i]=30000;
            lazy[i]=30000;
        }
        for(int i=1;i<=q;i++){
            int x,y,val;
            cin>>x>>y>>val;
            v.pb({val,{x,y}});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            update(1,1,n,v[i].ss.ff,v[i].ss.ss,v[i].ff);
        }
        cout<<"Case "<<++c<<": ";
        for(int i=1;i<=n;i++){
            int x=query(1,1,n,i,i);
            cout<<x<<" ";
        }
        cout<<"\n";
	}
    return 0;
}
