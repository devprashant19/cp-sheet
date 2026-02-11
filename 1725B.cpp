#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    long long d;
    cin >> n >> d;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    long long j = n - 1;
    long long i = 0;
    long long ans = 0;
    long long pow = a[j];
    while (i <= j)
    {
        if (pow > d)
        {
            j--;
            ans++;
            pow = a[j];
        }
        else
        {
            pow += a[j];
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}