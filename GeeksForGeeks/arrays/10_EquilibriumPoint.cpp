#if 0
Given an array A of n positive numbers. The task is to find the first Equilibium Point in the array. 
Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

Example 1:
Input:
n = 1
A[] = {1}
Output: 1
Explanation: Since its the only 
element hence its the only equilibrium 
point. 

Example 2:
Input:
n = 5
A[] = {1,3,5,2,2}
Output: 3
Explanation: For second test case 
equilibrium point is at position 3 
as elements before it (1+3) = 
elements after it (2+2).
 

Your Task:
The task is to complete the function equilibriumPoint() which takes the array and n as input parameters and returns the point of equilibrium. Return -1 if no such point exists.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= n <= 10^6
1 <= A[i] <= 10^8
#endif


// { Driver Code Starts
#include <iostream>
using namespace std;
// } Driver Code Ends

class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    
    long long sum(long long a[], int n)
    {
        long long res = 0;
        
        for(int i = 0; i < n; ++i)
            res += a[i];
    
        return res;
    }
    
    int equilibriumPoint(long long a[], int n) {
        
        if(n == 1)
        {
            return 1;
        }
    
        int total_sum = sum(a, n);
        int left_sum = 0;
        int right_sum;
        for(int i = 1; i < n; ++i)
        {
            left_sum += a[i-1];
            right_sum = total_sum - left_sum - a[i];
            if(left_sum == right_sum && i != n-1)
                return i+1;
        }
        return -1;
    }

};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
