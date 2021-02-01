
#include<bits/stdc++.h>
using namespace std;
#define ff               first
#define ss               second
#define pb              push_back
#define pi              2*acos(0.0)
#define sz(x)           (int)x.size()
#define btz(a)          __builtin_ctz(a)
#define all(v)          v.begin(),v.end()
#define parity(a)       __builtin_parity(a)
#define countone(a)     __builtin_popcount(a)
#define mem(a,v)        memset(a, v, sizeof(a))
#define faster          ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef long long int             ll;
typedef unsigned long long    ull;
typedef double                db;
typedef long double           ldb;
typedef pair<ll, ll>        pii;
typedef pair<ll, ll>          pll;
typedef pair<ll, pii>        piii;
typedef vector<ll>           vi;
typedef vector<ll>            vl;
typedef vector<pii>           vii;
typedef vector<piii>          viii;
typedef vector<vi>            vvi;
typedef map<ll, ll>         mapii;
typedef map<ll, bool>        mapib;
typedef map<ll, string>      mapis;
typedef map<ll, ll>           mapll;
typedef map<ll, bool>         maplb;
typedef map<ll, string>       mapls;
typedef set<ll>              seti;


static const int mx = 5e5 + 78;
static const int mod = 1e9 + 7;
static const int inf = 0x3f3f3f3f;
ll n,k,m,l,s,t;

struct node
{
    string name;
    ll a,speed,stupid;
    node(){}
    node(string nn,ll aa,ll bb,ll cc)
    {
        name=nn;
        a=aa;
        speed=bb;
        stupid=cc;
    }
};

bool cmp(node A,node B)
{
    if(A.a==B.a){
        if(A.speed==B.speed){
            if(A.stupid==B.stupid) {
                return A.name<B.name;
            }
            else {
                return A.stupid<B.stupid;
            }
        }
        else return A.speed>B.speed;
    }
    else return A.a>B.a;
}


int main()
{
    //freopen("bug output.txt", "w", stdout);

    faster;
    ll n;
    cin>>n;
    vector<node>v;
    for(int i=1;i<=n;i++){
        string nam;
        ll ac,sp,st;
        cin>>nam>>ac>>sp>>st;
        node x;
        x.name=nam;
        x.a=ac;
        x.speed=sp;
        x.stupid=st;
        v.pb(x);
    }

    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++) cout<<v[i].name<<endl;

}
