//leetcode question no.- 20

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char>bracket;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                bracket.push(s[i]);
            }
            else
            {
                if(bracket.empty())
                    return false;
                if((s[i]==')' && bracket.top()=='(') || (s[i]==']' && bracket.top()=='[') || (s[i]=='}' && bracket.top()=='{'))
                {
                    bracket.pop();
                }
                else
                {
                    return false;
                }
            }

        }
        return bracket.empty();
    }
};

// TIME COMPLEXITY= O(N)
// SPACE COMPLEXITY=O(N)