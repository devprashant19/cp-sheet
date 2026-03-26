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
        for (int i=0; i<n; i++)cin>>a[i];
        sort(a.begin(), a.end());
        if(a[0]!=1)cout<<"NO\n";
        else{
            long long sum=1;
            for(int i=1;i<n;i++){
                if(a[i]>sum) {
                    cout<<"NO\n";
                    break;
                }
                sum+=a[i];
            }
            cout<<"YES\n";
        }
    }
    return 0;
}