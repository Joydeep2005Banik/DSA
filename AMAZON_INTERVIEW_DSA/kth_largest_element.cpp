//leetcode problem no.-215

#include<bits/stdc++.h>
using namespace std;
int kthLargest(vector<int>&nums,int k)
{
    sort(nums.begin(),nums.end());
    return nums[nums.size()-k];
}
