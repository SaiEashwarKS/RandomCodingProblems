#if 0
Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.

Example 1:
Input:
N = 4
arr[] = {1, 5, 3, 2}
Output: 2
Explanation: There are 2 triplets: 
1 + 2 = 3 and 3 +2 = 5 

Example 2:
Input: 
N = 3
arr[] = {2, 3, 4}
Output: 0
Explanation: No such triplet exits
#endif



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 // } Driver Code Ends
//User function template for C++
#include<vector>
#include<algorithm>
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    int count = 0;
	    sort(arr, arr+n);
	    int j, k, sum;
	    for(int i = n-1; i >=0; --i)
	    {
	        j = 0;
	        k = i -1;
	        while(j < k)
	        {
	            sum = arr[j] + arr[k];
	        if(sum == arr[i])
	        {
	            ++count;
	            ++j;
	            --k;
	        }
	        else if(sum < arr[i])
	        {
	            ++j;
	        }
	        else
	        {
	            --k;
	        }
	        }
	        
	    }
	    return count;
	    
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
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}  // } Driver Code Ends
