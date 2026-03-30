#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int cnt=1;
        for(int i=n-2;i>=0;i--){
            if(s[i]==s[n-1])cnt++;
        }
        cout<<s.size()-cnt<<endl;
    }
}