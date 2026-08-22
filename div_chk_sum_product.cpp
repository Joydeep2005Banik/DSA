#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkDivisibility(int n) {
        int temp=n;
        int digitSum=0;
        int digitProduct=1;
        while(n!=0)
        {
            int rem=n%10;
            digitSum+=rem;
            digitProduct=digitProduct*rem;
            n=n/10;
        }
        return temp%(digitSum+digitProduct)==0;
    }
};