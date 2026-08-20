#include<bits/stdc++.h>
using namespace std;

string addStrings(string num1,string num2)
{
    int i=num1.size()-1;
    int j=num2.size()-1;
    int carry=0;
    string result;
    while(i>-1 || j>-1)
    {
        int digit1;
        if(i>-1)
            digit1=num1[i]-'0';
        else
            digit1=0;
        int digit2;
        if(j>-1)
            digit2=num2[j]-'0';
        else
            digit2=0;
        
        int sum=digit1+digit2+carry;
        result.push_back((sum%10)+'0');
        carry=sum/10;
        i--;
        j--;
    }
    if(carry==1)
        result.push_back(carry + '0');
    reverse(result.begin(),result.end());
    return result;
}
int main()
{
    string a="2859";
    string b="293";
    cout<<addStrings(a,b);
    return 0;
}