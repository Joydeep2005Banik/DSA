// leetcode question number = 3904

/*
INITIAL INTUITION:-

-> we can see that the minimum suffix is dynamic i.e. for every max element the min element changes
-> thus we iterate an outer loop from 0 to n in which we find the max element of nums for every iteration
-> we initialise the variable to store the min element early inside the outer loop (comes in handy later)
-> we run an inner loop from i to n in which we find the min element of the remaining subarray for that particular max value
-> inside the outer loop we calculate the instability and check if it is <=k
-> if true we find the minimum stability since there can be multiple stability<=k
-> during the next outer loop iteration the min element variable gets re-initialised to be used only for the next max variable
-> if the min. stability=INT_MAX we know that the stability condition wasnt matched and we return -1
-> else we return stability value

TIME COMPLEXITY = O(N^2)
SPACE COMPLEXITY=O(N)
*/

/*
OPTIMAL APPROACH:-

-> we use a vector for the min suffix to store the min values from n-2 to 0 and nums[n-1] is guaranteed to be a min value
-> in a seperate iteration run we find the max element of the prefix side
-> still inside the iteration run only, we calculate the instability and check <=k
-> if true we immediately return the index since the first index is guaranteed to be the minimum index position
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0)
            return -1;
        vector<int>suffMin(n);
        suffMin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffMin[i]=min(nums[i],suffMin[i+1]);
        }
        int prefMax=INT_MIN;
        for(int i=0;i<n;i++)
        {
            prefMax=max(prefMax,nums[i]);
            int instability=prefMax-suffMin[i];
            if(instability<=k)
                return i;
        }
        return -1;

    }
};

// TIME COMPLEXITY=O(N)
// SPACE COMPLEXITY=O(N)