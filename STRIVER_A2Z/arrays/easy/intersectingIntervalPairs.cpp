/*
Q1. Number of Intersecting Interval Pairs I
Easy
3 pt.

You are given a 2D integer array intervals of n elements, where intervals[i] = [starti, endi] represents the closed interval from starti to endi.

Return the number of pairs of indices (i, j) such that 0 <= i < j < n and intervals[i] and intervals[j] intersect.

Two intervals intersect if they have at least one point in common, including when they only share an endpoint.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4]]

Output: 2

Explanation:

There are 2 intersecting interval pairs:

    Intervals [1, 2] and [2, 3] intersect at the point 2.
    Intervals [2, 3] and [3, 4] intersect at the point 3.

Example 2:

Input: intervals = [[1,5],[2,4],[3,6]]

Output: 3

Explanation:

There are 3 intersecting interval pairs:

    The intersection of [1, 5] and [2, 4] is [2, 4].
    The intersection of [1, 5] and [3, 6] is [3, 5].
    The intersection of [2, 4] and [3, 6] is [3, 4].

Example 3:

Input: intervals = [[1,2],[3,4],[5,6]]

Output: 0

Explanation:

There are no intersecting interval pairs. Hence, the answer is 0.

 

Constraints:

    2 <= n == intervals.length <= 100
    intervals[i] = [starti, endi]
    0 <= starti <= endi <= 100

*/


/*
BRUTE FORCE APPROACH:-

-> if arr=[[a,b],[c,d]] then the condition for pair is only met if max[a,b] < min[c,d]
-> iterate i from 0 to n-1
-> iterate j fom i+1 to n-1
-> check if max(start[i], start[j]) < min(end[i], end[j])
-> if true increment counter
-> return counter.

TIME COMPLEXITY = O(N^2)
SPACE COMPLEXITY = O(1)

995/995 TESTCASES PASSED
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int counter=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int start_a=intervals[i][0];
                int start_b=intervals[j][0];
                int end_a=intervals[i][1];
                int end_b=intervals[j][1];
                if(max(start_a, start_b)<=(min(end_a, end_b)))
                counter++;
            }
        }
        return counter;
    }
};