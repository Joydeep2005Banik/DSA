#include<bits/stdc++.h>
using namespace std;

bool isVowel(char ch) {
    ch = tolower(static_cast<unsigned char>(ch));
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

string reverseVowels(string s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) 
    {      
        bool isLeft=isVowel(s[left]);
        bool isRight=isVowel(s[right]);
        if(isLeft== true && isRight==true)
        {
            swap(s[left],s[right]);
            left++;
            right--;
        }
        if(isLeft!=true)
            left++;
        if(isRight!=true)
            right--;
    }

    return s;
}

int main() {
    string s = "hello";
    cout << reverseVowels(s) << endl;
    return 0;
}