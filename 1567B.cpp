#include <bits/stdc++.h>
using namespace std;

long long x(long long n)
{
	long long a = n % 4;
	if (a == 0)
		return n;
	else if (a == 1)
		return 1;
	else if (a == 2)
		return n + 1;
	else
		return 0;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long a, b;
		cin >> a >> b;
		long long ans = x(a - 1);
		if (ans == b)
			cout << a << endl;
		else if ((ans ^ b) != a)
			cout << a + 1 << endl;
		else
			cout << a + 2 << endl;
	}
}