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
        if(a[0]!=1){
            cout<<"NO\n";
            continue;
        }
        bool flag=false;
        long long sum=1;
        for(int i=1;i<n;i++){
            if(a[i]>sum) {
                flag=true;
                break;
            }
            sum+=a[i];
        }
        if(flag) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}