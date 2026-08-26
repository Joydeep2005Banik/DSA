/*
leetcode question-283

Brute Force Approach:-
if nums[i]=0 -> then check the next nonzero element from i; that is from i to nums.size() and return
                the index of the nonzero element
after that swap(nums[i],nums[nonzeroindex])
Time Complexity= O(n^2)


Optimal Approach:-
while iterating check if nums[i] is a non-zero element.
    if yes, swap(nums[lastNonZeroIndex], nums[i]) and increment lastNonZeroIndex by +1
the advantage is that we dont need to do another pass looking for next zeroth element unlike brute force
Time Complexity=O(n)
*/
#include<bits/stdc++.h>
using namespace std;


void moveZeros(vector<int>&nums)
{
    int lastNonZero=0;

    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]!=0)
        {
            swap(nums[lastNonZero],nums[i]);
            lastNonZero++;
        }
    }
}
int main()
{
    vector<int>arr = {0,1,0,3,12};
    moveZeros(arr);
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}