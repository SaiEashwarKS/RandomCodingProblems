#if 0
Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

Example 1:

Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole
string(not individual words), the input
string becomes
much.very.program.this.like.i
Example 2:

Input:
S = pqr.mno
Output: mno.pqr
Explanation: After reversing the whole
string , the input string becomes
mno.pqr

Your Task:
You dont need to read input or print anything. Complete the function reverseWords() which takes string S as input parameter and returns a string containing 
the words in reversed order. Each word in the returning string should also be separated by '.' 


Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)


Constraints:
1 <= |S| <= 2000
#endif

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
  public:
    string reverseWords(string S) 
    { 
        // code here 
        string res("");
        int i = S.size() - 1;
        while(i >= 0)
        {
            string temp("");
            while(i >=0 && S[i] != '.')
            {
                temp.push_back(S[i]);
                --i;
            }
            reverse(temp.begin(), temp.end());
            temp.push_back('.');
            res += temp;
            --i;
        }
        res.pop_back();
        return res;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends
