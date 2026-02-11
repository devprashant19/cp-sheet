#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), [](int x, int y)
         { return abs(x) < abs(y); });
    for (int i : a)
        cout << i << endl;
    cout << a[0] << endl;
    return 0;
}
