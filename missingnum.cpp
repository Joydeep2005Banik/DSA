#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) 
{
    int n=nums.size();
    int arithmeticSum=(n*(n+1))/2;
    int actualSum=0;
    for(int i=0;i<n;i++)
        actualSum+=nums[i];
    return arithmeticSum-actualSum;
}
int main()
{
    vector<int>arr={0,1};
    cout<<missingNumber(arr);
    return 0;
}