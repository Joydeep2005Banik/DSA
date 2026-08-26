#include<bits/stdc++.h>
using namespace std;

int nonrepeating(string s)
{
    map<char,int>freq;
    for(char c:s)
    freq[c]++;

    for(int i=0;i<s.size();i++)
    {
        if(freq[s[i]]==1)
            return i;
    }
    return -1;
}
int main()
{
    string s="loveleetcode";
    cout<<nonrepeating(s)<<endl;
    return 0;
}