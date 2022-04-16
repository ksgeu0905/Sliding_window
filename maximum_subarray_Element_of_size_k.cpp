#include <bits/stdc++.h>
using namespace std;
void cal_max_element(int arr[],vector<int>&ans,int n,int k){
    int i=0,j=k-1;
    list<int> l;
    for(int z=i;z<=j;z++){
        if(l.empty())
            l.push_back(arr[z]);
        else{
            while(!l.empty() && arr[z]>l.back())
                l.pop_back();
            l.push_back(arr[z]);
        }
    }
    while(j<n){
        ans.push_back(l.front());
        if(arr[i]==l.front())
            l.pop_front();
        i++;j++;
        if(j!=n){
                while((!l.empty()) && arr[j]>l.back()){
                        l.pop_back();
                }
                l.push_back(arr[j]);
            }
    }
}
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter size of window: ";
    cin>>k;
    vector<int>ans;
    cal_max_element(arr,ans,n,k);
    for(auto i:ans){
        cout<<i<<" ";
    }
        return 0;
}