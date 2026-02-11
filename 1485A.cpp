#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long a, b;
		cin >> a >> b; 

		long long ans = INT_MAX; 
		for (int i = 0; i < 50; i++)
		{
			long long op = i; 
			long long b2 = b + i;
			if (b2 == 1) 
				continue;
			long long a2 = a;
			while (a2 > 0) 
			{
				a2 /= b2; 
				op++; 
			}
			ans = min(ans, op); 
		}
		cout << ans << endl;
	}
}