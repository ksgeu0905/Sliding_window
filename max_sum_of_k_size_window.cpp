#include <bits/stdc++.h>
using namespace std;
int max_sum(int arr[],int k,int n){
    int i=0,j=k-1,sum=0,ans=INT_MIN;
    for(int z=0;z<=j;z++){
        sum+=arr[z];
    }
    ans=max(ans,sum);
    for(;j<n-1;j++){
        sum=sum+arr[j+1]-arr[i];
        i++;
        ans=max(ans,sum);
    }
    return ans;
}
int main(){
    int n,k;
    cout<<"enter size of array and window:\n";
    cin>>n>>k;
    int arr[n];
    cout<<"Enter array elements: \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=max_sum(arr,k,n);
    cout<<"Maximum sum is: "<<sum<<endl;
    return 0;
}