#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    while (t--){
        long long n, x;
        cin >> n >> x;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++)cin >> a[i];
        sort(a.begin(), a.end());
        long long left = 1;
        long long right = 1e12;
        long long height=-1;
        while (left <= right){
            long long mid=left+(right-left)/2;
            long long res=0;
            for(long long i=0;i<n;i++){
                if(a[i]<mid)res+=mid-a[i];
            }
            if(res<=x){
                height=mid;
                left=mid+1; 
            } else{ 
                right=mid-1; 
            }
        }
        cout << height << endl;
    }
}
