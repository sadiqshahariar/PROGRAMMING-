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
int gcd(int a,int b,int* x,int* y)
{
	if(b==0)
	{
		*x=1;
		*y=0;
		return a;
	}
	int x1,y1;
	int store=gcd(b,a%b,&x1,&y1);
	*x=y1;
	*y=x1-y1 * (a/b);
	return store;
}
int possiblesolution(int a,int b,int c,int* x0,int* y0,int* g)
{
	*g = gcd(fabs(a),fabs(b),x0,y0);
	if(c % *g)return 0;
	*x0 *=c / *g;
	*y0 *= c / *g;
	if(a<0)*x0 *=-1;
	if(b<0)*y0 *=-1;
	return 1;
}
void shiftsolution(int* x,int* y, int a,int b,int shiftvar)
{
	*x+=shiftvar*b;
	*y-=shiftvar*a;
}
int findminsum(int a,int b,int c)
{
	int x,y,g;
	possiblesolution(a,b,c,&x,&y,&g);

	a/=g;
	b/=g;
	int sa=a>0? +1 : -1;
	int sb=b>0? +1: -1;
	shiftsolution(&x,&y,a,b,-x/b);

	if(x<0)shiftsolution(&x,&y,a,b,sb);
	int minx1=x;
	shiftsolution(&x,&y,a,b,y/a);

	if(y<0)shiftsolution(&x,&y,a,b,-sa);
	int minx2=x;
	if(minx2>x)
	{
		swap(minx2,x);
	}
	int minx = max(minx1,minx2);
	if(minx>x) return -1;
	int miny = (c-a*x)/b;
	cout<<miny<<" "<<minx<<nl;
	//return;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		findminsum(a,b,c);

	}
	return 0;
}
