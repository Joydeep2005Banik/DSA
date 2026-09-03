// leetcode question=3876

/*
INITIAL INTUITION:-

-> traverse and check if nums1 is odd/even. if true then copy it as it is and return true
-> if above condition doesnt satisfy it means that nums1 is a mixture.
-> parity formulas:
                    even-even=even -> not needed
                    odd-odd=even -> not needed
                    even-odd=odd
                    odd-even=odd

            This means our safest bet will  be to convert all the element to odd

-> the goal would be to convert all the elements to odd.
-> the safest way to ensure that nums1[i]-nums1[j]>=1 stays is by always subtracting the smallest possible element

-> some cases that arises:

    a. CASE 1: There is atleast one odd
        eg=[2,6,4,3,8] -> sort -> [2,3,4,6,8] 
                                    2-3=-1 -> breaks the >=1 condition
                                    4-3=1
                                    6-3=3
                                    8-3=5
        -> one key thing to note that if nums1[0] is even then it is impossible to turn the odd to even
        -> also it it imposiible to turn the even elements to odd(>=1)
        -> thus it amounts to false

        -> however, if nums1=[1,4,8,6,2] after sorting where nums1[0]=odd -> then it is possible amounting to true

        -> thus there is no general solution for case 1
        -> therefore case 1 will always result in false
        -> traverse the array and check if there is atleast one odd -> if yes return false
                

    b. CASE 2: There is atleast one even
        eg=[3,9,4,5,1] -> sort -> [1,3,4,5,9]
                                    nums1[2]=nums1[2]-nums1[0]=4-1=3
        -> identtify the even element position and do nums2[i]=nums1[even]-nums1[smallest odd number] 
        -> if nums2[i]<1 then immediately return false
        -> rest elements will be nums2[i]=nums1[i]
        -> thus nums2=[1,3,3,5,9] -> return true

-> the above cases can be more simplified by:
    a. CASE 1: nums1[0]%2!=0 
        -> this will always result in true
    b. CASE 2: nums1[0]%2==0
        -> this will always result in false
*/






#include<bits/stdc++.h>
using namespace std;
bool uniformArray(vector<int>&nums1)
{
    int evenCount=0;
    for(int i=0;i<nums1.size();i++)
    {
        if(nums1[i]%2==0)
            evenCount++;
    }
    if(evenCount==nums1.size())
        return true;
    int oddCount=0;
    for(int i=0;i<nums1.size();i++)
    {
        if(nums1[i]%2!=0)
            oddCount++;
    }
    if(oddCount==nums1.size())
        return true;
    sort(nums1.begin(),nums1.end());
    if(nums1[0]%2!=0)
        return true;
    return false;   
}
// TIME COMPLEXITY=O(N.log N)
// SPACE COMPLEXITY=O(N) OR O(1)for auxiliarry

/*
OPTIMISED APPROACH:-
-> since we know ans is only true if:
    a. all elements are even
    b. atleast there is one odd (all elements are odd condition also falls in this category)

    thus we can only check these 2 conditions
-> no need to sort we just traverse the array and find the min element
*/

bool uniformParityArr(vector<int>&nums1)
{
    int minimum=INT_MAX;
    int n=nums1.size();
    int evenCount=0;
    for(int i=0;i<n;i++)
    {
        if(nums1[i]%2==0)
        evenCount++;
        minimum=min(minimum,nums1[i]);
    }
    if(evenCount==n || minimum%2!=0)
    return true;
    return false;
}

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(1)