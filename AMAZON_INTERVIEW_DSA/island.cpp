#include<bits/stdc++.h>
using namespace std;
//using set since set only stores unique value 
/*
x=starting position for island
o=out of bounds or when grid[i][j]=0
u=moving up
d=moving down
l=moving left
r=moving right
*/


string func(vector<vector<int>>& grid, int i, int j, string start)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
        return "o";
    
    grid[i][j] = 0;
    
    string left  = func(grid, i, j - 1, "l");
    string right = func(grid, i, j + 1, "r");
    string up    = func(grid, i - 1, j, "u");
    string down  = func(grid, i + 1, j, "d");

    return start + left + right + up + down;
}

int island(vector<vector<int>>& grid)
{
    if (grid.empty())
        return 0;
    
    set<string> combination;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                string path = func(grid, i, j, "x");
                combination.insert(path);
            }
        }
    }
    return combination.size();
}

int main()
{
    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1}
    };
    
    cout << island(grid) << endl; 
    return 0;
}