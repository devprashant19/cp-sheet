#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<unordered_map<char, int>> mp(m);
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            mp[j][s[j]]++; 
        }
    }
    vector<int>mul(m);
    for(int i=0;i<m;i++){
        cin>>mul[i];
    }
    int sum=0;
    for(int i=0;i<m;i++){
        int maxVal=0;
        for(auto i:mp[i]){
            cout<<i.first<<" : "<<i.second<<endl;
            maxVal=max(maxVal,i.second);
        }
        sum+=maxVal*mul[i];
    }
    cout<<sum<<endl;
    return 0;
}
