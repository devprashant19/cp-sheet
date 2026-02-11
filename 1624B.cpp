#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        long long a2 = 2 * b - c;
        long long b2 = (a + c) / 2;
        long long c2 = 2 * b - a;
        bool flag = false;
        if (a2 / a > 0 && a2 % a == 0)
            flag = true;
        if (b2 / b > 0 && b2 % b == 0 && (c - a) % 2 == 0)
            flag = true;
        if (c2 / c > 0 && c2 % c == 0)
            flag = true;
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}