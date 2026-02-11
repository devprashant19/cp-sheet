#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k, q;
        cin >> n >> k >> q;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            if (a[i] <= q)
                a[i] = 1;
            else
                a[i] = 0;
        }
        long long ways = 0;
        long long count = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
            {
                count++;
            }
            else
            {
                if (count >= k)
                {
                    long long diff = count - k + 1;
                    ways += (diff * (diff + 1))/ 2;
                }
                count = 0;
            }
        }
        if (count >= k)
        {
            long long diff = count - k + 1;
            ways += diff * (diff + 1) / 2;
        }
        cout << ways << endl;
    }
    return 0;
}