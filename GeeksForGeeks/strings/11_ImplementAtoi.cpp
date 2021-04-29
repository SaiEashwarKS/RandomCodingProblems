#if 0
Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.

Example 1:
Input:
str = 123
Output: 123

Example 2:
Input:
str = 21a
Output: -1
Explanation: Output is -1 as all
characters are not digit only.
Your Task:
Complete the function atoi() which takes a string as input parameter and returns integer value of it. if the input string is not a numerical string then returns 1..

Expected Time Complexity: O(|S|), |S| = length of string S.
Expected Auxiliary Space: O(1)

Constraints:
1<=length of S<=10
#endif

// { Driver Code Starts
 #include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
        /*You are required to complete this method */
    int atoi(string str)
    {
        //Your code here
        int res = 0;
        int n = str.size();
        int place = n-1;
        int sign = 1;
        int i = 0;
        if(str[0] == '-' || str[0] == '+')
        {
            sign = str[0] == '-' ? -1 : 1;
            ++i;
            --place;
        }
        for(; i < n; ++i)
        {
            int temp = str[i] - '0';
            if(temp > 9 || temp < 0)
                return -1;
            res += temp * pow(10, place);
            --place;
        }
        return res*sign;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends
