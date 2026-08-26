#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) 
{
    vector<int>ans={};
    map<int,int>pairs;
    for(int i=0;i<nums.size();i++)
    {
        int sum=target-nums[i];
        if(pairs.find(sum)!=pairs.end())
        {
            ans.push_back(pairs[sum]);
            ans.push_back(i);
            return ans;
        }
        pairs[nums[i]]=i;
    }
    return ans;
}

int main()
{
    vector<int>arr={2,7,11,15};
    int target=10;
    vector<int>res=twoSum(arr,target);
    for(int i:res)
    cout<<i<<",";
    return 0;
}