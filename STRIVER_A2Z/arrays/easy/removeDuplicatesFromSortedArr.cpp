// leetcode question no. ->26

/*
APPROACH:-
-> we keep a pointer 'k' that denotes that upto the index value 'k' the array is sorted.
-> now we iterate the array. if arr[i] is a unique element that is arr[k]!=arr[i] then we increment
    the k and swap(arr[k],arr[i]). this is beacuse since the array is sorted, the duplicates will be
    clusterred together. so we need only one of the indices of the dupes and we can figure out the rest
    by looking adjacently.
-> return k+1 since it is a 0-based indexing
*/

#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>&nums)
{
    int k=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[k]!=nums[i])
        {
            k++;
            swap(nums[k],nums[i]);//swapping helps to push the uniques to one side
        }
    }
    return k+1;
}

// TIME COMPLEXITY= O(N)
// SPACE COMPLEXITY= O(1)