    #include <bits/stdc++.h>
    using namespace std;
    int main(){
        int t;
        cin >> t;
        while(t--){
            int n;
            cin >> n;
            vector<long long> f(n+1);
            for(int i = 1; i <= n; i++)cin >> f[i];
            vector<long long> a(n+1);
            for(int i = 2; i <= n-1; i++)a[i] = (f[i+1] - 2*f[i] + f[i-1]) / 2;
            long long S = (f[1] + f[n]) / (n-1);
            a[1] = (f[2] - f[1] + S) / 2;
            long long sum = 0;
            for(int i = 2; i <= n-1; i++)sum += a[i];
            a[n] = S - a[1] - sum;
            for(int i = 1; i <= n; i++)cout << a[i] << " ";
            cout << endl;
        }
    }
