#include <bits/stdc++.h>
using namespace std;
long long ceil_division(long long a, long long b) {
	return (a + b - 1) / b;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x,y,k;
        cin>>x>>y>>k;
        long long sticks_req=k*y+k-1;
        long long spt=x-1;
        long long steps=0;
        steps+=ceil_division(sticks_req,spt);
        steps+=k;
        cout<<steps<<endl;
    }
    return 0;
}