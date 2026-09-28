// leetcode question number:- 1614

/*
INITIAL INTUITION:-

-> since s has valid paranthesis, thus an opening bracket must have a closing bracket so counting only 1 of them is enough
-> once we encounter ( from a pair we increment depth counter and compare with previous iteration depth
-> once we encounter ) it means pair is complete to depth is reset to 0
*/

#include<bits/stdc++.h>
using namespace std;
int maxDepth(string s)
{
    int depth=0;
    int maxDepth=0;
    for(char c:s)
    {
        if(c=='(')
        {
            depth++;
            maxDepth=max(maxDepth,depth);
        }
        else if(c==')')
            depth--;
    }
    return maxDepth;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY= O(1)
*/