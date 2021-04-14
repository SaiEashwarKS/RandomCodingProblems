#if 0
Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
I 1
V 5
X 10
L 50
C 100
D 500
M 1000

Example 1:
Input:
s = V
Output: 5
 
Example 2:
Input:
s = III 
Output: 3
Your Task:
Complete the function romanToDecimal() which takes an string as input parameter and returns the equivalent decimal number. 

Expected Time Complexity: O(|S|), |S| = length of string S.
Expected Auxiliary Space: O(1)

Constraints:
1<=roman no range<=3999
#endif

// { Driver Code Starts
// Initial template for C++

// Program to convert Roman Numerals to Numbers
#include <bits/stdc++.h>
using namespace std;

// Returns decimal value of roman numaral
int romanToDecimal(string &);

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << romanToDecimal(s) << endl;
    }
}// } Driver Code Ends


// User fuunction teemplate for C++

// str given roman number string
// Returns decimal value of roman numaral
int util(char c)
{
    switch(c)
    {
        case 'I' : return 1;
        break;
        case 'V' : return 5;
        break;
        case 'X' : return 10;
        break;
        case 'L' : return 50;
        break;
        case 'C' : return 100;
        break;
        case 'D' : return 500;
        break;
        case 'M' : return 1000;
        break;
    }
}
int romanToDecimal(string &str) {
    // code here
    int res = 0;
    for(int i = 0; i < str.size(); ++i)
    {
        int next = -1;
        if(i != str.size() - 1)
            next = util(str[i+1]);
        int curr = util(str[i]);
        if(next > curr)
            res -= curr;
        else
            res += curr;
    }
    return res;
}
