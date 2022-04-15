// Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.

// Example 1:

// Input:
// txt = forxxorfxdofr
// pat = for
// Output: 3
// Explanation: for, orf and ofr appears
// in the txt, hence answer is 3.


#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
	int search(string pat, string txt) {
	    int s[26]={0};
	    int c=0,f=0;
	    map<int,int>m;
	    
	    for(auto v:pat){
	        m[v-97]++;
	    }
	    int i=0,j=pat.length()-1;
	    for(int z=i;z<=j;z++){
	        s[txt[z]-97]++;
	    }                                                                                                                  
	    while(j<txt.length()){
	        f=0;
	        for(auto v : m){
	            if(s[v.first]!=v.second){
	                f=1;
	                break;
	            }
	        }
	        if(f==0)
	            c++;
	        s[txt[i]-97]--;
	        j++;
	        s[txt[j]-97]++;
	        i++;
	    }
	    return c;
	}

};



int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}