#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a,b;
        cin>>a>>b;
        long long n=a.size();
        long long m=b.size();
        long long max_substr_len=0;
        for(long long len=1;len<=min(m,n);len++){
            for(long long i=0;i+len<=n;i++){
                for(long long j=0;j+len<=m;j++){
                    string substr_a=a.substr(i,len);
                    string substr_b=b.substr(j,len);
                    if(substr_a == substr_b){
                        max_substr_len=max(max_substr_len,len);
                    }
            }
        }
    }
        long long ans=n+m-2*max_substr_len;
        cout<<ans<<endl;
    }
    return 0;
}
