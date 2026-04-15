#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int small = 1;
        int large = 3 * n;
        for (int i = 0; i < n; i++) {
            cout << small << " " << large - 1 << " " << large << " ";
            small++;
            large -= 2; 
        }
        cout << "\n";
    }
}
