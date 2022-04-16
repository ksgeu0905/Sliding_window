/*Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.*/

#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int sum=0,size=0;
        map<char,int> m;
        int l=s.length();
        while(j<l){
            m[s[j]]++;
            sum++;
            if(m.size()==sum){
                size=max(size,j-i+1);
            }
            j++;
            while(sum>m.size()){
                m[s[i]]--;
                sum--;
                if(m[s[i]]==0)
                    m.erase(s[i]);
                i++;
            }
        }
        return size;
    }
int main(){
    string str;
    cin>>str;
    int ans=lengthOfLongestSubstring(str);
    cout<<ans<<endl;;
    return 0;
}