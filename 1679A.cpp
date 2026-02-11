#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long n;
		cin >> n;
        if(n%2!=0 || n<4)cout<<-1<<endl;
        else{
            long long x=n/4;
            long long y=(n+5)/6;
            cout<<y<<" "<<x<<endl;
        }
	}
	return 0;
}

