#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<char> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long long cnt = 0;
        for (int i = 0; i < k; i++)
        {
            if (a[i] == 'W')
                cnt++;
        }
        long long ans = cnt;
        for (int i = k; i < n; i++)
        {
            if (a[i] == 'W')
                cnt++;
            if (a[i - k] == 'W')
                cnt--;

            ans = min(ans, cnt);
        }

        cout << ans << endl;
    }
    return 0;
}
