#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>result={};
        vector<int>v2={};
        result.push_back(nums[0]);
        v2.push_back(nums[1]);
        for(int i=2;i<n;i++)
        {
            if(result.back()>v2.back())
                result.push_back(nums[i]);
            else
                v2.push_back(nums[i]);
            
        }
        result.insert(result.end(),v2.begin(),v2.end());
        return result;
    }
};