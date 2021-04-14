#if 0
Given two strings a and b consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, “act” and “tac” are an anagram of each other.

Example 1:

Input:
a = geeksforgeeks, b = forgeeksgeeks
Output: YES
Explanation: Both the string have same
characters with same frequency. So, 
both are anagrams.
Example 2:

Input:
a = allergy, b = allergic
Output: NO
Explanation:Characters in both the strings
are not same, so they are not anagrams.
Your Task:
You don't need to read input or print anything.Your task is to complete the function isAnagram() which takes the string a and string b as input parameter and check if the two strings are an anagram of each other. The function returns true if the strings are anagram else it returns false.

Expected Time Complexity: O(|a|+|b|).
Expected Auxiliary Space: O(Number of distinct characters).

Note: |s| represents the length of string s.

Constraints:
1 ≤ |a|,|b| ≤ 10^5
#endif

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    /*  Function to check if two strings are anagram
    *   a, b: input string
    */
    bool isAnagram(string a, string b){
        
        // Your code here
        unordered_map<char, int> mp;
        int i = 0;
        while(a[i] != '\0')
        {
            auto it = mp.find(a[i]);
            if(it == mp.end())
            {
                mp[a[i]] == 0;
            }
            ++mp[a[i]];
            ++i;
        }
        i = 0;
        while(b[i] != '\0')
        {
            auto it = mp.find(b[i]);
            if(it != mp.end())
            {
                --mp[b[i]];
            }
            else
            {
                mp[b[i]] = 1;
            }
            ++i;
        }
        for(auto it = mp.begin(); it != mp.end(); ++it)
        {
            if(it->second != 0)
                return false;
        }
        return true;
    }

};

// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
  // } Driver Code Ends
