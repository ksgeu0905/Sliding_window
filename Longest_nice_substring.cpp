#include <bits/stdc++.h>
using namespace std;
string longestNiceSubstring(string str)
{
    if (str == "")
        return "";
    set<char> s;
    for (auto i : str)
    {
        s.insert(i);
    }
    if (s.size() == 1)
        return "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            if (find(s.begin(), s.end(), str[i] - 32) == s.end())
            {
                string s1 = longestNiceSubstring(str.substr(0, i));
                string s2 = longestNiceSubstring(str.substr(i + 1));
                if (s1.length() >= s2.length())
                    return s1;
                return s2;
            }
        }
        else
        {
            if (find(s.begin(), s.end(), str[i] + 32) == s.end())
            {
                string s1 = longestNiceSubstring(str.substr(0, i));
                string s2 = longestNiceSubstring(str.substr(i + 1));
                if (s1.length() >= s2.length())
                    return s1;
                return s2;
            }
        }
        if (i == str.length() - 1)
            return str;
    }
    return "";
}

int main()
{
    string str;
    cin >> str;
    cout << "Longest Nice Subtring : " << longestNiceSubstring(str);
    return 0;
}