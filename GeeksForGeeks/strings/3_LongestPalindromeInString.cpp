#if 0
Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). 
Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. 
Incase of conflict, return the substring which occurs first ( with the least starting index).

Example 1:
Input:
S = "aaaabbaa"
Output: aabbaa
Explanation: The longest Palindromic
substring is "aabbaa".

Example 2:
Input: 
S = "abc"
Output: a
Explanation: "a", "b" and "c" are the 
longest palindromes with same length.
The result is the one with the least
starting index.

Your Task:
You don't need to read input or print anything. 
Your task is to complete the function longestPalin() which takes the string S as input and returns the longest palindromic substring of S.

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).
#endif


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

string longestPalin (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


string longestPalin (string S)
{
    // your code here
    #if 0
    The idea is to generate all even length and odd length palindromes and keep track of the longest palindrome seen so far.
    Step to generate odd length palindrome:
    Fix a centre and expand in both directions for longer palindromes.

    Step to generate even length palindrome
    Fix two centre ( low and high ) and expand in both directions for longer palindromes.
    #endif
        
    int maxLength = 1;
    int start = 0;
    int end = 0;
    int n = S.size();
    //find odd palindromes
    for(int i = 1; i < n-1; ++i)
    {
        int l = i - 1;
        int r = i + 1;
        int length = 1;
        while(l >= 0 && r < n && S[l] == S[r])
        {
            length+=2;
            --l;
            ++r;
        }
        if(length > maxLength)
        {
            maxLength = length;
            start = l+1;
            end = r - 1;
        }
    }
    //find even palindromes
    for(int i = 0; i < n-1; ++i)
    {
        if(S[i] == S[i+1])
        {
            int length = 2;
            int l = i-1;
            int r = i+2;
            while(l >= 0 && r < n && S[l] == S[r])
            {
                length+=2;
                --l;
                ++r;
            }
            if(length > maxLength)
            {
                maxLength = length;
                start = l+1;
                end = r - 1;
            }
        }
    }
    string res;
    for(int i = start; i <= end; ++i)
    {
        res.push_back(S[i]);
    }
    return res;
}
