
// leetcode question no. - 165

/*
INITIAL INTUITION:-
-> parse the string from the dot(.) and compare revision.
-> problems faced:-
    a. the first revision will get omitted if we only do size_t dot +1 so we also need to do -1
    b. doing the parsing we need to traverse the entire string which is hectic
    c. there is no solution for in-place storing the revisions so we may need to use vectors which will increase space complexity
    d. when comparing revisions with leading zeros, the comaprison will be based on octal system. doing this type 
        of comparison throughout the iteration may break the comparison mechanism
*/

/*
OPTIMAL APPROACH:-
a. we traverse through length of version1 or version2 which ever is longest
b. for version1, we traverse through the string until we hit a dot(.) i.e. version. simultaneously, we convert the substring to integer 
    using the equation:- num=num*10 + (version1[i]-'0')
                                      this part turns char to int using ASCII codes
    then we increment the version1 pointer by 1.
c. the similiar process goes for version2 and then incrementing version2 pointer by 1.
d. then we compare version1 and version2. and return if appropriate condition is found.
    it doesnt matter if revisions are still pending since the revisions are in heirarchial order
    if no condition satisfies we increment both version pointers by 1 for next iteration or revision.
e. thus this segregrates the revisions in each iteration and also turns them to int for decimal comparison by removing leading zeros.

*/


#include<bits/stdc++.h>
using namespace std;

int compareRevisions(string version1, string version2)
{
    int n1=version1.size();
    int n2=version2.size();

    for(int i=0,j=0;i<n1 || j<n2;)
    {
        int num1=0;
        while(i<n1 && version1[i]!='.')
        {
            num1=num1*10 + (version1[i]-'0');
            i++;
        }
        int num2=0;
        while(j<n2 && version2[j]!='.')
        {
            num2=num2*10 + (version2[j]-'0');
            j++;
        }
        if(num1<num2)
            return -1;
        else if(num1>num2)
            return 1;
        i++;
        j++;
    }
    return 0;
}

/* TIME COMPLEXITY= O(max(n1, n2))      where n1=size of version1 and n2=size of version2

    SPACE COMPLEXITY= O(1)

*/