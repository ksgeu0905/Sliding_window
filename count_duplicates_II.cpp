/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
*/
#include <bits/stdc++.h>
using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k) {
         if (nums.empty()) return false;
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); ++i) {
            // maintenance window nums[i-k, i-1], remove the front element from the window
            if (i > k) set.erase(nums[i-k-1]);
            // check the duplicates in set
            if (set.find(nums[i]) != set.end()) return true;
            // add current number into the set
            set.insert(nums[i]);
        }
        return false;
}
int main(){
    int n;
    cin>> n;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        cin>>ans[i];
    }
    int k;
    cin>>k;
    cout<<containsNearbyDuplicate(ans,k);
    return 0;
}