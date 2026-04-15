#include <bits/stdc++.h>
using namespace std;
bool canMake(const string& longStr, const string& shortStr) {
    int i=0,j=0;
    bool skipped = false;
    while (i<longStr.size() && j<shortStr.size()) {
        if (longStr[i] == shortStr[j]) {
            i++;
            j++;
        } else {
            if(skipped)return false;
            skipped = true;
            i++;
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    n = (int)s.size();
    if (n % 2 == 0) {
        cout << "NOT POSSIBLE\n";
        return 0;
    }
    int m=(n-1)/2;
    string ans1, ans2;
    bool flag1 = false, flag2 = false;
    string left = s.substr(0, m + 1);
    string right = s.substr(m + 1, m);
    if (canMake(left, right)) {
        flag1 = true;
        ans1 = right;
    }
    left = s.substr(0, m);
    right = s.substr(m, m + 1);
    if (canMake(right, left)) {
        flag2 = true;
        ans2 = left;
    }
    if (!flag1 && !flag2) {
        cout << "NOT POSSIBLE\n";
        return 0;
    }
    if (flag1 && flag2 && ans1 != ans2) {
        cout << "NOT UNIQUE\n";
        return 0;
    }
    if(flag1){
        cout<<ans1<<"\n";
    }else{
        cout<<ans2<<"\n";
    }
    return 0;
}
