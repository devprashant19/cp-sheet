#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--){
        long long n;
        cin>>n;
        vector<long long> a(n);
        long long sum = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
        long long maxSum=sum;
        sort(a.begin(), a.end());
        for(int i=0; i<n-1; i+=2){
            sum += 2*(-a[i]-a[i+1]);
            maxSum = max(maxSum, sum);
        }
        cout << maxSum << endl;
    }
    return 0;
}