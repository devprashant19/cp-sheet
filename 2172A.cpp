#include <bits/stdc++.h>
using namespace std;
int md(int a, int b, int c) {
    if ((b > a) == (a > c)) {
        return a;
    } else if ((a > b) == (b > c)) {
        return b;
    } else {
        return c;
    }
}
int main() {
    int g,c,l;
    cin>>g>>c>>l;
    if(max({g,c,l})-min({g,c,l})>=10)cout<<"check again"<<endl;
    else{
        int med = md(g,c,l);
        cout<<"final "<<med<<endl;
    } 
}