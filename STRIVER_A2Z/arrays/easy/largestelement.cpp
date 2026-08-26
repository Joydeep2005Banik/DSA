/*
arr=[2,4,6,7,3]
output=7
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