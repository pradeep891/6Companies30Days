// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    char ar[] = {'!' , '#' , '$' , '%' , '&' , '*' , '@' , '^' , '~'};
	    
	    int index = 0;
	    for(int i=0 ; i<9;i++)
	    {
	        int p1 = -1, p2 = -1 ;
	        for(int j=index ; j<n;j++)
	        {
	            if(nuts[j] == ar[i])
	            p1 = j;
	            if(bolts[j] == ar[i])
	            p2 = j;
	            
	        }
	        if(p1!= -1 && p2 != -1)
	        {
	            swap(nuts[p1] , nuts[index]);
	            swap(bolts[p2] , bolts[index]);
	            index++;
	        }
	    }
	  
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends