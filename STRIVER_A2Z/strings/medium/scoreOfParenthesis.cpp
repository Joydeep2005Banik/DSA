//leetcode question 856

/*
INITIAL APPROACH:

Every nested pair multiplies its contents by 2. This means a base pair "()" nested inside $d$ levels of outer
parentheses contributes exactly 1x2^d=2^d Because multiplication distributes over addition 
(2x(A + B) = 2A + 2B), 
the total score of the string is simply the sum of 2^d for every innermost leaf unit "()", 
where d is the nesting depth of that unit.


*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int scoreOfParentheses(string s) {
        int score=0;
        int level=0;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                level++;
            else
            {
                level--;
                if(s[i-1]=='(')
                {
                    score+=(int)(pow(2,level));
                }
            }
        }
        return score;
    }
};