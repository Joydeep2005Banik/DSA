#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
    if(s.size()!=t.size())
        return false;
    map<char,int>freq_s;
    for(char c:s)
    freq_s[c]++;
    map<char,int>freq_t;
    for(char c:t)
    freq_t[c]++;
    return freq_s==freq_t;
}
int main()
{
    string s="anagram";
    string t="nagaram";
    cout<<isAnagram(s,t);
    return 0;
}