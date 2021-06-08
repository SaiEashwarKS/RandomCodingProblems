#if 0
Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

Example 1:
Input:
N = 16
A[]={0,8,4,12,2,10,6,14,1,9,5
     13,3,11,7,15}
Output: 6
Explanation:Longest increasing subsequence
0 2 6 9 13 15, which has length 6

Example 2:
Input:
N = 6
A[] = {5,8,3,7,9,1}
Output: 3
Explanation:Longest increasing subsequence
5 7 9, with length 3
Your Task:
Complete the function longestSubsequence() which takes the input array and its size as input parameters and returns the length of the longest increasing subsequence.

Expected Time Complexity : O( N*log(N) )
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 10^5
0 ≤ A[i] ≤ 10^6
#endif

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    bool compare(int a, int b)
    {
        return a < b;
    }
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int arr[])
    {
       // your code here
       vector<int> dp(n);
       int numPiles = 0;
       int temp;
       for(int i = 0; i < n; ++i)
       {
           temp = arr[i];
           auto it = find_if(dp.begin(), dp.begin()+numPiles, [temp](int a){return a >= temp;});
           if(it == dp.begin()+numPiles)
           {
               *(dp.begin()+numPiles) = arr[i];
               ++numPiles;
           }
           else
           {
               *it = arr[i];
           }
       }
       return numPiles;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends
