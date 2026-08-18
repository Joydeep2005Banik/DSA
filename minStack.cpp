#include<bits/stdc++.h>
using namespace std;

class MinStack
{
    public:
    stack<int> s;
    stack<int> t;

    MinStack()
    {
        s = {};
        t = {};
    }
    void push(int value)
    {
        int min=0;
        s.push(value);
        if(t.empty()==true || value<t.top())
        min=value;
        else
        min=t.top();
        t.push(min);
    }
    void pop()
    {
        s.pop();
        t.pop();
    }
    int top()
    {
        s.top();
    }
    int getMin()
    {
        return t.top();
    }
};