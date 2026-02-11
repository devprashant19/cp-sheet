#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n,k,x;
        cin>>n>>k>>x;
        long long sum=0;
        for(long long i=n;i>n-k;i--){
            sum+=i;
        }
        long long sum2=k*(k+1)/2;
        if(sum>=x && x>=sum2){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}