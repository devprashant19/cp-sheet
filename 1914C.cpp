#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		long long n, k;
		cin >> n >> k;
		vector<long long> a(n), b(n); 
		for (long long i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (long long i = 0; i < n; i++) {
			cin >> b[i];
		}
        long long maxi =0;
		long long sum = 0; 
		long long ans = 0; 
		for (long long i = 0; i < min(n, k); i++) {
			sum += a[i];
			maxi = max(maxi, b[i]);
			ans = max(ans, sum + (k - (i + 1)) * maxi);
		}
		cout << ans << endl;
	}
}
