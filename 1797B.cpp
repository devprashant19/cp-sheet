#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
       long long n,k;
       cin>>n>>k;
       vector<vector<long long>>a(n,vector<long long>(n));
       for(int i=0;i<n;i++) {
           for(int j=0;j<n;j++) {
               cin>>a[i][j];
           }
       }
       long long k_min=0;
       for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j]!=a[n-i-1][n-j-1])k_min++;
			}
		}
        k_min/=2;
        if(k_min>k)cout<<"NO\n";
        else{
            long long temp=k-k_min;
            if((temp)%2==0){
                cout<<"YES\n";
            }
            else{
                if(n%2!=0)cout<<"YES\n";
                else cout<<"NO\n";
            }
        }
    }
    return 0;
}