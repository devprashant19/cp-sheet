#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--){
        long long n,c;
        cin>>n>>c;
        vector<long long> a(n);
        for (int i=0; i<n; i++)cin>>a[i];
        vector<pair<long long,long long> > v;
        for(int i=0;i<n;i++)v.push_back({a[i],i+1});
        sort(v.begin(), v.end(),[](pair<long long,long long> a,pair<long long,long long> b){
            return a.first+a.second<b.first+b.second;
        });
        long long cnt=0;
        for(int i=0;i<n;i++){
            if(v[i].first+v[i].second<=c){
                cnt++;
                c-=(v[i].first+v[i].second);
            }
        }
        cout << cnt << endl;
    }
    return 0;
}