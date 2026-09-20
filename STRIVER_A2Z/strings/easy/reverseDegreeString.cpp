// leetcode question number = 3498

/*
INTUITION:-

-> create a hashmap that maps values 26 to 1 for characters 'a' to 'z'.
-> thus, iterate from 'a' to 'z' and assign values 26 to 1 respectively.
-> then iterate through the string s character wise.
-> since we know the respective char values from the hashmap, the formula for total sum becomes:-

            total sum= total sum + (character value * [index position +1])

-> we do index position +1 for 1-based indexing.

*/

// code:-

#include<bits/stdc++.h>
using namespace std;
int reverseDegree(string s)
{
    unordered_map<char,int>mp;
    int val=26;
    for(char ch='a'; ch<='z'; ch++)
    {
        mp[ch]=val--;
    }
    int sum=0;
    for(int i=0;i<s.length();i++)
    {
        sum+=(i+1)*mp[s[i]];
    }
    return sum;
}

//TIME COMPLEXITY = O(26 + N) = O(N)
// SPACE COMPLEXITY = O(N); since the map consists of finite exactly 26 pairs