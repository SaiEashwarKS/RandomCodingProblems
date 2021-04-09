#if 0
Given a matrix of size R*C. Traverse the matrix in spiral form.

Example 1:

Input:
R = 4, C = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

Example 2:

Input:
R = 3, C = 4  
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12}}
Output: 
1 2 3 4 8 12 11 10 9 5 6 7
Explanation:
Applying same technique as shown above, 
output for the 2nd testcase will be 
1 2 3 4 8 12 11 10 9 5 6 7.

Your Task:
You dont need to read input or print anything. Complete the function spirallyTraverse() that takes matrix, R and C as input parameters and returns a list of integers denoting the spiral traversal of matrix. 

Expected Time Complexity: O(R*C)
Expected Auxiliary Space: O(R*C)

Constraints:
1 <= R, C <= 100
0 <= matrixi <= 100
#endif

// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
public:     
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int left = 0;
        int right = c-1;
        int top = 0;
        int bot = r - 1;
        vector<int> res;
        int count = 0;
        while(count < r*c)
        {
            int i;
            for(i = left; i <= right; ++i)
            {
                if(count < r*c)
                {
                    res.push_back(matrix[top][i]);
                    ++count;
                }
            }
            ++top;
            --i;
            int j;
            for(j = top; j <= bot; ++j)
            {
                if(count < r*c)
                {
                    res.push_back(matrix[j][i]);
                    ++count;
                }
            }
            --right;
            --j;
            int k;
            for(k = right; k >= left; --k)
            {
                if(count < r*c)
                {
                    res.push_back(matrix[j][k]);
                    ++count;
                }
            }
            --bot;
            ++k;
            int l;
            for(l = bot; l >= top; --l)
            {
                if(count < r*c)
                {
                    res.push_back(matrix[l][k]);
                    ++count;
                }
            }
            ++left;
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
