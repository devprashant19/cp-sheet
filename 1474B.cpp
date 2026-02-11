#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n)
{
    if (n <= 1)
        return false;
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long d;
        cin >> d;
        long long p=1+d;
        while(!isPrime(p))
        {
            p++;
        }
        long long q=p+d;
        while(!isPrime(q))
        {
            q++;
        }
        long long ans=min(p*p*p,p*q);
        cout << ans << endl;
    }
    return 0;
}