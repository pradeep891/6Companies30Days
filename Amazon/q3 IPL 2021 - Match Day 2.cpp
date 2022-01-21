// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        deque<int>dq;
        vector<int>ans;
        dq.push_back(0);
        
        int i=1;
        int start = 0;
        while(i<k && i<n)
        {
            if(!dq.empty() && arr[dq.front()] <= arr[i])
            {
                dq.clear();
                dq.push_back(i);
            }
              else
                {
                    while(!dq.empty() && arr[dq.back()] <= arr[i])
                    {
                        dq.pop_back();
                        // i++;
                    }
                    dq.push_back(i);
                }
            
            i++;
        }
        start = 1;
        ans.push_back(arr[dq.front()]);
        while(i<n)
        {
            while(!dq.empty() && dq.front() < start)
            dq.pop_front();
                if(!dq.empty() && arr[dq.front()] <= arr[i])
                {
                    dq.clear();
                    dq.push_back(i);
                }
                else
                {
                    while(!dq.empty() && arr[dq.back()] <= arr[i])
                    {
                        dq.pop_back();
                        // i++;
                    }
                    dq.push_back(i);
                }
            
            ans.push_back(arr[dq.front()]);
            i++;
            start++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends