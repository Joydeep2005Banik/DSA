#include<bits/stdc++.h>
using namespace std;

int reverse(int num)
{
    long sum=0;
    while(num!=0)
    {
        int rem=num%10;
        sum=(sum*10)+rem;
        if(sum>INT32_MAX || sum<INT32_MIN)
            return 0;
        num/=10;
    }
    return sum;
}

int main()
{
    int num=122345;
    cout<<reverse(num)<<endl;
    return 0;
}