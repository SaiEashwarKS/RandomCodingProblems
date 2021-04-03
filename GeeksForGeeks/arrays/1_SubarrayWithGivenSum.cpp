#if 0
PROBLEM STATEMENT
Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.
Example :
Input:
N = 10, S = 15
A[] = {1,2,3,4,5,6,7,8,9,10}
Output: 1 5
Explanation: The sum of elements 
from 1st position to 5th position
is 15.
#endif


#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Function to find the subarray with given sum k
    // arr: input array
    // n: size of array
    vector<int> subarraySum(int arr[], int n, int s){
        
        int sum = arr[0];
        int end = 0;
        int start = 0;
        while(start < n && end < n)
        {
            if(sum == s)
                return vector<int>{start + 1, end + 1};
            if(sum > s)
            {
                sum -= arr[start];
                ++start;
                //sum -= arr[end-1];
            }
            else
            {
                ++end;
                sum += arr[end];
            }
        }
        return vector<int>{-1};
        
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
