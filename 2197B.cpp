#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    while (t--){
        long long n;
        cin >> n;
        vector<long long> pos(n + 1);
        for (long long i = 0; i < n; ++i){
            long long val;
            cin >> val;
            pos[val] = i;
        }
        vector<long long> a(n);
        for (long long i = 0; i < n; ++i)cin >> a[i];
        vector<long long> min_a;
        vector<bool> visited(n + 1, false);
        bool flag = true;
        for (long long i = 0; i < n; ++i){
            if (i == 0 || a[i] != a[i - 1]){
                if (visited[a[i]]){
                    flag = false;
                    break;
                }
                visited[a[i]] = true;
                min_a.push_back(a[i]);
            }
        }
        if (flag){
            for (long long i = 1; i < min_a.size(); ++i){
                if (pos[min_a[i]] < pos[min_a[i - 1]]){
                    flag = false;
                    break;
                }
            }
        }
        if (flag)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}