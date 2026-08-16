#include<bits/stdc++.h>
using namespace std;

int peak(vector<int>&arr)
{
    int n=arr.size();
    int start=0;
    int end=n-1;
    while(start<end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]<arr[mid+1])
        start=mid+1;
        else if(arr[mid]>arr[mid+1])
        end=mid;
        else
        end--;
    }
    return start;
}


/*
int peak(vector<int>&arr)
{
    int n=arr.size();
    int peakindex=0;
    if(n==0) return -1;

    for (int i=0;i<n;i++)
    {
        if(arr[i]>arr[i+1])
        return i;
    }
    return n-1;
}
*/






int main()
{
    vector<int> arr = {1,2,4,4,4,9,5};
    cout<<"peak is "<<peak(arr);
    return 0;
}