#if 0
Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, 
compute how much water can be trapped between the blocks during the rainy season. 

Example 1:
Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10

Example 2:
Input:
N = 4
arr[] = {7,4,0,9}
Output:
10
Explanation:
Water trapped by above 
block of height 4 is 3 units and above 
block of height 0 is 7 units. So, the 
total unit of water trapped is 10 units.

Example 3:
Input:
N = 3
arr[] = {6,9,9}
Output:
0
Explanation:
No water will be trapped.

Your Task:
You don'y need to read input or print anything. The task is to complete the function trappingWater() which takes arr and N as input parameters and returns the total amount of water that can be trapped.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
3 <= N <= 10^7
0 <= Ai <= 10^8
#endif


// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        int capacity = 0;
        int left[n]; //left[i] => height of tallest wall to the left of ith wall
        int right[n]; //right[i] => height of tallest wall to the right of ith wall
        left[0] = 0;
        right[n-1] = 0;
        
        int maxi = arr[0];
        for(int i = 1; i < n; ++i)
        {
            maxi = max(maxi, arr[i-1]);
            left[i] = maxi; 
        }
        
        maxi = arr[n-1];
        for(int i = n-2; i >= 0; --i)
        {
            maxi = max(maxi, arr[i+1]);
            right[i] = maxi; 
        }
        
        int mini;
        for(int i = 1; i < n-1; ++i)
        {
            mini = min(left[i], right[i]);
            if(mini - arr[i] > 0)
            {
                capacity += mini - arr[i];
            }
        }
        return capacity;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends
