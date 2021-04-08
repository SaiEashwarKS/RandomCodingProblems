#if 0
Given an unsorted array of size N. Find the first element in array such that all of its left elements are smaller and all right elements to it are greater than it.

Note: Left and right side elements can be equal to required element. And extreme elements cannot be required element.

Example 1:

Input:
N = 4
A[] = {4, 2, 5, 7}
Output:
5
Explanation:
Elements on left of 5 are smaller than 5
and on right of it are greater than 5.
 

Example 2:

Input:
N = 3
A[] = {11, 9, 12}
Output:
-1

Your Task:  
You don't need to read input or print anything. Your task is to complete the function findElement() which takes the array A[] and its size N as inputs and returns the required element. If no such element present in array then return -1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
3 <= N <= 10^6
1 <= A[i] <= 10^6

#endif  

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


int findElement(int arr[], int n) {
    //the number should be greater than max element to its left and 
    // smaller than min element to its right
    int rmin[n]; //rmin[i] => min element to the right of arr[i]
    int lmax[n];
    lmax[1] = arr[0];
    rmin[n-2] = arr[n-1];
    for(int i = 2; i < n-1; ++i)
    {
        lmax[i] = max(lmax[i-1], arr[i-1]);
    }
    for(int i = n-3; i > 0; --i)
    {
        rmin[i] = min(rmin[i+1], arr[i+1]);
    }
    for(int i = 1; i < n-1; ++i)
    {
        if(arr[i] >= lmax[i] && arr[i] <= rmin[i])
            return arr[i];
    }
    return -1;
}
