#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for(int i = 0; i < n; i++)cin>> a[i];
        vector<long long> b(n);
        for(int i = 0; i < n; i++)cin >> b[i];
        int change1 =-1, change2 = -1;
        for(int i = 0; i < n; i++) {
            if(a[i] != b[i]) {
                if(change1 == -1){
                    change1 = i;
                }
                else{
                    change2 = i;
                    break;
                }
            }
        }
        int i=change1-1;
        while(i>=0){
            if(b[i]<=b[i+1])i--;
            else break;
        }
        change1 = i+1;
        if(change2 ==-1)change2=n-1;
        int j=change2+1;
        while(j<n){
            if(b[j]>=b[j-1])j++;
            else break;
        }
        change2 = j-1;
        cout<<change1+1<<" "<<change2+1<<endl;
    }
    return 0;
}