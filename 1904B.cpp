#include <bits/stdc++.h>
using namespace std;
int main() {
	int t = 1; 
	cin >> t;
	while (t--) {
		long long n; 
		cin >> n;
		long long a;
		vector<pair<long long, long long>> v; 
		for (int i = 0; i < n; i++) {  
			cin >> a;
			v.push_back({a, i});
		}
        sort(v.begin(), v.end());
		vector<long long> pre(n); 
		pre[0] = v[0].first;
		for (int i = 1; i < n; i++) {
			pre[i] = pre[i - 1] + v[i].first;
		}
		vector<long long> ans(n);
		for (int i = 0; i < n; i++) { 
			int j = i;
			int found = i;
			while (j < n) {
				pair<long long, long long> temp = {pre[j] + 1, INT_MIN};
				long long idx = lower_bound(v.begin(), v.end(), temp) - v.begin();
				idx--;
				if (idx == j) {
					break;
				}
				found += idx - j;
				j = idx;
			}
			ans[v[i].second] = found;
		}
		for (int i = 0; i < n; i++) { 
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}
