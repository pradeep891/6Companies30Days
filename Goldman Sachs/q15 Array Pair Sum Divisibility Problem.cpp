// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        if(nums.size() % 2)
        return false;
        
   
        int ar[k] = {0};
        for(int i=0 ; i<nums.size() ; i++)
        {
            ar[nums[i] % k]++;
        }
        
        if(k %  2 == 1)
        {
            // cout << "h1";
            for(int i=1 ; i<=k/2;i++)
            {
                if(ar[i] != ar[k-i])
                return false;
            }
        }
        else
        {
            // cout << "h2";
            for(int i=1 ; i<k/2;i++)
            {
                if(ar[i] != ar[k-i])
                return false;
            }
            
            if(ar[k/2] % 2 == 1)
            return false;
        }
        
        if(ar[0] % 2 == 1)
        return false;
        
        return true;
        
        
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends