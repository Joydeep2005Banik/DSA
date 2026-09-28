//leetcode question num:-125

/*
APPROACH:-

->  We use two pointers i and j to point to the two ends of the string s , and then loop through the following process until i ≥ j :
->  If s [ i ] is not a letter or a number, move the pointer i one step to the right and continue to the next loop.
->  If s [ j ] is not a letter or a number, move the pointer j one step to the left and continue to the next loop.
->  If the lowercase form of s [ i ] and s [ j ] are not equal, return false.
->  Otherwise, move the pointer i one step to the right and the pointer j one step to the left, and continue to the next loop.
->  At the end of the loop, return true.
*/


// TIME COMPLEXITY=O(N)
// SPACE COMPLEXITY=O(1)


#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s)
{
    int start=0;
    int end=s.size()-1;
    while(start<end)
    {
        if(isalnum(s[start])==false)
            start++;
        else if(isalnum(s[end])==false)
            end--;
        else if(tolower(s[start])!=tolower(s[end]))
            return false;
        else
        {
            start++;
            end--;
        }
    }
    return true;
}