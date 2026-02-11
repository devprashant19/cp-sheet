#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n,m;
        cin >> n >> m;
        vector<vector<long long>> a(n,vector<long long>(m,0));
        long long cnt=0;
        long long min_abs=INT_MAX;
        for (long long i = 0; i < n; i++)
        {
            for (long long j = 0; j < m; j++){
                cin >> a[i][j];
                if(a[i][j]<0){
                    cnt++;
                }
            }
        }
        long long total=0;
        for (long long i = 0; i < n; i++)
        {
            for (long long j = 0; j < m; j++){
                min_abs = min(min_abs,abs(a[i][j]));
                total+=abs(a[i][j]);
            }
        }
        if(cnt%2==0)cout<<total<<endl;
        else{
            total-=2*min_abs;
            cout<<total<<endl;
        }
        
    }
    return 0;
}