#include<bits/stdc++.h>
using namespace std;

int missing(vector<int>&arr)
{
    if(arr.empty()==true || arr.size()==0)
        return 1;
    int countOne=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==1)
            countOne=1;
        else if(arr[i]<=0 || arr[i]>arr.size())
            arr[i]=1;
    }
    if(countOne==0)
        return 1;
    
    for(int i=0;i<arr.size();i++)
    {
        int index=abs(arr[i])-1;
        if(arr[index]>0)
            arr[index]=-arr[index];
    }
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>0)
            return (i+1);
    }
    return arr.size()+1;
}
int main()
{
    vector<int>arr={3,4,-1,1};
    cout<<missing(arr)<<endl;
    return 0;
}