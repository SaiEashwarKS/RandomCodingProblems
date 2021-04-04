#if 0
Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on.

Example 1:
Input:
N = 6
arr[] = {1,2,3,4,5,6}
Output: 6 1 5 2 4 3
Explanation: Max element = 6, min = 1, 
second max = 5, second min = 2, and 
so on... Modified array is : 6 1 5 2 4 3.

Example 2:
Input:
N = 11
arr[]={10,20,30,40,50,60,70,80,90,100,110}
Output:110 10 100 20 90 30 80 40 70 50 60
Explanation: Max element = 110, min = 10, 
second max = 100, second min = 20, and 
so on... Modified array is : 
110 10 100 20 90 30 80 40 70 50 60.

Your Task:
The task is to complete the function rearrange() which rearranges elements as explained above. Printing of the modified array will be handled by driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
#endif


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends


class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
    	
    	// Your code here
    	//while rearraging, we shouldn't lose the old elements
    	//store old and new values simultaneously
    	//Dividend = Divisor * Quotient + Remainder
    	//   Divisor = number greater than all the numbers in the array
        //   Quotient = New number at index i after rearrangement
        //   Remainder = Old Number at index i before rearrangement
        //   Dividend = The number stored at index i
        
        long long divisor, quotient, remainder;
        divisor = arr[n-1] + 1;
        int max_idx = n-1;
        int min_idx = 0;
        for(int i = 0; i < n; ++i)
        {
            if(i % 2 == 0) //even indices : max elements
            {
                quotient = arr[max_idx] % divisor; //quotient for this element = remainder of the other element
                arr[i] = divisor * quotient + arr[i];
                --max_idx;
            }
            else //odd indices: min elements
            {
                quotient = arr[min_idx] % divisor;
                arr[i] = divisor * quotient + arr[i];
                ++min_idx;
            }
        }
        for(int i = 0; i < n; ++i)
        {
            arr[i] = arr[i] / divisor; //the new element is the quotient
        }
    }
};

// { Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 
  // } Driver Code Ends
