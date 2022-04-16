/*
*/#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t) {
        if(t.length() > s.length())
            return "";
        if(s==t)
            return s;
        int i=0,j=0,size=INT_MAX,start=0,count=0;
        map<char,int> m;
        for(auto z:t){
            m[z]++;
        }
        int l1=s.length(),l2=t.length();
        while(j<l1){
            if(count<l2){
                if(m.find(s[j])!=m.end()){
                    m[s[j]]--;
                    if(m[s[j]]==0)
                        count++;
                }
            }
            while(count==l2){
                if(j-i+1 <size){
                    size=j-i+1;
                    start=i;
                }
                if(m.find(s[i])!=m.end()){
                    m[s[i]]++;
                    if(m[s[i]]==1)
                        count--;
                }
                i++;
            }
            j++;
        }
        if(size==INT_MAX)
            size=0;
        return s.substr(start,size);
         
    }
int main(){
    string s,t;
    cout<<"Enter text : ";
    cin>>s;
    cout<<"Enter pattern : ";
    cin>>t;
    cout<<"Minimum Subarray Window is : "<<minWindow(s,t);

    return 0;
}