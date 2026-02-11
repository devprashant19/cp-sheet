#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a,b,kx,ky,qx,qy;
        cin>>a>>b;
        cin>>kx>>ky;
        cin>>qx>>qy;
        vector<pair<long long,long long>>v1,v2;
        v1.push_back({kx+a,ky+b});
        v1.push_back({kx-a,ky+b});
        v1.push_back({kx+a,ky-b});
        v1.push_back({kx-a,ky-b});
        v1.push_back({kx+b,ky+a});
        v1.push_back({kx-b,ky+a});
        v1.push_back({kx+b,ky-a});
        v1.push_back({kx-b,ky-a});
        v2.push_back({qx+a,qy+b});
        v2.push_back({qx-a,qy+b});
        v2.push_back({qx+a,qy-b});
        v2.push_back({qx-a,qy-b});
        v2.push_back({qx+b,qy+a});
        v2.push_back({qx-b,qy+a});
        v2.push_back({qx+b,qy-a});
        v2.push_back({qx-b,qy-a});
        set<pair<long long,long long>>p1;
        int cnt=0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(v1[i].first==v2[j].first && v1[i].second==v2[j].second) p1.insert({v1[i].first,v1[i].second});
            }
        }
        cout<<p1.size()<<endl;
    }
    return 0;
}