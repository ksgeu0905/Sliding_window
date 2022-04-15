#include <bits/stdc++.h>
using namespace std;
int max_size(int arr[],int target,int n){
    int i=0,j=-1,size=INT_MIN,sum=0,f_i,f_j;
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
            if(j-i+1>size){
                size=j-i+1;
                f_i=i;
                f_j=j;
            }
            sum+=arr[++j];
        }
    }
    while(f_i<=f_j){
        cout<<arr[f_i]<<" ";
        f_i++;
    }
    cout<<endl;
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
    return 0;
}