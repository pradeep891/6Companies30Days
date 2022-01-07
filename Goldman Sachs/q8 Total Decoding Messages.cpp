// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	
	    int solve(string str)
	    {
		    
		    if(str[0] == '0')
		    return 0;
		    
		    if(str[str.size() - 1] == '0' && str.size() > 2 && str[str.size() - 2] > '2')
		    return 0;
		    
		    for(int i=1 ; i<str.size() ; i++)
		    {
		        if(str[i] == str[i-1] && str[i] == '0')
		        return 0;
		    }
		    
		    for(int i=1 ; i<str.size() ; i++)
		    {
		        if(str[i] == '0')
		        {
		            if(str[i-1] == '1' || str[i-1] == '2')
		            ;
		            else
		            return 0;
		        }
		    }
		    
		    return 1;
	    }
		int CountWays(string s){
		    // Code here
		    if(s.size() == 0)
		    return 1;
		    
		    long long int mod = 1e9 + 7;
		    
		    if(solve(s)  == 0)
		    return 0;
		     
		    
		    int n = s.size();
		    long long int ar[n+1] = {0};
		    ar[0] = 1;
		    ar[1] = 1;
		    for(int i=1 ; i<n;i++)
		    {
		        if(s[i] == '0' && s[i-1] == '0')
		        {
		            ar[i+1] = 0;
		        }
		        else if(s[i] != '0' && s[i-1] == '0')
		        {
		            ar[i+1] =  ar[i];
		        }
		        else if(s[i] == '0' && s[i-1] != '0')
		        {
		            string ss = "";
		            ss.push_back(s[i-1]);
		            ss.push_back(s[i]);
		            if(s[i-1] == '2' || s[i-1] == '1')
		            ar[i+1] =  ar[i-1];
		            else
		            ar[i+1] = 0;
		        }
		        else
		        {
		            string ss = "";
		            ss.push_back(s[i-1]);
		            ss.push_back(s[i]);
		            if(stoi(ss) <= 26)
		            ar[i+1] = ar[i] + ar[i-1];
		            else
		            ar[i+1] = ar[i];
		        }
		        
		        ar[i+1] = ar[i+1] % mod;
		    }
		    
		    return ar[n] % mod;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends