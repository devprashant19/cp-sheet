#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin >> t;
    while (t--){
        int n;
        cin>>n;
        vector<int> arr;
        for (int i = 2; i < 3*n+1; i++)arr.push_back(i);
        arr.push_back(1);
        for (int i = 0; i < 3*n; i++)cout<<arr[i]<<" ";
        cout<<"\n";
    }
}
