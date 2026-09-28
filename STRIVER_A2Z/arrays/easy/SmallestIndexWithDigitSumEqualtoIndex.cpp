// leetcode question = 3550

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        int smallest_index=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(i==digit_sum(nums[i]))
            {
                smallest_index=min(smallest_index, i);
            }
        }
        if(smallest_index==INT_MAX)
        {
            return -1;
        }
        else
        {
            return smallest_index;
        }
    }
    int digit_sum(int num)
    {
        int sum=0;
        while(num!=0)
        {
            int rem=num%10;
            sum+=rem;
            num/=10;
        }
        return sum;
    }
};

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(1)