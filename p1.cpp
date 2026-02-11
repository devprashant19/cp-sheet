#include <bits/stdc++.h>
using namespace std;
vector<double> avg2(vector<int>& arr){
    int n=arr.size();
    vector<double> ans(n);
    for(int i=0;i<n;i++){
        double sum=0;
        for(int j=0;j<=i;j++)sum+=arr[j];
        ans[i]=(double)sum/(i+1);
    }
    return ans;
}
vector<double> avg(vector<int>& arr){
    int n=arr.size();
    vector<double> ans(n);
    double sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        ans[i]=(double)sum/(i+1);
    }
    return ans;
}
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> A(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cout<<"Enter element "<<i+1<<": ";
        cin >> A[i];
    }
    vector<double> result1 = avg(A),result2 = avg2(A);
    cout<<"O(n) result: ";
    for(double a:result1)cout<<a<<" ";
    cout<<"\nO(n^2) result: ";
    for(double a:result2)cout<<a<<" ";
    return 0;
}