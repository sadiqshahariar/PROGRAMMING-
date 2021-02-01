#include <bits/stdc++.h>
using namespace std;

long int countConsecutive(long int N)
{
	long int count = 0;
	for (long int L =1; L * (L + 1) < 2 * N; L++)
	{
		float a = (1.0 * N-(L * (L + 1)) / 2) / (L + 1);
		if (a-(int)a == 0.0)
			count++;
	}
	return count;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        cout<<countConsecutive(N)<<endl;
    }
	return 0;
}
