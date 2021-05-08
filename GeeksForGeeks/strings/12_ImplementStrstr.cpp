#if 0
Your task is to implement the function strstr. The function takes two strings as arguments (s,x) and  locates the occurrence of the string x in the string s.
The function returns and integer denoting the first occurrence of the string x in s (0 based indexing).

Note: You are not allowed to use inbuilt function.

Example 1:
Input:
s = GeeksForGeeks, x = Fr
Output: -1
Explanation: Fr is not present in the
string GeeksForGeeks as substring.
 

Example 2:
Input:
s = GeeksForGeeks, x = For
Output: 5
Explanation: For is present as substring
in GeeksForGeeks from index 5 (0 based
indexing).
 

Your Task:
You don't have to take any input. Just complete the strstr() function which takes two strings str, target as an input parameter. 
The function returns -1 if no match if found else it returns an integer denoting the first occurrence of the x in the string s.

Expected Time Complexity: O(|s|*|x|)
Expected Auxiliary Space: O(1)

Note : Try to solve the question in constant space complexity.

Constraints:
1 <= |s|,|x| <= 100
#endif


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}
// } Driver Code Ends



int make_lps(int lps[], string s)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    int ns = s.size();
    while(i < ns)
    {
        if(s[len] == s[i])
        {
            ++len;
            lps[i] = len;
            ++i;
        }
        else if(len > 0)
        {
            len = lps[len-1];
        }
        else
        {
            lps[i] = 0;
            ++i;
        }
    }
}

int kmp (string s, string x)
{
    int i = 0;
    int j = 0;
    int ns = s.size();
    int nx = x.size();
    int lps[ns];
    make_lps(lps, s);
    while(i < ns)
    {
        if(s[i] == x[j])
        {
            ++i;
            ++j;
        }
        if(j == nx)
        {
            return i-j;
        }
        else if(i < ns && s[i]!=x[j])
        {
            if(j > 0)
            {
                j = lps[j-1];
            }
            else
                ++i;
        }
    }
    return -1;
}

//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
     //Your code here
     return kmp(s, x);
}
