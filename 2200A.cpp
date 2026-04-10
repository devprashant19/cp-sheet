#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int max_dishes = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] > max_dishes) {
                max_dishes = a[i];
            }
        }
        int potential_winners = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == max_dishes) {
                potential_winners++;
            }
        }
        cout << potential_winners << endl;
    }
}
