/*
3875. Construct Uniform Parity Array I

You are given an array nums1 of n distinct integers.

You want to construct another array nums2 of length n such that the elements in nums2 are either all odd or all even.

For each index i, you must choose exactly one of the following (in any order):

nums2[i] = nums1[i]
nums2[i] = nums1[i] - nums1[j], for an index j != i
Return true if it is possible to construct such an array, otherwise, return false.

 

Example 1:

Input: nums1 = [2,3]

Output: true

Explanation:

Choose nums2[0] = nums1[0] - nums1[1] = 2 - 3 = -1.
Choose nums2[1] = nums1[1] = 3.
nums2 = [-1, 3], and both elements are odd. Thus, the answer is true​​​​​​​.
Example 2:

Input: nums1 = [4,6]

Output: true

Explanation:​​​​​​​

Choose nums2[0] = nums1[0] = 4.
Choose nums2[1] = nums1[1] = 6.
nums2 = [4, 6], and all elements are even. Thus, the answer is true.
 

Constraints:

1 <= n == nums1.length <= 100
1 <= nums1[i] <= 100
nums1 consists of distinct integers.
*/

/*
INITIAL INTUITION:

-> if nums1 is either entirely even/odd copy it to num2 as it is. even/odd can be checked by traversing the
    nums1 and performing %2. 
-> if the above step fails to provide an answer, we know the array has mixed evens and odds
-> since we know, even-odd=odd, odd-even=odd, odd-odd=even and even-even=even

                SUBTRACTING ODD NUMBER CHANGES PARITY
                    EVEN-ODD=ODD
                    ODD-ODD=EVEN
        
    there arises some cases:
    a. Can we make all elements Even?

        -> Any element that is already even can just stay nums1[i].
        -> Any element that is odd needs to become even.
        -> To turn an odd number into an even number, we must subtract another odd number: odd-odd=even
        -> Therefore, for each odd number at index i, we need another odd number at some index j!=i.
        -> This is possible if and only if there are at least two odd numbers in nums1.
        -> If there is only 1 odd number, that single odd number has no other odd number to subtract from it, so it can never become even.

    b. Can we make all elements Odd?
    
        -> Any element that is already odd can just stay nums1[i].
        -> Any element that is even needs to become odd.
        -> To turn an even number into an odd number, we must subtract an odd number: even-odd=odd
        -> For each even number at index i, we need an odd number at some index j!=i
        -> Since i is even and j is odd, j can never equal i.
        -> Therefore, as long as there is at least one odd number anywhere in nums1, every even number can pick that odd number and become odd.

CONCLUSION:
-> there will always be a possibility to construct nums2
-> since the function only returns bool we actually dont need to perform calculations and only need to just check the possibility


*/







#include<bits/stdc++.h>
using namespace std;
bool uniformArray(vector<int>&nums1)
{
    return true;
}

// TIME COMPLEXITY= O(1)
// SPACE COMPLEXITY= O(1)