/*
arr=[2,4,6,7,3]
output=7

brute force:- sort the array and return n-1 element
                time complexity=O(n logn), space complexity =O(log n)

optimal approach:- iterate from 0 to size of arr, init a largest var with lowest integer possible and find
            the min val between largest and arr[i]
            Time Complexity=O(n)
            Space Complexity=O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int largestnum(vector<int>&nums)
{
    int largest=INT_MIN;
    for(int i=0;i<nums.size();i++)
    largest=max(largest,nums[i]);
    return largest;
}
int main()
{
    vector<int>arr={1,4,2,5,7,3};
    cout<<largestnum(arr);
    return 0;
}