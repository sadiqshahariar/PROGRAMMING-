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

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x, int &y) {

	int x0 , y0;
    int g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x = x0 * c / g;
    y = y0 * c / g;

    if (a < 0) x = -x;
    if (b < 0) y = -y;
    return true;
}

int main()
{
	int t , a , b , c , x , y;

	cin>>t;

	while(t--)
	{
		cout<<"a : " , cin>>a;

		cout<<"b : " , cin>>b;

		cout<<"c : " , cin>>c;

		if(find_any_solution(a , b , c , x , y) == false){
			cout<<"No solution exists\n\n";
		}
		else
		{
			cout<<"x = "<<x<<" y = "<<y<<endl<<endl;
		}
	}
}


