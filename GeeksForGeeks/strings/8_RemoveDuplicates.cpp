#if 0
Given a string without spaces, the task is to remove duplicates from it.

Note: The original order of characters must be kept the same. 

Example 1:

Input: S = "zvvo"
Output: "zvo"
Explanation: Only keep the first
occurrence
Example 2:

Input: S = "gfg"
Output: gf
Explanation: Only keep the first
occurrence
Your task:
Your task is to complete the function removeDups() which takes a single string as input and returns the string. You need not take any input or print anything.
 

Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(constant)

Constraints:
1 <= |S| <= 10^5
S conatins lowercase english alphabets
#endif

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	string removeDups(string S) 
	{
	    // Your code goes here
	    unordered_set<char> mp;
	    string res;
	    for(int i = 0; i < S.size(); ++i)
	    {
	        auto it = mp.find(S[i]);
	        if(it == mp.end())
	        {
	            res.push_back(S[i]);
	            mp.insert(S[i]);
	        }
	    }
	    return res;
	}
};

// { Driver Code Starts.


int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   		
   		Solution ob;
   		cout << ob.removeDups(s) << "\n";
   		
   	}

    return 0;
}  // } Driver Code Ends
