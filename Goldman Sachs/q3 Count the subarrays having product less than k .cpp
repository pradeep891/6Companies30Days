// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int ct = 0;
        int end = 0;
        long long int pro = 1;
        for(int i=0 ; i<n;i++)
        {
            pro = pro * a[i];
            if(pro < k)
            {
                ct += (i - end + 1);
            }
            while(pro >= k)
            {
                pro = pro/a[end];
                end++;
                
                if(pro < k)
                ct += (i - end + 1);
            }
        }
        
        return ct;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends