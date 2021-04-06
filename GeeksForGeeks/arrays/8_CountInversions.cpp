#if 0
Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 

Example 1:
Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).

Example 2:
Input: N = 5
arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already 
sorted so there is no inversion count.

Example 3:
Input: N = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array 
are same, so there is no inversion count.

Your Task:
You don't need to read input or print anything. Your task is to complete the function inversionCount() which takes the array arr[] and the size of the array as inputs and returns the inversion count of the given array.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).
#endif



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long count = 0;
    
    void merge(long long arr[], long long l, long long m, long long r)
    {
        long long n1 = m - l + 1;
        long long n2 = r - m;
        long long a1[n1];
        long long a2[n2];
        for(int i = 0; i < n1; ++i)
            a1[i] = arr[l+i];
        for(int i = 0; i < n2; ++i)
            a2[i] = arr[m+1+i];
            
        // Initial index of first subarray
        int i = 0;
     
        // Initial index of second subarray
        int j = 0;
     
        // Initial index of merged subarray
        int k = l;
        while(i < n1 && j < n2)
        {
            if(a1[i] <= a2[j])
            {
                arr[k] = a1[i];
                ++i;
            }
            else
            {
                arr[k] = a2[j];
                ++j;
                count += n1 - i;
            }
            ++k;
        }
        //copy the remaining elements if any
        while(i < n1)
        {
            arr[k] = a1[i];
            ++k;
            ++i;
        }
        while(j < n2)
        {
            arr[k] = a2[j];
            ++k;
            ++j;
        }
    }
    
    void mergeSort(long long arr[], long long l, long long r)
    {
        if(l >= r)
            return;
        long long m = l + (r - l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        mergeSort(arr, 0, N-1);
        return count;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends
