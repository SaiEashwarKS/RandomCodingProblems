#if 0
Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.
 

Example 1:

Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
Output: 106
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3, 100}

Example 2:
Input: N = 3, arr[] = {1, 2, 3}
Output: 6
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3}

Your Task:  
You don't need to read input or print anything. Complete the function maxSumIS() which takes N and array arr as input parameters and returns the maximum value.


Expected Time Complexity: O(N^2)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 10^3
1 ≤ arr[i] ≤ 10^5
#endif

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> dp(n);
	    dp[0] = arr[0];
	    int res = arr[0];
	    for(int i = 1; i < n; ++i)
	    {   
	        int prev_res = INT_MIN;
	        int j = i-1;
	        while(j >= 0)
	        {
	            if(arr[j] < arr[i])
	            {
	                prev_res = max(prev_res, dp[j]);
	            }
	            --j;
	        }
	        if(prev_res == INT_MIN)
	        {
	            dp[i] = arr[i];
	        }
	        else
	        {
	            dp[i] = prev_res + arr[i];
	        }
	        res = max(res, dp[i]);
	    }
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
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends
