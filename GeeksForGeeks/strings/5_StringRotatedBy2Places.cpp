#if 0
Given two strings a and b. The task is to find if the string 'b' can be obtained by rotating another string 'a' by exactly 2 places.

Example 1:

Input:
a = amazon
b = azonam
Output: 1
Explanation: amazon can be rotated anti
clockwise by two places, which will make
it as azonam.
Example 2:

Input:
a = geeksforgeeks
b = geeksgeeksfor
Output: 0
Explanation: If we rotate geeksforgeeks by
two place in any direction , we won't get
geeksgeeksfor.
Your Task:
The task is to complete the function isRotated() which takes two strings as input parameters and checks if given strings can be formed by rotations. The function returns true if string 1 can be obtained by rotating string 2 by two places, else it returns false.

Expected Time Complexity: O(N).
Expected Auxilary Complexity: O(N).
Challenge: Try doing it in O(1) space complexity.

Constraints:
1 <= length of a, b < 100
#endif

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 // } Driver Code Ends

class Solution{
  public:
    /*  Function to check if str1 can be formed from
    *   str2 after rotation by 2 places
    */
    bool isRotated(string str1, string str2)
    {
        // Your code here
        int n1 = str1.length();
        if(n1 <= 2)
            return str1 == str2;
        string temp1 = str1;
        string temp2 = str1;
        rotate(temp1.begin(), temp1.begin()+2, temp1.end());//left rotate
        rotate(temp2.begin(), temp2.end()-2, temp2.end()); //right rotation
        return (temp1 == str2) || (temp2 == str2);
    }

};

// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends
