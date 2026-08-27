/*
QUESTION:-
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
*/


/*
APPROACH:
-> we can solve this by finding out the sum of the elements present in the array and finding out the sum of n-array elements.
-> Sum of n elements= n(n+1)/2
-> finding out the difference between sum of n-array and sum of actual elements in array will give the missing number.


*/



#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) 
{
    int n=nums.size();
    int arithmeticSum=(n*(n+1))/2;
    int actualSum=0;
    for(int i=0;i<n;i++)
        actualSum+=nums[i];
    return arithmeticSum-actualSum;
}
int main()
{
    vector<int>arr={0,1};
    cout<<missingNumber(arr);
    return 0;
}


// TIME COMPLEXITY- O(N)
// SPACE COMPLEXITY - O(1)