// Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

 

// Example 1:

// Input : 
// N = 5
// A[] = {-8, 2, 3, -6, 10}
// K = 2
// Output : 
// -8 0 -6 -6
// Explanation :
// First negative integer for each window of size k
// {-8, 2} = -8
// {2, 3} = 0 (does not contain a negative integer)
// {3, -6} = -6
// {-6, 10} = -6


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