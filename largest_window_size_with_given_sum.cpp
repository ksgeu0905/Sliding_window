#include <bits/stdc++.h>
using namespace std;
int max_size(int arr[],int target,int n){
    int i=0,j=-1,size=INT_MIN,sum=0;
    while(j<n){
        if(sum<target){
            j++;
            sum+=arr[j];
        }
        else if(sum>target){
            sum-=arr[i];
            i++;
        }
        else{
            size=max(size,j-i+1);
            sum+=arr[++j];
        }
    }
    return size;
}
int main(){
    int n,sum;
    cout<<"enter size of array and sum value:\n";
    cin>>n>>sum;
    int arr[n];
    cout<<"Enter array elements: \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int size=max_size(arr,sum,n);
    cout<<"Maximum size is: "<<size<<endl;
    return 0;
}