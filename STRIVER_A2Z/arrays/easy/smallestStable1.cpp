// leetcode question = 3903

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
*/

#include<bits/stdc++.h>
using namespace std;
int smallestStableInteger(vector<int>&nums, int k)
{
    int n=nums.size();
    int largest=INT_MIN;
    int instability=0;
    int stable=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int smallest=INT_MAX;
        largest=max(largest,nums[i]);
        for(int j=i;j<n;j++)
        {
            smallest=min(smallest,nums[j]);
        }
        instability=largest-smallest;
        if(instability<=k)
        {
            stable=min(stable,i);
        }
        
    }
    if(stable==INT_MAX)
        return -1;
    else
        return stable;
}

// TIME COMPLEXITY = O(N^2)
// SPACE COMPLEXITY = O(1)