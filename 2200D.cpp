#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    while (t--){
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        //section B
        vector<int> B(p.begin() + x, p.begin() + y);
        //merge initial A and C part
        vector<int> S(p.begin(), p.begin() + x);
        //rotate B
        S.insert(S.end(), p.begin() + y, p.end());
        auto min_it = min_element(B.begin(), B.end());
        rotate(B.begin(), min_it, B.end()); 
        int i = 0;
        while (i < S.size() && S[i] < B[0]) {
            i++;
        }
        S.insert(S.begin() + i, B.begin(), B.end());
        for (int v : S) cout << v << " ";
        cout << endl;
    }
}
