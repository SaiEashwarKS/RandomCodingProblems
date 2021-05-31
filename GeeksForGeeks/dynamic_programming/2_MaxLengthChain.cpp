#if 0
You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. 
A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. 
You have to find the longest chain which can be formed from the given set of pairs. 

Example 1:
Input:
N = 5
P[] = {5  24 , 39 60 , 15 28 , 27 40 , 50 90}
Output: 3
Explanation: The given pairs are { {5, 24}, {39, 60},
{15, 28}, {27, 40}, {50, 90} },the longest chain that
can be formed is of length 3, and the chain is
{{5, 24}, {27, 40}, {50, 90}}

Example 2:
Input:
N = 2
P[] = {5 10 , 1 11}
Output: 1
Explanation:The max length chain possible is only of
length one.

Your Task:
You don't need to read input or print anything. Your task is to Complete the function maxChainLen() which takes a structure p[] denoting the pairs 
and n as the number of pairs and returns the length of the longest chain formed.

Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(N)

Constraints:
1<=N<=100
#endif

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/

#if 0
//////////WITHOUT DP
bool compare(struct val a, struct val b)
{
    return a.first > b.first; //DESCENDING
}
int maxChainLen(struct val p[],int n)
{
    //Your code here
    sort(p, p + n, compare);
    int res = 1;
    struct val prev = p[0];
    for(int i = 1; i < n; ++i)
    {
        if(p[i].second < prev.first)
        {
            ++res;
            prev = p[i];
        }
    }
    return res;
}
#endif

//////////WITH DP
bool compare(struct val a, struct val b)
{
    return a.first < b.first; //ASCENDING
}

int maxChainLen(struct val p[],int n)
{
    //Your code here
    sort(p, p + n, compare);
    int* dp = new int[sizeof(int) * n];
    for(int i = 0; i < n; ++i)
    {
        dp[i] = 1;
    }
    
    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(p[j].second < p[i].first && dp[i] < dp[j]+1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }
    //dp[i] contains maximum chain length ending with pair i
    
    int max = 1;
    for(int i = 0; i < n; ++i)
    {
        if(max < dp[i])
        {
            max = dp[i];
        }
    }
    free(dp);
    return max;
}


