#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, r, b;
		cin >> n >> r >> b;
		string s;
		int lr = r / (b + 1);
		int leftr = r % (b + 1);
		for (int j = 1; j <= b + 1; j++)
		{
			for (int i = 0; i < lr; i++)
				s += 'R';
			if (leftr > 0)
			{
				s += 'R';
				leftr--;
			}
			if (j != b + 1)
				s += 'B';
		}
		cout << s << endl;
	}
	return 0;
}