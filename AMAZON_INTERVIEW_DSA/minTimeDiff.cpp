#include<bits/stdc++.h>
using namespace std;

int findMinDifference(vector<string>& timePoints) 
{
    vector<bool>bucket(1440);
    for(string time: timePoints)
    {
        size_t pos=0;
        int hours=stoi(time,&pos);
        int mins=stoi(time.substr(pos+1));
        int total=hours*60 + mins;
        if (bucket[total]==true)
            return 0;
        bucket[total]=true;
    }
    int minimum=INT_MAX;
    int prev=-1;
    int curr=-1;
    int first =-1;
    for(int i=0;i<bucket.size();i++)
    {
        if(bucket[i]==true)
        {
            if(prev==-1)
            {
                prev=i;
                first=i;
            }
            else
            {
                curr=i;
                minimum=min(minimum,curr-prev);
                prev=curr;
            }
        }
    }
    return min(minimum,1440-curr+first);
}
int main()
{
    vector<string>time={"01:01","02:01"};
    cout<<findMinDifference(time);
    return 0;
}