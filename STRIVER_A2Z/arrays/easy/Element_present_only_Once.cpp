/*
QUESTION:-
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.


Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4
*/


/*APPROACH:-
-> we can use xor operation for this. Since xor between exactly 2 duplicates result in 0, we 
    eliminate the duplicates.
-> for [4,1,2,1,2] ans=4 XOR 1 XOR 2 XOR 1 XOR 2 => 4 XOR 0 XOR 0 = 4
*/

#include<bits/stdc++.h>
using namespace std;

int dupes(vector<int>&nums)
{
    int res=0;
    for(int i=0;i<nums.size();i++)
    {
        res=res^nums[i];
    }
    return res;
}

//TIME COMPLEXITY- O(N)
// SPACE COMPLEXITY- O(1)