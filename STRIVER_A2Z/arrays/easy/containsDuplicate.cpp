// leetcode question=217

/*
INITIAL INTUITION:-
-> use a i pointer to point at current element arr[i].
-> use a j pointer to traverse from arr[i+1] to arr[n]. if any value is equal to arr[i] return true

TIME COMPLEXITY = O(N^2)
SPACE COMPLEXITY =O(1)
*/

/*
OPTIMAL APPROACH:-
-> use a hashmap to map the frequency of occurence of each element in the array.
-> if frequency of any element is atleast 2 return true
*/

#include<bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>nums)
{
    unordered_map<int,int>frequency;
    for(int i=0;i<nums.size();i++)
    {
        frequency[nums[i]]++;
        if(frequency[nums[i]]>1)
            return true;
    }
    return false;

}

// TIME COMPLEXITY=O(N)
// SPACE COMPLEXITY=O(N)