#if 0
Given a string S, find length of the longest substring with all distinct characters. 

Example 1:
Input:
S = "geeksforgeeks"
Output: 7
Explanation: "eksforg" is the longest 
substring with all distinct characters.

Example 2:
Input: 
S = "aaa"
Output: 3
Explanation: "a" is the longest substring 
with all distinct characters.

Your Task:
You don't need to read input or print anything. 
Your task is to complete the function longestSubstrDitinctChars() which takes the string S as input and returns the length of the longest substring with all distinct characters.


Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).


Constraints:
1<=|S|<=10^5
#endif

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDitinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDitinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int longestSubstrDitinctChars (string S)
{
    // your code here
    int count = 1;
    int maxCount = 1;
    unordered_map<char, int> map;
    map[S[0]] = 1;
    int start = 0;
    for(int i = 1; i < S.size(); ++i)
    {
        auto found = map.find(S[i]);
        if(found != map.end())
        {
            maxCount = max(maxCount, count);
            count = 1;
            map.clear();
            ++start;
            i = start;
            map[S[i]] = 1;
        }
        else
        {
            map[S[i]] = 1;
            ++count;
        }
    }
    maxCount = max(count, maxCount);
    return maxCount;
}
