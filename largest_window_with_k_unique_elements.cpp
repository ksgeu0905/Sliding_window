/*Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.


Example 1:

Input:
S = "aabacbebebe", K = 3
Output: 7
Explanation: "cbebebe" is the longest 
substring with K distinct characters.
*/

#include <bits/stdc++.h>
using namespace std;

 
class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int i=0,j=0;
        map<char,int> m;
        int size=-1;
        while(j<s.length()){
                m[s[j]]++;
            if(m.size()==k){
                size=max(size,j-i+1);
            }
            while(m.size()>k){
                m[s[i]]--;
                if(m[s[i]]==0)
                    m.erase(s[i]);
                i++;
            }
            j++;
        }
        return size;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}