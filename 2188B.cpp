#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        string s;
        cin >> s;
        int total_students = 0;
        int last_one = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                total_students++;
                if (last_one == -1)total_students += (i + 1) / 3;
                else {
                    int zeros_in_between = i - last_one - 1;
                    total_students += zeros_in_between / 3;
                }
                last_one = i;
            }
        }
        if (last_one == -1)total_students += (n + 2) / 3;
        else {
            int zeros_at_end = n - 1 - last_one;
            total_students += (zeros_at_end + 1) / 3;
        }

        cout << total_students << endl;
    }
}
