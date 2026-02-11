#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long a, b, n;
		cin >> a >> b >> n;
		long long x[n];
		for (int i = 0; i < n; i++)cin >> x[i];
		long long m = b;
		for (int i = 0; i < n; i++)m += min(x[i], a - 1);
		cout << m << endl;
	}
	return 0;
}