#if 0
Given a array of N strings, find the longest common prefix among all strings present in the array.

Example 1:
Input:
N = 4
arr[] = {geeksforgeeks, geeks, geek,
         geezer}
Output: gee
Explanation: "gee" is the longest common
prefix in all the given strings.

Example 2:
Input: 
N = 2
arr[] = {hello, world}
Output: -1
Explanation: There's no common prefix
in the given strings.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestCommonPrefix() which takes the string array arr[] and its size N as inputs and returns the longest common prefix common in all the strings in the array. If there's no prefix common in all the strings, return "-1".


Expected Time Complexity: O(N*max(|arri|)).
Expected Auxiliary Space: O(max(|arri|)) for result.


Constraints:
1<=N<=10^3
1<=|arri|<=10^3
#endif


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string res = "";
        int i = 0;
        int n1 = arr[0].size();
        char ch;
        while(i < n1)
        {
            ch = arr[0][i];
            for(int j = 1; j < N; ++j)
            {
                if(i >= arr[j].size() || arr[j][i] != ch)
                {
                    if(res != "")
                        return res;
                    return "-1";
                }
            }
            res.push_back(ch);
            ++i;
        }
        return res;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends
