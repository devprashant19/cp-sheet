#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<pair<long long, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({a[i], i});
        sort(v.begin(), v.end()); 
        vector<long long> pos(n, 0);
        long long ans = 0;
        long long cnt = 1;
        for (int i = n - 1; i >= 0; i -= 2)
        {
            pos[v[i].second] = cnt;
            ans += v[i].first * cnt;
            if (i - 1 >= 0)
            {
                pos[v[i - 1].second] = -cnt;
                ans += v[i - 1].first * cnt;
            }

            cnt++;
        }
        ans *= 2;
        cout << ans << "\n";
        cout << 0 << " ";
        for (int i = 0; i < n; i++)
            cout << pos[i] << " ";
        cout << "\n";
    }

    return 0;
}
