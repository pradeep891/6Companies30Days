// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int ar[n+1]  = {0};
        for(int i=0 ; i<n;i++)
        {
            int k = arr[i];
            ar[k]++;
        }
        
        int b = 0 , a = 0;
        for(int i=1 ; i<=n;i++)
        {
            if(ar[i] == 2)
            {
                b = i;
            }
            if(ar[i] == 0)
            a = i;
        }
        
        int *ans = new int[2];
        ans[0] = b;
        ans[1] = a;
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends