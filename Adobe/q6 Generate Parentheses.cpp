// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        string s = "";
        vector<string> ans;
        solve(s , n , n , ans);
        return ans;
    }
    
    void solve(string s , int a , int n , vector<string>&ans)
    {
        if(n == 0 && a == 0)
        {
            ans.push_back(s);
            return;
        }
        
        if(a > 0)
        {
            // solve(s , a , n , ans);
            s.push_back('(');
            // a--;
            solve(s , a-1 , n , ans);
            s.pop_back();
        }
        
        if(a<n){
            s.push_back(')');
            solve(s , a , n-1 , ans);
        }
        
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends