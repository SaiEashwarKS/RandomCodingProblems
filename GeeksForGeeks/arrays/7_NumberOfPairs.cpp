#if 0
Given two arrays X and Y of positive integers, find the number of pairs such that xy > yx (raised to power of) where x is an element from X and y is an element from Y.

Example 1:
Input: 
M = 3, X[] = [2 1 6] 
N = 2, Y[] = [1 5]
Output: 3
Explanation: 
The pairs which follow xy > yx are 
as such: 21 > 12,  25 > 52 and 61 > 16 .

Example 2:
Input: 
M = 4, X[] = [2 3 4 5]
N = 3, Y[] = [1 2 3]
Output: 5
Explanation: 
The pairs for the given input are 
21 > 12 , 31 > 13 , 32 > 23 , 41 > 14 , 
51 > 15 .

Your Task:
This is a function problem. You only need to complete the function countPairs() that takes X, Y, M, N as parameters and returns the total number of pairs.

Expected Time Complexity: O((N + M)log(N)).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ M, N ≤ 105
1 ≤ X[i], Y[i] ≤ 103
#endif


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends
 

class Solution{
    public:
    
    // X[], Y[]: input arrau
    // M, N: size of arrays X[] and Y[] respectively
    //Function to count number of pairs such that x^y is greater than y^x.
    int count(int x, int Y[], int N, int NoOfY[])
    {
        
        //If x is 0, then there can't be any value in Y[]
        //such that x^Y[val]>Y[val]^x. 
        if (x == 0) return 0;
        
        //If x is 1, then number of pair is equal to number of zeroes in Y[].
        if (x == 1) return NoOfY[0];
        
        //We work with logic that if x<y then x^y is greater than y^x.
        //Finding number of elements in Y[] with value greater than x.
        //upper_bound() gets address of first element greater than x in Y[].
        int* idx = upper_bound(Y, Y + N, x);
        
        //Updating number of pairs.
        int ans = (Y + N) - idx;
        
        //If we have reached here, then x must be greater than 1. 
        //Increasing number of pairs for y=0 and y=1.
        ans += (NoOfY[0] + NoOfY[1]);
        
        //Decreasing number of pairs for exception where x=2 and (y=4 or y=3). 
        if (x == 2)  ans -= (NoOfY[3] + NoOfY[4]);
        
        //Increasing number of pairs for exception where x=3 and y=2.
        if (x == 3)  ans += NoOfY[2];
     
        //returning number of pairs.
        return ans;
    }
    
    //Function to count number of pairs such that x^y is greater than y^x.
    long long countPairs(int X[], int Y[], int M, int N)
    {
        //Array to store counts of 0, 1, 2, 3 and 4 present in array Y.
        int NoOfY[5] = {0};
        //Storing the count in array if Y[i]<5.
        for (int i = 0; i < N; i++)
            if (Y[i] < 5)
                NoOfY[Y[i]]++;
     
        //Sorting Y[] so that we can do binary search on it later on.
        sort(Y, Y + N);
     
        long long total_pairs = 0; 
        
        //Taking every element of X[] and counting pairs with it.
        for (int i=0; i<M; i++)
            total_pairs += count(X[i], Y, N, NoOfY);
            
        //returning number of pairs.
        return total_pairs;
    }
};


// { Driver Code Starts.
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M,N;
		cin>>M>>N;
		int i,a[M],b[N];
		for(i=0;i<M;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>b[i];
		}
		Solution ob;
		cout<<ob.countPairs(a, b, M, N)<<endl;
	}
}  // } Driver Code Ends
