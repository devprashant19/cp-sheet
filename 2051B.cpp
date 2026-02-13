#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, a, b, c;
        cin >> n >> a >> b >> c;
        long long cycle = a + b + c;
        long long full = n / cycle;
        long long days = full * 3;
        long long rem = n % cycle;
        if(rem == 0)cout << days << endl;
        else if(rem <= a)cout << days + 1 << endl;
        else if(rem <= a + b)cout << days + 2 << endl;
        else cout << days + 3 << endl;
    }
    return 0;
}
