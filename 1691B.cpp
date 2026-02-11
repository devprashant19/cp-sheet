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
        vector<long long> a(n), ans(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        bool flag = true;
        for (int i = 0; i < n; )
        {
            int j = i;
            while (j < n && a[j] == a[i]) j++;

            if (j - i == 1)
            {
                flag = false;
                break;
            }
            i = j;
        }

        if (!flag)
        {
            cout << -1 << "\n";
            continue;
        }
        for (int i = 0; i < n; )
        {
            int j = i;
            while (j < n && a[j] == a[i]) j++;

            for (int k = i; k < j - 1; k++)
                ans[k] = k + 1;

            ans[j - 1] = i;
            i = j;
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] + 1 << " ";
        cout << "\n";
    }
    return 0;
}
