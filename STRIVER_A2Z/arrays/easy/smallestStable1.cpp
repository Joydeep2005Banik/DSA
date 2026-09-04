// leetcode question = 3903



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

