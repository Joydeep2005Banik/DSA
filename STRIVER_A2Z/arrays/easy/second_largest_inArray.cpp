/*
arr=[3,7,2,6,5]
output=6
largest element is 7 so second largest element is 6

brute force= sort the array and return the n-2 element
            Time Complexity= O(n log n)
            Space Complexity= O(log n)

Optimal Approach= use a 2 pointer approach->prev and curr. init prev=-1 and curr=arr[0] and iterate.
                  if arr[i]>curr, this means we got 1st largest. prev=curr and curr=arr[i]
                  else if arr[i]>prev and arr[i]!=curr -> prev=arr[i]
                  and finally return prev
*/

#include<bits/stdc++.h>
using namespace std;

int secondLargest(vector<int>&nums)
{
    int prev=-1;
    int curr=nums[0];
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>curr)
        {
            prev=curr;
            curr=nums[i];
        }
        else if(nums[i]>prev && nums[i]!=curr)
            prev=nums[i];
    }
    return prev;
}
int main()
{
    vector<int>arr={3,7,2,6,5};
    cout<<secondLargest(arr);
    return 0;
}