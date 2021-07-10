#if 0
You are given a set of N types of rectangular 3-D boxes, where the ith box has height h, width w and length l. 
Your task is to create a stack of boxes which is as tall as possible, but you can only stack a box on top of another box if the dimensions of the 2-D base of the 
lower box are each strictly larger than those of the 2-D base of the higher box. Of course, you can rotate a box so that any side functions as its base.
It is also allowable to use multiple instances of the same type of box. 
Your task is to complete the function maxHeight which returns the height of the highest possible stack so formed.

Note: 
Base of the lower box should be strictly larger than that of the new box we're going to place. 
This is in terms of both length and width, not just in terms of area. So, two boxes with same base cannot be placed one over the other.

Example 1:
Input:
n = 4
height[] = {4,1,4,10}
width[] = {6,2,5,12}
length[] = {7,3,6,32}
Output: 60
Explanation: One way of placing the boxes is
as follows in the bottom to top manner:
(Denoting the boxes in (l, w, h) manner)
(12, 32, 10) (10, 12, 32) (6, 7, 4) 
(5, 6, 4) (4, 5, 6) (2, 3, 1) (1, 2, 3)
Hence, the total height of this stack is
10 + 32 + 4 + 4 + 6 + 1 + 3 = 60.
No other combination of boxes produces a
height greater than this.

Example 2:
Input:
n = 3
height[] = {1,4,3}
width[] = {2,5,4}
length[] = {3,6,1}
Output: 15
Explanation: One way of placing the boxes is
as follows in the bottom to top manner:
(Denoting the boxes in (l, w, h) manner)
(5, 6, 4) (4, 5, 6) (3, 4, 1), (2, 3, 1) 
(1, 2, 3).
Hence, the total height of this stack is
4 + 6 + 1 + 1 + 3 = 15
No other combination of boxes produces a
height greater than this.
Your Task:
You don't need to read input or print anything. Your task is to complete the function maxHeight() which takes three arrays height[], width[], length[], and N as a number of boxes and returns the highest possible stack height which could be formed.


Expected Time Complexity : O(N*N)
Expected Auxiliary Space: O(N)


#endif

// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    struct box {
        int l, w, h; //w <= l
    };
    
    static int compare (const void* a, const void* b) 
    {
        return ((*(box*)b).l * (*(box*)b).w) - ((*(box*)a).l * (*(box*)a).w);
    }
    
    int maxHeight(int height[],int width[],int length[],int n)
    {
        //Your code here
        box boxes[3*n];
        int box_i = 0;
        for(int i = 0; i < n; ++i)
        {
            //original box
            boxes[box_i].h = height[i];
            boxes[box_i].l = max(length[i], width[i]);
            boxes[box_i].w = min(length[i], width[i]);
            ++box_i;
            
            //first rotation
            boxes[box_i].h = width[i];
            boxes[box_i].l = max(length[i], height[i]);
            boxes[box_i].w = min(length[i], height[i]);
            ++box_i;
            
            //second rotation
            boxes[box_i].h = length[i];
            boxes[box_i].l = max(height[i], width[i]);
            boxes[box_i].w = min(height[i], width[i]);
            ++box_i;
        }
        n *= 3;
        qsort(boxes, n, sizeof(boxes[0]), compare);
        
        int msh[n];
        for(int i = 0; i < n; ++i)
        {
            msh[i] = boxes[i].h;
        }
        
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(boxes[i].l < boxes[j].l && boxes[i].w < boxes[j].w && msh[i] < msh[j]+boxes[i].h)
                {
                    msh[i] = msh[j]+boxes[i].h;
                }
            }
        }
        
        int maxi = -1;
        for(int i = 0; i < n; ++i)
        {
            maxi = max(maxi, msh[i]);
        }
        return maxi;
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    }
	
	return 0;
}
	  // } Driver Code Ends
