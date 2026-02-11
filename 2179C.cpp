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
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        long long m = a[0];
        long long ans = m;
        bool flag = true;
        for (int i = 1; i < n; ++i)
        {
            if (a[i] <= 2 * m)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            long long min_diff = a[1] - m;
            for (int i = 2; i < n; ++i)
            {
                if (a[i] - m < min_diff)
                {
                    min_diff = a[i] - m;
                }
            }
            ans = min_diff;
        }

        cout << ans << endl;
    }
    return 0;
}