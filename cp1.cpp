#include <bits/stdc++.h>
using namespace std;

int bit_diff(int a, int b) {
    int x = a ^ b;
    int ans = 0;
    while(x) {
        ans+=(x&1);
        x>>=1;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        int k;
        cin>>k;
        int curr_xor=0; 
        for(int &i:a){
            curr_xor^=i;
        }
        int ans=bit_diff(curr_xor, k);
        cout<<ans<<"\n";
    }
}