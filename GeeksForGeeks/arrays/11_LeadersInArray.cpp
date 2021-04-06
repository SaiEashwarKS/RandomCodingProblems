#if 0
Given an array A of positive integers. Your task is to find the leaders in the array. An element of array is leader if it is greater than or equal to all the elements to its right side. 
The rightmost element is always a leader. 

Example 1:
Input:
n = 6
A[] = {16,17,4,3,5,2}
Output: 17 5 2
Explanation: The first leader is 17 
as it is greater than all the elements
to its right.  Similarly, the next 
leader is 5. The right most element 
is always a leader so it is also 
included.
 
Example 2:
Input:
n = 5
A[] = {1,2,3,4,0}
Output: 4 0
 
Your Task:
You don't need to read input or print anything. The task is to complete the function leader() which takes array A and n as input parameters and returns an array of leaders in order of their appearance. 

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 10^7
0 <= Ai <= 10^7
#endif



// { Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

    

class Solution{
    //Function to find the leaders in the array.
    public:
    int* constructMaxiArr (int a[], int n)
    {
        int* a2 = new int[n];
        int maxi = a[n-1];
        a2[n-1] = maxi;
        for(int i = n-2; i >= 0; --i)
        {
            maxi = a[i] > maxi ? a[i] : maxi;
            a2[i] = maxi;
        }
        return a2;
    }
    vector<int> leaders(int a[], int n){
        // Code here
        //construct an array such that a2[i] = max(a[i+1, i+2, ... n-1)
        int* maxiArray = constructMaxiArr(a, n);
        vector<int> res;
        for(int i = 0; i < n; ++i)
        {
            if(a[i] >= maxiArray[i])
                res.push_back(a[i]);
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}
  // } Driver Code Ends
