#include<bits/stdc++.h>
using namespace std;
int partition(vector<int> &v,int low,int high){
    int pivot=v[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if(v[j]<pivot){
            i++;
            swap(v[i],v[j]);
        }else j++;
    }
    swap(v[i+1],v[high]);
    return i+1;
}
void quickSort(vector<int>& v,int low,int high){
    if(low<high){
        int pos=partition(v,low,high);
        quickSort(v,low,pos-1);
        quickSort(v,pos+1,high);
    }
}

int main(){
    vector<int> v={10,9,8,7,6,5,4,3,2,1};
    quickSort(v,0,v.size()-1);
    for(auto x:v)cout<<x<<" ";
    return 0;
}