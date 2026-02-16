#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
int dfs(int k, vector<long long>& leftChild, vector<long long>& rightChild, vector<string>& s){
    if(k == 0)return 1;
    if(leftChild[k] == 0 && rightChild[k] == 0)return 1;
    int ans=1;
    if(s==""){
        s[k]="L";
        ans+=dfs(leftChild[k], leftChild, rightChild, s);
    }else if(s[k]=="L"){
        s[k]="R";
        ans+=dfs(rightChild[k], leftChild, rightChild, s);
    }else{
        s[k]="";
        return 1;
    }
    return ans%mod;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long>leftChild(n+1), rightChild(n+1);
        vector<string> s(n+1, "");
        for(long long i = 1; i <= n; i++)cin >> leftChild[i]>>rightChild[i];
        cout << dfs(1, leftChild, rightChild, s) << "\n";
    }
}
