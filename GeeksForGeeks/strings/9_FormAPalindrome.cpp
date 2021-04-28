// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int countMin(string str){
    //complete the function here
        int n = str.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int l = n; l >= 0; --l)
        {
            for(int h = l + 1; h < n; ++h)
            {
                dp[l][h] = (str[l] == str[h]) ?
                            dp[l+1][h-1] :
                            (min(dp[l+1][h], dp[l][h-1]) + 1);
            }
        }
        return dp[0][n-1];
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}

  // } Driver Code Ends
