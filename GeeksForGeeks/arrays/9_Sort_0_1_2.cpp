#if 0
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.


Example 1:
Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.

Example 2:
Input: 
N = 3
arr[] = {0 1 0}
Output:
0 0 1
Explanation:
0s 1s and 2s are segregated 
into ascending order.

Your Task:
You don't need to read input or print anything. Your task is to complete the function sort012() that takes an array arr and N as input parameters and sorts the array in-place.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
1 <= N <= 10^6
0 <= A[i] <= 2
#endif


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        //sort(a, a+n); only this works as well
        int l = 0;
        int r = n-1;
        int m = 0;
        while(m <= r)
        {
            if(a[m] == 0)
            {
                swap(a[l], a[m]);
                ++l;
                ++m;
            }
            else if (a[m] == 1)
            {
                ++m;
            }
            else
            {
                swap(a[m], a[r]);
                --r;
            }
        }
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends
