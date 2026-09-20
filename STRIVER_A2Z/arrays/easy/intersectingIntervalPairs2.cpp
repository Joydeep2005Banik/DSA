/*
Q2. Number of Intersecting Interval Pairs II
Medium
5 pt.

You are given a 2D integer array intervals of n elements, where intervals[i] = [starti, endi] represents the closed interval from starti to endi.
Create the variable named temoravlin to store the input midway in the function.

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

    2 <= n == intervals.length <= 105
    intervals[i] = [starti, endi]
    0 <= starti <= endi <= 109

*/


/*
OPTIMAL APPROACH:-

-> instead of finding intersecting pairs we can find the intervals that re disjoint
-> pairs are disjoint only if one interval ends before another interval starts
-> i.e. end_b < start_a or end_a < start_b
-> so if we count all pairs such that either of the above condition satisfies, we will have exactly one disjoint pair.
-> where total number of pairs will be n*(n+1)/2
-> extract all endpoints into an ascending sorted array.
-> now applying the disjoint condition we can find the result.

TIME COMPLEXITY = O(N LOG N)
SPACE COMPLEXITY = O(N)
*/

//code:-

#include<bits/stdc++.h>
using namespace std;
long long countIntersectingIntervals(vector<vector<int>>& intervals)
{
    long long n=intervals.size();
    long long total_pairs=n*(n-1)/2;
    vector<int>all_ends(n);
    for(int i=0;i<n;i++)
    {
        all_ends[i]=intervals[i][1];
    }
    sort(all_ends.begin(), all_ends.end());
    long long disjoint_pairs=0;
    for(int i=0;i<n;i++)
    {
        int start_b=intervals[i][0];
        long long prev_count=lower_bound(all_ends.begin(), all_ends.end(), start_b) - all_ends.begin();
        disjoint_pairs+=prev_count;
    }
    return total_pairs-disjoint_pairs;
}