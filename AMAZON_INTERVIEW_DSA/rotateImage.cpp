#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>&arr)
{
    if(arr.empty()==true || arr.size()==0)
        return;
    int n=arr.size();
    //transpose
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        swap(arr[i][j],arr[j][i]);
    }
    //reverse
    for(int i=0;i<n;i++)
    {
        for(int j=0,k=n-1;j<k;j++,k--)
        swap(arr[i][j],arr[i][k]);
    }
}

void printMatrix(const vector<vector<int>>& arr)
{
    for(const auto& row : arr) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
}
int main()
{
    vector<vector<int>>arr={{1,2,3},{4,5,6},{7,8,9}};
    rotate(arr);
    printMatrix(arr);
    return 0;
}