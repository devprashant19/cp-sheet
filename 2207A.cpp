#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    while (t--){
        long long n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> ones;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') ones.push_back(i);
        }
        if (ones.empty()) {
            cout << "0 0"<<endl;
            continue;
        }
        int min_ones = 0, max_ones = 0;
        int start = ones[0];
        for (long long i = 1; i < ones.size(); i++) {
            if (ones[i] - ones[i-1] > 2) { 
                int length = ones[i-1] - start + 1;
                max_ones += length;
                min_ones += (length / 2) + 1;
                start = ones[i];
            }
        }
        int length = ones.back() - start + 1;
        max_ones += length;
        min_ones += (length / 2) + 1;
        cout << min_ones << " " << max_ones << endl;
    }
}
