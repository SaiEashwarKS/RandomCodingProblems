#if 0
Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd


Example 1:
Input: str = "abcd"
Output: 3
Explanation: Inserted character marked
with bold characters in dcbabcd

Example 2:
Input: str = "aa"
Output: 0
Explanation:"aa" is already a palindrome.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function countMin() which takes the string str as inputs and returns the answer.

Expected Time Complexity: O(N2), N = |str|
Expected Auxiliary Space: O(N2)

Constraints:
1 ≤ |str| ≤ 103
str contains only lower case alphabets.


#endif


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int countMin(string str){
    //complete the function here
        int n = str.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int l = n; l >= 0; --l)
        {
            for(int h = l + 1; h < n; ++h)
            {
                dp[l][h] = (str[l] == str[h]) ?
                            dp[l+1][h-1] :
                            (min(dp[l+1][h], dp[l][h-1]) + 1);
            }
        }
        return dp[0][n-1];
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}

  // } Driver Code Ends
