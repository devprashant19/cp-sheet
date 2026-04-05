#include <bits/stdc++.h>
using namespace std;

class CuboidVolumeReducer {
private:
    map<array<long long, 3>, long long> memo;
    vector<long long> primes;
    void build_sieve(long long max_val) {
        vector<bool> is_prime(max_val + 1, true);
        for (long long p = 2; p <= max_val; p++) {
            if (is_prime[p]) {
                primes.push_back(p);
                for (long long i = p * p; i <= max_val; i += p) {
                    is_prime[i] = false;
                }
            }
        }
    }
    long long solve_dp(long long a, long long b, long long c) {
        array<long long, 3> state = {a, b, c};
        sort(state.begin(), state.end());
        if (memo.count(state)) return memo[state];
        long long min_val = state[0];
        if (min_val <= 1) return min_val;
        long long ans = min_val; 
        for (long long p : primes) {
            if (p > min_val) break; 
            long long cost = (state[0] % p) + (state[1] % p) + (state[2] % p);
            if (cost < ans) {
                ans = min(ans, cost + solve_dp(state[0] / p, state[1] / p, state[2] / p));
            }
        }
        return memo[state] = ans;
    }

public:
    long long minSteps(long long l, long long b, long long h) {
        long long g = __gcd(__gcd(l, b), h);
        l /= g;
        b /= g;
        h /= g;
        long long initial_min = min({l, b, h});
        if (initial_min > 1) {
            build_sieve(initial_min); 
        }
        memo.clear();
        return solve_dp(l, b, h);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long l, b, h;
    if (cin >> l >> b >> h) {
        CuboidVolumeReducer solver;
        cout << solver.minSteps(l, b, h) << "\n";
    }
    
    return 0;
}