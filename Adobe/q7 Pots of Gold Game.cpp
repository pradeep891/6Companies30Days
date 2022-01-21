//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int maxCoins(vector<int>&A,int n)
    {
	    vector< vector<int> > dp(n+1 , vector<int>(n+1 , -1));
	    return solve(A , 0 , n-1 , dp);
    }
    
    int solve(vector<int>&a , int i , int j , vector< vector<int> > &dp)
    {
        if(i > j)
        {
            return 0;
        }
        
        if(i == j)
        {
            dp[i][j] = a[i];
        }
        
        if(dp[i][j] != -1)
        return dp[i][j];
        
        int l = a[i] + min(solve(a , i+2 , j , dp) , solve(a , i+1 , j-1 , dp));
        int r = a[j] + min(solve(a , i , j-2 , dp) , solve(a , i+1 , j-1 , dp));
        int ans = max(l , r);
        dp[i][j] = ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends