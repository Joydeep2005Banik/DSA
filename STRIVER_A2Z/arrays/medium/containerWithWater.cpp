// leetcode question no. - 11

/*
INITIAL INTUITION:-
-> keep one pointer at arr[0](pointer 'i') and another at arr[n-1](ponter 'j)
-> we calculate area by = (j-i) x min(arr[i],arr[j])
-> store the area result in a vector
-> increment i and decrement j and repeat the steps
-> finally, pop the max value of the vector in which we stored the areas.

TIME COMPLEXITY= O(N)
SPACE COMPLEXITY= O(N)

*/

/*
PROBLEMS WITH INTUITION & OPTIMAL APPROACH:-
-> suppose there is arr=[5,1,4,2]. here when i is at arr[0] and j is at arr[3] then area is 3*2=6
-> now when we increment i and decrement j area becomes 1*1=1
-> but we missed a potential max area if i pointed at arr[0] and j pointed at arr[2]. here area would have
    been 2*4=8 which is max
-> thus in order to not miss a potential pair, we move the pointer that points to lower value
    i.e. if arr[i]<arr[j] i++ else j++

-> storing area in vector results in increased space complexity so instead we initialise a max variable 
    that stores the max area in each iteration
*/

#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>height)
{
    int maxArea=INT_MIN;
    int n=height.size();
    for(int i=0,j=n-1;i<j;)
    {
        int area=(j-i)*min(height[i],height[j]);
        maxArea=max(maxArea,area);
        if(height[i]<height[j])
            i++;
        else
            j--;
    }
    return maxArea;
}

// TIME COMPLEXITY=O(N)
// SPACE COMPLEXITY=O(1)