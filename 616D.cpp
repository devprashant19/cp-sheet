#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> freq(1000005, 0);
    int distinct_count = 0;
    int left = 0;
    int best_l = 0, best_r = 0;
    int max_len = 0;
    for (int right = 0; right < n; ++right) {
        if (freq[a[right]] == 0) {
            distinct_count++;
        }
        freq[a[right]]++;
        while (distinct_count > k) {
            freq[a[left]]--;
            if (freq[a[left]] == 0) {
                distinct_count--;
            }
            left++;
        }
        if (right - left + 1 > max_len) {
            max_len = right - left + 1;
            best_l = left + 1;
            best_r = right + 1;
        }
    }
    cout << best_l << " " << best_r << '\n';
    return 0;
}