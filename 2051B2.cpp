#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,a,b,c;
        cin>>n>>a>>b>>c;
        long long low=1,high=1e18,ans=0;
        long long sum=a+b+c;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long full=mid/3;
            long long rem=mid%3;
            long long dist=0;
            if(full>n/sum) dist=n+1;
            else dist=full*sum;
            if(dist<=n){
                if(rem>=1) dist+=a;
                if(rem>=2) dist+=b;
            }
            if(dist>=n){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
