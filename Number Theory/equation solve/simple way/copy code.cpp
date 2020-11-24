// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the gcd of a & b
// by Euclid's method

// x and y store solution of
// equation ax + by = g
int gcd(int a, int b, int* x, int* y)
{

	if (b == 0) {
		*x = 1;
		*y = 0;
		return a;
	}
	int x1, y1;
	int store_gcd = gcd(b, a % b,
						&x1, &y1);

	// Euclidean Algorithm
	*x = y1;
	*y = x1 - y1 * (a / b);

	// store_gcd returns
	// the gcd of a and b
	return store_gcd;
}

// Function to find any
// possible solution
int possible_solution(int a, int b,
					int c, int* x0,
					int* y0, int* g)
{
	*g = gcd(fabs(a), fabs(b), x0, y0);

	// Condition if solution
	// does not exists
	if (c % *g) {
		return 0;
	}

	*x0 *= c / *g;
	*y0 *= c / *g;

	// Adjusting the sign
	// of x0 and y0
	if (a < 0)
		*x0 *= -1;
	if (b < 0)
		*y0 *= -1;

	return 1;
}

// Function to shift solution
void shift_solution(int* x, int* y,
					int a, int b,
					int shift_var)
{

	// Shifting to obtain
	// another solution
	*x += shift_var * b;
	*y -= shift_var * a;
}

// Function to find minimum
// value of x and y
int find_min_sum(int a, int b, int c)
{
	int x, y, g;

	// g is the gcd of a and b
	if (!possible_solution(a, b, c,
						&x, &y, &g))
		return -1;

	a /= g;
	b /= g;

	// Store sign of a and b
	int sign_a = a > 0 ? +1 : -1;
	int sign_b = b > 0 ? +1 : -1;

	shift_solution(&x, &y, a, b, -x / b);

	// If x is less than 0, then
	// shift solution
	if (x < 0)
		shift_solution(&x, &y, a, b, sign_b);

	int minx1 = x;

	shift_solution(&x, &y, a, b, y / a);

	// If y is less than 0, then
	// shift solution
	if (y < 0)
		shift_solution(&x, &y, a, b, -sign_a);

	int minx2 = x;

	if (minx2 > x)
		swap(minx2, x);
	int minx = max(minx1, minx2);

	// Find intersection such
	// that both x and y are positive

	if (minx > x)
		return -1;

	// miny is value of y
	// corresponding to minx
	int miny = (c - a * x) / b;

	// Returns minimum value of x+y
	cout<<miny<<" "<<minx<<endl;
	return (miny + minx);
}

// Driver Code
int main()
{
	// Given a, b, and c
	int a = 2, b = 3, c = 1;

	// Function Call
	cout << find_min_sum(a, b, c)
		<< "\n";

	return 0;
}

