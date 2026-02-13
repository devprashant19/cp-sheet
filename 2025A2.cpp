#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--){
        string s1, s2;
        cin >> s1 >> s2;
        long long n1 = s1.size();
        long long n2 = s2.size();
        long long low = 0;
        long long high = min(n1, n2);
        long long x = 0;
        while (low <= high){
            long long mid = (low + high) / 2;
            if (s1.substr(0, mid) == s2.substr(0, mid)){
                x = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        long long ans = n1 + n2;
        if (x != 0)ans = n1 + n2 - x + 1;
        cout << ans << endl;
    }
    return 0;
}
