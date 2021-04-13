#if 0
Given a string s, remove all its adjacent duplicate characters recursively. 

Example 1:

Input:
S = "geeksforgeek"
Output: "gksforgk"
Explanation: 
g(ee)ksforg(ee)k -> gksforgkâ€‹

Example 2:

Input: 
S = "acaaabbbacdddd"
Output: "acac"
Explanation: 
ac(aaa)(bbb)ac(dddd) -> acac

Your Task:
You don't need to read input or print anything. Your task is to complete the function remove() which takes the string S as input parameter and returns the resultant string.


Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)


Constraints:
1<=|S|<=10^5
#endif

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
public:
    string removeUtil(string s){
        int n = s.size();
        int i = 0;
        string res;
        while(i < n)
        {
            if(i < n-1 && s[i] == s[i+1])
            {
                while(i < n-1 && s[i] == s[i+1])
                {
                    ++i;
                }
            }
            else
            {
               res.push_back(s[i]);
            }
            ++i;
        }
        return res;
    }
    string remove(string s)
    {
        string res = s;
        string temp;
        while(temp.size() != res.size())
        {
            temp = res;
            res = removeUtil(res);
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.remove(s) << "\n";
    }
    return 0;
}  // } Driver Code Ends
