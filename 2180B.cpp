#include <bits/stdc++.h>
using namespace std;
bool lex(string a, string b){
    for (long long i = 0; i < min(a.size(), b.size()); i++){
        if (a[i] < b[i])return true;
        else if (a[i] > b[i])return false;
    }
    return a.size() < b.size();
}
int main(){
    long long t;
    cin >> t;
    while (t--){
        long long n;
        cin >> n;
        vector<string> a(n);
        for (long long i = 0; i < n; i++)cin >> a[i];
        string s = a[0];
        for(int i=1; i<n; i++){
            if(lex(a[i], s))s.insert(0,a[i]);
            else s.insert(s.size(),a[i]);
        }
        cout << s << endl;
    }
}
