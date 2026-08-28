//leetcode question no.-27

/*
INTUITION 1-
-> we iterate through the array and if we find arr[i]=val then swap(arr[i],arr[n-1]) and use pop_back to pop the last value.
-> however this doesnt remove all the duplicates in a single pass and edge cases may occur like:
    arr=[3,2,1,3], val=3
    here at arr[0]=val so we swap with arr[n-1] which is also 3 and we pop_back().
    thus the resulting array becomes [3,2,1]. this is a issue to tackle
-> a fix can be that we first sort the array. however it will raise the time complexity to O(Log N)
*/

/*
APPROACH:-
-> the main issue was that after swapping, the index position may still have a duplicate but the index pointer was incrementing.
-> firstly, we can eliminate swapping by just updating the current index value with the end value i.e. arr[i]=arr[n-1]
-> thus, after updating, we reduce the array size and reiterate that position and recheck the equal condition.
    if false, we i++ else we again swap and reduce arr size
*/

#include<bits/stdc++.h>
using namespace std;

int removeElement(vector<int>&arr, int val)
{
    int n=arr.size();

    for(int i=0;i<n;)//no increment here
    {
        if(arr[i]==val)
        {
            arr[i]=arr[n-1];
            n--;
        }
        else   
            i++;
    }
    return n;
}

// TIME COMPLEXITY= O(N)
// SPACE COMPLEXITY= O(1)