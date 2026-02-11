#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x,y;
        cin>>x;
        if(x%2!=0)y=2*x;
        else y=x/2;
        cout<<y<<endl;
    }
    return 0;
}
