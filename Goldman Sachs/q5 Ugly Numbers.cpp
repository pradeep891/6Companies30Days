// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    int a = 0 , b = 0 , c = 0;
	    vector<long long int>ugly(n+1);
	    ugly[0] = 1;
	    
	    for(int i=1 ; i<n ; i++)
	    {
	        ugly[i] = min(min(2 * ugly[a] , 3*ugly[b] ) , 5*ugly[c]);
	        if(2*ugly[a] == ugly[i])
	            a++;
	        if(3*ugly[b] == ugly[i])
	            b++;
	        if(5*ugly[c] == ugly[i])
	            c++;
	            
	       //cout << ugly[i] << " ";
	    }
	    
	    return ugly[n-1];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends