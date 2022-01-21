// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0 ; i<N ; i++)
        sum += arr[i];
        
        if(sum % 2 == 1)
        return 0;
        
        vector< vector<int> >dp(N+2 , vector<int>(sum/2 + 2 , -1));
        bool ans = solve(arr , N , sum/2 , dp);
    
        return ans;
    }
    
    bool solve(int a[] , int n , int sum ,  vector< vector<int>> &dp)
    {
        if(sum == 0)
        return true;
        
        if(n == 0)
        return false;
        
        if(dp[n][sum] == -1)
        return dp[n][sum] = (solve(a , n-1 , sum, dp) || solve(a , n-1 , sum - a[n-1] , dp) );
    
        else
        return dp[n][sum];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends